#pragma once

#include <functional>
#include <iomanip>
#include <iostream>
#include <optional>
#include <sstream>
#include <string_view>
#include <vector>

namespace CppUnitTestFramework {

    struct AssertLocation {
        std::string_view SourceFile;
        size_t LineNumber;
    };

    enum class AssertType {
        Throw,
        Continue
    };

    struct AssertException :
        std::exception
    {
        AssertException(const std::string_view& message)
          : m_message(message)
        {}

        const char* what() const noexcept override {
            return m_message.data();
        }

    private:
        std::string_view m_message;
    };

    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------

    struct ILogger {
        virtual ~ILogger() = default;

        virtual void SkipTest(const std::string_view& name) = 0;
        virtual void EnterTest(const std::string_view& name) = 0;
        virtual void ExitTest() = 0;

        virtual void SkipSection(const std::string_view& name) = 0;
        virtual void PushSection(const std::string_view& name) = 0;
        virtual void PopSection() = 0;

        virtual void AssertFailed(
            AssertType type,
            const AssertLocation& location,
            const std::string_view& message
        ) = 0;
        virtual void UnhandledException(const std::string_view& message) = 0;
    };
    using ILoggerPtr = std::shared_ptr<ILogger>;

    //--------------------------------------------------------------------------------------------------------

    struct ConsoleLogger :
        ILogger
    {
        static ILoggerPtr Create() {
            return std::make_unique<ConsoleLogger>();
        }

        virtual ~ConsoleLogger() = default;

        void SkipTest(const std::string_view& name) override {
            std::cout << "Skip: " << name.data() << std::endl;
        }
        void EnterTest(const std::string_view& name) override {
            std::cout << "Test: " << name.data() << std::endl;
            m_indent_level++;
        }
        void ExitTest() override {
            m_indent_level = 0;
        }

        void SkipSection(const std::string_view& name) override {
            Indent(std::cout) << "[Skipped] " << name.data() << std::endl;
        }
        void PushSection(const std::string_view& name) override {
            Indent(std::cout) << name.data() << std::endl;
            m_indent_level++;
        }
        void PopSection() override {
            if (m_indent_level > 0) {
                m_indent_level--;
            }
        }

        void AssertFailed(
            AssertType type,
            const AssertLocation& location,
            const std::string_view& message
        ) override {
            m_test_failed = true;
            auto& log = Indent(std::cout);

            log << "@" << location.LineNumber << " ";

            switch (type) {
            case AssertType::Throw: log << "REQUIRE"; break;
            case AssertType::Continue: log << "CHECK"; break;
            }

            log << ": " << message.data() << std::endl;
        }
        void UnhandledException(const std::string_view& message) override {
            m_test_failed = true;
            Indent(std::cout) << "Fail: " << message.data() << std::endl;
        }

    private:
        bool m_test_failed = false;
        size_t m_indent_level = 0;

        std::ostream& Indent(std::ostream& out) {
            for (size_t i = 0; i != m_indent_level; ++i) {
                out << "    ";
            }
            return out;
        }
    };

    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------

    struct TestRunContext {
        ILoggerPtr Logger;
    };

    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------

    struct TestRegistry {
    private:
        using TestCallback = std::function<void (const ILoggerPtr& logger)>;
        struct TestDetails {
            std::string_view Name;
            TestCallback Callback;
        };

    public:
        template <typename TTestCase>
        struct AutoReg {
            AutoReg() {
                TestRegistry::Add<TTestCase>();
            }
        };

    public:
        template <typename TTestCase>
        static void Add() {
            TestDetails details {
                TTestCase::Name,
                [](const auto&... args) {
                    TTestCase test_case(args...);
                    test_case.Run();
                }
            };

            GetTestVector().push_back(std::move(details));
        }

        static void Run(const ILoggerPtr& logger) {
            for (auto& test_case : GetTestVector()) {
                // if (filter00 && !filter00(test_case.Name)) {
                //     logger->SkipTest(test_case.Name);
                //     continue;
                // }

                logger->EnterTest(test_case.Name);

                try {
                    test_case.Callback(logger);
                } catch (const AssertException& e) {
                    // REQUIRE* statement failed.  We should stop here.
                } catch (const std::exception& e) {
                    logger->UnhandledException(e.what());
                } catch (...) {
                    logger->UnhandledException("<unstructured>");
                }

                logger->ExitTest();
            }
        }

    private:
        static std::vector<TestDetails>& GetTestVector() {
            static std::vector<TestDetails> s_test_vector;
            return s_test_vector;
        }
    };

    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------

    namespace Ext {
        template <typename T>
        std::string ToString([[maybe_unused]] const T& value) {
            if constexpr (std::is_null_pointer_v<T>) {
                return "nullptr";

            } else if constexpr (std::is_constructible_v<std::string, const T&>) {
                return std::string(value);

            } else if constexpr (std::is_pointer_v<T>) {
                std::ostringstream ss;
                ss << "0x" << std::hex << std::setfill('0') << std::setw(sizeof(size_t) * 2)
                    << reinterpret_cast<std::uintptr_t>(value);
                return ss.str();

            } else if constexpr (std::is_enum_v<T>) {
                std::ostringstream ss;
                ss << "[" << typeid(T).name() << "] " << static_cast<std::underlying_type_t<T>>(value);
                return ss.str();

            } else {
                return std::to_string(value);
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------

    namespace Assert {
        template <typename TLeft, typename TRight>
        std::optional<AssertException> AreEqual(TLeft&& left, TRight&& right) {
            bool equal = (left == right);
            if (equal) {
                return std::nullopt;
            }

            auto msg = Ext::ToString(left) + " == " + Ext::ToString(right);
            return AssertException(msg.c_str());
        }

        //----------------------------------------------------------------------------------------------------

        inline std::optional<AssertException> AreEqual(const char* left, const char* right) {
            bool equal = (strcmp(left, right) == 0);
            if (equal) {
                return std::nullopt;
            }

            auto msg = Ext::ToString(left) + " == " + Ext::ToString(right);
            return AssertException(msg.c_str());
        }

        //----------------------------------------------------------------------------------------------------

        template <typename T>
        std::optional<AssertException> IsNull(const T& value) {
            return AreEqual(value, nullptr);
        }

        //----------------------------------------------------------------------------------------------------

        inline std::optional<AssertException> IsTrue(bool value) {
            if (!value) {
                return AssertException("false == true");
            }
            return std::nullopt;
        }

        //----------------------------------------------------------------------------------------------------

        inline std::optional<AssertException> IsFalse(bool value) {
            if (value) {
                return AssertException("true == false");
            }
            return std::nullopt;
        }

        //----------------------------------------------------------------------------------------------------

        template <typename TException, typename Callback>
        inline std::optional<AssertException> Throws(const Callback& callback) {
            try {
                callback();
            } catch (const TException&) {
                return std::nullopt;
            } catch (...) {
                std::ostringstream ss;
                ss << "Expected exception [" << typeid(TException).name() << "] but caught another";
                return AssertException(ss.str().c_str());
            }

            std::ostringstream ss;
            ss << "Expected exception [" << typeid(TException).name() << "] but none was thrown";
            return AssertException(ss.str().c_str());
        }
    };

    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------

    struct CommonFixture;
    struct SectionLock {
        ~SectionLock() {
            if (m_logger00) {
                m_logger00->PopSection();
                m_logger00 = nullptr;
            }
        }

    private:
        SectionLock(const std::string_view& text, ILoggerPtr logger)
          : m_logger00(std::move(logger))
        {
            m_logger00->PushSection(text);
        }

        SectionLock(SectionLock&& other)
          : m_logger00(std::move(other.m_logger00))
        {}

        SectionLock& operator = (SectionLock&& other) {
            if (m_logger00) {
                m_logger00->PopSection();
            }
            m_logger00 = std::move(other.m_logger00);
            return *this;
        }

        ILoggerPtr m_logger00;

        friend struct CommonFixture;
    };

    //--------------------------------------------------------------------------------------------------------

    struct CommonFixture
    {
        CommonFixture(ILoggerPtr logger)
          : m_logger(std::move(logger))
        {}

    protected:
        SectionLock EnterSection(std::string text) {
            return SectionLock(text, m_logger);
        }

        void HandleAssert(
            AssertType behavior,
            const AssertLocation& location,
            const std::optional<AssertException>& exception00
        ) {
            if (!exception00) {
                // Nothing happened.
                return;
            }

            m_logger->AssertFailed(behavior, location, exception00->what());

            if (behavior == AssertType::Throw) {
                throw *exception00;
            }
        }

    private:
        ILoggerPtr m_logger;
    };
}

//------------------------------------------------------------------------------------------------------------

#define _CPPUTF_COMBINE_NAME_PARTS2(a, b) a##b
#define _CPPUTF_COMBINE_NAME_PARTS(a, b) _CPPUTF_COMBINE_NAME_PARTS2(a, b)
#define _CPPUTF_NEXT_REGISTRAR_NAME    _CPPUTF_COMBINE_NAME_PARTS(s_test_registrar_, __COUNTER__)
#define _CPPUTF_NEXT_SECTION_LOCK_NAME _CPPUTF_COMBINE_NAME_PARTS(section_lock_, __COUNTER__)
#define _CPPUTF_NEXT_EXCEPTION_NAME    _CPPUTF_COMBINE_NAME_PARTS(exception_, __COUNTER__)
#define _CPPUTF_NEXT_MAYBEUNUSED_NAME  _CPPUTF_COMBINE_NAME_PARTS(unused_, __COUNTER__)

//------------------------------------------------------------------------------------------------------------

#define TEST_CASE(TestFixture, TestName) namespace {                                                \
    struct TestCase_##TestName : TestFixture, CppUnitTestFramework::CommonFixture {                 \
        using CppUnitTestFramework::CommonFixture::CommonFixture;                                   \
        static constexpr std::string_view Name = #TestFixture "::" #TestName;                       \
        void Run();                                                                                 \
    };                                                                                              \
    CppUnitTestFramework::TestRegistry::AutoReg<TestCase_##TestName> _CPPUTF_NEXT_REGISTRAR_NAME;   \
}                                                                                                   \
void TestCase_##TestName::Run()

//------------------------------------------------------------------------------------------------------------

#define SECTION(Text)  if (auto _CPPUTF_NEXT_SECTION_LOCK_NAME = EnterSection("Section: " Text); true)
#define SCENARIO(Text) if (auto _CPPUTF_NEXT_SECTION_LOCK_NAME = EnterSection("Scenario: " Text); true)
#define GIVEN(Text)    if (auto _CPPUTF_NEXT_SECTION_LOCK_NAME = EnterSection("Given: " Text); true)
#define AND(Text)      if (auto _CPPUTF_NEXT_SECTION_LOCK_NAME = EnterSection("And: " Text); true)
#define WHEN(Text)     if (auto _CPPUTF_NEXT_SECTION_LOCK_NAME = EnterSection("When: " Text); true)
#define THEN(Text)     if (auto _CPPUTF_NEXT_SECTION_LOCK_NAME = EnterSection("Then: " Text); true)

//------------------------------------------------------------------------------------------------------------

#define _CPPUTF_ASSERT_LOCATION CppUnitTestFramework::AssertLocation{ __FILE__, __LINE__ }

#define REQUIRE(Expression)        CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Throw, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::IsTrue((Expression)))
#define REQUIRE_TRUE(Expression)   CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Throw, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::IsTrue((Expression)))
#define REQUIRE_FALSE(Expression)  CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Throw, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::IsFalse((Expression)))
#define REQUIRE_EQUAL(Left, Right) CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Throw, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::AreEqual((Left), (Right)))
#define REQUIRE_NULL(Expression)   CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Throw, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::IsNull((Expression)))
#define REQUIRE_THROW(ExceptionType, Expression) \
    CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Throw, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::Throws<ExceptionType>([&] { Expression; }))

#define CHECK(Expression)        CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Continue, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::IsTrue((Expression)))
#define CHECK_TRUE(Expression)   CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Continue, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::IsTrue((Expression)))
#define CHECK_FALSE(Expression)  CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Continue, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::IsFalse((Expression)))
#define CHECK_EQUAL(Left, Right) CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Continue, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::AreEqual((Left), (Right)))
#define CHECK_NULL(Expression)   CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Continue, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::IsNull((Expression)))
#define CHECK_THROW(ExceptionType, Expression) \
    CppUnitTestFramework::CommonFixture::HandleAssert(CppUnitTestFramework::AssertType::Continue, _CPPUTF_ASSERT_LOCATION, CppUnitTestFramework::Assert::Throws<ExceptionType>([&] { Expression; }))

//------------------------------------------------------------------------------------------------------------

#define UNUSED_RETURN(Expression) [[maybe_unused]] auto _CPPUTF_NEXT_MAYBEUNUSED_NAME = Expression

//------------------------------------------------------------------------------------------------------------

#ifdef GENERATE_UNIT_TEST_MAIN
int main(int /*argc*/, const char* /*argv*/[]) {
    std::cout << "Running tests..." << std::endl;

    CppUnitTestFramework::TestRegistry::Run(
        CppUnitTestFramework::ConsoleLogger::Create()
    );

    return 0;
}
#endif