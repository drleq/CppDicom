#pragma once

#include "dicom/DataDictionary.h"
#include "dicom/tag.h"

namespace dicom::tags {
    DICOM_EXPORT void populate_data_dictionary(const DataDictionaryPtr& data_dictionary);

    /** AbortFlag, 0x40101024, CS, 1, RET */
    extern DICOM_EXPORT const tag AbortFlag;
    /** AbortReason, 0x40101021, CS, 1, RET */
    extern DICOM_EXPORT const tag AbortReason;
    /** AbsoluteChannelDisplayScale, 0x003A0248, FL, 1 */
    extern DICOM_EXPORT const tag AbsoluteChannelDisplayScale;
    /** AbstractPriorCodeSequence, 0x0072003E, SQ, 1 */
    extern DICOM_EXPORT const tag AbstractPriorCodeSequence;
    /** AbstractPriorValue, 0x0072003C, SS, 2 */
    extern DICOM_EXPORT const tag AbstractPriorValue;
    /** AccessionNumber, 0x00080050, SH, 1 */
    extern DICOM_EXPORT const tag AccessionNumber;
    /** AccessoryCode, 0x300A00F9, LO, 1 */
    extern DICOM_EXPORT const tag AccessoryCode;
    /** AcquiredImageAreaDoseProduct, 0x00189473, FL, 1 */
    extern DICOM_EXPORT const tag AcquiredImageAreaDoseProduct;
    /** AcquiredSoundpathLength, 0x00144031, DS, 1, RET */
    extern DICOM_EXPORT const tag AcquiredSoundpathLength;
    /** AcquisitionComments, 0x00184000, LT, 1, RET */
    extern DICOM_EXPORT const tag AcquisitionComments;
    /** AcquisitionCompressionType, 0x00144032, CS, 1, RET */
    extern DICOM_EXPORT const tag AcquisitionCompressionType;
    /** AcquisitionContextDescription, 0x00400556, ST, 1 */
    extern DICOM_EXPORT const tag AcquisitionContextDescription;
    /** AcquisitionContextSequence, 0x00400555, SQ, 1 */
    extern DICOM_EXPORT const tag AcquisitionContextSequence;
    /** AcquisitionContrast, 0x00089209, CS, 1 */
    extern DICOM_EXPORT const tag AcquisitionContrast;
    /** AcquisitionDate, 0x00080022, DA, 1 */
    extern DICOM_EXPORT const tag AcquisitionDate;
    /** AcquisitionDateTime, 0x0008002A, DT, 1 */
    extern DICOM_EXPORT const tag AcquisitionDateTime;
    /** AcquisitionDeviceProcessingCode, 0x00181401, LO, 1 */
    extern DICOM_EXPORT const tag AcquisitionDeviceProcessingCode;
    /** AcquisitionDeviceProcessingDescription, 0x00181400, LO, 1 */
    extern DICOM_EXPORT const tag AcquisitionDeviceProcessingDescription;
    /** AcquisitionDeviceTypeCodeSequence, 0x00220015, SQ, 1 */
    extern DICOM_EXPORT const tag AcquisitionDeviceTypeCodeSequence;
    /** AcquisitionDuration, 0x00189073, FD, 1 */
    extern DICOM_EXPORT const tag AcquisitionDuration;
    /** AcquisitionEndLocationSequence, 0x00189932, SQ, 1 */
    extern DICOM_EXPORT const tag AcquisitionEndLocationSequence;
    /** AcquisitionIndex, 0x00209518, US, 1 */
    extern DICOM_EXPORT const tag AcquisitionIndex;
    /** AcquisitionMatrix, 0x00181310, US, 4 */
    extern DICOM_EXPORT const tag AcquisitionMatrix;
    /** AcquisitionMethodAlgorithmSequence, 0x00221423, SQ, 1 */
    extern DICOM_EXPORT const tag AcquisitionMethodAlgorithmSequence;
    /** AcquisitionMethodCodeSequence, 0x00221420, SQ, 1 */
    extern DICOM_EXPORT const tag AcquisitionMethodCodeSequence;
    /** AcquisitionMotion, 0x00189930, CS, 1 */
    extern DICOM_EXPORT const tag AcquisitionMotion;
    /** AcquisitionNumber, 0x00200012, IS, 1 */
    extern DICOM_EXPORT const tag AcquisitionNumber;
    /** AcquisitionProtocolDescription, 0x00189424, LT, 1 */
    extern DICOM_EXPORT const tag AcquisitionProtocolDescription;
    /** AcquisitionProtocolElementSequence, 0x00189920, SQ, 1 */
    extern DICOM_EXPORT const tag AcquisitionProtocolElementSequence;
    /** AcquisitionProtocolElementSpecificationSequence, 0x0018991F, SQ, 1 */
    extern DICOM_EXPORT const tag AcquisitionProtocolElementSpecificationSequence;
    /** AcquisitionProtocolName, 0x00189423, LO, 1 */
    extern DICOM_EXPORT const tag AcquisitionProtocolName;
    /** AcquisitionSampleSize, 0x00144033, IS, 1, RET */
    extern DICOM_EXPORT const tag AcquisitionSampleSize;
    /** AcquisitionsInSeries, 0x00201001, IS, 1, RET */
    extern DICOM_EXPORT const tag AcquisitionsInSeries;
    /** AcquisitionsInStudy, 0x00201004, IS, 1, RET */
    extern DICOM_EXPORT const tag AcquisitionsInStudy;
    /** AcquisitionStartCondition, 0x00180073, CS, 1 */
    extern DICOM_EXPORT const tag AcquisitionStartCondition;
    /** AcquisitionStartConditionData, 0x00180074, IS, 1 */
    extern DICOM_EXPORT const tag AcquisitionStartConditionData;
    /** AcquisitionStartLocationSequence, 0x00189931, SQ, 1 */
    extern DICOM_EXPORT const tag AcquisitionStartLocationSequence;
    /** AcquisitionStatus, 0x40101044, CS, 1, RET */
    extern DICOM_EXPORT const tag AcquisitionStatus;
    /** AcquisitionTerminationCondition, 0x00180071, CS, 1 */
    extern DICOM_EXPORT const tag AcquisitionTerminationCondition;
    /** AcquisitionTerminationConditionData, 0x00180075, IS, 1 */
    extern DICOM_EXPORT const tag AcquisitionTerminationConditionData;
    /** AcquisitionTime, 0x00080032, TM, 1 */
    extern DICOM_EXPORT const tag AcquisitionTime;
    /** AcquisitionTimeSynchronized, 0x00181800, CS, 1 */
    extern DICOM_EXPORT const tag AcquisitionTimeSynchronized;
    /** AcquisitionType, 0x00189302, CS, 1 */
    extern DICOM_EXPORT const tag AcquisitionType;
    /** AcrossScanSpatialResolution, 0x00220048, FL, 1 */
    extern DICOM_EXPORT const tag AcrossScanSpatialResolution;
    /** ActiveAperture, 0x00145100, US, 1, RET */
    extern DICOM_EXPORT const tag ActiveAperture;
    /** ActiveSourceDiameter, 0x300A0218, DS, 1 */
    extern DICOM_EXPORT const tag ActiveSourceDiameter;
    /** ActiveSourceLength, 0x300A021A, DS, 1 */
    extern DICOM_EXPORT const tag ActiveSourceLength;
    /** ActualCardiacTriggerDelayTime, 0x00209252, FD, 1 */
    extern DICOM_EXPORT const tag ActualCardiacTriggerDelayTime;
    /** ActualCardiacTriggerTimePriorToRPeak, 0x00209155, FL, 1 */
    extern DICOM_EXPORT const tag ActualCardiacTriggerTimePriorToRPeak;
    /** ActualEnvironmentalConditions, 0x00141010, ST, 1, RET */
    extern DICOM_EXPORT const tag ActualEnvironmentalConditions;
    /** ActualFrameDuration, 0x00181242, IS, 1 */
    extern DICOM_EXPORT const tag ActualFrameDuration;
    /** ActualHumanPerformersSequence, 0x00404035, SQ, 1 */
    extern DICOM_EXPORT const tag ActualHumanPerformersSequence;
    /** ActualRespiratoryTriggerDelayTime, 0x00209257, FD, 1 */
    extern DICOM_EXPORT const tag ActualRespiratoryTriggerDelayTime;
    /** AdaptiveMapFormat, 0x00280730, US, 1, RET */
    extern DICOM_EXPORT const tag AdaptiveMapFormat;
    /** AddIntermediateSequence, 0x00460101, SQ, 1 */
    extern DICOM_EXPORT const tag AddIntermediateSequence;
    /** AdditionalDrugSequence, 0x0018002A, SQ, 1 */
    extern DICOM_EXPORT const tag AdditionalDrugSequence;
    /** AdditionalInspectionMethodSequence, 0x4010106F, SQ, 1, RET */
    extern DICOM_EXPORT const tag AdditionalInspectionMethodSequence;
    /** AdditionalInspectionSelectionCriteria, 0x4010106E, CS, 1, RET */
    extern DICOM_EXPORT const tag AdditionalInspectionSelectionCriteria;
    /** AdditionalPatientHistory, 0x001021B0, LT, 1 */
    extern DICOM_EXPORT const tag AdditionalPatientHistory;
    /** AdditionalRTROIIdentificationCodeSequence, 0x300600B9, SQ, 1, RET */
    extern DICOM_EXPORT const tag AdditionalRTROIIdentificationCodeSequence;
    /** AdditionalScreeningPerformed, 0x4010106D, CS, 1, RET */
    extern DICOM_EXPORT const tag AdditionalScreeningPerformed;
    /** AddNearSequence, 0x00460100, SQ, 1 */
    extern DICOM_EXPORT const tag AddNearSequence;
    /** AddOtherSequence, 0x00460102, SQ, 1 */
    extern DICOM_EXPORT const tag AddOtherSequence;
    /** AddPower, 0x00460104, FD, 1 */
    extern DICOM_EXPORT const tag AddPower;
    /** AddressTrial, 0x0040A353, ST, 1, RET */
    extern DICOM_EXPORT const tag AddressTrial;
    /** AdministrationRouteCodeSequence, 0x00540302, SQ, 1 */
    extern DICOM_EXPORT const tag AdministrationRouteCodeSequence;
    /** AdmissionID, 0x00380010, LO, 1 */
    extern DICOM_EXPORT const tag AdmissionID;
    /** AdmittingDate, 0x00380020, DA, 1 */
    extern DICOM_EXPORT const tag AdmittingDate;
    /** AdmittingDiagnosesCodeSequence, 0x00081084, SQ, 1 */
    extern DICOM_EXPORT const tag AdmittingDiagnosesCodeSequence;
    /** AdmittingDiagnosesDescription, 0x00081080, LO, 1 */
    extern DICOM_EXPORT const tag AdmittingDiagnosesDescription;
    /** AdmittingTime, 0x00380021, TM, 1 */
    extern DICOM_EXPORT const tag AdmittingTime;
    /** AdvancedBlendingSequence, 0x00701B01, SQ, 1 */
    extern DICOM_EXPORT const tag AdvancedBlendingSequence;
    /** AfterloaderChannelID, 0x300A0273, SH, 1 */
    extern DICOM_EXPORT const tag AfterloaderChannelID;
    /** AgeCorrectedSensitivityDeviationAlgorithmSequence, 0x00240065, SQ, 1 */
    extern DICOM_EXPORT const tag AgeCorrectedSensitivityDeviationAlgorithmSequence;
    /** AgeCorrectedSensitivityDeviationProbabilityValue, 0x00240100, FL, 1 */
    extern DICOM_EXPORT const tag AgeCorrectedSensitivityDeviationProbabilityValue;
    /** AgeCorrectedSensitivityDeviationValue, 0x00240092, FL, 1 */
    extern DICOM_EXPORT const tag AgeCorrectedSensitivityDeviationValue;
    /** AirCounts, 0x00143070, OB or OW, 1, RET */
    extern DICOM_EXPORT const tag AirCounts;
    /** AITDeviceType, 0x40101070, CS, 1, RET */
    extern DICOM_EXPORT const tag AITDeviceType;
    /** AlarmDecision, 0x40101031, CS, 1, RET */
    extern DICOM_EXPORT const tag AlarmDecision;
    /** AlarmDecisionTime, 0x4010102B, DT, 1, RET */
    extern DICOM_EXPORT const tag AlarmDecisionTime;
    /** AlgorithmCodeSequenceTrial, 0x0040A296, SQ, 1, RET */
    extern DICOM_EXPORT const tag AlgorithmCodeSequenceTrial;
    /** AlgorithmDescription, 0x00189528, LO, 1 */
    extern DICOM_EXPORT const tag AlgorithmDescription;
    /** AlgorithmDescriptionTrial, 0x0040A297, ST, 1, RET */
    extern DICOM_EXPORT const tag AlgorithmDescriptionTrial;
    /** AlgorithmFamilyCodeSequence, 0x0066002F, SQ, 1 */
    extern DICOM_EXPORT const tag AlgorithmFamilyCodeSequence;
    /** AlgorithmName, 0x00660036, LO, 1 */
    extern DICOM_EXPORT const tag AlgorithmName;
    /** AlgorithmNameCodeSequence, 0x00660030, SQ, 1 */
    extern DICOM_EXPORT const tag AlgorithmNameCodeSequence;
    /** AlgorithmParameters, 0x00660032, LT, 1 */
    extern DICOM_EXPORT const tag AlgorithmParameters;
    /** AlgorithmRoutingCodeSequence, 0x40101064, SQ, 1, RET */
    extern DICOM_EXPORT const tag AlgorithmRoutingCodeSequence;
    /** AlgorithmSource, 0x00240202, LO, 1 */
    extern DICOM_EXPORT const tag AlgorithmSource;
    /** AlgorithmType, 0x00189527, CS, 1 */
    extern DICOM_EXPORT const tag AlgorithmType;
    /** AlgorithmVersion, 0x00660031, LO, 1 */
    extern DICOM_EXPORT const tag AlgorithmVersion;
    /** AliasedDataType, 0x0018980B, CS, 1 */
    extern DICOM_EXPORT const tag AliasedDataType;
    /** ALinePixelSpacing, 0x00520014, FD, 1 */
    extern DICOM_EXPORT const tag ALinePixelSpacing;
    /** ALineRate, 0x00520011, FD, 1 */
    extern DICOM_EXPORT const tag ALineRate;
    /** ALinesPerFrame, 0x00520012, US, 1 */
    extern DICOM_EXPORT const tag ALinesPerFrame;
    /** Allergies, 0x00102110, LO, 1 */
    extern DICOM_EXPORT const tag Allergies;
    /** AllowLossyCompression, 0x2200000F, CS, 1 */
    extern DICOM_EXPORT const tag AllowLossyCompression;
    /** AllowMediaSplitting, 0x22000007, CS, 1 */
    extern DICOM_EXPORT const tag AllowMediaSplitting;
    /** AlongScanSpatialResolution, 0x00220037, FL, 1 */
    extern DICOM_EXPORT const tag AlongScanSpatialResolution;
    /** AlphaLUTTransferFunction, 0x00281410, CS, 1 */
    extern DICOM_EXPORT const tag AlphaLUTTransferFunction;
    /** AlphaPaletteColorLookupTableData, 0x00281204, OW, 1 */
    extern DICOM_EXPORT const tag AlphaPaletteColorLookupTableData;
    /** AlphaPaletteColorLookupTableDescriptor, 0x00281104, US, 3 */
    extern DICOM_EXPORT const tag AlphaPaletteColorLookupTableDescriptor;
    /** AlternateBeamDose, 0x300A0091, DS, 1 */
    extern DICOM_EXPORT const tag AlternateBeamDose;
    /** AlternateBeamDoseType, 0x300A0092, CS, 1 */
    extern DICOM_EXPORT const tag AlternateBeamDoseType;
    /** AlternateContainerIdentifierSequence, 0x00400515, SQ, 1 */
    extern DICOM_EXPORT const tag AlternateContainerIdentifierSequence;
    /** AlternateContentDescriptionSequence, 0x00700087, SQ, 1 */
    extern DICOM_EXPORT const tag AlternateContentDescriptionSequence;
    /** AlternateRepresentationSequence, 0x00083001, SQ, 1 */
    extern DICOM_EXPORT const tag AlternateRepresentationSequence;
    /** AmbientLightValueSource, 0x00287025, CS, 1 */
    extern DICOM_EXPORT const tag AmbientLightValueSource;
    /** AmbientReflectionIntensity, 0x00701702, FD, 1 */
    extern DICOM_EXPORT const tag AmbientReflectionIntensity;
    /** AmplifierType, 0x0014400A, CS, 1, RET */
    extern DICOM_EXPORT const tag AmplifierType;
    /** AnalyzedArea, 0x00460227, FL, 1 */
    extern DICOM_EXPORT const tag AnalyzedArea;
    /** AnatomicalOrientationType, 0x00102210, CS, 1 */
    extern DICOM_EXPORT const tag AnatomicalOrientationType;
    /** AnatomicApproachDirectionCodeSequenceTrial, 0x00082255, SQ, 1, RET */
    extern DICOM_EXPORT const tag AnatomicApproachDirectionCodeSequenceTrial;
    /** AnatomicLocationOfExaminingInstrumentCodeSequenceTrial, 0x00082259, SQ, 1, RET */
    extern DICOM_EXPORT const tag AnatomicLocationOfExaminingInstrumentCodeSequenceTrial;
    /** AnatomicLocationOfExaminingInstrumentDescriptionTrial, 0x00082258, ST, 1, RET */
    extern DICOM_EXPORT const tag AnatomicLocationOfExaminingInstrumentDescriptionTrial;
    /** AnatomicPerspectiveCodeSequenceTrial, 0x00082257, SQ, 1, RET */
    extern DICOM_EXPORT const tag AnatomicPerspectiveCodeSequenceTrial;
    /** AnatomicPerspectiveDescriptionTrial, 0x00082256, ST, 1, RET */
    extern DICOM_EXPORT const tag AnatomicPerspectiveDescriptionTrial;
    /** AnatomicPortalOfEntranceCodeSequenceTrial, 0x00082253, SQ, 1, RET */
    extern DICOM_EXPORT const tag AnatomicPortalOfEntranceCodeSequenceTrial;
    /** AnatomicRegionModifierSequence, 0x00082220, SQ, 1 */
    extern DICOM_EXPORT const tag AnatomicRegionModifierSequence;
    /** AnatomicRegionSequence, 0x00082218, SQ, 1 */
    extern DICOM_EXPORT const tag AnatomicRegionSequence;
    /** AnatomicRegionsInStudyCodeSequence, 0x00080063, SQ, 1 */
    extern DICOM_EXPORT const tag AnatomicRegionsInStudyCodeSequence;
    /** AnatomicStructure, 0x00082208, CS, 1, RET */
    extern DICOM_EXPORT const tag AnatomicStructure;
    /** AnatomicStructureReferencePoint, 0x00221463, FL, 2 */
    extern DICOM_EXPORT const tag AnatomicStructureReferencePoint;
    /** AnatomicStructureSpaceOrRegionCodeSequenceTrial, 0x00082251, SQ, 1, RET */
    extern DICOM_EXPORT const tag AnatomicStructureSpaceOrRegionCodeSequenceTrial;
    /** AnatomicStructureSpaceOrRegionModifierCodeSequenceTrial, 0x0008225A, SQ, 1, RET */
    extern DICOM_EXPORT const tag AnatomicStructureSpaceOrRegionModifierCodeSequenceTrial;
    /** AnatomicStructureSpaceOrRegionSequence, 0x00082229, SQ, 1, RET */
    extern DICOM_EXPORT const tag AnatomicStructureSpaceOrRegionSequence;
    /** AnchorPoint, 0x00700014, FL, 2 */
    extern DICOM_EXPORT const tag AnchorPoint;
    /** AnchorPointAnnotationUnits, 0x00700004, CS, 1 */
    extern DICOM_EXPORT const tag AnchorPointAnnotationUnits;
    /** AnchorPointVisibility, 0x00700015, CS, 1 */
    extern DICOM_EXPORT const tag AnchorPointVisibility;
    /** AngioFlag, 0x00180025, CS, 1 */
    extern DICOM_EXPORT const tag AngioFlag;
    /** AngleNumber, 0x00200018, IS, 1, RET */
    extern DICOM_EXPORT const tag AngleNumber;
    /** AngularPosition, 0x00181141, DS, 1, RET */
    extern DICOM_EXPORT const tag AngularPosition;
    /** AngularStep, 0x00181144, DS, 1 */
    extern DICOM_EXPORT const tag AngularStep;
    /** AngularViewVector, 0x00540090, US, 1 */
    extern DICOM_EXPORT const tag AngularViewVector;
    /** AnimationCurveSequence, 0x00701A04, SQ, 1 */
    extern DICOM_EXPORT const tag AnimationCurveSequence;
    /** AnimationStepSize, 0x00701A05, FD, 1 */
    extern DICOM_EXPORT const tag AnimationStepSize;
    /** AnnotationClipping, 0x00701907, CS, 1 */
    extern DICOM_EXPORT const tag AnnotationClipping;
    /** AnnotationContentSequence, 0x21300050, SQ, 1, RET */
    extern DICOM_EXPORT const tag AnnotationContentSequence;
    /** AnnotationDisplayFormatID, 0x20100030, CS, 1 */
    extern DICOM_EXPORT const tag AnnotationDisplayFormatID;
    /** AnnotationFlag, 0x20000065, CS, 1, RET */
    extern DICOM_EXPORT const tag AnnotationFlag;
    /** AnnotationGroupNumber, 0x0040A180, US, 1 */
    extern DICOM_EXPORT const tag AnnotationGroupNumber;
    /** AnnotationPosition, 0x20300010, US, 1 */
    extern DICOM_EXPORT const tag AnnotationPosition;
    /** AnodeTargetMaterial, 0x00181191, CS, 1 */
    extern DICOM_EXPORT const tag AnodeTargetMaterial;
    /** AnomalyLocatorIndicator, 0x4010107A, FL, 3, RET */
    extern DICOM_EXPORT const tag AnomalyLocatorIndicator;
    /** AnomalyLocatorIndicatorSequence, 0x40101079, SQ, 1, RET */
    extern DICOM_EXPORT const tag AnomalyLocatorIndicatorSequence;
    /** AnteriorChamberDepth, 0x00221131, FL, 1 */
    extern DICOM_EXPORT const tag AnteriorChamberDepth;
    /** AnteriorChamberDepthDefinitionCodeSequence, 0x00221125, SQ, 1 */
    extern DICOM_EXPORT const tag AnteriorChamberDepthDefinitionCodeSequence;
    /** AnteriorChamberDepthSequence, 0x00221128, SQ, 1 */
    extern DICOM_EXPORT const tag AnteriorChamberDepthSequence;
    /** ApertureElevation, 0x00145102, DS, 1, RET */
    extern DICOM_EXPORT const tag ApertureElevation;
    /** ApexPosition, 0x00209308, FD, 3 */
    extern DICOM_EXPORT const tag ApexPosition;
    /** ApplicableFrameRange, 0x00286102, US, 2 */
    extern DICOM_EXPORT const tag ApplicableFrameRange;
    /** ApplicableSafetyStandardAgency, 0x00189174, CS, 1 */
    extern DICOM_EXPORT const tag ApplicableSafetyStandardAgency;
    /** ApplicableSafetyStandardDescription, 0x00189175, LO, 1 */
    extern DICOM_EXPORT const tag ApplicableSafetyStandardDescription;
    /** ApplicationManufacturer, 0x00189526, LO, 1 */
    extern DICOM_EXPORT const tag ApplicationManufacturer;
    /** ApplicationMaximumRepaintTime, 0x0072010E, US, 1 */
    extern DICOM_EXPORT const tag ApplicationMaximumRepaintTime;
    /** ApplicationName, 0x00189524, LO, 1 */
    extern DICOM_EXPORT const tag ApplicationName;
    /** ApplicationSetupCheck, 0x30080116, CS, 1 */
    extern DICOM_EXPORT const tag ApplicationSetupCheck;
    /** ApplicationSetupManufacturer, 0x300A0238, LO, 1 */
    extern DICOM_EXPORT const tag ApplicationSetupManufacturer;
    /** ApplicationSetupName, 0x300A0236, LO, 1 */
    extern DICOM_EXPORT const tag ApplicationSetupName;
    /** ApplicationSetupNumber, 0x300A0234, IS, 1 */
    extern DICOM_EXPORT const tag ApplicationSetupNumber;
    /** ApplicationSetupSequence, 0x300A0230, SQ, 1 */
    extern DICOM_EXPORT const tag ApplicationSetupSequence;
    /** ApplicationSetupType, 0x300A0232, CS, 1 */
    extern DICOM_EXPORT const tag ApplicationSetupType;
    /** ApplicationVersion, 0x00189525, LO, 1 */
    extern DICOM_EXPORT const tag ApplicationVersion;
    /** ApplicatorApertureShape, 0x300A0432, CS, 1 */
    extern DICOM_EXPORT const tag ApplicatorApertureShape;
    /** ApplicatorDescription, 0x300A010A, LO, 1 */
    extern DICOM_EXPORT const tag ApplicatorDescription;
    /** ApplicatorGeometrySequence, 0x300A0431, SQ, 1 */
    extern DICOM_EXPORT const tag ApplicatorGeometrySequence;
    /** ApplicatorID, 0x300A0108, SH, 1 */
    extern DICOM_EXPORT const tag ApplicatorID;
    /** ApplicatorOpening, 0x300A0433, FL, 1 */
    extern DICOM_EXPORT const tag ApplicatorOpening;
    /** ApplicatorOpeningX, 0x300A0434, FL, 1 */
    extern DICOM_EXPORT const tag ApplicatorOpeningX;
    /** ApplicatorOpeningY, 0x300A0435, FL, 1 */
    extern DICOM_EXPORT const tag ApplicatorOpeningY;
    /** ApplicatorSequence, 0x300A0107, SQ, 1 */
    extern DICOM_EXPORT const tag ApplicatorSequence;
    /** ApplicatorType, 0x300A0109, CS, 1 */
    extern DICOM_EXPORT const tag ApplicatorType;
    /** ApprovalSequence, 0x00440100, SQ, 1 */
    extern DICOM_EXPORT const tag ApprovalSequence;
    /** ApprovalStatus, 0x300E0002, CS, 1 */
    extern DICOM_EXPORT const tag ApprovalStatus;
    /** ApprovalStatusDateTime, 0x00440004, DT, 1 */
    extern DICOM_EXPORT const tag ApprovalStatusDateTime;
    /** ApprovalStatusFurtherDescription, 0x00440003, LT, 1 */
    extern DICOM_EXPORT const tag ApprovalStatusFurtherDescription;
    /** ApprovalSubjectSequence, 0x00440109, SQ, 1 */
    extern DICOM_EXPORT const tag ApprovalSubjectSequence;
    /** Arbitrary, 0x40000010, LT, 1, RET */
    extern DICOM_EXPORT const tag Arbitrary;
    /** ArchiveRequested, 0x0040A494, CS, 1 */
    extern DICOM_EXPORT const tag ArchiveRequested;
    /** ArterialSpinLabelingContrast, 0x00189250, CS, 1 */
    extern DICOM_EXPORT const tag ArterialSpinLabelingContrast;
    /** AscanRate, 0x00221649, FL, 1 */
    extern DICOM_EXPORT const tag AscanRate;
    /** ASLBolusCutoffDelayTime, 0x0018925F, UL, 1 */
    extern DICOM_EXPORT const tag ASLBolusCutoffDelayTime;
    /** ASLBolusCutoffFlag, 0x0018925C, CS, 1 */
    extern DICOM_EXPORT const tag ASLBolusCutoffFlag;
    /** ASLBolusCutoffTechnique, 0x0018925E, LO, 1 */
    extern DICOM_EXPORT const tag ASLBolusCutoffTechnique;
    /** ASLBolusCutoffTimingSequence, 0x0018925D, SQ, 1 */
    extern DICOM_EXPORT const tag ASLBolusCutoffTimingSequence;
    /** ASLContext, 0x00189257, CS, 1 */
    extern DICOM_EXPORT const tag ASLContext;
    /** ASLCrusherDescription, 0x0018925B, LO, 1 */
    extern DICOM_EXPORT const tag ASLCrusherDescription;
    /** ASLCrusherFlag, 0x00189259, CS, 1 */
    extern DICOM_EXPORT const tag ASLCrusherFlag;
    /** ASLCrusherFlowLimit, 0x0018925A, FD, 1 */
    extern DICOM_EXPORT const tag ASLCrusherFlowLimit;
    /** ASLMidSlabPosition, 0x00189256, FD, 3 */
    extern DICOM_EXPORT const tag ASLMidSlabPosition;
    /** ASLPulseTrainDuration, 0x00189258, UL, 1 */
    extern DICOM_EXPORT const tag ASLPulseTrainDuration;
    /** ASLSlabNumber, 0x00189253, US, 1 */
    extern DICOM_EXPORT const tag ASLSlabNumber;
    /** ASLSlabOrientation, 0x00189255, FD, 3 */
    extern DICOM_EXPORT const tag ASLSlabOrientation;
    /** ASLSlabSequence, 0x00189260, SQ, 1 */
    extern DICOM_EXPORT const tag ASLSlabSequence;
    /** ASLSlabThickness, 0x00189254, FD, 1 */
    extern DICOM_EXPORT const tag ASLSlabThickness;
    /** ASLTechniqueDescription, 0x00189252, LO, 1 */
    extern DICOM_EXPORT const tag ASLTechniqueDescription;
    /** AsserterIdentificationSequence, 0x00440103, SQ, 1 */
    extern DICOM_EXPORT const tag AsserterIdentificationSequence;
    /** AssertionCodeSequence, 0x00440101, SQ, 1 */
    extern DICOM_EXPORT const tag AssertionCodeSequence;
    /** AssertionComments, 0x00440106, UT, 1 */
    extern DICOM_EXPORT const tag AssertionComments;
    /** AssertionDateTime, 0x00440104, DT, 1 */
    extern DICOM_EXPORT const tag AssertionDateTime;
    /** AssertionExpirationDateTime, 0x00440105, DT, 1 */
    extern DICOM_EXPORT const tag AssertionExpirationDateTime;
    /** AssertionUID, 0x00440102, UI, 1 */
    extern DICOM_EXPORT const tag AssertionUID;
    /** AssessedAttributeValueSequence, 0x00820010, SQ, 1 */
    extern DICOM_EXPORT const tag AssessedAttributeValueSequence;
    /** AssessedSOPInstanceSequence, 0x00820004, SQ, 1 */
    extern DICOM_EXPORT const tag AssessedSOPInstanceSequence;
    /** AssessmentLabel, 0x00820023, LO, 1 */
    extern DICOM_EXPORT const tag AssessmentLabel;
    /** AssessmentObservationsSequence, 0x00820007, SQ, 1 */
    extern DICOM_EXPORT const tag AssessmentObservationsSequence;
    /** AssessmentRequesterSequence, 0x00820017, SQ, 1 */
    extern DICOM_EXPORT const tag AssessmentRequesterSequence;
    /** AssessmentSetID, 0x00820016, LO, 1 */
    extern DICOM_EXPORT const tag AssessmentSetID;
    /** AssessmentSummary, 0x00820001, CS, 1 */
    extern DICOM_EXPORT const tag AssessmentSummary;
    /** AssessmentSummaryDescription, 0x00820003, UT, 1 */
    extern DICOM_EXPORT const tag AssessmentSummaryDescription;
    /** AssessmentTypeCodeSequence, 0x00820021, SQ, 1 */
    extern DICOM_EXPORT const tag AssessmentTypeCodeSequence;
    /** AssignedLocation, 0x4010102A, SH, 1, RET */
    extern DICOM_EXPORT const tag AssignedLocation;
    /** AssigningAgencyOrDepartmentCodeSequence, 0x0040003A, SQ, 1 */
    extern DICOM_EXPORT const tag AssigningAgencyOrDepartmentCodeSequence;
    /** AssigningFacilitySequence, 0x00400036, SQ, 1 */
    extern DICOM_EXPORT const tag AssigningFacilitySequence;
    /** AssigningJurisdictionCodeSequence, 0x00400039, SQ, 1 */
    extern DICOM_EXPORT const tag AssigningJurisdictionCodeSequence;
    /** ATDAbilityAssessment, 0x40101014, CS, 1, RET */
    extern DICOM_EXPORT const tag ATDAbilityAssessment;
    /** ATDAssessmentFlag, 0x40101015, CS, 1, RET */
    extern DICOM_EXPORT const tag ATDAssessmentFlag;
    /** ATDAssessmentProbability, 0x40101016, FL, 1, RET */
    extern DICOM_EXPORT const tag ATDAssessmentProbability;
    /** ATDAssessmentSequence, 0x40101038, SQ, 1, RET */
    extern DICOM_EXPORT const tag ATDAssessmentSequence;
    /** AttachedContours, 0x30060049, IS, 1 */
    extern DICOM_EXPORT const tag AttachedContours;
    /** AttenuationCorrected, 0x00189759, CS, 1 */
    extern DICOM_EXPORT const tag AttenuationCorrected;
    /** AttenuationCorrectionMethod, 0x00541101, LO, 1 */
    extern DICOM_EXPORT const tag AttenuationCorrectionMethod;
    /** AttenuationCorrectionSource, 0x00189738, CS, 1 */
    extern DICOM_EXPORT const tag AttenuationCorrectionSource;
    /** AttenuationCorrectionTemporalRelationship, 0x00189770, CS, 1 */
    extern DICOM_EXPORT const tag AttenuationCorrectionTemporalRelationship;
    /** AttributeItemSelector, 0x00741054, UL, 1 */
    extern DICOM_EXPORT const tag AttributeItemSelector;
    /** AttributeModificationDateTime, 0x04000562, DT, 1 */
    extern DICOM_EXPORT const tag AttributeModificationDateTime;
    /** AttributeOccurrencePointer, 0x00741052, AT, 1 */
    extern DICOM_EXPORT const tag AttributeOccurrencePointer;
    /** AttributeOccurrencePrivateCreator, 0x00741056, LO, 1 */
    extern DICOM_EXPORT const tag AttributeOccurrencePrivateCreator;
    /** AttributeOccurrenceSequence, 0x00741050, SQ, 1 */
    extern DICOM_EXPORT const tag AttributeOccurrenceSequence;
    /** AudioComments, 0x5000200E, LT, 1, RET */
    extern DICOM_EXPORT const range_tag AudioComments;
    /** AudioSampleData, 0x5000200C, OB or OW, 1, RET */
    extern DICOM_EXPORT const range_tag AudioSampleData;
    /** AudioSampleFormat, 0x50002002, US, 1, RET */
    extern DICOM_EXPORT const range_tag AudioSampleFormat;
    /** AudioType, 0x50002000, US, 1, RET */
    extern DICOM_EXPORT const range_tag AudioType;
    /** AuthorizationEquipmentCertificationNumber, 0x01000426, LO, 1 */
    extern DICOM_EXPORT const tag AuthorizationEquipmentCertificationNumber;
    /** AuthorObserverSequence, 0x0040A078, SQ, 1 */
    extern DICOM_EXPORT const tag AuthorObserverSequence;
    /** AutoKVPLowerBound, 0x00189946, FD, 1 */
    extern DICOM_EXPORT const tag AutoKVPLowerBound;
    /** AutoKVPSelectionType, 0x00189944, CS, 1 */
    extern DICOM_EXPORT const tag AutoKVPSelectionType;
    /** AutoKVPUpperBound, 0x00189945, FD, 1 */
    extern DICOM_EXPORT const tag AutoKVPUpperBound;
    /** AutorefractionLeftEyeSequence, 0x00460052, SQ, 1 */
    extern DICOM_EXPORT const tag AutorefractionLeftEyeSequence;
    /** AutorefractionRightEyeSequence, 0x00460050, SQ, 1 */
    extern DICOM_EXPORT const tag AutorefractionRightEyeSequence;
    /** AutosequenceFlag, 0x00741025, CS, 1 */
    extern DICOM_EXPORT const tag AutosequenceFlag;
    /** AverageBeamDosePointDepth, 0x300A008D, FL, 1, RET */
    extern DICOM_EXPORT const tag AverageBeamDosePointDepth;
    /** AverageBeamDosePointEquivalentDepth, 0x300A008E, FL, 1, RET */
    extern DICOM_EXPORT const tag AverageBeamDosePointEquivalentDepth;
    /** AverageBeamDosePointSourceToExternalContourDistance, 0x300A0131, FL, 1 */
    extern DICOM_EXPORT const tag AverageBeamDosePointSourceToExternalContourDistance;
    /** AverageBeamDosePointSSD, 0x300A008F, FL, 1, RET */
    extern DICOM_EXPORT const tag AverageBeamDosePointSSD;
    /** AverageCornealPower, 0x00460220, FL, 1 */
    extern DICOM_EXPORT const tag AverageCornealPower;
    /** AveragePulseWidth, 0x00181154, DS, 1 */
    extern DICOM_EXPORT const tag AveragePulseWidth;
    /** AxialAcceptance, 0x00541200, DS, 1 */
    extern DICOM_EXPORT const tag AxialAcceptance;
    /** AxialDetectorDimension, 0x00189727, FD, 1 */
    extern DICOM_EXPORT const tag AxialDetectorDimension;
    /** AxialLengthOfTheEye, 0x00220030, FL, 1 */
    extern DICOM_EXPORT const tag AxialLengthOfTheEye;
    /** AxialMash, 0x00541201, IS, 2 */
    extern DICOM_EXPORT const tag AxialMash;
    /** AxialPower, 0x00460249, FL, 1 */
    extern DICOM_EXPORT const tag AxialPower;
    /** AxialResolution, 0x00520008, FD, 1 */
    extern DICOM_EXPORT const tag AxialResolution;
    /** AxisLabels, 0x50000040, SH, 1, RET */
    extern DICOM_EXPORT const range_tag AxisLabels;
    /** AxisOfRotation, 0x0066001B, FL, 3 */
    extern DICOM_EXPORT const tag AxisOfRotation;
    /** AxisUnits, 0x50000030, SH, 1, RET */
    extern DICOM_EXPORT const range_tag AxisUnits;
    /** B1rms, 0x00181320, FL, 1 */
    extern DICOM_EXPORT const tag B1rms;
    /** BackgroundColor, 0x00460092, CS, 1 */
    extern DICOM_EXPORT const tag BackgroundColor;
    /** BackgroundIlluminationColorCodeSequence, 0x00240024, SQ, 1 */
    extern DICOM_EXPORT const tag BackgroundIlluminationColorCodeSequence;
    /** BackgroundLuminance, 0x00240020, FL, 1 */
    extern DICOM_EXPORT const tag BackgroundLuminance;
    /** BadPixelImage, 0x00143080, OB, 1, RET */
    extern DICOM_EXPORT const tag BadPixelImage;
    /** BarcodeSymbology, 0x22000006, CS, 1 */
    extern DICOM_EXPORT const tag BarcodeSymbology;
    /** BarcodeValue, 0x22000005, LT, 1 */
    extern DICOM_EXPORT const tag BarcodeValue;
    /** BaselineCorrection, 0x00189067, CS, 1 */
    extern DICOM_EXPORT const tag BaselineCorrection;
    /** BasicColorImageSequence, 0x20200111, SQ, 1 */
    extern DICOM_EXPORT const tag BasicColorImageSequence;
    /** BasicGrayscaleImageSequence, 0x20200110, SQ, 1 */
    extern DICOM_EXPORT const tag BasicGrayscaleImageSequence;
    /** BasisMaterialsCodeSequence, 0x40101045, SQ, 1, RET */
    extern DICOM_EXPORT const tag BasisMaterialsCodeSequence;
    /** BeamAngle, 0x00189449, FL, 1 */
    extern DICOM_EXPORT const tag BeamAngle;
    /** BeamCurrentModulationID, 0x300A034C, SH, 1 */
    extern DICOM_EXPORT const tag BeamCurrentModulationID;
    /** BeamDeliveryDurationLimit, 0x300A00C5, FD, 1 */
    extern DICOM_EXPORT const tag BeamDeliveryDurationLimit;
    /** BeamDescription, 0x300A00C3, ST, 1 */
    extern DICOM_EXPORT const tag BeamDescription;
    /** BeamDose, 0x300A0084, DS, 1 */
    extern DICOM_EXPORT const tag BeamDose;
    /** BeamDoseMeaning, 0x300A008B, CS, 1 */
    extern DICOM_EXPORT const tag BeamDoseMeaning;
    /** BeamDosePointDepth, 0x300A0088, FL, 1 */
    extern DICOM_EXPORT const tag BeamDosePointDepth;
    /** BeamDosePointEquivalentDepth, 0x300A0089, FL, 1 */
    extern DICOM_EXPORT const tag BeamDosePointEquivalentDepth;
    /** BeamDosePointSSD, 0x300A008A, FL, 1 */
    extern DICOM_EXPORT const tag BeamDosePointSSD;
    /** BeamDoseSpecificationPoint, 0x300A0082, DS, 3 */
    extern DICOM_EXPORT const tag BeamDoseSpecificationPoint;
    /** BeamDoseType, 0x300A0090, CS, 1 */
    extern DICOM_EXPORT const tag BeamDoseType;
    /** BeamDoseVerificationControlPointSequence, 0x300A008C, SQ, 1 */
    extern DICOM_EXPORT const tag BeamDoseVerificationControlPointSequence;
    /** BeamLimitingDeviceAngle, 0x300A0120, DS, 1 */
    extern DICOM_EXPORT const tag BeamLimitingDeviceAngle;
    /** BeamLimitingDeviceAngleTolerance, 0x300A0046, DS, 1 */
    extern DICOM_EXPORT const tag BeamLimitingDeviceAngleTolerance;
    /** BeamLimitingDeviceLeafPairsSequence, 0x300800A0, SQ, 1 */
    extern DICOM_EXPORT const tag BeamLimitingDeviceLeafPairsSequence;
    /** BeamLimitingDevicePositionSequence, 0x300A011A, SQ, 1 */
    extern DICOM_EXPORT const tag BeamLimitingDevicePositionSequence;
    /** BeamLimitingDevicePositionTolerance, 0x300A004A, DS, 1 */
    extern DICOM_EXPORT const tag BeamLimitingDevicePositionTolerance;
    /** BeamLimitingDeviceRotationDirection, 0x300A0121, CS, 1 */
    extern DICOM_EXPORT const tag BeamLimitingDeviceRotationDirection;
    /** BeamLimitingDeviceSequence, 0x300A00B6, SQ, 1 */
    extern DICOM_EXPORT const tag BeamLimitingDeviceSequence;
    /** BeamLimitingDeviceToleranceSequence, 0x300A0048, SQ, 1 */
    extern DICOM_EXPORT const tag BeamLimitingDeviceToleranceSequence;
    /** BeamMeterset, 0x300A0086, DS, 1 */
    extern DICOM_EXPORT const tag BeamMeterset;
    /** BeamName, 0x300A00C2, LO, 1 */
    extern DICOM_EXPORT const tag BeamName;
    /** BeamNumber, 0x300A00C0, IS, 1 */
    extern DICOM_EXPORT const tag BeamNumber;
    /** BeamOrderIndex, 0x00741324, UL, 1 */
    extern DICOM_EXPORT const tag BeamOrderIndex;
    /** BeamOrderIndexTrial, 0x00741024, IS, 1, RET */
    extern DICOM_EXPORT const tag BeamOrderIndexTrial;
    /** BeamSequence, 0x300A00B0, SQ, 1 */
    extern DICOM_EXPORT const tag BeamSequence;
    /** BeamSpotSize, 0x00520003, FD, 1 */
    extern DICOM_EXPORT const tag BeamSpotSize;
    /** BeamStopperPosition, 0x30080230, CS, 1 */
    extern DICOM_EXPORT const tag BeamStopperPosition;
    /** BeamTaskSequence, 0x00741020, SQ, 1 */
    extern DICOM_EXPORT const tag BeamTaskSequence;
    /** BeamTaskType, 0x00741022, CS, 1 */
    extern DICOM_EXPORT const tag BeamTaskType;
    /** BeamType, 0x300A00C4, CS, 1 */
    extern DICOM_EXPORT const tag BeamType;
    /** BeatRejectionFlag, 0x00181080, CS, 1 */
    extern DICOM_EXPORT const tag BeatRejectionFlag;
    /** BeltHeight, 0x40101062, FL, 1, RET */
    extern DICOM_EXPORT const tag BeltHeight;
    /** BibliographicCitationTrial, 0x0040A16A, ST, 1, RET */
    extern DICOM_EXPORT const tag BibliographicCitationTrial;
    /** BillingItemSequence, 0x00400296, SQ, 1 */
    extern DICOM_EXPORT const tag BillingItemSequence;
    /** BillingProcedureStepSequence, 0x00400320, SQ, 1 */
    extern DICOM_EXPORT const tag BillingProcedureStepSequence;
    /** BillingSuppliesAndDevicesSequence, 0x00400324, SQ, 1 */
    extern DICOM_EXPORT const tag BillingSuppliesAndDevicesSequence;
    /** BiopsyTargetSequence, 0x00182041, SQ, 1 */
    extern DICOM_EXPORT const tag BiopsyTargetSequence;
    /** BiPlaneAcquisitionSequence, 0x00285000, SQ, 1, RET */
    extern DICOM_EXPORT const tag BiPlaneAcquisitionSequence;
    /** BitsAllocated, 0x00280100, US, 1 */
    extern DICOM_EXPORT const tag BitsAllocated;
    /** BitsForCodeWord, 0x00280804, US, 1, RET */
    extern DICOM_EXPORT const range_tag BitsForCodeWord;
    /** BitsGrouped, 0x00280069, US, 1, RET */
    extern DICOM_EXPORT const tag BitsGrouped;
    /** BitsMappedToColorLookupTable, 0x00281403, US, 1 */
    extern DICOM_EXPORT const tag BitsMappedToColorLookupTable;
    /** BitsStored, 0x00280101, US, 1 */
    extern DICOM_EXPORT const tag BitsStored;
    /** BlendingDisplayInputSequence, 0x00701B03, SQ, 1 */
    extern DICOM_EXPORT const tag BlendingDisplayInputSequence;
    /** BlendingDisplaySequence, 0x00701B04, SQ, 1 */
    extern DICOM_EXPORT const tag BlendingDisplaySequence;
    /** BlendingInputNumber, 0x00701B02, US, 1 */
    extern DICOM_EXPORT const tag BlendingInputNumber;
    /** BlendingLookupTableData, 0x00281408, OW, 1 */
    extern DICOM_EXPORT const tag BlendingLookupTableData;
    /** BlendingLookupTableDescriptor, 0x00281407, US, 3 */
    extern DICOM_EXPORT const tag BlendingLookupTableDescriptor;
    /** BlendingLUT1Sequence, 0x00281404, SQ, 1 */
    extern DICOM_EXPORT const tag BlendingLUT1Sequence;
    /** BlendingLUT1TransferFunction, 0x00281405, CS, 1 */
    extern DICOM_EXPORT const tag BlendingLUT1TransferFunction;
    /** BlendingLUT2Sequence, 0x0028140C, SQ, 1 */
    extern DICOM_EXPORT const tag BlendingLUT2Sequence;
    /** BlendingLUT2TransferFunction, 0x0028140D, CS, 1 */
    extern DICOM_EXPORT const tag BlendingLUT2TransferFunction;
    /** BlendingMode, 0x00701B06, CS, 1 */
    extern DICOM_EXPORT const tag BlendingMode;
    /** BlendingOperationType, 0x00720500, CS, 1 */
    extern DICOM_EXPORT const tag BlendingOperationType;
    /** BlendingPosition, 0x00700405, CS, 1 */
    extern DICOM_EXPORT const tag BlendingPosition;
    /** BlendingSequence, 0x00700402, SQ, 1 */
    extern DICOM_EXPORT const tag BlendingSequence;
    /** BlendingWeightConstant, 0x00281406, FD, 1 */
    extern DICOM_EXPORT const tag BlendingWeightConstant;
    /** BlindSpotLocalized, 0x00240106, CS, 1 */
    extern DICOM_EXPORT const tag BlindSpotLocalized;
    /** BlindSpotXCoordinate, 0x00240107, FL, 1 */
    extern DICOM_EXPORT const tag BlindSpotXCoordinate;
    /** BlindSpotYCoordinate, 0x00240108, FL, 1 */
    extern DICOM_EXPORT const tag BlindSpotYCoordinate;
    /** BlockColumns, 0x00280092, US, 1, RET */
    extern DICOM_EXPORT const tag BlockColumns;
    /** BlockData, 0x300A0106, DS, 2 */
    extern DICOM_EXPORT const tag BlockData;
    /** BlockDivergence, 0x300A00FA, CS, 1 */
    extern DICOM_EXPORT const tag BlockDivergence;
    /** BlockedPixels, 0x00280090, CS, 1, RET */
    extern DICOM_EXPORT const tag BlockedPixels;
    /** BlockIdentifyingInformationStatus, 0x00080303, CS, 1 */
    extern DICOM_EXPORT const tag BlockIdentifyingInformationStatus;
    /** BlockMountingPosition, 0x300A00FB, CS, 1 */
    extern DICOM_EXPORT const tag BlockMountingPosition;
    /** BlockName, 0x300A00FE, LO, 1 */
    extern DICOM_EXPORT const tag BlockName;
    /** BlockNumber, 0x300A00FC, IS, 1 */
    extern DICOM_EXPORT const tag BlockNumber;
    /** BlockNumberOfPoints, 0x300A0104, IS, 1 */
    extern DICOM_EXPORT const tag BlockNumberOfPoints;
    /** BlockRows, 0x00280091, US, 1, RET */
    extern DICOM_EXPORT const tag BlockRows;
    /** BlockSequence, 0x300A00F4, SQ, 1 */
    extern DICOM_EXPORT const tag BlockSequence;
    /** BlockSlabNumber, 0x300A0443, US, 1 */
    extern DICOM_EXPORT const tag BlockSlabNumber;
    /** BlockSlabSequence, 0x300A0441, SQ, 1 */
    extern DICOM_EXPORT const tag BlockSlabSequence;
    /** BlockSlabThickness, 0x300A0442, DS, 1 */
    extern DICOM_EXPORT const tag BlockSlabThickness;
    /** BlockThickness, 0x300A0100, DS, 1 */
    extern DICOM_EXPORT const tag BlockThickness;
    /** BlockTransmission, 0x300A0102, DS, 1 */
    extern DICOM_EXPORT const tag BlockTransmission;
    /** BlockTrayID, 0x300A00F5, SH, 1 */
    extern DICOM_EXPORT const tag BlockTrayID;
    /** BlockType, 0x300A00F8, CS, 1 */
    extern DICOM_EXPORT const tag BlockType;
    /** BloodSignalNulling, 0x00189022, CS, 1 */
    extern DICOM_EXPORT const tag BloodSignalNulling;
    /** BluePaletteColorLookupTableData, 0x00281203, OW, 1 */
    extern DICOM_EXPORT const tag BluePaletteColorLookupTableData;
    /** BluePaletteColorLookupTableDescriptor, 0x00281103, US or SS, 3 */
    extern DICOM_EXPORT const tag BluePaletteColorLookupTableDescriptor;
    /** BoardingPassID, 0x4010101A, SH, 1, RET */
    extern DICOM_EXPORT const tag BoardingPassID;
    /** BodyPartExamined, 0x00180015, CS, 1 */
    extern DICOM_EXPORT const tag BodyPartExamined;
    /** BodyPartThickness, 0x001811A0, DS, 1 */
    extern DICOM_EXPORT const tag BodyPartThickness;
    /** Bold, 0x00700249, CS, 1 */
    extern DICOM_EXPORT const tag Bold;
    /** BolusDescription, 0x300A00DD, ST, 1 */
    extern DICOM_EXPORT const tag BolusDescription;
    /** BolusID, 0x300A00DC, SH, 1 */
    extern DICOM_EXPORT const tag BolusID;
    /** BoneThermalIndex, 0x00185024, DS, 1 */
    extern DICOM_EXPORT const tag BoneThermalIndex;
    /** BorderDensity, 0x20100100, CS, 1 */
    extern DICOM_EXPORT const tag BorderDensity;
    /** BottomRightHandCornerOfLocalizerArea, 0x00480202, US, 2 */
    extern DICOM_EXPORT const tag BottomRightHandCornerOfLocalizerArea;
    /** BoundingBoxAnnotationUnits, 0x00700003, CS, 1 */
    extern DICOM_EXPORT const tag BoundingBoxAnnotationUnits;
    /** BoundingBoxBottomRightHandCorner, 0x00700011, FL, 2 */
    extern DICOM_EXPORT const tag BoundingBoxBottomRightHandCorner;
    /** BoundingBoxCrop, 0x00701303, FD, 6 */
    extern DICOM_EXPORT const tag BoundingBoxCrop;
    /** BoundingBoxTextHorizontalJustification, 0x00700012, CS, 1 */
    extern DICOM_EXPORT const tag BoundingBoxTextHorizontalJustification;
    /** BoundingBoxTopLeftHandCorner, 0x00700010, FL, 2 */
    extern DICOM_EXPORT const tag BoundingBoxTopLeftHandCorner;
    /** BoundingPolygon, 0x4010101D, FL, 6, RET */
    extern DICOM_EXPORT const tag BoundingPolygon;
    /** BoundingRectangle, 0x00686347, FD, 4 */
    extern DICOM_EXPORT const tag BoundingRectangle;
    /** BrachyAccessoryDeviceID, 0x300A0263, SH, 1 */
    extern DICOM_EXPORT const tag BrachyAccessoryDeviceID;
    /** BrachyAccessoryDeviceName, 0x300A0266, LO, 1 */
    extern DICOM_EXPORT const tag BrachyAccessoryDeviceName;
    /** BrachyAccessoryDeviceNominalThickness, 0x300A026A, DS, 1 */
    extern DICOM_EXPORT const tag BrachyAccessoryDeviceNominalThickness;
    /** BrachyAccessoryDeviceNominalTransmission, 0x300A026C, DS, 1 */
    extern DICOM_EXPORT const tag BrachyAccessoryDeviceNominalTransmission;
    /** BrachyAccessoryDeviceNumber, 0x300A0262, IS, 1 */
    extern DICOM_EXPORT const tag BrachyAccessoryDeviceNumber;
    /** BrachyAccessoryDeviceSequence, 0x300A0260, SQ, 1 */
    extern DICOM_EXPORT const tag BrachyAccessoryDeviceSequence;
    /** BrachyAccessoryDeviceType, 0x300A0264, CS, 1 */
    extern DICOM_EXPORT const tag BrachyAccessoryDeviceType;
    /** BrachyApplicationSetupDose, 0x300A00A4, DS, 1 */
    extern DICOM_EXPORT const tag BrachyApplicationSetupDose;
    /** BrachyApplicationSetupDoseSpecificationPoint, 0x300A00A2, DS, 3 */
    extern DICOM_EXPORT const tag BrachyApplicationSetupDoseSpecificationPoint;
    /** BrachyControlPointDeliveredSequence, 0x30080160, SQ, 1 */
    extern DICOM_EXPORT const tag BrachyControlPointDeliveredSequence;
    /** BrachyControlPointSequence, 0x300A02D0, SQ, 1 */
    extern DICOM_EXPORT const tag BrachyControlPointSequence;
    /** BrachyPulseControlPointDeliveredSequence, 0x30080173, SQ, 1 */
    extern DICOM_EXPORT const tag BrachyPulseControlPointDeliveredSequence;
    /** BrachyReferencedDoseReferenceSequence, 0x300C0055, SQ, 1 */
    extern DICOM_EXPORT const tag BrachyReferencedDoseReferenceSequence;
    /** BrachyTaskSequence, 0x00741401, SQ, 1 */
    extern DICOM_EXPORT const tag BrachyTaskSequence;
    /** BrachyTreatmentTechnique, 0x300A0200, CS, 1 */
    extern DICOM_EXPORT const tag BrachyTreatmentTechnique;
    /** BrachyTreatmentType, 0x300A0202, CS, 1 */
    extern DICOM_EXPORT const tag BrachyTreatmentType;
    /** BranchOfService, 0x00101081, LO, 1 */
    extern DICOM_EXPORT const tag BranchOfService;
    /** BreastImplantPresent, 0x00281300, CS, 1 */
    extern DICOM_EXPORT const tag BreastImplantPresent;
    /** BreastSupportIsocenterPrimaryAngle, 0x00189545, FD, 1 */
    extern DICOM_EXPORT const tag BreastSupportIsocenterPrimaryAngle;
    /** BreastSupportIsocenterSecondaryAngle, 0x00189546, FD, 1 */
    extern DICOM_EXPORT const tag BreastSupportIsocenterSecondaryAngle;
    /** BreastSupportXPositionToIsocenter, 0x00189547, FD, 1 */
    extern DICOM_EXPORT const tag BreastSupportXPositionToIsocenter;
    /** BreastSupportYPositionToIsocenter, 0x00189548, FD, 1 */
    extern DICOM_EXPORT const tag BreastSupportYPositionToIsocenter;
    /** BreastSupportZPositionToIsocenter, 0x00189549, FD, 1 */
    extern DICOM_EXPORT const tag BreastSupportZPositionToIsocenter;
    /** BreedRegistrationNumber, 0x00102295, LO, 1 */
    extern DICOM_EXPORT const tag BreedRegistrationNumber;
    /** BreedRegistrationSequence, 0x00102294, SQ, 1 */
    extern DICOM_EXPORT const tag BreedRegistrationSequence;
    /** BreedRegistryCodeSequence, 0x00102296, SQ, 1 */
    extern DICOM_EXPORT const tag BreedRegistryCodeSequence;
    /** BridgeResistors, 0x00144088, DS, 1, RET */
    extern DICOM_EXPORT const tag BridgeResistors;
    /** BscanCycleTime, 0x00221645, FL, 1 */
    extern DICOM_EXPORT const tag BscanCycleTime;
    /** BscanCycleTimeVector, 0x00221646, FL, 1 */
    extern DICOM_EXPORT const tag BscanCycleTimeVector;
    /** BscanRate, 0x00221650, FL, 1 */
    extern DICOM_EXPORT const tag BscanRate;
    /** BscanSlabThickness, 0x00221643, FL, 1 */
    extern DICOM_EXPORT const tag BscanSlabThickness;
    /** BulkMotionCompensationTechnique, 0x00189172, CS, 1 */
    extern DICOM_EXPORT const tag BulkMotionCompensationTechnique;
    /** BulkMotionSignalSource, 0x00189173, CS, 1 */
    extern DICOM_EXPORT const tag BulkMotionSignalSource;
    /** BulkMotionStatus, 0x00189166, CS, 1, RET */
    extern DICOM_EXPORT const tag BulkMotionStatus;
    /** BurnedInAnnotation, 0x00280301, CS, 1 */
    extern DICOM_EXPORT const tag BurnedInAnnotation;
    /** CADFileFormat, 0x00140023, ST, 1, RET */
    extern DICOM_EXPORT const tag CADFileFormat;
    /** CalciumScoringMassFactorDevice, 0x00189352, FL, 3 */
    extern DICOM_EXPORT const tag CalciumScoringMassFactorDevice;
    /** CalciumScoringMassFactorPatient, 0x00189351, FL, 1 */
    extern DICOM_EXPORT const tag CalciumScoringMassFactorPatient;
    /** CalculatedAnatomyThickness, 0x00189452, FL, 1 */
    extern DICOM_EXPORT const tag CalculatedAnatomyThickness;
    /** CalculatedDoseReferenceDescription, 0x30080074, ST, 1 */
    extern DICOM_EXPORT const tag CalculatedDoseReferenceDescription;
    /** CalculatedDoseReferenceDoseValue, 0x30080076, DS, 1 */
    extern DICOM_EXPORT const tag CalculatedDoseReferenceDoseValue;
    /** CalculatedDoseReferenceNumber, 0x30080072, IS, 1 */
    extern DICOM_EXPORT const tag CalculatedDoseReferenceNumber;
    /** CalculatedDoseReferenceSequence, 0x30080070, SQ, 1 */
    extern DICOM_EXPORT const tag CalculatedDoseReferenceSequence;
    /** CalculatedFrameList, 0x00081162, UL, 3 */
    extern DICOM_EXPORT const tag CalculatedFrameList;
    /** CalculatedTargetPosition, 0x00182044, FL, 3 */
    extern DICOM_EXPORT const tag CalculatedTargetPosition;
    /** CalibrationDataSequence, 0x00540306, SQ, 1 */
    extern DICOM_EXPORT const tag CalibrationDataSequence;
    /** CalibrationDate, 0x0014407E, DA, 1, RET */
    extern DICOM_EXPORT const tag CalibrationDate;
    /** CalibrationImage, 0x00500004, CS, 1 */
    extern DICOM_EXPORT const tag CalibrationImage;
    /** CalibrationNotes, 0x00143099, LT, 1, RET */
    extern DICOM_EXPORT const tag CalibrationNotes;
    /** CalibrationProcedure, 0x00144072, ST, 1, RET */
    extern DICOM_EXPORT const tag CalibrationProcedure;
    /** CalibrationSequence, 0x00189455, SQ, 1 */
    extern DICOM_EXPORT const tag CalibrationSequence;
    /** CalibrationSettingsSequence, 0x00144070, SQ, 1, RET */
    extern DICOM_EXPORT const tag CalibrationSettingsSequence;
    /** CalibrationTime, 0x0014407C, TM, 1, RET */
    extern DICOM_EXPORT const tag CalibrationTime;
    /** CameraAngleOfView, 0x0022001E, FL, 1 */
    extern DICOM_EXPORT const tag CameraAngleOfView;
    /** CardiacBeatRejectionTechnique, 0x00189169, CS, 1 */
    extern DICOM_EXPORT const tag CardiacBeatRejectionTechnique;
    /** CardiacCyclePosition, 0x00189236, CS, 1 */
    extern DICOM_EXPORT const tag CardiacCyclePosition;
    /** CardiacFramingType, 0x00181064, LO, 1 */
    extern DICOM_EXPORT const tag CardiacFramingType;
    /** CardiacNumberOfImages, 0x00181090, IS, 1 */
    extern DICOM_EXPORT const tag CardiacNumberOfImages;
    /** CardiacRRIntervalSpecified, 0x00189070, FD, 1 */
    extern DICOM_EXPORT const tag CardiacRRIntervalSpecified;
    /** CardiacSignalSource, 0x00189085, CS, 1 */
    extern DICOM_EXPORT const tag CardiacSignalSource;
    /** CardiacSynchronizationSequence, 0x00189118, SQ, 1 */
    extern DICOM_EXPORT const tag CardiacSynchronizationSequence;
    /** CardiacSynchronizationTechnique, 0x00189037, CS, 1 */
    extern DICOM_EXPORT const tag CardiacSynchronizationTechnique;
    /** CArmPositionerTabletopRelationship, 0x00189474, CS, 1 */
    extern DICOM_EXPORT const tag CArmPositionerTabletopRelationship;
    /** CarrierID, 0x40101058, SH, 1, RET */
    extern DICOM_EXPORT const tag CarrierID;
    /** CarrierIDAssigningAuthority, 0x40101059, CS, 1, RET */
    extern DICOM_EXPORT const tag CarrierIDAssigningAuthority;
    /** CassetteID, 0x00181007, LO, 1 */
    extern DICOM_EXPORT const tag CassetteID;
    /** CassetteOrientation, 0x00181402, CS, 1 */
    extern DICOM_EXPORT const tag CassetteOrientation;
    /** CassetteSize, 0x00181403, CS, 1 */
    extern DICOM_EXPORT const tag CassetteSize;
    /** CatchTrialsDataFlag, 0x00240055, CS, 1 */
    extern DICOM_EXPORT const tag CatchTrialsDataFlag;
    /** CatheterDirectionOfRotation, 0x00520031, CS, 1 */
    extern DICOM_EXPORT const tag CatheterDirectionOfRotation;
    /** CatheterRotationalRate, 0x00520013, FD, 1 */
    extern DICOM_EXPORT const tag CatheterRotationalRate;
    /** CenterOfCircularCollimator, 0x00181710, IS, 2 */
    extern DICOM_EXPORT const tag CenterOfCircularCollimator;
    /** CenterOfCircularExposureControlSensingRegion, 0x00189440, SS, 2 */
    extern DICOM_EXPORT const tag CenterOfCircularExposureControlSensingRegion;
    /** CenterOfCircularShutter, 0x00181610, IS, 2 */
    extern DICOM_EXPORT const tag CenterOfCircularShutter;
    /** CenterOfMass, 0x4010101B, FL, 3, RET */
    extern DICOM_EXPORT const tag CenterOfMass;
    /** CenterOfPTO, 0x4010101C, FL, 3, RET */
    extern DICOM_EXPORT const tag CenterOfPTO;
    /** CenterOfRotation, 0x0066001C, FL, 3 */
    extern DICOM_EXPORT const tag CenterOfRotation;
    /** CenterOfRotationOffset, 0x00181145, DS, 1 */
    extern DICOM_EXPORT const tag CenterOfRotationOffset;
    /** CertificateOfSigner, 0x04000115, OB, 1 */
    extern DICOM_EXPORT const tag CertificateOfSigner;
    /** CertificateType, 0x04000110, CS, 1 */
    extern DICOM_EXPORT const tag CertificateType;
    /** CertifiedTimestamp, 0x04000310, OB, 1 */
    extern DICOM_EXPORT const tag CertifiedTimestamp;
    /** CertifiedTimestampType, 0x04000305, CS, 1 */
    extern DICOM_EXPORT const tag CertifiedTimestampType;
    /** ChairHeadFramePosition, 0x300A0151, DS, 1 */
    extern DICOM_EXPORT const tag ChairHeadFramePosition;
    /** ChairHeadFramePositionTolerance, 0x300A0153, DS, 1 */
    extern DICOM_EXPORT const tag ChairHeadFramePositionTolerance;
    /** ChannelBaseline, 0x003A0213, DS, 1 */
    extern DICOM_EXPORT const tag ChannelBaseline;
    /** ChannelDefinitionSequence, 0x003A0200, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelDefinitionSequence;
    /** ChannelDeliveryContinuationSequence, 0x0074140D, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelDeliveryContinuationSequence;
    /** ChannelDeliveryOrderIndex, 0x0074140C, IS, 1 */
    extern DICOM_EXPORT const tag ChannelDeliveryOrderIndex;
    /** ChannelDeliveryOrderSequence, 0x00741405, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelDeliveryOrderSequence;
    /** ChannelDerivationDescription, 0x003A020C, LO, 1 */
    extern DICOM_EXPORT const tag ChannelDerivationDescription;
    /** ChannelDescriptionCodeSequence, 0x0022001A, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelDescriptionCodeSequence;
    /** ChannelDisplaySequence, 0x003A0242, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelDisplaySequence;
    /** ChannelEffectiveLength, 0x300A0271, DS, 1 */
    extern DICOM_EXPORT const tag ChannelEffectiveLength;
    /** ChannelIdentificationCode, 0x003A0301, IS, 1 */
    extern DICOM_EXPORT const tag ChannelIdentificationCode;
    /** ChannelInnerLength, 0x300A0272, DS, 1 */
    extern DICOM_EXPORT const tag ChannelInnerLength;
    /** ChannelLabel, 0x003A0203, SH, 1 */
    extern DICOM_EXPORT const tag ChannelLabel;
    /** ChannelLength, 0x300A0284, DS, 1 */
    extern DICOM_EXPORT const tag ChannelLength;
    /** ChannelMaximumValue, 0x54000112, OB or OW, 1 */
    extern DICOM_EXPORT const tag ChannelMaximumValue;
    /** ChannelMinimumValue, 0x54000110, OB or OW, 1 */
    extern DICOM_EXPORT const tag ChannelMinimumValue;
    /** ChannelMode, 0x003A0302, CS, 1 */
    extern DICOM_EXPORT const tag ChannelMode;
    /** ChannelNumber, 0x300A0282, IS, 1 */
    extern DICOM_EXPORT const tag ChannelNumber;
    /** ChannelOffset, 0x003A0218, DS, 1 */
    extern DICOM_EXPORT const tag ChannelOffset;
    /** ChannelOverlap, 0x0014409F, DS, 1, RET */
    extern DICOM_EXPORT const tag ChannelOverlap;
    /** ChannelPosition, 0x003A0245, FL, 1 */
    extern DICOM_EXPORT const tag ChannelPosition;
    /** ChannelRecommendedDisplayCIELabValue, 0x003A0244, US, 3 */
    extern DICOM_EXPORT const tag ChannelRecommendedDisplayCIELabValue;
    /** ChannelSampleSkew, 0x003A0215, DS, 1 */
    extern DICOM_EXPORT const tag ChannelSampleSkew;
    /** ChannelSensitivity, 0x003A0210, DS, 1 */
    extern DICOM_EXPORT const tag ChannelSensitivity;
    /** ChannelSensitivityCorrectionFactor, 0x003A0212, DS, 1 */
    extern DICOM_EXPORT const tag ChannelSensitivityCorrectionFactor;
    /** ChannelSensitivityUnitsSequence, 0x003A0211, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelSensitivityUnitsSequence;
    /** ChannelSequence, 0x300A0280, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelSequence;
    /** ChannelSettingsSequence, 0x00144091, SQ, 1, RET */
    extern DICOM_EXPORT const tag ChannelSettingsSequence;
    /** ChannelShieldID, 0x300A02B3, SH, 1 */
    extern DICOM_EXPORT const tag ChannelShieldID;
    /** ChannelShieldName, 0x300A02B4, LO, 1 */
    extern DICOM_EXPORT const tag ChannelShieldName;
    /** ChannelShieldNominalThickness, 0x300A02B8, DS, 1 */
    extern DICOM_EXPORT const tag ChannelShieldNominalThickness;
    /** ChannelShieldNominalTransmission, 0x300A02BA, DS, 1 */
    extern DICOM_EXPORT const tag ChannelShieldNominalTransmission;
    /** ChannelShieldNumber, 0x300A02B2, IS, 1 */
    extern DICOM_EXPORT const tag ChannelShieldNumber;
    /** ChannelShieldSequence, 0x300A02B0, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelShieldSequence;
    /** ChannelSourceModifiersSequence, 0x003A0209, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelSourceModifiersSequence;
    /** ChannelSourceSequence, 0x003A0208, SQ, 1 */
    extern DICOM_EXPORT const tag ChannelSourceSequence;
    /** ChannelStatus, 0x003A0205, CS, 1 */
    extern DICOM_EXPORT const tag ChannelStatus;
    /** ChannelThreshold, 0x00144092, DS, 1, RET */
    extern DICOM_EXPORT const tag ChannelThreshold;
    /** ChannelTimeSkew, 0x003A0214, DS, 1 */
    extern DICOM_EXPORT const tag ChannelTimeSkew;
    /** ChannelTotalTime, 0x300A0286, DS, 1 */
    extern DICOM_EXPORT const tag ChannelTotalTime;
    /** ChannelWidth, 0x00460042, FD, 1 */
    extern DICOM_EXPORT const tag ChannelWidth;
    /** ChemicalShiftMaximumIntegrationLimitInHz, 0x00189196, FD, 1, RET */
    extern DICOM_EXPORT const tag ChemicalShiftMaximumIntegrationLimitInHz;
    /** ChemicalShiftMaximumIntegrationLimitInppm, 0x00189296, FD, 1 */
    extern DICOM_EXPORT const tag ChemicalShiftMaximumIntegrationLimitInppm;
    /** ChemicalShiftMinimumIntegrationLimitInHz, 0x00189195, FD, 1, RET */
    extern DICOM_EXPORT const tag ChemicalShiftMinimumIntegrationLimitInHz;
    /** ChemicalShiftMinimumIntegrationLimitInppm, 0x00189295, FD, 1 */
    extern DICOM_EXPORT const tag ChemicalShiftMinimumIntegrationLimitInppm;
    /** ChemicalShiftReference, 0x00189053, FD, 1 */
    extern DICOM_EXPORT const tag ChemicalShiftReference;
    /** ChemicalShiftSequence, 0x00189084, SQ, 1 */
    extern DICOM_EXPORT const tag ChemicalShiftSequence;
    /** CIExyWhitePoint, 0x00287018, FL, 2 */
    extern DICOM_EXPORT const tag CIExyWhitePoint;
    /** CineRate, 0x00180040, IS, 1 */
    extern DICOM_EXPORT const tag CineRate;
    /** CineRelativeToRealTime, 0x00720330, FD, 1 */
    extern DICOM_EXPORT const tag CineRelativeToRealTime;
    /** ClinicalTrialCoordinatingCenterName, 0x00120060, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialCoordinatingCenterName;
    /** ClinicalTrialProtocolEthicsCommitteeApprovalNumber, 0x00120082, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialProtocolEthicsCommitteeApprovalNumber;
    /** ClinicalTrialProtocolEthicsCommitteeName, 0x00120081, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialProtocolEthicsCommitteeName;
    /** ClinicalTrialProtocolID, 0x00120020, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialProtocolID;
    /** ClinicalTrialProtocolName, 0x00120021, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialProtocolName;
    /** ClinicalTrialSeriesDescription, 0x00120072, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialSeriesDescription;
    /** ClinicalTrialSeriesID, 0x00120071, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialSeriesID;
    /** ClinicalTrialSiteID, 0x00120030, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialSiteID;
    /** ClinicalTrialSiteName, 0x00120031, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialSiteName;
    /** ClinicalTrialSponsorName, 0x00120010, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialSponsorName;
    /** ClinicalTrialSubjectID, 0x00120040, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialSubjectID;
    /** ClinicalTrialSubjectReadingID, 0x00120042, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialSubjectReadingID;
    /** ClinicalTrialTimePointDescription, 0x00120051, ST, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialTimePointDescription;
    /** ClinicalTrialTimePointID, 0x00120050, LO, 1 */
    extern DICOM_EXPORT const tag ClinicalTrialTimePointID;
    /** CoatingMaterialsCodeSequence, 0x006863A4, SQ, 1 */
    extern DICOM_EXPORT const tag CoatingMaterialsCodeSequence;
    /** CodeLabel, 0x00280800, CS, 1, RET */
    extern DICOM_EXPORT const range_tag CodeLabel;
    /** CodeMeaning, 0x00080104, LO, 1 */
    extern DICOM_EXPORT const tag CodeMeaning;
    /** CodeNumberFormat, 0x00280740, US, 1, RET */
    extern DICOM_EXPORT const tag CodeNumberFormat;
    /** CodeTableLocation, 0x00280803, AT, 1, RET */
    extern DICOM_EXPORT const range_tag CodeTableLocation;
    /** CodeValue, 0x00080100, SH, 1 */
    extern DICOM_EXPORT const tag CodeValue;
    /** CodingSchemeDesignator, 0x00080102, SH, 1 */
    extern DICOM_EXPORT const tag CodingSchemeDesignator;
    /** CodingSchemeExternalID, 0x00080114, ST, 1 */
    extern DICOM_EXPORT const tag CodingSchemeExternalID;
    /** CodingSchemeIdentificationSequence, 0x00080110, SQ, 1 */
    extern DICOM_EXPORT const tag CodingSchemeIdentificationSequence;
    /** CodingSchemeName, 0x00080115, ST, 1 */
    extern DICOM_EXPORT const tag CodingSchemeName;
    /** CodingSchemeRegistry, 0x00080112, LO, 1 */
    extern DICOM_EXPORT const tag CodingSchemeRegistry;
    /** CodingSchemeResourcesSequence, 0x00080109, SQ, 1 */
    extern DICOM_EXPORT const tag CodingSchemeResourcesSequence;
    /** CodingSchemeResponsibleOrganization, 0x00080116, ST, 1 */
    extern DICOM_EXPORT const tag CodingSchemeResponsibleOrganization;
    /** CodingSchemeUID, 0x0008010C, UI, 1 */
    extern DICOM_EXPORT const tag CodingSchemeUID;
    /** CodingSchemeURL, 0x0008010E, UR, 1 */
    extern DICOM_EXPORT const tag CodingSchemeURL;
    /** CodingSchemeURLType, 0x0008010A, CS, 1 */
    extern DICOM_EXPORT const tag CodingSchemeURLType;
    /** CodingSchemeVersion, 0x00080103, SH, 1 */
    extern DICOM_EXPORT const tag CodingSchemeVersion;
    /** CoefficientCoding, 0x00280402, LO, 1, RET */
    extern DICOM_EXPORT const range_tag CoefficientCoding;
    /** CoefficientCodingPointers, 0x00280403, AT, 1, RET */
    extern DICOM_EXPORT const range_tag CoefficientCodingPointers;
    /** CoefficientsSDDN, 0x7FE00040, OW, 1, RET */
    extern DICOM_EXPORT const tag CoefficientsSDDN;
    /** CoefficientsSDHN, 0x7FE00030, OW, 1, RET */
    extern DICOM_EXPORT const tag CoefficientsSDHN;
    /** CoefficientsSDVN, 0x7FE00020, OW, 1, RET */
    extern DICOM_EXPORT const tag CoefficientsSDVN;
    /** CoincidenceWindowWidth, 0x00541210, DS, 1 */
    extern DICOM_EXPORT const tag CoincidenceWindowWidth;
    /** CollationFlag, 0x20000063, CS, 1, RET */
    extern DICOM_EXPORT const tag CollationFlag;
    /** CollimatorGridName, 0x00181180, SH, 1 */
    extern DICOM_EXPORT const tag CollimatorGridName;
    /** CollimatorLeftVerticalEdge, 0x00181702, IS, 1 */
    extern DICOM_EXPORT const tag CollimatorLeftVerticalEdge;
    /** CollimatorLowerHorizontalEdge, 0x00181708, IS, 1 */
    extern DICOM_EXPORT const tag CollimatorLowerHorizontalEdge;
    /** CollimatorRightVerticalEdge, 0x00181704, IS, 1 */
    extern DICOM_EXPORT const tag CollimatorRightVerticalEdge;
    /** CollimatorShape, 0x00181700, CS, 1 */
    extern DICOM_EXPORT const tag CollimatorShape;
    /** CollimatorShapeSequence, 0x00189407, SQ, 1 */
    extern DICOM_EXPORT const tag CollimatorShapeSequence;
    /** CollimatorType, 0x00181181, CS, 1 */
    extern DICOM_EXPORT const tag CollimatorType;
    /** CollimatorUpperHorizontalEdge, 0x00181706, IS, 1 */
    extern DICOM_EXPORT const tag CollimatorUpperHorizontalEdge;
    /** ColorImagePrintingFlag, 0x20000062, CS, 1, RET */
    extern DICOM_EXPORT const tag ColorImagePrintingFlag;
    /** ColorSpace, 0x00282002, CS, 1 */
    extern DICOM_EXPORT const tag ColorSpace;
    /** ColumnAngulation, 0x00181450, DS, 1 */
    extern DICOM_EXPORT const tag ColumnAngulation;
    /** ColumnAngulationPatient, 0x00189447, FL, 1 */
    extern DICOM_EXPORT const tag ColumnAngulationPatient;
    /** ColumnOverlap, 0x00280094, US, 1, RET */
    extern DICOM_EXPORT const tag ColumnOverlap;
    /** ColumnPositionInTotalImagePixelMatrix, 0x0048021E, SL, 1 */
    extern DICOM_EXPORT const tag ColumnPositionInTotalImagePixelMatrix;
    /** Columns, 0x00280011, US, 1 */
    extern DICOM_EXPORT const tag Columns;
    /** ColumnsForNthOrderCoefficients, 0x00280401, US, 1, RET */
    extern DICOM_EXPORT const range_tag ColumnsForNthOrderCoefficients;
    /** CommentsOnPatientPerformanceOfVisualField, 0x00240044, LT, 1 */
    extern DICOM_EXPORT const tag CommentsOnPatientPerformanceOfVisualField;
    /** CommentsOnRadiationDose, 0x00400310, ST, 1 */
    extern DICOM_EXPORT const tag CommentsOnRadiationDose;
    /** CommentsOnThePerformedProcedureStep, 0x00400280, ST, 1 */
    extern DICOM_EXPORT const tag CommentsOnThePerformedProcedureStep;
    /** CommentsOnTheScheduledProcedureStep, 0x00400400, LT, 1 */
    extern DICOM_EXPORT const tag CommentsOnTheScheduledProcedureStep;
    /** CompensatorColumnOffset, 0x300A02E5, FL, 1 */
    extern DICOM_EXPORT const tag CompensatorColumnOffset;
    /** CompensatorColumns, 0x300A00E8, IS, 1 */
    extern DICOM_EXPORT const tag CompensatorColumns;
    /** CompensatorDescription, 0x300A02EB, LT, 1 */
    extern DICOM_EXPORT const tag CompensatorDescription;
    /** CompensatorDivergence, 0x300A02E0, CS, 1 */
    extern DICOM_EXPORT const tag CompensatorDivergence;
    /** CompensatorID, 0x300A00E5, SH, 1 */
    extern DICOM_EXPORT const tag CompensatorID;
    /** CompensatorMillingToolDiameter, 0x300A02E8, FL, 1 */
    extern DICOM_EXPORT const tag CompensatorMillingToolDiameter;
    /** CompensatorMountingPosition, 0x300A02E1, CS, 1 */
    extern DICOM_EXPORT const tag CompensatorMountingPosition;
    /** CompensatorNumber, 0x300A00E4, IS, 1 */
    extern DICOM_EXPORT const tag CompensatorNumber;
    /** CompensatorPixelSpacing, 0x300A00E9, DS, 2 */
    extern DICOM_EXPORT const tag CompensatorPixelSpacing;
    /** CompensatorPosition, 0x300A00EA, DS, 2 */
    extern DICOM_EXPORT const tag CompensatorPosition;
    /** CompensatorRelativeStoppingPowerRatio, 0x300A02E7, FL, 1 */
    extern DICOM_EXPORT const tag CompensatorRelativeStoppingPowerRatio;
    /** CompensatorRows, 0x300A00E7, IS, 1 */
    extern DICOM_EXPORT const tag CompensatorRows;
    /** CompensatorSequence, 0x300A00E3, SQ, 1 */
    extern DICOM_EXPORT const tag CompensatorSequence;
    /** CompensatorThicknessData, 0x300A00EC, DS, 1 */
    extern DICOM_EXPORT const tag CompensatorThicknessData;
    /** CompensatorTransmissionData, 0x300A00EB, DS, 1 */
    extern DICOM_EXPORT const tag CompensatorTransmissionData;
    /** CompensatorTrayID, 0x300A00EF, SH, 1 */
    extern DICOM_EXPORT const tag CompensatorTrayID;
    /** CompensatorType, 0x300A00EE, CS, 1 */
    extern DICOM_EXPORT const tag CompensatorType;
    /** CompletionFlag, 0x0040A491, CS, 1 */
    extern DICOM_EXPORT const tag CompletionFlag;
    /** CompletionFlagDescription, 0x0040A492, LO, 1 */
    extern DICOM_EXPORT const tag CompletionFlagDescription;
    /** ComplexImageComponent, 0x00089208, CS, 1 */
    extern DICOM_EXPORT const tag ComplexImageComponent;
    /** Component1ReferencedID, 0x00760070, US, 1 */
    extern DICOM_EXPORT const tag Component1ReferencedID;
    /** Component1ReferencedMatingFeatureID, 0x00760090, US, 1 */
    extern DICOM_EXPORT const tag Component1ReferencedMatingFeatureID;
    /** Component1ReferencedMatingFeatureSetID, 0x00760080, US, 1 */
    extern DICOM_EXPORT const tag Component1ReferencedMatingFeatureSetID;
    /** Component2ReferencedID, 0x007600A0, US, 1 */
    extern DICOM_EXPORT const tag Component2ReferencedID;
    /** Component2ReferencedMatingFeatureID, 0x007600C0, US, 1 */
    extern DICOM_EXPORT const tag Component2ReferencedMatingFeatureID;
    /** Component2ReferencedMatingFeatureSetID, 0x007600B0, US, 1 */
    extern DICOM_EXPORT const tag Component2ReferencedMatingFeatureSetID;
    /** ComponentAssemblySequence, 0x00760060, SQ, 1 */
    extern DICOM_EXPORT const tag ComponentAssemblySequence;
    /** ComponentID, 0x00760055, US, 1 */
    extern DICOM_EXPORT const tag ComponentID;
    /** ComponentInputSequence, 0x00701803, SQ, 1 */
    extern DICOM_EXPORT const tag ComponentInputSequence;
    /** ComponentManufacturer, 0x00140028, ST, 1, RET */
    extern DICOM_EXPORT const tag ComponentManufacturer;
    /** ComponentManufacturingProcedure, 0x00140025, ST, 1, RET */
    extern DICOM_EXPORT const tag ComponentManufacturingProcedure;
    /** ComponentReferenceSystem, 0x00140024, ST, 1, RET */
    extern DICOM_EXPORT const tag ComponentReferenceSystem;
    /** ComponentSequence, 0x00760040, SQ, 1 */
    extern DICOM_EXPORT const tag ComponentSequence;
    /** ComponentShape, 0x00140050, CS, 1, RET */
    extern DICOM_EXPORT const tag ComponentShape;
    /** ComponentType, 0x00701802, CS, 1 */
    extern DICOM_EXPORT const tag ComponentType;
    /** ComponentTypeCodeSequence, 0x00760034, SQ, 1 */
    extern DICOM_EXPORT const tag ComponentTypeCodeSequence;
    /** ComponentTypesSequence, 0x00760032, SQ, 1 */
    extern DICOM_EXPORT const tag ComponentTypesSequence;
    /** ComponentWelderIDs, 0x00140100, LO, 1, RET */
    extern DICOM_EXPORT const tag ComponentWelderIDs;
    /** CompositingMethod, 0x00701206, CS, 1, RET */
    extern DICOM_EXPORT const tag CompositingMethod;
    /** CompoundGraphicInstanceID, 0x00700226, UL, 1 */
    extern DICOM_EXPORT const tag CompoundGraphicInstanceID;
    /** CompoundGraphicSequence, 0x00700209, SQ, 1 */
    extern DICOM_EXPORT const tag CompoundGraphicSequence;
    /** CompoundGraphicType, 0x00700294, CS, 1 */
    extern DICOM_EXPORT const tag CompoundGraphicType;
    /** CompoundGraphicUnits, 0x00700282, CS, 1 */
    extern DICOM_EXPORT const tag CompoundGraphicUnits;
    /** CompressionCode, 0x00280060, CS, 1, RET */
    extern DICOM_EXPORT const tag CompressionCode;
    /** CompressionContactArea, 0x001811A5, DS, 1 */
    extern DICOM_EXPORT const tag CompressionContactArea;
    /** CompressionDescription, 0x00280063, SH, 1, RET */
    extern DICOM_EXPORT const tag CompressionDescription;
    /** CompressionForce, 0x001811A2, DS, 1 */
    extern DICOM_EXPORT const tag CompressionForce;
    /** CompressionLabel, 0x00280062, LO, 1, RET */
    extern DICOM_EXPORT const tag CompressionLabel;
    /** CompressionOriginator, 0x00280061, SH, 1, RET */
    extern DICOM_EXPORT const tag CompressionOriginator;
    /** CompressionPressure, 0x001811A3, DS, 1 */
    extern DICOM_EXPORT const tag CompressionPressure;
    /** CompressionRecognitionCode, 0x0028005F, LO, 1, RET */
    extern DICOM_EXPORT const tag CompressionRecognitionCode;
    /** CompressionSequence, 0x00280065, CS, 1, RET */
    extern DICOM_EXPORT const tag CompressionSequence;
    /** CompressionStepPointers, 0x00280066, AT, 1, RET */
    extern DICOM_EXPORT const tag CompressionStepPointers;
    /** ConcatenationFrameOffsetNumber, 0x00209228, UL, 1 */
    extern DICOM_EXPORT const tag ConcatenationFrameOffsetNumber;
    /** ConcatenationUID, 0x00209161, UI, 1 */
    extern DICOM_EXPORT const tag ConcatenationUID;
    /** ConceptCodeSequence, 0x0040A168, SQ, 1 */
    extern DICOM_EXPORT const tag ConceptCodeSequence;
    /** ConceptNameCodeSequence, 0x0040A043, SQ, 1 */
    extern DICOM_EXPORT const tag ConceptNameCodeSequence;
    /** CondenserLensPower, 0x00480111, DS, 1 */
    extern DICOM_EXPORT const tag CondenserLensPower;
    /** ConfidentialityCode, 0x00401008, LO, 1 */
    extern DICOM_EXPORT const tag ConfidentialityCode;
    /** ConfidentialityConstraintOnPatientDataDescription, 0x00403001, LO, 1 */
    extern DICOM_EXPORT const tag ConfidentialityConstraintOnPatientDataDescription;
    /** ConfigurationDescription, 0x0028700D, LO, 1 */
    extern DICOM_EXPORT const tag ConfigurationDescription;
    /** ConfigurationID, 0x0028700B, US, 1 */
    extern DICOM_EXPORT const tag ConfigurationID;
    /** ConfigurationInformation, 0x20100150, ST, 1 */
    extern DICOM_EXPORT const tag ConfigurationInformation;
    /** ConfigurationInformationDescription, 0x20100152, LT, 1 */
    extern DICOM_EXPORT const tag ConfigurationInformationDescription;
    /** ConfigurationName, 0x0028700C, SH, 1 */
    extern DICOM_EXPORT const tag ConfigurationName;
    /** ConfigurationQAResultsSequence, 0x00287011, SQ, 1 */
    extern DICOM_EXPORT const tag ConfigurationQAResultsSequence;
    /** ConnectorType, 0x00145105, CS, 1, RET */
    extern DICOM_EXPORT const tag ConnectorType;
    /** ConsentForClinicalTrialUseSequence, 0x00120083, SQ, 1 */
    extern DICOM_EXPORT const tag ConsentForClinicalTrialUseSequence;
    /** ConsentForDistributionFlag, 0x00120085, CS, 1 */
    extern DICOM_EXPORT const tag ConsentForDistributionFlag;
    /** ConstantVolumeFlag, 0x00189333, CS, 1 */
    extern DICOM_EXPORT const tag ConstantVolumeFlag;
    /** ConstraintType, 0x00820032, CS, 1 */
    extern DICOM_EXPORT const tag ConstraintType;
    /** ConstraintValueSequence, 0x00820034, SQ, 1 */
    extern DICOM_EXPORT const tag ConstraintValueSequence;
    /** ConstraintViolationCondition, 0x00820037, UT, 1 */
    extern DICOM_EXPORT const tag ConstraintViolationCondition;
    /** ConstraintViolationSignificance, 0x00820036, CS, 1 */
    extern DICOM_EXPORT const tag ConstraintViolationSignificance;
    /** ConstraintWeight, 0x300A0021, DS, 1 */
    extern DICOM_EXPORT const tag ConstraintWeight;
    /** ConsultingPhysicianIdentificationSequence, 0x0008009D, SQ, 1 */
    extern DICOM_EXPORT const tag ConsultingPhysicianIdentificationSequence;
    /** ConsultingPhysicianName, 0x0008009C, PN, 1 */
    extern DICOM_EXPORT const tag ConsultingPhysicianName;
    /** ContactDisplayName, 0x0074100C, LO, 1 */
    extern DICOM_EXPORT const tag ContactDisplayName;
    /** ContactURI, 0x0074100A, UR, 1 */
    extern DICOM_EXPORT const tag ContactURI;
    /** ContainerComponentDescription, 0x0050001E, LO, 1 */
    extern DICOM_EXPORT const tag ContainerComponentDescription;
    /** ContainerComponentDiameter, 0x0050001D, FD, 1 */
    extern DICOM_EXPORT const tag ContainerComponentDiameter;
    /** ContainerComponentID, 0x0050001B, LO, 1 */
    extern DICOM_EXPORT const tag ContainerComponentID;
    /** ContainerComponentLength, 0x0050001C, FD, 1 */
    extern DICOM_EXPORT const tag ContainerComponentLength;
    /** ContainerComponentMaterial, 0x0050001A, CS, 1 */
    extern DICOM_EXPORT const tag ContainerComponentMaterial;
    /** ContainerComponentSequence, 0x00400520, SQ, 1 */
    extern DICOM_EXPORT const tag ContainerComponentSequence;
    /** ContainerComponentThickness, 0x00500013, FD, 1 */
    extern DICOM_EXPORT const tag ContainerComponentThickness;
    /** ContainerComponentTypeCodeSequence, 0x00500012, SQ, 1 */
    extern DICOM_EXPORT const tag ContainerComponentTypeCodeSequence;
    /** ContainerComponentWidth, 0x00500015, FD, 1 */
    extern DICOM_EXPORT const tag ContainerComponentWidth;
    /** ContainerDescription, 0x0040051A, LO, 1 */
    extern DICOM_EXPORT const tag ContainerDescription;
    /** ContainerIdentifier, 0x00400512, LO, 1 */
    extern DICOM_EXPORT const tag ContainerIdentifier;
    /** ContainerTypeCodeSequence, 0x00400518, SQ, 1 */
    extern DICOM_EXPORT const tag ContainerTypeCodeSequence;
    /** ContentCreatorIdentificationCodeSequence, 0x00700086, SQ, 1 */
    extern DICOM_EXPORT const tag ContentCreatorIdentificationCodeSequence;
    /** ContentCreatorName, 0x00700084, PN, 1 */
    extern DICOM_EXPORT const tag ContentCreatorName;
    /** ContentDate, 0x00080023, DA, 1 */
    extern DICOM_EXPORT const tag ContentDate;
    /** ContentDescription, 0x00700081, LO, 1 */
    extern DICOM_EXPORT const tag ContentDescription;
    /** ContentItemModifierSequence, 0x00400441, SQ, 1 */
    extern DICOM_EXPORT const tag ContentItemModifierSequence;
    /** ContentLabel, 0x00700080, CS, 1 */
    extern DICOM_EXPORT const tag ContentLabel;
    /** ContentQualification, 0x00189004, CS, 1 */
    extern DICOM_EXPORT const tag ContentQualification;
    /** ContentSequence, 0x0040A730, SQ, 1 */
    extern DICOM_EXPORT const tag ContentSequence;
    /** ContentTemplateSequence, 0x0040A504, SQ, 1 */
    extern DICOM_EXPORT const tag ContentTemplateSequence;
    /** ContentTime, 0x00080033, TM, 1 */
    extern DICOM_EXPORT const tag ContentTime;
    /** ContextGroupExtensionCreatorUID, 0x0008010D, UI, 1 */
    extern DICOM_EXPORT const tag ContextGroupExtensionCreatorUID;
    /** ContextGroupExtensionFlag, 0x0008010B, CS, 1 */
    extern DICOM_EXPORT const tag ContextGroupExtensionFlag;
    /** ContextGroupIdentificationSequence, 0x00080123, SQ, 1 */
    extern DICOM_EXPORT const tag ContextGroupIdentificationSequence;
    /** ContextGroupLocalVersion, 0x00080107, DT, 1 */
    extern DICOM_EXPORT const tag ContextGroupLocalVersion;
    /** ContextGroupVersion, 0x00080106, DT, 1 */
    extern DICOM_EXPORT const tag ContextGroupVersion;
    /** ContextIdentifier, 0x0008010F, CS, 1 */
    extern DICOM_EXPORT const tag ContextIdentifier;
    /** ContextUID, 0x00080117, UI, 1 */
    extern DICOM_EXPORT const tag ContextUID;
    /** ContinuationEndMeterset, 0x00740121, FD, 1 */
    extern DICOM_EXPORT const tag ContinuationEndMeterset;
    /** ContinuationEndTotalReferenceAirKerma, 0x00741403, DS, 1 */
    extern DICOM_EXPORT const tag ContinuationEndTotalReferenceAirKerma;
    /** ContinuationPulseNumber, 0x00741404, IS, 1 */
    extern DICOM_EXPORT const tag ContinuationPulseNumber;
    /** ContinuationStartMeterset, 0x00740120, FD, 1 */
    extern DICOM_EXPORT const tag ContinuationStartMeterset;
    /** ContinuationStartTotalReferenceAirKerma, 0x00741402, DS, 1 */
    extern DICOM_EXPORT const tag ContinuationStartTotalReferenceAirKerma;
    /** ContinuityOfContent, 0x0040A050, CS, 1 */
    extern DICOM_EXPORT const tag ContinuityOfContent;
    /** ContourData, 0x30060050, DS, 3 */
    extern DICOM_EXPORT const tag ContourData;
    /** ContourGeometricType, 0x30060042, CS, 1 */
    extern DICOM_EXPORT const tag ContourGeometricType;
    /** ContourImageSequence, 0x30060016, SQ, 1 */
    extern DICOM_EXPORT const tag ContourImageSequence;
    /** ContourNumber, 0x30060048, IS, 1 */
    extern DICOM_EXPORT const tag ContourNumber;
    /** ContourOffsetVector, 0x30060045, DS, 3 */
    extern DICOM_EXPORT const tag ContourOffsetVector;
    /** ContourSequence, 0x30060040, SQ, 1 */
    extern DICOM_EXPORT const tag ContourSequence;
    /** ContourSlabThickness, 0x30060044, DS, 1 */
    extern DICOM_EXPORT const tag ContourSlabThickness;
    /** ContourUncertaintyRadius, 0x00700312, FD, 1 */
    extern DICOM_EXPORT const tag ContourUncertaintyRadius;
    /** ContraindicationsCodeSequence, 0x0018990B, SQ, 1 */
    extern DICOM_EXPORT const tag ContraindicationsCodeSequence;
    /** ContrastAdministrationProfileSequence, 0x00189340, SQ, 1 */
    extern DICOM_EXPORT const tag ContrastAdministrationProfileSequence;
    /** ContrastBolusAdministrationRouteSequence, 0x00180014, SQ, 1 */
    extern DICOM_EXPORT const tag ContrastBolusAdministrationRouteSequence;
    /** ContrastBolusAgent, 0x00180010, LO, 1 */
    extern DICOM_EXPORT const tag ContrastBolusAgent;
    /** ContrastBolusAgentAdministered, 0x00189342, CS, 1 */
    extern DICOM_EXPORT const tag ContrastBolusAgentAdministered;
    /** ContrastBolusAgentDetected, 0x00189343, CS, 1 */
    extern DICOM_EXPORT const tag ContrastBolusAgentDetected;
    /** ContrastBolusAgentNumber, 0x00189337, US, 1 */
    extern DICOM_EXPORT const tag ContrastBolusAgentNumber;
    /** ContrastBolusAgentPhase, 0x00189344, CS, 1 */
    extern DICOM_EXPORT const tag ContrastBolusAgentPhase;
    /** ContrastBolusAgentSequence, 0x00180012, SQ, 1 */
    extern DICOM_EXPORT const tag ContrastBolusAgentSequence;
    /** ContrastBolusIngredient, 0x00181048, CS, 1 */
    extern DICOM_EXPORT const tag ContrastBolusIngredient;
    /** ContrastBolusIngredientCodeSequence, 0x00189338, SQ, 1 */
    extern DICOM_EXPORT const tag ContrastBolusIngredientCodeSequence;
    /** ContrastBolusIngredientConcentration, 0x00181049, DS, 1 */
    extern DICOM_EXPORT const tag ContrastBolusIngredientConcentration;
    /** ContrastBolusIngredientOpaque, 0x00189425, CS, 1 */
    extern DICOM_EXPORT const tag ContrastBolusIngredientOpaque;
    /** ContrastBolusIngredientPercentByVolume, 0x00520001, FL, 1 */
    extern DICOM_EXPORT const tag ContrastBolusIngredientPercentByVolume;
    /** ContrastBolusRoute, 0x00181040, LO, 1 */
    extern DICOM_EXPORT const tag ContrastBolusRoute;
    /** ContrastBolusStartTime, 0x00181042, TM, 1 */
    extern DICOM_EXPORT const tag ContrastBolusStartTime;
    /** ContrastBolusStopTime, 0x00181043, TM, 1 */
    extern DICOM_EXPORT const tag ContrastBolusStopTime;
    /** ContrastBolusT1Relaxivity, 0x00180013, FL, 1 */
    extern DICOM_EXPORT const tag ContrastBolusT1Relaxivity;
    /** ContrastBolusTotalDose, 0x00181044, DS, 1 */
    extern DICOM_EXPORT const tag ContrastBolusTotalDose;
    /** ContrastBolusUsageSequence, 0x00189341, SQ, 1 */
    extern DICOM_EXPORT const tag ContrastBolusUsageSequence;
    /** ContrastBolusVolume, 0x00181041, DS, 1 */
    extern DICOM_EXPORT const tag ContrastBolusVolume;
    /** ContrastFlowDuration, 0x00181047, DS, 1 */
    extern DICOM_EXPORT const tag ContrastFlowDuration;
    /** ContrastFlowRate, 0x00181046, DS, 1 */
    extern DICOM_EXPORT const tag ContrastFlowRate;
    /** ContrastFrameAveraging, 0x00286112, US, 1 */
    extern DICOM_EXPORT const tag ContrastFrameAveraging;
    /** ContributingEquipmentSequence, 0x0018A001, SQ, 1 */
    extern DICOM_EXPORT const tag ContributingEquipmentSequence;
    /** ContributingSOPInstancesReferenceSequence, 0x00209529, SQ, 1 */
    extern DICOM_EXPORT const tag ContributingSOPInstancesReferenceSequence;
    /** ContributingSourcesSequence, 0x00189506, SQ, 1 */
    extern DICOM_EXPORT const tag ContributingSourcesSequence;
    /** ContributionDateTime, 0x0018A002, DT, 1 */
    extern DICOM_EXPORT const tag ContributionDateTime;
    /** ContributionDescription, 0x0018A003, ST, 1 */
    extern DICOM_EXPORT const tag ContributionDescription;
    /** ControlPoint3DPosition, 0x300A02D4, DS, 3 */
    extern DICOM_EXPORT const tag ControlPoint3DPosition;
    /** ControlPointDeliverySequence, 0x30080040, SQ, 1 */
    extern DICOM_EXPORT const tag ControlPointDeliverySequence;
    /** ControlPointIndex, 0x300A0112, IS, 1 */
    extern DICOM_EXPORT const tag ControlPointIndex;
    /** ControlPointOrientation, 0x300A0412, FL, 3 */
    extern DICOM_EXPORT const tag ControlPointOrientation;
    /** ControlPointRelativePosition, 0x300A02D2, DS, 1 */
    extern DICOM_EXPORT const tag ControlPointRelativePosition;
    /** ControlPointSequence, 0x300A0111, SQ, 1 */
    extern DICOM_EXPORT const tag ControlPointSequence;
    /** ConventionalControlPointVerificationSequence, 0x0074104C, SQ, 1 */
    extern DICOM_EXPORT const tag ConventionalControlPointVerificationSequence;
    /** ConventionalMachineVerificationSequence, 0x00741044, SQ, 1 */
    extern DICOM_EXPORT const tag ConventionalMachineVerificationSequence;
    /** ConversionSourceAttributesSequence, 0x00209172, SQ, 1 */
    extern DICOM_EXPORT const tag ConversionSourceAttributesSequence;
    /** ConversionType, 0x00080064, CS, 1 */
    extern DICOM_EXPORT const tag ConversionType;
    /** ConvolutionKernel, 0x00181210, SH, 1 */
    extern DICOM_EXPORT const tag ConvolutionKernel;
    /** ConvolutionKernelGroup, 0x00189316, CS, 1 */
    extern DICOM_EXPORT const tag ConvolutionKernelGroup;
    /** CoordinatesSetGeometricTypeTrial, 0x0040A290, CS, 1, RET */
    extern DICOM_EXPORT const tag CoordinatesSetGeometricTypeTrial;
    /** CoordinateStartValue, 0x50000112, US, 1, RET */
    extern DICOM_EXPORT const range_tag CoordinateStartValue;
    /** CoordinateStepValue, 0x50000114, US, 1, RET */
    extern DICOM_EXPORT const range_tag CoordinateStepValue;
    /** CoordinateSystemAxesSequence, 0x00142204, SQ, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemAxesSequence;
    /** CoordinateSystemAxisCodeSequence, 0x004008DA, SQ, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemAxisCodeSequence;
    /** CoordinateSystemAxisDescription, 0x00142206, ST, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemAxisDescription;
    /** CoordinateSystemAxisNumber, 0x0014220A, IS, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemAxisNumber;
    /** CoordinateSystemAxisType, 0x0014220C, CS, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemAxisType;
    /** CoordinateSystemAxisUnits, 0x0014220E, CS, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemAxisUnits;
    /** CoordinateSystemAxisValues, 0x00142210, OB, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemAxisValues;
    /** CoordinateSystemDataSetMapping, 0x00142208, CS, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemDataSetMapping;
    /** CoordinateSystemNumberOfAxes, 0x00142202, IS, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemNumberOfAxes;
    /** CoordinateSystemTransformRotationAndScaleMatrix, 0x0014222A, DS, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemTransformRotationAndScaleMatrix;
    /** CoordinateSystemTransformSequence, 0x00142220, SQ, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemTransformSequence;
    /** CoordinateSystemTransformTranslationMatrix, 0x0014222C, DS, 1, RET */
    extern DICOM_EXPORT const tag CoordinateSystemTransformTranslationMatrix;
    /** CornealEccentricityIndex, 0x00460234, FL, 1 */
    extern DICOM_EXPORT const tag CornealEccentricityIndex;
    /** CornealISValue, 0x00460224, FL, 1 */
    extern DICOM_EXPORT const tag CornealISValue;
    /** CornealPointEstimated, 0x00460248, CS, 1 */
    extern DICOM_EXPORT const tag CornealPointEstimated;
    /** CornealPointLocation, 0x00460247, FL, 3 */
    extern DICOM_EXPORT const tag CornealPointLocation;
    /** CornealSize, 0x00460046, FD, 1 */
    extern DICOM_EXPORT const tag CornealSize;
    /** CornealTopographyMappingNormalsSequence, 0x00460210, SQ, 1 */
    extern DICOM_EXPORT const tag CornealTopographyMappingNormalsSequence;
    /** CornealTopographyMapQualityEvaluation, 0x00460242, CS, 1 */
    extern DICOM_EXPORT const tag CornealTopographyMapQualityEvaluation;
    /** CornealTopographyMapTypeCodeSequence, 0x00460207, SQ, 1 */
    extern DICOM_EXPORT const tag CornealTopographyMapTypeCodeSequence;
    /** CornealTopographySurface, 0x00460201, CS, 1 */
    extern DICOM_EXPORT const tag CornealTopographySurface;
    /** CornealVertexLocation, 0x00460202, FL, 2 */
    extern DICOM_EXPORT const tag CornealVertexLocation;
    /** CornealWavefront, 0x00460253, FL, 1 */
    extern DICOM_EXPORT const tag CornealWavefront;
    /** CorrectedImage, 0x00280051, CS, 1 */
    extern DICOM_EXPORT const tag CorrectedImage;
    /** CorrectedLocalizedDeviationFromNormal, 0x00240079, FL, 1 */
    extern DICOM_EXPORT const tag CorrectedLocalizedDeviationFromNormal;
    /** CorrectedLocalizedDeviationFromNormalCalculated, 0x00240078, CS, 1 */
    extern DICOM_EXPORT const tag CorrectedLocalizedDeviationFromNormalCalculated;
    /** CorrectedLocalizedDeviationFromNormalProbability, 0x00240081, FL, 1 */
    extern DICOM_EXPORT const tag CorrectedLocalizedDeviationFromNormalProbability;
    /** CorrectedLocalizedDeviationFromNormalProbabilityCalculated, 0x00240080, CS, 1 */
    extern DICOM_EXPORT const tag CorrectedLocalizedDeviationFromNormalProbabilityCalculated;
    /** CorrectedParameterSequence, 0x30080068, SQ, 1 */
    extern DICOM_EXPORT const tag CorrectedParameterSequence;
    /** CorrectionValue, 0x3008006A, FL, 1 */
    extern DICOM_EXPORT const tag CorrectionValue;
    /** CountLossNormalizationCorrected, 0x00189764, CS, 1 */
    extern DICOM_EXPORT const tag CountLossNormalizationCorrected;
    /** CountRate, 0x00181243, IS, 1 */
    extern DICOM_EXPORT const tag CountRate;
    /** CountryOfResidence, 0x00102150, LO, 1 */
    extern DICOM_EXPORT const tag CountryOfResidence;
    /** CountsAccumulated, 0x00180070, IS, 1 */
    extern DICOM_EXPORT const tag CountsAccumulated;
    /** CountsIncluded, 0x00541400, CS, 1, RET */
    extern DICOM_EXPORT const tag CountsIncluded;
    /** CountsSource, 0x00541002, CS, 1 */
    extern DICOM_EXPORT const tag CountsSource;
    /** CouplingMedium, 0x00144056, ST, 1, RET */
    extern DICOM_EXPORT const tag CouplingMedium;
    /** CouplingTechnique, 0x00144054, ST, 1, RET */
    extern DICOM_EXPORT const tag CouplingTechnique;
    /** CouplingVelocity, 0x00144057, DS, 1, RET */
    extern DICOM_EXPORT const tag CouplingVelocity;
    /** CoverageOfKSpace, 0x00189094, CS, 1 */
    extern DICOM_EXPORT const tag CoverageOfKSpace;
    /** CranialThermalIndex, 0x00185026, DS, 1 */
    extern DICOM_EXPORT const tag CranialThermalIndex;
    /** CreationDate, 0x21000040, DA, 1 */
    extern DICOM_EXPORT const tag CreationDate;
    /** CreationTime, 0x21000050, TM, 1 */
    extern DICOM_EXPORT const tag CreationTime;
    /** CreatorVersionUID, 0x00089123, UI, 1 */
    extern DICOM_EXPORT const tag CreatorVersionUID;
    /** Crop, 0x00701204, CS, 1 */
    extern DICOM_EXPORT const tag Crop;
    /** CroppingSpecificationIndex, 0x00701205, US, 1 */
    extern DICOM_EXPORT const tag CroppingSpecificationIndex;
    /** CroppingSpecificationNumber, 0x00701309, US, 1 */
    extern DICOM_EXPORT const tag CroppingSpecificationNumber;
    /** CSSFontName, 0x00700229, LO, 1 */
    extern DICOM_EXPORT const tag CSSFontName;
    /** CTAcquisitionDetailsSequence, 0x00189304, SQ, 1 */
    extern DICOM_EXPORT const tag CTAcquisitionDetailsSequence;
    /** CTAcquisitionTypeSequence, 0x00189301, SQ, 1 */
    extern DICOM_EXPORT const tag CTAcquisitionTypeSequence;
    /** CTAdditionalXRaySourceSequence, 0x00189360, SQ, 1 */
    extern DICOM_EXPORT const tag CTAdditionalXRaySourceSequence;
    /** CTDIPhantomTypeCodeSequence, 0x00189346, SQ, 1 */
    extern DICOM_EXPORT const tag CTDIPhantomTypeCodeSequence;
    /** CTDIvol, 0x00189345, FD, 1 */
    extern DICOM_EXPORT const tag CTDIvol;
    /** CTDIvolNotificationTrigger, 0x00189942, FD, 1 */
    extern DICOM_EXPORT const tag CTDIvolNotificationTrigger;
    /** CTExposureSequence, 0x00189321, SQ, 1 */
    extern DICOM_EXPORT const tag CTExposureSequence;
    /** CTGeometrySequence, 0x00189312, SQ, 1 */
    extern DICOM_EXPORT const tag CTGeometrySequence;
    /** CTImageFrameTypeSequence, 0x00189329, SQ, 1 */
    extern DICOM_EXPORT const tag CTImageFrameTypeSequence;
    /** CTPositionSequence, 0x00189326, SQ, 1 */
    extern DICOM_EXPORT const tag CTPositionSequence;
    /** CTReconstructionSequence, 0x00189314, SQ, 1 */
    extern DICOM_EXPORT const tag CTReconstructionSequence;
    /** CTTableDynamicsSequence, 0x00189308, SQ, 1 */
    extern DICOM_EXPORT const tag CTTableDynamicsSequence;
    /** CTXRayDetailsSequence, 0x00189325, SQ, 1 */
    extern DICOM_EXPORT const tag CTXRayDetailsSequence;
    /** CumulativeDoseReferenceCoefficient, 0x300A010C, DS, 1 */
    extern DICOM_EXPORT const tag CumulativeDoseReferenceCoefficient;
    /** CumulativeDoseToDoseReference, 0x30080052, DS, 1 */
    extern DICOM_EXPORT const tag CumulativeDoseToDoseReference;
    /** CumulativeMetersetWeight, 0x300A0134, DS, 1 */
    extern DICOM_EXPORT const tag CumulativeMetersetWeight;
    /** CumulativeTimeWeight, 0x300A02D6, DS, 1 */
    extern DICOM_EXPORT const tag CumulativeTimeWeight;
    /** CurrentConfigurationID, 0x00287002, US, 1 */
    extern DICOM_EXPORT const tag CurrentConfigurationID;
    /** CurrentFractionNumber, 0x30080022, IS, 1 */
    extern DICOM_EXPORT const tag CurrentFractionNumber;
    /** CurrentObserverTrial, 0x0040A307, PN, 1, RET */
    extern DICOM_EXPORT const tag CurrentObserverTrial;
    /** CurrentPatientLocation, 0x00380300, LO, 1 */
    extern DICOM_EXPORT const tag CurrentPatientLocation;
    /** CurrentRequestedProcedureEvidenceSequence, 0x0040A375, SQ, 1 */
    extern DICOM_EXPORT const tag CurrentRequestedProcedureEvidenceSequence;
    /** CurrentTreatmentStatus, 0x30080200, CS, 1 */
    extern DICOM_EXPORT const tag CurrentTreatmentStatus;
    /** CurvatureType, 0x00140052, CS, 1, RET */
    extern DICOM_EXPORT const tag CurvatureType;
    /** CurveActivationLayer, 0x50001001, CS, 1, RET */
    extern DICOM_EXPORT const range_tag CurveActivationLayer;
    /** CurveData, 0x50003000, OB or OW, 1, RET */
    extern DICOM_EXPORT const range_tag CurveData;
    /** CurveDataDescriptor, 0x50000110, US, 1, RET */
    extern DICOM_EXPORT const range_tag CurveDataDescriptor;
    /** CurveDate, 0x00080025, DA, 1, RET */
    extern DICOM_EXPORT const tag CurveDate;
    /** CurveDescription, 0x50000022, LO, 1, RET */
    extern DICOM_EXPORT const range_tag CurveDescription;
    /** CurveDimensions, 0x50000005, US, 1, RET */
    extern DICOM_EXPORT const range_tag CurveDimensions;
    /** CurveLabel, 0x50002500, LO, 1, RET */
    extern DICOM_EXPORT const range_tag CurveLabel;
    /** CurveNumber, 0x00200024, IS, 1, RET */
    extern DICOM_EXPORT const tag CurveNumber;
    /** CurveRange, 0x50000106, SH, 1, RET */
    extern DICOM_EXPORT const range_tag CurveRange;
    /** CurveReferencedOverlayGroup, 0x50002610, US, 1, RET */
    extern DICOM_EXPORT const range_tag CurveReferencedOverlayGroup;
    /** CurveReferencedOverlaySequence, 0x50002600, SQ, 1, RET */
    extern DICOM_EXPORT const range_tag CurveReferencedOverlaySequence;
    /** CurveTime, 0x00080035, TM, 1, RET */
    extern DICOM_EXPORT const tag CurveTime;
    /** CustodialOrganizationSequence, 0x0040A07C, SQ, 1 */
    extern DICOM_EXPORT const tag CustodialOrganizationSequence;
    /** CylinderAxis, 0x00220009, FL, 1 */
    extern DICOM_EXPORT const tag CylinderAxis;
    /** CylinderLensPower, 0x00220008, FL, 1 */
    extern DICOM_EXPORT const tag CylinderLensPower;
    /** CylinderPower, 0x00460147, FD, 1 */
    extern DICOM_EXPORT const tag CylinderPower;
    /** CylinderSequence, 0x00460018, SQ, 1 */
    extern DICOM_EXPORT const tag CylinderSequence;
    /** DACAmplitude, 0x0014403C, DS, 1, RET */
    extern DICOM_EXPORT const tag DACAmplitude;
    /** DACGainPoints, 0x00144038, DS, 1, RET */
    extern DICOM_EXPORT const tag DACGainPoints;
    /** DACSequence, 0x00144035, SQ, 1, RET */
    extern DICOM_EXPORT const tag DACSequence;
    /** DACTimePoints, 0x0014403A, DS, 1, RET */
    extern DICOM_EXPORT const tag DACTimePoints;
    /** DACType, 0x00144036, CS, 1, RET */
    extern DICOM_EXPORT const tag DACType;
    /** Damping, 0x00144028, DS, 1, RET */
    extern DICOM_EXPORT const tag Damping;
    /** DarkCurrentCounts, 0x00143050, OB or OW, 1, RET */
    extern DICOM_EXPORT const tag DarkCurrentCounts;
    /** DarkCurrentSequence, 0x00143040, SQ, 1, RET */
    extern DICOM_EXPORT const tag DarkCurrentSequence;
    /** DataBlock, 0x00280702, AT, 1, RET */
    extern DICOM_EXPORT const tag DataBlock;
    /** DataBlockDescription, 0x00280701, CS, 1, RET */
    extern DICOM_EXPORT const tag DataBlockDescription;
    /** DataCollectionCenterPatient, 0x00189313, FD, 3 */
    extern DICOM_EXPORT const tag DataCollectionCenterPatient;
    /** DataCollectionDiameter, 0x00180090, DS, 1 */
    extern DICOM_EXPORT const tag DataCollectionDiameter;
    /** DataElementsSigned, 0x04000020, AT, 1 */
    extern DICOM_EXPORT const tag DataElementsSigned;
    /** DataFrameAssignmentSequence, 0x00281401, SQ, 1 */
    extern DICOM_EXPORT const tag DataFrameAssignmentSequence;
    /** DataInformationSequence, 0x00540063, SQ, 1 */
    extern DICOM_EXPORT const tag DataInformationSequence;
    /** DataObservationSequence, 0x00240325, SQ, 1 */
    extern DICOM_EXPORT const tag DataObservationSequence;
    /** DataPathAssignment, 0x00281402, CS, 1 */
    extern DICOM_EXPORT const tag DataPathAssignment;
    /** DataPathID, 0x0028140E, CS, 1 */
    extern DICOM_EXPORT const tag DataPathID;
    /** DataPointColumns, 0x00289002, UL, 1 */
    extern DICOM_EXPORT const tag DataPointColumns;
    /** DataPointRows, 0x00289001, UL, 1 */
    extern DICOM_EXPORT const tag DataPointRows;
    /** DataRepresentation, 0x00289108, CS, 1 */
    extern DICOM_EXPORT const tag DataRepresentation;
    /** DataSetDescription, 0x00240309, LO, 1 */
    extern DICOM_EXPORT const tag DataSetDescription;
    /** DataSetName, 0x00240306, LO, 1 */
    extern DICOM_EXPORT const tag DataSetName;
    /** DataSetSource, 0x00240308, LO, 1 */
    extern DICOM_EXPORT const tag DataSetSource;
    /** DataSetSubtype, 0x00080041, LO, 1, RET */
    extern DICOM_EXPORT const tag DataSetSubtype;
    /** DataSetTrailingPadding, 0xFFFCFFFC, OB, 1 */
    extern DICOM_EXPORT const tag DataSetTrailingPadding;
    /** DataSetType, 0x00080040, US, 1, RET */
    extern DICOM_EXPORT const tag DataSetType;
    /** DataSetVersion, 0x00240307, LO, 1 */
    extern DICOM_EXPORT const tag DataSetVersion;
    /** DataType, 0x00189808, CS, 1 */
    extern DICOM_EXPORT const tag DataType;
    /** DataValueRepresentation, 0x50000103, US, 1, RET */
    extern DICOM_EXPORT const range_tag DataValueRepresentation;
    /** Date, 0x0040A121, DA, 1 */
    extern DICOM_EXPORT const tag Date;
    /** DateOfDocumentOrVerbalTransactionTrial, 0x0040A110, DA, 1, RET */
    extern DICOM_EXPORT const tag DateOfDocumentOrVerbalTransactionTrial;
    /** DateOfGainCalibration, 0x00143076, DA, 1, RET */
    extern DICOM_EXPORT const tag DateOfGainCalibration;
    /** DateOfLastCalibration, 0x00181200, DA, 1 */
    extern DICOM_EXPORT const tag DateOfLastCalibration;
    /** DateOfLastDetectorCalibration, 0x0018700C, DA, 1 */
    extern DICOM_EXPORT const tag DateOfLastDetectorCalibration;
    /** DateOfSecondaryCapture, 0x00181012, DA, 1 */
    extern DICOM_EXPORT const tag DateOfSecondaryCapture;
    /** DateTime, 0x0040A120, DT, 1 */
    extern DICOM_EXPORT const tag DateTime;
    /** DateTimeOfLastCalibration, 0x00181202, DT, 1 */
    extern DICOM_EXPORT const tag DateTimeOfLastCalibration;
    /** dBdt, 0x00181318, DS, 1 */
    extern DICOM_EXPORT const tag dBdt;
    /** DCTLabel, 0x00280700, LO, 1, RET */
    extern DICOM_EXPORT const tag DCTLabel;
    /** DDLValue, 0x00287017, US, 1 */
    extern DICOM_EXPORT const tag DDLValue;
    /** DeadTimeCorrected, 0x00189761, CS, 1 */
    extern DICOM_EXPORT const tag DeadTimeCorrected;
    /** DeadTimeCorrectionFlag, 0x00541401, CS, 1, RET */
    extern DICOM_EXPORT const tag DeadTimeCorrectionFlag;
    /** DeadTimeFactor, 0x00541324, DS, 1 */
    extern DICOM_EXPORT const tag DeadTimeFactor;
    /** DecayCorrected, 0x00189758, CS, 1 */
    extern DICOM_EXPORT const tag DecayCorrected;
    /** DecayCorrection, 0x00541102, CS, 1 */
    extern DICOM_EXPORT const tag DecayCorrection;
    /** DecayCorrectionDateTime, 0x00189701, DT, 1 */
    extern DICOM_EXPORT const tag DecayCorrectionDateTime;
    /** DecayFactor, 0x00541321, DS, 1 */
    extern DICOM_EXPORT const tag DecayFactor;
    /** DecimalPotentialVisualAcuity, 0x00460238, FL, 1 */
    extern DICOM_EXPORT const tag DecimalPotentialVisualAcuity;
    /** DecimalVisualAcuity, 0x00460137, FD, 1 */
    extern DICOM_EXPORT const tag DecimalVisualAcuity;
    /** DecimateCropResult, 0x202000A2, CS, 1 */
    extern DICOM_EXPORT const tag DecimateCropResult;
    /** DecoupledNucleus, 0x00189060, CS, 1 */
    extern DICOM_EXPORT const tag DecoupledNucleus;
    /** Decoupling, 0x00189059, CS, 1 */
    extern DICOM_EXPORT const tag Decoupling;
    /** DecouplingChemicalShiftReference, 0x00189063, FD, 1 */
    extern DICOM_EXPORT const tag DecouplingChemicalShiftReference;
    /** DecouplingFrequency, 0x00189061, FD, 1 */
    extern DICOM_EXPORT const tag DecouplingFrequency;
    /** DecouplingMethod, 0x00189062, CS, 1 */
    extern DICOM_EXPORT const tag DecouplingMethod;
    /** DefaultMagnificationType, 0x201000A6, CS, 1 */
    extern DICOM_EXPORT const tag DefaultMagnificationType;
    /** DefaultPrinterResolutionID, 0x20100054, CS, 1 */
    extern DICOM_EXPORT const tag DefaultPrinterResolutionID;
    /** DefaultSmoothingType, 0x201000A8, CS, 1 */
    extern DICOM_EXPORT const tag DefaultSmoothingType;
    /** DefinitionSourceSequence, 0x00081156, SQ, 1 */
    extern DICOM_EXPORT const tag DefinitionSourceSequence;
    /** DeformableRegistrationGridSequence, 0x00640005, SQ, 1 */
    extern DICOM_EXPORT const tag DeformableRegistrationGridSequence;
    /** DeformableRegistrationSequence, 0x00640002, SQ, 1 */
    extern DICOM_EXPORT const tag DeformableRegistrationSequence;
    /** DegreeOfDilation, 0x0022000E, FL, 1 */
    extern DICOM_EXPORT const tag DegreeOfDilation;
    /** DegreeOfFreedomID, 0x00686410, US, 1 */
    extern DICOM_EXPORT const tag DegreeOfFreedomID;
    /** DegreeOfFreedomType, 0x00686420, CS, 1 */
    extern DICOM_EXPORT const tag DegreeOfFreedomType;
    /** DeidentificationAction, 0x00080307, CS, 1 */
    extern DICOM_EXPORT const tag DeidentificationAction;
    /** DeidentificationActionSequence, 0x00080305, SQ, 1 */
    extern DICOM_EXPORT const tag DeidentificationActionSequence;
    /** DeidentificationMethod, 0x00120063, LO, 1 */
    extern DICOM_EXPORT const tag DeidentificationMethod;
    /** DeidentificationMethodCodeSequence, 0x00120064, SQ, 1 */
    extern DICOM_EXPORT const tag DeidentificationMethodCodeSequence;
    /** DelayLawIdentifier, 0x0014405C, ST, 1, RET */
    extern DICOM_EXPORT const tag DelayLawIdentifier;
    /** DeletionLock, 0x00741230, LO, 1 */
    extern DICOM_EXPORT const tag DeletionLock;
    /** DeliveredChannelTotalTime, 0x30080134, DS, 1 */
    extern DICOM_EXPORT const tag DeliveredChannelTotalTime;
    /** DeliveredDepthDoseParametersSequence, 0x300A0506, SQ, 1 */
    extern DICOM_EXPORT const tag DeliveredDepthDoseParametersSequence;
    /** DeliveredDistalDepth, 0x300A0508, FL, 1 */
    extern DICOM_EXPORT const tag DeliveredDistalDepth;
    /** DeliveredDistalDepthFraction, 0x300A0507, FL, 1 */
    extern DICOM_EXPORT const tag DeliveredDistalDepthFraction;
    /** DeliveredMeterset, 0x30080044, DS, 1 */
    extern DICOM_EXPORT const tag DeliveredMeterset;
    /** DeliveredNominalRangeModulatedRegionDepths, 0x300A0510, FL, 2 */
    extern DICOM_EXPORT const tag DeliveredNominalRangeModulatedRegionDepths;
    /** DeliveredNominalRangeModulationFractions, 0x300A0509, FL, 2 */
    extern DICOM_EXPORT const tag DeliveredNominalRangeModulationFractions;
    /** DeliveredNumberOfPulses, 0x30080138, IS, 1 */
    extern DICOM_EXPORT const tag DeliveredNumberOfPulses;
    /** DeliveredPrimaryMeterset, 0x30080036, DS, 1 */
    extern DICOM_EXPORT const tag DeliveredPrimaryMeterset;
    /** DeliveredPulseRepetitionInterval, 0x3008013C, DS, 1 */
    extern DICOM_EXPORT const tag DeliveredPulseRepetitionInterval;
    /** DeliveredReferenceDoseDefinition, 0x300A0511, CS, 1 */
    extern DICOM_EXPORT const tag DeliveredReferenceDoseDefinition;
    /** DeliveredSecondaryMeterset, 0x30080037, DS, 1 */
    extern DICOM_EXPORT const tag DeliveredSecondaryMeterset;
    /** DeliveredTreatmentTime, 0x3008003B, DS, 1 */
    extern DICOM_EXPORT const tag DeliveredTreatmentTime;
    /** DeliveryMaximumDose, 0x300A0023, DS, 1 */
    extern DICOM_EXPORT const tag DeliveryMaximumDose;
    /** DeliveryVerificationImageSequence, 0x00741030, SQ, 1 */
    extern DICOM_EXPORT const tag DeliveryVerificationImageSequence;
    /** DeliveryWarningDose, 0x300A0022, DS, 1 */
    extern DICOM_EXPORT const tag DeliveryWarningDose;
    /** Density, 0x40101018, FL, 1, RET */
    extern DICOM_EXPORT const tag Density;
    /** DepthDoseParametersSequence, 0x300A0505, SQ, 1 */
    extern DICOM_EXPORT const tag DepthDoseParametersSequence;
    /** DepthOfScanField, 0x00185050, IS, 1 */
    extern DICOM_EXPORT const tag DepthOfScanField;
    /** DepthOfTransverseImage, 0x00220041, FL, 1 */
    extern DICOM_EXPORT const tag DepthOfTransverseImage;
    /** DepthsOfFocus, 0x00189801, FD, 1 */
    extern DICOM_EXPORT const tag DepthsOfFocus;
    /** DepthSpatialResolution, 0x00220035, FL, 1 */
    extern DICOM_EXPORT const tag DepthSpatialResolution;
    /** DepthValueAveragingFlag, 0x300A0093, CS, 1 */
    extern DICOM_EXPORT const tag DepthValueAveragingFlag;
    /** DerivationAlgorithmSequence, 0x00221612, SQ, 1 */
    extern DICOM_EXPORT const tag DerivationAlgorithmSequence;
    /** DerivationCodeSequence, 0x00089215, SQ, 1 */
    extern DICOM_EXPORT const tag DerivationCodeSequence;
    /** DerivationDescription, 0x00082111, ST, 1 */
    extern DICOM_EXPORT const tag DerivationDescription;
    /** DerivationImageSequence, 0x00089124, SQ, 1 */
    extern DICOM_EXPORT const tag DerivationImageSequence;
    /** DerivationImplantAssemblyTemplateSequence, 0x0076000E, SQ, 1 */
    extern DICOM_EXPORT const tag DerivationImplantAssemblyTemplateSequence;
    /** DerivationImplantTemplateSequence, 0x00686224, SQ, 1 */
    extern DICOM_EXPORT const tag DerivationImplantTemplateSequence;
    /** DestinationAE, 0x21000140, AE, 1 */
    extern DICOM_EXPORT const tag DestinationAE;
    /** DetailsOfCoefficients, 0x00280404, AT, 1, RET */
    extern DICOM_EXPORT const tag DetailsOfCoefficients;
    /** DetectorActivationOffsetFromExposure, 0x00187016, DS, 1 */
    extern DICOM_EXPORT const tag DetectorActivationOffsetFromExposure;
    /** DetectorActiveAreaOrientation, 0x00189558, FD, 6 */
    extern DICOM_EXPORT const tag DetectorActiveAreaOrientation;
    /** DetectorActiveAreaTLHCPosition, 0x00189557, FD, 3 */
    extern DICOM_EXPORT const tag DetectorActiveAreaTLHCPosition;
    /** DetectorActiveDimensions, 0x00187026, DS, 1 */
    extern DICOM_EXPORT const tag DetectorActiveDimensions;
    /** DetectorActiveOrigin, 0x00187028, DS, 2 */
    extern DICOM_EXPORT const tag DetectorActiveOrigin;
    /** DetectorActiveShape, 0x00187024, CS, 1 */
    extern DICOM_EXPORT const tag DetectorActiveShape;
    /** DetectorActiveTime, 0x00187014, DS, 1 */
    extern DICOM_EXPORT const tag DetectorActiveTime;
    /** DetectorBinning, 0x0018701A, DS, 2 */
    extern DICOM_EXPORT const tag DetectorBinning;
    /** DetectorCalibrationData, 0x4010106C, OB, 1, RET */
    extern DICOM_EXPORT const tag DetectorCalibrationData;
    /** DetectorConditionsNominalFlag, 0x00187000, CS, 1 */
    extern DICOM_EXPORT const tag DetectorConditionsNominalFlag;
    /** DetectorConfiguration, 0x00187005, CS, 1 */
    extern DICOM_EXPORT const tag DetectorConfiguration;
    /** DetectorDescription, 0x00187006, LT, 1 */
    extern DICOM_EXPORT const tag DetectorDescription;
    /** DetectorElementPhysicalSize, 0x00187020, DS, 2 */
    extern DICOM_EXPORT const tag DetectorElementPhysicalSize;
    /** DetectorElementSize, 0x00541203, DS, 2 */
    extern DICOM_EXPORT const tag DetectorElementSize;
    /** DetectorElementSpacing, 0x00187022, DS, 2 */
    extern DICOM_EXPORT const tag DetectorElementSpacing;
    /** DetectorGeometry, 0x00189725, CS, 1 */
    extern DICOM_EXPORT const tag DetectorGeometry;
    /** DetectorGeometrySequence, 0x40100004, SQ, 1, RET */
    extern DICOM_EXPORT const tag DetectorGeometrySequence;
    /** DetectorID, 0x0018700A, SH, 1 */
    extern DICOM_EXPORT const tag DetectorID;
    /** DetectorInformationSequence, 0x00540022, SQ, 1 */
    extern DICOM_EXPORT const tag DetectorInformationSequence;
    /** DetectorIsocenterPrimaryAngle, 0x00189550, FD, 1 */
    extern DICOM_EXPORT const tag DetectorIsocenterPrimaryAngle;
    /** DetectorIsocenterSecondaryAngle, 0x00189551, FD, 1 */
    extern DICOM_EXPORT const tag DetectorIsocenterSecondaryAngle;
    /** DetectorLinesOfResponseUsed, 0x00541104, LO, 1 */
    extern DICOM_EXPORT const tag DetectorLinesOfResponseUsed;
    /** DetectorManufacturerModelName, 0x0018702B, LO, 1 */
    extern DICOM_EXPORT const tag DetectorManufacturerModelName;
    /** DetectorManufacturerName, 0x0018702A, LO, 1 */
    extern DICOM_EXPORT const tag DetectorManufacturerName;
    /** DetectorMode, 0x00187008, LT, 1 */
    extern DICOM_EXPORT const tag DetectorMode;
    /** DetectorNormalizationCorrection, 0x00189768, CS, 1 */
    extern DICOM_EXPORT const tag DetectorNormalizationCorrection;
    /** DetectorPositionSequence, 0x00189541, SQ, 1 */
    extern DICOM_EXPORT const tag DetectorPositionSequence;
    /** DetectorPrimaryAngle, 0x00181530, DS, 1 */
    extern DICOM_EXPORT const tag DetectorPrimaryAngle;
    /** DetectorSecondaryAngle, 0x00181531, DS, 1 */
    extern DICOM_EXPORT const tag DetectorSecondaryAngle;
    /** DetectorTemperature, 0x00187001, DS, 1 */
    extern DICOM_EXPORT const tag DetectorTemperature;
    /** DetectorTemperatureSequence, 0x00143020, SQ, 1, RET */
    extern DICOM_EXPORT const tag DetectorTemperatureSequence;
    /** DetectorTimeSinceLastExposure, 0x00187012, DS, 1 */
    extern DICOM_EXPORT const tag DetectorTimeSinceLastExposure;
    /** DetectorType, 0x00187004, CS, 1 */
    extern DICOM_EXPORT const tag DetectorType;
    /** DetectorVector, 0x00540020, US, 1 */
    extern DICOM_EXPORT const tag DetectorVector;
    /** DetectorXPositionToIsocenter, 0x00189552, FD, 1 */
    extern DICOM_EXPORT const tag DetectorXPositionToIsocenter;
    /** DetectorYPositionToIsocenter, 0x00189553, FD, 1 */
    extern DICOM_EXPORT const tag DetectorYPositionToIsocenter;
    /** DetectorZPositionToIsocenter, 0x00189554, FD, 1 */
    extern DICOM_EXPORT const tag DetectorZPositionToIsocenter;
    /** DeviationIndex, 0x00181413, DS, 1 */
    extern DICOM_EXPORT const tag DeviationIndex;
    /** DeviceDescription, 0x00500020, LO, 1 */
    extern DICOM_EXPORT const tag DeviceDescription;
    /** DeviceDiameter, 0x00500016, DS, 1 */
    extern DICOM_EXPORT const tag DeviceDiameter;
    /** DeviceDiameterUnits, 0x00500017, CS, 1 */
    extern DICOM_EXPORT const tag DeviceDiameterUnits;
    /** DeviceID, 0x00181003, LO, 1 */
    extern DICOM_EXPORT const tag DeviceID;
    /** DeviceLength, 0x00500014, DS, 1 */
    extern DICOM_EXPORT const tag DeviceLength;
    /** DeviceMotionControlSequence, 0x300A0450, SQ, 1 */
    extern DICOM_EXPORT const tag DeviceMotionControlSequence;
    /** DeviceMotionExecutionMode, 0x300A0451, CS, 1 */
    extern DICOM_EXPORT const tag DeviceMotionExecutionMode;
    /** DeviceMotionObservationMode, 0x300A0452, CS, 1 */
    extern DICOM_EXPORT const tag DeviceMotionObservationMode;
    /** DeviceMotionParameterCodeSequence, 0x300A0453, SQ, 1 */
    extern DICOM_EXPORT const tag DeviceMotionParameterCodeSequence;
    /** DeviceSequence, 0x00500010, SQ, 1 */
    extern DICOM_EXPORT const tag DeviceSequence;
    /** DeviceSerialNumber, 0x00181000, LO, 1 */
    extern DICOM_EXPORT const tag DeviceSerialNumber;
    /** DeviceUID, 0x00181002, UI, 1 */
    extern DICOM_EXPORT const tag DeviceUID;
    /** DeviceVolume, 0x00500018, DS, 1 */
    extern DICOM_EXPORT const tag DeviceVolume;
    /** DiameterOfVisibility, 0x00700262, FL, 1 */
    extern DICOM_EXPORT const tag DiameterOfVisibility;
    /** DiaphragmPosition, 0x30020034, DS, 4 */
    extern DICOM_EXPORT const tag DiaphragmPosition;
    /** DICOMMediaRetrievalSequence, 0x0040E022, SQ, 1 */
    extern DICOM_EXPORT const tag DICOMMediaRetrievalSequence;
    /** DICOMRetrievalSequence, 0x0040E021, SQ, 1 */
    extern DICOM_EXPORT const tag DICOMRetrievalSequence;
    /** DICOMStorageSequence, 0x00404071, SQ, 1 */
    extern DICOM_EXPORT const tag DICOMStorageSequence;
    /** DICOSVersion, 0x4010103A, CS, 1, RET */
    extern DICOM_EXPORT const tag DICOSVersion;
    /** DiffuseReflectionIntensity, 0x00701704, FD, 1 */
    extern DICOM_EXPORT const tag DiffuseReflectionIntensity;
    /** DiffusionAcquisitionCodeSequence, 0x00660133, SQ, 1 */
    extern DICOM_EXPORT const tag DiffusionAcquisitionCodeSequence;
    /** DiffusionAnisotropyType, 0x00189147, CS, 1 */
    extern DICOM_EXPORT const tag DiffusionAnisotropyType;
    /** DiffusionBMatrixSequence, 0x00189601, SQ, 1 */
    extern DICOM_EXPORT const tag DiffusionBMatrixSequence;
    /** DiffusionBValue, 0x00189087, FD, 1 */
    extern DICOM_EXPORT const tag DiffusionBValue;
    /** DiffusionBValueXX, 0x00189602, FD, 1 */
    extern DICOM_EXPORT const tag DiffusionBValueXX;
    /** DiffusionBValueXY, 0x00189603, FD, 1 */
    extern DICOM_EXPORT const tag DiffusionBValueXY;
    /** DiffusionBValueXZ, 0x00189604, FD, 1 */
    extern DICOM_EXPORT const tag DiffusionBValueXZ;
    /** DiffusionBValueYY, 0x00189605, FD, 1 */
    extern DICOM_EXPORT const tag DiffusionBValueYY;
    /** DiffusionBValueYZ, 0x00189606, FD, 1 */
    extern DICOM_EXPORT const tag DiffusionBValueYZ;
    /** DiffusionBValueZZ, 0x00189607, FD, 1 */
    extern DICOM_EXPORT const tag DiffusionBValueZZ;
    /** DiffusionDirectionality, 0x00189075, CS, 1 */
    extern DICOM_EXPORT const tag DiffusionDirectionality;
    /** DiffusionGradientDirectionSequence, 0x00189076, SQ, 1 */
    extern DICOM_EXPORT const tag DiffusionGradientDirectionSequence;
    /** DiffusionGradientOrientation, 0x00189089, FD, 3 */
    extern DICOM_EXPORT const tag DiffusionGradientOrientation;
    /** DiffusionModelCodeSequence, 0x00660134, SQ, 1 */
    extern DICOM_EXPORT const tag DiffusionModelCodeSequence;
    /** DigitalImageFormatAcquired, 0x00181023, LO, 1 */
    extern DICOM_EXPORT const tag DigitalImageFormatAcquired;
    /** DigitalSignatureDateTime, 0x04000105, DT, 1 */
    extern DICOM_EXPORT const tag DigitalSignatureDateTime;
    /** DigitalSignaturePurposeCodeSequence, 0x04000401, SQ, 1 */
    extern DICOM_EXPORT const tag DigitalSignaturePurposeCodeSequence;
    /** DigitalSignaturesSequence, 0xFFFAFFFA, SQ, 1 */
    extern DICOM_EXPORT const tag DigitalSignaturesSequence;
    /** DigitalSignatureUID, 0x04000100, UI, 1 */
    extern DICOM_EXPORT const tag DigitalSignatureUID;
    /** DigitizingDeviceTransportDirection, 0x00182020, CS, 1 */
    extern DICOM_EXPORT const tag DigitizingDeviceTransportDirection;
    /** DimensionDescriptionLabel, 0x00209421, LO, 1 */
    extern DICOM_EXPORT const tag DimensionDescriptionLabel;
    /** DimensionIndexPointer, 0x00209165, AT, 1 */
    extern DICOM_EXPORT const tag DimensionIndexPointer;
    /** DimensionIndexPrivateCreator, 0x00209213, LO, 1 */
    extern DICOM_EXPORT const tag DimensionIndexPrivateCreator;
    /** DimensionIndexSequence, 0x00209222, SQ, 1 */
    extern DICOM_EXPORT const tag DimensionIndexSequence;
    /** DimensionIndexValues, 0x00209157, UL, 1 */
    extern DICOM_EXPORT const tag DimensionIndexValues;
    /** DimensionOrganizationSequence, 0x00209221, SQ, 1 */
    extern DICOM_EXPORT const tag DimensionOrganizationSequence;
    /** DimensionOrganizationType, 0x00209311, CS, 1 */
    extern DICOM_EXPORT const tag DimensionOrganizationType;
    /** DimensionOrganizationUID, 0x00209164, UI, 1 */
    extern DICOM_EXPORT const tag DimensionOrganizationUID;
    /** DirectoryRecordSequence, 0x00041220, SQ, 1 */
    extern DICOM_EXPORT const tag DirectoryRecordSequence;
    /** DirectoryRecordType, 0x00041430, CS, 1 */
    extern DICOM_EXPORT const tag DirectoryRecordType;
    /** DischargeDate, 0x00380030, DA, 1, RET */
    extern DICOM_EXPORT const tag DischargeDate;
    /** DischargeDiagnosisCodeSequence, 0x00380044, SQ, 1, RET */
    extern DICOM_EXPORT const tag DischargeDiagnosisCodeSequence;
    /** DischargeDiagnosisDescription, 0x00380040, LO, 1, RET */
    extern DICOM_EXPORT const tag DischargeDiagnosisDescription;
    /** DischargeTime, 0x00380032, TM, 1, RET */
    extern DICOM_EXPORT const tag DischargeTime;
    /** DisplayCalibrationResultSequence, 0x00287016, SQ, 1 */
    extern DICOM_EXPORT const tag DisplayCalibrationResultSequence;
    /** DisplayDeviceTypeCodeSequence, 0x00287022, SQ, 1 */
    extern DICOM_EXPORT const tag DisplayDeviceTypeCodeSequence;
    /** DisplayedAreaBottomRightHandCorner, 0x00700053, SL, 2 */
    extern DICOM_EXPORT const tag DisplayedAreaBottomRightHandCorner;
    /** DisplayedAreaBottomRightHandCornerTrial, 0x00700051, US, 2, RET */
    extern DICOM_EXPORT const tag DisplayedAreaBottomRightHandCornerTrial;
    /** DisplayedAreaSelectionSequence, 0x0070005A, SQ, 1 */
    extern DICOM_EXPORT const tag DisplayedAreaSelectionSequence;
    /** DisplayedAreaTopLeftHandCorner, 0x00700052, SL, 2 */
    extern DICOM_EXPORT const tag DisplayedAreaTopLeftHandCorner;
    /** DisplayedAreaTopLeftHandCornerTrial, 0x00700050, US, 2, RET */
    extern DICOM_EXPORT const tag DisplayedAreaTopLeftHandCornerTrial;
    /** DisplayedZValue, 0x00182046, FL, 1 */
    extern DICOM_EXPORT const tag DisplayedZValue;
    /** DisplayEnvironmentSpatialPosition, 0x00720108, FD, 4 */
    extern DICOM_EXPORT const tag DisplayEnvironmentSpatialPosition;
    /** DisplayFilterPercentage, 0x00289411, FL, 1 */
    extern DICOM_EXPORT const tag DisplayFilterPercentage;
    /** DisplayFunctionType, 0x00287019, CS, 1 */
    extern DICOM_EXPORT const tag DisplayFunctionType;
    /** DisplaySetHorizontalJustification, 0x00720717, CS, 1 */
    extern DICOM_EXPORT const tag DisplaySetHorizontalJustification;
    /** DisplaySetLabel, 0x00720203, LO, 1 */
    extern DICOM_EXPORT const tag DisplaySetLabel;
    /** DisplaySetNumber, 0x00720202, US, 1 */
    extern DICOM_EXPORT const tag DisplaySetNumber;
    /** DisplaySetPatientOrientation, 0x00720700, CS, 2 */
    extern DICOM_EXPORT const tag DisplaySetPatientOrientation;
    /** DisplaySetPresentationGroup, 0x00720204, US, 1 */
    extern DICOM_EXPORT const tag DisplaySetPresentationGroup;
    /** DisplaySetPresentationGroupDescription, 0x00720206, LO, 1 */
    extern DICOM_EXPORT const tag DisplaySetPresentationGroupDescription;
    /** DisplaySetScrollingGroup, 0x00720212, US, 2 */
    extern DICOM_EXPORT const tag DisplaySetScrollingGroup;
    /** DisplaySetsSequence, 0x00720200, SQ, 1 */
    extern DICOM_EXPORT const tag DisplaySetsSequence;
    /** DisplaySetVerticalJustification, 0x00720718, CS, 1 */
    extern DICOM_EXPORT const tag DisplaySetVerticalJustification;
    /** DisplayShadingFlag, 0x003A0246, CS, 1 */
    extern DICOM_EXPORT const tag DisplayShadingFlag;
    /** DisplaySubsystemConfigurationSequence, 0x0028700A, SQ, 1 */
    extern DICOM_EXPORT const tag DisplaySubsystemConfigurationSequence;
    /** DisplaySubsystemDescription, 0x00287005, LO, 1 */
    extern DICOM_EXPORT const tag DisplaySubsystemDescription;
    /** DisplaySubsystemID, 0x00287003, US, 1 */
    extern DICOM_EXPORT const tag DisplaySubsystemID;
    /** DisplaySubsystemName, 0x00287004, SH, 1 */
    extern DICOM_EXPORT const tag DisplaySubsystemName;
    /** DisplaySubsystemQAResultsSequence, 0x00287010, SQ, 1 */
    extern DICOM_EXPORT const tag DisplaySubsystemQAResultsSequence;
    /** DisplaySubsystemSequence, 0x00287023, SQ, 1 */
    extern DICOM_EXPORT const tag DisplaySubsystemSequence;
    /** DisplayWindowLabelVector, 0x00182006, SH, 1 */
    extern DICOM_EXPORT const tag DisplayWindowLabelVector;
    /** DistalDepth, 0x300A0502, FL, 1 */
    extern DICOM_EXPORT const tag DistalDepth;
    /** DistalDepthFraction, 0x300A0501, FL, 1 */
    extern DICOM_EXPORT const tag DistalDepthFraction;
    /** DistanceBetweenBscanSlabs, 0x00221644, FL, 1 */
    extern DICOM_EXPORT const tag DistanceBetweenBscanSlabs;
    /** DistanceBetweenFocalPlanes, 0x00480014, FL, 1 */
    extern DICOM_EXPORT const tag DistanceBetweenFocalPlanes;
    /** DistanceObjectToTableTop, 0x00189403, FL, 1 */
    extern DICOM_EXPORT const tag DistanceObjectToTableTop;
    /** DistancePupillaryDistance, 0x00460060, FD, 1 */
    extern DICOM_EXPORT const tag DistancePupillaryDistance;
    /** DistanceReceptorPlaneToDetectorHousing, 0x00189426, FL, 1 */
    extern DICOM_EXPORT const tag DistanceReceptorPlaneToDetectorHousing;
    /** DistanceSourceToDataCollectionCenter, 0x00189335, FD, 1 */
    extern DICOM_EXPORT const tag DistanceSourceToDataCollectionCenter;
    /** DistanceSourceToDetector, 0x00181110, DS, 1 */
    extern DICOM_EXPORT const tag DistanceSourceToDetector;
    /** DistanceSourceToEntrance, 0x00400306, DS, 1 */
    extern DICOM_EXPORT const tag DistanceSourceToEntrance;
    /** DistanceSourceToIsocenter, 0x00189402, FL, 1 */
    extern DICOM_EXPORT const tag DistanceSourceToIsocenter;
    /** DistanceSourceToPatient, 0x00181111, DS, 1 */
    extern DICOM_EXPORT const tag DistanceSourceToPatient;
    /** DistanceSourceToSupport, 0x00400307, DS, 1, RET */
    extern DICOM_EXPORT const tag DistanceSourceToSupport;
    /** DistributionAddress, 0x4008011A, LO, 1, RET */
    extern DICOM_EXPORT const tag DistributionAddress;
    /** DistributionName, 0x40080119, PN, 1, RET */
    extern DICOM_EXPORT const tag DistributionName;
    /** DistributionType, 0x00120084, CS, 1 */
    extern DICOM_EXPORT const tag DistributionType;
    /** DLPNotificationTrigger, 0x00189943, FD, 1 */
    extern DICOM_EXPORT const tag DLPNotificationTrigger;
    /** DocumentAuthorIdentifierCodeSequenceTrial, 0x0040A068, SQ, 1, RET */
    extern DICOM_EXPORT const tag DocumentAuthorIdentifierCodeSequenceTrial;
    /** DocumentAuthorTrial, 0x0040A067, PN, 1, RET */
    extern DICOM_EXPORT const tag DocumentAuthorTrial;
    /** DocumentClassCodeSequence, 0x0040E008, SQ, 1 */
    extern DICOM_EXPORT const tag DocumentClassCodeSequence;
    /** DocumentIdentifierCodeSequenceTrial, 0x0040A066, SQ, 1, RET */
    extern DICOM_EXPORT const tag DocumentIdentifierCodeSequenceTrial;
    /** DocumentingObserverIdentifierCodeSequenceTrial, 0x0040A076, SQ, 1, RET */
    extern DICOM_EXPORT const tag DocumentingObserverIdentifierCodeSequenceTrial;
    /** DocumentingOrganizationIdentifierCodeSequenceTrial, 0x0040A028, SQ, 1, RET */
    extern DICOM_EXPORT const tag DocumentingOrganizationIdentifierCodeSequenceTrial;
    /** DocumentTitle, 0x00420010, ST, 1 */
    extern DICOM_EXPORT const tag DocumentTitle;
    /** DopplerCorrectionAngle, 0x00186034, FD, 1 */
    extern DICOM_EXPORT const tag DopplerCorrectionAngle;
    /** DopplerSampleVolumeXPosition, 0x00186039, SL, 1 */
    extern DICOM_EXPORT const tag DopplerSampleVolumeXPosition;
    /** DopplerSampleVolumeXPositionRetired, 0x00186038, UL, 1, RET */
    extern DICOM_EXPORT const tag DopplerSampleVolumeXPositionRetired;
    /** DopplerSampleVolumeYPosition, 0x0018603B, SL, 1 */
    extern DICOM_EXPORT const tag DopplerSampleVolumeYPosition;
    /** DopplerSampleVolumeYPositionRetired, 0x0018603A, UL, 1, RET */
    extern DICOM_EXPORT const tag DopplerSampleVolumeYPositionRetired;
    /** DoseCalibrationFactor, 0x00541322, DS, 1 */
    extern DICOM_EXPORT const tag DoseCalibrationFactor;
    /** DoseComment, 0x30040006, LO, 1 */
    extern DICOM_EXPORT const tag DoseComment;
    /** DoseGridScaling, 0x3004000E, DS, 1 */
    extern DICOM_EXPORT const tag DoseGridScaling;
    /** DoseRateDelivered, 0x30080048, DS, 1 */
    extern DICOM_EXPORT const tag DoseRateDelivered;
    /** DoseRateSet, 0x300A0115, DS, 1 */
    extern DICOM_EXPORT const tag DoseRateSet;
    /** DoseReferenceDescription, 0x300A0016, LO, 1 */
    extern DICOM_EXPORT const tag DoseReferenceDescription;
    /** DoseReferenceNumber, 0x300A0012, IS, 1 */
    extern DICOM_EXPORT const tag DoseReferenceNumber;
    /** DoseReferencePointCoordinates, 0x300A0018, DS, 3 */
    extern DICOM_EXPORT const tag DoseReferencePointCoordinates;
    /** DoseReferenceSequence, 0x300A0010, SQ, 1 */
    extern DICOM_EXPORT const tag DoseReferenceSequence;
    /** DoseReferenceStructureType, 0x300A0014, CS, 1 */
    extern DICOM_EXPORT const tag DoseReferenceStructureType;
    /** DoseReferenceType, 0x300A0020, CS, 1 */
    extern DICOM_EXPORT const tag DoseReferenceType;
    /** DoseReferenceUID, 0x300A0013, UI, 1 */
    extern DICOM_EXPORT const tag DoseReferenceUID;
    /** DoseSummationType, 0x3004000A, CS, 1 */
    extern DICOM_EXPORT const tag DoseSummationType;
    /** DoseType, 0x30040004, CS, 1 */
    extern DICOM_EXPORT const tag DoseType;
    /** DoseUnits, 0x30040002, CS, 1 */
    extern DICOM_EXPORT const tag DoseUnits;
    /** DoseValue, 0x30040012, DS, 1 */
    extern DICOM_EXPORT const tag DoseValue;
    /** DoubleExposureFieldDelta, 0x0074133A, FD, 4 */
    extern DICOM_EXPORT const tag DoubleExposureFieldDelta;
    /** DoubleExposureFieldDeltaTrial, 0x0074103A, DS, 4, RET */
    extern DICOM_EXPORT const tag DoubleExposureFieldDeltaTrial;
    /** DoubleExposureFlag, 0x00741034, CS, 1 */
    extern DICOM_EXPORT const tag DoubleExposureFlag;
    /** DoubleExposureMeterset, 0x00741338, FD, 1 */
    extern DICOM_EXPORT const tag DoubleExposureMeterset;
    /** DoubleExposureMetersetTrial, 0x00741038, DS, 1, RET */
    extern DICOM_EXPORT const tag DoubleExposureMetersetTrial;
    /** DoubleExposureOrdering, 0x00741036, CS, 1 */
    extern DICOM_EXPORT const tag DoubleExposureOrdering;
    /** DoubleFloatPixelData, 0x7FE00009, OD, 1 */
    extern DICOM_EXPORT const tag DoubleFloatPixelData;
    /** DoubleFloatPixelPaddingRangeLimit, 0x00280125, FD, 1 */
    extern DICOM_EXPORT const tag DoubleFloatPixelPaddingRangeLimit;
    /** DoubleFloatPixelPaddingValue, 0x00280123, FD, 1 */
    extern DICOM_EXPORT const tag DoubleFloatPixelPaddingValue;
    /** DoubleFloatRealWorldValueFirstValueMapped, 0x00409214, FD, 1 */
    extern DICOM_EXPORT const tag DoubleFloatRealWorldValueFirstValueMapped;
    /** DoubleFloatRealWorldValueLastValueMapped, 0x00409213, FD, 1 */
    extern DICOM_EXPORT const tag DoubleFloatRealWorldValueLastValueMapped;
    /** DriveProbeSequence, 0x00144083, SQ, 1, RET */
    extern DICOM_EXPORT const tag DriveProbeSequence;
    /** DriveType, 0x00144081, CS, 1, RET */
    extern DICOM_EXPORT const tag DriveType;
    /** DVHData, 0x30040058, DS, 2 */
    extern DICOM_EXPORT const tag DVHData;
    /** DVHDoseScaling, 0x30040052, DS, 1 */
    extern DICOM_EXPORT const tag DVHDoseScaling;
    /** DVHMaximumDose, 0x30040072, DS, 1 */
    extern DICOM_EXPORT const tag DVHMaximumDose;
    /** DVHMeanDose, 0x30040074, DS, 1 */
    extern DICOM_EXPORT const tag DVHMeanDose;
    /** DVHMinimumDose, 0x30040070, DS, 1 */
    extern DICOM_EXPORT const tag DVHMinimumDose;
    /** DVHNormalizationDoseValue, 0x30040042, DS, 1 */
    extern DICOM_EXPORT const tag DVHNormalizationDoseValue;
    /** DVHNormalizationPoint, 0x30040040, DS, 3 */
    extern DICOM_EXPORT const tag DVHNormalizationPoint;
    /** DVHNumberOfBins, 0x30040056, IS, 1 */
    extern DICOM_EXPORT const tag DVHNumberOfBins;
    /** DVHReferencedROISequence, 0x30040060, SQ, 1 */
    extern DICOM_EXPORT const tag DVHReferencedROISequence;
    /** DVHROIContributionType, 0x30040062, CS, 1 */
    extern DICOM_EXPORT const tag DVHROIContributionType;
    /** DVHSequence, 0x30040050, SQ, 1 */
    extern DICOM_EXPORT const tag DVHSequence;
    /** DVHType, 0x30040001, CS, 1 */
    extern DICOM_EXPORT const tag DVHType;
    /** DVHVolumeUnits, 0x30040054, CS, 1 */
    extern DICOM_EXPORT const tag DVHVolumeUnits;
    /** DynamicRange, 0x00185030, DS, 1, RET */
    extern DICOM_EXPORT const tag DynamicRange;
    /** EchoNumbers, 0x00180086, IS, 1 */
    extern DICOM_EXPORT const tag EchoNumbers;
    /** EchoPeakPosition, 0x00189298, IS, 1 */
    extern DICOM_EXPORT const tag EchoPeakPosition;
    /** EchoPlanarPulseSequence, 0x00189018, CS, 1 */
    extern DICOM_EXPORT const tag EchoPlanarPulseSequence;
    /** EchoPulseSequence, 0x00189008, CS, 1 */
    extern DICOM_EXPORT const tag EchoPulseSequence;
    /** EchoTime, 0x00180081, DS, 1 */
    extern DICOM_EXPORT const tag EchoTime;
    /** EchoTrainLength, 0x00180091, IS, 1 */
    extern DICOM_EXPORT const tag EchoTrainLength;
    /** EdgePointIndexList, 0x00660024, OW, 1, RET */
    extern DICOM_EXPORT const tag EdgePointIndexList;
    /** EffectiveDateTime, 0x00686226, DT, 1 */
    extern DICOM_EXPORT const tag EffectiveDateTime;
    /** EffectiveDuration, 0x00180072, DS, 1 */
    extern DICOM_EXPORT const tag EffectiveDuration;
    /** EffectiveEchoTime, 0x00189082, FD, 1 */
    extern DICOM_EXPORT const tag EffectiveEchoTime;
    /** EffectiveRefractiveIndex, 0x00520004, FD, 1 */
    extern DICOM_EXPORT const tag EffectiveRefractiveIndex;
    /** EffectiveWedgeAngle, 0x300A00DE, DS, 1 */
    extern DICOM_EXPORT const tag EffectiveWedgeAngle;
    /** ElementDimensionA, 0x00144014, DS, 1, RET */
    extern DICOM_EXPORT const tag ElementDimensionA;
    /** ElementDimensionB, 0x00144015, DS, 1, RET */
    extern DICOM_EXPORT const tag ElementDimensionB;
    /** ElementPitchA, 0x00144016, DS, 1, RET */
    extern DICOM_EXPORT const tag ElementPitchA;
    /** ElementPitchB, 0x0014401D, DS, 1, RET */
    extern DICOM_EXPORT const tag ElementPitchB;
    /** ElementShape, 0x00144013, CS, 1, RET */
    extern DICOM_EXPORT const tag ElementShape;
    /** EmmetropicMagnification, 0x0022000A, FL, 1 */
    extern DICOM_EXPORT const tag EmmetropicMagnification;
    /** EmptyImageBoxCIELabValue, 0x00720421, US, 3 */
    extern DICOM_EXPORT const tag EmptyImageBoxCIELabValue;
    /** EmptyImageDensity, 0x20100110, CS, 1 */
    extern DICOM_EXPORT const tag EmptyImageDensity;
    /** EncapsulatedDocument, 0x00420011, OB, 1 */
    extern DICOM_EXPORT const tag EncapsulatedDocument;
    /** EncryptedAttributesSequence, 0x04000500, SQ, 1 */
    extern DICOM_EXPORT const tag EncryptedAttributesSequence;
    /** EncryptedContent, 0x04000520, OB, 1 */
    extern DICOM_EXPORT const tag EncryptedContent;
    /** EncryptedContentTransferSyntaxUID, 0x04000510, UI, 1 */
    extern DICOM_EXPORT const tag EncryptedContentTransferSyntaxUID;
    /** EndAcquisitionDateTime, 0x00189517, DT, 1 */
    extern DICOM_EXPORT const tag EndAcquisitionDateTime;
    /** EndCumulativeMetersetWeight, 0x300C0009, DS, 1 */
    extern DICOM_EXPORT const tag EndCumulativeMetersetWeight;
    /** EndCumulativeTimeWeight, 0x00741408, DS, 1 */
    extern DICOM_EXPORT const tag EndCumulativeTimeWeight;
    /** EndingRespiratoryAmplitude, 0x00209248, FL, 1 */
    extern DICOM_EXPORT const tag EndingRespiratoryAmplitude;
    /** EndingRespiratoryPhase, 0x00209249, CS, 1 */
    extern DICOM_EXPORT const tag EndingRespiratoryPhase;
    /** EndMeterset, 0x3008007A, DS, 1 */
    extern DICOM_EXPORT const tag EndMeterset;
    /** EnergyWeightingFactor, 0x00189353, FL, 1 */
    extern DICOM_EXPORT const tag EnergyWeightingFactor;
    /** EnergyWindowCenterline, 0x00180032, DS, 1, RET */
    extern DICOM_EXPORT const tag EnergyWindowCenterline;
    /** EnergyWindowInformationSequence, 0x00540012, SQ, 1 */
    extern DICOM_EXPORT const tag EnergyWindowInformationSequence;
    /** EnergyWindowLowerLimit, 0x00540014, DS, 1 */
    extern DICOM_EXPORT const tag EnergyWindowLowerLimit;
    /** EnergyWindowName, 0x00540018, SH, 1 */
    extern DICOM_EXPORT const tag EnergyWindowName;
    /** EnergyWindowNumber, 0x00540308, US, 1 */
    extern DICOM_EXPORT const tag EnergyWindowNumber;
    /** EnergyWindowRangeSequence, 0x00540013, SQ, 1 */
    extern DICOM_EXPORT const tag EnergyWindowRangeSequence;
    /** EnergyWindowTotalWidth, 0x00180033, DS, 1, RET */
    extern DICOM_EXPORT const tag EnergyWindowTotalWidth;
    /** EnergyWindowUpperLimit, 0x00540015, DS, 1 */
    extern DICOM_EXPORT const tag EnergyWindowUpperLimit;
    /** EnergyWindowVector, 0x00540010, US, 1 */
    extern DICOM_EXPORT const tag EnergyWindowVector;
    /** EnhancedPaletteColorLookupTableSequence, 0x0028140B, SQ, 1 */
    extern DICOM_EXPORT const tag EnhancedPaletteColorLookupTableSequence;
    /** EntranceDose, 0x00400302, US, 1 */
    extern DICOM_EXPORT const tag EntranceDose;
    /** EntranceDoseDerivation, 0x00408303, CS, 1 */
    extern DICOM_EXPORT const tag EntranceDoseDerivation;
    /** EntranceDoseInmGy, 0x00408302, DS, 1 */
    extern DICOM_EXPORT const tag EntranceDoseInmGy;
    /** EnvironmentalConditions, 0x00141040, ST, 1, RET */
    extern DICOM_EXPORT const tag EnvironmentalConditions;
    /** EquipmentAdministratorSequence, 0x00287000, SQ, 1 */
    extern DICOM_EXPORT const tag EquipmentAdministratorSequence;
    /** EquipmentCoordinateSystemIdentification, 0x00289537, CS, 1 */
    extern DICOM_EXPORT const tag EquipmentCoordinateSystemIdentification;
    /** EquipmentModality, 0x00080221, CS, 1 */
    extern DICOM_EXPORT const tag EquipmentModality;
    /** EquivalentCDADocumentSequence, 0x0040A090, SQ, 1, RET */
    extern DICOM_EXPORT const tag EquivalentCDADocumentSequence;
    /** EquivalentCodeSequence, 0x00080121, SQ, 1 */
    extern DICOM_EXPORT const tag EquivalentCodeSequence;
    /** EquivalentPupilRadius, 0x00460205, FL, 1 */
    extern DICOM_EXPORT const tag EquivalentPupilRadius;
    /** EscapeTriplet, 0x10000000, US, 3, RET */
    extern DICOM_EXPORT const range_tag EscapeTriplet;
    /** EstimatedDoseSaving, 0x00189324, FD, 1 */
    extern DICOM_EXPORT const tag EstimatedDoseSaving;
    /** EstimatedRadiographicMagnificationFactor, 0x00181114, DS, 1 */
    extern DICOM_EXPORT const tag EstimatedRadiographicMagnificationFactor;
    /** EthicsCommitteeApprovalEffectivenessEndDate, 0x00120087, DA, 1 */
    extern DICOM_EXPORT const tag EthicsCommitteeApprovalEffectivenessEndDate;
    /** EthicsCommitteeApprovalEffectivenessStartDate, 0x00120086, DA, 1 */
    extern DICOM_EXPORT const tag EthicsCommitteeApprovalEffectivenessStartDate;
    /** EthnicGroup, 0x00102160, SH, 1 */
    extern DICOM_EXPORT const tag EthnicGroup;
    /** EvaluationAttempt, 0x00142008, IS, 1, RET */
    extern DICOM_EXPORT const tag EvaluationAttempt;
    /** EvaluatorName, 0x00142006, PN, 1, RET */
    extern DICOM_EXPORT const tag EvaluatorName;
    /** EvaluatorNumber, 0x00142004, IS, 1, RET */
    extern DICOM_EXPORT const tag EvaluatorNumber;
    /** EvaluatorSequence, 0x00142002, SQ, 1, RET */
    extern DICOM_EXPORT const tag EvaluatorSequence;
    /** EventCodeSequence, 0x00082135, SQ, 1 */
    extern DICOM_EXPORT const tag EventCodeSequence;
    /** EventElapsedTimes, 0x00082130, DS, 1 */
    extern DICOM_EXPORT const tag EventElapsedTimes;
    /** EventTimeOffset, 0x00082134, FD, 1 */
    extern DICOM_EXPORT const tag EventTimeOffset;
    /** EventTimerNames, 0x00082132, LO, 1 */
    extern DICOM_EXPORT const tag EventTimerNames;
    /** EventTimerSequence, 0x00082133, SQ, 1 */
    extern DICOM_EXPORT const tag EventTimerSequence;
    /** ExaminedBodyThickness, 0x00109431, FL, 1 */
    extern DICOM_EXPORT const tag ExaminedBodyThickness;
    /** ExcessiveFalseNegatives, 0x00240052, CS, 1 */
    extern DICOM_EXPORT const tag ExcessiveFalseNegatives;
    /** ExcessiveFalseNegativesDataFlag, 0x00240051, CS, 1 */
    extern DICOM_EXPORT const tag ExcessiveFalseNegativesDataFlag;
    /** ExcessiveFalsePositives, 0x00240062, CS, 1 */
    extern DICOM_EXPORT const tag ExcessiveFalsePositives;
    /** ExcessiveFalsePositivesDataFlag, 0x00240061, CS, 1 */
    extern DICOM_EXPORT const tag ExcessiveFalsePositivesDataFlag;
    /** ExcessiveFixationLosses, 0x00240040, CS, 1 */
    extern DICOM_EXPORT const tag ExcessiveFixationLosses;
    /** ExcessiveFixationLossesDataFlag, 0x00240039, CS, 1 */
    extern DICOM_EXPORT const tag ExcessiveFixationLossesDataFlag;
    /** ExcitationFrequency, 0x00144024, DS, 1, RET */
    extern DICOM_EXPORT const tag ExcitationFrequency;
    /** ExcludedIntervalsSequence, 0x00189803, SQ, 1 */
    extern DICOM_EXPORT const tag ExcludedIntervalsSequence;
    /** ExclusionDuration, 0x00189805, FD, 1 */
    extern DICOM_EXPORT const tag ExclusionDuration;
    /** ExclusionStartDateTime, 0x00189804, DT, 1 */
    extern DICOM_EXPORT const tag ExclusionStartDateTime;
    /** ExclusiveComponentType, 0x00760036, CS, 1 */
    extern DICOM_EXPORT const tag ExclusiveComponentType;
    /** ExecutionStatus, 0x21000020, CS, 1 */
    extern DICOM_EXPORT const tag ExecutionStatus;
    /** ExecutionStatusInfo, 0x21000030, CS, 1 */
    extern DICOM_EXPORT const tag ExecutionStatusInfo;
    /** ExpectedCompletionDateTime, 0x00404011, DT, 1 */
    extern DICOM_EXPORT const tag ExpectedCompletionDateTime;
    /** ExpiryDate, 0x00141020, DA, 1, RET */
    extern DICOM_EXPORT const tag ExpiryDate;
    /** ExposedArea, 0x00400303, US, 1 */
    extern DICOM_EXPORT const tag ExposedArea;
    /** Exposure, 0x00181152, IS, 1 */
    extern DICOM_EXPORT const tag Exposure;
    /** ExposureControlMode, 0x00187060, CS, 1 */
    extern DICOM_EXPORT const tag ExposureControlMode;
    /** ExposureControlModeDescription, 0x00187062, LT, 1 */
    extern DICOM_EXPORT const tag ExposureControlModeDescription;
    /** ExposureControlSensingRegionLeftVerticalEdge, 0x00189436, SS, 1 */
    extern DICOM_EXPORT const tag ExposureControlSensingRegionLeftVerticalEdge;
    /** ExposureControlSensingRegionLowerHorizontalEdge, 0x00189439, SS, 1 */
    extern DICOM_EXPORT const tag ExposureControlSensingRegionLowerHorizontalEdge;
    /** ExposureControlSensingRegionRightVerticalEdge, 0x00189437, SS, 1 */
    extern DICOM_EXPORT const tag ExposureControlSensingRegionRightVerticalEdge;
    /** ExposureControlSensingRegionShape, 0x00189435, CS, 1 */
    extern DICOM_EXPORT const tag ExposureControlSensingRegionShape;
    /** ExposureControlSensingRegionsSequence, 0x00189434, SQ, 1 */
    extern DICOM_EXPORT const tag ExposureControlSensingRegionsSequence;
    /** ExposureControlSensingRegionUpperHorizontalEdge, 0x00189438, SS, 1 */
    extern DICOM_EXPORT const tag ExposureControlSensingRegionUpperHorizontalEdge;
    /** ExposureDoseSequence, 0x0040030E, SQ, 1, RET */
    extern DICOM_EXPORT const tag ExposureDoseSequence;
    /** ExposureIndex, 0x00181411, DS, 1 */
    extern DICOM_EXPORT const tag ExposureIndex;
    /** ExposureInmAs, 0x00189332, FD, 1 */
    extern DICOM_EXPORT const tag ExposureInmAs;
    /** ExposureInuAs, 0x00181153, IS, 1 */
    extern DICOM_EXPORT const tag ExposureInuAs;
    /** ExposureModulationType, 0x00189323, CS, 1 */
    extern DICOM_EXPORT const tag ExposureModulationType;
    /** ExposureSequence, 0x30020030, SQ, 1 */
    extern DICOM_EXPORT const tag ExposureSequence;
    /** ExposuresOnDetectorSinceLastCalibration, 0x00187010, IS, 1 */
    extern DICOM_EXPORT const tag ExposuresOnDetectorSinceLastCalibration;
    /** ExposuresOnDetectorSinceManufactured, 0x00187011, IS, 1 */
    extern DICOM_EXPORT const tag ExposuresOnDetectorSinceManufactured;
    /** ExposuresOnPlate, 0x00181404, US, 1 */
    extern DICOM_EXPORT const tag ExposuresOnPlate;
    /** ExposureStatus, 0x00187064, CS, 1 */
    extern DICOM_EXPORT const tag ExposureStatus;
    /** ExposureTime, 0x00181150, IS, 1 */
    extern DICOM_EXPORT const tag ExposureTime;
    /** ExposureTimeInms, 0x00189328, FD, 1 */
    extern DICOM_EXPORT const tag ExposureTimeInms;
    /** ExposureTimeInuS, 0x00188150, DS, 1 */
    extern DICOM_EXPORT const tag ExposureTimeInuS;
    /** ExtendedCodeMeaning, 0x00080108, LT, 1, RET */
    extern DICOM_EXPORT const tag ExtendedCodeMeaning;
    /** ExtendedCodeValue, 0x00080101, LO, 1, RET */
    extern DICOM_EXPORT const tag ExtendedCodeValue;
    /** ExtendedDepthOfField, 0x00480012, CS, 1 */
    extern DICOM_EXPORT const tag ExtendedDepthOfField;
    /** ExternalContourEntryPoint, 0x300A0133, FL, 3 */
    extern DICOM_EXPORT const tag ExternalContourEntryPoint;
    /** FacetSequence, 0x00660034, SQ, 1 */
    extern DICOM_EXPORT const tag FacetSequence;
    /** FailedAttributesSequence, 0x00741048, SQ, 1 */
    extern DICOM_EXPORT const tag FailedAttributesSequence;
    /** FailedSOPInstanceUIDList, 0x00080058, UI, 1 */
    extern DICOM_EXPORT const tag FailedSOPInstanceUIDList;
    /** FailedSOPSequence, 0x00081198, SQ, 1 */
    extern DICOM_EXPORT const tag FailedSOPSequence;
    /** FailureAttributes, 0x2200000E, AT, 1 */
    extern DICOM_EXPORT const tag FailureAttributes;
    /** FailureReason, 0x00081197, US, 1 */
    extern DICOM_EXPORT const tag FailureReason;
    /** FalseNegativesEstimate, 0x00240046, FL, 1 */
    extern DICOM_EXPORT const tag FalseNegativesEstimate;
    /** FalseNegativesEstimateFlag, 0x00240045, CS, 1 */
    extern DICOM_EXPORT const tag FalseNegativesEstimateFlag;
    /** FalseNegativesQuantity, 0x00240050, US, 1 */
    extern DICOM_EXPORT const tag FalseNegativesQuantity;
    /** FalsePositivesEstimate, 0x00240054, FL, 1 */
    extern DICOM_EXPORT const tag FalsePositivesEstimate;
    /** FalsePositivesEstimateFlag, 0x00240053, CS, 1 */
    extern DICOM_EXPORT const tag FalsePositivesEstimateFlag;
    /** FalsePositivesQuantity, 0x00240060, US, 1 */
    extern DICOM_EXPORT const tag FalsePositivesQuantity;
    /** FiducialDescription, 0x0070030F, ST, 1 */
    extern DICOM_EXPORT const tag FiducialDescription;
    /** FiducialIdentifier, 0x00700310, SH, 1 */
    extern DICOM_EXPORT const tag FiducialIdentifier;
    /** FiducialIdentifierCodeSequence, 0x00700311, SQ, 1 */
    extern DICOM_EXPORT const tag FiducialIdentifierCodeSequence;
    /** FiducialSequence, 0x0070031E, SQ, 1 */
    extern DICOM_EXPORT const tag FiducialSequence;
    /** FiducialSetSequence, 0x0070031C, SQ, 1 */
    extern DICOM_EXPORT const tag FiducialSetSequence;
    /** FiducialsPropertyCategoryCodeSequence, 0x0070031F, SQ, 1 */
    extern DICOM_EXPORT const tag FiducialsPropertyCategoryCodeSequence;
    /** FiducialUID, 0x0070031A, UI, 1 */
    extern DICOM_EXPORT const tag FiducialUID;
    /** FieldOfViewDescription, 0x00189433, LO, 1 */
    extern DICOM_EXPORT const tag FieldOfViewDescription;
    /** FieldOfViewDimensions, 0x00181149, IS, 1 */
    extern DICOM_EXPORT const tag FieldOfViewDimensions;
    /** FieldOfViewDimensionsInFloat, 0x00189461, FL, 1 */
    extern DICOM_EXPORT const tag FieldOfViewDimensionsInFloat;
    /** FieldOfViewHorizontalFlip, 0x00187034, CS, 1 */
    extern DICOM_EXPORT const tag FieldOfViewHorizontalFlip;
    /** FieldOfViewOrigin, 0x00187030, DS, 2 */
    extern DICOM_EXPORT const tag FieldOfViewOrigin;
    /** FieldOfViewRotation, 0x00187032, DS, 1 */
    extern DICOM_EXPORT const tag FieldOfViewRotation;
    /** FieldOfViewSequence, 0x00189432, SQ, 1 */
    extern DICOM_EXPORT const tag FieldOfViewSequence;
    /** FieldOfViewShape, 0x00181147, CS, 1 */
    extern DICOM_EXPORT const tag FieldOfViewShape;
    /** FileMetaInformationGroupLength, 0x00020000, UL, 1 */
    extern DICOM_EXPORT const tag FileMetaInformationGroupLength;
    /** FileMetaInformationVersion, 0x00020001, OB, 1 */
    extern DICOM_EXPORT const tag FileMetaInformationVersion;
    /** FileSetConsistencyFlag, 0x00041212, US, 1 */
    extern DICOM_EXPORT const tag FileSetConsistencyFlag;
    /** FileSetDescriptorFileID, 0x00041141, CS, 1 */
    extern DICOM_EXPORT const tag FileSetDescriptorFileID;
    /** FileSetID, 0x00041130, CS, 1 */
    extern DICOM_EXPORT const tag FileSetID;
    /** FillerOrderNumberImagingServiceRequest, 0x00402017, LO, 1 */
    extern DICOM_EXPORT const tag FillerOrderNumberImagingServiceRequest;
    /** FillerOrderNumberImagingServiceRequestRetired, 0x00402007, SH, 1, RET */
    extern DICOM_EXPORT const tag FillerOrderNumberImagingServiceRequestRetired;
    /** FillerOrderNumberProcedure, 0x00401007, SH, 1, RET */
    extern DICOM_EXPORT const tag FillerOrderNumberProcedure;
    /** FillMode, 0x00700257, CS, 1 */
    extern DICOM_EXPORT const tag FillMode;
    /** FillPattern, 0x00700256, OB, 1 */
    extern DICOM_EXPORT const tag FillPattern;
    /** FillStyleSequence, 0x00700233, SQ, 1 */
    extern DICOM_EXPORT const tag FillStyleSequence;
    /** FilmBoxContentSequence, 0x21300030, SQ, 1, RET */
    extern DICOM_EXPORT const tag FilmBoxContentSequence;
    /** FilmConsumptionSequence, 0x00400321, SQ, 1 */
    extern DICOM_EXPORT const tag FilmConsumptionSequence;
    /** FilmDestination, 0x20000040, CS, 1 */
    extern DICOM_EXPORT const tag FilmDestination;
    /** FilmOrientation, 0x20100040, CS, 1 */
    extern DICOM_EXPORT const tag FilmOrientation;
    /** FilmSessionLabel, 0x20000050, LO, 1 */
    extern DICOM_EXPORT const tag FilmSessionLabel;
    /** FilmSizeID, 0x20100050, CS, 1 */
    extern DICOM_EXPORT const tag FilmSizeID;
    /** FilterBeamPathLengthMaximum, 0x00187058, FL, 1 */
    extern DICOM_EXPORT const tag FilterBeamPathLengthMaximum;
    /** FilterBeamPathLengthMinimum, 0x00187056, FL, 1 */
    extern DICOM_EXPORT const tag FilterBeamPathLengthMinimum;
    /** FilterByAttributePresence, 0x00720404, CS, 1 */
    extern DICOM_EXPORT const tag FilterByAttributePresence;
    /** FilterByCategory, 0x00720402, CS, 1 */
    extern DICOM_EXPORT const tag FilterByCategory;
    /** FilterByOperator, 0x00720406, CS, 1 */
    extern DICOM_EXPORT const tag FilterByOperator;
    /** FilterHighFrequency, 0x003A0221, DS, 1 */
    extern DICOM_EXPORT const tag FilterHighFrequency;
    /** FilterLowFrequency, 0x003A0220, DS, 1 */
    extern DICOM_EXPORT const tag FilterLowFrequency;
    /** FilterMaterial, 0x00187050, CS, 1 */
    extern DICOM_EXPORT const tag FilterMaterial;
    /** FilterMaterialUsedInGainCalibration, 0x00143074, LO, 1, RET */
    extern DICOM_EXPORT const tag FilterMaterialUsedInGainCalibration;
    /** FilterOperationsSequence, 0x00720400, SQ, 1 */
    extern DICOM_EXPORT const tag FilterOperationsSequence;
    /** FilterThicknessMaximum, 0x00187054, DS, 1 */
    extern DICOM_EXPORT const tag FilterThicknessMaximum;
    /** FilterThicknessMinimum, 0x00187052, DS, 1 */
    extern DICOM_EXPORT const tag FilterThicknessMinimum;
    /** FilterThicknessUsedInGainCalibration, 0x00143075, DS, 1, RET */
    extern DICOM_EXPORT const tag FilterThicknessUsedInGainCalibration;
    /** FilterType, 0x00181160, SH, 1 */
    extern DICOM_EXPORT const tag FilterType;
    /** FinalCumulativeMetersetWeight, 0x300A010E, DS, 1 */
    extern DICOM_EXPORT const tag FinalCumulativeMetersetWeight;
    /** FinalCumulativeTimeWeight, 0x300A02C8, DS, 1 */
    extern DICOM_EXPORT const tag FinalCumulativeTimeWeight;
    /** FindingsFlagTrial, 0x0040A007, CS, 1, RET */
    extern DICOM_EXPORT const tag FindingsFlagTrial;
    /** FindingsGroupRecordingDateTrial, 0x0040A023, DA, 1, RET */
    extern DICOM_EXPORT const tag FindingsGroupRecordingDateTrial;
    /** FindingsGroupRecordingTimeTrial, 0x0040A024, TM, 1, RET */
    extern DICOM_EXPORT const tag FindingsGroupRecordingTimeTrial;
    /** FindingsGroupUIDTrial, 0x0040A021, UI, 1, RET */
    extern DICOM_EXPORT const tag FindingsGroupUIDTrial;
    /** FindingsSequenceTrial, 0x0040A020, SQ, 1, RET */
    extern DICOM_EXPORT const tag FindingsSequenceTrial;
    /** FindingsSourceCategoryCodeSequenceTrial, 0x0040A026, SQ, 1, RET */
    extern DICOM_EXPORT const tag FindingsSourceCategoryCodeSequenceTrial;
    /** FiniteVolume, 0x0066000E, CS, 1 */
    extern DICOM_EXPORT const tag FiniteVolume;
    /** FirstALineLocation, 0x00520034, FD, 1 */
    extern DICOM_EXPORT const tag FirstALineLocation;
    /** FirstOrderPhaseCorrection, 0x00189198, CS, 1 */
    extern DICOM_EXPORT const tag FirstOrderPhaseCorrection;
    /** FirstOrderPhaseCorrectionAngle, 0x56000010, OF, 1 */
    extern DICOM_EXPORT const tag FirstOrderPhaseCorrectionAngle;
    /** FirstTreatmentDate, 0x30080054, DA, 1 */
    extern DICOM_EXPORT const tag FirstTreatmentDate;
    /** FixationCheckedQuantity, 0x00240035, US, 1 */
    extern DICOM_EXPORT const tag FixationCheckedQuantity;
    /** FixationDeviceDescription, 0x300A0196, ST, 1 */
    extern DICOM_EXPORT const tag FixationDeviceDescription;
    /** FixationDeviceLabel, 0x300A0194, SH, 1 */
    extern DICOM_EXPORT const tag FixationDeviceLabel;
    /** FixationDevicePitchAngle, 0x300A0199, FL, 1 */
    extern DICOM_EXPORT const tag FixationDevicePitchAngle;
    /** FixationDevicePosition, 0x300A0198, SH, 1 */
    extern DICOM_EXPORT const tag FixationDevicePosition;
    /** FixationDeviceRollAngle, 0x300A019A, FL, 1 */
    extern DICOM_EXPORT const tag FixationDeviceRollAngle;
    /** FixationDeviceSequence, 0x300A0190, SQ, 1 */
    extern DICOM_EXPORT const tag FixationDeviceSequence;
    /** FixationDeviceType, 0x300A0192, CS, 1 */
    extern DICOM_EXPORT const tag FixationDeviceType;
    /** FixationEye, 0x300A0150, CS, 1 */
    extern DICOM_EXPORT const tag FixationEye;
    /** FixationLightAzimuthalAngle, 0x300A0356, FL, 1 */
    extern DICOM_EXPORT const tag FixationLightAzimuthalAngle;
    /** FixationLightAzimuthalAngleTolerance, 0x300A0154, DS, 1 */
    extern DICOM_EXPORT const tag FixationLightAzimuthalAngleTolerance;
    /** FixationLightPolarAngle, 0x300A0358, FL, 1 */
    extern DICOM_EXPORT const tag FixationLightPolarAngle;
    /** FixationLightPolarAngleTolerance, 0x300A0155, DS, 1 */
    extern DICOM_EXPORT const tag FixationLightPolarAngleTolerance;
    /** FixationMethodCodeSequence, 0x006863AC, SQ, 1 */
    extern DICOM_EXPORT const tag FixationMethodCodeSequence;
    /** FixationMonitoringCodeSequence, 0x00240033, SQ, 1 */
    extern DICOM_EXPORT const tag FixationMonitoringCodeSequence;
    /** FixationSequence, 0x00240032, SQ, 1 */
    extern DICOM_EXPORT const tag FixationSequence;
    /** FlatKeratometricAxisSequence, 0x00460080, SQ, 1 */
    extern DICOM_EXPORT const tag FlatKeratometricAxisSequence;
    /** FlipAngle, 0x00181314, DS, 1 */
    extern DICOM_EXPORT const tag FlipAngle;
    /** FloatingPointValue, 0x0040A161, FD, 1 */
    extern DICOM_EXPORT const tag FloatingPointValue;
    /** FloatingPointValues, 0x00660125, OF, 1 */
    extern DICOM_EXPORT const tag FloatingPointValues;
    /** FloatPixelData, 0x7FE00008, OF, 1 */
    extern DICOM_EXPORT const tag FloatPixelData;
    /** FloatPixelPaddingRangeLimit, 0x00280124, FL, 1 */
    extern DICOM_EXPORT const tag FloatPixelPaddingRangeLimit;
    /** FloatPixelPaddingValue, 0x00280122, FL, 1 */
    extern DICOM_EXPORT const tag FloatPixelPaddingValue;
    /** FlowCompensation, 0x00189010, CS, 1 */
    extern DICOM_EXPORT const tag FlowCompensation;
    /** FlowCompensationDirection, 0x00189183, CS, 1 */
    extern DICOM_EXPORT const tag FlowCompensationDirection;
    /** FluenceDataScale, 0x30020042, DS, 1 */
    extern DICOM_EXPORT const tag FluenceDataScale;
    /** FluenceDataSource, 0x30020041, CS, 1 */
    extern DICOM_EXPORT const tag FluenceDataSource;
    /** FluenceMapSequence, 0x30020040, SQ, 1 */
    extern DICOM_EXPORT const tag FluenceMapSequence;
    /** FluenceMode, 0x30020051, CS, 1 */
    extern DICOM_EXPORT const tag FluenceMode;
    /** FluenceModeID, 0x30020052, SH, 1 */
    extern DICOM_EXPORT const tag FluenceModeID;
    /** FluoroscopyFlag, 0x00189334, CS, 1 */
    extern DICOM_EXPORT const tag FluoroscopyFlag;
    /** FocalDistance, 0x00181182, IS, 1 */
    extern DICOM_EXPORT const tag FocalDistance;
    /** FocalSpots, 0x00181190, DS, 1 */
    extern DICOM_EXPORT const tag FocalSpots;
    /** FocusDepth, 0x00185012, DS, 1 */
    extern DICOM_EXPORT const tag FocusDepth;
    /** FocusMethod, 0x00480011, CS, 1 */
    extern DICOM_EXPORT const tag FocusMethod;
    /** FontName, 0x00700227, LO, 1 */
    extern DICOM_EXPORT const tag FontName;
    /** FontNameType, 0x00700228, CS, 1 */
    extern DICOM_EXPORT const tag FontNameType;
    /** FovealPointNormativeDataFlag, 0x00240117, CS, 1 */
    extern DICOM_EXPORT const tag FovealPointNormativeDataFlag;
    /** FovealPointProbabilityValue, 0x00240118, FL, 1 */
    extern DICOM_EXPORT const tag FovealPointProbabilityValue;
    /** FovealSensitivity, 0x00240087, FL, 1 */
    extern DICOM_EXPORT const tag FovealSensitivity;
    /** FovealSensitivityMeasured, 0x00240086, CS, 1 */
    extern DICOM_EXPORT const tag FovealSensitivityMeasured;
    /** FractionalChannelDisplayScale, 0x003A0247, FL, 1 */
    extern DICOM_EXPORT const tag FractionalChannelDisplayScale;
    /** FractionGroupDescription, 0x300A0072, LO, 1 */
    extern DICOM_EXPORT const tag FractionGroupDescription;
    /** FractionGroupNumber, 0x300A0071, IS, 1 */
    extern DICOM_EXPORT const tag FractionGroupNumber;
    /** FractionGroupSequence, 0x300A0070, SQ, 1 */
    extern DICOM_EXPORT const tag FractionGroupSequence;
    /** FractionGroupSummarySequence, 0x30080220, SQ, 1 */
    extern DICOM_EXPORT const tag FractionGroupSummarySequence;
    /** FractionGroupType, 0x30080224, CS, 1 */
    extern DICOM_EXPORT const tag FractionGroupType;
    /** FractionNumber, 0x30020029, IS, 1 */
    extern DICOM_EXPORT const tag FractionNumber;
    /** FractionPattern, 0x300A007B, LT, 1 */
    extern DICOM_EXPORT const tag FractionPattern;
    /** FractionStatusSummarySequence, 0x30080240, SQ, 1 */
    extern DICOM_EXPORT const tag FractionStatusSummarySequence;
    /** FrameAcquisitionDateTime, 0x00189074, DT, 1 */
    extern DICOM_EXPORT const tag FrameAcquisitionDateTime;
    /** FrameAcquisitionDuration, 0x00189220, FD, 1 */
    extern DICOM_EXPORT const tag FrameAcquisitionDuration;
    /** FrameAcquisitionNumber, 0x00209156, US, 1 */
    extern DICOM_EXPORT const tag FrameAcquisitionNumber;
    /** FrameAcquisitionSequence, 0x00189417, SQ, 1 */
    extern DICOM_EXPORT const tag FrameAcquisitionSequence;
    /** FrameAnatomySequence, 0x00209071, SQ, 1 */
    extern DICOM_EXPORT const tag FrameAnatomySequence;
    /** FrameComments, 0x00209158, LT, 1 */
    extern DICOM_EXPORT const tag FrameComments;
    /** FrameContentSequence, 0x00209111, SQ, 1 */
    extern DICOM_EXPORT const tag FrameContentSequence;
    /** FrameDelay, 0x00181066, DS, 1 */
    extern DICOM_EXPORT const tag FrameDelay;
    /** FrameDetectorParametersSequence, 0x00189451, SQ, 1 */
    extern DICOM_EXPORT const tag FrameDetectorParametersSequence;
    /** FrameDimensionPointer, 0x0028000A, AT, 1 */
    extern DICOM_EXPORT const tag FrameDimensionPointer;
    /** FrameDisplaySequence, 0x00089458, SQ, 1 */
    extern DICOM_EXPORT const tag FrameDisplaySequence;
    /** FrameDisplayShutterSequence, 0x00189472, SQ, 1 */
    extern DICOM_EXPORT const tag FrameDisplayShutterSequence;
    /** FrameExtractionSequence, 0x00081164, SQ, 1 */
    extern DICOM_EXPORT const tag FrameExtractionSequence;
    /** FrameIncrementPointer, 0x00280009, AT, 1 */
    extern DICOM_EXPORT const tag FrameIncrementPointer;
    /** FrameLabel, 0x00209453, LO, 1 */
    extern DICOM_EXPORT const tag FrameLabel;
    /** FrameLabelVector, 0x00182002, SH, 1 */
    extern DICOM_EXPORT const tag FrameLabelVector;
    /** FrameLaterality, 0x00209072, CS, 1 */
    extern DICOM_EXPORT const tag FrameLaterality;
    /** FrameNumbersOfInterest, 0x00286020, US, 1 */
    extern DICOM_EXPORT const tag FrameNumbersOfInterest;
    /** FrameOfInterestDescription, 0x00286022, LO, 1 */
    extern DICOM_EXPORT const tag FrameOfInterestDescription;
    /** FrameOfInterestType, 0x00286023, CS, 1 */
    extern DICOM_EXPORT const tag FrameOfInterestType;
    /** FrameOfReferenceRelationshipSequence, 0x300600C0, SQ, 1, RET */
    extern DICOM_EXPORT const tag FrameOfReferenceRelationshipSequence;
    /** FrameOfReferenceToDisplayedCoordinateSystemTransformationMatrix, 0x0070030B, FD, 16 */
    extern DICOM_EXPORT const tag FrameOfReferenceToDisplayedCoordinateSystemTransformationMatrix;
    /** FrameOfReferenceTransformationComment, 0x300600C8, LO, 1 */
    extern DICOM_EXPORT const tag FrameOfReferenceTransformationComment;
    /** FrameOfReferenceTransformationMatrix, 0x300600C6, DS, 16 */
    extern DICOM_EXPORT const tag FrameOfReferenceTransformationMatrix;
    /** FrameOfReferenceTransformationMatrixType, 0x0070030C, CS, 1 */
    extern DICOM_EXPORT const tag FrameOfReferenceTransformationMatrixType;
    /** FrameOfReferenceTransformationType, 0x300600C4, CS, 1, RET */
    extern DICOM_EXPORT const tag FrameOfReferenceTransformationType;
    /** FrameOfReferenceUID, 0x00200052, UI, 1 */
    extern DICOM_EXPORT const tag FrameOfReferenceUID;
    /** FramePixelDataPropertiesSequence, 0x00289443, SQ, 1 */
    extern DICOM_EXPORT const tag FramePixelDataPropertiesSequence;
    /** FramePixelShiftSequence, 0x00289415, SQ, 1 */
    extern DICOM_EXPORT const tag FramePixelShiftSequence;
    /** FramePrimaryAngleVector, 0x00182003, DS, 1 */
    extern DICOM_EXPORT const tag FramePrimaryAngleVector;
    /** FrameReferenceDateTime, 0x00189151, DT, 1 */
    extern DICOM_EXPORT const tag FrameReferenceDateTime;
    /** FrameReferenceTime, 0x00541300, DS, 1 */
    extern DICOM_EXPORT const tag FrameReferenceTime;
    /** FrameSecondaryAngleVector, 0x00182004, DS, 1 */
    extern DICOM_EXPORT const tag FrameSecondaryAngleVector;
    /** FrameTime, 0x00181063, DS, 1 */
    extern DICOM_EXPORT const tag FrameTime;
    /** FrameTimeVector, 0x00181065, DS, 1 */
    extern DICOM_EXPORT const tag FrameTimeVector;
    /** FrameType, 0x00089007, CS, 4 */
    extern DICOM_EXPORT const tag FrameType;
    /** FrameVOILUTSequence, 0x00289132, SQ, 1 */
    extern DICOM_EXPORT const tag FrameVOILUTSequence;
    /** FrequencyCorrection, 0x00189101, CS, 1 */
    extern DICOM_EXPORT const tag FrequencyCorrection;
    /** FunctionalGroupPointer, 0x00209167, AT, 1 */
    extern DICOM_EXPORT const tag FunctionalGroupPointer;
    /** FunctionalGroupPrivateCreator, 0x00209238, LO, 1 */
    extern DICOM_EXPORT const tag FunctionalGroupPrivateCreator;
    /** FunctionalMRSequence, 0x00189621, SQ, 1 */
    extern DICOM_EXPORT const tag FunctionalMRSequence;
    /** FunctionalSettlingPhaseFramesPresent, 0x00189622, CS, 1 */
    extern DICOM_EXPORT const tag FunctionalSettlingPhaseFramesPresent;
    /** FunctionalSyncPulse, 0x00189623, DT, 1 */
    extern DICOM_EXPORT const tag FunctionalSyncPulse;
    /** GainCorrectionReferenceSequence, 0x00143060, SQ, 1, RET */
    extern DICOM_EXPORT const tag GainCorrectionReferenceSequence;
    /** GammaValue, 0x0028701A, FL, 1 */
    extern DICOM_EXPORT const tag GammaValue;
    /** GantryAngle, 0x300A011E, DS, 1 */
    extern DICOM_EXPORT const tag GantryAngle;
    /** GantryAngleTolerance, 0x300A0044, DS, 1 */
    extern DICOM_EXPORT const tag GantryAngleTolerance;
    /** GantryDetectorSlew, 0x00181121, DS, 1 */
    extern DICOM_EXPORT const tag GantryDetectorSlew;
    /** GantryDetectorTilt, 0x00181120, DS, 1 */
    extern DICOM_EXPORT const tag GantryDetectorTilt;
    /** GantryID, 0x00181008, LO, 1 */
    extern DICOM_EXPORT const tag GantryID;
    /** GantryMotionCorrected, 0x00189762, CS, 1 */
    extern DICOM_EXPORT const tag GantryMotionCorrected;
    /** GantryPitchAngle, 0x300A014A, FL, 1 */
    extern DICOM_EXPORT const tag GantryPitchAngle;
    /** GantryPitchAngleTolerance, 0x300A014E, FL, 1 */
    extern DICOM_EXPORT const tag GantryPitchAngleTolerance;
    /** GantryPitchRotationDirection, 0x300A014C, CS, 1 */
    extern DICOM_EXPORT const tag GantryPitchRotationDirection;
    /** GantryRotationDirection, 0x300A011F, CS, 1 */
    extern DICOM_EXPORT const tag GantryRotationDirection;
    /** GantryType, 0x40101008, CS, 1, RET */
    extern DICOM_EXPORT const tag GantryType;
    /** GapLength, 0x00700261, FL, 1 */
    extern DICOM_EXPORT const tag GapLength;
    /** GatedInformationSequence, 0x00540062, SQ, 1 */
    extern DICOM_EXPORT const tag GatedInformationSequence;
    /** GateSettingsSequence, 0x00144060, SQ, 1, RET */
    extern DICOM_EXPORT const tag GateSettingsSequence;
    /** GateThreshold, 0x00144062, DS, 1, RET */
    extern DICOM_EXPORT const tag GateThreshold;
    /** GeneralAccessoryDescription, 0x300A0422, ST, 1 */
    extern DICOM_EXPORT const tag GeneralAccessoryDescription;
    /** GeneralAccessoryID, 0x300A0421, SH, 1 */
    extern DICOM_EXPORT const tag GeneralAccessoryID;
    /** GeneralAccessoryNumber, 0x300A0424, IS, 1 */
    extern DICOM_EXPORT const tag GeneralAccessoryNumber;
    /** GeneralAccessorySequence, 0x300A0420, SQ, 1 */
    extern DICOM_EXPORT const tag GeneralAccessorySequence;
    /** GeneralAccessoryType, 0x300A0423, CS, 1 */
    extern DICOM_EXPORT const tag GeneralAccessoryType;
    /** GeneralizedDefectCorrectedSensitivityDeviationFlag, 0x00240102, CS, 1 */
    extern DICOM_EXPORT const tag GeneralizedDefectCorrectedSensitivityDeviationFlag;
    /** GeneralizedDefectCorrectedSensitivityDeviationProbabilityValue, 0x00240104, FL, 1 */
    extern DICOM_EXPORT const tag GeneralizedDefectCorrectedSensitivityDeviationProbabilityValue;
    /** GeneralizedDefectCorrectedSensitivityDeviationValue, 0x00240103, FL, 1 */
    extern DICOM_EXPORT const tag GeneralizedDefectCorrectedSensitivityDeviationValue;
    /** GeneralizedDefectSensitivityDeviationAlgorithmSequence, 0x00240067, SQ, 1 */
    extern DICOM_EXPORT const tag GeneralizedDefectSensitivityDeviationAlgorithmSequence;
    /** GeneralMachineVerificationSequence, 0x00741042, SQ, 1 */
    extern DICOM_EXPORT const tag GeneralMachineVerificationSequence;
    /** GeneralPurposePerformedProcedureStepStatus, 0x00404002, CS, 1, RET */
    extern DICOM_EXPORT const tag GeneralPurposePerformedProcedureStepStatus;
    /** GeneralPurposeScheduledProcedureStepPriority, 0x00404003, CS, 1, RET */
    extern DICOM_EXPORT const tag GeneralPurposeScheduledProcedureStepPriority;
    /** GeneralPurposeScheduledProcedureStepStatus, 0x00404001, CS, 1, RET */
    extern DICOM_EXPORT const tag GeneralPurposeScheduledProcedureStepStatus;
    /** GeneratorID, 0x00181005, LO, 1 */
    extern DICOM_EXPORT const tag GeneratorID;
    /** GeneratorPower, 0x00181170, IS, 1 */
    extern DICOM_EXPORT const tag GeneratorPower;
    /** GeneticModificationsCodeSequence, 0x00100229, SQ, 1 */
    extern DICOM_EXPORT const tag GeneticModificationsCodeSequence;
    /** GeneticModificationsDescription, 0x00100222, UC, 1 */
    extern DICOM_EXPORT const tag GeneticModificationsDescription;
    /** GeneticModificationsNomenclature, 0x00100223, LO, 1 */
    extern DICOM_EXPORT const tag GeneticModificationsNomenclature;
    /** GeneticModificationsSequence, 0x00100221, SQ, 1 */
    extern DICOM_EXPORT const tag GeneticModificationsSequence;
    /** GeometricalProperties, 0x00289444, CS, 1 */
    extern DICOM_EXPORT const tag GeometricalProperties;
    /** GeometricMaximumDistortion, 0x00289445, FL, 1 */
    extern DICOM_EXPORT const tag GeometricMaximumDistortion;
    /** GeometryForDisplay, 0x00701B08, CS, 1 */
    extern DICOM_EXPORT const tag GeometryForDisplay;
    /** GeometryOfKSpaceTraversal, 0x00189032, CS, 1 */
    extern DICOM_EXPORT const tag GeometryOfKSpaceTraversal;
    /** GlobalCrop, 0x0070120B, CS, 1 */
    extern DICOM_EXPORT const tag GlobalCrop;
    /** GlobalCroppingSpecificationIndex, 0x0070120C, US, 1 */
    extern DICOM_EXPORT const tag GlobalCroppingSpecificationIndex;
    /** GlobalDeviationFromNormal, 0x00240066, FL, 1 */
    extern DICOM_EXPORT const tag GlobalDeviationFromNormal;
    /** GlobalDeviationProbability, 0x00240071, FL, 1 */
    extern DICOM_EXPORT const tag GlobalDeviationProbability;
    /** GlobalDeviationProbabilityNormalsFlag, 0x00240059, CS, 1 */
    extern DICOM_EXPORT const tag GlobalDeviationProbabilityNormalsFlag;
    /** GlobalDeviationProbabilitySequence, 0x00240083, SQ, 1 */
    extern DICOM_EXPORT const tag GlobalDeviationProbabilitySequence;
    /** GradientEchoTrainLength, 0x00189241, US, 1 */
    extern DICOM_EXPORT const tag GradientEchoTrainLength;
    /** GradientOutput, 0x00189182, FD, 1 */
    extern DICOM_EXPORT const tag GradientOutput;
    /** GradientOutputType, 0x00189180, CS, 1 */
    extern DICOM_EXPORT const tag GradientOutputType;
    /** GraphicAnnotationSequence, 0x00700001, SQ, 1 */
    extern DICOM_EXPORT const tag GraphicAnnotationSequence;
    /** GraphicAnnotationUnits, 0x00700005, CS, 1 */
    extern DICOM_EXPORT const tag GraphicAnnotationUnits;
    /** GraphicCoordinatesDataSequence, 0x00700318, SQ, 1 */
    extern DICOM_EXPORT const tag GraphicCoordinatesDataSequence;
    /** GraphicData, 0x00700022, FL, 2 */
    extern DICOM_EXPORT const tag GraphicData;
    /** GraphicDimensions, 0x00700020, US, 1 */
    extern DICOM_EXPORT const tag GraphicDimensions;
    /** GraphicFilled, 0x00700024, CS, 1 */
    extern DICOM_EXPORT const tag GraphicFilled;
    /** GraphicGroupDescription, 0x00700208, ST, 1 */
    extern DICOM_EXPORT const tag GraphicGroupDescription;
    /** GraphicGroupID, 0x00700295, UL, 1 */
    extern DICOM_EXPORT const tag GraphicGroupID;
    /** GraphicGroupLabel, 0x00700207, LO, 1 */
    extern DICOM_EXPORT const tag GraphicGroupLabel;
    /** GraphicGroupSequence, 0x00700234, SQ, 1 */
    extern DICOM_EXPORT const tag GraphicGroupSequence;
    /** GraphicLayer, 0x00700002, CS, 1 */
    extern DICOM_EXPORT const tag GraphicLayer;
    /** GraphicLayerDescription, 0x00700068, LO, 1 */
    extern DICOM_EXPORT const tag GraphicLayerDescription;
    /** GraphicLayerOrder, 0x00700062, IS, 1 */
    extern DICOM_EXPORT const tag GraphicLayerOrder;
    /** GraphicLayerRecommendedDisplayCIELabValue, 0x00700401, US, 3 */
    extern DICOM_EXPORT const tag GraphicLayerRecommendedDisplayCIELabValue;
    /** GraphicLayerRecommendedDisplayGrayscaleValue, 0x00700066, US, 1 */
    extern DICOM_EXPORT const tag GraphicLayerRecommendedDisplayGrayscaleValue;
    /** GraphicLayerRecommendedDisplayRGBValue, 0x00700067, US, 3, RET */
    extern DICOM_EXPORT const tag GraphicLayerRecommendedDisplayRGBValue;
    /** GraphicLayerSequence, 0x00700060, SQ, 1 */
    extern DICOM_EXPORT const tag GraphicLayerSequence;
    /** GraphicObjectSequence, 0x00700009, SQ, 1 */
    extern DICOM_EXPORT const tag GraphicObjectSequence;
    /** GraphicType, 0x00700023, CS, 1 */
    extern DICOM_EXPORT const tag GraphicType;
    /** GrayLookupTableData, 0x00281200, US or SS or OW, 1, RET */
    extern DICOM_EXPORT const tag GrayLookupTableData;
    /** GrayLookupTableDescriptor, 0x00281100, US or SS, 3, RET */
    extern DICOM_EXPORT const tag GrayLookupTableDescriptor;
    /** GrayScale, 0x00281080, CS, 1, RET */
    extern DICOM_EXPORT const tag GrayScale;
    /** GreenPaletteColorLookupTableData, 0x00281202, OW, 1 */
    extern DICOM_EXPORT const tag GreenPaletteColorLookupTableData;
    /** GreenPaletteColorLookupTableDescriptor, 0x00281102, US or SS, 3 */
    extern DICOM_EXPORT const tag GreenPaletteColorLookupTableDescriptor;
    /** Grid, 0x00181166, CS, 1 */
    extern DICOM_EXPORT const tag Grid;
    /** GridAbsorbingMaterial, 0x00187040, LT, 1 */
    extern DICOM_EXPORT const tag GridAbsorbingMaterial;
    /** GridAspectRatio, 0x00187046, IS, 2 */
    extern DICOM_EXPORT const tag GridAspectRatio;
    /** GridDimensions, 0x00640007, UL, 3 */
    extern DICOM_EXPORT const tag GridDimensions;
    /** GridFocalDistance, 0x0018704C, DS, 1 */
    extern DICOM_EXPORT const tag GridFocalDistance;
    /** GridFrameOffsetVector, 0x3004000C, DS, 2 */
    extern DICOM_EXPORT const tag GridFrameOffsetVector;
    /** GridID, 0x00181006, LO, 1 */
    extern DICOM_EXPORT const tag GridID;
    /** GridPeriod, 0x00187048, DS, 1 */
    extern DICOM_EXPORT const tag GridPeriod;
    /** GridPitch, 0x00187044, DS, 1 */
    extern DICOM_EXPORT const tag GridPitch;
    /** GridResolution, 0x00640008, FD, 3 */
    extern DICOM_EXPORT const tag GridResolution;
    /** GridSpacingMaterial, 0x00187041, LT, 1 */
    extern DICOM_EXPORT const tag GridSpacingMaterial;
    /** GridThickness, 0x00187042, DS, 1 */
    extern DICOM_EXPORT const tag GridThickness;
    /** GroupOfPatientsIdentificationSequence, 0x00100027, SQ, 1 */
    extern DICOM_EXPORT const tag GroupOfPatientsIdentificationSequence;
    /** HalfValueLayer, 0x00400314, DS, 1 */
    extern DICOM_EXPORT const tag HalfValueLayer;
    /** HangingProtocolCreationDateTime, 0x0072000A, DT, 1 */
    extern DICOM_EXPORT const tag HangingProtocolCreationDateTime;
    /** HangingProtocolCreator, 0x00720008, LO, 1 */
    extern DICOM_EXPORT const tag HangingProtocolCreator;
    /** HangingProtocolDefinitionSequence, 0x0072000C, SQ, 1 */
    extern DICOM_EXPORT const tag HangingProtocolDefinitionSequence;
    /** HangingProtocolDescription, 0x00720004, LO, 1 */
    extern DICOM_EXPORT const tag HangingProtocolDescription;
    /** HangingProtocolLevel, 0x00720006, CS, 1 */
    extern DICOM_EXPORT const tag HangingProtocolLevel;
    /** HangingProtocolName, 0x00720002, SH, 1 */
    extern DICOM_EXPORT const tag HangingProtocolName;
    /** HangingProtocolUserGroupName, 0x00720010, LO, 1 */
    extern DICOM_EXPORT const tag HangingProtocolUserGroupName;
    /** HangingProtocolUserIdentificationCodeSequence, 0x0072000E, SQ, 1 */
    extern DICOM_EXPORT const tag HangingProtocolUserIdentificationCodeSequence;
    /** HardcopyCreationDeviceID, 0x00181011, LO, 1, RET */
    extern DICOM_EXPORT const tag HardcopyCreationDeviceID;
    /** HardcopyDeviceManufacturer, 0x00181017, LO, 1, RET */
    extern DICOM_EXPORT const tag HardcopyDeviceManufacturer;
    /** HardcopyDeviceManufacturerModelName, 0x0018101B, LO, 1, RET */
    extern DICOM_EXPORT const tag HardcopyDeviceManufacturerModelName;
    /** HardcopyDeviceSoftwareVersion, 0x0018101A, LO, 1, RET */
    extern DICOM_EXPORT const tag HardcopyDeviceSoftwareVersion;
    /** HeadFixationAngle, 0x300A0148, FL, 1 */
    extern DICOM_EXPORT const tag HeadFixationAngle;
    /** HeadFixationAngleTolerance, 0x300A0152, DS, 1 */
    extern DICOM_EXPORT const tag HeadFixationAngleTolerance;
    /** HeartRate, 0x00181088, IS, 1 */
    extern DICOM_EXPORT const tag HeartRate;
    /** HighBit, 0x00280102, US, 1 */
    extern DICOM_EXPORT const tag HighBit;
    /** HighDoseTechniqueType, 0x300A00C7, CS, 1 */
    extern DICOM_EXPORT const tag HighDoseTechniqueType;
    /** HighEnergyDetectors, 0x40100002, CS, 1, RET */
    extern DICOM_EXPORT const tag HighEnergyDetectors;
    /** HighRRValue, 0x00181082, IS, 1 */
    extern DICOM_EXPORT const tag HighRRValue;
    /** HistogramBinWidth, 0x00603008, US, 1 */
    extern DICOM_EXPORT const tag HistogramBinWidth;
    /** HistogramData, 0x00603020, UL, 1 */
    extern DICOM_EXPORT const tag HistogramData;
    /** HistogramExplanation, 0x00603010, LO, 1 */
    extern DICOM_EXPORT const tag HistogramExplanation;
    /** HistogramFirstBinValue, 0x00603004, US or SS, 1 */
    extern DICOM_EXPORT const tag HistogramFirstBinValue;
    /** HistogramLastBinValue, 0x00603006, US or SS, 1 */
    extern DICOM_EXPORT const tag HistogramLastBinValue;
    /** HistogramNumberOfBins, 0x00603002, US, 1 */
    extern DICOM_EXPORT const tag HistogramNumberOfBins;
    /** HistogramSequence, 0x00603000, SQ, 1 */
    extern DICOM_EXPORT const tag HistogramSequence;
    /** HL7DocumentEffectiveTime, 0x0040E004, DT, 1 */
    extern DICOM_EXPORT const tag HL7DocumentEffectiveTime;
    /** HL7DocumentTypeCodeSequence, 0x0040E006, SQ, 1 */
    extern DICOM_EXPORT const tag HL7DocumentTypeCodeSequence;
    /** HL7InstanceIdentifier, 0x0040E001, ST, 1 */
    extern DICOM_EXPORT const tag HL7InstanceIdentifier;
    /** HL7StructuredDocumentReferenceSequence, 0x0040A390, SQ, 1 */
    extern DICOM_EXPORT const tag HL7StructuredDocumentReferenceSequence;
    /** HomeCommunityID, 0x0040E031, UI, 1 */
    extern DICOM_EXPORT const tag HomeCommunityID;
    /** HorizontalAlignment, 0x00700242, CS, 1 */
    extern DICOM_EXPORT const tag HorizontalAlignment;
    /** HorizontalFieldOfView, 0x0022000C, FL, 1 */
    extern DICOM_EXPORT const tag HorizontalFieldOfView;
    /** HorizontalOffsetOfSensor, 0x00143024, DS, 1, RET */
    extern DICOM_EXPORT const tag HorizontalOffsetOfSensor;
    /** HorizontalPrismBase, 0x00460032, CS, 1 */
    extern DICOM_EXPORT const tag HorizontalPrismBase;
    /** HorizontalPrismPower, 0x00460030, FD, 1 */
    extern DICOM_EXPORT const tag HorizontalPrismPower;
    /** HPGLContourPenNumber, 0x00686310, US, 1 */
    extern DICOM_EXPORT const tag HPGLContourPenNumber;
    /** HPGLDocument, 0x00686300, OB, 1 */
    extern DICOM_EXPORT const tag HPGLDocument;
    /** HPGLDocumentID, 0x006862D0, US, 1 */
    extern DICOM_EXPORT const tag HPGLDocumentID;
    /** HPGLDocumentLabel, 0x006862D5, LO, 1 */
    extern DICOM_EXPORT const tag HPGLDocumentLabel;
    /** HPGLDocumentScaling, 0x006862F2, FD, 1 */
    extern DICOM_EXPORT const tag HPGLDocumentScaling;
    /** HPGLDocumentSequence, 0x006862C0, SQ, 1 */
    extern DICOM_EXPORT const tag HPGLDocumentSequence;
    /** HPGLPenDescription, 0x00686345, ST, 1 */
    extern DICOM_EXPORT const tag HPGLPenDescription;
    /** HPGLPenLabel, 0x00686340, LO, 1 */
    extern DICOM_EXPORT const tag HPGLPenLabel;
    /** HPGLPenNumber, 0x00686330, US, 1 */
    extern DICOM_EXPORT const tag HPGLPenNumber;
    /** HPGLPenSequence, 0x00686320, SQ, 1 */
    extern DICOM_EXPORT const tag HPGLPenSequence;
    /** HuffmanTableSize, 0x10000002, US, 1, RET */
    extern DICOM_EXPORT const range_tag HuffmanTableSize;
    /** HuffmanTableTriplet, 0x10000003, US, 3, RET */
    extern DICOM_EXPORT const range_tag HuffmanTableTriplet;
    /** HumanPerformerCodeSequence, 0x00404009, SQ, 1 */
    extern DICOM_EXPORT const tag HumanPerformerCodeSequence;
    /** HumanPerformerName, 0x00404037, PN, 1 */
    extern DICOM_EXPORT const tag HumanPerformerName;
    /** HumanPerformerOrganization, 0x00404036, LO, 1 */
    extern DICOM_EXPORT const tag HumanPerformerOrganization;
    /** ICCProfile, 0x00282000, OB, 1 */
    extern DICOM_EXPORT const tag ICCProfile;
    /** IconImageSequence, 0x00880200, SQ, 1 */
    extern DICOM_EXPORT const tag IconImageSequence;
    /** IdenticalDocumentsSequence, 0x0040A525, SQ, 1 */
    extern DICOM_EXPORT const tag IdenticalDocumentsSequence;
    /** IdentificationDescriptionTrial, 0x0040A224, ST, 1, RET */
    extern DICOM_EXPORT const tag IdentificationDescriptionTrial;
    /** IdentifierCodeSequenceTrial, 0x0040A070, SQ, 1, RET */
    extern DICOM_EXPORT const tag IdentifierCodeSequenceTrial;
    /** IdentifierTypeCode, 0x00400035, CS, 1 */
    extern DICOM_EXPORT const tag IdentifierTypeCode;
    /** IdentifyingComments, 0x00084000, LT, 1, RET */
    extern DICOM_EXPORT const tag IdentifyingComments;
    /** IdentifyingPrivateElements, 0x00080306, US, 1 */
    extern DICOM_EXPORT const tag IdentifyingPrivateElements;
    /** Illumination, 0x2010015E, US, 1 */
    extern DICOM_EXPORT const tag Illumination;
    /** IlluminationBandwidth, 0x00220057, FL, 1 */
    extern DICOM_EXPORT const tag IlluminationBandwidth;
    /** IlluminationColorCodeSequence, 0x00480108, SQ, 1 */
    extern DICOM_EXPORT const tag IlluminationColorCodeSequence;
    /** IlluminationPower, 0x00220056, FL, 1 */
    extern DICOM_EXPORT const tag IlluminationPower;
    /** IlluminationTypeCodeSequence, 0x00220016, SQ, 1 */
    extern DICOM_EXPORT const tag IlluminationTypeCodeSequence;
    /** IlluminationWaveLength, 0x00220055, FL, 1 */
    extern DICOM_EXPORT const tag IlluminationWaveLength;
    /** IlluminatorTypeCodeSequence, 0x00480100, SQ, 1 */
    extern DICOM_EXPORT const tag IlluminatorTypeCodeSequence;
    /** ImageAndFluoroscopyAreaDoseProduct, 0x0018115E, DS, 1 */
    extern DICOM_EXPORT const tag ImageAndFluoroscopyAreaDoseProduct;
    /** ImageBoxContentSequence, 0x21300040, SQ, 1, RET */
    extern DICOM_EXPORT const tag ImageBoxContentSequence;
    /** ImageBoxesSequence, 0x00720300, SQ, 1 */
    extern DICOM_EXPORT const tag ImageBoxesSequence;
    /** ImageBoxLargeScrollAmount, 0x00720318, US, 1 */
    extern DICOM_EXPORT const tag ImageBoxLargeScrollAmount;
    /** ImageBoxLargeScrollType, 0x00720316, CS, 1 */
    extern DICOM_EXPORT const tag ImageBoxLargeScrollType;
    /** ImageBoxLayoutType, 0x00720304, CS, 1 */
    extern DICOM_EXPORT const tag ImageBoxLayoutType;
    /** ImageBoxNumber, 0x00720302, US, 1 */
    extern DICOM_EXPORT const tag ImageBoxNumber;
    /** ImageBoxOverlapPriority, 0x00720320, US, 1 */
    extern DICOM_EXPORT const tag ImageBoxOverlapPriority;
    /** ImageBoxPosition, 0x20200010, US, 1 */
    extern DICOM_EXPORT const tag ImageBoxPosition;
    /** ImageBoxPresentationLUTFlag, 0x2000006A, CS, 1, RET */
    extern DICOM_EXPORT const tag ImageBoxPresentationLUTFlag;
    /** ImageBoxScrollDirection, 0x00720310, CS, 1 */
    extern DICOM_EXPORT const tag ImageBoxScrollDirection;
    /** ImageBoxSmallScrollAmount, 0x00720314, US, 1 */
    extern DICOM_EXPORT const tag ImageBoxSmallScrollAmount;
    /** ImageBoxSmallScrollType, 0x00720312, CS, 1 */
    extern DICOM_EXPORT const tag ImageBoxSmallScrollType;
    /** ImageBoxSynchronizationSequence, 0x00720430, SQ, 1 */
    extern DICOM_EXPORT const tag ImageBoxSynchronizationSequence;
    /** ImageBoxTileHorizontalDimension, 0x00720306, US, 1 */
    extern DICOM_EXPORT const tag ImageBoxTileHorizontalDimension;
    /** ImageBoxTileVerticalDimension, 0x00720308, US, 1 */
    extern DICOM_EXPORT const tag ImageBoxTileVerticalDimension;
    /** ImageCenterPointCoordinatesSequence, 0x0040071A, SQ, 1 */
    extern DICOM_EXPORT const tag ImageCenterPointCoordinatesSequence;
    /** ImageComments, 0x00204000, LT, 1 */
    extern DICOM_EXPORT const tag ImageComments;
    /** ImageDataLocation, 0x00280808, AT, 1, RET */
    extern DICOM_EXPORT const range_tag ImageDataLocation;
    /** ImageDataTypeSequence, 0x00189807, SQ, 1 */
    extern DICOM_EXPORT const tag ImageDataTypeSequence;
    /** ImageDimensions, 0x00280005, US, 1, RET */
    extern DICOM_EXPORT const tag ImageDimensions;
    /** ImageDisplayFormat, 0x20100010, ST, 1 */
    extern DICOM_EXPORT const tag ImageDisplayFormat;
    /** ImagedNucleus, 0x00180085, SH, 1 */
    extern DICOM_EXPORT const tag ImagedNucleus;
    /** ImagedVolumeDepth, 0x00480003, FL, 1 */
    extern DICOM_EXPORT const tag ImagedVolumeDepth;
    /** ImagedVolumeHeight, 0x00480002, FL, 1 */
    extern DICOM_EXPORT const tag ImagedVolumeHeight;
    /** ImagedVolumeWidth, 0x00480001, FL, 1 */
    extern DICOM_EXPORT const tag ImagedVolumeWidth;
    /** ImageFilter, 0x00189320, SH, 1 */
    extern DICOM_EXPORT const tag ImageFilter;
    /** ImageFilterDescription, 0x00189941, UT, 1 */
    extern DICOM_EXPORT const tag ImageFilterDescription;
    /** ImageFormat, 0x00280040, CS, 1, RET */
    extern DICOM_EXPORT const tag ImageFormat;
    /** ImageFrameOrigin, 0x60000051, US, 1 */
    extern DICOM_EXPORT const range_tag ImageFrameOrigin;
    /** ImageGeometryType, 0x00200070, LO, 1, RET */
    extern DICOM_EXPORT const tag ImageGeometryType;
    /** ImageHorizontalFlip, 0x00700041, CS, 1 */
    extern DICOM_EXPORT const tag ImageHorizontalFlip;
    /** ImageID, 0x00540400, SH, 1 */
    extern DICOM_EXPORT const tag ImageID;
    /** ImageIndex, 0x00541330, US, 1 */
    extern DICOM_EXPORT const tag ImageIndex;
    /** ImageLaterality, 0x00200062, CS, 1 */
    extern DICOM_EXPORT const tag ImageLaterality;
    /** ImageLocation, 0x00280200, US, 1, RET */
    extern DICOM_EXPORT const tag ImageLocation;
    /** ImageOrientation, 0x00200035, DS, 6, RET */
    extern DICOM_EXPORT const tag ImageOrientation;
    /** ImageOrientationPatient, 0x00200037, DS, 6 */
    extern DICOM_EXPORT const tag ImageOrientationPatient;
    /** ImageOrientationSlide, 0x00480102, DS, 6 */
    extern DICOM_EXPORT const tag ImageOrientationSlide;
    /** ImageOrientationVolume, 0x00209302, FD, 6 */
    extern DICOM_EXPORT const tag ImageOrientationVolume;
    /** ImageOverlayBoxContentSequence, 0x21300060, SQ, 1, RET */
    extern DICOM_EXPORT const tag ImageOverlayBoxContentSequence;
    /** ImageOverlayFlag, 0x20000067, CS, 1, RET */
    extern DICOM_EXPORT const tag ImageOverlayFlag;
    /** ImagePathFilterPassBand, 0x00220004, US, 2 */
    extern DICOM_EXPORT const tag ImagePathFilterPassBand;
    /** ImagePathFilterPassThroughWavelength, 0x00220003, US, 1 */
    extern DICOM_EXPORT const tag ImagePathFilterPassThroughWavelength;
    /** ImagePathFilterTypeStackCodeSequence, 0x00220018, SQ, 1 */
    extern DICOM_EXPORT const tag ImagePathFilterTypeStackCodeSequence;
    /** ImagePlanePixelSpacing, 0x30020011, DS, 2 */
    extern DICOM_EXPORT const tag ImagePlanePixelSpacing;
    /** ImagePosition, 0x00200030, DS, 3, RET */
    extern DICOM_EXPORT const tag ImagePosition;
    /** ImagePositionPatient, 0x00200032, DS, 3 */
    extern DICOM_EXPORT const tag ImagePositionPatient;
    /** ImagePositionVolume, 0x00209301, FD, 3 */
    extern DICOM_EXPORT const tag ImagePositionVolume;
    /** ImagePresentationComments, 0x00284000, LT, 1, RET */
    extern DICOM_EXPORT const tag ImagePresentationComments;
    /** ImageProcessingApplied, 0x00289446, CS, 1 */
    extern DICOM_EXPORT const tag ImageProcessingApplied;
    /** ImageQualityIndicatorMaterial, 0x001440A1, LO, 1, RET */
    extern DICOM_EXPORT const tag ImageQualityIndicatorMaterial;
    /** ImageQualityIndicatorSize, 0x001440A2, LO, 1, RET */
    extern DICOM_EXPORT const tag ImageQualityIndicatorSize;
    /** ImageQualityIndicatorType, 0x001440A0, LO, 1, RET */
    extern DICOM_EXPORT const tag ImageQualityIndicatorType;
    /** ImageRotation, 0x00700042, US, 1 */
    extern DICOM_EXPORT const tag ImageRotation;
    /** ImageRotationRetired, 0x00700040, IS, 1, RET */
    extern DICOM_EXPORT const tag ImageRotationRetired;
    /** ImagerPixelSpacing, 0x00181164, DS, 2 */
    extern DICOM_EXPORT const tag ImagerPixelSpacing;
    /** ImageScaleRepresentation, 0x40101075, DS, 1, RET */
    extern DICOM_EXPORT const tag ImageScaleRepresentation;
    /** ImageSetLabel, 0x00720040, LO, 1 */
    extern DICOM_EXPORT const tag ImageSetLabel;
    /** ImageSetNumber, 0x00720032, US, 1 */
    extern DICOM_EXPORT const tag ImageSetNumber;
    /** ImageSetSelectorCategory, 0x00720034, CS, 1 */
    extern DICOM_EXPORT const tag ImageSetSelectorCategory;
    /** ImageSetSelectorSequence, 0x00720022, SQ, 1 */
    extern DICOM_EXPORT const tag ImageSetSelectorSequence;
    /** ImageSetSelectorUsageFlag, 0x00720024, CS, 1 */
    extern DICOM_EXPORT const tag ImageSetSelectorUsageFlag;
    /** ImageSetsSequence, 0x00720020, SQ, 1 */
    extern DICOM_EXPORT const tag ImageSetsSequence;
    /** ImagesInAcquisition, 0x00201002, IS, 1 */
    extern DICOM_EXPORT const tag ImagesInAcquisition;
    /** ImagesInSeries, 0x00201003, IS, 1, RET */
    extern DICOM_EXPORT const tag ImagesInSeries;
    /** ImagesInStudy, 0x00201005, IS, 1, RET */
    extern DICOM_EXPORT const tag ImagesInStudy;
    /** ImageToEquipmentMappingMatrix, 0x00289520, DS, 16 */
    extern DICOM_EXPORT const tag ImageToEquipmentMappingMatrix;
    /** ImageTransformationMatrix, 0x00185210, DS, 6, RET */
    extern DICOM_EXPORT const tag ImageTransformationMatrix;
    /** ImageTranslationVector, 0x00185212, DS, 3, RET */
    extern DICOM_EXPORT const tag ImageTranslationVector;
    /** ImageTriggerDelay, 0x00181067, DS, 1 */
    extern DICOM_EXPORT const tag ImageTriggerDelay;
    /** ImageType, 0x00080008, CS, 2 */
    extern DICOM_EXPORT const tag ImageType;
    /** ImageVolumeGeometry, 0x00701208, CS, 1 */
    extern DICOM_EXPORT const tag ImageVolumeGeometry;
    /** ImagingDeviceSpecificAcquisitionParameters, 0x300A00CC, LO, 1 */
    extern DICOM_EXPORT const tag ImagingDeviceSpecificAcquisitionParameters;
    /** ImagingFrequency, 0x00180084, DS, 1 */
    extern DICOM_EXPORT const tag ImagingFrequency;
    /** ImagingServiceRequestComments, 0x00402400, LT, 1 */
    extern DICOM_EXPORT const tag ImagingServiceRequestComments;
    /** ImplantAssemblyTemplateIssuer, 0x00760003, LO, 1 */
    extern DICOM_EXPORT const tag ImplantAssemblyTemplateIssuer;
    /** ImplantAssemblyTemplateName, 0x00760001, LO, 1 */
    extern DICOM_EXPORT const tag ImplantAssemblyTemplateName;
    /** ImplantAssemblyTemplateTargetAnatomySequence, 0x00760010, SQ, 1 */
    extern DICOM_EXPORT const tag ImplantAssemblyTemplateTargetAnatomySequence;
    /** ImplantAssemblyTemplateType, 0x0076000A, CS, 1 */
    extern DICOM_EXPORT const tag ImplantAssemblyTemplateType;
    /** ImplantAssemblyTemplateVersion, 0x00760006, LO, 1 */
    extern DICOM_EXPORT const tag ImplantAssemblyTemplateVersion;
    /** ImplantName, 0x00221095, LO, 1 */
    extern DICOM_EXPORT const tag ImplantName;
    /** ImplantPartNumber, 0x00221097, LO, 1 */
    extern DICOM_EXPORT const tag ImplantPartNumber;
    /** ImplantRegulatoryDisapprovalCodeSequence, 0x006862A0, SQ, 1 */
    extern DICOM_EXPORT const tag ImplantRegulatoryDisapprovalCodeSequence;
    /** ImplantSize, 0x00686210, LO, 1 */
    extern DICOM_EXPORT const tag ImplantSize;
    /** ImplantTargetAnatomySequence, 0x00686230, SQ, 1 */
    extern DICOM_EXPORT const tag ImplantTargetAnatomySequence;
    /** ImplantTemplate3DModelSurfaceNumber, 0x00686350, US, 1 */
    extern DICOM_EXPORT const tag ImplantTemplate3DModelSurfaceNumber;
    /** ImplantTemplateGroupDescription, 0x00780010, ST, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupDescription;
    /** ImplantTemplateGroupIssuer, 0x00780020, LO, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupIssuer;
    /** ImplantTemplateGroupMemberID, 0x0078002E, US, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupMemberID;
    /** ImplantTemplateGroupMemberMatching2DCoordinatesSequence, 0x00780070, SQ, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupMemberMatching2DCoordinatesSequence;
    /** ImplantTemplateGroupMembersSequence, 0x0078002A, SQ, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupMembersSequence;
    /** ImplantTemplateGroupName, 0x00780001, LO, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupName;
    /** ImplantTemplateGroupTargetAnatomySequence, 0x00780028, SQ, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupTargetAnatomySequence;
    /** ImplantTemplateGroupVariationDimensionName, 0x007800B2, LO, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupVariationDimensionName;
    /** ImplantTemplateGroupVariationDimensionRank, 0x007800B8, US, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupVariationDimensionRank;
    /** ImplantTemplateGroupVariationDimensionRankSequence, 0x007800B4, SQ, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupVariationDimensionRankSequence;
    /** ImplantTemplateGroupVariationDimensionSequence, 0x007800B0, SQ, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupVariationDimensionSequence;
    /** ImplantTemplateGroupVersion, 0x00780024, LO, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateGroupVersion;
    /** ImplantTemplateVersion, 0x00686221, LO, 1 */
    extern DICOM_EXPORT const tag ImplantTemplateVersion;
    /** ImplantType, 0x00686223, CS, 1 */
    extern DICOM_EXPORT const tag ImplantType;
    /** ImplantTypeCodeSequence, 0x006863A8, SQ, 1 */
    extern DICOM_EXPORT const tag ImplantTypeCodeSequence;
    /** ImplementationClassUID, 0x00020012, UI, 1 */
    extern DICOM_EXPORT const tag ImplementationClassUID;
    /** ImplementationVersionName, 0x00020013, SH, 1 */
    extern DICOM_EXPORT const tag ImplementationVersionName;
    /** Impressions, 0x40080300, ST, 1, RET */
    extern DICOM_EXPORT const tag Impressions;
    /** InboundArrivalType, 0x40101056, CS, 1, RET */
    extern DICOM_EXPORT const tag InboundArrivalType;
    /** IncidentAngle, 0x00144052, DS, 1, RET */
    extern DICOM_EXPORT const tag IncidentAngle;
    /** IncludeDisplayApplication, 0x22000009, CS, 1 */
    extern DICOM_EXPORT const tag IncludeDisplayApplication;
    /** IncludeNonDICOMObjects, 0x22000008, CS, 1 */
    extern DICOM_EXPORT const tag IncludeNonDICOMObjects;
    /** InConcatenationNumber, 0x00209162, US, 1 */
    extern DICOM_EXPORT const tag InConcatenationNumber;
    /** InConcatenationTotalNumber, 0x00209163, US, 1 */
    extern DICOM_EXPORT const tag InConcatenationTotalNumber;
    /** IndexNormalsFlag, 0x00240338, CS, 1 */
    extern DICOM_EXPORT const tag IndexNormalsFlag;
    /** IndexProbability, 0x00240341, FL, 1 */
    extern DICOM_EXPORT const tag IndexProbability;
    /** IndexProbabilitySequence, 0x00240344, SQ, 1 */
    extern DICOM_EXPORT const tag IndexProbabilitySequence;
    /** IndicationDescription, 0x00142018, ST, 1, RET */
    extern DICOM_EXPORT const tag IndicationDescription;
    /** IndicationDisposition, 0x0014201C, CS, 1, RET */
    extern DICOM_EXPORT const tag IndicationDisposition;
    /** IndicationLabel, 0x00142016, SH, 1, RET */
    extern DICOM_EXPORT const tag IndicationLabel;
    /** IndicationNumber, 0x00142014, IS, 1, RET */
    extern DICOM_EXPORT const tag IndicationNumber;
    /** IndicationPhysicalPropertySequence, 0x00142030, SQ, 1, RET */
    extern DICOM_EXPORT const tag IndicationPhysicalPropertySequence;
    /** IndicationROISequence, 0x0014201E, SQ, 1, RET */
    extern DICOM_EXPORT const tag IndicationROISequence;
    /** IndicationSequence, 0x00142012, SQ, 1, RET */
    extern DICOM_EXPORT const tag IndicationSequence;
    /** IndicationType, 0x0014201A, CS, 1, RET */
    extern DICOM_EXPORT const tag IndicationType;
    /** InformationFromManufacturerSequence, 0x00686260, SQ, 1 */
    extern DICOM_EXPORT const tag InformationFromManufacturerSequence;
    /** InformationIssueDateTime, 0x00686270, DT, 1 */
    extern DICOM_EXPORT const tag InformationIssueDateTime;
    /** InformationSummary, 0x00686280, ST, 1 */
    extern DICOM_EXPORT const tag InformationSummary;
    /** InitialCineRunState, 0x00180042, CS, 1 */
    extern DICOM_EXPORT const tag InitialCineRunState;
    /** InnerDiameter, 0x00140056, DS, 1, RET */
    extern DICOM_EXPORT const tag InnerDiameter;
    /** InPlanePhaseEncodingDirection, 0x00181312, CS, 1 */
    extern DICOM_EXPORT const tag InPlanePhaseEncodingDirection;
    /** InputAvailabilityFlag, 0x00404020, CS, 1, RET */
    extern DICOM_EXPORT const tag InputAvailabilityFlag;
    /** InputInformationSequence, 0x00404021, SQ, 1 */
    extern DICOM_EXPORT const tag InputInformationSequence;
    /** InputReadinessState, 0x00404041, CS, 1 */
    extern DICOM_EXPORT const tag InputReadinessState;
    /** InputSequencePositionIndex, 0x00701203, US, 1 */
    extern DICOM_EXPORT const tag InputSequencePositionIndex;
    /** InspectionSelectionCriteria, 0x4010107C, CS, 1, RET */
    extern DICOM_EXPORT const tag InspectionSelectionCriteria;
    /** InStackPositionNumber, 0x00209057, UL, 1 */
    extern DICOM_EXPORT const tag InStackPositionNumber;
    /** InstanceAvailability, 0x00080056, CS, 1 */
    extern DICOM_EXPORT const tag InstanceAvailability;
    /** InstanceCoercionDateTime, 0x00080015, DT, 1 */
    extern DICOM_EXPORT const tag InstanceCoercionDateTime;
    /** InstanceCreationDate, 0x00080012, DA, 1 */
    extern DICOM_EXPORT const tag InstanceCreationDate;
    /** InstanceCreationTime, 0x00080013, TM, 1 */
    extern DICOM_EXPORT const tag InstanceCreationTime;
    /** InstanceCreatorUID, 0x00080014, UI, 1 */
    extern DICOM_EXPORT const tag InstanceCreatorUID;
    /** InstanceNumber, 0x00200013, IS, 1 */
    extern DICOM_EXPORT const tag InstanceNumber;
    /** InstitutionAddress, 0x00080081, ST, 1 */
    extern DICOM_EXPORT const tag InstitutionAddress;
    /** InstitutionalDepartmentName, 0x00081040, LO, 1 */
    extern DICOM_EXPORT const tag InstitutionalDepartmentName;
    /** InstitutionCodeSequence, 0x00080082, SQ, 1 */
    extern DICOM_EXPORT const tag InstitutionCodeSequence;
    /** InstitutionName, 0x00080080, LO, 1 */
    extern DICOM_EXPORT const tag InstitutionName;
    /** InstructionDescription, 0x00189917, UT, 1 */
    extern DICOM_EXPORT const tag InstructionDescription;
    /** InstructionIndex, 0x00189915, US, 1 */
    extern DICOM_EXPORT const tag InstructionIndex;
    /** InstructionPerformanceComment, 0x0018991A, UT, 1 */
    extern DICOM_EXPORT const tag InstructionPerformanceComment;
    /** InstructionPerformedDateTime, 0x00189919, DT, 1 */
    extern DICOM_EXPORT const tag InstructionPerformedDateTime;
    /** InstructionPerformedFlag, 0x00189918, CS, 1 */
    extern DICOM_EXPORT const tag InstructionPerformedFlag;
    /** InstructionSequence, 0x00189914, SQ, 1 */
    extern DICOM_EXPORT const tag InstructionSequence;
    /** InstructionText, 0x00189916, LO, 1 */
    extern DICOM_EXPORT const tag InstructionText;
    /** InsurancePlanIdentification, 0x00101050, LO, 1, RET */
    extern DICOM_EXPORT const tag InsurancePlanIdentification;
    /** IntendedRecipientsOfResultsIdentificationSequence, 0x00401011, SQ, 1 */
    extern DICOM_EXPORT const tag IntendedRecipientsOfResultsIdentificationSequence;
    /** IntensifierActiveDimensions, 0x00189428, FL, 1 */
    extern DICOM_EXPORT const tag IntensifierActiveDimensions;
    /** IntensifierActiveShape, 0x00189427, CS, 1 */
    extern DICOM_EXPORT const tag IntensifierActiveShape;
    /** IntensifierSize, 0x00181162, DS, 1 */
    extern DICOM_EXPORT const tag IntensifierSize;
    /** InterMarkerDistance, 0x00500019, DS, 1 */
    extern DICOM_EXPORT const tag InterMarkerDistance;
    /** IntermediatePupillaryDistance, 0x00460063, FD, 1 */
    extern DICOM_EXPORT const tag IntermediatePupillaryDistance;
    /** InternalDetectorFrameTime, 0x00143011, DS, 1, RET */
    extern DICOM_EXPORT const tag InternalDetectorFrameTime;
    /** InternationalRouteSegment, 0x40101028, CS, 1, RET */
    extern DICOM_EXPORT const tag InternationalRouteSegment;
    /** InterpolationType, 0x00520039, CS, 1 */
    extern DICOM_EXPORT const tag InterpolationType;
    /** InterpretationApprovalDate, 0x40080112, DA, 1, RET */
    extern DICOM_EXPORT const tag InterpretationApprovalDate;
    /** InterpretationApprovalTime, 0x40080113, TM, 1, RET */
    extern DICOM_EXPORT const tag InterpretationApprovalTime;
    /** InterpretationApproverSequence, 0x40080111, SQ, 1, RET */
    extern DICOM_EXPORT const tag InterpretationApproverSequence;
    /** InterpretationAuthor, 0x4008010C, PN, 1, RET */
    extern DICOM_EXPORT const tag InterpretationAuthor;
    /** InterpretationDiagnosisCodeSequence, 0x40080117, SQ, 1, RET */
    extern DICOM_EXPORT const tag InterpretationDiagnosisCodeSequence;
    /** InterpretationDiagnosisDescription, 0x40080115, LT, 1, RET */
    extern DICOM_EXPORT const tag InterpretationDiagnosisDescription;
    /** InterpretationID, 0x40080200, SH, 1, RET */
    extern DICOM_EXPORT const tag InterpretationID;
    /** InterpretationIDIssuer, 0x40080202, LO, 1, RET */
    extern DICOM_EXPORT const tag InterpretationIDIssuer;
    /** InterpretationRecordedDate, 0x40080100, DA, 1, RET */
    extern DICOM_EXPORT const tag InterpretationRecordedDate;
    /** InterpretationRecordedTime, 0x40080101, TM, 1, RET */
    extern DICOM_EXPORT const tag InterpretationRecordedTime;
    /** InterpretationRecorder, 0x40080102, PN, 1, RET */
    extern DICOM_EXPORT const tag InterpretationRecorder;
    /** InterpretationStatusID, 0x40080212, CS, 1, RET */
    extern DICOM_EXPORT const tag InterpretationStatusID;
    /** InterpretationText, 0x4008010B, ST, 1, RET */
    extern DICOM_EXPORT const tag InterpretationText;
    /** InterpretationTranscriber, 0x4008010A, PN, 1, RET */
    extern DICOM_EXPORT const tag InterpretationTranscriber;
    /** InterpretationTranscriptionDate, 0x40080108, DA, 1, RET */
    extern DICOM_EXPORT const tag InterpretationTranscriptionDate;
    /** InterpretationTranscriptionTime, 0x40080109, TM, 1, RET */
    extern DICOM_EXPORT const tag InterpretationTranscriptionTime;
    /** InterpretationTypeID, 0x40080210, CS, 1, RET */
    extern DICOM_EXPORT const tag InterpretationTypeID;
    /** IntervalNumber, 0x00200016, IS, 1, RET */
    extern DICOM_EXPORT const tag IntervalNumber;
    /** IntervalsAcquired, 0x00181083, IS, 1 */
    extern DICOM_EXPORT const tag IntervalsAcquired;
    /** IntervalsRejected, 0x00181084, IS, 1 */
    extern DICOM_EXPORT const tag IntervalsRejected;
    /** InterventionDescription, 0x0018003A, ST, 1 */
    extern DICOM_EXPORT const tag InterventionDescription;
    /** InterventionDrugCodeSequence, 0x00180029, SQ, 1 */
    extern DICOM_EXPORT const tag InterventionDrugCodeSequence;
    /** InterventionDrugDose, 0x00180028, DS, 1 */
    extern DICOM_EXPORT const tag InterventionDrugDose;
    /** InterventionDrugInformationSequence, 0x00180026, SQ, 1 */
    extern DICOM_EXPORT const tag InterventionDrugInformationSequence;
    /** InterventionDrugName, 0x00180034, LO, 1 */
    extern DICOM_EXPORT const tag InterventionDrugName;
    /** InterventionDrugStartTime, 0x00180035, TM, 1 */
    extern DICOM_EXPORT const tag InterventionDrugStartTime;
    /** InterventionDrugStopTime, 0x00180027, TM, 1 */
    extern DICOM_EXPORT const tag InterventionDrugStopTime;
    /** InterventionSequence, 0x00180036, SQ, 1 */
    extern DICOM_EXPORT const tag InterventionSequence;
    /** InterventionStatus, 0x00180038, CS, 1 */
    extern DICOM_EXPORT const tag InterventionStatus;
    /** IntraocularLensCalculationsLeftEyeSequence, 0x00221310, SQ, 1 */
    extern DICOM_EXPORT const tag IntraocularLensCalculationsLeftEyeSequence;
    /** IntraocularLensCalculationsRightEyeSequence, 0x00221300, SQ, 1 */
    extern DICOM_EXPORT const tag IntraocularLensCalculationsRightEyeSequence;
    /** IntraOcularPressure, 0x0022000B, FL, 1 */
    extern DICOM_EXPORT const tag IntraOcularPressure;
    /** IntravascularFrameContentSequence, 0x00520027, SQ, 1 */
    extern DICOM_EXPORT const tag IntravascularFrameContentSequence;
    /** IntravascularLongitudinalDistance, 0x00520028, FD, 1 */
    extern DICOM_EXPORT const tag IntravascularLongitudinalDistance;
    /** IntravascularOCTFrameContentSequence, 0x00520029, SQ, 1 */
    extern DICOM_EXPORT const tag IntravascularOCTFrameContentSequence;
    /** IntravascularOCTFrameTypeSequence, 0x00520025, SQ, 1 */
    extern DICOM_EXPORT const tag IntravascularOCTFrameTypeSequence;
    /** InversionRecovery, 0x00189009, CS, 1 */
    extern DICOM_EXPORT const tag InversionRecovery;
    /** InversionTime, 0x00180082, DS, 1 */
    extern DICOM_EXPORT const tag InversionTime;
    /** InversionTimes, 0x00189079, FD, 1 */
    extern DICOM_EXPORT const tag InversionTimes;
    /** IOLFormulaCodeSequence, 0x00221028, SQ, 1 */
    extern DICOM_EXPORT const tag IOLFormulaCodeSequence;
    /** IOLFormulaDetail, 0x00221029, LO, 1 */
    extern DICOM_EXPORT const tag IOLFormulaDetail;
    /** IOLManufacturer, 0x00221093, LO, 1 */
    extern DICOM_EXPORT const tag IOLManufacturer;
    /** IOLPower, 0x00221053, FL, 1 */
    extern DICOM_EXPORT const tag IOLPower;
    /** IOLPowerForExactEmmetropia, 0x00221121, FL, 1 */
    extern DICOM_EXPORT const tag IOLPowerForExactEmmetropia;
    /** IOLPowerForExactTargetRefraction, 0x00221122, FL, 1 */
    extern DICOM_EXPORT const tag IOLPowerForExactTargetRefraction;
    /** IOLPowerSequence, 0x00221090, SQ, 1 */
    extern DICOM_EXPORT const tag IOLPowerSequence;
    /** IonBeamLimitingDeviceSequence, 0x300A03A4, SQ, 1 */
    extern DICOM_EXPORT const tag IonBeamLimitingDeviceSequence;
    /** IonBeamSequence, 0x300A03A2, SQ, 1 */
    extern DICOM_EXPORT const tag IonBeamSequence;
    /** IonBlockSequence, 0x300A03A6, SQ, 1 */
    extern DICOM_EXPORT const tag IonBlockSequence;
    /** IonControlPointDeliverySequence, 0x30080041, SQ, 1 */
    extern DICOM_EXPORT const tag IonControlPointDeliverySequence;
    /** IonControlPointSequence, 0x300A03A8, SQ, 1 */
    extern DICOM_EXPORT const tag IonControlPointSequence;
    /** IonControlPointVerificationSequence, 0x0074104E, SQ, 1 */
    extern DICOM_EXPORT const tag IonControlPointVerificationSequence;
    /** IonMachineVerificationSequence, 0x00741046, SQ, 1 */
    extern DICOM_EXPORT const tag IonMachineVerificationSequence;
    /** IonRangeCompensatorSequence, 0x300A02EA, SQ, 1 */
    extern DICOM_EXPORT const tag IonRangeCompensatorSequence;
    /** IonToleranceTableSequence, 0x300A03A0, SQ, 1 */
    extern DICOM_EXPORT const tag IonToleranceTableSequence;
    /** IonWedgePositionSequence, 0x300A03AC, SQ, 1 */
    extern DICOM_EXPORT const tag IonWedgePositionSequence;
    /** IonWedgeSequence, 0x300A03AA, SQ, 1 */
    extern DICOM_EXPORT const tag IonWedgeSequence;
    /** IrradiationEventIdentificationSequence, 0x00189477, SQ, 1 */
    extern DICOM_EXPORT const tag IrradiationEventIdentificationSequence;
    /** IrradiationEventUID, 0x00083010, UI, 1 */
    extern DICOM_EXPORT const tag IrradiationEventUID;
    /** IsocenterPosition, 0x300A012C, DS, 3 */
    extern DICOM_EXPORT const tag IsocenterPosition;
    /** IsocenterReferenceSystemSequence, 0x00189462, SQ, 1 */
    extern DICOM_EXPORT const tag IsocenterReferenceSystemSequence;
    /** IsocenterToBeamLimitingDeviceDistance, 0x300A00BB, FL, 1 */
    extern DICOM_EXPORT const tag IsocenterToBeamLimitingDeviceDistance;
    /** IsocenterToBlockTrayDistance, 0x300A00F7, FL, 1 */
    extern DICOM_EXPORT const tag IsocenterToBlockTrayDistance;
    /** IsocenterToCompensatorDistances, 0x300A02E6, FL, 1 */
    extern DICOM_EXPORT const tag IsocenterToCompensatorDistances;
    /** IsocenterToCompensatorTrayDistance, 0x300A02E4, FL, 1 */
    extern DICOM_EXPORT const tag IsocenterToCompensatorTrayDistance;
    /** IsocenterToLateralSpreadingDeviceDistance, 0x300A0374, FL, 1 */
    extern DICOM_EXPORT const tag IsocenterToLateralSpreadingDeviceDistance;
    /** IsocenterToRangeModulatorDistance, 0x300A038A, FL, 1 */
    extern DICOM_EXPORT const tag IsocenterToRangeModulatorDistance;
    /** IsocenterToRangeShifterDistance, 0x300A0364, FL, 1 */
    extern DICOM_EXPORT const tag IsocenterToRangeShifterDistance;
    /** IsocenterToWedgeTrayDistance, 0x300A00D9, FL, 1 */
    extern DICOM_EXPORT const tag IsocenterToWedgeTrayDistance;
    /** IsotopeNumber, 0x00200014, IS, 1, RET */
    extern DICOM_EXPORT const tag IsotopeNumber;
    /** IssueDateOfImagingServiceRequest, 0x00402004, DA, 1 */
    extern DICOM_EXPORT const tag IssueDateOfImagingServiceRequest;
    /** IssuerOfAccessionNumberSequence, 0x00080051, SQ, 1 */
    extern DICOM_EXPORT const tag IssuerOfAccessionNumberSequence;
    /** IssuerOfAdmissionID, 0x00380011, LO, 1, RET */
    extern DICOM_EXPORT const tag IssuerOfAdmissionID;
    /** IssuerOfAdmissionIDSequence, 0x00380014, SQ, 1 */
    extern DICOM_EXPORT const tag IssuerOfAdmissionIDSequence;
    /** IssuerOfPatientID, 0x00100021, LO, 1 */
    extern DICOM_EXPORT const tag IssuerOfPatientID;
    /** IssuerOfPatientIDQualifiersSequence, 0x00100024, SQ, 1 */
    extern DICOM_EXPORT const tag IssuerOfPatientIDQualifiersSequence;
    /** IssuerOfServiceEpisodeID, 0x00380061, LO, 1, RET */
    extern DICOM_EXPORT const tag IssuerOfServiceEpisodeID;
    /** IssuerOfServiceEpisodeIDSequence, 0x00380064, SQ, 1 */
    extern DICOM_EXPORT const tag IssuerOfServiceEpisodeIDSequence;
    /** IssuerOfTheContainerIdentifierSequence, 0x00400513, SQ, 1 */
    extern DICOM_EXPORT const tag IssuerOfTheContainerIdentifierSequence;
    /** IssuerOfTheSpecimenIdentifierSequence, 0x00400562, SQ, 1 */
    extern DICOM_EXPORT const tag IssuerOfTheSpecimenIdentifierSequence;
    /** IssueTimeOfImagingServiceRequest, 0x00402005, TM, 1 */
    extern DICOM_EXPORT const tag IssueTimeOfImagingServiceRequest;
    /** Italic, 0x00700250, CS, 1 */
    extern DICOM_EXPORT const tag Italic;
    /** ItemNumber, 0x00200019, IS, 1 */
    extern DICOM_EXPORT const tag ItemNumber;
    /** IterativeReconstructionMethod, 0x00189769, CS, 1 */
    extern DICOM_EXPORT const tag IterativeReconstructionMethod;
    /** ItineraryID, 0x40101051, LO, 1, RET */
    extern DICOM_EXPORT const tag ItineraryID;
    /** ItineraryIDAssigningAuthority, 0x40101053, LO, 1, RET */
    extern DICOM_EXPORT const tag ItineraryIDAssigningAuthority;
    /** ItineraryIDType, 0x40101052, SH, 1, RET */
    extern DICOM_EXPORT const tag ItineraryIDType;
    /** IVUSAcquisition, 0x00183100, CS, 1 */
    extern DICOM_EXPORT const tag IVUSAcquisition;
    /** IVUSGatedRate, 0x00183102, DS, 1 */
    extern DICOM_EXPORT const tag IVUSGatedRate;
    /** IVUSPullbackRate, 0x00183101, DS, 1 */
    extern DICOM_EXPORT const tag IVUSPullbackRate;
    /** IVUSPullbackStartFrameNumber, 0x00183103, IS, 1 */
    extern DICOM_EXPORT const tag IVUSPullbackStartFrameNumber;
    /** IVUSPullbackStopFrameNumber, 0x00183104, IS, 1 */
    extern DICOM_EXPORT const tag IVUSPullbackStopFrameNumber;
    /** KeratoconusPredictionIndex, 0x00460236, FL, 1 */
    extern DICOM_EXPORT const tag KeratoconusPredictionIndex;
    /** KeratometerIndex, 0x00221033, FL, 1 */
    extern DICOM_EXPORT const tag KeratometerIndex;
    /** KeratometricAxis, 0x00460077, FD, 1 */
    extern DICOM_EXPORT const tag KeratometricAxis;
    /** KeratometricPower, 0x00460076, FD, 1 */
    extern DICOM_EXPORT const tag KeratometricPower;
    /** KeratometryLeftEyeSequence, 0x00460071, SQ, 1 */
    extern DICOM_EXPORT const tag KeratometryLeftEyeSequence;
    /** KeratometryMeasurementTypeCodeSequence, 0x00221096, SQ, 1 */
    extern DICOM_EXPORT const tag KeratometryMeasurementTypeCodeSequence;
    /** KeratometryRightEyeSequence, 0x00460070, SQ, 1 */
    extern DICOM_EXPORT const tag KeratometryRightEyeSequence;
    /** KSpaceFiltering, 0x00189064, CS, 1 */
    extern DICOM_EXPORT const tag KSpaceFiltering;
    /** KVP, 0x00180060, DS, 1 */
    extern DICOM_EXPORT const tag KVP;
    /** KVUsedInGainCalibration, 0x00143071, DS, 1, RET */
    extern DICOM_EXPORT const tag KVUsedInGainCalibration;
    /** LabelStyleSelection, 0x22000003, CS, 1 */
    extern DICOM_EXPORT const tag LabelStyleSelection;
    /** LabelText, 0x22000002, UT, 1 */
    extern DICOM_EXPORT const tag LabelText;
    /** LabelUsingInformationExtractedFromInstances, 0x22000001, CS, 1 */
    extern DICOM_EXPORT const tag LabelUsingInformationExtractedFromInstances;
    /** LanguageCodeSequence, 0x00080006, SQ, 1 */
    extern DICOM_EXPORT const tag LanguageCodeSequence;
    /** LanguageCodeSequenceTrial, 0x0040A744, SQ, 1, RET */
    extern DICOM_EXPORT const tag LanguageCodeSequenceTrial;
    /** LargeBluePaletteColorLookupTableData, 0x00281213, OW, 1, RET */
    extern DICOM_EXPORT const tag LargeBluePaletteColorLookupTableData;
    /** LargeBluePaletteColorLookupTableDescriptor, 0x00281113, US or SS, 4, RET */
    extern DICOM_EXPORT const tag LargeBluePaletteColorLookupTableDescriptor;
    /** LargeGreenPaletteColorLookupTableData, 0x00281212, OW, 1, RET */
    extern DICOM_EXPORT const tag LargeGreenPaletteColorLookupTableData;
    /** LargeGreenPaletteColorLookupTableDescriptor, 0x00281112, US or SS, 4, RET */
    extern DICOM_EXPORT const tag LargeGreenPaletteColorLookupTableDescriptor;
    /** LargePaletteColorLookupTableUID, 0x00281214, UI, 1, RET */
    extern DICOM_EXPORT const tag LargePaletteColorLookupTableUID;
    /** LargeRedPaletteColorLookupTableData, 0x00281211, OW, 1, RET */
    extern DICOM_EXPORT const tag LargeRedPaletteColorLookupTableData;
    /** LargeRedPaletteColorLookupTableDescriptor, 0x00281111, US or SS, 4, RET */
    extern DICOM_EXPORT const tag LargeRedPaletteColorLookupTableDescriptor;
    /** LargestImagePixelValue, 0x00280107, US or SS, 1 */
    extern DICOM_EXPORT const tag LargestImagePixelValue;
    /** LargestImagePixelValueInPlane, 0x00280111, US or SS, 1, RET */
    extern DICOM_EXPORT const tag LargestImagePixelValueInPlane;
    /** LargestMonochromePixelValue, 0x00289099, US, 1, RET */
    extern DICOM_EXPORT const tag LargestMonochromePixelValue;
    /** LargestPixelValueInSeries, 0x00280109, US or SS, 1 */
    extern DICOM_EXPORT const tag LargestPixelValueInSeries;
    /** LargestValidPixelValue, 0x00280105, US or SS, 1, RET */
    extern DICOM_EXPORT const tag LargestValidPixelValue;
    /** LastMenstrualDate, 0x001021D0, DA, 1 */
    extern DICOM_EXPORT const tag LastMenstrualDate;
    /** Laterality, 0x00200060, CS, 1 */
    extern DICOM_EXPORT const tag Laterality;
    /** LateralSpreadingDeviceDescription, 0x300A033A, LO, 1 */
    extern DICOM_EXPORT const tag LateralSpreadingDeviceDescription;
    /** LateralSpreadingDeviceID, 0x300A0336, SH, 1 */
    extern DICOM_EXPORT const tag LateralSpreadingDeviceID;
    /** LateralSpreadingDeviceNumber, 0x300A0334, IS, 1 */
    extern DICOM_EXPORT const tag LateralSpreadingDeviceNumber;
    /** LateralSpreadingDeviceSequence, 0x300A0332, SQ, 1 */
    extern DICOM_EXPORT const tag LateralSpreadingDeviceSequence;
    /** LateralSpreadingDeviceSetting, 0x300A0372, LO, 1 */
    extern DICOM_EXPORT const tag LateralSpreadingDeviceSetting;
    /** LateralSpreadingDeviceSettingsSequence, 0x300A0370, SQ, 1 */
    extern DICOM_EXPORT const tag LateralSpreadingDeviceSettingsSequence;
    /** LateralSpreadingDeviceType, 0x300A0338, CS, 1 */
    extern DICOM_EXPORT const tag LateralSpreadingDeviceType;
    /** LateralSpreadingDeviceWaterEquivalentThickness, 0x300A033C, FL, 1 */
    extern DICOM_EXPORT const tag LateralSpreadingDeviceWaterEquivalentThickness;
    /** LeafJawPositions, 0x300A011C, DS, 2 */
    extern DICOM_EXPORT const tag LeafJawPositions;
    /** LeafPositionBoundaries, 0x300A00BE, DS, 3 */
    extern DICOM_EXPORT const tag LeafPositionBoundaries;
    /** LeftImageSequence, 0x00220021, SQ, 1 */
    extern DICOM_EXPORT const tag LeftImageSequence;
    /** LeftLensSequence, 0x00460015, SQ, 1 */
    extern DICOM_EXPORT const tag LeftLensSequence;
    /** LengthToEnd, 0x00080001, UL, 1, RET */
    extern DICOM_EXPORT const tag LengthToEnd;
    /** LensConstantDescription, 0x00221094, LO, 1, RET */
    extern DICOM_EXPORT const tag LensConstantDescription;
    /** LensConstantSequence, 0x00221092, SQ, 1 */
    extern DICOM_EXPORT const tag LensConstantSequence;
    /** LensDescription, 0x00460012, LO, 1 */
    extern DICOM_EXPORT const tag LensDescription;
    /** LensesCodeSequence, 0x00220019, SQ, 1 */
    extern DICOM_EXPORT const tag LensesCodeSequence;
    /** LensSegmentType, 0x00460038, CS, 1 */
    extern DICOM_EXPORT const tag LensSegmentType;
    /** LensStatusCodeSequence, 0x00221024, SQ, 1 */
    extern DICOM_EXPORT const tag LensStatusCodeSequence;
    /** LensStatusDescription, 0x00221065, LO, 1 */
    extern DICOM_EXPORT const tag LensStatusDescription;
    /** LensThickness, 0x00221130, FL, 1 */
    extern DICOM_EXPORT const tag LensThickness;
    /** LensThicknessSequence, 0x00221127, SQ, 1 */
    extern DICOM_EXPORT const tag LensThicknessSequence;
    /** LesionNumber, 0x00183105, IS, 1 */
    extern DICOM_EXPORT const tag LesionNumber;
    /** LightDirection, 0x00701703, FD, 3 */
    extern DICOM_EXPORT const tag LightDirection;
    /** LightPathFilterPassBand, 0x00220002, US, 2 */
    extern DICOM_EXPORT const tag LightPathFilterPassBand;
    /** LightPathFilterPassThroughWavelength, 0x00220001, US, 1 */
    extern DICOM_EXPORT const tag LightPathFilterPassThroughWavelength;
    /** LightPathFilterTypeStackCodeSequence, 0x00220017, SQ, 1 */
    extern DICOM_EXPORT const tag LightPathFilterTypeStackCodeSequence;
    /** LINACEnergy, 0x00145002, IS, 1, RET */
    extern DICOM_EXPORT const tag LINACEnergy;
    /** LINACOutput, 0x00145004, IS, 1, RET */
    extern DICOM_EXPORT const tag LINACOutput;
    /** LineDashingStyle, 0x00700254, CS, 1 */
    extern DICOM_EXPORT const tag LineDashingStyle;
    /** LinePattern, 0x00700255, UL, 1 */
    extern DICOM_EXPORT const tag LinePattern;
    /** LineSequence, 0x00660028, SQ, 1 */
    extern DICOM_EXPORT const tag LineSequence;
    /** LineStyleSequence, 0x00700232, SQ, 1 */
    extern DICOM_EXPORT const tag LineStyleSequence;
    /** LineThickness, 0x00700253, FL, 1 */
    extern DICOM_EXPORT const tag LineThickness;
    /** ListOfMIMETypes, 0x00420014, LO, 1 */
    extern DICOM_EXPORT const tag ListOfMIMETypes;
    /** LocalDeviationProbabilityNormalsFlag, 0x00240072, CS, 1 */
    extern DICOM_EXPORT const tag LocalDeviationProbabilityNormalsFlag;
    /** LocalizedDeviationFromNormal, 0x00240068, FL, 1 */
    extern DICOM_EXPORT const tag LocalizedDeviationFromNormal;
    /** LocalizedDeviationProbability, 0x00240073, FL, 1 */
    extern DICOM_EXPORT const tag LocalizedDeviationProbability;
    /** LocalizedDeviationProbabilitySequence, 0x00240085, SQ, 1 */
    extern DICOM_EXPORT const tag LocalizedDeviationProbabilitySequence;
    /** LocalizingCursorPosition, 0x00182043, FL, 2 */
    extern DICOM_EXPORT const tag LocalizingCursorPosition;
    /** LocalNamespaceEntityID, 0x00400031, UT, 1 */
    extern DICOM_EXPORT const tag LocalNamespaceEntityID;
    /** Location, 0x00200050, DS, 1, RET */
    extern DICOM_EXPORT const tag Location;
    /** LocationOfMeasuredBeamDiameter, 0x00144019, DS, 1, RET */
    extern DICOM_EXPORT const tag LocationOfMeasuredBeamDiameter;
    /** LongCodeValue, 0x00080119, UC, 1 */
    extern DICOM_EXPORT const tag LongCodeValue;
    /** LongEdgePointIndexList, 0x00660042, OL, 1 */
    extern DICOM_EXPORT const tag LongEdgePointIndexList;
    /** LongitudinalTemporalEventType, 0x00120053, CS, 1 */
    extern DICOM_EXPORT const tag LongitudinalTemporalEventType;
    /** LongitudinalTemporalInformationModified, 0x00280303, CS, 1 */
    extern DICOM_EXPORT const tag LongitudinalTemporalInformationModified;
    /** LongitudinalTemporalOffsetFromEvent, 0x00120052, FD, 1 */
    extern DICOM_EXPORT const tag LongitudinalTemporalOffsetFromEvent;
    /** LongPrimitivePointIndexList, 0x00660040, OL, 1 */
    extern DICOM_EXPORT const tag LongPrimitivePointIndexList;
    /** LongTrianglePointIndexList, 0x00660041, OL, 1 */
    extern DICOM_EXPORT const tag LongTrianglePointIndexList;
    /** LongVertexPointIndexList, 0x00660043, OL, 1 */
    extern DICOM_EXPORT const tag LongVertexPointIndexList;
    /** LossyImageCompression, 0x00282110, CS, 1 */
    extern DICOM_EXPORT const tag LossyImageCompression;
    /** LossyImageCompressionMethod, 0x00282114, CS, 1 */
    extern DICOM_EXPORT const tag LossyImageCompressionMethod;
    /** LossyImageCompressionRatio, 0x00282112, DS, 1 */
    extern DICOM_EXPORT const tag LossyImageCompressionRatio;
    /** LossyImageCompressionRetired, 0x00082110, CS, 1, RET */
    extern DICOM_EXPORT const tag LossyImageCompressionRetired;
    /** LowEnergyDetectors, 0x40100001, CS, 1, RET */
    extern DICOM_EXPORT const tag LowEnergyDetectors;
    /** LowRRValue, 0x00181081, IS, 1 */
    extern DICOM_EXPORT const tag LowRRValue;
    /** LuminanceCharacteristicsID, 0x00287009, US, 1 */
    extern DICOM_EXPORT const tag LuminanceCharacteristicsID;
    /** LuminanceResponseDescription, 0x00287020, LO, 1 */
    extern DICOM_EXPORT const tag LuminanceResponseDescription;
    /** LuminanceResponseSequence, 0x0028701C, SQ, 1 */
    extern DICOM_EXPORT const tag LuminanceResponseSequence;
    /** LuminanceResultSequence, 0x00287024, SQ, 1 */
    extern DICOM_EXPORT const tag LuminanceResultSequence;
    /** LuminanceUniformityResultSequence, 0x00287027, SQ, 1 */
    extern DICOM_EXPORT const tag LuminanceUniformityResultSequence;
    /** LuminanceValue, 0x0028701F, FL, 1 */
    extern DICOM_EXPORT const tag LuminanceValue;
    /** LUTData, 0x00283006, US or OW, 1 */
    extern DICOM_EXPORT const tag LUTData;
    /** LUTDescriptor, 0x00283002, US or SS, 3 */
    extern DICOM_EXPORT const tag LUTDescriptor;
    /** LUTExplanation, 0x00283003, LO, 1 */
    extern DICOM_EXPORT const tag LUTExplanation;
    /** LUTFrameRange, 0x00289507, US, 2 */
    extern DICOM_EXPORT const tag LUTFrameRange;
    /** LUTFunction, 0x00289474, CS, 1 */
    extern DICOM_EXPORT const tag LUTFunction;
    /** LUTLabel, 0x00409210, SH, 1 */
    extern DICOM_EXPORT const tag LUTLabel;
    /** LUTNumber, 0x00200026, IS, 1, RET */
    extern DICOM_EXPORT const tag LUTNumber;
    /** MAC, 0x04000404, OB, 1 */
    extern DICOM_EXPORT const tag MAC;
    /** MACAlgorithm, 0x04000015, CS, 1 */
    extern DICOM_EXPORT const tag MACAlgorithm;
    /** MACCalculationTransferSyntaxUID, 0x04000010, UI, 1 */
    extern DICOM_EXPORT const tag MACCalculationTransferSyntaxUID;
    /** MACIDNumber, 0x04000005, US, 1 */
    extern DICOM_EXPORT const tag MACIDNumber;
    /** MACParametersSequence, 0x4FFE0001, SQ, 1 */
    extern DICOM_EXPORT const tag MACParametersSequence;
    /** MagneticFieldStrength, 0x00180087, DS, 1 */
    extern DICOM_EXPORT const tag MagneticFieldStrength;
    /** MagnetizationTransfer, 0x00189020, CS, 1 */
    extern DICOM_EXPORT const tag MagnetizationTransfer;
    /** MagnificationType, 0x20100060, CS, 1 */
    extern DICOM_EXPORT const tag MagnificationType;
    /** MagnifyToNumberOfColumns, 0x20400074, US, 1, RET */
    extern DICOM_EXPORT const tag MagnifyToNumberOfColumns;
    /** MainLobeAngle, 0x00145103, DS, 1, RET */
    extern DICOM_EXPORT const tag MainLobeAngle;
    /** MainRoofAngle, 0x00145104, DS, 1, RET */
    extern DICOM_EXPORT const tag MainRoofAngle;
    /** MajorTicksSequence, 0x00700287, SQ, 1 */
    extern DICOM_EXPORT const tag MajorTicksSequence;
    /** MandatoryComponentType, 0x00760038, CS, 1 */
    extern DICOM_EXPORT const tag MandatoryComponentType;
    /** Manifold, 0x00660010, CS, 1 */
    extern DICOM_EXPORT const tag Manifold;
    /** ManipulatedImage, 0x00280050, LO, 1, RET */
    extern DICOM_EXPORT const tag ManipulatedImage;
    /** Manufacturer, 0x00080070, LO, 1 */
    extern DICOM_EXPORT const tag Manufacturer;
    /** ManufacturerModelName, 0x00081090, LO, 1 */
    extern DICOM_EXPORT const tag ManufacturerModelName;
    /** ManufacturerRelatedModelGroup, 0x00080222, LO, 1 */
    extern DICOM_EXPORT const tag ManufacturerRelatedModelGroup;
    /** MappedPixelValue, 0x00221452, US or SS, 1 */
    extern DICOM_EXPORT const tag MappedPixelValue;
    /** MappingResource, 0x00080105, CS, 1 */
    extern DICOM_EXPORT const tag MappingResource;
    /** MappingResourceIdentificationSequence, 0x00080124, SQ, 1 */
    extern DICOM_EXPORT const tag MappingResourceIdentificationSequence;
    /** MappingResourceName, 0x00080122, LO, 1 */
    extern DICOM_EXPORT const tag MappingResourceName;
    /** MappingResourceUID, 0x00080118, UI, 1 */
    extern DICOM_EXPORT const tag MappingResourceUID;
    /** MaskFrameNumbers, 0x00286110, US, 1 */
    extern DICOM_EXPORT const tag MaskFrameNumbers;
    /** MaskingImage, 0x00200080, CS, 1, RET */
    extern DICOM_EXPORT const tag MaskingImage;
    /** MaskOperation, 0x00286101, CS, 1 */
    extern DICOM_EXPORT const tag MaskOperation;
    /** MaskOperationExplanation, 0x00286190, ST, 1 */
    extern DICOM_EXPORT const tag MaskOperationExplanation;
    /** MaskPointers, 0x00286030, US, 1, RET */
    extern DICOM_EXPORT const tag MaskPointers;
    /** MaskSelectionMode, 0x00289454, CS, 1 */
    extern DICOM_EXPORT const tag MaskSelectionMode;
    /** MaskSubPixelShift, 0x00286114, FL, 2 */
    extern DICOM_EXPORT const tag MaskSubPixelShift;
    /** MaskSubtractionSequence, 0x00286100, SQ, 1 */
    extern DICOM_EXPORT const tag MaskSubtractionSequence;
    /** MaskVisibilityPercentage, 0x00289478, FL, 1 */
    extern DICOM_EXPORT const tag MaskVisibilityPercentage;
    /** Mass, 0x40101017, FL, 1, RET */
    extern DICOM_EXPORT const tag Mass;
    /** MaterialGrade, 0x00140042, ST, 1, RET */
    extern DICOM_EXPORT const tag MaterialGrade;
    /** MaterialID, 0x300A00E1, SH, 1 */
    extern DICOM_EXPORT const tag MaterialID;
    /** MaterialIsolationDiameter, 0x00140034, DS, 1, RET */
    extern DICOM_EXPORT const tag MaterialIsolationDiameter;
    /** MaterialNotes, 0x00140046, LT, 1, RET */
    extern DICOM_EXPORT const tag MaterialNotes;
    /** MaterialPipeDiameter, 0x00140032, DS, 1, RET */
    extern DICOM_EXPORT const tag MaterialPipeDiameter;
    /** MaterialPropertiesDescription, 0x00140044, ST, 1, RET */
    extern DICOM_EXPORT const tag MaterialPropertiesDescription;
    /** MaterialPropertiesFileFormatRetired, 0x00140045, ST, 1, RET */
    extern DICOM_EXPORT const tag MaterialPropertiesFileFormatRetired;
    /** MaterialsCodeSequence, 0x006863A0, SQ, 1 */
    extern DICOM_EXPORT const tag MaterialsCodeSequence;
    /** MaterialThickness, 0x00140030, DS, 1, RET */
    extern DICOM_EXPORT const tag MaterialThickness;
    /** MatingFeatureDegreeOfFreedomSequence, 0x00686400, SQ, 1 */
    extern DICOM_EXPORT const tag MatingFeatureDegreeOfFreedomSequence;
    /** MatingFeatureID, 0x006863F0, US, 1 */
    extern DICOM_EXPORT const tag MatingFeatureID;
    /** MatingFeatureSequence, 0x006863E0, SQ, 1 */
    extern DICOM_EXPORT const tag MatingFeatureSequence;
    /** MatingFeatureSetID, 0x006863C0, US, 1 */
    extern DICOM_EXPORT const tag MatingFeatureSetID;
    /** MatingFeatureSetLabel, 0x006863D0, LO, 1 */
    extern DICOM_EXPORT const tag MatingFeatureSetLabel;
    /** MatingFeatureSetsSequence, 0x006863B0, SQ, 1 */
    extern DICOM_EXPORT const tag MatingFeatureSetsSequence;
    /** MatrixRegistrationSequence, 0x00700309, SQ, 1 */
    extern DICOM_EXPORT const tag MatrixRegistrationSequence;
    /** MatrixSequence, 0x0070030A, SQ, 1 */
    extern DICOM_EXPORT const tag MatrixSequence;
    /** MAUsedInGainCalibration, 0x00143072, DS, 1, RET */
    extern DICOM_EXPORT const tag MAUsedInGainCalibration;
    /** MaxDensity, 0x20100130, US, 1 */
    extern DICOM_EXPORT const tag MaxDensity;
    /** MaximumAcrossScanDistortion, 0x00220049, FL, 1 */
    extern DICOM_EXPORT const tag MaximumAcrossScanDistortion;
    /** MaximumAlongScanDistortion, 0x00220038, FL, 1 */
    extern DICOM_EXPORT const tag MaximumAlongScanDistortion;
    /** MaximumCollatedFilms, 0x20100154, IS, 1 */
    extern DICOM_EXPORT const tag MaximumCollatedFilms;
    /** MaximumCoordinateValue, 0x50000105, US, 1, RET */
    extern DICOM_EXPORT const range_tag MaximumCoordinateValue;
    /** MaximumCornealCurvature, 0x00460212, FL, 1 */
    extern DICOM_EXPORT const tag MaximumCornealCurvature;
    /** MaximumCornealCurvatureLocation, 0x00460213, FL, 2 */
    extern DICOM_EXPORT const tag MaximumCornealCurvatureLocation;
    /** MaximumCornealCurvatureSequence, 0x00460211, SQ, 1 */
    extern DICOM_EXPORT const tag MaximumCornealCurvatureSequence;
    /** MaximumDepthDistortion, 0x00220036, FL, 1 */
    extern DICOM_EXPORT const tag MaximumDepthDistortion;
    /** MaximumFractionalValue, 0x0062000E, US, 1 */
    extern DICOM_EXPORT const tag MaximumFractionalValue;
    /** MaximumMemoryAllocation, 0x20000061, IS, 1 */
    extern DICOM_EXPORT const tag MaximumMemoryAllocation;
    /** MaximumPointDistance, 0x00660019, FL, 1 */
    extern DICOM_EXPORT const tag MaximumPointDistance;
    /** MaximumStimulusLuminance, 0x00240018, FL, 1 */
    extern DICOM_EXPORT const tag MaximumStimulusLuminance;
    /** MaximumStoredValueMapped, 0x00281232, FD, 1 */
    extern DICOM_EXPORT const tag MaximumStoredValueMapped;
    /** MeanPointDistance, 0x00660018, FL, 1 */
    extern DICOM_EXPORT const tag MeanPointDistance;
    /** MeasuredAPDimension, 0x00101023, DS, 1 */
    extern DICOM_EXPORT const tag MeasuredAPDimension;
    /** MeasuredBandwidth, 0x0014401C, DS, 1, RET */
    extern DICOM_EXPORT const tag MeasuredBandwidth;
    /** MeasuredBeamDimensionA, 0x00144017, DS, 1, RET */
    extern DICOM_EXPORT const tag MeasuredBeamDimensionA;
    /** MeasuredBeamDimensionB, 0x00144018, DS, 1, RET */
    extern DICOM_EXPORT const tag MeasuredBeamDimensionB;
    /** MeasuredCenterFrequency, 0x0014401B, DS, 1, RET */
    extern DICOM_EXPORT const tag MeasuredCenterFrequency;
    /** MeasuredCharacteristics, 0x00287026, CS, 1 */
    extern DICOM_EXPORT const tag MeasuredCharacteristics;
    /** MeasuredDoseDescription, 0x30080012, ST, 1 */
    extern DICOM_EXPORT const tag MeasuredDoseDescription;
    /** MeasuredDoseReferenceNumber, 0x30080064, IS, 1 */
    extern DICOM_EXPORT const tag MeasuredDoseReferenceNumber;
    /** MeasuredDoseReferenceSequence, 0x30080010, SQ, 1 */
    extern DICOM_EXPORT const tag MeasuredDoseReferenceSequence;
    /** MeasuredDoseType, 0x30080014, CS, 1 */
    extern DICOM_EXPORT const tag MeasuredDoseType;
    /** MeasuredDoseValue, 0x30080016, DS, 1 */
    extern DICOM_EXPORT const tag MeasuredDoseValue;
    /** MeasuredLateralDimension, 0x00101024, DS, 1 */
    extern DICOM_EXPORT const tag MeasuredLateralDimension;
    /** MeasuredValueSequence, 0x0040A300, SQ, 1 */
    extern DICOM_EXPORT const tag MeasuredValueSequence;
    /** MeasurementAutomationTrial, 0x0040A194, CS, 1, RET */
    extern DICOM_EXPORT const tag MeasurementAutomationTrial;
    /** MeasurementEquipmentSequence, 0x00287012, SQ, 1 */
    extern DICOM_EXPORT const tag MeasurementEquipmentSequence;
    /** MeasurementEquipmentType, 0x00287014, CS, 1 */
    extern DICOM_EXPORT const tag MeasurementEquipmentType;
    /** MeasurementFunctions, 0x00287013, CS, 1 */
    extern DICOM_EXPORT const tag MeasurementFunctions;
    /** MeasurementLaterality, 0x00240113, CS, 1 */
    extern DICOM_EXPORT const tag MeasurementLaterality;
    /** MeasurementPatternCodeSequence, 0x0028702D, SQ, 1 */
    extern DICOM_EXPORT const tag MeasurementPatternCodeSequence;
    /** MeasurementPrecisionDescriptionTrial, 0x0040A047, LO, 1, RET */
    extern DICOM_EXPORT const tag MeasurementPrecisionDescriptionTrial;
    /** MeasurementsSequence, 0x00660121, SQ, 1 */
    extern DICOM_EXPORT const tag MeasurementsSequence;
    /** MeasurementUnitsCodeSequence, 0x004008EA, SQ, 1 */
    extern DICOM_EXPORT const tag MeasurementUnitsCodeSequence;
    /** MeasurementValuesSequence, 0x00660132, SQ, 1 */
    extern DICOM_EXPORT const tag MeasurementValuesSequence;
    /** MeasuringUnitsSequence, 0x00400295, SQ, 1 */
    extern DICOM_EXPORT const tag MeasuringUnitsSequence;
    /** MechanicalIndex, 0x00185022, DS, 1 */
    extern DICOM_EXPORT const tag MechanicalIndex;
    /** MediaDisposition, 0x22000004, LT, 1 */
    extern DICOM_EXPORT const tag MediaDisposition;
    /** MediaInstalledSequence, 0x200000A2, SQ, 1 */
    extern DICOM_EXPORT const tag MediaInstalledSequence;
    /** MediaStorageSOPClassUID, 0x00020002, UI, 1 */
    extern DICOM_EXPORT const tag MediaStorageSOPClassUID;
    /** MediaStorageSOPInstanceUID, 0x00020003, UI, 1 */
    extern DICOM_EXPORT const tag MediaStorageSOPInstanceUID;
    /** MedicalAlerts, 0x00102000, LO, 1 */
    extern DICOM_EXPORT const tag MedicalAlerts;
    /** MedicalRecordLocator, 0x00101090, LO, 1, RET */
    extern DICOM_EXPORT const tag MedicalRecordLocator;
    /** MediumType, 0x20000030, CS, 1 */
    extern DICOM_EXPORT const tag MediumType;
    /** MemoryAllocation, 0x20000060, IS, 1 */
    extern DICOM_EXPORT const tag MemoryAllocation;
    /** MemoryBitDepth, 0x200000A0, US, 1 */
    extern DICOM_EXPORT const tag MemoryBitDepth;
    /** MetaboliteMapCodeSequence, 0x00189083, SQ, 1 */
    extern DICOM_EXPORT const tag MetaboliteMapCodeSequence;
    /** MetaboliteMapDescription, 0x00189080, ST, 1 */
    extern DICOM_EXPORT const tag MetaboliteMapDescription;
    /** MetersetExposure, 0x30020032, DS, 1 */
    extern DICOM_EXPORT const tag MetersetExposure;
    /** MetersetRate, 0x300A035A, FL, 1 */
    extern DICOM_EXPORT const tag MetersetRate;
    /** MetersetRateDelivered, 0x30080046, FL, 1 */
    extern DICOM_EXPORT const tag MetersetRateDelivered;
    /** MetersetRateSet, 0x30080045, FL, 1 */
    extern DICOM_EXPORT const tag MetersetRateSet;
    /** MidSlabPosition, 0x00189106, FD, 3 */
    extern DICOM_EXPORT const tag MidSlabPosition;
    /** MilitaryRank, 0x00101080, LO, 1 */
    extern DICOM_EXPORT const tag MilitaryRank;
    /** MIMETypeOfEncapsulatedDocument, 0x00420012, LO, 1 */
    extern DICOM_EXPORT const tag MIMETypeOfEncapsulatedDocument;
    /** MinDensity, 0x20100120, US, 1 */
    extern DICOM_EXPORT const tag MinDensity;
    /** MinimumCoordinateValue, 0x50000104, US, 1, RET */
    extern DICOM_EXPORT const range_tag MinimumCoordinateValue;
    /** MinimumKeratometricSequence, 0x00460215, SQ, 1 */
    extern DICOM_EXPORT const tag MinimumKeratometricSequence;
    /** MinimumSensitivityValue, 0x00240105, FL, 1 */
    extern DICOM_EXPORT const tag MinimumSensitivityValue;
    /** MinimumStoredValueMapped, 0x00281231, FD, 1 */
    extern DICOM_EXPORT const tag MinimumStoredValueMapped;
    /** ModalitiesInStudy, 0x00080061, CS, 1 */
    extern DICOM_EXPORT const tag ModalitiesInStudy;
    /** Modality, 0x00080060, CS, 1 */
    extern DICOM_EXPORT const tag Modality;
    /** ModalityLUTSequence, 0x00283000, SQ, 1 */
    extern DICOM_EXPORT const tag ModalityLUTSequence;
    /** ModalityLUTType, 0x00283004, LO, 1 */
    extern DICOM_EXPORT const tag ModalityLUTType;
    /** ModelMirroring, 0x00687002, CS, 1 */
    extern DICOM_EXPORT const tag ModelMirroring;
    /** ModelModification, 0x00687001, CS, 1 */
    extern DICOM_EXPORT const tag ModelModification;
    /** ModelSpecificationSequence, 0x00189912, SQ, 1 */
    extern DICOM_EXPORT const tag ModelSpecificationSequence;
    /** ModelUsageCodeSequence, 0x00687003, SQ, 1 */
    extern DICOM_EXPORT const tag ModelUsageCodeSequence;
    /** ModeOfPercutaneousAccessSequence, 0x00520016, SQ, 1 */
    extern DICOM_EXPORT const tag ModeOfPercutaneousAccessSequence;
    /** ModifiableConstraintFlag, 0x00820038, CS, 1 */
    extern DICOM_EXPORT const tag ModifiableConstraintFlag;
    /** ModifiedAttributesSequence, 0x04000550, SQ, 1 */
    extern DICOM_EXPORT const tag ModifiedAttributesSequence;
    /** ModifiedImageDate, 0x00203403, DA, 1, RET */
    extern DICOM_EXPORT const tag ModifiedImageDate;
    /** ModifiedImageDescription, 0x00203406, LO, 1, RET */
    extern DICOM_EXPORT const tag ModifiedImageDescription;
    /** ModifiedImageID, 0x00203402, CS, 1, RET */
    extern DICOM_EXPORT const tag ModifiedImageID;
    /** ModifiedImageTime, 0x00203405, TM, 1, RET */
    extern DICOM_EXPORT const tag ModifiedImageTime;
    /** ModifierCodeSequence, 0x0040A195, SQ, 1 */
    extern DICOM_EXPORT const tag ModifierCodeSequence;
    /** ModifyingDeviceID, 0x00203401, CS, 1, RET */
    extern DICOM_EXPORT const tag ModifyingDeviceID;
    /** ModifyingDeviceManufacturer, 0x00203404, LO, 1, RET */
    extern DICOM_EXPORT const tag ModifyingDeviceManufacturer;
    /** ModifyingSystem, 0x04000563, LO, 1 */
    extern DICOM_EXPORT const tag ModifyingSystem;
    /** ModulatedScanModeType, 0x300A0309, CS, 1 */
    extern DICOM_EXPORT const tag ModulatedScanModeType;
    /** ModulationType, 0x00144026, CS, 1, RET */
    extern DICOM_EXPORT const tag ModulationType;
    /** MostRecentTreatmentDate, 0x30080056, DA, 1 */
    extern DICOM_EXPORT const tag MostRecentTreatmentDate;
    /** MotionSynchronizationSequence, 0x300A0410, SQ, 1 */
    extern DICOM_EXPORT const tag MotionSynchronizationSequence;
    /** MPRSlabThickness, 0x00701503, FD, 1 */
    extern DICOM_EXPORT const tag MPRSlabThickness;
    /** MPRThicknessType, 0x00701502, CS, 1 */
    extern DICOM_EXPORT const tag MPRThicknessType;
    /** MPRTopLeftHandCorner, 0x00701505, FD, 3 */
    extern DICOM_EXPORT const tag MPRTopLeftHandCorner;
    /** MPRViewHeight, 0x00701512, FD, 1 */
    extern DICOM_EXPORT const tag MPRViewHeight;
    /** MPRViewHeightDirection, 0x00701511, FD, 3 */
    extern DICOM_EXPORT const tag MPRViewHeightDirection;
    /** MPRViewWidth, 0x00701508, FD, 1 */
    extern DICOM_EXPORT const tag MPRViewWidth;
    /** MPRViewWidthDirection, 0x00701507, FD, 3 */
    extern DICOM_EXPORT const tag MPRViewWidthDirection;
    /** MRAcquisitionFrequencyEncodingSteps, 0x00189058, US, 1 */
    extern DICOM_EXPORT const tag MRAcquisitionFrequencyEncodingSteps;
    /** MRAcquisitionPhaseEncodingStepsInPlane, 0x00189231, US, 1 */
    extern DICOM_EXPORT const tag MRAcquisitionPhaseEncodingStepsInPlane;
    /** MRAcquisitionPhaseEncodingStepsOutOfPlane, 0x00189232, US, 1 */
    extern DICOM_EXPORT const tag MRAcquisitionPhaseEncodingStepsOutOfPlane;
    /** MRAcquisitionType, 0x00180023, CS, 1 */
    extern DICOM_EXPORT const tag MRAcquisitionType;
    /** MRArterialSpinLabelingSequence, 0x00189251, SQ, 1 */
    extern DICOM_EXPORT const tag MRArterialSpinLabelingSequence;
    /** MRAveragesSequence, 0x00189119, SQ, 1 */
    extern DICOM_EXPORT const tag MRAveragesSequence;
    /** MRDiffusionSequence, 0x00189117, SQ, 1 */
    extern DICOM_EXPORT const tag MRDiffusionSequence;
    /** MRDRDirectoryRecordOffset, 0x00041504, UL, 1, RET */
    extern DICOM_EXPORT const tag MRDRDirectoryRecordOffset;
    /** MREchoSequence, 0x00189114, SQ, 1 */
    extern DICOM_EXPORT const tag MREchoSequence;
    /** MRFOVGeometrySequence, 0x00189125, SQ, 1 */
    extern DICOM_EXPORT const tag MRFOVGeometrySequence;
    /** MRImageFrameTypeSequence, 0x00189226, SQ, 1 */
    extern DICOM_EXPORT const tag MRImageFrameTypeSequence;
    /** MRImagingModifierSequence, 0x00189006, SQ, 1 */
    extern DICOM_EXPORT const tag MRImagingModifierSequence;
    /** MRMetaboliteMapSequence, 0x00189152, SQ, 1 */
    extern DICOM_EXPORT const tag MRMetaboliteMapSequence;
    /** MRModifierSequence, 0x00189115, SQ, 1 */
    extern DICOM_EXPORT const tag MRModifierSequence;
    /** MRReceiveCoilSequence, 0x00189042, SQ, 1 */
    extern DICOM_EXPORT const tag MRReceiveCoilSequence;
    /** MRSpatialSaturationSequence, 0x00189107, SQ, 1 */
    extern DICOM_EXPORT const tag MRSpatialSaturationSequence;
    /** MRSpectroscopyAcquisitionType, 0x00189200, CS, 1 */
    extern DICOM_EXPORT const tag MRSpectroscopyAcquisitionType;
    /** MRSpectroscopyFOVGeometrySequence, 0x00189103, SQ, 1 */
    extern DICOM_EXPORT const tag MRSpectroscopyFOVGeometrySequence;
    /** MRSpectroscopyFrameTypeSequence, 0x00189227, SQ, 1 */
    extern DICOM_EXPORT const tag MRSpectroscopyFrameTypeSequence;
    /** MRTimingAndRelatedParametersSequence, 0x00189112, SQ, 1 */
    extern DICOM_EXPORT const tag MRTimingAndRelatedParametersSequence;
    /** MRTransmitCoilSequence, 0x00189049, SQ, 1 */
    extern DICOM_EXPORT const tag MRTransmitCoilSequence;
    /** MRVelocityEncodingSequence, 0x00189197, SQ, 1 */
    extern DICOM_EXPORT const tag MRVelocityEncodingSequence;
    /** MultiCoilConfiguration, 0x00189046, LO, 1 */
    extern DICOM_EXPORT const tag MultiCoilConfiguration;
    /** MultiCoilDefinitionSequence, 0x00189045, SQ, 1 */
    extern DICOM_EXPORT const tag MultiCoilDefinitionSequence;
    /** MultiCoilElementName, 0x00189047, SH, 1 */
    extern DICOM_EXPORT const tag MultiCoilElementName;
    /** MultiCoilElementUsed, 0x00189048, CS, 1 */
    extern DICOM_EXPORT const tag MultiCoilElementUsed;
    /** MultiFramePresentationSequence, 0x00289505, SQ, 1 */
    extern DICOM_EXPORT const tag MultiFramePresentationSequence;
    /** MultiFrameSourceSOPInstanceUID, 0x00081167, UI, 1 */
    extern DICOM_EXPORT const tag MultiFrameSourceSOPInstanceUID;
    /** MultiPlanarExcitation, 0x00189012, CS, 1 */
    extern DICOM_EXPORT const tag MultiPlanarExcitation;
    /** MultiPlanarReconstructionStyle, 0x00701501, CS, 1 */
    extern DICOM_EXPORT const tag MultiPlanarReconstructionStyle;
    /** MultipleComponentApprovalSequence, 0x00140106, SQ, 1, RET */
    extern DICOM_EXPORT const tag MultipleComponentApprovalSequence;
    /** MultipleCopiesFlag, 0x00404006, CS, 1, RET */
    extern DICOM_EXPORT const tag MultipleCopiesFlag;
    /** MultipleSpinEcho, 0x00189011, CS, 1 */
    extern DICOM_EXPORT const tag MultipleSpinEcho;
    /** MultiplexedAudioChannelsDescriptionCodeSequence, 0x003A0300, SQ, 1 */
    extern DICOM_EXPORT const tag MultiplexedAudioChannelsDescriptionCodeSequence;
    /** MultiplexGroupLabel, 0x003A0020, SH, 1 */
    extern DICOM_EXPORT const tag MultiplexGroupLabel;
    /** MultiplexGroupTimeOffset, 0x00181068, DS, 1 */
    extern DICOM_EXPORT const tag MultiplexGroupTimeOffset;
    /** MydriaticAgentCodeSequence, 0x0022001C, SQ, 1 */
    extern DICOM_EXPORT const tag MydriaticAgentCodeSequence;
    /** MydriaticAgentConcentration, 0x0022004E, DS, 1 */
    extern DICOM_EXPORT const tag MydriaticAgentConcentration;
    /** MydriaticAgentConcentrationUnitsSequence, 0x00220042, SQ, 1 */
    extern DICOM_EXPORT const tag MydriaticAgentConcentrationUnitsSequence;
    /** MydriaticAgentSequence, 0x00220058, SQ, 1 */
    extern DICOM_EXPORT const tag MydriaticAgentSequence;
    /** NameOfPhysiciansReadingStudy, 0x00081060, PN, 1 */
    extern DICOM_EXPORT const tag NameOfPhysiciansReadingStudy;
    /** NamesOfIntendedRecipientsOfResults, 0x00401010, PN, 1 */
    extern DICOM_EXPORT const tag NamesOfIntendedRecipientsOfResults;
    /** NavigationDisplaySet, 0x00720216, US, 1 */
    extern DICOM_EXPORT const tag NavigationDisplaySet;
    /** NavigationIndicatorSequence, 0x00720214, SQ, 1 */
    extern DICOM_EXPORT const tag NavigationIndicatorSequence;
    /** NearPupillaryDistance, 0x00460062, FD, 1 */
    extern DICOM_EXPORT const tag NearPupillaryDistance;
    /** NegativeCatchTrialsQuantity, 0x00240048, US, 1 */
    extern DICOM_EXPORT const tag NegativeCatchTrialsQuantity;
    /** NetworkID, 0x00081000, AE, 1, RET */
    extern DICOM_EXPORT const tag NetworkID;
    /** NominalBeamAngle, 0x00145112, DS, 1, RET */
    extern DICOM_EXPORT const tag NominalBeamAngle;
    /** NominalBeamEnergy, 0x300A0114, DS, 1 */
    extern DICOM_EXPORT const tag NominalBeamEnergy;
    /** NominalBeamEnergyUnit, 0x300A0015, CS, 1 */
    extern DICOM_EXPORT const tag NominalBeamEnergyUnit;
    /** NominalCardiacTriggerDelayTime, 0x00209153, FD, 1 */
    extern DICOM_EXPORT const tag NominalCardiacTriggerDelayTime;
    /** NominalCardiacTriggerTimePriorToRPeak, 0x00209154, FL, 1 */
    extern DICOM_EXPORT const tag NominalCardiacTriggerTimePriorToRPeak;
    /** NominalFrequency, 0x0014401A, DS, 1, RET */
    extern DICOM_EXPORT const tag NominalFrequency;
    /** NominalInterval, 0x00181062, IS, 1 */
    extern DICOM_EXPORT const tag NominalInterval;
    /** NominalPercentageOfCardiacPhase, 0x00209241, FL, 1 */
    extern DICOM_EXPORT const tag NominalPercentageOfCardiacPhase;
    /** NominalPercentageOfRespiratoryPhase, 0x00209245, FL, 1 */
    extern DICOM_EXPORT const tag NominalPercentageOfRespiratoryPhase;
    /** NominalPriorDose, 0x300A001A, DS, 1 */
    extern DICOM_EXPORT const tag NominalPriorDose;
    /** NominalRangeModulatedRegionDepths, 0x300A0504, FL, 2 */
    extern DICOM_EXPORT const tag NominalRangeModulatedRegionDepths;
    /** NominalRangeModulationFractions, 0x300A0503, FL, 2 */
    extern DICOM_EXPORT const tag NominalRangeModulationFractions;
    /** NominalRespiratoryTriggerDelayTime, 0x00209255, FD, 1 */
    extern DICOM_EXPORT const tag NominalRespiratoryTriggerDelayTime;
    /** NominalScannedPixelSpacing, 0x00182010, DS, 2 */
    extern DICOM_EXPORT const tag NominalScannedPixelSpacing;
    /** NominalScreenDefinitionSequence, 0x00720102, SQ, 1 */
    extern DICOM_EXPORT const tag NominalScreenDefinitionSequence;
    /** NonDICOMOutputCodeSequence, 0x00404032, SQ, 1, RET */
    extern DICOM_EXPORT const tag NonDICOMOutputCodeSequence;
    /** NonidentifyingPrivateElements, 0x00080304, US, 1 */
    extern DICOM_EXPORT const tag NonidentifyingPrivateElements;
    /** NonUniformRadialSamplingCorrected, 0x00189766, CS, 1 */
    extern DICOM_EXPORT const tag NonUniformRadialSamplingCorrected;
    /** NormalizationFactorFormat, 0x00280710, US, 1, RET */
    extern DICOM_EXPORT const tag NormalizationFactorFormat;
    /** NormalizationPoint, 0x30040008, DS, 3 */
    extern DICOM_EXPORT const tag NormalizationPoint;
    /** NotchFilterBandwidth, 0x003A0223, DS, 1 */
    extern DICOM_EXPORT const tag NotchFilterBandwidth;
    /** NotchFilterFrequency, 0x003A0222, DS, 1 */
    extern DICOM_EXPORT const tag NotchFilterFrequency;
    /** NotificationFromManufacturerSequence, 0x00686265, SQ, 1 */
    extern DICOM_EXPORT const tag NotificationFromManufacturerSequence;
    /** NTPSourceAddress, 0x00181803, LO, 1 */
    extern DICOM_EXPORT const tag NTPSourceAddress;
    /** NuclearMedicineSeriesType, 0x00080042, CS, 1, RET */
    extern DICOM_EXPORT const tag NuclearMedicineSeriesType;
    /** NumberOfAlarmObjects, 0x40101034, US, 1, RET */
    extern DICOM_EXPORT const tag NumberOfAlarmObjects;
    /** NumberOfAssessmentObservations, 0x00820006, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfAssessmentObservations;
    /** NumberOfAverages, 0x00180083, DS, 1 */
    extern DICOM_EXPORT const tag NumberOfAverages;
    /** NumberOfBeams, 0x300A0080, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfBeams;
    /** NumberOfBlocks, 0x300A00F0, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfBlocks;
    /** NumberOfBlockSlabItems, 0x300A0440, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfBlockSlabItems;
    /** NumberOfBoli, 0x300A00ED, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfBoli;
    /** NumberOfBrachyApplicationSetups, 0x300A00A0, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfBrachyApplicationSetups;
    /** NumberofBscansPerFrame, 0x00221642, UL, 1 */
    extern DICOM_EXPORT const tag NumberofBscansPerFrame;
    /** NumberOfChannels, 0x50002004, US, 1, RET */
    extern DICOM_EXPORT const range_tag NumberOfChannels;
    /** NumberOfCompensators, 0x300A00E0, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfCompensators;
    /** NumberOfContourPoints, 0x30060046, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfContourPoints;
    /** NumberOfControlPoints, 0x300A0110, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfControlPoints;
    /** NumberOfCopies, 0x20000010, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfCopies;
    /** NumberOfDetectors, 0x00540021, US, 1 */
    extern DICOM_EXPORT const tag NumberOfDetectors;
    /** NumberOfDisplaySubsystems, 0x00287001, US, 1 */
    extern DICOM_EXPORT const tag NumberOfDisplaySubsystems;
    /** NumberOfElements, 0x00144012, US, 1, RET */
    extern DICOM_EXPORT const tag NumberOfElements;
    /** NumberOfEnergyWindows, 0x00540011, US, 1 */
    extern DICOM_EXPORT const tag NumberOfEnergyWindows;
    /** NumberOfEventTimers, 0x00082129, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfEventTimers;
    /** NumberOfFilms, 0x21000170, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfFilms;
    /** NumberOfFocalPlanes, 0x00480013, US, 1 */
    extern DICOM_EXPORT const tag NumberOfFocalPlanes;
    /** NumberOfFractionPatternDigitsPerDay, 0x300A0079, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfFractionPatternDigitsPerDay;
    /** NumberOfFractionsDelivered, 0x3008005A, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfFractionsDelivered;
    /** NumberOfFractionsPlanned, 0x300A0078, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfFractionsPlanned;
    /** NumberOfFrames, 0x00280008, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfFrames;
    /** NumberOfFramesInOverlay, 0x60000015, IS, 1 */
    extern DICOM_EXPORT const range_tag NumberOfFramesInOverlay;
    /** NumberOfFramesInPhase, 0x00540033, US, 1 */
    extern DICOM_EXPORT const tag NumberOfFramesInPhase;
    /** NumberOfFramesInRotation, 0x00540053, US, 1 */
    extern DICOM_EXPORT const tag NumberOfFramesInRotation;
    /** NumberOfFramesIntegrated, 0x00143012, DS, 1, RET */
    extern DICOM_EXPORT const tag NumberOfFramesIntegrated;
    /** NumberOfFramesUsedForIntegration, 0x00143073, DS, 1, RET */
    extern DICOM_EXPORT const tag NumberOfFramesUsedForIntegration;
    /** NumberOfGraphicPoints, 0x00700021, US, 1 */
    extern DICOM_EXPORT const tag NumberOfGraphicPoints;
    /** NumberOfHorizontalPixels, 0x00720106, US, 1 */
    extern DICOM_EXPORT const tag NumberOfHorizontalPixels;
    /** NumberOfIterations, 0x00189739, US, 1 */
    extern DICOM_EXPORT const tag NumberOfIterations;
    /** NumberOfKSpaceTrajectories, 0x00189093, US, 1 */
    extern DICOM_EXPORT const tag NumberOfKSpaceTrajectories;
    /** NumberOfLateralSpreadingDevices, 0x300A0330, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfLateralSpreadingDevices;
    /** NumberOfLeafJawPairs, 0x300A00BC, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfLeafJawPairs;
    /** NumberOfLuminancePoints, 0x0028701B, US, 1 */
    extern DICOM_EXPORT const tag NumberOfLuminancePoints;
    /** NumberOfMapPoints, 0x00221530, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfMapPoints;
    /** NumberOfOpticalPaths, 0x00480302, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfOpticalPaths;
    /** NumberOfPaddedALines, 0x00520038, US, 1 */
    extern DICOM_EXPORT const tag NumberOfPaddedALines;
    /** NumberOfPaintings, 0x300A039A, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfPaintings;
    /** NumberOfPatientRelatedInstances, 0x00201204, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfPatientRelatedInstances;
    /** NumberOfPatientRelatedSeries, 0x00201202, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfPatientRelatedSeries;
    /** NumberOfPatientRelatedStudies, 0x00201200, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfPatientRelatedStudies;
    /** NumberOfPhaseEncodingSteps, 0x00180089, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfPhaseEncodingSteps;
    /** NumberOfPhases, 0x00540031, US, 1 */
    extern DICOM_EXPORT const tag NumberOfPhases;
    /** NumberOfPoints, 0x50000010, US, 1, RET */
    extern DICOM_EXPORT const range_tag NumberOfPoints;
    /** NumberOfPriorsReferenced, 0x00720014, US, 1 */
    extern DICOM_EXPORT const tag NumberOfPriorsReferenced;
    /** NumberOfPulses, 0x300A028A, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfPulses;
    /** NumberOfRangeModulators, 0x300A0340, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfRangeModulators;
    /** NumberOfRangeShifters, 0x300A0312, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfRangeShifters;
    /** NumberOfReferences, 0x00041600, UL, 1, RET */
    extern DICOM_EXPORT const tag NumberOfReferences;
    /** NumberOfRotations, 0x00540051, US, 1 */
    extern DICOM_EXPORT const tag NumberOfRotations;
    /** NumberOfRRIntervals, 0x00540061, US, 1 */
    extern DICOM_EXPORT const tag NumberOfRRIntervals;
    /** NumberOfSamples, 0x50002006, UL, 1, RET */
    extern DICOM_EXPORT const range_tag NumberOfSamples;
    /** NumberOfScanSpotPositions, 0x300A0392, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfScanSpotPositions;
    /** NumberOfScreens, 0x00720100, US, 1 */
    extern DICOM_EXPORT const tag NumberOfScreens;
    /** NumberOfSeriesRelatedInstances, 0x00201209, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfSeriesRelatedInstances;
    /** NumberOfSlices, 0x00540081, US, 1 */
    extern DICOM_EXPORT const tag NumberOfSlices;
    /** NumberOfStages, 0x00082124, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfStages;
    /** NumberOfStudyRelatedInstances, 0x00201208, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfStudyRelatedInstances;
    /** NumberOfStudyRelatedSeries, 0x00201206, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfStudyRelatedSeries;
    /** NumberOfSubsets, 0x00189740, US, 1 */
    extern DICOM_EXPORT const tag NumberOfSubsets;
    /** NumberOfSurfacePoints, 0x00660015, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfSurfacePoints;
    /** NumberOfSurfaces, 0x00660001, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfSurfaces;
    /** NumberOfTableBreakPoints, 0x00186050, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfTableBreakPoints;
    /** NumberOfTableEntries, 0x00186056, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfTableEntries;
    /** NumberOfTables, 0x00280802, US, 1, RET */
    extern DICOM_EXPORT const range_tag NumberOfTables;
    /** NumberOfTemporalPositions, 0x00200105, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfTemporalPositions;
    /** NumberOfTimeSlices, 0x00540101, US, 1 */
    extern DICOM_EXPORT const tag NumberOfTimeSlices;
    /** NumberOfTimeSlots, 0x00540071, US, 1 */
    extern DICOM_EXPORT const tag NumberOfTimeSlots;
    /** NumberOfTomosynthesisSourceImages, 0x00181495, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfTomosynthesisSourceImages;
    /** NumberOfTotalObjects, 0x40101033, US, 1, RET */
    extern DICOM_EXPORT const tag NumberOfTotalObjects;
    /** NumberOfTransformSteps, 0x00280402, US, 1, RET */
    extern DICOM_EXPORT const tag NumberOfTransformSteps;
    /** NumberOfTriggersInPhase, 0x00540211, US, 1 */
    extern DICOM_EXPORT const tag NumberOfTriggersInPhase;
    /** NumberOfVectors, 0x0066001E, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfVectors;
    /** NumberOfVerticalPixels, 0x00720104, US, 1 */
    extern DICOM_EXPORT const tag NumberOfVerticalPixels;
    /** NumberOfViewsInStage, 0x0008212A, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfViewsInStage;
    /** NumberOfVisualStimuli, 0x00240038, US, 1 */
    extern DICOM_EXPORT const tag NumberOfVisualStimuli;
    /** NumberOfVolumetricCurvePoints, 0x0070150C, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfVolumetricCurvePoints;
    /** NumberOfWaveformChannels, 0x003A0005, US, 1 */
    extern DICOM_EXPORT const tag NumberOfWaveformChannels;
    /** NumberOfWaveformSamples, 0x003A0010, UL, 1 */
    extern DICOM_EXPORT const tag NumberOfWaveformSamples;
    /** NumberOfWedges, 0x300A00D0, IS, 1 */
    extern DICOM_EXPORT const tag NumberOfWedges;
    /** NumberOfZeroFills, 0x00189066, US, 1 */
    extern DICOM_EXPORT const tag NumberOfZeroFills;
    /** NumericValue, 0x0040A30A, DS, 1 */
    extern DICOM_EXPORT const tag NumericValue;
    /** NumericValueQualifierCodeSequence, 0x0040A301, SQ, 1 */
    extern DICOM_EXPORT const tag NumericValueQualifierCodeSequence;
    /** ObjectBinaryIdentifierTrial, 0x0040A074, OB, 1, RET */
    extern DICOM_EXPORT const tag ObjectBinaryIdentifierTrial;
    /** ObjectDirectoryBinaryIdentifierTrial, 0x0040A089, OB, 1, RET */
    extern DICOM_EXPORT const tag ObjectDirectoryBinaryIdentifierTrial;
    /** ObjectiveLensNumericalAperture, 0x00480113, DS, 1 */
    extern DICOM_EXPORT const tag ObjectiveLensNumericalAperture;
    /** ObjectiveLensPower, 0x00480112, DS, 1 */
    extern DICOM_EXPORT const tag ObjectiveLensPower;
    /** ObjectPixelSpacingInCenterOfBeam, 0x00189404, FL, 2 */
    extern DICOM_EXPORT const tag ObjectPixelSpacingInCenterOfBeam;
    /** ObjectThicknessSequence, 0x00189456, SQ, 1 */
    extern DICOM_EXPORT const tag ObjectThicknessSequence;
    /** ObliqueCroppingPlaneSequence, 0x00701304, SQ, 1 */
    extern DICOM_EXPORT const tag ObliqueCroppingPlaneSequence;
    /** ObservationBasisCodeSequence, 0x00820022, SQ, 1 */
    extern DICOM_EXPORT const tag ObservationBasisCodeSequence;
    /** ObservationCategoryCodeSequenceTrial, 0x0040A167, SQ, 1, RET */
    extern DICOM_EXPORT const tag ObservationCategoryCodeSequenceTrial;
    /** ObservationDateTime, 0x0040A032, DT, 1 */
    extern DICOM_EXPORT const tag ObservationDateTime;
    /** ObservationDateTrial, 0x0040A192, DA, 1, RET */
    extern DICOM_EXPORT const tag ObservationDateTrial;
    /** ObservationDescription, 0x0082000A, UT, 1 */
    extern DICOM_EXPORT const tag ObservationDescription;
    /** ObservationNumber, 0x30060082, IS, 1 */
    extern DICOM_EXPORT const tag ObservationNumber;
    /** ObservationSignificance, 0x00820008, CS, 1 */
    extern DICOM_EXPORT const tag ObservationSignificance;
    /** ObservationSubjectClassTrial, 0x0040A403, CS, 1, RET */
    extern DICOM_EXPORT const tag ObservationSubjectClassTrial;
    /** ObservationSubjectContextFlagTrial, 0x0040A600, CS, 1, RET */
    extern DICOM_EXPORT const tag ObservationSubjectContextFlagTrial;
    /** ObservationSubjectTypeCodeSequenceTrial, 0x0040A404, SQ, 1, RET */
    extern DICOM_EXPORT const tag ObservationSubjectTypeCodeSequenceTrial;
    /** ObservationSubjectUIDTrial, 0x0040A402, UI, 1, RET */
    extern DICOM_EXPORT const tag ObservationSubjectUIDTrial;
    /** ObservationTimeTrial, 0x0040A193, TM, 1, RET */
    extern DICOM_EXPORT const tag ObservationTimeTrial;
    /** ObservationUID, 0x0040A171, UI, 1 */
    extern DICOM_EXPORT const tag ObservationUID;
    /** ObserverContextFlagTrial, 0x0040A601, CS, 1, RET */
    extern DICOM_EXPORT const tag ObserverContextFlagTrial;
    /** ObserverType, 0x0040A084, CS, 1 */
    extern DICOM_EXPORT const tag ObserverType;
    /** Occupation, 0x00102180, SH, 1 */
    extern DICOM_EXPORT const tag Occupation;
    /** OCTAcquisitionDomain, 0x00520006, CS, 1 */
    extern DICOM_EXPORT const tag OCTAcquisitionDomain;
    /** OCTBscanAnalysisAcquisitionParametersSequence, 0x00221640, SQ, 1 */
    extern DICOM_EXPORT const tag OCTBscanAnalysisAcquisitionParametersSequence;
    /** OCTFocalDistance, 0x00520002, FD, 1 */
    extern DICOM_EXPORT const tag OCTFocalDistance;
    /** OCTOpticalCenterWavelength, 0x00520007, FD, 1 */
    extern DICOM_EXPORT const tag OCTOpticalCenterWavelength;
    /** OCTZOffsetApplied, 0x00520026, CS, 1 */
    extern DICOM_EXPORT const tag OCTZOffsetApplied;
    /** OCTZOffsetCorrection, 0x00520030, SS, 1 */
    extern DICOM_EXPORT const tag OCTZOffsetCorrection;
    /** OffsetDirection, 0x00189905, CS, 1 */
    extern DICOM_EXPORT const tag OffsetDirection;
    /** OffsetDistance, 0x00189904, DS, 1 */
    extern DICOM_EXPORT const tag OffsetDistance;
    /** OffsetOfReferencedLowerLevelDirectoryEntity, 0x00041420, UL, 1 */
    extern DICOM_EXPORT const tag OffsetOfReferencedLowerLevelDirectoryEntity;
    /** OffsetOfTheFirstDirectoryRecordOfTheRootDirectoryEntity, 0x00041200, UL, 1 */
    extern DICOM_EXPORT const tag OffsetOfTheFirstDirectoryRecordOfTheRootDirectoryEntity;
    /** OffsetOfTheLastDirectoryRecordOfTheRootDirectoryEntity, 0x00041202, UL, 1 */
    extern DICOM_EXPORT const tag OffsetOfTheLastDirectoryRecordOfTheRootDirectoryEntity;
    /** OffsetOfTheNextDirectoryRecord, 0x00041400, UL, 1 */
    extern DICOM_EXPORT const tag OffsetOfTheNextDirectoryRecord;
    /** OmittedApplicationSetupSequence, 0x0074140E, SQ, 1 */
    extern DICOM_EXPORT const tag OmittedApplicationSetupSequence;
    /** OmittedBeamTaskSequence, 0x300C0111, SQ, 1 */
    extern DICOM_EXPORT const tag OmittedBeamTaskSequence;
    /** OmittedChannelSequence, 0x00741409, SQ, 1 */
    extern DICOM_EXPORT const tag OmittedChannelSequence;
    /** OnAxisBackgroundAnatomicStructureCodeSequenceTrial, 0x0008225C, SQ, 1, RET */
    extern DICOM_EXPORT const tag OnAxisBackgroundAnatomicStructureCodeSequenceTrial;
    /** OOIOwnerCreationTime, 0x40101041, DT, 1, RET */
    extern DICOM_EXPORT const tag OOIOwnerCreationTime;
    /** OOIOwnerSequence, 0x40101047, SQ, 1, RET */
    extern DICOM_EXPORT const tag OOIOwnerSequence;
    /** OOIOwnerType, 0x40101009, CS, 1, RET */
    extern DICOM_EXPORT const tag OOIOwnerType;
    /** OOISize, 0x40101043, FL, 3, RET */
    extern DICOM_EXPORT const tag OOISize;
    /** OOIType, 0x40101042, CS, 1, RET */
    extern DICOM_EXPORT const tag OOIType;
    /** OOITypeDescriptor, 0x40101068, LT, 1, RET */
    extern DICOM_EXPORT const tag OOITypeDescriptor;
    /** OperatingMode, 0x00189178, CS, 1 */
    extern DICOM_EXPORT const tag OperatingMode;
    /** OperatingModeSequence, 0x00189176, SQ, 1 */
    extern DICOM_EXPORT const tag OperatingModeSequence;
    /** OperatingModeType, 0x00189177, CS, 1 */
    extern DICOM_EXPORT const tag OperatingModeType;
    /** OperatorIdentificationSequence, 0x00081072, SQ, 1 */
    extern DICOM_EXPORT const tag OperatorIdentificationSequence;
    /** OperatorsName, 0x00081070, PN, 1 */
    extern DICOM_EXPORT const tag OperatorsName;
    /** OphthalmicAnatomicReferencePointXCoordinate, 0x00221624, FL, 1 */
    extern DICOM_EXPORT const tag OphthalmicAnatomicReferencePointXCoordinate;
    /** OphthalmicAnatomicReferencePointYCoordinate, 0x00221626, FL, 1 */
    extern DICOM_EXPORT const tag OphthalmicAnatomicReferencePointYCoordinate;
    /** OphthalmicAxialLength, 0x00221019, FL, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLength;
    /** OphthalmicAxialLengthAcquisitionMethodCodeSequence, 0x00221153, SQ, 1, RET */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthAcquisitionMethodCodeSequence;
    /** OphthalmicAxialLengthDataSourceCodeSequence, 0x00221150, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthDataSourceCodeSequence;
    /** OphthalmicAxialLengthDataSourceDescription, 0x00221159, LO, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthDataSourceDescription;
    /** OphthalmicAxialLengthMeasurementModified, 0x00221140, CS, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthMeasurementModified;
    /** OphthalmicAxialLengthMeasurementsLengthSummationSequence, 0x00221212, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthMeasurementsLengthSummationSequence;
    /** OphthalmicAxialLengthMeasurementsSegmentalLengthSequence, 0x00221211, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthMeasurementsSegmentalLengthSequence;
    /** OphthalmicAxialLengthMeasurementsSegmentNameCodeSequence, 0x00221101, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthMeasurementsSegmentNameCodeSequence;
    /** OphthalmicAxialLengthMeasurementsSequence, 0x00221050, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthMeasurementsSequence;
    /** OphthalmicAxialLengthMeasurementsTotalLengthSequence, 0x00221210, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthMeasurementsTotalLengthSequence;
    /** OphthalmicAxialLengthMeasurementsType, 0x00221010, CS, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthMeasurementsType;
    /** OphthalmicAxialLengthMethod, 0x00221515, CS, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthMethod;
    /** OphthalmicAxialLengthQualityMetricSequence, 0x00221262, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthQualityMetricSequence;
    /** OphthalmicAxialLengthQualityMetricTypeCodeSequence, 0x00221265, SQ, 1, RET */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthQualityMetricTypeCodeSequence;
    /** OphthalmicAxialLengthQualityMetricTypeDescription, 0x00221273, LO, 1, RET */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthQualityMetricTypeDescription;
    /** OphthalmicAxialLengthSelectionMethodCodeSequence, 0x00221250, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthSelectionMethodCodeSequence;
    /** OphthalmicAxialLengthSequence, 0x00221012, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthSequence;
    /** OphthalmicAxialLengthVelocity, 0x00221059, FL, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialLengthVelocity;
    /** OphthalmicAxialMeasurementsDeviceType, 0x00221009, CS, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialMeasurementsDeviceType;
    /** OphthalmicAxialMeasurementsLeftEyeSequence, 0x00221008, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialMeasurementsLeftEyeSequence;
    /** OphthalmicAxialMeasurementsRightEyeSequence, 0x00221007, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicAxialMeasurementsRightEyeSequence;
    /** OphthalmicEnFaceImageQualityRatingSequence, 0x00221628, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicEnFaceImageQualityRatingSequence;
    /** OphthalmicFOV, 0x00221517, FL, 1 */
    extern DICOM_EXPORT const tag OphthalmicFOV;
    /** OphthalmicFrameLocationSequence, 0x00220031, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicFrameLocationSequence;
    /** OphthalmicImageOrientation, 0x00220039, CS, 1 */
    extern DICOM_EXPORT const tag OphthalmicImageOrientation;
    /** OphthalmicImageTypeCodeSequence, 0x00221615, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicImageTypeCodeSequence;
    /** OphthalmicImageTypeDescription, 0x00221616, LO, 1 */
    extern DICOM_EXPORT const tag OphthalmicImageTypeDescription;
    /** OphthalmicMappingDeviceType, 0x00221415, CS, 1 */
    extern DICOM_EXPORT const tag OphthalmicMappingDeviceType;
    /** OphthalmicPatientClinicalInformationLeftEyeSequence, 0x00240114, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicPatientClinicalInformationLeftEyeSequence;
    /** OphthalmicPatientClinicalInformationRightEyeSequence, 0x00240115, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicPatientClinicalInformationRightEyeSequence;
    /** OphthalmicThicknessMappingNormalsSequence, 0x00221443, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicThicknessMappingNormalsSequence;
    /** OphthalmicThicknessMapQualityRatingSequence, 0x00221470, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicThicknessMapQualityRatingSequence;
    /** OphthalmicThicknessMapQualityThresholdSequence, 0x00221458, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicThicknessMapQualityThresholdSequence;
    /** OphthalmicThicknessMapThresholdQualityRating, 0x00221460, FL, 1 */
    extern DICOM_EXPORT const tag OphthalmicThicknessMapThresholdQualityRating;
    /** OphthalmicThicknessMapTypeCodeSequence, 0x00221436, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicThicknessMapTypeCodeSequence;
    /** OphthalmicUltrasoundMethodCodeSequence, 0x00221044, SQ, 1 */
    extern DICOM_EXPORT const tag OphthalmicUltrasoundMethodCodeSequence;
    /** OphthalmicVolumetricPropertiesFlag, 0x00221622, CS, 1 */
    extern DICOM_EXPORT const tag OphthalmicVolumetricPropertiesFlag;
    /** OpticalOphthalmicAxialLengthMeasurementsSequence, 0x00221225, SQ, 1 */
    extern DICOM_EXPORT const tag OpticalOphthalmicAxialLengthMeasurementsSequence;
    /** OpticalPathDescription, 0x00480107, ST, 1 */
    extern DICOM_EXPORT const tag OpticalPathDescription;
    /** OpticalPathIdentificationSequence, 0x00480207, SQ, 1 */
    extern DICOM_EXPORT const tag OpticalPathIdentificationSequence;
    /** OpticalPathIdentifier, 0x00480106, SH, 1 */
    extern DICOM_EXPORT const tag OpticalPathIdentifier;
    /** OpticalPathSequence, 0x00480105, SQ, 1 */
    extern DICOM_EXPORT const tag OpticalPathSequence;
    /** OpticalSelectedOphthalmicAxialLengthSequence, 0x00221255, SQ, 1 */
    extern DICOM_EXPORT const tag OpticalSelectedOphthalmicAxialLengthSequence;
    /** OpticalTransmittance, 0x00460040, FD, 1 */
    extern DICOM_EXPORT const tag OpticalTransmittance;
    /** Optotype, 0x00460094, CS, 1 */
    extern DICOM_EXPORT const tag Optotype;
    /** OptotypeDetailedDefinition, 0x00460139, LO, 1 */
    extern DICOM_EXPORT const tag OptotypeDetailedDefinition;
    /** OptotypePresentation, 0x00460095, CS, 1 */
    extern DICOM_EXPORT const tag OptotypePresentation;
    /** OrderCallbackPhoneNumber, 0x00402010, SH, 1 */
    extern DICOM_EXPORT const tag OrderCallbackPhoneNumber;
    /** OrderCallbackTelecomInformation, 0x00402011, LT, 1 */
    extern DICOM_EXPORT const tag OrderCallbackTelecomInformation;
    /** OrderEnteredBy, 0x00402008, PN, 1 */
    extern DICOM_EXPORT const tag OrderEnteredBy;
    /** OrderEntererLocation, 0x00402009, SH, 1 */
    extern DICOM_EXPORT const tag OrderEntererLocation;
    /** OrderFillerIdentifierSequence, 0x00400027, SQ, 1 */
    extern DICOM_EXPORT const tag OrderFillerIdentifierSequence;
    /** OrderPlacerIdentifierSequence, 0x00400026, SQ, 1 */
    extern DICOM_EXPORT const tag OrderPlacerIdentifierSequence;
    /** OrganAtRiskFullVolumeDose, 0x300A002A, DS, 1 */
    extern DICOM_EXPORT const tag OrganAtRiskFullVolumeDose;
    /** OrganAtRiskLimitDose, 0x300A002B, DS, 1 */
    extern DICOM_EXPORT const tag OrganAtRiskLimitDose;
    /** OrganAtRiskMaximumDose, 0x300A002C, DS, 1 */
    extern DICOM_EXPORT const tag OrganAtRiskMaximumDose;
    /** OrganAtRiskOverdoseVolumeFraction, 0x300A002D, DS, 1 */
    extern DICOM_EXPORT const tag OrganAtRiskOverdoseVolumeFraction;
    /** OrganDose, 0x00400316, DS, 1 */
    extern DICOM_EXPORT const tag OrganDose;
    /** OrganExposed, 0x00400318, CS, 1 */
    extern DICOM_EXPORT const tag OrganExposed;
    /** OrganizationalRoleCodeSequence, 0x0044010A, SQ, 1 */
    extern DICOM_EXPORT const tag OrganizationalRoleCodeSequence;
    /** OriginalAttributesSequence, 0x04000561, SQ, 1 */
    extern DICOM_EXPORT const tag OriginalAttributesSequence;
    /** OriginalImageIdentification, 0x00205000, AT, 1, RET */
    extern DICOM_EXPORT const tag OriginalImageIdentification;
    /** OriginalImageIdentificationNomenclature, 0x00205002, LO, 1, RET */
    extern DICOM_EXPORT const tag OriginalImageIdentificationNomenclature;
    /** OriginalImageSequence, 0x213000C0, SQ, 1, RET */
    extern DICOM_EXPORT const tag OriginalImageSequence;
    /** OriginalImplantAssemblyTemplateSequence, 0x0076000C, SQ, 1 */
    extern DICOM_EXPORT const tag OriginalImplantAssemblyTemplateSequence;
    /** OriginalImplantTemplateSequence, 0x00686225, SQ, 1 */
    extern DICOM_EXPORT const tag OriginalImplantTemplateSequence;
    /** OriginalSpecializedSOPClassUID, 0x0008001B, UI, 1 */
    extern DICOM_EXPORT const tag OriginalSpecializedSOPClassUID;
    /** Originator, 0x21000070, AE, 1 */
    extern DICOM_EXPORT const tag Originator;
    /** OtherApprovalStatus, 0x00140107, CS, 1, RET */
    extern DICOM_EXPORT const tag OtherApprovalStatus;
    /** OtherFailuresSequence, 0x0008119A, SQ, 1 */
    extern DICOM_EXPORT const tag OtherFailuresSequence;
    /** OtherMagnificationTypesAvailable, 0x201000A7, CS, 1 */
    extern DICOM_EXPORT const tag OtherMagnificationTypesAvailable;
    /** OtherMediaAvailableSequence, 0x200000A4, SQ, 1 */
    extern DICOM_EXPORT const tag OtherMediaAvailableSequence;
    /** OtherPatientIDs, 0x00101000, LO, 1, RET */
    extern DICOM_EXPORT const tag OtherPatientIDs;
    /** OtherPatientIDsSequence, 0x00101002, SQ, 1 */
    extern DICOM_EXPORT const tag OtherPatientIDsSequence;
    /** OtherPatientNames, 0x00101001, PN, 1 */
    extern DICOM_EXPORT const tag OtherPatientNames;
    /** OtherPupillaryDistance, 0x00460064, FD, 1 */
    extern DICOM_EXPORT const tag OtherPupillaryDistance;
    /** OtherSecondaryApprovalStatus, 0x00140108, CS, 1, RET */
    extern DICOM_EXPORT const tag OtherSecondaryApprovalStatus;
    /** OtherSmoothingTypesAvailable, 0x201000A9, CS, 1 */
    extern DICOM_EXPORT const tag OtherSmoothingTypesAvailable;
    /** OtherStudyNumbers, 0x00201070, IS, 1, RET */
    extern DICOM_EXPORT const tag OtherStudyNumbers;
    /** OuterDiameter, 0x00140054, DS, 1, RET */
    extern DICOM_EXPORT const tag OuterDiameter;
    /** OutputDestinationSequence, 0x00404070, SQ, 1 */
    extern DICOM_EXPORT const tag OutputDestinationSequence;
    /** OutputInformationSequence, 0x00404033, SQ, 1 */
    extern DICOM_EXPORT const tag OutputInformationSequence;
    /** OutputPower, 0x00185000, SH, 1 */
    extern DICOM_EXPORT const tag OutputPower;
    /** OverallTemplateSpatialTolerance, 0x006862A5, FD, 1 */
    extern DICOM_EXPORT const tag OverallTemplateSpatialTolerance;
    /** OverlayActivationLayer, 0x60001001, CS, 1 */
    extern DICOM_EXPORT const range_tag OverlayActivationLayer;
    /** OverlayBackgroundDensity, 0x20400082, CS, 1, RET */
    extern DICOM_EXPORT const tag OverlayBackgroundDensity;
    /** OverlayBitPosition, 0x60000102, US, 1 */
    extern DICOM_EXPORT const range_tag OverlayBitPosition;
    /** OverlayBitsAllocated, 0x60000100, US, 1 */
    extern DICOM_EXPORT const range_tag OverlayBitsAllocated;
    /** OverlayBitsForCodeWord, 0x60000804, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayBitsForCodeWord;
    /** OverlayBitsGrouped, 0x60000069, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayBitsGrouped;
    /** OverlayCodeLabel, 0x60000800, CS, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayCodeLabel;
    /** OverlayCodeTableLocation, 0x60000803, AT, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayCodeTableLocation;
    /** OverlayColumns, 0x60000011, US, 1 */
    extern DICOM_EXPORT const range_tag OverlayColumns;
    /** OverlayComments, 0x60004000, LT, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayComments;
    /** OverlayCompressionCode, 0x60000060, CS, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayCompressionCode;
    /** OverlayCompressionDescription, 0x60000063, CS, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayCompressionDescription;
    /** OverlayCompressionLabel, 0x60000062, SH, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayCompressionLabel;
    /** OverlayCompressionOriginator, 0x60000061, SH, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayCompressionOriginator;
    /** OverlayCompressionStepPointers, 0x60000066, AT, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayCompressionStepPointers;
    /** OverlayData, 0x60003000, OB or OW, 1 */
    extern DICOM_EXPORT const range_tag OverlayData;
    /** OverlayDate, 0x00080024, DA, 1, RET */
    extern DICOM_EXPORT const tag OverlayDate;
    /** OverlayDescription, 0x60000022, LO, 1 */
    extern DICOM_EXPORT const range_tag OverlayDescription;
    /** OverlayDescriptorBlue, 0x60001103, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayDescriptorBlue;
    /** OverlayDescriptorGray, 0x60001100, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayDescriptorGray;
    /** OverlayDescriptorGreen, 0x60001102, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayDescriptorGreen;
    /** OverlayDescriptorRed, 0x60001101, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayDescriptorRed;
    /** OverlayForegroundDensity, 0x20400080, CS, 1, RET */
    extern DICOM_EXPORT const tag OverlayForegroundDensity;
    /** OverlayFormat, 0x60000110, CS, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayFormat;
    /** OverlayLabel, 0x60001500, LO, 1 */
    extern DICOM_EXPORT const range_tag OverlayLabel;
    /** OverlayLocation, 0x60000200, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayLocation;
    /** OverlayMagnificationType, 0x20400060, CS, 1, RET */
    extern DICOM_EXPORT const tag OverlayMagnificationType;
    /** OverlayMode, 0x20400090, CS, 1, RET */
    extern DICOM_EXPORT const tag OverlayMode;
    /** OverlayNumber, 0x00200022, IS, 1, RET */
    extern DICOM_EXPORT const tag OverlayNumber;
    /** OverlayNumberOfTables, 0x60000802, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayNumberOfTables;
    /** OverlayOrigin, 0x60000050, SS, 2 */
    extern DICOM_EXPORT const range_tag OverlayOrigin;
    /** OverlayOrImageMagnification, 0x20400072, CS, 1, RET */
    extern DICOM_EXPORT const tag OverlayOrImageMagnification;
    /** OverlayPixelDataSequence, 0x20400020, SQ, 1, RET */
    extern DICOM_EXPORT const tag OverlayPixelDataSequence;
    /** OverlayPlaneOrigin, 0x60000052, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayPlaneOrigin;
    /** OverlayPlanes, 0x60000012, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayPlanes;
    /** OverlayRepeatInterval, 0x60000068, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlayRepeatInterval;
    /** OverlayRows, 0x60000010, US, 1 */
    extern DICOM_EXPORT const range_tag OverlayRows;
    /** OverlaysBlue, 0x60001203, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlaysBlue;
    /** OverlaysGray, 0x60001200, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlaysGray;
    /** OverlaysGreen, 0x60001202, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlaysGreen;
    /** OverlaySmoothingType, 0x20400070, CS, 1, RET */
    extern DICOM_EXPORT const tag OverlaySmoothingType;
    /** OverlaysRed, 0x60001201, US, 1, RET */
    extern DICOM_EXPORT const range_tag OverlaysRed;
    /** OverlaySubtype, 0x60000045, LO, 1 */
    extern DICOM_EXPORT const range_tag OverlaySubtype;
    /** OverlayTime, 0x00080034, TM, 1, RET */
    extern DICOM_EXPORT const tag OverlayTime;
    /** OverlayType, 0x60000040, CS, 1 */
    extern DICOM_EXPORT const range_tag OverlayType;
    /** OverriddenAttributesSequence, 0x0074104A, SQ, 1 */
    extern DICOM_EXPORT const tag OverriddenAttributesSequence;
    /** OverrideParameterPointer, 0x30080062, AT, 1 */
    extern DICOM_EXPORT const tag OverrideParameterPointer;
    /** OverrideReason, 0x30080066, ST, 1 */
    extern DICOM_EXPORT const tag OverrideReason;
    /** OverrideSequence, 0x30080060, SQ, 1 */
    extern DICOM_EXPORT const tag OverrideSequence;
    /** OversamplingPhase, 0x00189029, CS, 1 */
    extern DICOM_EXPORT const tag OversamplingPhase;
    /** OwnerID, 0x21000160, SH, 1 */
    extern DICOM_EXPORT const tag OwnerID;
    /** PaddleDescription, 0x001811A4, LO, 1 */
    extern DICOM_EXPORT const tag PaddleDescription;
    /** PageNumberVector, 0x00182001, IS, 1 */
    extern DICOM_EXPORT const tag PageNumberVector;
    /** PaletteColorLookupTableSequence, 0x00480120, SQ, 1 */
    extern DICOM_EXPORT const tag PaletteColorLookupTableSequence;
    /** PaletteColorLookupTableUID, 0x00281199, UI, 1 */
    extern DICOM_EXPORT const tag PaletteColorLookupTableUID;
    /** ParallelAcquisition, 0x00189077, CS, 1 */
    extern DICOM_EXPORT const tag ParallelAcquisition;
    /** ParallelAcquisitionTechnique, 0x00189078, CS, 1 */
    extern DICOM_EXPORT const tag ParallelAcquisitionTechnique;
    /** ParallelReductionFactorInPlane, 0x00189069, FD, 1 */
    extern DICOM_EXPORT const tag ParallelReductionFactorInPlane;
    /** ParallelReductionFactorInPlaneRetired, 0x00189096, FD, 1, RET */
    extern DICOM_EXPORT const tag ParallelReductionFactorInPlaneRetired;
    /** ParallelReductionFactorOutOfPlane, 0x00189155, FD, 1 */
    extern DICOM_EXPORT const tag ParallelReductionFactorOutOfPlane;
    /** ParallelReductionFactorSecondInPlane, 0x00189168, FD, 1 */
    extern DICOM_EXPORT const tag ParallelReductionFactorSecondInPlane;
    /** ParameterItemIndex, 0x30080063, IS, 1 */
    extern DICOM_EXPORT const tag ParameterItemIndex;
    /** ParameterPointer, 0x30080065, AT, 1 */
    extern DICOM_EXPORT const tag ParameterPointer;
    /** ParameterSequencePointer, 0x30080061, AT, 1 */
    extern DICOM_EXPORT const tag ParameterSequencePointer;
    /** ParametersSpecificationSequence, 0x00189913, SQ, 1 */
    extern DICOM_EXPORT const tag ParametersSpecificationSequence;
    /** ParameterValueNumber, 0x30080067, US, 1 */
    extern DICOM_EXPORT const tag ParameterValueNumber;
    /** ParametricMapFrameTypeSequence, 0x00409092, SQ, 1 */
    extern DICOM_EXPORT const tag ParametricMapFrameTypeSequence;
    /** PartialDataDisplayHandling, 0x00720208, CS, 1 */
    extern DICOM_EXPORT const tag PartialDataDisplayHandling;
    /** PartialFourier, 0x00189081, CS, 1 */
    extern DICOM_EXPORT const tag PartialFourier;
    /** PartialFourierDirection, 0x00189036, CS, 1 */
    extern DICOM_EXPORT const tag PartialFourierDirection;
    /** PartialView, 0x00281350, CS, 1 */
    extern DICOM_EXPORT const tag PartialView;
    /** PartialViewCodeSequence, 0x00281352, SQ, 1 */
    extern DICOM_EXPORT const tag PartialViewCodeSequence;
    /** PartialViewDescription, 0x00281351, ST, 1 */
    extern DICOM_EXPORT const tag PartialViewDescription;
    /** ParticipantSequence, 0x0040A07A, SQ, 1 */
    extern DICOM_EXPORT const tag ParticipantSequence;
    /** ParticipationDateTime, 0x0040A082, DT, 1 */
    extern DICOM_EXPORT const tag ParticipationDateTime;
    /** ParticipationType, 0x0040A080, CS, 1 */
    extern DICOM_EXPORT const tag ParticipationType;
    /** PatientAdditionalPosition, 0x300A0184, LO, 1 */
    extern DICOM_EXPORT const tag PatientAdditionalPosition;
    /** PatientAddress, 0x00101040, LO, 1 */
    extern DICOM_EXPORT const tag PatientAddress;
    /** PatientAge, 0x00101010, AS, 1 */
    extern DICOM_EXPORT const tag PatientAge;
    /** PatientAlternativeCalendar, 0x00100035, CS, 1 */
    extern DICOM_EXPORT const tag PatientAlternativeCalendar;
    /** PatientBirthDate, 0x00100030, DA, 1 */
    extern DICOM_EXPORT const tag PatientBirthDate;
    /** PatientBirthDateInAlternativeCalendar, 0x00100033, LO, 1 */
    extern DICOM_EXPORT const tag PatientBirthDateInAlternativeCalendar;
    /** PatientBirthName, 0x00101005, PN, 1 */
    extern DICOM_EXPORT const tag PatientBirthName;
    /** PatientBirthTime, 0x00100032, TM, 1 */
    extern DICOM_EXPORT const tag PatientBirthTime;
    /** PatientBodyMassIndex, 0x00101022, DS, 1 */
    extern DICOM_EXPORT const tag PatientBodyMassIndex;
    /** PatientBreedCodeSequence, 0x00102293, SQ, 1 */
    extern DICOM_EXPORT const tag PatientBreedCodeSequence;
    /** PatientBreedDescription, 0x00102292, LO, 1 */
    extern DICOM_EXPORT const tag PatientBreedDescription;
    /** PatientClinicalTrialParticipationSequence, 0x00380502, SQ, 1 */
    extern DICOM_EXPORT const tag PatientClinicalTrialParticipationSequence;
    /** PatientComments, 0x00104000, LT, 1 */
    extern DICOM_EXPORT const tag PatientComments;
    /** PatientDeathDateInAlternativeCalendar, 0x00100034, LO, 1 */
    extern DICOM_EXPORT const tag PatientDeathDateInAlternativeCalendar;
    /** PatientEyeMovementCommandCodeSequence, 0x00220006, SQ, 1 */
    extern DICOM_EXPORT const tag PatientEyeMovementCommandCodeSequence;
    /** PatientEyeMovementCommanded, 0x00220005, CS, 1 */
    extern DICOM_EXPORT const tag PatientEyeMovementCommanded;
    /** PatientFrameOfReferenceSource, 0x0020930C, CS, 1 */
    extern DICOM_EXPORT const tag PatientFrameOfReferenceSource;
    /** PatientGantryRelationshipCodeSequence, 0x00540414, SQ, 1 */
    extern DICOM_EXPORT const tag PatientGantryRelationshipCodeSequence;
    /** PatientID, 0x00100020, LO, 1 */
    extern DICOM_EXPORT const tag PatientID;
    /** PatientIdentityRemoved, 0x00120062, CS, 1 */
    extern DICOM_EXPORT const tag PatientIdentityRemoved;
    /** PatientInstitutionResidence, 0x00380400, LO, 1 */
    extern DICOM_EXPORT const tag PatientInstitutionResidence;
    /** PatientInsurancePlanCodeSequence, 0x00100050, SQ, 1 */
    extern DICOM_EXPORT const tag PatientInsurancePlanCodeSequence;
    /** PatientMotherBirthName, 0x00101060, PN, 1 */
    extern DICOM_EXPORT const tag PatientMotherBirthName;
    /** PatientMotionCorrected, 0x00189763, CS, 1 */
    extern DICOM_EXPORT const tag PatientMotionCorrected;
    /** PatientName, 0x00100010, PN, 1 */
    extern DICOM_EXPORT const tag PatientName;
    /** PatientNotProperlyFixatedQuantity, 0x00240036, US, 1 */
    extern DICOM_EXPORT const tag PatientNotProperlyFixatedQuantity;
    /** PatientOrientation, 0x00200020, CS, 2 */
    extern DICOM_EXPORT const tag PatientOrientation;
    /** PatientOrientationCodeSequence, 0x00540410, SQ, 1 */
    extern DICOM_EXPORT const tag PatientOrientationCodeSequence;
    /** PatientOrientationInFrameSequence, 0x00209450, SQ, 1 */
    extern DICOM_EXPORT const tag PatientOrientationInFrameSequence;
    /** PatientOrientationModifierCodeSequence, 0x00540412, SQ, 1 */
    extern DICOM_EXPORT const tag PatientOrientationModifierCodeSequence;
    /** PatientPhysiologicalStateCodeSequence, 0x00189772, SQ, 1 */
    extern DICOM_EXPORT const tag PatientPhysiologicalStateCodeSequence;
    /** PatientPhysiologicalStateSequence, 0x00189771, SQ, 1 */
    extern DICOM_EXPORT const tag PatientPhysiologicalStateSequence;
    /** PatientPosition, 0x00185100, CS, 1 */
    extern DICOM_EXPORT const tag PatientPosition;
    /** PatientPositioningInstructionSequence, 0x0018991B, SQ, 1 */
    extern DICOM_EXPORT const tag PatientPositioningInstructionSequence;
    /** PatientPrimaryLanguageCodeSequence, 0x00100101, SQ, 1 */
    extern DICOM_EXPORT const tag PatientPrimaryLanguageCodeSequence;
    /** PatientPrimaryLanguageModifierCodeSequence, 0x00100102, SQ, 1 */
    extern DICOM_EXPORT const tag PatientPrimaryLanguageModifierCodeSequence;
    /** PatientReliabilityIndicator, 0x00240069, LO, 1 */
    extern DICOM_EXPORT const tag PatientReliabilityIndicator;
    /** PatientReligiousPreference, 0x001021F0, LO, 1 */
    extern DICOM_EXPORT const tag PatientReligiousPreference;
    /** PatientSetupLabel, 0x300A0183, LO, 1 */
    extern DICOM_EXPORT const tag PatientSetupLabel;
    /** PatientSetupNumber, 0x300A0182, IS, 1 */
    extern DICOM_EXPORT const tag PatientSetupNumber;
    /** PatientSetupSequence, 0x300A0180, SQ, 1 */
    extern DICOM_EXPORT const tag PatientSetupSequence;
    /** PatientSex, 0x00100040, CS, 1 */
    extern DICOM_EXPORT const tag PatientSex;
    /** PatientSexNeutered, 0x00102203, CS, 1 */
    extern DICOM_EXPORT const tag PatientSexNeutered;
    /** PatientSize, 0x00101020, DS, 1 */
    extern DICOM_EXPORT const tag PatientSize;
    /** PatientSizeCodeSequence, 0x00101021, SQ, 1 */
    extern DICOM_EXPORT const tag PatientSizeCodeSequence;
    /** PatientSpeciesCodeSequence, 0x00102202, SQ, 1 */
    extern DICOM_EXPORT const tag PatientSpeciesCodeSequence;
    /** PatientSpeciesDescription, 0x00102201, LO, 1 */
    extern DICOM_EXPORT const tag PatientSpeciesDescription;
    /** PatientSpecificationSequence, 0x00189911, SQ, 1 */
    extern DICOM_EXPORT const tag PatientSpecificationSequence;
    /** PatientState, 0x00380500, LO, 1 */
    extern DICOM_EXPORT const tag PatientState;
    /** PatientSupportAccessoryCode, 0x300A0354, LO, 1 */
    extern DICOM_EXPORT const tag PatientSupportAccessoryCode;
    /** PatientSupportAdjustedAngle, 0x0074102A, FD, 1 */
    extern DICOM_EXPORT const tag PatientSupportAdjustedAngle;
    /** PatientSupportAngle, 0x300A0122, DS, 1 */
    extern DICOM_EXPORT const tag PatientSupportAngle;
    /** PatientSupportAngleTolerance, 0x300A004C, DS, 1 */
    extern DICOM_EXPORT const tag PatientSupportAngleTolerance;
    /** PatientSupportID, 0x300A0352, SH, 1 */
    extern DICOM_EXPORT const tag PatientSupportID;
    /** PatientSupportRotationDirection, 0x300A0123, CS, 1 */
    extern DICOM_EXPORT const tag PatientSupportRotationDirection;
    /** PatientSupportType, 0x300A0350, CS, 1 */
    extern DICOM_EXPORT const tag PatientSupportType;
    /** PatientTelecomInformation, 0x00102155, LT, 1 */
    extern DICOM_EXPORT const tag PatientTelecomInformation;
    /** PatientTelephoneNumbers, 0x00102154, SH, 1 */
    extern DICOM_EXPORT const tag PatientTelephoneNumbers;
    /** PatientTransportArrangements, 0x00401004, LO, 1 */
    extern DICOM_EXPORT const tag PatientTransportArrangements;
    /** PatientWeight, 0x00101030, DS, 1 */
    extern DICOM_EXPORT const tag PatientWeight;
    /** PatternOffColorCIELabValue, 0x00700252, US, 3 */
    extern DICOM_EXPORT const tag PatternOffColorCIELabValue;
    /** PatternOffOpacity, 0x00700285, FL, 1 */
    extern DICOM_EXPORT const tag PatternOffOpacity;
    /** PatternOnColorCIELabValue, 0x00700251, US, 3 */
    extern DICOM_EXPORT const tag PatternOnColorCIELabValue;
    /** PatternOnOpacity, 0x00700284, FL, 1 */
    extern DICOM_EXPORT const tag PatternOnOpacity;
    /** PauseBetweenFrames, 0x00540038, IS, 1 */
    extern DICOM_EXPORT const tag PauseBetweenFrames;
    /** PercentPhaseFieldOfView, 0x00180094, DS, 1 */
    extern DICOM_EXPORT const tag PercentPhaseFieldOfView;
    /** PercentSampling, 0x00180093, DS, 1 */
    extern DICOM_EXPORT const tag PercentSampling;
    /** PerformedLocation, 0x00400243, SH, 1 */
    extern DICOM_EXPORT const tag PerformedLocation;
    /** PerformedProcedureCodeSequence, 0x0040A372, SQ, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureCodeSequence;
    /** PerformedProcedureStepDescription, 0x00400254, LO, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepDescription;
    /** PerformedProcedureStepDiscontinuationReasonCodeSequence, 0x00400281, SQ, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepDiscontinuationReasonCodeSequence;
    /** PerformedProcedureStepEndDate, 0x00400250, DA, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepEndDate;
    /** PerformedProcedureStepEndDateTime, 0x00404051, DT, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepEndDateTime;
    /** PerformedProcedureStepEndTime, 0x00400251, TM, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepEndTime;
    /** PerformedProcedureStepID, 0x00400253, SH, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepID;
    /** PerformedProcedureStepStartDate, 0x00400244, DA, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepStartDate;
    /** PerformedProcedureStepStartDateTime, 0x00404050, DT, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepStartDateTime;
    /** PerformedProcedureStepStartTime, 0x00400245, TM, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepStartTime;
    /** PerformedProcedureStepStatus, 0x00400252, CS, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureStepStatus;
    /** PerformedProcedureTypeDescription, 0x00400255, LO, 1 */
    extern DICOM_EXPORT const tag PerformedProcedureTypeDescription;
    /** PerformedProcessingApplicationsCodeSequence, 0x00404007, SQ, 1, RET */
    extern DICOM_EXPORT const tag PerformedProcessingApplicationsCodeSequence;
    /** PerformedProcessingParametersSequence, 0x00741212, SQ, 1 */
    extern DICOM_EXPORT const tag PerformedProcessingParametersSequence;
    /** PerformedProtocolCodeSequence, 0x00400260, SQ, 1 */
    extern DICOM_EXPORT const tag PerformedProtocolCodeSequence;
    /** PerformedProtocolType, 0x00400261, CS, 1 */
    extern DICOM_EXPORT const tag PerformedProtocolType;
    /** PerformedSeriesSequence, 0x00400340, SQ, 1 */
    extern DICOM_EXPORT const tag PerformedSeriesSequence;
    /** PerformedStationAETitle, 0x00400241, AE, 1 */
    extern DICOM_EXPORT const tag PerformedStationAETitle;
    /** PerformedStationClassCodeSequence, 0x00404029, SQ, 1 */
    extern DICOM_EXPORT const tag PerformedStationClassCodeSequence;
    /** PerformedStationGeographicLocationCodeSequence, 0x00404030, SQ, 1 */
    extern DICOM_EXPORT const tag PerformedStationGeographicLocationCodeSequence;
    /** PerformedStationName, 0x00400242, SH, 1 */
    extern DICOM_EXPORT const tag PerformedStationName;
    /** PerformedStationNameCodeSequence, 0x00404028, SQ, 1 */
    extern DICOM_EXPORT const tag PerformedStationNameCodeSequence;
    /** PerformedWorkitemCodeSequence, 0x00404019, SQ, 1 */
    extern DICOM_EXPORT const tag PerformedWorkitemCodeSequence;
    /** PerformingPhysicianIdentificationSequence, 0x00081052, SQ, 1 */
    extern DICOM_EXPORT const tag PerformingPhysicianIdentificationSequence;
    /** PerformingPhysicianName, 0x00081050, PN, 1 */
    extern DICOM_EXPORT const tag PerformingPhysicianName;
    /** PerFrameFunctionalGroupsSequence, 0x52009230, SQ, 1 */
    extern DICOM_EXPORT const tag PerFrameFunctionalGroupsSequence;
    /** PerimeterTable, 0x00280070, US, 1, RET */
    extern DICOM_EXPORT const tag PerimeterTable;
    /** PerimeterValue, 0x00280071, US or SS, 1, RET */
    extern DICOM_EXPORT const tag PerimeterValue;
    /** PerProjectionAcquisitionSequence, 0x00189538, SQ, 1 */
    extern DICOM_EXPORT const tag PerProjectionAcquisitionSequence;
    /** PersonAddress, 0x00401102, ST, 1 */
    extern DICOM_EXPORT const tag PersonAddress;
    /** PersonIdentificationCodeSequence, 0x00401101, SQ, 1 */
    extern DICOM_EXPORT const tag PersonIdentificationCodeSequence;
    /** PersonName, 0x0040A123, PN, 1 */
    extern DICOM_EXPORT const tag PersonName;
    /** PersonTelecomInformation, 0x00401104, LT, 1 */
    extern DICOM_EXPORT const tag PersonTelecomInformation;
    /** PersonTelephoneNumbers, 0x00401103, LO, 1 */
    extern DICOM_EXPORT const tag PersonTelephoneNumbers;
    /** PertinentDocumentsSequence, 0x00380100, SQ, 1 */
    extern DICOM_EXPORT const tag PertinentDocumentsSequence;
    /** PertinentOtherEvidenceSequence, 0x0040A385, SQ, 1 */
    extern DICOM_EXPORT const tag PertinentOtherEvidenceSequence;
    /** PertinentResourcesSequence, 0x00380101, SQ, 1 */
    extern DICOM_EXPORT const tag PertinentResourcesSequence;
    /** PETDetectorMotionDetailsSequence, 0x00189733, SQ, 1 */
    extern DICOM_EXPORT const tag PETDetectorMotionDetailsSequence;
    /** PETFrameAcquisitionSequence, 0x00189732, SQ, 1 */
    extern DICOM_EXPORT const tag PETFrameAcquisitionSequence;
    /** PETFrameCorrectionFactorsSequence, 0x00189736, SQ, 1 */
    extern DICOM_EXPORT const tag PETFrameCorrectionFactorsSequence;
    /** PETFrameTypeSequence, 0x00189751, SQ, 1 */
    extern DICOM_EXPORT const tag PETFrameTypeSequence;
    /** PETPositionSequence, 0x00189735, SQ, 1 */
    extern DICOM_EXPORT const tag PETPositionSequence;
    /** PETReconstructionSequence, 0x00189749, SQ, 1 */
    extern DICOM_EXPORT const tag PETReconstructionSequence;
    /** PETTableDynamicsSequence, 0x00189734, SQ, 1 */
    extern DICOM_EXPORT const tag PETTableDynamicsSequence;
    /** PhantomType, 0x40101046, CS, 1, RET */
    extern DICOM_EXPORT const tag PhantomType;
    /** PhaseContrast, 0x00189014, CS, 1 */
    extern DICOM_EXPORT const tag PhaseContrast;
    /** PhaseDelay, 0x00540036, IS, 1 */
    extern DICOM_EXPORT const tag PhaseDelay;
    /** PhaseDescription, 0x00540039, CS, 1 */
    extern DICOM_EXPORT const tag PhaseDescription;
    /** PhaseInformationSequence, 0x00540032, SQ, 1 */
    extern DICOM_EXPORT const tag PhaseInformationSequence;
    /** PhaseNumber, 0x00200015, IS, 1, RET */
    extern DICOM_EXPORT const tag PhaseNumber;
    /** PhaseVector, 0x00540030, US, 1 */
    extern DICOM_EXPORT const tag PhaseVector;
    /** PhosphorType, 0x00181261, LO, 1 */
    extern DICOM_EXPORT const tag PhosphorType;
    /** PhotometricInterpretation, 0x00280004, CS, 1 */
    extern DICOM_EXPORT const tag PhotometricInterpretation;
    /** PhototimerSetting, 0x00187065, DS, 1 */
    extern DICOM_EXPORT const tag PhototimerSetting;
    /** PhysicalDeltaX, 0x0018602C, FD, 1 */
    extern DICOM_EXPORT const tag PhysicalDeltaX;
    /** PhysicalDeltaY, 0x0018602E, FD, 1 */
    extern DICOM_EXPORT const tag PhysicalDeltaY;
    /** PhysicalDetectorSize, 0x00189429, FL, 2 */
    extern DICOM_EXPORT const tag PhysicalDetectorSize;
    /** PhysicalUnitsXDirection, 0x00186024, US, 1 */
    extern DICOM_EXPORT const tag PhysicalUnitsXDirection;
    /** PhysicalUnitsYDirection, 0x00186026, US, 1 */
    extern DICOM_EXPORT const tag PhysicalUnitsYDirection;
    /** PhysicianApprovingInterpretation, 0x40080114, PN, 1, RET */
    extern DICOM_EXPORT const tag PhysicianApprovingInterpretation;
    /** PhysiciansOfRecord, 0x00081048, PN, 1 */
    extern DICOM_EXPORT const tag PhysiciansOfRecord;
    /** PhysiciansOfRecordIdentificationSequence, 0x00081049, SQ, 1 */
    extern DICOM_EXPORT const tag PhysiciansOfRecordIdentificationSequence;
    /** PhysiciansReadingStudyIdentificationSequence, 0x00081062, SQ, 1 */
    extern DICOM_EXPORT const tag PhysiciansReadingStudyIdentificationSequence;
    /** PixelAspectRatio, 0x00280034, IS, 2 */
    extern DICOM_EXPORT const tag PixelAspectRatio;
    /** PixelBandwidth, 0x00180095, DS, 1 */
    extern DICOM_EXPORT const tag PixelBandwidth;
    /** PixelComponentDataType, 0x0018604E, US, 1 */
    extern DICOM_EXPORT const tag PixelComponentDataType;
    /** PixelComponentMask, 0x00186046, UL, 1 */
    extern DICOM_EXPORT const tag PixelComponentMask;
    /** PixelComponentOrganization, 0x00186044, US, 1 */
    extern DICOM_EXPORT const tag PixelComponentOrganization;
    /** PixelComponentPhysicalUnits, 0x0018604C, US, 1 */
    extern DICOM_EXPORT const tag PixelComponentPhysicalUnits;
    /** PixelComponentRangeStart, 0x00186048, UL, 1 */
    extern DICOM_EXPORT const tag PixelComponentRangeStart;
    /** PixelComponentRangeStop, 0x0018604A, UL, 1 */
    extern DICOM_EXPORT const tag PixelComponentRangeStop;
    /** PixelCoordinatesSetTrial, 0x0040A29A, SL, 2, RET */
    extern DICOM_EXPORT const tag PixelCoordinatesSetTrial;
    /** PixelData, 0x7FE00010, OB or OW, 1 */
    extern DICOM_EXPORT const tag PixelData;
    /** PixelDataAreaOriginRelativeToFOV, 0x00187036, FL, 2 */
    extern DICOM_EXPORT const tag PixelDataAreaOriginRelativeToFOV;
    /** PixelDataAreaRotationAngleRelativeToFOV, 0x00187038, FL, 1 */
    extern DICOM_EXPORT const tag PixelDataAreaRotationAngleRelativeToFOV;
    /** PixelDataProviderURL, 0x00287FE0, UR, 1 */
    extern DICOM_EXPORT const tag PixelDataProviderURL;
    /** PixelIntensityRelationship, 0x00281040, CS, 1 */
    extern DICOM_EXPORT const tag PixelIntensityRelationship;
    /** PixelIntensityRelationshipLUTSequence, 0x00289422, SQ, 1 */
    extern DICOM_EXPORT const tag PixelIntensityRelationshipLUTSequence;
    /** PixelIntensityRelationshipSign, 0x00281041, SS, 1 */
    extern DICOM_EXPORT const tag PixelIntensityRelationshipSign;
    /** PixelMeasuresSequence, 0x00289110, SQ, 1 */
    extern DICOM_EXPORT const tag PixelMeasuresSequence;
    /** PixelOriginInterpretation, 0x00480301, CS, 1 */
    extern DICOM_EXPORT const tag PixelOriginInterpretation;
    /** PixelPaddingRangeLimit, 0x00280121, US or SS, 1 */
    extern DICOM_EXPORT const tag PixelPaddingRangeLimit;
    /** PixelPaddingValue, 0x00280120, US or SS, 1 */
    extern DICOM_EXPORT const tag PixelPaddingValue;
    /** PixelPresentation, 0x00089205, CS, 1 */
    extern DICOM_EXPORT const tag PixelPresentation;
    /** PixelRepresentation, 0x00280103, US, 1 */
    extern DICOM_EXPORT const tag PixelRepresentation;
    /** PixelShiftFrameRange, 0x00289506, US, 2 */
    extern DICOM_EXPORT const tag PixelShiftFrameRange;
    /** PixelShiftSequence, 0x00289501, SQ, 1 */
    extern DICOM_EXPORT const tag PixelShiftSequence;
    /** PixelSpacing, 0x00280030, DS, 2 */
    extern DICOM_EXPORT const tag PixelSpacing;
    /** PixelSpacingCalibrationDescription, 0x00280A04, LO, 1 */
    extern DICOM_EXPORT const tag PixelSpacingCalibrationDescription;
    /** PixelSpacingCalibrationType, 0x00280A02, CS, 1 */
    extern DICOM_EXPORT const tag PixelSpacingCalibrationType;
    /** PixelSpacingSequence, 0x004008D8, SQ, 1, RET */
    extern DICOM_EXPORT const tag PixelSpacingSequence;
    /** PixelValueMappingCodeSequence, 0x00409098, SQ, 1 */
    extern DICOM_EXPORT const tag PixelValueMappingCodeSequence;
    /** PixelValueMappingExplanation, 0x00221454, LO, 1 */
    extern DICOM_EXPORT const tag PixelValueMappingExplanation;
    /** PixelValueMappingToCodedConceptSequence, 0x00221450, SQ, 1 */
    extern DICOM_EXPORT const tag PixelValueMappingToCodedConceptSequence;
    /** PixelValueTransformationSequence, 0x00289145, SQ, 1 */
    extern DICOM_EXPORT const tag PixelValueTransformationSequence;
    /** PlacerOrderNumberImagingServiceRequest, 0x00402016, LO, 1 */
    extern DICOM_EXPORT const tag PlacerOrderNumberImagingServiceRequest;
    /** PlacerOrderNumberImagingServiceRequestRetired, 0x00402006, SH, 1, RET */
    extern DICOM_EXPORT const tag PlacerOrderNumberImagingServiceRequestRetired;
    /** PlacerOrderNumberProcedure, 0x00401006, SH, 1, RET */
    extern DICOM_EXPORT const tag PlacerOrderNumberProcedure;
    /** PlanarConfiguration, 0x00280006, US, 1 */
    extern DICOM_EXPORT const tag PlanarConfiguration;
    /** Plane, 0x00701305, FD, 4 */
    extern DICOM_EXPORT const tag Plane;
    /** PlaneIdentification, 0x00189457, CS, 1 */
    extern DICOM_EXPORT const tag PlaneIdentification;
    /** PlaneNormal, 0x00701306, FD, 3 */
    extern DICOM_EXPORT const tag PlaneNormal;
    /** PlaneOrientationSequence, 0x00209116, SQ, 1 */
    extern DICOM_EXPORT const tag PlaneOrientationSequence;
    /** PlaneOrientationVolumeSequence, 0x0020930F, SQ, 1 */
    extern DICOM_EXPORT const tag PlaneOrientationVolumeSequence;
    /** PlanePositionSequence, 0x00209113, SQ, 1 */
    extern DICOM_EXPORT const tag PlanePositionSequence;
    /** PlanePositionSlideSequence, 0x0048021A, SQ, 1 */
    extern DICOM_EXPORT const tag PlanePositionSlideSequence;
    /** PlanePositionVolumeSequence, 0x0020930E, SQ, 1 */
    extern DICOM_EXPORT const tag PlanePositionVolumeSequence;
    /** Planes, 0x00280012, US, 1, RET */
    extern DICOM_EXPORT const tag Planes;
    /** PlanesInAcquisition, 0x00189410, CS, 1 */
    extern DICOM_EXPORT const tag PlanesInAcquisition;
    /** PlanIntent, 0x300A000A, CS, 1 */
    extern DICOM_EXPORT const tag PlanIntent;
    /** PlannedVerificationImageSequence, 0x300A00CA, SQ, 1 */
    extern DICOM_EXPORT const tag PlannedVerificationImageSequence;
    /** PlanningLandmarkDescription, 0x00686540, LO, 1 */
    extern DICOM_EXPORT const tag PlanningLandmarkDescription;
    /** PlanningLandmarkID, 0x00686530, US, 1 */
    extern DICOM_EXPORT const tag PlanningLandmarkID;
    /** PlanningLandmarkIdentificationCodeSequence, 0x00686545, SQ, 1 */
    extern DICOM_EXPORT const tag PlanningLandmarkIdentificationCodeSequence;
    /** PlanningLandmarkLineSequence, 0x00686510, SQ, 1 */
    extern DICOM_EXPORT const tag PlanningLandmarkLineSequence;
    /** PlanningLandmarkPlaneSequence, 0x00686520, SQ, 1 */
    extern DICOM_EXPORT const tag PlanningLandmarkPlaneSequence;
    /** PlanningLandmarkPointSequence, 0x00686500, SQ, 1 */
    extern DICOM_EXPORT const tag PlanningLandmarkPointSequence;
    /** PlateID, 0x00181004, LO, 1 */
    extern DICOM_EXPORT const tag PlateID;
    /** PlateType, 0x00181260, SH, 1 */
    extern DICOM_EXPORT const tag PlateType;
    /** PointCoordinatesData, 0x00660016, OF, 1 */
    extern DICOM_EXPORT const tag PointCoordinatesData;
    /** PointPositionAccuracy, 0x00660017, FL, 3 */
    extern DICOM_EXPORT const tag PointPositionAccuracy;
    /** PointsBoundingBoxCoordinates, 0x0066001A, FL, 6 */
    extern DICOM_EXPORT const tag PointsBoundingBoxCoordinates;
    /** Polarity, 0x20200020, CS, 1 */
    extern DICOM_EXPORT const tag Polarity;
    /** PositionerIsocenterDetectorRotationAngle, 0x00189465, FL, 1 */
    extern DICOM_EXPORT const tag PositionerIsocenterDetectorRotationAngle;
    /** PositionerIsocenterPrimaryAngle, 0x00189463, FL, 1 */
    extern DICOM_EXPORT const tag PositionerIsocenterPrimaryAngle;
    /** PositionerIsocenterSecondaryAngle, 0x00189464, FL, 1 */
    extern DICOM_EXPORT const tag PositionerIsocenterSecondaryAngle;
    /** PositionerMotion, 0x00181500, CS, 1 */
    extern DICOM_EXPORT const tag PositionerMotion;
    /** PositionerPositionSequence, 0x00189405, SQ, 1 */
    extern DICOM_EXPORT const tag PositionerPositionSequence;
    /** PositionerPrimaryAngle, 0x00181510, DS, 1 */
    extern DICOM_EXPORT const tag PositionerPrimaryAngle;
    /** PositionerPrimaryAngleDirection, 0x00189559, CS, 1 */
    extern DICOM_EXPORT const tag PositionerPrimaryAngleDirection;
    /** PositionerPrimaryAngleIncrement, 0x00181520, DS, 1 */
    extern DICOM_EXPORT const tag PositionerPrimaryAngleIncrement;
    /** PositionerSecondaryAngle, 0x00181511, DS, 1 */
    extern DICOM_EXPORT const tag PositionerSecondaryAngle;
    /** PositionerSecondaryAngleIncrement, 0x00181521, DS, 1 */
    extern DICOM_EXPORT const tag PositionerSecondaryAngleIncrement;
    /** PositionerType, 0x00181508, CS, 1 */
    extern DICOM_EXPORT const tag PositionerType;
    /** PositioningLandmarkSequence, 0x0018991D, SQ, 1 */
    extern DICOM_EXPORT const tag PositioningLandmarkSequence;
    /** PositioningMethodCodeSequence, 0x0018991C, SQ, 1 */
    extern DICOM_EXPORT const tag PositioningMethodCodeSequence;
    /** PositionMeasuringDeviceUsed, 0x0018980C, CS, 1 */
    extern DICOM_EXPORT const tag PositionMeasuringDeviceUsed;
    /** PositionOfIsocenterProjection, 0x00189430, FL, 2 */
    extern DICOM_EXPORT const tag PositionOfIsocenterProjection;
    /** PositionReferenceIndicator, 0x00201040, LO, 1 */
    extern DICOM_EXPORT const tag PositionReferenceIndicator;
    /** PositiveCatchTrialsQuantity, 0x00240056, US, 1 */
    extern DICOM_EXPORT const tag PositiveCatchTrialsQuantity;
    /** PostDeformationMatrixRegistrationSequence, 0x00640010, SQ, 1 */
    extern DICOM_EXPORT const tag PostDeformationMatrixRegistrationSequence;
    /** PostprocessingFunction, 0x00185021, LO, 1, RET */
    extern DICOM_EXPORT const tag PostprocessingFunction;
    /** PotentialDiagnosticTasks, 0x0018990A, UC, 1 */
    extern DICOM_EXPORT const tag PotentialDiagnosticTasks;
    /** PotentialReasonsForProcedure, 0x00189908, UC, 1 */
    extern DICOM_EXPORT const tag PotentialReasonsForProcedure;
    /** PotentialReasonsForProcedureCodeSequence, 0x00189909, SQ, 1 */
    extern DICOM_EXPORT const tag PotentialReasonsForProcedureCodeSequence;
    /** PotentialRequestedProcedureCodeSequence, 0x00189907, SQ, 1 */
    extern DICOM_EXPORT const tag PotentialRequestedProcedureCodeSequence;
    /** PotentialScheduledProtocolCodeSequence, 0x00189906, SQ, 1 */
    extern DICOM_EXPORT const tag PotentialScheduledProtocolCodeSequence;
    /** PotentialThreatObjectID, 0x40101010, US, 1, RET */
    extern DICOM_EXPORT const tag PotentialThreatObjectID;
    /** PRCSToRCSOrientation, 0x4010107E, DS, 6, RET */
    extern DICOM_EXPORT const tag PRCSToRCSOrientation;
    /** PreAmplifierEquipmentSequence, 0x0014400E, SQ, 1, RET */
    extern DICOM_EXPORT const tag PreAmplifierEquipmentSequence;
    /** PreAmplifierNotes, 0x0014400F, LT, 1, RET */
    extern DICOM_EXPORT const tag PreAmplifierNotes;
    /** PreAmplifierSettingsSequence, 0x00144040, SQ, 1, RET */
    extern DICOM_EXPORT const tag PreAmplifierSettingsSequence;
    /** PredecessorDocumentsSequence, 0x0040A360, SQ, 1 */
    extern DICOM_EXPORT const tag PredecessorDocumentsSequence;
    /** PredecessorProtocolSequence, 0x0018990E, SQ, 1 */
    extern DICOM_EXPORT const tag PredecessorProtocolSequence;
    /** PredecessorStructureSetSequence, 0x30060018, SQ, 1 */
    extern DICOM_EXPORT const tag PredecessorStructureSetSequence;
    /** PreDeformationMatrixRegistrationSequence, 0x0064000F, SQ, 1 */
    extern DICOM_EXPORT const tag PreDeformationMatrixRegistrationSequence;
    /** PredictedRefractiveError, 0x00221054, FL, 1 */
    extern DICOM_EXPORT const tag PredictedRefractiveError;
    /** PredictorColumns, 0x00280081, US, 1, RET */
    extern DICOM_EXPORT const tag PredictorColumns;
    /** PredictorConstants, 0x00280082, US, 1, RET */
    extern DICOM_EXPORT const tag PredictorConstants;
    /** PredictorRows, 0x00280080, US, 1, RET */
    extern DICOM_EXPORT const tag PredictorRows;
    /** PreferredPlaybackSequencing, 0x00181244, US, 1 */
    extern DICOM_EXPORT const tag PreferredPlaybackSequencing;
    /** PregnancyStatus, 0x001021C0, US, 1 */
    extern DICOM_EXPORT const tag PregnancyStatus;
    /** PreliminaryFlag, 0x0040A496, CS, 1 */
    extern DICOM_EXPORT const tag PreliminaryFlag;
    /** PreMedication, 0x00400012, LO, 1 */
    extern DICOM_EXPORT const tag PreMedication;
    /** PrescriptionDescription, 0x300A000E, ST, 1 */
    extern DICOM_EXPORT const tag PrescriptionDescription;
    /** PresentationAnimationStyle, 0x00701A01, CS, 1 */
    extern DICOM_EXPORT const tag PresentationAnimationStyle;
    /** PresentationCreationDate, 0x00700082, DA, 1 */
    extern DICOM_EXPORT const tag PresentationCreationDate;
    /** PresentationCreationTime, 0x00700083, TM, 1 */
    extern DICOM_EXPORT const tag PresentationCreationTime;
    /** PresentationDisplayCollectionUID, 0x00701101, UI, 1 */
    extern DICOM_EXPORT const tag PresentationDisplayCollectionUID;
    /** PresentationGroupNumber, 0x003A0241, US, 1 */
    extern DICOM_EXPORT const tag PresentationGroupNumber;
    /** PresentationInputType, 0x00701202, CS, 1 */
    extern DICOM_EXPORT const tag PresentationInputType;
    /** PresentationIntentType, 0x00080068, CS, 1 */
    extern DICOM_EXPORT const tag PresentationIntentType;
    /** PresentationLUTContentSequence, 0x21300080, SQ, 1, RET */
    extern DICOM_EXPORT const tag PresentationLUTContentSequence;
    /** PresentationLUTFlag, 0x20000069, CS, 1, RET */
    extern DICOM_EXPORT const tag PresentationLUTFlag;
    /** PresentationLUTSequence, 0x20500010, SQ, 1 */
    extern DICOM_EXPORT const tag PresentationLUTSequence;
    /** PresentationLUTShape, 0x20500020, CS, 1 */
    extern DICOM_EXPORT const tag PresentationLUTShape;
    /** PresentationPixelAspectRatio, 0x00700102, IS, 2 */
    extern DICOM_EXPORT const tag PresentationPixelAspectRatio;
    /** PresentationPixelMagnificationRatio, 0x00700103, FL, 1 */
    extern DICOM_EXPORT const tag PresentationPixelMagnificationRatio;
    /** PresentationPixelSpacing, 0x00700101, DS, 2 */
    extern DICOM_EXPORT const tag PresentationPixelSpacing;
    /** PresentationSequenceCollectionUID, 0x00701102, UI, 1 */
    extern DICOM_EXPORT const tag PresentationSequenceCollectionUID;
    /** PresentationSequencePositionIndex, 0x00701103, US, 1 */
    extern DICOM_EXPORT const tag PresentationSequencePositionIndex;
    /** PresentationSizeMode, 0x00700100, CS, 1 */
    extern DICOM_EXPORT const tag PresentationSizeMode;
    /** PresentationStateClassificationComponentSequence, 0x00701801, SQ, 1 */
    extern DICOM_EXPORT const tag PresentationStateClassificationComponentSequence;
    /** PresentationStateCompositorComponentSequence, 0x00701805, SQ, 1 */
    extern DICOM_EXPORT const tag PresentationStateCompositorComponentSequence;
    /** PresentedVisualStimuliDataFlag, 0x00240037, CS, 1 */
    extern DICOM_EXPORT const tag PresentedVisualStimuliDataFlag;
    /** PreserveCompositeInstancesAfterMediaCreation, 0x2200000A, CS, 1 */
    extern DICOM_EXPORT const tag PreserveCompositeInstancesAfterMediaCreation;
    /** PrimaryAnatomicStructureModifierSequence, 0x00082230, SQ, 1 */
    extern DICOM_EXPORT const tag PrimaryAnatomicStructureModifierSequence;
    /** PrimaryAnatomicStructureSequence, 0x00082228, SQ, 1 */
    extern DICOM_EXPORT const tag PrimaryAnatomicStructureSequence;
    /** PrimaryDosimeterUnit, 0x300A00B3, CS, 1 */
    extern DICOM_EXPORT const tag PrimaryDosimeterUnit;
    /** PrimaryFluenceModeSequence, 0x30020050, SQ, 1 */
    extern DICOM_EXPORT const tag PrimaryFluenceModeSequence;
    /** PrimaryPositionerIncrement, 0x00189514, FL, 1 */
    extern DICOM_EXPORT const tag PrimaryPositionerIncrement;
    /** PrimaryPositionerIncrementSign, 0x00189518, SS, 1 */
    extern DICOM_EXPORT const tag PrimaryPositionerIncrementSign;
    /** PrimaryPositionerScanArc, 0x00189508, FL, 1 */
    extern DICOM_EXPORT const tag PrimaryPositionerScanArc;
    /** PrimaryPositionerScanStartAngle, 0x00189510, FL, 1 */
    extern DICOM_EXPORT const tag PrimaryPositionerScanStartAngle;
    /** PrimaryPromptsCountsAccumulated, 0x00541310, IS, 1 */
    extern DICOM_EXPORT const tag PrimaryPromptsCountsAccumulated;
    /** PrimitivePointIndexList, 0x00660029, OW, 1, RET */
    extern DICOM_EXPORT const tag PrimitivePointIndexList;
    /** PrinterCharacteristicsSequence, 0x21300015, SQ, 1, RET */
    extern DICOM_EXPORT const tag PrinterCharacteristicsSequence;
    /** PrinterConfigurationSequence, 0x2000001E, SQ, 1 */
    extern DICOM_EXPORT const tag PrinterConfigurationSequence;
    /** PrinterName, 0x21100030, LO, 1 */
    extern DICOM_EXPORT const tag PrinterName;
    /** PrinterPixelSpacing, 0x20100376, DS, 2 */
    extern DICOM_EXPORT const tag PrinterPixelSpacing;
    /** PrinterResolutionID, 0x20100052, CS, 1 */
    extern DICOM_EXPORT const tag PrinterResolutionID;
    /** PrinterStatus, 0x21100010, CS, 1 */
    extern DICOM_EXPORT const tag PrinterStatus;
    /** PrinterStatusInfo, 0x21100020, CS, 1 */
    extern DICOM_EXPORT const tag PrinterStatusInfo;
    /** PrintingBitDepth, 0x200000A1, US, 1 */
    extern DICOM_EXPORT const tag PrintingBitDepth;
    /** PrintJobDescriptionSequence, 0x21200050, SQ, 1, RET */
    extern DICOM_EXPORT const tag PrintJobDescriptionSequence;
    /** PrintJobID, 0x21000010, SH, 1, RET */
    extern DICOM_EXPORT const tag PrintJobID;
    /** PrintManagementCapabilitiesSequence, 0x21300010, SQ, 1, RET */
    extern DICOM_EXPORT const tag PrintManagementCapabilitiesSequence;
    /** PrintPriority, 0x20000020, CS, 1 */
    extern DICOM_EXPORT const tag PrintPriority;
    /** PrintQueueID, 0x21100099, SH, 1, RET */
    extern DICOM_EXPORT const tag PrintQueueID;
    /** PrismSequence, 0x00460028, SQ, 1 */
    extern DICOM_EXPORT const tag PrismSequence;
    /** PrivateCreatorReference, 0x00080302, LO, 1 */
    extern DICOM_EXPORT const tag PrivateCreatorReference;
    /** PrivateDataElement, 0x00080308, US, 1 */
    extern DICOM_EXPORT const tag PrivateDataElement;
    /** PrivateDataElementCharacteristicsSequence, 0x00080300, SQ, 1 */
    extern DICOM_EXPORT const tag PrivateDataElementCharacteristicsSequence;
    /** PrivateDataElementDefinitionSequence, 0x00080310, SQ, 1 */
    extern DICOM_EXPORT const tag PrivateDataElementDefinitionSequence;
    /** PrivateDataElementDescription, 0x0008030E, UT, 1 */
    extern DICOM_EXPORT const tag PrivateDataElementDescription;
    /** PrivateDataElementEncoding, 0x0008030F, UT, 1 */
    extern DICOM_EXPORT const tag PrivateDataElementEncoding;
    /** PrivateDataElementKeyword, 0x0008030D, UC, 1 */
    extern DICOM_EXPORT const tag PrivateDataElementKeyword;
    /** PrivateDataElementName, 0x0008030C, UC, 1 */
    extern DICOM_EXPORT const tag PrivateDataElementName;
    /** PrivateDataElementNumberOfItems, 0x0008030B, UL, 1 */
    extern DICOM_EXPORT const tag PrivateDataElementNumberOfItems;
    /** PrivateDataElementValueMultiplicity, 0x00080309, UL, 1 */
    extern DICOM_EXPORT const tag PrivateDataElementValueMultiplicity;
    /** PrivateDataElementValueRepresentation, 0x0008030A, CS, 1 */
    extern DICOM_EXPORT const tag PrivateDataElementValueRepresentation;
    /** PrivateGroupReference, 0x00080301, US, 1 */
    extern DICOM_EXPORT const tag PrivateGroupReference;
    /** PrivateInformation, 0x00020102, OB, 1 */
    extern DICOM_EXPORT const tag PrivateInformation;
    /** PrivateInformationCreatorUID, 0x00020100, UI, 1 */
    extern DICOM_EXPORT const tag PrivateInformationCreatorUID;
    /** PrivateRecordUID, 0x00041432, UI, 1 */
    extern DICOM_EXPORT const tag PrivateRecordUID;
    /** ProbeCenterLocationX, 0x00144058, DS, 1, RET */
    extern DICOM_EXPORT const tag ProbeCenterLocationX;
    /** ProbeCenterLocationZ, 0x00144059, DS, 1, RET */
    extern DICOM_EXPORT const tag ProbeCenterLocationZ;
    /** ProbeDriveEquipmentSequence, 0x00144080, SQ, 1, RET */
    extern DICOM_EXPORT const tag ProbeDriveEquipmentSequence;
    /** ProbeDriveNotes, 0x00144082, LT, 1, RET */
    extern DICOM_EXPORT const tag ProbeDriveNotes;
    /** ProbeDriveSettingsSequence, 0x00144087, SQ, 1, RET */
    extern DICOM_EXPORT const tag ProbeDriveSettingsSequence;
    /** ProbeInductance, 0x00144084, DS, 1, RET */
    extern DICOM_EXPORT const tag ProbeInductance;
    /** ProbeOrientationAngle, 0x00144089, DS, 1, RET */
    extern DICOM_EXPORT const tag ProbeOrientationAngle;
    /** ProbeResistance, 0x00144085, DS, 1, RET */
    extern DICOM_EXPORT const tag ProbeResistance;
    /** ProcedureCodeSequence, 0x00081032, SQ, 1 */
    extern DICOM_EXPORT const tag ProcedureCodeSequence;
    /** ProcedureContextFlagTrial, 0x0040A603, CS, 1, RET */
    extern DICOM_EXPORT const tag ProcedureContextFlagTrial;
    /** ProcedureContextSequenceTrial, 0x0040A340, SQ, 1, RET */
    extern DICOM_EXPORT const tag ProcedureContextSequenceTrial;
    /** ProcedureCreationDate, 0x00144076, DA, 1, RET */
    extern DICOM_EXPORT const tag ProcedureCreationDate;
    /** ProcedureExpirationDate, 0x00144078, DA, 1, RET */
    extern DICOM_EXPORT const tag ProcedureExpirationDate;
    /** ProcedureIdentifierCodeSequenceTrial, 0x0040A085, SQ, 1, RET */
    extern DICOM_EXPORT const tag ProcedureIdentifierCodeSequenceTrial;
    /** ProcedureLastModifiedDate, 0x0014407A, DA, 1, RET */
    extern DICOM_EXPORT const tag ProcedureLastModifiedDate;
    /** ProcedureStepCancellationDateTime, 0x00404052, DT, 1 */
    extern DICOM_EXPORT const tag ProcedureStepCancellationDateTime;
    /** ProcedureStepCommunicationsURISequence, 0x00741008, SQ, 1 */
    extern DICOM_EXPORT const tag ProcedureStepCommunicationsURISequence;
    /** ProcedureStepDiscontinuationReasonCodeSequence, 0x0074100E, SQ, 1 */
    extern DICOM_EXPORT const tag ProcedureStepDiscontinuationReasonCodeSequence;
    /** ProcedureStepLabel, 0x00741204, LO, 1 */
    extern DICOM_EXPORT const tag ProcedureStepLabel;
    /** ProcedureStepProgress, 0x00741004, DS, 1 */
    extern DICOM_EXPORT const tag ProcedureStepProgress;
    /** ProcedureStepProgressDescription, 0x00741006, ST, 1 */
    extern DICOM_EXPORT const tag ProcedureStepProgressDescription;
    /** ProcedureStepProgressInformationSequence, 0x00741002, SQ, 1 */
    extern DICOM_EXPORT const tag ProcedureStepProgressInformationSequence;
    /** ProcedureStepProgressParametersSequence, 0x00741007, SQ, 1 */
    extern DICOM_EXPORT const tag ProcedureStepProgressParametersSequence;
    /** ProcedureStepRelationshipType, 0x00741222, LO, 1, RET */
    extern DICOM_EXPORT const tag ProcedureStepRelationshipType;
    /** ProcedureStepState, 0x00741000, CS, 1 */
    extern DICOM_EXPORT const tag ProcedureStepState;
    /** ProcedureTypeCodeSequence, 0x00760020, SQ, 1 */
    extern DICOM_EXPORT const tag ProcedureTypeCodeSequence;
    /** ProcedureVersion, 0x00144074, SH, 1, RET */
    extern DICOM_EXPORT const tag ProcedureVersion;
    /** ProcessingFunction, 0x00185020, LO, 1 */
    extern DICOM_EXPORT const tag ProcessingFunction;
    /** ProductDescription, 0x00440009, LT, 1 */
    extern DICOM_EXPORT const tag ProductDescription;
    /** ProductExpirationDateTime, 0x0044000B, DT, 1 */
    extern DICOM_EXPORT const tag ProductExpirationDateTime;
    /** ProductLotIdentifier, 0x0044000A, LO, 1 */
    extern DICOM_EXPORT const tag ProductLotIdentifier;
    /** ProductName, 0x00440008, LO, 1 */
    extern DICOM_EXPORT const tag ProductName;
    /** ProductPackageIdentifier, 0x00440001, ST, 1 */
    extern DICOM_EXPORT const tag ProductPackageIdentifier;
    /** ProductParameterSequence, 0x00440013, SQ, 1 */
    extern DICOM_EXPORT const tag ProductParameterSequence;
    /** ProductTypeCodeSequence, 0x00440007, SQ, 1 */
    extern DICOM_EXPORT const tag ProductTypeCodeSequence;
    /** ProjectionEponymousNameCodeSequence, 0x00185104, SQ, 1 */
    extern DICOM_EXPORT const tag ProjectionEponymousNameCodeSequence;
    /** ProjectionPixelCalibrationSequence, 0x00189401, SQ, 1 */
    extern DICOM_EXPORT const tag ProjectionPixelCalibrationSequence;
    /** PropertyLabel, 0x00142032, SH, 1, RET */
    extern DICOM_EXPORT const tag PropertyLabel;
    /** ProposedStudySequence, 0x213000A0, SQ, 1, RET */
    extern DICOM_EXPORT const tag ProposedStudySequence;
    /** ProtocolContextSequence, 0x00400440, SQ, 1 */
    extern DICOM_EXPORT const tag ProtocolContextSequence;
    /** ProtocolDefinedPatientPosition, 0x00189947, CS, 1 */
    extern DICOM_EXPORT const tag ProtocolDefinedPatientPosition;
    /** ProtocolDesignRationale, 0x00189910, UT, 1 */
    extern DICOM_EXPORT const tag ProtocolDesignRationale;
    /** ProtocolElementCharacteristicsSummary, 0x00189923, UT, 1 */
    extern DICOM_EXPORT const tag ProtocolElementCharacteristicsSummary;
    /** ProtocolElementName, 0x00189922, LO, 1 */
    extern DICOM_EXPORT const tag ProtocolElementName;
    /** ProtocolElementNumber, 0x00189921, US, 1 */
    extern DICOM_EXPORT const tag ProtocolElementNumber;
    /** ProtocolElementPurpose, 0x00189924, UT, 1 */
    extern DICOM_EXPORT const tag ProtocolElementPurpose;
    /** ProtocolName, 0x00181030, LO, 1 */
    extern DICOM_EXPORT const tag ProtocolName;
    /** ProtocolPlanningInformation, 0x0018990F, UT, 1 */
    extern DICOM_EXPORT const tag ProtocolPlanningInformation;
    /** PseudoColorPaletteInstanceReferenceSequence, 0x00720705, SQ, 1 */
    extern DICOM_EXPORT const tag PseudoColorPaletteInstanceReferenceSequence;
    /** PseudoColorType, 0x00720704, CS, 1 */
    extern DICOM_EXPORT const tag PseudoColorType;
    /** PTOLocationDescription, 0x40101078, ST, 1, RET */
    extern DICOM_EXPORT const tag PTOLocationDescription;
    /** PTORegionSequence, 0x4010107B, SQ, 1, RET */
    extern DICOM_EXPORT const tag PTORegionSequence;
    /** PTORepresentationSequence, 0x40101037, SQ, 1, RET */
    extern DICOM_EXPORT const tag PTORepresentationSequence;
    /** PulseNumber, 0x30080172, US, 1 */
    extern DICOM_EXPORT const tag PulseNumber;
    /** PulseRepetitionFrequency, 0x00186032, UL, 1 */
    extern DICOM_EXPORT const tag PulseRepetitionFrequency;
    /** PulseRepetitionInterval, 0x300A028C, DS, 1 */
    extern DICOM_EXPORT const tag PulseRepetitionInterval;
    /** PulserEquipmentSequence, 0x00144002, SQ, 1, RET */
    extern DICOM_EXPORT const tag PulserEquipmentSequence;
    /** PulserNotes, 0x00144006, LT, 1, RET */
    extern DICOM_EXPORT const tag PulserNotes;
    /** PulserSettingsSequence, 0x00144020, SQ, 1, RET */
    extern DICOM_EXPORT const tag PulserSettingsSequence;
    /** PulserType, 0x00144004, CS, 1, RET */
    extern DICOM_EXPORT const tag PulserType;
    /** PulseSequenceName, 0x00189005, SH, 1 */
    extern DICOM_EXPORT const tag PulseSequenceName;
    /** PulseSpecificBrachyControlPointDeliveredSequence, 0x30080171, SQ, 1 */
    extern DICOM_EXPORT const tag PulseSpecificBrachyControlPointDeliveredSequence;
    /** PulseWidth, 0x00144022, DS, 1, RET */
    extern DICOM_EXPORT const tag PulseWidth;
    /** PupilCentroidXCoordinate, 0x00460203, FL, 1 */
    extern DICOM_EXPORT const tag PupilCentroidXCoordinate;
    /** PupilCentroidYCoordinate, 0x00460204, FL, 1 */
    extern DICOM_EXPORT const tag PupilCentroidYCoordinate;
    /** PupilDilated, 0x0022000D, CS, 1 */
    extern DICOM_EXPORT const tag PupilDilated;
    /** PupilSize, 0x00460044, FD, 1 */
    extern DICOM_EXPORT const tag PupilSize;
    /** PurposeOfReferenceCodeSequence, 0x0040A170, SQ, 1, RET */
    extern DICOM_EXPORT const tag PurposeOfReferenceCodeSequence;
    /** PVCRejection, 0x00181085, LO, 1 */
    extern DICOM_EXPORT const tag PVCRejection;
    /** QAResultsSequence, 0x0028700F, SQ, 1 */
    extern DICOM_EXPORT const tag QAResultsSequence;
    /** QRMeasurementsSequence, 0x40101071, SQ, 1, RET */
    extern DICOM_EXPORT const tag QRMeasurementsSequence;
    /** QuadratureReceiveCoil, 0x00189044, CS, 1 */
    extern DICOM_EXPORT const tag QuadratureReceiveCoil;
    /** QualityControlImage, 0x00280300, CS, 1 */
    extern DICOM_EXPORT const tag QualityControlImage;
    /** QualityControlSubject, 0x00100200, CS, 1 */
    extern DICOM_EXPORT const tag QualityControlSubject;
    /** QualityControlSubjectTypeCodeSequence, 0x00100201, SQ, 1 */
    extern DICOM_EXPORT const tag QualityControlSubjectTypeCodeSequence;
    /** QualityThreshold, 0x00221630, DS, 1 */
    extern DICOM_EXPORT const tag QualityThreshold;
    /** QuantifiedDefect, 0x00240098, FL, 1 */
    extern DICOM_EXPORT const tag QuantifiedDefect;
    /** Quantity, 0x00400294, DS, 1 */
    extern DICOM_EXPORT const tag Quantity;
    /** QuantityDefinitionSequence, 0x00409220, SQ, 1 */
    extern DICOM_EXPORT const tag QuantityDefinitionSequence;
    /** QuantitySequence, 0x00400293, SQ, 1 */
    extern DICOM_EXPORT const tag QuantitySequence;
    /** QueryRetrieveLevel, 0x00080052, CS, 1 */
    extern DICOM_EXPORT const tag QueryRetrieveLevel;
    /** QueryRetrieveView, 0x00080053, CS, 1 */
    extern DICOM_EXPORT const tag QueryRetrieveView;
    /** QueueStatus, 0x21200010, CS, 1, RET */
    extern DICOM_EXPORT const tag QueueStatus;
    /** RadialPosition, 0x00181142, DS, 1 */
    extern DICOM_EXPORT const tag RadialPosition;
    /** RadiationAtomicNumber, 0x300A0304, IS, 1 */
    extern DICOM_EXPORT const tag RadiationAtomicNumber;
    /** RadiationChargeState, 0x300A0306, SS, 1 */
    extern DICOM_EXPORT const tag RadiationChargeState;
    /** RadiationMachineName, 0x30020020, SH, 1 */
    extern DICOM_EXPORT const tag RadiationMachineName;
    /** RadiationMachineSAD, 0x30020022, DS, 1 */
    extern DICOM_EXPORT const tag RadiationMachineSAD;
    /** RadiationMachineSSD, 0x30020024, DS, 1 */
    extern DICOM_EXPORT const tag RadiationMachineSSD;
    /** RadiationMassNumber, 0x300A0302, IS, 1 */
    extern DICOM_EXPORT const tag RadiationMassNumber;
    /** RadiationMode, 0x0018115A, CS, 1 */
    extern DICOM_EXPORT const tag RadiationMode;
    /** RadiationSetting, 0x00181155, CS, 1 */
    extern DICOM_EXPORT const tag RadiationSetting;
    /** RadiationType, 0x300A00C6, CS, 1 */
    extern DICOM_EXPORT const tag RadiationType;
    /** Radionuclide, 0x00180030, LO, 1, RET */
    extern DICOM_EXPORT const tag Radionuclide;
    /** RadionuclideCodeSequence, 0x00540300, SQ, 1 */
    extern DICOM_EXPORT const tag RadionuclideCodeSequence;
    /** RadionuclideHalfLife, 0x00181075, DS, 1 */
    extern DICOM_EXPORT const tag RadionuclideHalfLife;
    /** RadionuclidePositronFraction, 0x00181076, DS, 1 */
    extern DICOM_EXPORT const tag RadionuclidePositronFraction;
    /** RadionuclideTotalDose, 0x00181074, DS, 1 */
    extern DICOM_EXPORT const tag RadionuclideTotalDose;
    /** Radiopharmaceutical, 0x00180031, LO, 1 */
    extern DICOM_EXPORT const tag Radiopharmaceutical;
    /** RadiopharmaceuticalAdministrationEventUID, 0x00083012, UI, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalAdministrationEventUID;
    /** RadiopharmaceuticalAgentNumber, 0x00189729, US, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalAgentNumber;
    /** RadiopharmaceuticalCodeSequence, 0x00540304, SQ, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalCodeSequence;
    /** RadiopharmaceuticalInformationSequence, 0x00540016, SQ, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalInformationSequence;
    /** RadiopharmaceuticalRoute, 0x00181070, LO, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalRoute;
    /** RadiopharmaceuticalSpecificActivity, 0x00181077, DS, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalSpecificActivity;
    /** RadiopharmaceuticalStartDateTime, 0x00181078, DT, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalStartDateTime;
    /** RadiopharmaceuticalStartTime, 0x00181072, TM, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalStartTime;
    /** RadiopharmaceuticalStopDateTime, 0x00181079, DT, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalStopDateTime;
    /** RadiopharmaceuticalStopTime, 0x00181073, TM, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalStopTime;
    /** RadiopharmaceuticalUsageSequence, 0x00189737, SQ, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalUsageSequence;
    /** RadiopharmaceuticalVolume, 0x00181071, DS, 1 */
    extern DICOM_EXPORT const tag RadiopharmaceuticalVolume;
    /** RadiusAlongWedge, 0x0014511F, DS, 1, RET */
    extern DICOM_EXPORT const tag RadiusAlongWedge;
    /** RadiusOfCircularCollimator, 0x00181712, IS, 1 */
    extern DICOM_EXPORT const tag RadiusOfCircularCollimator;
    /** RadiusOfCircularExposureControlSensingRegion, 0x00189441, US, 1 */
    extern DICOM_EXPORT const tag RadiusOfCircularExposureControlSensingRegion;
    /** RadiusOfCircularShutter, 0x00181612, IS, 1 */
    extern DICOM_EXPORT const tag RadiusOfCircularShutter;
    /** RadiusOfCurvature, 0x00460075, FD, 1 */
    extern DICOM_EXPORT const tag RadiusOfCurvature;
    /** RandomsCorrected, 0x00189765, CS, 1 */
    extern DICOM_EXPORT const tag RandomsCorrected;
    /** RandomsCorrectionMethod, 0x00541100, CS, 1 */
    extern DICOM_EXPORT const tag RandomsCorrectionMethod;
    /** RangeModulatorDescription, 0x300A034A, LO, 1 */
    extern DICOM_EXPORT const tag RangeModulatorDescription;
    /** RangeModulatorGatingStartValue, 0x300A0382, FL, 1 */
    extern DICOM_EXPORT const tag RangeModulatorGatingStartValue;
    /** RangeModulatorGatingStartWaterEquivalentThickness, 0x300A0386, FL, 1 */
    extern DICOM_EXPORT const tag RangeModulatorGatingStartWaterEquivalentThickness;
    /** RangeModulatorGatingStopValue, 0x300A0384, FL, 1 */
    extern DICOM_EXPORT const tag RangeModulatorGatingStopValue;
    /** RangeModulatorGatingStopWaterEquivalentThickness, 0x300A0388, FL, 1 */
    extern DICOM_EXPORT const tag RangeModulatorGatingStopWaterEquivalentThickness;
    /** RangeModulatorID, 0x300A0346, SH, 1 */
    extern DICOM_EXPORT const tag RangeModulatorID;
    /** RangeModulatorNumber, 0x300A0344, IS, 1 */
    extern DICOM_EXPORT const tag RangeModulatorNumber;
    /** RangeModulatorSequence, 0x300A0342, SQ, 1 */
    extern DICOM_EXPORT const tag RangeModulatorSequence;
    /** RangeModulatorSettingsSequence, 0x300A0380, SQ, 1 */
    extern DICOM_EXPORT const tag RangeModulatorSettingsSequence;
    /** RangeModulatorType, 0x300A0348, CS, 1 */
    extern DICOM_EXPORT const tag RangeModulatorType;
    /** RangeOfFreedom, 0x006864A0, FD, 2 */
    extern DICOM_EXPORT const tag RangeOfFreedom;
    /** RangeShifterDescription, 0x300A0322, LO, 1 */
    extern DICOM_EXPORT const tag RangeShifterDescription;
    /** RangeShifterID, 0x300A0318, SH, 1 */
    extern DICOM_EXPORT const tag RangeShifterID;
    /** RangeShifterNumber, 0x300A0316, IS, 1 */
    extern DICOM_EXPORT const tag RangeShifterNumber;
    /** RangeShifterSequence, 0x300A0314, SQ, 1 */
    extern DICOM_EXPORT const tag RangeShifterSequence;
    /** RangeShifterSetting, 0x300A0362, LO, 1 */
    extern DICOM_EXPORT const tag RangeShifterSetting;
    /** RangeShifterSettingsSequence, 0x300A0360, SQ, 1 */
    extern DICOM_EXPORT const tag RangeShifterSettingsSequence;
    /** RangeShifterType, 0x300A0320, CS, 1 */
    extern DICOM_EXPORT const tag RangeShifterType;
    /** RangeShifterWaterEquivalentThickness, 0x300A0366, FL, 1 */
    extern DICOM_EXPORT const tag RangeShifterWaterEquivalentThickness;
    /** RangingDepth, 0x00520009, FD, 1 */
    extern DICOM_EXPORT const tag RangingDepth;
    /** RationalDenominatorValue, 0x0040A163, UL, 1 */
    extern DICOM_EXPORT const tag RationalDenominatorValue;
    /** RationalNumeratorValue, 0x0040A162, SL, 1 */
    extern DICOM_EXPORT const tag RationalNumeratorValue;
    /** RawDataHandling, 0x00404040, CS, 1 */
    extern DICOM_EXPORT const tag RawDataHandling;
    /** RealWorldValueFirstValueMapped, 0x00409216, US or SS, 1 */
    extern DICOM_EXPORT const tag RealWorldValueFirstValueMapped;
    /** RealWorldValueIntercept, 0x00409224, FD, 1 */
    extern DICOM_EXPORT const tag RealWorldValueIntercept;
    /** RealWorldValueLastValueMapped, 0x00409211, US or SS, 1 */
    extern DICOM_EXPORT const tag RealWorldValueLastValueMapped;
    /** RealWorldValueLUTData, 0x00409212, FD, 1 */
    extern DICOM_EXPORT const tag RealWorldValueLUTData;
    /** RealWorldValueMappingSequence, 0x00409096, SQ, 1 */
    extern DICOM_EXPORT const tag RealWorldValueMappingSequence;
    /** RealWorldValueSlope, 0x00409225, FD, 1 */
    extern DICOM_EXPORT const tag RealWorldValueSlope;
    /** ReasonForCancellation, 0x00741238, LT, 1 */
    extern DICOM_EXPORT const tag ReasonForCancellation;
    /** ReasonForChannelOmission, 0x0074140A, CS, 1 */
    extern DICOM_EXPORT const tag ReasonForChannelOmission;
    /** ReasonForChannelOmissionDescription, 0x0074140B, LO, 1 */
    extern DICOM_EXPORT const tag ReasonForChannelOmissionDescription;
    /** ReasonForOmission, 0x300C0112, CS, 1 */
    extern DICOM_EXPORT const tag ReasonForOmission;
    /** ReasonForOmissionDescription, 0x300C0113, LO, 1 */
    extern DICOM_EXPORT const tag ReasonForOmissionDescription;
    /** ReasonForPerformedProcedureCodeSequence, 0x00401012, SQ, 1 */
    extern DICOM_EXPORT const tag ReasonForPerformedProcedureCodeSequence;
    /** ReasonForRequestedProcedureCodeSequence, 0x0040100A, SQ, 1 */
    extern DICOM_EXPORT const tag ReasonForRequestedProcedureCodeSequence;
    /** ReasonForStudy, 0x00321030, LO, 1, RET */
    extern DICOM_EXPORT const tag ReasonForStudy;
    /** ReasonForTheAttributeModification, 0x04000565, CS, 1 */
    extern DICOM_EXPORT const tag ReasonForTheAttributeModification;
    /** ReasonForTheImagingServiceRequest, 0x00402001, LO, 1, RET */
    extern DICOM_EXPORT const tag ReasonForTheImagingServiceRequest;
    /** ReasonForTheRequestedProcedure, 0x00401002, LO, 1 */
    extern DICOM_EXPORT const tag ReasonForTheRequestedProcedure;
    /** ReceiveCoilManufacturerName, 0x00189041, LO, 1 */
    extern DICOM_EXPORT const tag ReceiveCoilManufacturerName;
    /** ReceiveCoilName, 0x00181250, SH, 1 */
    extern DICOM_EXPORT const tag ReceiveCoilName;
    /** ReceiveCoilType, 0x00189043, CS, 1 */
    extern DICOM_EXPORT const tag ReceiveCoilType;
    /** ReceiveProbeSequence, 0x00144086, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReceiveProbeSequence;
    /** ReceiverEquipmentSequence, 0x00144008, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReceiverEquipmentSequence;
    /** ReceiverNotes, 0x0014400C, LT, 1, RET */
    extern DICOM_EXPORT const tag ReceiverNotes;
    /** ReceiverSettingsSequence, 0x00144030, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReceiverSettingsSequence;
    /** ReceiveTransducerSequence, 0x00144011, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReceiveTransducerSequence;
    /** ReceiveTransducerSettingsSequence, 0x00144051, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReceiveTransducerSettingsSequence;
    /** ReceivingAE, 0x00741234, AE, 1 */
    extern DICOM_EXPORT const tag ReceivingAE;
    /** ReceivingApplicationEntityTitle, 0x00020018, AE, 1 */
    extern DICOM_EXPORT const tag ReceivingApplicationEntityTitle;
    /** RecognitionCode, 0x00080010, SH, 1, RET */
    extern DICOM_EXPORT const tag RecognitionCode;
    /** RecognizableVisualFeatures, 0x00280302, CS, 1 */
    extern DICOM_EXPORT const tag RecognizableVisualFeatures;
    /** RecommendedAbsentPixelCIELabValue, 0x00480015, US, 3 */
    extern DICOM_EXPORT const tag RecommendedAbsentPixelCIELabValue;
    /** RecommendedAnimationRate, 0x00701A03, FD, 1 */
    extern DICOM_EXPORT const tag RecommendedAnimationRate;
    /** RecommendedDefaultValueSequence, 0x00820035, SQ, 1 */
    extern DICOM_EXPORT const tag RecommendedDefaultValueSequence;
    /** RecommendedDisplayCIELabValue, 0x0062000D, US, 3 */
    extern DICOM_EXPORT const tag RecommendedDisplayCIELabValue;
    /** RecommendedDisplayCIELabValueList, 0x00660103, OW, 1 */
    extern DICOM_EXPORT const tag RecommendedDisplayCIELabValueList;
    /** RecommendedDisplayFrameRate, 0x00082144, IS, 1 */
    extern DICOM_EXPORT const tag RecommendedDisplayFrameRate;
    /** RecommendedDisplayFrameRateInFloat, 0x00089459, FL, 1 */
    extern DICOM_EXPORT const tag RecommendedDisplayFrameRateInFloat;
    /** RecommendedDisplayGrayscaleValue, 0x0062000C, US, 1 */
    extern DICOM_EXPORT const tag RecommendedDisplayGrayscaleValue;
    /** RecommendedLineThickness, 0x00660038, FL, 1 */
    extern DICOM_EXPORT const tag RecommendedLineThickness;
    /** RecommendedPointRadius, 0x00660037, FL, 1 */
    extern DICOM_EXPORT const tag RecommendedPointRadius;
    /** RecommendedPresentationOpacity, 0x0066000C, FL, 1 */
    extern DICOM_EXPORT const tag RecommendedPresentationOpacity;
    /** RecommendedPresentationType, 0x0066000D, CS, 1 */
    extern DICOM_EXPORT const tag RecommendedPresentationType;
    /** RecommendedRotationPoint, 0x00686346, FD, 2 */
    extern DICOM_EXPORT const tag RecommendedRotationPoint;
    /** RecommendedViewingMode, 0x00281090, CS, 1 */
    extern DICOM_EXPORT const tag RecommendedViewingMode;
    /** ReconstructionAlgorithm, 0x00189315, CS, 1 */
    extern DICOM_EXPORT const tag ReconstructionAlgorithm;
    /** ReconstructionAlgorithmSequence, 0x0018993D, SQ, 1 */
    extern DICOM_EXPORT const tag ReconstructionAlgorithmSequence;
    /** ReconstructionAngle, 0x00189319, FD, 1 */
    extern DICOM_EXPORT const tag ReconstructionAngle;
    /** ReconstructionDescription, 0x00189531, LO, 1 */
    extern DICOM_EXPORT const tag ReconstructionDescription;
    /** ReconstructionDiameter, 0x00181100, DS, 1 */
    extern DICOM_EXPORT const tag ReconstructionDiameter;
    /** ReconstructionEndLocationSequence, 0x0018993C, SQ, 1 */
    extern DICOM_EXPORT const tag ReconstructionEndLocationSequence;
    /** ReconstructionFieldOfView, 0x00189317, FD, 2 */
    extern DICOM_EXPORT const tag ReconstructionFieldOfView;
    /** ReconstructionIndex, 0x00209536, US, 1 */
    extern DICOM_EXPORT const tag ReconstructionIndex;
    /** ReconstructionMethod, 0x00541103, LO, 1 */
    extern DICOM_EXPORT const tag ReconstructionMethod;
    /** ReconstructionPixelSpacing, 0x00189322, FD, 2 */
    extern DICOM_EXPORT const tag ReconstructionPixelSpacing;
    /** ReconstructionProtocolElementSequence, 0x00189934, SQ, 1 */
    extern DICOM_EXPORT const tag ReconstructionProtocolElementSequence;
    /** ReconstructionProtocolElementSpecificationSequence, 0x00189933, SQ, 1 */
    extern DICOM_EXPORT const tag ReconstructionProtocolElementSpecificationSequence;
    /** ReconstructionStartLocationSequence, 0x0018993B, SQ, 1 */
    extern DICOM_EXPORT const tag ReconstructionStartLocationSequence;
    /** ReconstructionTargetCenterLocationSequence, 0x0018993E, SQ, 1 */
    extern DICOM_EXPORT const tag ReconstructionTargetCenterLocationSequence;
    /** ReconstructionTargetCenterPatient, 0x00189318, FD, 3 */
    extern DICOM_EXPORT const tag ReconstructionTargetCenterPatient;
    /** ReconstructionType, 0x00189756, CS, 1 */
    extern DICOM_EXPORT const tag ReconstructionType;
    /** RecordedBlockSequence, 0x300800D0, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedBlockSequence;
    /** RecordedBrachyAccessoryDeviceSequence, 0x30080120, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedBrachyAccessoryDeviceSequence;
    /** RecordedChannelSequence, 0x30080130, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedChannelSequence;
    /** RecordedChannelShieldSequence, 0x30080150, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedChannelShieldSequence;
    /** RecordedCompensatorSequence, 0x300800C0, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedCompensatorSequence;
    /** RecordedLateralSpreadingDeviceSequence, 0x300800F4, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedLateralSpreadingDeviceSequence;
    /** RecordedRangeModulatorSequence, 0x300800F6, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedRangeModulatorSequence;
    /** RecordedRangeShifterSequence, 0x300800F2, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedRangeShifterSequence;
    /** RecordedSnoutSequence, 0x300800F0, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedSnoutSequence;
    /** RecordedSourceApplicatorSequence, 0x30080140, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedSourceApplicatorSequence;
    /** RecordedSourceSequence, 0x30080100, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedSourceSequence;
    /** RecordedWedgeSequence, 0x300800B0, SQ, 1 */
    extern DICOM_EXPORT const tag RecordedWedgeSequence;
    /** RecordInUseFlag, 0x00041410, US, 1 */
    extern DICOM_EXPORT const tag RecordInUseFlag;
    /** RectificationType, 0x00181156, CS, 1 */
    extern DICOM_EXPORT const tag RectificationType;
    /** RectifierSmoothing, 0x00144034, DS, 1, RET */
    extern DICOM_EXPORT const tag RectifierSmoothing;
    /** RectilinearPhaseEncodeReordering, 0x00189034, CS, 1 */
    extern DICOM_EXPORT const tag RectilinearPhaseEncodeReordering;
    /** RedPaletteColorLookupTableData, 0x00281201, OW, 1 */
    extern DICOM_EXPORT const tag RedPaletteColorLookupTableData;
    /** RedPaletteColorLookupTableDescriptor, 0x00281101, US or SS, 3 */
    extern DICOM_EXPORT const tag RedPaletteColorLookupTableDescriptor;
    /** Reference, 0x00201020, LO, 1, RET */
    extern DICOM_EXPORT const tag Reference;
    /** ReferenceAirKermaRate, 0x300A022A, DS, 1 */
    extern DICOM_EXPORT const tag ReferenceAirKermaRate;
    /** ReferenceBasisCodeSequence, 0x00189902, SQ, 1 */
    extern DICOM_EXPORT const tag ReferenceBasisCodeSequence;
    /** ReferenceCoordinates, 0x00220032, FL, 2 */
    extern DICOM_EXPORT const tag ReferenceCoordinates;
    /** ReferencedAccessionSequenceTrial, 0x0040A313, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedAccessionSequenceTrial;
    /** ReferencedAssertionUID, 0x00440108, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedAssertionUID;
    /** ReferencedBasicAnnotationBoxSequence, 0x20100520, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedBasicAnnotationBoxSequence;
    /** ReferencedBeamNumber, 0x300C0006, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedBeamNumber;
    /** ReferencedBeamSequence, 0x300C0004, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedBeamSequence;
    /** ReferencedBlockNumber, 0x300C00E0, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedBlockNumber;
    /** ReferencedBolusSequence, 0x300C00B0, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedBolusSequence;
    /** ReferencedBrachyAccessoryDeviceNumber, 0x30080122, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedBrachyAccessoryDeviceNumber;
    /** ReferencedBrachyApplicationSetupNumber, 0x300C000C, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedBrachyApplicationSetupNumber;
    /** ReferencedBrachyApplicationSetupSequence, 0x300C000A, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedBrachyApplicationSetupSequence;
    /** ReferencedCalculatedDoseReferenceNumber, 0x30080092, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedCalculatedDoseReferenceNumber;
    /** ReferencedCalculatedDoseReferenceSequence, 0x30080090, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedCalculatedDoseReferenceSequence;
    /** ReferencedChannelNumber, 0x00741406, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedChannelNumber;
    /** ReferencedChannelShieldNumber, 0x30080152, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedChannelShieldNumber;
    /** ReferencedColorPaletteInstanceUID, 0x00280304, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedColorPaletteInstanceUID;
    /** ReferencedComparisonSOPInstanceSequence, 0x00820005, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedComparisonSOPInstanceSequence;
    /** ReferencedCompensatorNumber, 0x300C00D0, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedCompensatorNumber;
    /** ReferencedContentItem, 0x00701904, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedContentItem;
    /** ReferencedContentItemIdentifier, 0x0040DB73, UL, 1 */
    extern DICOM_EXPORT const tag ReferencedContentItemIdentifier;
    /** ReferencedControlPointIndex, 0x300C00F0, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedControlPointIndex;
    /** ReferencedControlPointSequence, 0x300C00F2, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedControlPointSequence;
    /** ReferencedCurveSequence, 0x00081145, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedCurveSequence;
    /** ReferencedDateTime, 0x0040A13A, DT, 1 */
    extern DICOM_EXPORT const tag ReferencedDateTime;
    /** ReferencedDefinedProtocolSequence, 0x0018990C, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedDefinedProtocolSequence;
    /** ReferencedDigitalSignatureSequence, 0x04000402, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedDigitalSignatureSequence;
    /** ReferencedDoseReferenceNumber, 0x300C0051, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedDoseReferenceNumber;
    /** ReferencedDoseReferenceSequence, 0x300C0050, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedDoseReferenceSequence;
    /** ReferencedDoseReferenceUID, 0x300A0083, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedDoseReferenceUID;
    /** ReferencedDoseSequence, 0x300C0080, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedDoseSequence;
    /** ReferencedFiducialUID, 0x0070031B, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedFiducialUID;
    /** ReferencedFileID, 0x00041500, CS, 1 */
    extern DICOM_EXPORT const tag ReferencedFileID;
    /** ReferencedFilmBoxSequence, 0x20000500, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedFilmBoxSequence;
    /** ReferencedFilmSessionSequence, 0x20100500, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedFilmSessionSequence;
    /** ReferencedFindingsGroupUIDTrial, 0x0040A022, UI, 1, RET */
    extern DICOM_EXPORT const tag ReferencedFindingsGroupUIDTrial;
    /** ReferencedFirstFrameSequence, 0x00720427, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedFirstFrameSequence;
    /** ReferencedFractionGroupNumber, 0x300C0022, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedFractionGroupNumber;
    /** ReferencedFractionGroupSequence, 0x300C0020, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedFractionGroupSequence;
    /** ReferencedFractionNumber, 0x30080223, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedFractionNumber;
    /** ReferencedFrameNumber, 0x00081160, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedFrameNumber;
    /** ReferencedFrameNumbers, 0x0040A136, US, 1 */
    extern DICOM_EXPORT const tag ReferencedFrameNumbers;
    /** ReferencedFrameOfReferenceSequence, 0x30060010, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedFrameOfReferenceSequence;
    /** ReferencedFrameOfReferenceUID, 0x30060024, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedFrameOfReferenceUID;
    /** ReferencedGeneralPurposeScheduledProcedureStepSequence, 0x00404016, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedGeneralPurposeScheduledProcedureStepSequence;
    /** ReferencedGeneralPurposeScheduledProcedureStepTransactionUID, 0x00404023, UI, 1, RET */
    extern DICOM_EXPORT const tag ReferencedGeneralPurposeScheduledProcedureStepTransactionUID;
    /** ReferencedHPGLDocumentID, 0x00686440, US, 1 */
    extern DICOM_EXPORT const tag ReferencedHPGLDocumentID;
    /** ReferencedImageBoxSequence, 0x20100510, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedImageBoxSequence;
    /** ReferencedImageBoxSequenceRetired, 0x20400500, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedImageBoxSequenceRetired;
    /** ReferencedImageEvidenceSequence, 0x00089092, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedImageEvidenceSequence;
    /** ReferencedImageNavigationSequence, 0x00480200, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedImageNavigationSequence;
    /** ReferencedImageOverlayBoxSequence, 0x20200130, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedImageOverlayBoxSequence;
    /** ReferencedImageRealWorldValueMappingSequence, 0x00409094, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedImageRealWorldValueMappingSequence;
    /** ReferencedImageSequence, 0x00081140, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedImageSequence;
    /** ReferencedImplantTemplateGroupMemberID, 0x007800B6, US, 1 */
    extern DICOM_EXPORT const tag ReferencedImplantTemplateGroupMemberID;
    /** ReferencedInstanceSequence, 0x0008114A, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedInstanceSequence;
    /** ReferencedInterpretationSequence, 0x40080050, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedInterpretationSequence;
    /** ReferenceDisplaySets, 0x00720218, US, 1 */
    extern DICOM_EXPORT const tag ReferenceDisplaySets;
    /** ReferencedLateralSpreadingDeviceNumber, 0x300C0102, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedLateralSpreadingDeviceNumber;
    /** ReferencedMeasuredDoseReferenceNumber, 0x30080082, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedMeasuredDoseReferenceNumber;
    /** ReferencedMeasuredDoseReferenceSequence, 0x30080080, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedMeasuredDoseReferenceSequence;
    /** ReferencedNonImageCompositeSOPInstanceSequence, 0x00400220, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedNonImageCompositeSOPInstanceSequence;
    /** ReferencedObjectObservationClassTrial, 0x0040A174, CS, 1, RET */
    extern DICOM_EXPORT const tag ReferencedObjectObservationClassTrial;
    /** ReferencedObservationClassTrial, 0x0040A173, CS, 1, RET */
    extern DICOM_EXPORT const tag ReferencedObservationClassTrial;
    /** ReferencedObservationUIDTrial, 0x0040A172, UI, 1, RET */
    extern DICOM_EXPORT const tag ReferencedObservationUIDTrial;
    /** ReferencedOphthalmicAxialLengthMeasurementQCImageSequence, 0x00221330, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedOphthalmicAxialLengthMeasurementQCImageSequence;
    /** ReferencedOphthalmicAxialMeasurementsSequence, 0x00221100, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedOphthalmicAxialMeasurementsSequence;
    /** ReferenceDoseDefinition, 0x300A0512, CS, 1 */
    extern DICOM_EXPORT const tag ReferenceDoseDefinition;
    /** ReferencedOtherPlaneSequence, 0x00089410, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedOtherPlaneSequence;
    /** ReferencedOverlayPlaneGroups, 0x20400011, US, 1, RET */
    extern DICOM_EXPORT const tag ReferencedOverlayPlaneGroups;
    /** ReferencedOverlayPlaneSequence, 0x20400010, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedOverlayPlaneSequence;
    /** ReferencedOverlaySequence, 0x00081130, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedOverlaySequence;
    /** ReferencedPatientAliasSequence, 0x00380004, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedPatientAliasSequence;
    /** ReferencedPatientPhotoSequence, 0x00101100, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedPatientPhotoSequence;
    /** ReferencedPatientSequence, 0x00081120, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedPatientSequence;
    /** ReferencedPatientSetupNumber, 0x300C006A, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedPatientSetupNumber;
    /** ReferencedPerformedProcedureStepSequence, 0x00081111, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedPerformedProcedureStepSequence;
    /** ReferencedPerformedProtocolSequence, 0x0018990D, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedPerformedProtocolSequence;
    /** ReferencedPresentationLUTSequence, 0x20500500, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedPresentationLUTSequence;
    /** ReferencedPresentationStateSequence, 0x00089237, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedPresentationStateSequence;
    /** ReferencedPrintJobSequence, 0x21200070, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedPrintJobSequence;
    /** ReferencedPrintJobSequencePullStoredPrint, 0x21000500, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedPrintJobSequencePullStoredPrint;
    /** ReferencedProcedureStepSequence, 0x00400330, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedProcedureStepSequence;
    /** ReferencedPTOSequence, 0x40101076, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedPTOSequence;
    /** ReferencedRangeModulatorNumber, 0x300C0104, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedRangeModulatorNumber;
    /** ReferencedRangeShifterNumber, 0x300C0100, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedRangeShifterNumber;
    /** ReferencedRawDataSequence, 0x00089121, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedRawDataSequence;
    /** ReferencedRealWorldValueMappingInstanceSequence, 0x0008114B, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedRealWorldValueMappingInstanceSequence;
    /** ReferencedReferenceImageNumber, 0x300C0007, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedReferenceImageNumber;
    /** ReferencedReferenceImageSequence, 0x300C0042, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedReferenceImageSequence;
    /** ReferencedRefractiveMeasurementsSequence, 0x00460145, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedRefractiveMeasurementsSequence;
    /** ReferencedRelatedGeneralSOPClassUIDInFile, 0x0004151A, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedRelatedGeneralSOPClassUIDInFile;
    /** ReferencedRequestSequence, 0x0040A370, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedRequestSequence;
    /** ReferencedResultsSequence, 0x00081100, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedResultsSequence;
    /** ReferencedROINumber, 0x30060084, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedROINumber;
    /** ReferencedRTPlanSequence, 0x300C0002, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedRTPlanSequence;
    /** ReferencedSamplePositions, 0x0040A132, UL, 1 */
    extern DICOM_EXPORT const tag ReferencedSamplePositions;
    /** ReferencedSegmentNumber, 0x0062000B, US, 1 */
    extern DICOM_EXPORT const tag ReferencedSegmentNumber;
    /** ReferencedSeriesSequence, 0x00081115, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedSeriesSequence;
    /** ReferencedSetupImageSequence, 0x300A0401, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedSetupImageSequence;
    /** ReferencedSOPClassUID, 0x00081150, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedSOPClassUID;
    /** ReferencedSOPClassUIDInFile, 0x00041510, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedSOPClassUIDInFile;
    /** ReferencedSOPInstanceMACSequence, 0x04000403, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedSOPInstanceMACSequence;
    /** ReferencedSOPInstanceUID, 0x00081155, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedSOPInstanceUID;
    /** ReferencedSOPInstanceUIDInFile, 0x00041511, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedSOPInstanceUIDInFile;
    /** ReferencedSOPSequence, 0x00081199, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedSOPSequence;
    /** ReferencedSourceApplicatorNumber, 0x30080142, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedSourceApplicatorNumber;
    /** ReferencedSourceNumber, 0x300C000E, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedSourceNumber;
    /** ReferencedSpatialRegistrationSequence, 0x00700404, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedSpatialRegistrationSequence;
    /** ReferencedStartControlPointIndex, 0x300C00F4, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedStartControlPointIndex;
    /** ReferencedStereometricInstanceSequence, 0x00081134, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedStereometricInstanceSequence;
    /** ReferencedStopControlPointIndex, 0x300C00F6, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedStopControlPointIndex;
    /** ReferencedStorageMediaSequence, 0x2200000D, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedStorageMediaSequence;
    /** ReferencedStoredPrintSequence, 0x20000510, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedStoredPrintSequence;
    /** ReferencedStructuredContextSequence, 0x00701903, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedStructuredContextSequence;
    /** ReferencedStructureSetSequence, 0x300C0060, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedStructureSetSequence;
    /** ReferencedStudySequence, 0x00081110, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedStudySequence;
    /** ReferencedSurfaceDataSequence, 0x00800013, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedSurfaceDataSequence;
    /** ReferencedSurfaceMeshIdentificationSequence, 0x00221620, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedSurfaceMeshIdentificationSequence;
    /** ReferencedSurfaceNumber, 0x0066002C, UL, 1 */
    extern DICOM_EXPORT const tag ReferencedSurfaceNumber;
    /** ReferencedSurfaceSequence, 0x0066002B, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedSurfaceSequence;
    /** ReferencedTargetLuminanceCharacteristicsID, 0x0028700E, US, 1 */
    extern DICOM_EXPORT const tag ReferencedTargetLuminanceCharacteristicsID;
    /** ReferencedTDRInstanceSequence, 0x40101077, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedTDRInstanceSequence;
    /** ReferencedTextureSequence, 0x00800012, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedTextureSequence;
    /** ReferencedTimeOffsets, 0x0040A138, DS, 1 */
    extern DICOM_EXPORT const tag ReferencedTimeOffsets;
    /** ReferencedToleranceTableNumber, 0x300C00A0, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedToleranceTableNumber;
    /** ReferencedTransferSyntaxUIDInFile, 0x00041512, UI, 1 */
    extern DICOM_EXPORT const tag ReferencedTransferSyntaxUIDInFile;
    /** ReferencedTreatmentRecordSequence, 0x30080030, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedTreatmentRecordSequence;
    /** ReferencedVerificationImageSequence, 0x300C0040, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedVerificationImageSequence;
    /** ReferencedVisitSequence, 0x00081125, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedVisitSequence;
    /** ReferencedVOILUTBoxSequence, 0x20200140, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReferencedVOILUTBoxSequence;
    /** ReferencedWaveformChannels, 0x0040A0B0, US, 2 */
    extern DICOM_EXPORT const tag ReferencedWaveformChannels;
    /** ReferencedWaveformSequence, 0x0008113A, SQ, 1 */
    extern DICOM_EXPORT const tag ReferencedWaveformSequence;
    /** ReferencedWedgeNumber, 0x300C00C0, IS, 1 */
    extern DICOM_EXPORT const tag ReferencedWedgeNumber;
    /** ReferenceGeometryCodeSequence, 0x00189903, SQ, 1 */
    extern DICOM_EXPORT const tag ReferenceGeometryCodeSequence;
    /** ReferenceImageNumber, 0x300A00C8, IS, 1 */
    extern DICOM_EXPORT const tag ReferenceImageNumber;
    /** ReferenceLocationDescription, 0x00189901, UT, 1 */
    extern DICOM_EXPORT const tag ReferenceLocationDescription;
    /** ReferenceLocationLabel, 0x00189900, LO, 1 */
    extern DICOM_EXPORT const tag ReferenceLocationLabel;
    /** ReferencePixelPhysicalValueX, 0x00186028, FD, 1 */
    extern DICOM_EXPORT const tag ReferencePixelPhysicalValueX;
    /** ReferencePixelPhysicalValueY, 0x0018602A, FD, 1 */
    extern DICOM_EXPORT const tag ReferencePixelPhysicalValueY;
    /** ReferencePixelX0, 0x00186020, SL, 1 */
    extern DICOM_EXPORT const tag ReferencePixelX0;
    /** ReferencePixelY0, 0x00186022, SL, 1 */
    extern DICOM_EXPORT const tag ReferencePixelY0;
    /** ReferenceToRecordedSound, 0x40080103, LO, 1, RET */
    extern DICOM_EXPORT const tag ReferenceToRecordedSound;
    /** ReferringPhysicianAddress, 0x00080092, ST, 1 */
    extern DICOM_EXPORT const tag ReferringPhysicianAddress;
    /** ReferringPhysicianIdentificationSequence, 0x00080096, SQ, 1 */
    extern DICOM_EXPORT const tag ReferringPhysicianIdentificationSequence;
    /** ReferringPhysicianName, 0x00080090, PN, 1 */
    extern DICOM_EXPORT const tag ReferringPhysicianName;
    /** ReferringPhysicianTelephoneNumbers, 0x00080094, SH, 1 */
    extern DICOM_EXPORT const tag ReferringPhysicianTelephoneNumbers;
    /** ReflectedAmbientLight, 0x20100160, US, 1 */
    extern DICOM_EXPORT const tag ReflectedAmbientLight;
    /** ReformattingInterval, 0x00720514, FD, 1 */
    extern DICOM_EXPORT const tag ReformattingInterval;
    /** ReformattingOperationInitialViewDirection, 0x00720516, CS, 1 */
    extern DICOM_EXPORT const tag ReformattingOperationInitialViewDirection;
    /** ReformattingOperationType, 0x00720510, CS, 1 */
    extern DICOM_EXPORT const tag ReformattingOperationType;
    /** ReformattingThickness, 0x00720512, FD, 1 */
    extern DICOM_EXPORT const tag ReformattingThickness;
    /** RefractiveErrorBeforeRefractiveSurgeryCodeSequence, 0x00221103, SQ, 1 */
    extern DICOM_EXPORT const tag RefractiveErrorBeforeRefractiveSurgeryCodeSequence;
    /** RefractiveIndexApplied, 0x0052003A, CS, 1 */
    extern DICOM_EXPORT const tag RefractiveIndexApplied;
    /** RefractiveParametersUsedOnPatientSequence, 0x00240112, SQ, 1 */
    extern DICOM_EXPORT const tag RefractiveParametersUsedOnPatientSequence;
    /** RefractivePower, 0x00460251, FL, 1 */
    extern DICOM_EXPORT const tag RefractivePower;
    /** RefractiveProcedureOccurred, 0x00221039, CS, 1 */
    extern DICOM_EXPORT const tag RefractiveProcedureOccurred;
    /** RefractiveStateSequence, 0x0022001B, SQ, 1 */
    extern DICOM_EXPORT const tag RefractiveStateSequence;
    /** RefractiveSurgeryTypeCodeSequence, 0x00221040, SQ, 1 */
    extern DICOM_EXPORT const tag RefractiveSurgeryTypeCodeSequence;
    /** RegionDataType, 0x00186014, US, 1 */
    extern DICOM_EXPORT const tag RegionDataType;
    /** RegionFlags, 0x00186016, UL, 1 */
    extern DICOM_EXPORT const tag RegionFlags;
    /** RegionLocationMaxX1, 0x0018601C, UL, 1 */
    extern DICOM_EXPORT const tag RegionLocationMaxX1;
    /** RegionLocationMaxY1, 0x0018601E, UL, 1 */
    extern DICOM_EXPORT const tag RegionLocationMaxY1;
    /** RegionLocationMinX0, 0x00186018, UL, 1 */
    extern DICOM_EXPORT const tag RegionLocationMinX0;
    /** RegionLocationMinY0, 0x0018601A, UL, 1 */
    extern DICOM_EXPORT const tag RegionLocationMinY0;
    /** RegionOfResidence, 0x00102152, LO, 1 */
    extern DICOM_EXPORT const tag RegionOfResidence;
    /** RegionPixelShiftSequence, 0x00289502, SQ, 1 */
    extern DICOM_EXPORT const tag RegionPixelShiftSequence;
    /** RegionSpatialFormat, 0x00186012, US, 1 */
    extern DICOM_EXPORT const tag RegionSpatialFormat;
    /** RegisteredLocalizerBottomRightHandCorner, 0x00221468, FL, 2 */
    extern DICOM_EXPORT const tag RegisteredLocalizerBottomRightHandCorner;
    /** RegisteredLocalizerTopLeftHandCorner, 0x00221467, FL, 2 */
    extern DICOM_EXPORT const tag RegisteredLocalizerTopLeftHandCorner;
    /** RegisteredLocalizerUnits, 0x00221466, CS, 1 */
    extern DICOM_EXPORT const tag RegisteredLocalizerUnits;
    /** RegistrationMethodCodeSequence, 0x00800003, SQ, 1 */
    extern DICOM_EXPORT const tag RegistrationMethodCodeSequence;
    /** RegistrationSequence, 0x00700308, SQ, 1 */
    extern DICOM_EXPORT const tag RegistrationSequence;
    /** RegistrationToLocalizerSequence, 0x00221465, SQ, 1 */
    extern DICOM_EXPORT const tag RegistrationToLocalizerSequence;
    /** RegistrationTypeCodeSequence, 0x0070030D, SQ, 1 */
    extern DICOM_EXPORT const tag RegistrationTypeCodeSequence;
    /** RelatedAssertionSequence, 0x00440107, SQ, 1 */
    extern DICOM_EXPORT const tag RelatedAssertionSequence;
    /** RelatedFrameOfReferenceUID, 0x300600C2, UI, 1, RET */
    extern DICOM_EXPORT const tag RelatedFrameOfReferenceUID;
    /** RelatedGeneralSOPClassUID, 0x0008001A, UI, 1 */
    extern DICOM_EXPORT const tag RelatedGeneralSOPClassUID;
    /** RelatedProcedureStepSequence, 0x00741220, SQ, 1, RET */
    extern DICOM_EXPORT const tag RelatedProcedureStepSequence;
    /** RelatedReferenceRTImageSequence, 0x00741040, SQ, 1 */
    extern DICOM_EXPORT const tag RelatedReferenceRTImageSequence;
    /** RelatedRTROIObservationsSequence, 0x300600A0, SQ, 1 */
    extern DICOM_EXPORT const tag RelatedRTROIObservationsSequence;
    /** RelatedSeriesSequence, 0x00081250, SQ, 1 */
    extern DICOM_EXPORT const tag RelatedSeriesSequence;
    /** RelationshipSequenceTrial, 0x0040A731, SQ, 1, RET */
    extern DICOM_EXPORT const tag RelationshipSequenceTrial;
    /** RelationshipType, 0x0040A010, CS, 1 */
    extern DICOM_EXPORT const tag RelationshipType;
    /** RelationshipTypeCodeSequenceTrial, 0x0040A732, SQ, 1, RET */
    extern DICOM_EXPORT const tag RelationshipTypeCodeSequenceTrial;
    /** RelativeElevation, 0x00460252, FL, 1 */
    extern DICOM_EXPORT const tag RelativeElevation;
    /** RelativeImagePositionCodeSequence, 0x0022001D, SQ, 1 */
    extern DICOM_EXPORT const tag RelativeImagePositionCodeSequence;
    /** RelativeOpacity, 0x00700403, FL, 1 */
    extern DICOM_EXPORT const tag RelativeOpacity;
    /** RelativeTime, 0x00720038, US, 2 */
    extern DICOM_EXPORT const tag RelativeTime;
    /** RelativeTimeUnits, 0x0072003A, CS, 1 */
    extern DICOM_EXPORT const tag RelativeTimeUnits;
    /** RelativeXRayExposure, 0x00181405, IS, 1 */
    extern DICOM_EXPORT const tag RelativeXRayExposure;
    /** RelevantInformationSequence, 0x00404022, SQ, 1, RET */
    extern DICOM_EXPORT const tag RelevantInformationSequence;
    /** RelevantOPTAttributesSequence, 0x00221472, SQ, 1 */
    extern DICOM_EXPORT const tag RelevantOPTAttributesSequence;
    /** RenderedImageReferenceSequence, 0x00701104, SQ, 1 */
    extern DICOM_EXPORT const tag RenderedImageReferenceSequence;
    /** RenderFieldOfView, 0x00701606, FD, 6 */
    extern DICOM_EXPORT const tag RenderFieldOfView;
    /** RenderingMethod, 0x0070120D, CS, 1 */
    extern DICOM_EXPORT const tag RenderingMethod;
    /** RenderProjection, 0x00701602, CS, 1 */
    extern DICOM_EXPORT const tag RenderProjection;
    /** RepairID, 0x00140105, ST, 1, RET */
    extern DICOM_EXPORT const tag RepairID;
    /** RepeatFractionCycleLength, 0x300A007A, IS, 1 */
    extern DICOM_EXPORT const tag RepeatFractionCycleLength;
    /** RepeatInterval, 0x00280068, US, 1, RET */
    extern DICOM_EXPORT const tag RepeatInterval;
    /** RepetitionTime, 0x00180080, DS, 1 */
    extern DICOM_EXPORT const tag RepetitionTime;
    /** ReplacedImplantAssemblyTemplateSequence, 0x00760008, SQ, 1 */
    extern DICOM_EXPORT const tag ReplacedImplantAssemblyTemplateSequence;
    /** ReplacedImplantTemplateGroupSequence, 0x00780026, SQ, 1 */
    extern DICOM_EXPORT const tag ReplacedImplantTemplateGroupSequence;
    /** ReplacedImplantTemplateSequence, 0x00686222, SQ, 1 */
    extern DICOM_EXPORT const tag ReplacedImplantTemplateSequence;
    /** ReplacedProcedureStepSequence, 0x00741224, SQ, 1 */
    extern DICOM_EXPORT const tag ReplacedProcedureStepSequence;
    /** ReportDetailSequenceTrial, 0x0040A380, SQ, 1, RET */
    extern DICOM_EXPORT const tag ReportDetailSequenceTrial;
    /** ReportedValuesOrigin, 0x3002000A, CS, 1 */
    extern DICOM_EXPORT const tag ReportedValuesOrigin;
    /** ReportingPriority, 0x00401009, SH, 1 */
    extern DICOM_EXPORT const tag ReportingPriority;
    /** ReportNumber, 0x002000AA, IS, 1, RET */
    extern DICOM_EXPORT const tag ReportNumber;
    /** ReportProductionStatusTrial, 0x400800FF, CS, 1, RET */
    extern DICOM_EXPORT const tag ReportProductionStatusTrial;
    /** ReportStatusCommentTrial, 0x0040A33A, ST, 1, RET */
    extern DICOM_EXPORT const tag ReportStatusCommentTrial;
    /** ReportStatusIDTrial, 0x0040A125, CS, 2, RET */
    extern DICOM_EXPORT const tag ReportStatusIDTrial;
    /** RepositoryUniqueID, 0x0040E030, UI, 1 */
    extern DICOM_EXPORT const tag RepositoryUniqueID;
    /** RepresentativeFrameNumber, 0x00286010, US, 1 */
    extern DICOM_EXPORT const tag RepresentativeFrameNumber;
    /** ReprojectionMethod, 0x00541004, CS, 1 */
    extern DICOM_EXPORT const tag ReprojectionMethod;
    /** RequestAttributesSequence, 0x00400275, SQ, 1 */
    extern DICOM_EXPORT const tag RequestAttributesSequence;
    /** RequestedContrastAgent, 0x00321070, LO, 1 */
    extern DICOM_EXPORT const tag RequestedContrastAgent;
    /** RequestedDecimateCropBehavior, 0x20200040, CS, 1 */
    extern DICOM_EXPORT const tag RequestedDecimateCropBehavior;
    /** RequestedImageSize, 0x20200030, DS, 1 */
    extern DICOM_EXPORT const tag RequestedImageSize;
    /** RequestedImageSizeFlag, 0x202000A0, CS, 1 */
    extern DICOM_EXPORT const tag RequestedImageSizeFlag;
    /** RequestedMediaApplicationProfile, 0x2200000C, LO, 1 */
    extern DICOM_EXPORT const tag RequestedMediaApplicationProfile;
    /** RequestedProcedureCodeSequence, 0x00321064, SQ, 1 */
    extern DICOM_EXPORT const tag RequestedProcedureCodeSequence;
    /** RequestedProcedureComments, 0x00401400, LT, 1 */
    extern DICOM_EXPORT const tag RequestedProcedureComments;
    /** RequestedProcedureDescription, 0x00321060, LO, 1 */
    extern DICOM_EXPORT const tag RequestedProcedureDescription;
    /** RequestedProcedureDescriptionTrial, 0x00401060, LO, 1, RET */
    extern DICOM_EXPORT const tag RequestedProcedureDescriptionTrial;
    /** RequestedProcedureID, 0x00401001, SH, 1 */
    extern DICOM_EXPORT const tag RequestedProcedureID;
    /** RequestedProcedureLocation, 0x00401005, LO, 1 */
    extern DICOM_EXPORT const tag RequestedProcedureLocation;
    /** RequestedProcedurePriority, 0x00401003, SH, 1 */
    extern DICOM_EXPORT const tag RequestedProcedurePriority;
    /** RequestedResolutionID, 0x20200050, CS, 1 */
    extern DICOM_EXPORT const tag RequestedResolutionID;
    /** RequestedSeriesDescription, 0x00189937, LO, 1 */
    extern DICOM_EXPORT const tag RequestedSeriesDescription;
    /** RequestedSubsequentWorkitemCodeSequence, 0x00404031, SQ, 1, RET */
    extern DICOM_EXPORT const tag RequestedSubsequentWorkitemCodeSequence;
    /** RequestingAE, 0x00741236, AE, 1 */
    extern DICOM_EXPORT const tag RequestingAE;
    /** RequestingPhysician, 0x00321032, PN, 1 */
    extern DICOM_EXPORT const tag RequestingPhysician;
    /** RequestingPhysicianIdentificationSequence, 0x00321031, SQ, 1 */
    extern DICOM_EXPORT const tag RequestingPhysicianIdentificationSequence;
    /** RequestingService, 0x00321033, LO, 1 */
    extern DICOM_EXPORT const tag RequestingService;
    /** RequestingServiceCodeSequence, 0x00321034, SQ, 1 */
    extern DICOM_EXPORT const tag RequestingServiceCodeSequence;
    /** RequestPriority, 0x22000020, CS, 1 */
    extern DICOM_EXPORT const tag RequestPriority;
    /** RescaleIntercept, 0x00281052, DS, 1 */
    extern DICOM_EXPORT const tag RescaleIntercept;
    /** RescaleSlope, 0x00281053, DS, 1 */
    extern DICOM_EXPORT const tag RescaleSlope;
    /** RescaleType, 0x00281054, LO, 1 */
    extern DICOM_EXPORT const tag RescaleType;
    /** ResidualSyringeCounts, 0x00540017, IS, 1 */
    extern DICOM_EXPORT const tag ResidualSyringeCounts;
    /** ResonantNucleus, 0x00189100, CS, 1 */
    extern DICOM_EXPORT const tag ResonantNucleus;
    /** ResourceDescription, 0x00380102, LO, 1 */
    extern DICOM_EXPORT const tag ResourceDescription;
    /** RespiratoryCyclePosition, 0x00189214, CS, 1 */
    extern DICOM_EXPORT const tag RespiratoryCyclePosition;
    /** RespiratoryIntervalTime, 0x00209254, FD, 1 */
    extern DICOM_EXPORT const tag RespiratoryIntervalTime;
    /** RespiratoryMotionCompensationTechnique, 0x00189170, CS, 1 */
    extern DICOM_EXPORT const tag RespiratoryMotionCompensationTechnique;
    /** RespiratoryMotionCompensationTechniqueDescription, 0x00189185, ST, 1 */
    extern DICOM_EXPORT const tag RespiratoryMotionCompensationTechniqueDescription;
    /** RespiratorySignalSource, 0x00189171, CS, 1 */
    extern DICOM_EXPORT const tag RespiratorySignalSource;
    /** RespiratorySignalSourceID, 0x00189186, SH, 1 */
    extern DICOM_EXPORT const tag RespiratorySignalSourceID;
    /** RespiratorySynchronizationSequence, 0x00209253, SQ, 1 */
    extern DICOM_EXPORT const tag RespiratorySynchronizationSequence;
    /** RespiratoryTriggerDelayThreshold, 0x00209256, FD, 1 */
    extern DICOM_EXPORT const tag RespiratoryTriggerDelayThreshold;
    /** RespiratoryTriggerType, 0x00209250, CS, 1 */
    extern DICOM_EXPORT const tag RespiratoryTriggerType;
    /** ResponsibleGroupCodeSequence, 0x00080220, SQ, 1 */
    extern DICOM_EXPORT const tag ResponsibleGroupCodeSequence;
    /** ResponsibleOrganization, 0x00102299, LO, 1 */
    extern DICOM_EXPORT const tag ResponsibleOrganization;
    /** ResponsiblePerson, 0x00102297, PN, 1 */
    extern DICOM_EXPORT const tag ResponsiblePerson;
    /** ResponsiblePersonRole, 0x00102298, CS, 1 */
    extern DICOM_EXPORT const tag ResponsiblePersonRole;
    /** ResultingGeneralPurposePerformedProcedureStepsSequence, 0x00404015, SQ, 1, RET */
    extern DICOM_EXPORT const tag ResultingGeneralPurposePerformedProcedureStepsSequence;
    /** ResultsComments, 0x40084000, ST, 1, RET */
    extern DICOM_EXPORT const tag ResultsComments;
    /** ResultsDistributionListSequence, 0x40080118, SQ, 1, RET */
    extern DICOM_EXPORT const tag ResultsDistributionListSequence;
    /** ResultsID, 0x40080040, SH, 1, RET */
    extern DICOM_EXPORT const tag ResultsID;
    /** ResultsIDIssuer, 0x40080042, LO, 1, RET */
    extern DICOM_EXPORT const tag ResultsIDIssuer;
    /** ResultsNormalsSequence, 0x00240064, SQ, 1 */
    extern DICOM_EXPORT const tag ResultsNormalsSequence;
    /** RetestSensitivityValue, 0x00240096, FL, 1 */
    extern DICOM_EXPORT const tag RetestSensitivityValue;
    /** RetestStimulusSeen, 0x00240095, CS, 1 */
    extern DICOM_EXPORT const tag RetestStimulusSeen;
    /** RetinalThicknessDefinitionCodeSequence, 0x00221445, SQ, 1 */
    extern DICOM_EXPORT const tag RetinalThicknessDefinitionCodeSequence;
    /** RetrieveAETitle, 0x00080054, AE, 1 */
    extern DICOM_EXPORT const tag RetrieveAETitle;
    /** RetrieveLocationUID, 0x0040E011, UI, 1 */
    extern DICOM_EXPORT const tag RetrieveLocationUID;
    /** RetrieveURI, 0x0040E010, UR, 1 */
    extern DICOM_EXPORT const tag RetrieveURI;
    /** RetrieveURL, 0x00081190, UR, 1 */
    extern DICOM_EXPORT const tag RetrieveURL;
    /** ReviewDate, 0x300E0004, DA, 1 */
    extern DICOM_EXPORT const tag ReviewDate;
    /** ReviewerName, 0x300E0008, PN, 1 */
    extern DICOM_EXPORT const tag ReviewerName;
    /** ReviewTime, 0x300E0005, TM, 1 */
    extern DICOM_EXPORT const tag ReviewTime;
    /** RevolutionTime, 0x00189305, FD, 1 */
    extern DICOM_EXPORT const tag RevolutionTime;
    /** RFEchoTrainLength, 0x00189240, US, 1 */
    extern DICOM_EXPORT const tag RFEchoTrainLength;
    /** RGBATransferFunctionDescription, 0x00701A09, LO, 1 */
    extern DICOM_EXPORT const tag RGBATransferFunctionDescription;
    /** RGBLUTTransferFunction, 0x0028140F, CS, 1 */
    extern DICOM_EXPORT const tag RGBLUTTransferFunction;
    /** RightImageSequence, 0x00220022, SQ, 1 */
    extern DICOM_EXPORT const tag RightImageSequence;
    /** RightLensSequence, 0x00460014, SQ, 1 */
    extern DICOM_EXPORT const tag RightLensSequence;
    /** ROIArea, 0x60001301, IS, 1 */
    extern DICOM_EXPORT const range_tag ROIArea;
    /** ROIContourSequence, 0x30060039, SQ, 1 */
    extern DICOM_EXPORT const tag ROIContourSequence;
    /** ROIDescription, 0x30060028, ST, 1 */
    extern DICOM_EXPORT const tag ROIDescription;
    /** ROIDisplayColor, 0x3006002A, IS, 3 */
    extern DICOM_EXPORT const tag ROIDisplayColor;
    /** ROIElementalCompositionAtomicMassFraction, 0x300600B8, FL, 1 */
    extern DICOM_EXPORT const tag ROIElementalCompositionAtomicMassFraction;
    /** ROIElementalCompositionAtomicNumber, 0x300600B7, US, 1 */
    extern DICOM_EXPORT const tag ROIElementalCompositionAtomicNumber;
    /** ROIElementalCompositionSequence, 0x300600B6, SQ, 1 */
    extern DICOM_EXPORT const tag ROIElementalCompositionSequence;
    /** ROIGenerationAlgorithm, 0x30060036, CS, 1 */
    extern DICOM_EXPORT const tag ROIGenerationAlgorithm;
    /** ROIGenerationDescription, 0x30060038, LO, 1 */
    extern DICOM_EXPORT const tag ROIGenerationDescription;
    /** ROIInterpreter, 0x300600A6, PN, 1 */
    extern DICOM_EXPORT const tag ROIInterpreter;
    /** ROIMean, 0x60001302, DS, 1 */
    extern DICOM_EXPORT const range_tag ROIMean;
    /** ROIName, 0x30060026, LO, 1 */
    extern DICOM_EXPORT const tag ROIName;
    /** ROINumber, 0x30060022, IS, 1 */
    extern DICOM_EXPORT const tag ROINumber;
    /** ROIObservationDescription, 0x30060088, ST, 1 */
    extern DICOM_EXPORT const tag ROIObservationDescription;
    /** ROIObservationLabel, 0x30060085, SH, 1 */
    extern DICOM_EXPORT const tag ROIObservationLabel;
    /** ROIPhysicalPropertiesSequence, 0x300600B0, SQ, 1 */
    extern DICOM_EXPORT const tag ROIPhysicalPropertiesSequence;
    /** ROIPhysicalProperty, 0x300600B2, CS, 1 */
    extern DICOM_EXPORT const tag ROIPhysicalProperty;
    /** ROIPhysicalPropertyValue, 0x300600B4, DS, 1 */
    extern DICOM_EXPORT const tag ROIPhysicalPropertyValue;
    /** ROIStandardDeviation, 0x60001303, DS, 1 */
    extern DICOM_EXPORT const range_tag ROIStandardDeviation;
    /** ROIVolume, 0x3006002C, DS, 1 */
    extern DICOM_EXPORT const tag ROIVolume;
    /** RotationAngle, 0x00700230, FD, 1 */
    extern DICOM_EXPORT const tag RotationAngle;
    /** RotationDirection, 0x00181140, CS, 1 */
    extern DICOM_EXPORT const tag RotationDirection;
    /** RotationInformationSequence, 0x00540052, SQ, 1 */
    extern DICOM_EXPORT const tag RotationInformationSequence;
    /** RotationOffset, 0x00181146, DS, 1, RET */
    extern DICOM_EXPORT const tag RotationOffset;
    /** RotationOfScannedFilm, 0x00182030, DS, 1 */
    extern DICOM_EXPORT const tag RotationOfScannedFilm;
    /** RotationPoint, 0x00700273, FL, 2 */
    extern DICOM_EXPORT const tag RotationPoint;
    /** RotationVector, 0x00540050, US, 1 */
    extern DICOM_EXPORT const tag RotationVector;
    /** RouteID, 0x40101054, SH, 1, RET */
    extern DICOM_EXPORT const tag RouteID;
    /** RouteIDAssigningAuthority, 0x40101055, SH, 1, RET */
    extern DICOM_EXPORT const tag RouteIDAssigningAuthority;
    /** RouteOfAdmissions, 0x00380016, LO, 1 */
    extern DICOM_EXPORT const tag RouteOfAdmissions;
    /** RouteSegmentEndLocationID, 0x4010101F, SH, 1, RET */
    extern DICOM_EXPORT const tag RouteSegmentEndLocationID;
    /** RouteSegmentEndTime, 0x40101026, DT, 1, RET */
    extern DICOM_EXPORT const tag RouteSegmentEndTime;
    /** RouteSegmentID, 0x40101007, SH, 1, RET */
    extern DICOM_EXPORT const tag RouteSegmentID;
    /** RouteSegmentLocationIDType, 0x40101020, CS, 1, RET */
    extern DICOM_EXPORT const tag RouteSegmentLocationIDType;
    /** RouteSegmentSequence, 0x4010100A, SQ, 1, RET */
    extern DICOM_EXPORT const tag RouteSegmentSequence;
    /** RouteSegmentStartLocationID, 0x4010101E, SH, 1, RET */
    extern DICOM_EXPORT const tag RouteSegmentStartLocationID;
    /** RouteSegmentStartTime, 0x40101025, DT, 1, RET */
    extern DICOM_EXPORT const tag RouteSegmentStartTime;
    /** RowOverlap, 0x00280093, US, 1, RET */
    extern DICOM_EXPORT const tag RowOverlap;
    /** RowPositionInTotalImagePixelMatrix, 0x0048021F, SL, 1 */
    extern DICOM_EXPORT const tag RowPositionInTotalImagePixelMatrix;
    /** Rows, 0x00280010, US, 1 */
    extern DICOM_EXPORT const tag Rows;
    /** RowsForNthOrderCoefficients, 0x00280400, US, 1, RET */
    extern DICOM_EXPORT const range_tag RowsForNthOrderCoefficients;
    /** RRIntervalTimeNominal, 0x00209251, FD, 1 */
    extern DICOM_EXPORT const tag RRIntervalTimeNominal;
    /** RRIntervalVector, 0x00540060, US, 1 */
    extern DICOM_EXPORT const tag RRIntervalVector;
    /** RTBeamLimitingDeviceType, 0x300A00B8, CS, 1 */
    extern DICOM_EXPORT const tag RTBeamLimitingDeviceType;
    /** RTDoseROISequence, 0x30040010, SQ, 1 */
    extern DICOM_EXPORT const tag RTDoseROISequence;
    /** RTImageDescription, 0x30020004, ST, 1 */
    extern DICOM_EXPORT const tag RTImageDescription;
    /** RTImageLabel, 0x30020002, SH, 1 */
    extern DICOM_EXPORT const tag RTImageLabel;
    /** RTImageName, 0x30020003, LO, 1 */
    extern DICOM_EXPORT const tag RTImageName;
    /** RTImageOrientation, 0x30020010, DS, 6 */
    extern DICOM_EXPORT const tag RTImageOrientation;
    /** RTImagePlane, 0x3002000C, CS, 1 */
    extern DICOM_EXPORT const tag RTImagePlane;
    /** RTImagePosition, 0x30020012, DS, 2 */
    extern DICOM_EXPORT const tag RTImagePosition;
    /** RTImageSID, 0x30020026, DS, 1 */
    extern DICOM_EXPORT const tag RTImageSID;
    /** RTPlanDate, 0x300A0006, DA, 1 */
    extern DICOM_EXPORT const tag RTPlanDate;
    /** RTPlanDescription, 0x300A0004, ST, 1 */
    extern DICOM_EXPORT const tag RTPlanDescription;
    /** RTPlanGeometry, 0x300A000C, CS, 1 */
    extern DICOM_EXPORT const tag RTPlanGeometry;
    /** RTPlanLabel, 0x300A0002, SH, 1 */
    extern DICOM_EXPORT const tag RTPlanLabel;
    /** RTPlanName, 0x300A0003, LO, 1 */
    extern DICOM_EXPORT const tag RTPlanName;
    /** RTPlanRelationship, 0x300A0055, CS, 1 */
    extern DICOM_EXPORT const tag RTPlanRelationship;
    /** RTPlanTime, 0x300A0007, TM, 1 */
    extern DICOM_EXPORT const tag RTPlanTime;
    /** RTReferencedSeriesSequence, 0x30060014, SQ, 1 */
    extern DICOM_EXPORT const tag RTReferencedSeriesSequence;
    /** RTReferencedStudySequence, 0x30060012, SQ, 1 */
    extern DICOM_EXPORT const tag RTReferencedStudySequence;
    /** RTRelatedROISequence, 0x30060030, SQ, 1 */
    extern DICOM_EXPORT const tag RTRelatedROISequence;
    /** RTROIIdentificationCodeSequence, 0x30060086, SQ, 1 */
    extern DICOM_EXPORT const tag RTROIIdentificationCodeSequence;
    /** RTROIInterpretedType, 0x300600A4, CS, 1 */
    extern DICOM_EXPORT const tag RTROIInterpretedType;
    /** RTROIObservationsSequence, 0x30060080, SQ, 1 */
    extern DICOM_EXPORT const tag RTROIObservationsSequence;
    /** RTROIRelationship, 0x30060033, CS, 1 */
    extern DICOM_EXPORT const tag RTROIRelationship;
    /** RunLengthTriplet, 0x10000001, US, 3, RET */
    extern DICOM_EXPORT const range_tag RunLengthTriplet;
    /** RWavePointer, 0x00286040, US, 1 */
    extern DICOM_EXPORT const tag RWavePointer;
    /** RWaveTimeVector, 0x00186060, FL, 1 */
    extern DICOM_EXPORT const tag RWaveTimeVector;
    /** SafePositionExitDate, 0x30080162, DA, 1 */
    extern DICOM_EXPORT const tag SafePositionExitDate;
    /** SafePositionExitTime, 0x30080164, TM, 1 */
    extern DICOM_EXPORT const tag SafePositionExitTime;
    /** SafePositionReturnDate, 0x30080166, DA, 1 */
    extern DICOM_EXPORT const tag SafePositionReturnDate;
    /** SafePositionReturnTime, 0x30080168, TM, 1 */
    extern DICOM_EXPORT const tag SafePositionReturnTime;
    /** SampleRate, 0x50002008, UL, 1, RET */
    extern DICOM_EXPORT const range_tag SampleRate;
    /** SamplesPerPixel, 0x00280002, US, 1 */
    extern DICOM_EXPORT const tag SamplesPerPixel;
    /** SamplesPerPixelUsed, 0x00280003, US, 1 */
    extern DICOM_EXPORT const tag SamplesPerPixelUsed;
    /** SamplingFrequency, 0x003A001A, DS, 1 */
    extern DICOM_EXPORT const tag SamplingFrequency;
    /** SamplingStepSize, 0x00701607, FD, 1 */
    extern DICOM_EXPORT const tag SamplingStepSize;
    /** SAR, 0x00181316, DS, 1 */
    extern DICOM_EXPORT const tag SAR;
    /** SaturationRecovery, 0x00189024, CS, 1 */
    extern DICOM_EXPORT const tag SaturationRecovery;
    /** ScanArc, 0x00181143, DS, 1 */
    extern DICOM_EXPORT const tag ScanArc;
    /** ScanLength, 0x00181302, IS, 1 */
    extern DICOM_EXPORT const tag ScanLength;
    /** ScanMode, 0x300A0308, CS, 1 */
    extern DICOM_EXPORT const tag ScanMode;
    /** ScannerSettingsSequence, 0x0014409A, SQ, 1, RET */
    extern DICOM_EXPORT const tag ScannerSettingsSequence;
    /** ScanningSequence, 0x00180020, CS, 1 */
    extern DICOM_EXPORT const tag ScanningSequence;
    /** ScanningSpotSize, 0x300A0398, FL, 2 */
    extern DICOM_EXPORT const tag ScanningSpotSize;
    /** ScanOptions, 0x00180022, CS, 1 */
    extern DICOM_EXPORT const tag ScanOptions;
    /** ScanPatternTypeCodeSequence, 0x00221618, SQ, 1 */
    extern DICOM_EXPORT const tag ScanPatternTypeCodeSequence;
    /** ScanProcedure, 0x0014409B, ST, 1, RET */
    extern DICOM_EXPORT const tag ScanProcedure;
    /** ScanProgressionDirection, 0x00540501, CS, 1 */
    extern DICOM_EXPORT const tag ScanProgressionDirection;
    /** ScanSpotMetersetsDelivered, 0x30080047, FL, 1 */
    extern DICOM_EXPORT const tag ScanSpotMetersetsDelivered;
    /** ScanSpotMetersetWeights, 0x300A0396, FL, 1 */
    extern DICOM_EXPORT const tag ScanSpotMetersetWeights;
    /** ScanSpotPositionMap, 0x300A0394, FL, 1 */
    extern DICOM_EXPORT const tag ScanSpotPositionMap;
    /** ScanSpotPrescribedIndices, 0x300A0391, IS, 1 */
    extern DICOM_EXPORT const tag ScanSpotPrescribedIndices;
    /** ScanSpotReordered, 0x300A0393, CS, 1 */
    extern DICOM_EXPORT const tag ScanSpotReordered;
    /** ScanSpotReorderingAllowed, 0x300A0395, CS, 1 */
    extern DICOM_EXPORT const tag ScanSpotReorderingAllowed;
    /** ScanSpotTimeOffset, 0x300A038F, FL, 1 */
    extern DICOM_EXPORT const tag ScanSpotTimeOffset;
    /** ScanSpotTuneID, 0x300A0390, SH, 1 */
    extern DICOM_EXPORT const tag ScanSpotTuneID;
    /** ScanType, 0x40101048, CS, 1, RET */
    extern DICOM_EXPORT const tag ScanType;
    /** ScanVelocity, 0x00181300, DS, 1 */
    extern DICOM_EXPORT const tag ScanVelocity;
    /** ScatterCorrected, 0x00189760, CS, 1 */
    extern DICOM_EXPORT const tag ScatterCorrected;
    /** ScatterCorrectionMethod, 0x00541105, LO, 1 */
    extern DICOM_EXPORT const tag ScatterCorrectionMethod;
    /** ScatterFractionFactor, 0x00541323, DS, 1 */
    extern DICOM_EXPORT const tag ScatterFractionFactor;
    /** ScheduledAdmissionDate, 0x0038001A, DA, 1, RET */
    extern DICOM_EXPORT const tag ScheduledAdmissionDate;
    /** ScheduledAdmissionTime, 0x0038001B, TM, 1, RET */
    extern DICOM_EXPORT const tag ScheduledAdmissionTime;
    /** ScheduledDischargeDate, 0x0038001C, DA, 1, RET */
    extern DICOM_EXPORT const tag ScheduledDischargeDate;
    /** ScheduledDischargeTime, 0x0038001D, TM, 1, RET */
    extern DICOM_EXPORT const tag ScheduledDischargeTime;
    /** ScheduledHumanPerformersSequence, 0x00404034, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledHumanPerformersSequence;
    /** ScheduledPatientInstitutionResidence, 0x0038001E, LO, 1, RET */
    extern DICOM_EXPORT const tag ScheduledPatientInstitutionResidence;
    /** ScheduledPerformingPhysicianIdentificationSequence, 0x0040000B, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledPerformingPhysicianIdentificationSequence;
    /** ScheduledPerformingPhysicianName, 0x00400006, PN, 1 */
    extern DICOM_EXPORT const tag ScheduledPerformingPhysicianName;
    /** ScheduledProcedureStepDescription, 0x00400007, LO, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepDescription;
    /** ScheduledProcedureStepEndDate, 0x00400004, DA, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepEndDate;
    /** ScheduledProcedureStepEndTime, 0x00400005, TM, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepEndTime;
    /** ScheduledProcedureStepExpirationDateTime, 0x00404008, DT, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepExpirationDateTime;
    /** ScheduledProcedureStepID, 0x00400009, SH, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepID;
    /** ScheduledProcedureStepLocation, 0x00400011, SH, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepLocation;
    /** ScheduledProcedureStepModificationDateTime, 0x00404010, DT, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepModificationDateTime;
    /** ScheduledProcedureStepPriority, 0x00741200, CS, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepPriority;
    /** ScheduledProcedureStepSequence, 0x00400100, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepSequence;
    /** ScheduledProcedureStepStartDate, 0x00400002, DA, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepStartDate;
    /** ScheduledProcedureStepStartDateTime, 0x00404005, DT, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepStartDateTime;
    /** ScheduledProcedureStepStartTime, 0x00400003, TM, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepStartTime;
    /** ScheduledProcedureStepStatus, 0x00400020, CS, 1 */
    extern DICOM_EXPORT const tag ScheduledProcedureStepStatus;
    /** ScheduledProcessingApplicationsCodeSequence, 0x00404004, SQ, 1, RET */
    extern DICOM_EXPORT const tag ScheduledProcessingApplicationsCodeSequence;
    /** ScheduledProcessingParametersSequence, 0x00741210, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledProcessingParametersSequence;
    /** ScheduledProtocolCodeSequence, 0x00400008, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledProtocolCodeSequence;
    /** ScheduledSpecimenSequence, 0x00400500, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledSpecimenSequence;
    /** ScheduledStationAETitle, 0x00400001, AE, 1 */
    extern DICOM_EXPORT const tag ScheduledStationAETitle;
    /** ScheduledStationClassCodeSequence, 0x00404026, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledStationClassCodeSequence;
    /** ScheduledStationGeographicLocationCodeSequence, 0x00404027, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledStationGeographicLocationCodeSequence;
    /** ScheduledStationName, 0x00400010, SH, 1 */
    extern DICOM_EXPORT const tag ScheduledStationName;
    /** ScheduledStationNameCodeSequence, 0x00404025, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledStationNameCodeSequence;
    /** ScheduledStepAttributesSequence, 0x00400270, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledStepAttributesSequence;
    /** ScheduledStudyLocation, 0x00321020, LO, 1, RET */
    extern DICOM_EXPORT const tag ScheduledStudyLocation;
    /** ScheduledStudyLocationAETitle, 0x00321021, AE, 1, RET */
    extern DICOM_EXPORT const tag ScheduledStudyLocationAETitle;
    /** ScheduledStudyStartDate, 0x00321000, DA, 1, RET */
    extern DICOM_EXPORT const tag ScheduledStudyStartDate;
    /** ScheduledStudyStartTime, 0x00321001, TM, 1, RET */
    extern DICOM_EXPORT const tag ScheduledStudyStartTime;
    /** ScheduledStudyStopDate, 0x00321010, DA, 1, RET */
    extern DICOM_EXPORT const tag ScheduledStudyStopDate;
    /** ScheduledStudyStopTime, 0x00321011, TM, 1, RET */
    extern DICOM_EXPORT const tag ScheduledStudyStopTime;
    /** ScheduledWorkitemCodeSequence, 0x00404018, SQ, 1 */
    extern DICOM_EXPORT const tag ScheduledWorkitemCodeSequence;
    /** SCPStatus, 0x00741242, CS, 1 */
    extern DICOM_EXPORT const tag SCPStatus;
    /** ScreeningBaselineMeasured, 0x00240120, CS, 1 */
    extern DICOM_EXPORT const tag ScreeningBaselineMeasured;
    /** ScreeningBaselineMeasuredSequence, 0x00240122, SQ, 1 */
    extern DICOM_EXPORT const tag ScreeningBaselineMeasuredSequence;
    /** ScreeningBaselineType, 0x00240124, CS, 1 */
    extern DICOM_EXPORT const tag ScreeningBaselineType;
    /** ScreeningBaselineValue, 0x00240126, FL, 1 */
    extern DICOM_EXPORT const tag ScreeningBaselineValue;
    /** ScreeningTestModeCodeSequence, 0x00240016, SQ, 1 */
    extern DICOM_EXPORT const tag ScreeningTestModeCodeSequence;
    /** ScreenMinimumColorBitDepth, 0x0072010C, US, 1 */
    extern DICOM_EXPORT const tag ScreenMinimumColorBitDepth;
    /** ScreenMinimumGrayscaleBitDepth, 0x0072010A, US, 1 */
    extern DICOM_EXPORT const tag ScreenMinimumGrayscaleBitDepth;
    /** SeamLineIndex, 0x00520036, US, 1 */
    extern DICOM_EXPORT const tag SeamLineIndex;
    /** SeamLineLocation, 0x00520033, FD, 1 */
    extern DICOM_EXPORT const tag SeamLineLocation;
    /** SecondaryApprovalStatus, 0x00140101, CS, 1, RET */
    extern DICOM_EXPORT const tag SecondaryApprovalStatus;
    /** SecondaryCaptureDeviceID, 0x00181010, LO, 1 */
    extern DICOM_EXPORT const tag SecondaryCaptureDeviceID;
    /** SecondaryCaptureDeviceManufacturer, 0x00181016, LO, 1 */
    extern DICOM_EXPORT const tag SecondaryCaptureDeviceManufacturer;
    /** SecondaryCaptureDeviceManufacturerModelName, 0x00181018, LO, 1 */
    extern DICOM_EXPORT const tag SecondaryCaptureDeviceManufacturerModelName;
    /** SecondaryCaptureDeviceSoftwareVersions, 0x00181019, LO, 1 */
    extern DICOM_EXPORT const tag SecondaryCaptureDeviceSoftwareVersions;
    /** SecondaryCountsAccumulated, 0x00541311, IS, 1 */
    extern DICOM_EXPORT const tag SecondaryCountsAccumulated;
    /** SecondaryCountsType, 0x00541220, CS, 1 */
    extern DICOM_EXPORT const tag SecondaryCountsType;
    /** SecondaryInspectionMethodSequence, 0x4010107D, SQ, 1, RET */
    extern DICOM_EXPORT const tag SecondaryInspectionMethodSequence;
    /** SecondaryPositionerIncrement, 0x00189515, FL, 1 */
    extern DICOM_EXPORT const tag SecondaryPositionerIncrement;
    /** SecondaryPositionerIncrementSign, 0x00189519, SS, 1 */
    extern DICOM_EXPORT const tag SecondaryPositionerIncrementSign;
    /** SecondaryPositionerScanArc, 0x00189509, FL, 1 */
    extern DICOM_EXPORT const tag SecondaryPositionerScanArc;
    /** SecondaryPositionerScanStartAngle, 0x00189511, FL, 1 */
    extern DICOM_EXPORT const tag SecondaryPositionerScanStartAngle;
    /** SecondaryReviewDate, 0x00140102, DA, 1, RET */
    extern DICOM_EXPORT const tag SecondaryReviewDate;
    /** SecondaryReviewerName, 0x00140104, PN, 1, RET */
    extern DICOM_EXPORT const tag SecondaryReviewerName;
    /** SecondaryReviewTime, 0x00140103, TM, 1, RET */
    extern DICOM_EXPORT const tag SecondaryReviewTime;
    /** SegmentAlgorithmName, 0x00620009, LO, 1 */
    extern DICOM_EXPORT const tag SegmentAlgorithmName;
    /** SegmentAlgorithmType, 0x00620008, CS, 1 */
    extern DICOM_EXPORT const tag SegmentAlgorithmType;
    /** SegmentationAlgorithmIdentificationSequence, 0x00620007, SQ, 1 */
    extern DICOM_EXPORT const tag SegmentationAlgorithmIdentificationSequence;
    /** SegmentationFractionalType, 0x00620010, CS, 1 */
    extern DICOM_EXPORT const tag SegmentationFractionalType;
    /** SegmentationType, 0x00620001, CS, 1 */
    extern DICOM_EXPORT const tag SegmentationType;
    /** SegmentDescription, 0x00620006, ST, 1 */
    extern DICOM_EXPORT const tag SegmentDescription;
    /** SegmentedAlphaPaletteColorLookupTableData, 0x00281224, OW, 1 */
    extern DICOM_EXPORT const tag SegmentedAlphaPaletteColorLookupTableData;
    /** SegmentedBluePaletteColorLookupTableData, 0x00281223, OW, 1 */
    extern DICOM_EXPORT const tag SegmentedBluePaletteColorLookupTableData;
    /** SegmentedGreenPaletteColorLookupTableData, 0x00281222, OW, 1 */
    extern DICOM_EXPORT const tag SegmentedGreenPaletteColorLookupTableData;
    /** SegmentedKSpaceTraversal, 0x00189033, CS, 1 */
    extern DICOM_EXPORT const tag SegmentedKSpaceTraversal;
    /** SegmentedPropertyCategoryCodeSequence, 0x00620003, SQ, 1 */
    extern DICOM_EXPORT const tag SegmentedPropertyCategoryCodeSequence;
    /** SegmentedPropertyTypeCodeSequence, 0x0062000F, SQ, 1 */
    extern DICOM_EXPORT const tag SegmentedPropertyTypeCodeSequence;
    /** SegmentedPropertyTypeModifierCodeSequence, 0x00620011, SQ, 1 */
    extern DICOM_EXPORT const tag SegmentedPropertyTypeModifierCodeSequence;
    /** SegmentedRedPaletteColorLookupTableData, 0x00281221, OW, 1 */
    extern DICOM_EXPORT const tag SegmentedRedPaletteColorLookupTableData;
    /** SegmentIdentificationSequence, 0x0062000A, SQ, 1 */
    extern DICOM_EXPORT const tag SegmentIdentificationSequence;
    /** SegmentLabel, 0x00620005, LO, 1 */
    extern DICOM_EXPORT const tag SegmentLabel;
    /** SegmentNumber, 0x00620004, US, 1 */
    extern DICOM_EXPORT const tag SegmentNumber;
    /** SegmentSequence, 0x00620002, SQ, 1 */
    extern DICOM_EXPORT const tag SegmentSequence;
    /** SegmentSurfaceGenerationAlgorithmIdentificationSequence, 0x0066002D, SQ, 1 */
    extern DICOM_EXPORT const tag SegmentSurfaceGenerationAlgorithmIdentificationSequence;
    /** SegmentSurfaceSourceInstanceSequence, 0x0066002E, SQ, 1 */
    extern DICOM_EXPORT const tag SegmentSurfaceSourceInstanceSequence;
    /** SelectedSegmentalOphthalmicAxialLengthSequence, 0x00221257, SQ, 1 */
    extern DICOM_EXPORT const tag SelectedSegmentalOphthalmicAxialLengthSequence;
    /** SelectedTotalOphthalmicAxialLengthSequence, 0x00221260, SQ, 1 */
    extern DICOM_EXPORT const tag SelectedTotalOphthalmicAxialLengthSequence;
    /** SelectorAEValue, 0x0072005E, AE, 1 */
    extern DICOM_EXPORT const tag SelectorAEValue;
    /** SelectorASValue, 0x0072005F, AS, 1 */
    extern DICOM_EXPORT const tag SelectorASValue;
    /** SelectorAttribute, 0x00720026, AT, 1 */
    extern DICOM_EXPORT const tag SelectorAttribute;
    /** SelectorAttributeKeyword, 0x00820019, LO, 1 */
    extern DICOM_EXPORT const tag SelectorAttributeKeyword;
    /** SelectorAttributeName, 0x00820018, LO, 1 */
    extern DICOM_EXPORT const tag SelectorAttributeName;
    /** SelectorAttributePrivateCreator, 0x00720056, LO, 1 */
    extern DICOM_EXPORT const tag SelectorAttributePrivateCreator;
    /** SelectorAttributeVR, 0x00720050, CS, 1 */
    extern DICOM_EXPORT const tag SelectorAttributeVR;
    /** SelectorATValue, 0x00720060, AT, 1 */
    extern DICOM_EXPORT const tag SelectorATValue;
    /** SelectorCodeSequenceValue, 0x00720080, SQ, 1 */
    extern DICOM_EXPORT const tag SelectorCodeSequenceValue;
    /** SelectorCSValue, 0x00720062, CS, 1 */
    extern DICOM_EXPORT const tag SelectorCSValue;
    /** SelectorDAValue, 0x00720061, DA, 1 */
    extern DICOM_EXPORT const tag SelectorDAValue;
    /** SelectorDSValue, 0x00720072, DS, 1 */
    extern DICOM_EXPORT const tag SelectorDSValue;
    /** SelectorDTValue, 0x00720063, DT, 1 */
    extern DICOM_EXPORT const tag SelectorDTValue;
    /** SelectorFDValue, 0x00720074, FD, 1 */
    extern DICOM_EXPORT const tag SelectorFDValue;
    /** SelectorFLValue, 0x00720076, FL, 1 */
    extern DICOM_EXPORT const tag SelectorFLValue;
    /** SelectorISValue, 0x00720064, IS, 1 */
    extern DICOM_EXPORT const tag SelectorISValue;
    /** SelectorLOValue, 0x00720066, LO, 1 */
    extern DICOM_EXPORT const tag SelectorLOValue;
    /** SelectorLTValue, 0x00720068, LT, 1 */
    extern DICOM_EXPORT const tag SelectorLTValue;
    /** SelectorOBValue, 0x00720065, OB, 1 */
    extern DICOM_EXPORT const tag SelectorOBValue;
    /** SelectorODValue, 0x00720073, OD, 1 */
    extern DICOM_EXPORT const tag SelectorODValue;
    /** SelectorOFValue, 0x00720067, OF, 1 */
    extern DICOM_EXPORT const tag SelectorOFValue;
    /** SelectorOLValue, 0x00720075, OL, 1 */
    extern DICOM_EXPORT const tag SelectorOLValue;
    /** SelectorOWValue, 0x00720069, OW, 1 */
    extern DICOM_EXPORT const tag SelectorOWValue;
    /** SelectorPNValue, 0x0072006A, PN, 1 */
    extern DICOM_EXPORT const tag SelectorPNValue;
    /** SelectorSequencePointer, 0x00720052, AT, 1 */
    extern DICOM_EXPORT const tag SelectorSequencePointer;
    /** SelectorSequencePointerItems, 0x00741057, IS, 1 */
    extern DICOM_EXPORT const tag SelectorSequencePointerItems;
    /** SelectorSequencePointerPrivateCreator, 0x00720054, LO, 1 */
    extern DICOM_EXPORT const tag SelectorSequencePointerPrivateCreator;
    /** SelectorSHValue, 0x0072006C, SH, 1 */
    extern DICOM_EXPORT const tag SelectorSHValue;
    /** SelectorSLValue, 0x0072007C, SL, 1 */
    extern DICOM_EXPORT const tag SelectorSLValue;
    /** SelectorSSValue, 0x0072007E, SS, 1 */
    extern DICOM_EXPORT const tag SelectorSSValue;
    /** SelectorSTValue, 0x0072006E, ST, 1 */
    extern DICOM_EXPORT const tag SelectorSTValue;
    /** SelectorTMValue, 0x0072006B, TM, 1 */
    extern DICOM_EXPORT const tag SelectorTMValue;
    /** SelectorUCValue, 0x0072006F, UC, 1 */
    extern DICOM_EXPORT const tag SelectorUCValue;
    /** SelectorUIValue, 0x0072007F, UI, 1 */
    extern DICOM_EXPORT const tag SelectorUIValue;
    /** SelectorULValue, 0x00720078, UL, 1 */
    extern DICOM_EXPORT const tag SelectorULValue;
    /** SelectorUNValue, 0x0072006D, UN, 1 */
    extern DICOM_EXPORT const tag SelectorUNValue;
    /** SelectorURValue, 0x00720071, UR, 1 */
    extern DICOM_EXPORT const tag SelectorURValue;
    /** SelectorUSValue, 0x0072007A, US, 1 */
    extern DICOM_EXPORT const tag SelectorUSValue;
    /** SelectorUTValue, 0x00720070, UT, 1 */
    extern DICOM_EXPORT const tag SelectorUTValue;
    /** SelectorValueNumber, 0x00720028, US, 1 */
    extern DICOM_EXPORT const tag SelectorValueNumber;
    /** SendingApplicationEntityTitle, 0x00020017, AE, 1 */
    extern DICOM_EXPORT const tag SendingApplicationEntityTitle;
    /** Sensitivity, 0x00186000, DS, 1 */
    extern DICOM_EXPORT const tag Sensitivity;
    /** SensitivityCalibrated, 0x00189767, CS, 1 */
    extern DICOM_EXPORT const tag SensitivityCalibrated;
    /** SensitivityValue, 0x00240094, FL, 1 */
    extern DICOM_EXPORT const tag SensitivityValue;
    /** SensorName, 0x00143022, ST, 1, RET */
    extern DICOM_EXPORT const tag SensorName;
    /** SensorTemperature, 0x00143028, DS, 1, RET */
    extern DICOM_EXPORT const tag SensorTemperature;
    /** SequenceName, 0x00180024, SH, 1 */
    extern DICOM_EXPORT const tag SequenceName;
    /** SequenceOfCompressedData, 0x00280403, LO, 1, RET */
    extern DICOM_EXPORT const tag SequenceOfCompressedData;
    /** SequenceOfUltrasoundRegions, 0x00186011, SQ, 1 */
    extern DICOM_EXPORT const tag SequenceOfUltrasoundRegions;
    /** SequenceVariant, 0x00180021, CS, 1 */
    extern DICOM_EXPORT const tag SequenceVariant;
    /** SequencingIndicatorTrial, 0x0040A060, LO, 1, RET */
    extern DICOM_EXPORT const tag SequencingIndicatorTrial;
    /** SeriesDate, 0x00080021, DA, 1 */
    extern DICOM_EXPORT const tag SeriesDate;
    /** SeriesDescription, 0x0008103E, LO, 1 */
    extern DICOM_EXPORT const tag SeriesDescription;
    /** SeriesDescriptionCodeSequence, 0x0008103F, SQ, 1 */
    extern DICOM_EXPORT const tag SeriesDescriptionCodeSequence;
    /** SeriesInstanceUID, 0x0020000E, UI, 1 */
    extern DICOM_EXPORT const tag SeriesInstanceUID;
    /** SeriesInStudy, 0x00201000, IS, 1, RET */
    extern DICOM_EXPORT const tag SeriesInStudy;
    /** SeriesNumber, 0x00200011, IS, 1 */
    extern DICOM_EXPORT const tag SeriesNumber;
    /** SeriesTime, 0x00080031, TM, 1 */
    extern DICOM_EXPORT const tag SeriesTime;
    /** SeriesType, 0x00541000, CS, 2 */
    extern DICOM_EXPORT const tag SeriesType;
    /** ServiceEpisodeDescription, 0x00380062, LO, 1 */
    extern DICOM_EXPORT const tag ServiceEpisodeDescription;
    /** ServiceEpisodeID, 0x00380060, LO, 1 */
    extern DICOM_EXPORT const tag ServiceEpisodeID;
    /** SettlingPhaseFrame, 0x00189624, CS, 1 */
    extern DICOM_EXPORT const tag SettlingPhaseFrame;
    /** SetupDeviceDescription, 0x300A01BA, ST, 1 */
    extern DICOM_EXPORT const tag SetupDeviceDescription;
    /** SetupDeviceLabel, 0x300A01B8, SH, 1 */
    extern DICOM_EXPORT const tag SetupDeviceLabel;
    /** SetupDeviceParameter, 0x300A01BC, DS, 1 */
    extern DICOM_EXPORT const tag SetupDeviceParameter;
    /** SetupDeviceSequence, 0x300A01B4, SQ, 1 */
    extern DICOM_EXPORT const tag SetupDeviceSequence;
    /** SetupDeviceType, 0x300A01B6, CS, 1 */
    extern DICOM_EXPORT const tag SetupDeviceType;
    /** SetupImageComment, 0x300A0402, ST, 1 */
    extern DICOM_EXPORT const tag SetupImageComment;
    /** SetupReferenceDescription, 0x300A01D0, ST, 1 */
    extern DICOM_EXPORT const tag SetupReferenceDescription;
    /** SetupTechnique, 0x300A01B0, CS, 1 */
    extern DICOM_EXPORT const tag SetupTechnique;
    /** SetupTechniqueDescription, 0x300A01B2, ST, 1 */
    extern DICOM_EXPORT const tag SetupTechniqueDescription;
    /** ShadingStyle, 0x00701701, CS, 1 */
    extern DICOM_EXPORT const tag ShadingStyle;
    /** ShadowColorCIELabValue, 0x00700247, US, 3 */
    extern DICOM_EXPORT const tag ShadowColorCIELabValue;
    /** ShadowOffsetX, 0x00700245, FL, 1 */
    extern DICOM_EXPORT const tag ShadowOffsetX;
    /** ShadowOffsetY, 0x00700246, FL, 1 */
    extern DICOM_EXPORT const tag ShadowOffsetY;
    /** ShadowOpacity, 0x00700258, FL, 1 */
    extern DICOM_EXPORT const tag ShadowOpacity;
    /** ShadowStyle, 0x00700244, CS, 1 */
    extern DICOM_EXPORT const tag ShadowStyle;
    /** ShapeType, 0x00700306, CS, 1 */
    extern DICOM_EXPORT const tag ShapeType;
    /** SharedFunctionalGroupsSequence, 0x52009229, SQ, 1 */
    extern DICOM_EXPORT const tag SharedFunctionalGroupsSequence;
    /** ShieldingDeviceDescription, 0x300A01A6, ST, 1 */
    extern DICOM_EXPORT const tag ShieldingDeviceDescription;
    /** ShieldingDeviceLabel, 0x300A01A4, SH, 1 */
    extern DICOM_EXPORT const tag ShieldingDeviceLabel;
    /** ShieldingDevicePosition, 0x300A01A8, SH, 1 */
    extern DICOM_EXPORT const tag ShieldingDevicePosition;
    /** ShieldingDeviceSequence, 0x300A01A0, SQ, 1 */
    extern DICOM_EXPORT const tag ShieldingDeviceSequence;
    /** ShieldingDeviceType, 0x300A01A2, CS, 1 */
    extern DICOM_EXPORT const tag ShieldingDeviceType;
    /** ShiftTableSize, 0x10000004, US, 1, RET */
    extern DICOM_EXPORT const range_tag ShiftTableSize;
    /** ShiftTableTriplet, 0x10000005, US, 3, RET */
    extern DICOM_EXPORT const range_tag ShiftTableTriplet;
    /** Shininess, 0x00701706, FD, 1 */
    extern DICOM_EXPORT const tag Shininess;
    /** ShortTermFluctuation, 0x00240075, FL, 1 */
    extern DICOM_EXPORT const tag ShortTermFluctuation;
    /** ShortTermFluctuationCalculated, 0x00240074, CS, 1 */
    extern DICOM_EXPORT const tag ShortTermFluctuationCalculated;
    /** ShortTermFluctuationProbability, 0x00240077, FL, 1 */
    extern DICOM_EXPORT const tag ShortTermFluctuationProbability;
    /** ShortTermFluctuationProbabilityCalculated, 0x00240076, CS, 1 */
    extern DICOM_EXPORT const tag ShortTermFluctuationProbabilityCalculated;
    /** ShotDurationTime, 0x00800004, FD, 1 */
    extern DICOM_EXPORT const tag ShotDurationTime;
    /** ShotOffsetTime, 0x00800005, FD, 1 */
    extern DICOM_EXPORT const tag ShotOffsetTime;
    /** ShowAcquisitionTechniquesFlag, 0x00720716, CS, 1 */
    extern DICOM_EXPORT const tag ShowAcquisitionTechniquesFlag;
    /** ShowGraphicAnnotationFlag, 0x00720712, CS, 1 */
    extern DICOM_EXPORT const tag ShowGraphicAnnotationFlag;
    /** ShowGrayscaleInverted, 0x00720706, CS, 1 */
    extern DICOM_EXPORT const tag ShowGrayscaleInverted;
    /** ShowImageTrueSizeFlag, 0x00720710, CS, 1 */
    extern DICOM_EXPORT const tag ShowImageTrueSizeFlag;
    /** ShowPatientDemographicsFlag, 0x00720714, CS, 1 */
    extern DICOM_EXPORT const tag ShowPatientDemographicsFlag;
    /** ShowTickLabel, 0x00700278, CS, 1 */
    extern DICOM_EXPORT const tag ShowTickLabel;
    /** ShutterLeftVerticalEdge, 0x00181602, IS, 1 */
    extern DICOM_EXPORT const tag ShutterLeftVerticalEdge;
    /** ShutterLowerHorizontalEdge, 0x00181608, IS, 1 */
    extern DICOM_EXPORT const tag ShutterLowerHorizontalEdge;
    /** ShutterOverlayGroup, 0x00181623, US, 1 */
    extern DICOM_EXPORT const tag ShutterOverlayGroup;
    /** ShutterPresentationColorCIELabValue, 0x00181624, US, 3 */
    extern DICOM_EXPORT const tag ShutterPresentationColorCIELabValue;
    /** ShutterPresentationValue, 0x00181622, US, 1 */
    extern DICOM_EXPORT const tag ShutterPresentationValue;
    /** ShutterRightVerticalEdge, 0x00181604, IS, 1 */
    extern DICOM_EXPORT const tag ShutterRightVerticalEdge;
    /** ShutterShape, 0x00181600, CS, 1 */
    extern DICOM_EXPORT const tag ShutterShape;
    /** ShutterUpperHorizontalEdge, 0x00181606, IS, 1 */
    extern DICOM_EXPORT const tag ShutterUpperHorizontalEdge;
    /** SignalDomainColumns, 0x00289003, CS, 1 */
    extern DICOM_EXPORT const tag SignalDomainColumns;
    /** SignalDomainRows, 0x00289235, CS, 1 */
    extern DICOM_EXPORT const tag SignalDomainRows;
    /** SignalToNoiseRatio, 0x00221155, FL, 1 */
    extern DICOM_EXPORT const tag SignalToNoiseRatio;
    /** Signature, 0x04000120, OB, 1 */
    extern DICOM_EXPORT const tag Signature;
    /** SimpleFrameList, 0x00081161, UL, 1 */
    extern DICOM_EXPORT const tag SimpleFrameList;
    /** SimulatedKeratometricCylinderSequence, 0x00460218, SQ, 1 */
    extern DICOM_EXPORT const tag SimulatedKeratometricCylinderSequence;
    /** SingleCollimationWidth, 0x00189306, FD, 1 */
    extern DICOM_EXPORT const tag SingleCollimationWidth;
    /** SkipBeats, 0x00181086, IS, 1 */
    extern DICOM_EXPORT const tag SkipBeats;
    /** SkipFrameRangeFlag, 0x00089460, CS, 1 */
    extern DICOM_EXPORT const tag SkipFrameRangeFlag;
    /** SlabOrientation, 0x00189105, FD, 3 */
    extern DICOM_EXPORT const tag SlabOrientation;
    /** SlabThickness, 0x00189104, FD, 1 */
    extern DICOM_EXPORT const tag SlabThickness;
    /** SliceLocation, 0x00201041, DS, 1 */
    extern DICOM_EXPORT const tag SliceLocation;
    /** SliceLocationVector, 0x00182005, DS, 1 */
    extern DICOM_EXPORT const tag SliceLocationVector;
    /** SliceProgressionDirection, 0x00540500, CS, 1 */
    extern DICOM_EXPORT const tag SliceProgressionDirection;
    /** SliceSensitivityFactor, 0x00541320, DS, 1 */
    extern DICOM_EXPORT const tag SliceSensitivityFactor;
    /** SliceThickness, 0x00180050, DS, 1 */
    extern DICOM_EXPORT const tag SliceThickness;
    /** SliceVector, 0x00540080, US, 1 */
    extern DICOM_EXPORT const tag SliceVector;
    /** SlideIdentifier, 0x004006FA, LO, 1, RET */
    extern DICOM_EXPORT const tag SlideIdentifier;
    /** SmallestImagePixelValue, 0x00280106, US or SS, 1 */
    extern DICOM_EXPORT const tag SmallestImagePixelValue;
    /** SmallestImagePixelValueInPlane, 0x00280110, US or SS, 1, RET */
    extern DICOM_EXPORT const tag SmallestImagePixelValueInPlane;
    /** SmallestPixelValueInSeries, 0x00280108, US or SS, 1 */
    extern DICOM_EXPORT const tag SmallestPixelValueInSeries;
    /** SmallestValidPixelValue, 0x00280104, US or SS, 1, RET */
    extern DICOM_EXPORT const tag SmallestValidPixelValue;
    /** SmokingStatus, 0x001021A0, CS, 1 */
    extern DICOM_EXPORT const tag SmokingStatus;
    /** SmoothingType, 0x20100080, CS, 1 */
    extern DICOM_EXPORT const tag SmoothingType;
    /** SnoutID, 0x300A030F, SH, 1 */
    extern DICOM_EXPORT const tag SnoutID;
    /** SnoutPosition, 0x300A030D, FL, 1 */
    extern DICOM_EXPORT const tag SnoutPosition;
    /** SnoutPositionTolerance, 0x300A004B, FL, 1 */
    extern DICOM_EXPORT const tag SnoutPositionTolerance;
    /** SnoutSequence, 0x300A030C, SQ, 1 */
    extern DICOM_EXPORT const tag SnoutSequence;
    /** SNRThreshold, 0x40101073, FD, 1, RET */
    extern DICOM_EXPORT const tag SNRThreshold;
    /** SoftcopyVOILUTSequence, 0x00283110, SQ, 1 */
    extern DICOM_EXPORT const tag SoftcopyVOILUTSequence;
    /** SoftTissueFocusThermalIndex, 0x00185028, DS, 1 */
    extern DICOM_EXPORT const tag SoftTissueFocusThermalIndex;
    /** SoftTissueSurfaceThermalIndex, 0x00185029, DS, 1 */
    extern DICOM_EXPORT const tag SoftTissueSurfaceThermalIndex;
    /** SoftTissueThermalIndex, 0x00185027, DS, 1 */
    extern DICOM_EXPORT const tag SoftTissueThermalIndex;
    /** SoftwareVersions, 0x00181020, LO, 1 */
    extern DICOM_EXPORT const tag SoftwareVersions;
    /** SOPAuthorizationComment, 0x01000424, LT, 1 */
    extern DICOM_EXPORT const tag SOPAuthorizationComment;
    /** SOPAuthorizationDateTime, 0x01000420, DT, 1 */
    extern DICOM_EXPORT const tag SOPAuthorizationDateTime;
    /** SOPClassesInStudy, 0x00080062, UI, 1 */
    extern DICOM_EXPORT const tag SOPClassesInStudy;
    /** SOPClassesSupported, 0x0008115A, UI, 1 */
    extern DICOM_EXPORT const tag SOPClassesSupported;
    /** SOPClassUID, 0x00080016, UI, 1 */
    extern DICOM_EXPORT const tag SOPClassUID;
    /** SOPInstanceStatus, 0x01000410, CS, 1 */
    extern DICOM_EXPORT const tag SOPInstanceStatus;
    /** SOPInstanceUID, 0x00080018, UI, 1 */
    extern DICOM_EXPORT const tag SOPInstanceUID;
    /** SOPInstanceUIDOfConcatenationSource, 0x00200242, UI, 1 */
    extern DICOM_EXPORT const tag SOPInstanceUIDOfConcatenationSource;
    /** SortByCategory, 0x00720602, CS, 1 */
    extern DICOM_EXPORT const tag SortByCategory;
    /** SortingDirection, 0x00720604, CS, 1 */
    extern DICOM_EXPORT const tag SortingDirection;
    /** SortingOperationsSequence, 0x00720600, SQ, 1 */
    extern DICOM_EXPORT const tag SortingOperationsSequence;
    /** SoundPathLength, 0x0014405A, DS, 1, RET */
    extern DICOM_EXPORT const tag SoundPathLength;
    /** SourceAcquisitionBeamNumber, 0x00189939, US, 1 */
    extern DICOM_EXPORT const tag SourceAcquisitionBeamNumber;
    /** SourceAcquisitionProtocolElementNumber, 0x00189938, US, 1 */
    extern DICOM_EXPORT const tag SourceAcquisitionProtocolElementNumber;
    /** SourceApplicationEntityTitle, 0x00020016, AE, 1 */
    extern DICOM_EXPORT const tag SourceApplicationEntityTitle;
    /** SourceApplicatorID, 0x300A0291, SH, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorID;
    /** SourceApplicatorLength, 0x300A0296, DS, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorLength;
    /** SourceApplicatorManufacturer, 0x300A0298, LO, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorManufacturer;
    /** SourceApplicatorName, 0x300A0294, LO, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorName;
    /** SourceApplicatorNumber, 0x300A0290, IS, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorNumber;
    /** SourceApplicatorStepSize, 0x300A02A0, DS, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorStepSize;
    /** SourceApplicatorTipLength, 0x300A0274, DS, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorTipLength;
    /** SourceApplicatorType, 0x300A0292, CS, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorType;
    /** SourceApplicatorWallNominalThickness, 0x300A029C, DS, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorWallNominalThickness;
    /** SourceApplicatorWallNominalTransmission, 0x300A029E, DS, 1 */
    extern DICOM_EXPORT const tag SourceApplicatorWallNominalTransmission;
    /** SourceAxisDistance, 0x300A00B4, DS, 1 */
    extern DICOM_EXPORT const tag SourceAxisDistance;
    /** SourceDescription, 0x300A021C, LO, 1 */
    extern DICOM_EXPORT const tag SourceDescription;
    /** SourceEncapsulationNominalThickness, 0x300A0222, DS, 1 */
    extern DICOM_EXPORT const tag SourceEncapsulationNominalThickness;
    /** SourceEncapsulationNominalTransmission, 0x300A0224, DS, 1 */
    extern DICOM_EXPORT const tag SourceEncapsulationNominalTransmission;
    /** SourceFrameOfReferenceUID, 0x00640003, UI, 1 */
    extern DICOM_EXPORT const tag SourceFrameOfReferenceUID;
    /** SourceHangingProtocolSequence, 0x00720012, SQ, 1 */
    extern DICOM_EXPORT const tag SourceHangingProtocolSequence;
    /** SourceImageCornealProcessedDataSequence, 0x00460244, SQ, 1 */
    extern DICOM_EXPORT const tag SourceImageCornealProcessedDataSequence;
    /** SourceImageEvidenceSequence, 0x00089154, SQ, 1 */
    extern DICOM_EXPORT const tag SourceImageEvidenceSequence;
    /** SourceImageIDs, 0x00203100, CS, 1, RET */
    extern DICOM_EXPORT const range_tag SourceImageIDs;
    /** SourceImageSequence, 0x00082112, SQ, 1 */
    extern DICOM_EXPORT const tag SourceImageSequence;
    /** SourceInstanceSequence, 0x00420013, SQ, 1 */
    extern DICOM_EXPORT const tag SourceInstanceSequence;
    /** SourceIrradiationEventSequence, 0x00083011, SQ, 1 */
    extern DICOM_EXPORT const tag SourceIrradiationEventSequence;
    /** SourceIsotopeHalfLife, 0x300A0228, DS, 1 */
    extern DICOM_EXPORT const tag SourceIsotopeHalfLife;
    /** SourceIsotopeName, 0x300A0226, LO, 1 */
    extern DICOM_EXPORT const tag SourceIsotopeName;
    /** SourceManufacturer, 0x300A0216, LO, 1 */
    extern DICOM_EXPORT const tag SourceManufacturer;
    /** SourceModelID, 0x300A021B, SH, 1 */
    extern DICOM_EXPORT const tag SourceModelID;
    /** SourceMovementType, 0x300A0288, CS, 1 */
    extern DICOM_EXPORT const tag SourceMovementType;
    /** SourceNumber, 0x300A0212, IS, 1 */
    extern DICOM_EXPORT const tag SourceNumber;
    /** SourceOfAnteriorChamberDepthDataCodeSequence, 0x00221133, SQ, 1 */
    extern DICOM_EXPORT const tag SourceOfAnteriorChamberDepthDataCodeSequence;
    /** SourceOfLensThicknessDataCodeSequence, 0x00221132, SQ, 1 */
    extern DICOM_EXPORT const tag SourceOfLensThicknessDataCodeSequence;
    /** SourceOfOphthalmicAxialLengthCodeSequence, 0x00221035, SQ, 1 */
    extern DICOM_EXPORT const tag SourceOfOphthalmicAxialLengthCodeSequence;
    /** SourceOfPreviousValues, 0x04000564, LO, 1 */
    extern DICOM_EXPORT const tag SourceOfPreviousValues;
    /** SourceOfRefractiveMeasurementsCodeSequence, 0x00221135, SQ, 1 */
    extern DICOM_EXPORT const tag SourceOfRefractiveMeasurementsCodeSequence;
    /** SourceOfRefractiveMeasurementsSequence, 0x00221134, SQ, 1 */
    extern DICOM_EXPORT const tag SourceOfRefractiveMeasurementsSequence;
    /** SourceOrientation, 0x40101060, FL, 3, RET */
    extern DICOM_EXPORT const tag SourceOrientation;
    /** SourcePatientGroupIdentificationSequence, 0x00100026, SQ, 1 */
    extern DICOM_EXPORT const tag SourcePatientGroupIdentificationSequence;
    /** SourcePosition, 0x40101061, FL, 3, RET */
    extern DICOM_EXPORT const tag SourcePosition;
    /** SourceReconstructionProtocolElementNumber, 0x0018993A, US, 1 */
    extern DICOM_EXPORT const tag SourceReconstructionProtocolElementNumber;
    /** SourceSequence, 0x300A0210, SQ, 1 */
    extern DICOM_EXPORT const tag SourceSequence;
    /** SourceSerialNumber, 0x30080105, LO, 1 */
    extern DICOM_EXPORT const tag SourceSerialNumber;
    /** SourceStrength, 0x300A022B, DS, 1 */
    extern DICOM_EXPORT const tag SourceStrength;
    /** SourceStrengthReferenceDate, 0x300A022C, DA, 1 */
    extern DICOM_EXPORT const tag SourceStrengthReferenceDate;
    /** SourceStrengthReferenceTime, 0x300A022E, TM, 1 */
    extern DICOM_EXPORT const tag SourceStrengthReferenceTime;
    /** SourceStrengthUnits, 0x300A0229, CS, 1 */
    extern DICOM_EXPORT const tag SourceStrengthUnits;
    /** SourceToApplicatorMountingPositionDistance, 0x300A0436, FL, 1 */
    extern DICOM_EXPORT const tag SourceToApplicatorMountingPositionDistance;
    /** SourceToBeamLimitingDeviceDistance, 0x300A00BA, DS, 1 */
    extern DICOM_EXPORT const tag SourceToBeamLimitingDeviceDistance;
    /** SourceToBlockTrayDistance, 0x300A00F6, DS, 1 */
    extern DICOM_EXPORT const tag SourceToBlockTrayDistance;
    /** SourceToCompensatorDistance, 0x300A02E2, DS, 1 */
    extern DICOM_EXPORT const tag SourceToCompensatorDistance;
    /** SourceToCompensatorTrayDistance, 0x300A00E6, DS, 1 */
    extern DICOM_EXPORT const tag SourceToCompensatorTrayDistance;
    /** SourceToExternalContourDistance, 0x300A0132, FL, 1 */
    extern DICOM_EXPORT const tag SourceToExternalContourDistance;
    /** SourceToGeneralAccessoryDistance, 0x300A0425, FL, 1 */
    extern DICOM_EXPORT const tag SourceToGeneralAccessoryDistance;
    /** SourceToReferenceObjectDistance, 0x30020028, DS, 1 */
    extern DICOM_EXPORT const tag SourceToReferenceObjectDistance;
    /** SourceToSurfaceDistance, 0x300A0130, DS, 1 */
    extern DICOM_EXPORT const tag SourceToSurfaceDistance;
    /** SourceToWedgeTrayDistance, 0x300A00DA, DS, 1 */
    extern DICOM_EXPORT const tag SourceToWedgeTrayDistance;
    /** SourceType, 0x300A0214, CS, 1 */
    extern DICOM_EXPORT const tag SourceType;
    /** SourceWaveformSequence, 0x003A020A, SQ, 1 */
    extern DICOM_EXPORT const tag SourceWaveformSequence;
    /** SpacingBetweenSlices, 0x00180088, DS, 1 */
    extern DICOM_EXPORT const tag SpacingBetweenSlices;
    /** SpatialLocationsPreserved, 0x0028135A, CS, 1 */
    extern DICOM_EXPORT const tag SpatialLocationsPreserved;
    /** SpatialPresaturation, 0x00189027, CS, 1 */
    extern DICOM_EXPORT const tag SpatialPresaturation;
    /** SpatialResolution, 0x00181050, DS, 1 */
    extern DICOM_EXPORT const tag SpatialResolution;
    /** SpatialTransformOfDose, 0x30040005, CS, 1 */
    extern DICOM_EXPORT const tag SpatialTransformOfDose;
    /** SpecialNeeds, 0x00380050, LO, 1 */
    extern DICOM_EXPORT const tag SpecialNeeds;
    /** SpecificAbsorptionRateDefinition, 0x00189179, CS, 1 */
    extern DICOM_EXPORT const tag SpecificAbsorptionRateDefinition;
    /** SpecificAbsorptionRateSequence, 0x00189239, SQ, 1 */
    extern DICOM_EXPORT const tag SpecificAbsorptionRateSequence;
    /** SpecificAbsorptionRateValue, 0x00189181, FD, 1 */
    extern DICOM_EXPORT const tag SpecificAbsorptionRateValue;
    /** SpecificationSelectionGuidance, 0x00820033, UT, 1 */
    extern DICOM_EXPORT const tag SpecificationSelectionGuidance;
    /** SpecificCharacterSet, 0x00080005, CS, 1 */
    extern DICOM_EXPORT const tag SpecificCharacterSet;
    /** SpecificCharacterSetOfFileSetDescriptorFile, 0x00041142, CS, 1 */
    extern DICOM_EXPORT const tag SpecificCharacterSetOfFileSetDescriptorFile;
    /** SpecifiedChannelTotalTime, 0x30080132, DS, 1 */
    extern DICOM_EXPORT const tag SpecifiedChannelTotalTime;
    /** SpecifiedMeterset, 0x30080042, DS, 1 */
    extern DICOM_EXPORT const tag SpecifiedMeterset;
    /** SpecifiedNumberOfPulses, 0x30080136, IS, 1 */
    extern DICOM_EXPORT const tag SpecifiedNumberOfPulses;
    /** SpecifiedPrimaryMeterset, 0x30080032, DS, 1 */
    extern DICOM_EXPORT const tag SpecifiedPrimaryMeterset;
    /** SpecifiedPulseRepetitionInterval, 0x3008013A, DS, 1 */
    extern DICOM_EXPORT const tag SpecifiedPulseRepetitionInterval;
    /** SpecifiedSecondaryMeterset, 0x30080033, DS, 1 */
    extern DICOM_EXPORT const tag SpecifiedSecondaryMeterset;
    /** SpecifiedTreatmentTime, 0x3008003A, DS, 1 */
    extern DICOM_EXPORT const tag SpecifiedTreatmentTime;
    /** SpecimenAccessionNumber, 0x0040050A, LO, 1, RET */
    extern DICOM_EXPORT const tag SpecimenAccessionNumber;
    /** SpecimenDescriptionSequence, 0x00400560, SQ, 1 */
    extern DICOM_EXPORT const tag SpecimenDescriptionSequence;
    /** SpecimenDescriptionSequenceTrial, 0x00400552, SQ, 1, RET */
    extern DICOM_EXPORT const tag SpecimenDescriptionSequenceTrial;
    /** SpecimenDescriptionTrial, 0x00400553, ST, 1, RET */
    extern DICOM_EXPORT const tag SpecimenDescriptionTrial;
    /** SpecimenDetailedDescription, 0x00400602, UT, 1 */
    extern DICOM_EXPORT const tag SpecimenDetailedDescription;
    /** SpecimenIdentifier, 0x00400551, LO, 1 */
    extern DICOM_EXPORT const tag SpecimenIdentifier;
    /** SpecimenLabelInImage, 0x00480010, CS, 1 */
    extern DICOM_EXPORT const tag SpecimenLabelInImage;
    /** SpecimenLocalizationContentItemSequence, 0x00400620, SQ, 1 */
    extern DICOM_EXPORT const tag SpecimenLocalizationContentItemSequence;
    /** SpecimenPreparationSequence, 0x00400610, SQ, 1 */
    extern DICOM_EXPORT const tag SpecimenPreparationSequence;
    /** SpecimenPreparationStepContentItemSequence, 0x00400612, SQ, 1 */
    extern DICOM_EXPORT const tag SpecimenPreparationStepContentItemSequence;
    /** SpecimenReferenceSequence, 0x00480110, SQ, 1 */
    extern DICOM_EXPORT const tag SpecimenReferenceSequence;
    /** SpecimenSequence, 0x00400550, SQ, 1, RET */
    extern DICOM_EXPORT const tag SpecimenSequence;
    /** SpecimenShortDescription, 0x00400600, LO, 1 */
    extern DICOM_EXPORT const tag SpecimenShortDescription;
    /** SpecimenTypeCodeSequence, 0x0040059A, SQ, 1 */
    extern DICOM_EXPORT const tag SpecimenTypeCodeSequence;
    /** SpecimenUID, 0x00400554, UI, 1 */
    extern DICOM_EXPORT const tag SpecimenUID;
    /** SpectrallySelectedExcitation, 0x00189026, CS, 1 */
    extern DICOM_EXPORT const tag SpectrallySelectedExcitation;
    /** SpectrallySelectedSuppression, 0x00189025, CS, 1 */
    extern DICOM_EXPORT const tag SpectrallySelectedSuppression;
    /** SpectralWidth, 0x00189052, FD, 1 */
    extern DICOM_EXPORT const tag SpectralWidth;
    /** SpectroscopyAcquisitionDataColumns, 0x00189127, UL, 1 */
    extern DICOM_EXPORT const tag SpectroscopyAcquisitionDataColumns;
    /** SpectroscopyAcquisitionOutOfPlanePhaseSteps, 0x00189159, UL, 1 */
    extern DICOM_EXPORT const tag SpectroscopyAcquisitionOutOfPlanePhaseSteps;
    /** SpectroscopyAcquisitionPhaseColumns, 0x00189234, UL, 1 */
    extern DICOM_EXPORT const tag SpectroscopyAcquisitionPhaseColumns;
    /** SpectroscopyAcquisitionPhaseRows, 0x00189095, UL, 1 */
    extern DICOM_EXPORT const tag SpectroscopyAcquisitionPhaseRows;
    /** SpectroscopyData, 0x56000020, OF, 1 */
    extern DICOM_EXPORT const tag SpectroscopyData;
    /** SpecularReflectionIntensity, 0x00701705, FD, 1 */
    extern DICOM_EXPORT const tag SpecularReflectionIntensity;
    /** SpherePower, 0x00460146, FD, 1 */
    extern DICOM_EXPORT const tag SpherePower;
    /** SphericalLensPower, 0x00220007, FL, 1 */
    extern DICOM_EXPORT const tag SphericalLensPower;
    /** SpiralPitchFactor, 0x00189311, FD, 1 */
    extern DICOM_EXPORT const tag SpiralPitchFactor;
    /** Spoiling, 0x00189016, CS, 1 */
    extern DICOM_EXPORT const tag Spoiling;
    /** StackID, 0x00209056, SH, 1 */
    extern DICOM_EXPORT const tag StackID;
    /** StageCodeSequence, 0x0040000A, SQ, 1 */
    extern DICOM_EXPORT const tag StageCodeSequence;
    /** StageName, 0x00082120, SH, 1 */
    extern DICOM_EXPORT const tag StageName;
    /** StageNumber, 0x00082122, IS, 1 */
    extern DICOM_EXPORT const tag StageNumber;
    /** StartAcquisitionDateTime, 0x00189516, DT, 1 */
    extern DICOM_EXPORT const tag StartAcquisitionDateTime;
    /** StartAngle, 0x00540200, DS, 1 */
    extern DICOM_EXPORT const tag StartAngle;
    /** StartCardiacTriggerCountThreshold, 0x00189717, FD, 1 */
    extern DICOM_EXPORT const tag StartCardiacTriggerCountThreshold;
    /** StartCumulativeMetersetWeight, 0x300C0008, DS, 1 */
    extern DICOM_EXPORT const tag StartCumulativeMetersetWeight;
    /** StartCumulativeTimeWeight, 0x00741407, DS, 1 */
    extern DICOM_EXPORT const tag StartCumulativeTimeWeight;
    /** StartDensityThreshold, 0x00189715, FD, 1 */
    extern DICOM_EXPORT const tag StartDensityThreshold;
    /** StartingRespiratoryAmplitude, 0x00209246, FL, 1 */
    extern DICOM_EXPORT const tag StartingRespiratoryAmplitude;
    /** StartingRespiratoryPhase, 0x00209247, CS, 1 */
    extern DICOM_EXPORT const tag StartingRespiratoryPhase;
    /** StartMeterset, 0x30080078, DS, 1 */
    extern DICOM_EXPORT const tag StartMeterset;
    /** StartRelativeDensityDifferenceThreshold, 0x00189716, FD, 1 */
    extern DICOM_EXPORT const tag StartRelativeDensityDifferenceThreshold;
    /** StartRespiratoryTriggerCountThreshold, 0x00189718, FD, 1 */
    extern DICOM_EXPORT const tag StartRespiratoryTriggerCountThreshold;
    /** StartTrim, 0x00082142, IS, 1 */
    extern DICOM_EXPORT const tag StartTrim;
    /** StationAETitle, 0x00080055, AE, 1 */
    extern DICOM_EXPORT const tag StationAETitle;
    /** StationName, 0x00081010, SH, 1 */
    extern DICOM_EXPORT const tag StationName;
    /** SteadyStatePulseSequence, 0x00189017, CS, 1 */
    extern DICOM_EXPORT const tag SteadyStatePulseSequence;
    /** SteepKeratometricAxisSequence, 0x00460074, SQ, 1 */
    extern DICOM_EXPORT const tag SteepKeratometricAxisSequence;
    /** SteeringAngle, 0x00186036, FD, 1 */
    extern DICOM_EXPORT const tag SteeringAngle;
    /** StereoBaselineAngle, 0x00220010, FL, 1 */
    extern DICOM_EXPORT const tag StereoBaselineAngle;
    /** StereoBaselineDisplacement, 0x00220011, FL, 1 */
    extern DICOM_EXPORT const tag StereoBaselineDisplacement;
    /** StereoHorizontalPixelOffset, 0x00220012, FL, 1 */
    extern DICOM_EXPORT const tag StereoHorizontalPixelOffset;
    /** StereoPairsPresent, 0x00220028, CS, 1 */
    extern DICOM_EXPORT const tag StereoPairsPresent;
    /** StereoPairsSequence, 0x00220020, SQ, 1 */
    extern DICOM_EXPORT const tag StereoPairsSequence;
    /** StereoRotation, 0x00220014, FL, 1 */
    extern DICOM_EXPORT const tag StereoRotation;
    /** StereoVerticalPixelOffset, 0x00220013, FL, 1 */
    extern DICOM_EXPORT const tag StereoVerticalPixelOffset;
    /** StimuliRetestingQuantity, 0x00240042, US, 1 */
    extern DICOM_EXPORT const tag StimuliRetestingQuantity;
    /** StimulusArea, 0x00240025, FL, 1 */
    extern DICOM_EXPORT const tag StimulusArea;
    /** StimulusColorCodeSequence, 0x00240021, SQ, 1 */
    extern DICOM_EXPORT const tag StimulusColorCodeSequence;
    /** StimulusPresentationTime, 0x00240028, FL, 1 */
    extern DICOM_EXPORT const tag StimulusPresentationTime;
    /** StimulusResults, 0x00240093, CS, 1 */
    extern DICOM_EXPORT const tag StimulusResults;
    /** StopTrim, 0x00082143, IS, 1 */
    extern DICOM_EXPORT const tag StopTrim;
    /** StorageMediaFileSetID, 0x00880130, SH, 1 */
    extern DICOM_EXPORT const tag StorageMediaFileSetID;
    /** StorageMediaFileSetUID, 0x00880140, UI, 1 */
    extern DICOM_EXPORT const tag StorageMediaFileSetUID;
    /** StorageProtocolElementSequence, 0x00189936, SQ, 1 */
    extern DICOM_EXPORT const tag StorageProtocolElementSequence;
    /** StorageProtocolElementSpecificationSequence, 0x00189935, SQ, 1 */
    extern DICOM_EXPORT const tag StorageProtocolElementSpecificationSequence;
    /** StorageURL, 0x00404073, UR, 1 */
    extern DICOM_EXPORT const tag StorageURL;
    /** StoredValueColorRangeSequence, 0x00281230, SQ, 1 */
    extern DICOM_EXPORT const tag StoredValueColorRangeSequence;
    /** STOWRSStorageSequence, 0x00404072, SQ, 1 */
    extern DICOM_EXPORT const tag STOWRSStorageSequence;
    /** StrainAdditionalInformation, 0x00100218, UT, 1 */
    extern DICOM_EXPORT const tag StrainAdditionalInformation;
    /** StrainCodeSequence, 0x00100219, SQ, 1 */
    extern DICOM_EXPORT const tag StrainCodeSequence;
    /** StrainDescription, 0x00100212, UC, 1 */
    extern DICOM_EXPORT const tag StrainDescription;
    /** StrainNomenclature, 0x00100213, LO, 1 */
    extern DICOM_EXPORT const tag StrainNomenclature;
    /** StrainSource, 0x00100217, LO, 1 */
    extern DICOM_EXPORT const tag StrainSource;
    /** StrainSourceRegistryCodeSequence, 0x00100215, SQ, 1 */
    extern DICOM_EXPORT const tag StrainSourceRegistryCodeSequence;
    /** StrainStockNumber, 0x00100214, LO, 1 */
    extern DICOM_EXPORT const tag StrainStockNumber;
    /** StrainStockSequence, 0x00100216, SQ, 1 */
    extern DICOM_EXPORT const tag StrainStockSequence;
    /** StructuredConstraintObservationSequence, 0x0082000C, SQ, 1 */
    extern DICOM_EXPORT const tag StructuredConstraintObservationSequence;
    /** StructuredDisplayBackgroundCIELabValue, 0x00720420, US, 3 */
    extern DICOM_EXPORT const tag StructuredDisplayBackgroundCIELabValue;
    /** StructuredDisplayImageBoxSequence, 0x00720422, SQ, 1 */
    extern DICOM_EXPORT const tag StructuredDisplayImageBoxSequence;
    /** StructuredDisplayTextBoxSequence, 0x00720424, SQ, 1 */
    extern DICOM_EXPORT const tag StructuredDisplayTextBoxSequence;
    /** StructureSetDate, 0x30060008, DA, 1 */
    extern DICOM_EXPORT const tag StructureSetDate;
    /** StructureSetDescription, 0x30060006, ST, 1 */
    extern DICOM_EXPORT const tag StructureSetDescription;
    /** StructureSetLabel, 0x30060002, SH, 1 */
    extern DICOM_EXPORT const tag StructureSetLabel;
    /** StructureSetName, 0x30060004, LO, 1 */
    extern DICOM_EXPORT const tag StructureSetName;
    /** StructureSetROISequence, 0x30060020, SQ, 1 */
    extern DICOM_EXPORT const tag StructureSetROISequence;
    /** StructureSetTime, 0x30060009, TM, 1 */
    extern DICOM_EXPORT const tag StructureSetTime;
    /** StudiesContainingOtherReferencedInstancesSequence, 0x00081200, SQ, 1 */
    extern DICOM_EXPORT const tag StudiesContainingOtherReferencedInstancesSequence;
    /** StudyArrivalDate, 0x00321040, DA, 1, RET */
    extern DICOM_EXPORT const tag StudyArrivalDate;
    /** StudyArrivalTime, 0x00321041, TM, 1, RET */
    extern DICOM_EXPORT const tag StudyArrivalTime;
    /** StudyComments, 0x00324000, LT, 1, RET */
    extern DICOM_EXPORT const tag StudyComments;
    /** StudyCompletionDate, 0x00321050, DA, 1, RET */
    extern DICOM_EXPORT const tag StudyCompletionDate;
    /** StudyCompletionTime, 0x00321051, TM, 1, RET */
    extern DICOM_EXPORT const tag StudyCompletionTime;
    /** StudyComponentStatusID, 0x00321055, CS, 1, RET */
    extern DICOM_EXPORT const tag StudyComponentStatusID;
    /** StudyDate, 0x00080020, DA, 1 */
    extern DICOM_EXPORT const tag StudyDate;
    /** StudyDescription, 0x00081030, LO, 1 */
    extern DICOM_EXPORT const tag StudyDescription;
    /** StudyID, 0x00200010, SH, 1 */
    extern DICOM_EXPORT const tag StudyID;
    /** StudyIDIssuer, 0x00320012, LO, 1, RET */
    extern DICOM_EXPORT const tag StudyIDIssuer;
    /** StudyInstanceUID, 0x0020000D, UI, 1 */
    extern DICOM_EXPORT const tag StudyInstanceUID;
    /** StudyPriorityID, 0x0032000C, CS, 1, RET */
    extern DICOM_EXPORT const tag StudyPriorityID;
    /** StudyReadDate, 0x00320034, DA, 1, RET */
    extern DICOM_EXPORT const tag StudyReadDate;
    /** StudyReadTime, 0x00320035, TM, 1, RET */
    extern DICOM_EXPORT const tag StudyReadTime;
    /** StudyStatusID, 0x0032000A, CS, 1, RET */
    extern DICOM_EXPORT const tag StudyStatusID;
    /** StudyTime, 0x00080030, TM, 1 */
    extern DICOM_EXPORT const tag StudyTime;
    /** StudyVerifiedDate, 0x00320032, DA, 1, RET */
    extern DICOM_EXPORT const tag StudyVerifiedDate;
    /** StudyVerifiedTime, 0x00320033, TM, 1, RET */
    extern DICOM_EXPORT const tag StudyVerifiedTime;
    /** SubjectiveRefractionLeftEyeSequence, 0x00460098, SQ, 1 */
    extern DICOM_EXPORT const tag SubjectiveRefractionLeftEyeSequence;
    /** SubjectiveRefractionRightEyeSequence, 0x00460097, SQ, 1 */
    extern DICOM_EXPORT const tag SubjectiveRefractionRightEyeSequence;
    /** SubjectRelativePositionInImage, 0x00100028, US, 3 */
    extern DICOM_EXPORT const tag SubjectRelativePositionInImage;
    /** SubscriptionListStatus, 0x00741244, CS, 1 */
    extern DICOM_EXPORT const tag SubscriptionListStatus;
    /** SubstanceAdministrationApproval, 0x00440002, CS, 1 */
    extern DICOM_EXPORT const tag SubstanceAdministrationApproval;
    /** SubstanceAdministrationDateTime, 0x00440010, DT, 1 */
    extern DICOM_EXPORT const tag SubstanceAdministrationDateTime;
    /** SubstanceAdministrationDeviceID, 0x00440012, LO, 1 */
    extern DICOM_EXPORT const tag SubstanceAdministrationDeviceID;
    /** SubstanceAdministrationNotes, 0x00440011, LO, 1 */
    extern DICOM_EXPORT const tag SubstanceAdministrationNotes;
    /** SubstanceAdministrationParameterSequence, 0x00440019, SQ, 1 */
    extern DICOM_EXPORT const tag SubstanceAdministrationParameterSequence;
    /** SubtractionItemID, 0x00289416, US, 1 */
    extern DICOM_EXPORT const tag SubtractionItemID;
    /** SupportedImageDisplayFormatsSequence, 0x200000A8, SQ, 1 */
    extern DICOM_EXPORT const tag SupportedImageDisplayFormatsSequence;
    /** SurfaceAsymmetryIndex, 0x00460232, FL, 1 */
    extern DICOM_EXPORT const tag SurfaceAsymmetryIndex;
    /** SurfaceComments, 0x00660004, LT, 1 */
    extern DICOM_EXPORT const tag SurfaceComments;
    /** SurfaceCount, 0x0066002A, UL, 1 */
    extern DICOM_EXPORT const tag SurfaceCount;
    /** SurfaceEntryPoint, 0x300A012E, DS, 3 */
    extern DICOM_EXPORT const tag SurfaceEntryPoint;
    /** SurfaceMeshPrimitivesSequence, 0x00660013, SQ, 1 */
    extern DICOM_EXPORT const tag SurfaceMeshPrimitivesSequence;
    /** SurfaceMeshZPixelOffset, 0x00221658, UL, 1 */
    extern DICOM_EXPORT const tag SurfaceMeshZPixelOffset;
    /** SurfaceModelDescriptionSequence, 0x00686360, SQ, 1 */
    extern DICOM_EXPORT const tag SurfaceModelDescriptionSequence;
    /** SurfaceModelLabel, 0x00686380, LO, 1 */
    extern DICOM_EXPORT const tag SurfaceModelLabel;
    /** SurfaceModelScalingFactor, 0x00686390, FD, 1 */
    extern DICOM_EXPORT const tag SurfaceModelScalingFactor;
    /** SurfaceNumber, 0x00660003, UL, 1 */
    extern DICOM_EXPORT const tag SurfaceNumber;
    /** SurfacePointColorCIELabValueData, 0x00800007, US, 3 */
    extern DICOM_EXPORT const tag SurfacePointColorCIELabValueData;
    /** SurfacePointPresentationValueData, 0x00800006, US, 1 */
    extern DICOM_EXPORT const tag SurfacePointPresentationValueData;
    /** SurfacePointsNormalsSequence, 0x00660012, SQ, 1 */
    extern DICOM_EXPORT const tag SurfacePointsNormalsSequence;
    /** SurfacePointsSequence, 0x00660011, SQ, 1 */
    extern DICOM_EXPORT const tag SurfacePointsSequence;
    /** SurfaceProcessing, 0x00660009, CS, 1 */
    extern DICOM_EXPORT const tag SurfaceProcessing;
    /** SurfaceProcessingAlgorithmIdentificationSequence, 0x00660035, SQ, 1 */
    extern DICOM_EXPORT const tag SurfaceProcessingAlgorithmIdentificationSequence;
    /** SurfaceProcessingDescription, 0x0066000B, LO, 1 */
    extern DICOM_EXPORT const tag SurfaceProcessingDescription;
    /** SurfaceProcessingRatio, 0x0066000A, FL, 1 */
    extern DICOM_EXPORT const tag SurfaceProcessingRatio;
    /** SurfaceRegularityIndex, 0x00460230, FL, 1 */
    extern DICOM_EXPORT const tag SurfaceRegularityIndex;
    /** SurfaceScanAcquisitionTypeCodeSequence, 0x00800001, SQ, 1 */
    extern DICOM_EXPORT const tag SurfaceScanAcquisitionTypeCodeSequence;
    /** SurfaceScanModeCodeSequence, 0x00800002, SQ, 1 */
    extern DICOM_EXPORT const tag SurfaceScanModeCodeSequence;
    /** SurfaceSequence, 0x00660002, SQ, 1 */
    extern DICOM_EXPORT const tag SurfaceSequence;
    /** SurgicalTechnique, 0x00760030, LO, 1 */
    extern DICOM_EXPORT const tag SurgicalTechnique;
    /** SUVType, 0x00541006, CS, 1 */
    extern DICOM_EXPORT const tag SUVType;
    /** SwivelRange, 0x00701A06, FD, 1 */
    extern DICOM_EXPORT const tag SwivelRange;
    /** SynchronizationChannel, 0x0018106C, US, 2 */
    extern DICOM_EXPORT const tag SynchronizationChannel;
    /** SynchronizationFrameOfReferenceUID, 0x00200200, UI, 1 */
    extern DICOM_EXPORT const tag SynchronizationFrameOfReferenceUID;
    /** SynchronizationTrigger, 0x0018106A, CS, 1 */
    extern DICOM_EXPORT const tag SynchronizationTrigger;
    /** SynchronizedImageBoxList, 0x00720432, US, 2 */
    extern DICOM_EXPORT const tag SynchronizedImageBoxList;
    /** SynchronizedScrollingSequence, 0x00720210, SQ, 1 */
    extern DICOM_EXPORT const tag SynchronizedScrollingSequence;
    /** SyringeCounts, 0x00181045, IS, 1 */
    extern DICOM_EXPORT const tag SyringeCounts;
    /** SystemStatus, 0x00287006, CS, 1 */
    extern DICOM_EXPORT const tag SystemStatus;
    /** SystemStatusComment, 0x00287007, LO, 1 */
    extern DICOM_EXPORT const tag SystemStatusComment;
    /** T2Preparation, 0x00189021, CS, 1 */
    extern DICOM_EXPORT const tag T2Preparation;
    /** TableAngle, 0x00181138, DS, 1 */
    extern DICOM_EXPORT const tag TableAngle;
    /** TableCradleTiltAngle, 0x00189471, FL, 1 */
    extern DICOM_EXPORT const tag TableCradleTiltAngle;
    /** TableFeedPerRotation, 0x00189310, FD, 1 */
    extern DICOM_EXPORT const tag TableFeedPerRotation;
    /** TableFrameOfReferenceUID, 0x00209313, UI, 1 */
    extern DICOM_EXPORT const tag TableFrameOfReferenceUID;
    /** TableHeadTiltAngle, 0x00189470, FL, 1 */
    extern DICOM_EXPORT const tag TableHeadTiltAngle;
    /** TableHeight, 0x00181130, DS, 1 */
    extern DICOM_EXPORT const tag TableHeight;
    /** TableHorizontalRotationAngle, 0x00189469, FL, 1 */
    extern DICOM_EXPORT const tag TableHorizontalRotationAngle;
    /** TableLateralIncrement, 0x00181136, DS, 1 */
    extern DICOM_EXPORT const tag TableLateralIncrement;
    /** TableLongitudinalIncrement, 0x00181137, DS, 1 */
    extern DICOM_EXPORT const tag TableLongitudinalIncrement;
    /** TableMotion, 0x00181134, CS, 1 */
    extern DICOM_EXPORT const tag TableMotion;
    /** TableOfParameterValues, 0x0018605A, FL, 1 */
    extern DICOM_EXPORT const tag TableOfParameterValues;
    /** TableOfPixelValues, 0x00186058, UL, 1 */
    extern DICOM_EXPORT const tag TableOfPixelValues;
    /** TableOfXBreakPoints, 0x00186052, UL, 1 */
    extern DICOM_EXPORT const tag TableOfXBreakPoints;
    /** TableOfYBreakPoints, 0x00186054, FD, 1 */
    extern DICOM_EXPORT const tag TableOfYBreakPoints;
    /** TablePosition, 0x00189327, FD, 1 */
    extern DICOM_EXPORT const tag TablePosition;
    /** TablePositionSequence, 0x00189406, SQ, 1 */
    extern DICOM_EXPORT const tag TablePositionSequence;
    /** TableSpeed, 0x00189309, FD, 1 */
    extern DICOM_EXPORT const tag TableSpeed;
    /** TableTopEccentricAdjustedAngle, 0x0074102B, FD, 1 */
    extern DICOM_EXPORT const tag TableTopEccentricAdjustedAngle;
    /** TableTopEccentricAngle, 0x300A0125, DS, 1 */
    extern DICOM_EXPORT const tag TableTopEccentricAngle;
    /** TableTopEccentricAngleTolerance, 0x300A004E, DS, 1 */
    extern DICOM_EXPORT const tag TableTopEccentricAngleTolerance;
    /** TableTopEccentricAxisDistance, 0x300A0124, DS, 1 */
    extern DICOM_EXPORT const tag TableTopEccentricAxisDistance;
    /** TableTopEccentricRotationDirection, 0x300A0126, CS, 1 */
    extern DICOM_EXPORT const tag TableTopEccentricRotationDirection;
    /** TableTopLateralAdjustedPosition, 0x00741028, FD, 1 */
    extern DICOM_EXPORT const tag TableTopLateralAdjustedPosition;
    /** TableTopLateralPosition, 0x300A012A, DS, 1 */
    extern DICOM_EXPORT const tag TableTopLateralPosition;
    /** TableTopLateralPositionTolerance, 0x300A0053, DS, 1 */
    extern DICOM_EXPORT const tag TableTopLateralPositionTolerance;
    /** TableTopLateralSetupDisplacement, 0x300A01D6, DS, 1 */
    extern DICOM_EXPORT const tag TableTopLateralSetupDisplacement;
    /** TableTopLongitudinalAdjustedPosition, 0x00741027, FD, 1 */
    extern DICOM_EXPORT const tag TableTopLongitudinalAdjustedPosition;
    /** TableTopLongitudinalPosition, 0x300A0129, DS, 1 */
    extern DICOM_EXPORT const tag TableTopLongitudinalPosition;
    /** TableTopLongitudinalPositionTolerance, 0x300A0052, DS, 1 */
    extern DICOM_EXPORT const tag TableTopLongitudinalPositionTolerance;
    /** TableTopLongitudinalSetupDisplacement, 0x300A01D4, DS, 1 */
    extern DICOM_EXPORT const tag TableTopLongitudinalSetupDisplacement;
    /** TableTopPitchAdjustedAngle, 0x0074102C, FD, 1 */
    extern DICOM_EXPORT const tag TableTopPitchAdjustedAngle;
    /** TableTopPitchAngle, 0x300A0140, FL, 1 */
    extern DICOM_EXPORT const tag TableTopPitchAngle;
    /** TableTopPitchAngleTolerance, 0x300A004F, FL, 1 */
    extern DICOM_EXPORT const tag TableTopPitchAngleTolerance;
    /** TableTopPitchRotationDirection, 0x300A0142, CS, 1 */
    extern DICOM_EXPORT const tag TableTopPitchRotationDirection;
    /** TableTopRollAdjustedAngle, 0x0074102D, FD, 1 */
    extern DICOM_EXPORT const tag TableTopRollAdjustedAngle;
    /** TableTopRollAngle, 0x300A0144, FL, 1 */
    extern DICOM_EXPORT const tag TableTopRollAngle;
    /** TableTopRollAngleTolerance, 0x300A0050, FL, 1 */
    extern DICOM_EXPORT const tag TableTopRollAngleTolerance;
    /** TableTopRollRotationDirection, 0x300A0146, CS, 1 */
    extern DICOM_EXPORT const tag TableTopRollRotationDirection;
    /** TableTopVerticalAdjustedPosition, 0x00741026, FD, 1 */
    extern DICOM_EXPORT const tag TableTopVerticalAdjustedPosition;
    /** TableTopVerticalPosition, 0x300A0128, DS, 1 */
    extern DICOM_EXPORT const tag TableTopVerticalPosition;
    /** TableTopVerticalPositionTolerance, 0x300A0051, DS, 1 */
    extern DICOM_EXPORT const tag TableTopVerticalPositionTolerance;
    /** TableTopVerticalSetupDisplacement, 0x300A01D2, DS, 1 */
    extern DICOM_EXPORT const tag TableTopVerticalSetupDisplacement;
    /** TableTraverse, 0x00181131, DS, 1 */
    extern DICOM_EXPORT const tag TableTraverse;
    /** TableType, 0x0018113A, CS, 1 */
    extern DICOM_EXPORT const tag TableType;
    /** TableVerticalIncrement, 0x00181135, DS, 1 */
    extern DICOM_EXPORT const tag TableVerticalIncrement;
    /** TableXPositionToIsocenter, 0x00189466, FL, 1 */
    extern DICOM_EXPORT const tag TableXPositionToIsocenter;
    /** TableYPositionToIsocenter, 0x00189467, FL, 1 */
    extern DICOM_EXPORT const tag TableYPositionToIsocenter;
    /** TableZPositionToIsocenter, 0x00189468, FL, 1 */
    extern DICOM_EXPORT const tag TableZPositionToIsocenter;
    /** TagAngleFirstAxis, 0x00189019, FD, 1 */
    extern DICOM_EXPORT const tag TagAngleFirstAxis;
    /** TagAngleSecondAxis, 0x00189219, SS, 1 */
    extern DICOM_EXPORT const tag TagAngleSecondAxis;
    /** Tagging, 0x00189028, CS, 1 */
    extern DICOM_EXPORT const tag Tagging;
    /** TaggingDelay, 0x00189184, FD, 1 */
    extern DICOM_EXPORT const tag TaggingDelay;
    /** TagSpacingFirstDimension, 0x00189030, FD, 1 */
    extern DICOM_EXPORT const tag TagSpacingFirstDimension;
    /** TagSpacingSecondDimension, 0x00189218, FD, 1 */
    extern DICOM_EXPORT const tag TagSpacingSecondDimension;
    /** TagThickness, 0x00189035, FD, 1 */
    extern DICOM_EXPORT const tag TagThickness;
    /** TangentialPower, 0x00460250, FL, 1 */
    extern DICOM_EXPORT const tag TangentialPower;
    /** TargetExposureIndex, 0x00181412, DS, 1 */
    extern DICOM_EXPORT const tag TargetExposureIndex;
    /** TargetFrameOfReferenceUID, 0x0018991E, UI, 1 */
    extern DICOM_EXPORT const tag TargetFrameOfReferenceUID;
    /** TargetLabel, 0x00182045, SH, 1 */
    extern DICOM_EXPORT const tag TargetLabel;
    /** TargetLuminanceCharacteristicsSequence, 0x00287008, SQ, 1 */
    extern DICOM_EXPORT const tag TargetLuminanceCharacteristicsSequence;
    /** TargetMaterialSequence, 0x40101072, SQ, 1, RET */
    extern DICOM_EXPORT const tag TargetMaterialSequence;
    /** TargetMaximumDose, 0x300A0027, DS, 1 */
    extern DICOM_EXPORT const tag TargetMaximumDose;
    /** TargetMaximumLuminance, 0x0028701E, FL, 1 */
    extern DICOM_EXPORT const tag TargetMaximumLuminance;
    /** TargetMinimumDose, 0x300A0025, DS, 1 */
    extern DICOM_EXPORT const tag TargetMinimumDose;
    /** TargetMinimumLuminance, 0x0028701D, FL, 1 */
    extern DICOM_EXPORT const tag TargetMinimumLuminance;
    /** TargetPositionReferenceIndicator, 0x0020103F, LO, 1 */
    extern DICOM_EXPORT const tag TargetPositionReferenceIndicator;
    /** TargetPrescriptionDose, 0x300A0026, DS, 1 */
    extern DICOM_EXPORT const tag TargetPrescriptionDose;
    /** TargetRefraction, 0x00221037, FL, 1 */
    extern DICOM_EXPORT const tag TargetRefraction;
    /** TargetUID, 0x00182042, UI, 1 */
    extern DICOM_EXPORT const tag TargetUID;
    /** TargetUnderdoseVolumeFraction, 0x300A0028, DS, 1 */
    extern DICOM_EXPORT const tag TargetUnderdoseVolumeFraction;
    /** TDRType, 0x40101027, CS, 1, RET */
    extern DICOM_EXPORT const tag TDRType;
    /** TelephoneNumberTrial, 0x0040A354, LO, 1, RET */
    extern DICOM_EXPORT const tag TelephoneNumberTrial;
    /** TemplateExtensionCreatorUID, 0x0040DB0D, UI, 1, RET */
    extern DICOM_EXPORT const tag TemplateExtensionCreatorUID;
    /** TemplateExtensionFlag, 0x0040DB0B, CS, 1, RET */
    extern DICOM_EXPORT const tag TemplateExtensionFlag;
    /** TemplateExtensionOrganizationUID, 0x0040DB0C, UI, 1, RET */
    extern DICOM_EXPORT const tag TemplateExtensionOrganizationUID;
    /** TemplateIdentifier, 0x0040DB00, CS, 1 */
    extern DICOM_EXPORT const tag TemplateIdentifier;
    /** TemplateLocalVersion, 0x0040DB07, DT, 1, RET */
    extern DICOM_EXPORT const tag TemplateLocalVersion;
    /** TemplateName, 0x300A0244, LO, 1 */
    extern DICOM_EXPORT const tag TemplateName;
    /** TemplateNumber, 0x300A0240, IS, 1 */
    extern DICOM_EXPORT const tag TemplateNumber;
    /** TemplateType, 0x300A0242, SH, 1 */
    extern DICOM_EXPORT const tag TemplateType;
    /** TemplateVersion, 0x0040DB06, DT, 1, RET */
    extern DICOM_EXPORT const tag TemplateVersion;
    /** TemporalPositionIdentifier, 0x00200100, IS, 1 */
    extern DICOM_EXPORT const tag TemporalPositionIdentifier;
    /** TemporalPositionIndex, 0x00209128, UL, 1 */
    extern DICOM_EXPORT const tag TemporalPositionIndex;
    /** TemporalPositionSequence, 0x00209310, SQ, 1 */
    extern DICOM_EXPORT const tag TemporalPositionSequence;
    /** TemporalPositionTimeOffset, 0x0020930D, FD, 1 */
    extern DICOM_EXPORT const tag TemporalPositionTimeOffset;
    /** TemporalRangeType, 0x0040A130, CS, 1 */
    extern DICOM_EXPORT const tag TemporalRangeType;
    /** TemporalResolution, 0x00200110, DS, 1 */
    extern DICOM_EXPORT const tag TemporalResolution;
    /** TerminationCardiacTriggerCountThreshold, 0x00189723, FD, 1 */
    extern DICOM_EXPORT const tag TerminationCardiacTriggerCountThreshold;
    /** TerminationCountsThreshold, 0x00189719, FD, 1 */
    extern DICOM_EXPORT const tag TerminationCountsThreshold;
    /** TerminationDensityThreshold, 0x00189720, FD, 1 */
    extern DICOM_EXPORT const tag TerminationDensityThreshold;
    /** TerminationRelativeDensityThreshold, 0x00189721, FD, 1 */
    extern DICOM_EXPORT const tag TerminationRelativeDensityThreshold;
    /** TerminationRespiratoryTriggerCountThreshold, 0x00189724, FD, 1 */
    extern DICOM_EXPORT const tag TerminationRespiratoryTriggerCountThreshold;
    /** TerminationTimeThreshold, 0x00189722, FD, 1 */
    extern DICOM_EXPORT const tag TerminationTimeThreshold;
    /** TestImageValidation, 0x0028702B, CS, 1 */
    extern DICOM_EXPORT const tag TestImageValidation;
    /** TestPatternCodeSequence, 0x0028702C, SQ, 1 */
    extern DICOM_EXPORT const tag TestPatternCodeSequence;
    /** TestPointNormalsDataFlag, 0x00240057, CS, 1 */
    extern DICOM_EXPORT const tag TestPointNormalsDataFlag;
    /** TestPointNormalsSequence, 0x00240058, SQ, 1 */
    extern DICOM_EXPORT const tag TestPointNormalsSequence;
    /** TestResult, 0x00287029, CS, 1 */
    extern DICOM_EXPORT const tag TestResult;
    /** TestResultComment, 0x0028702A, LO, 1 */
    extern DICOM_EXPORT const tag TestResultComment;
    /** TextColorCIELabValue, 0x00700241, US, 3 */
    extern DICOM_EXPORT const tag TextColorCIELabValue;
    /** TextComments, 0x40004000, LT, 1, RET */
    extern DICOM_EXPORT const tag TextComments;
    /** TextObjectSequence, 0x00700008, SQ, 1 */
    extern DICOM_EXPORT const tag TextObjectSequence;
    /** TextString, 0x20300020, LO, 1 */
    extern DICOM_EXPORT const tag TextString;
    /** TextStyleSequence, 0x00700231, SQ, 1 */
    extern DICOM_EXPORT const tag TextStyleSequence;
    /** TextureLabel, 0x00800009, SH, 1 */
    extern DICOM_EXPORT const tag TextureLabel;
    /** TextValue, 0x0040A160, UT, 1 */
    extern DICOM_EXPORT const tag TextValue;
    /** TherapyDescription, 0x00180039, CS, 1, RET */
    extern DICOM_EXPORT const tag TherapyDescription;
    /** TherapyType, 0x00180037, CS, 1, RET */
    extern DICOM_EXPORT const tag TherapyType;
    /** ThreatCategory, 0x40101012, CS, 1, RET */
    extern DICOM_EXPORT const tag ThreatCategory;
    /** ThreatCategoryDescription, 0x40101013, LT, 1, RET */
    extern DICOM_EXPORT const tag ThreatCategoryDescription;
    /** ThreatDetectionAlgorithmandVersion, 0x40101029, LO, 1, RET */
    extern DICOM_EXPORT const tag ThreatDetectionAlgorithmandVersion;
    /** ThreatROIBase, 0x40101004, FL, 3, RET */
    extern DICOM_EXPORT const tag ThreatROIBase;
    /** ThreatROIBitmap, 0x40101006, OB, 1, RET */
    extern DICOM_EXPORT const tag ThreatROIBitmap;
    /** ThreatROIExtents, 0x40101005, FL, 3, RET */
    extern DICOM_EXPORT const tag ThreatROIExtents;
    /** ThreatROIVoxelSequence, 0x40101001, SQ, 1, RET */
    extern DICOM_EXPORT const tag ThreatROIVoxelSequence;
    /** ThreatSequence, 0x40101011, SQ, 1, RET */
    extern DICOM_EXPORT const tag ThreatSequence;
    /** ThreeDDegreeOfFreedomAxis, 0x00686490, FD, 3 */
    extern DICOM_EXPORT const tag ThreeDDegreeOfFreedomAxis;
    /** ThreeDImplantTemplateGroupMemberMatchingAxes, 0x00780060, FD, 9 */
    extern DICOM_EXPORT const tag ThreeDImplantTemplateGroupMemberMatchingAxes;
    /** ThreeDImplantTemplateGroupMemberMatchingPoint, 0x00780050, FD, 3 */
    extern DICOM_EXPORT const tag ThreeDImplantTemplateGroupMemberMatchingPoint;
    /** ThreeDLineCoordinates, 0x006865D0, FD, 6 */
    extern DICOM_EXPORT const tag ThreeDLineCoordinates;
    /** ThreeDMatingAxes, 0x006864D0, FD, 9 */
    extern DICOM_EXPORT const tag ThreeDMatingAxes;
    /** ThreeDMatingPoint, 0x006864C0, FD, 3 */
    extern DICOM_EXPORT const tag ThreeDMatingPoint;
    /** ThreeDPlaneNormal, 0x00686620, FD, 3 */
    extern DICOM_EXPORT const tag ThreeDPlaneNormal;
    /** ThreeDPlaneOrigin, 0x00686610, FD, 3 */
    extern DICOM_EXPORT const tag ThreeDPlaneOrigin;
    /** ThreeDPointCoordinates, 0x00686590, FD, 3 */
    extern DICOM_EXPORT const tag ThreeDPointCoordinates;
    /** ThreeDRenderingType, 0x00720520, CS, 1 */
    extern DICOM_EXPORT const tag ThreeDRenderingType;
    /** ThresholdDensity, 0x20400100, CS, 1, RET */
    extern DICOM_EXPORT const tag ThresholdDensity;
    /** ThresholdSequence, 0x00701B11, SQ, 1 */
    extern DICOM_EXPORT const tag ThresholdSequence;
    /** ThresholdType, 0x00701B13, CS, 1 */
    extern DICOM_EXPORT const tag ThresholdType;
    /** ThresholdValue, 0x00701B14, FD, 1 */
    extern DICOM_EXPORT const tag ThresholdValue;
    /** ThresholdValueSequence, 0x00701B12, SQ, 1 */
    extern DICOM_EXPORT const tag ThresholdValueSequence;
    /** TickAlignment, 0x00700274, CS, 1 */
    extern DICOM_EXPORT const tag TickAlignment;
    /** TickLabel, 0x00700289, SH, 1 */
    extern DICOM_EXPORT const tag TickLabel;
    /** TickLabelAlignment, 0x00700279, CS, 1 */
    extern DICOM_EXPORT const tag TickLabelAlignment;
    /** TickPosition, 0x00700288, FL, 1 */
    extern DICOM_EXPORT const tag TickPosition;
    /** TIDOffset, 0x00286120, SS, 1 */
    extern DICOM_EXPORT const tag TIDOffset;
    /** Time, 0x0040A122, TM, 1 */
    extern DICOM_EXPORT const tag Time;
    /** TimeBasedImageSetsSequence, 0x00720030, SQ, 1 */
    extern DICOM_EXPORT const tag TimeBasedImageSetsSequence;
    /** TimeDistributionProtocol, 0x00181802, CS, 1 */
    extern DICOM_EXPORT const tag TimeDistributionProtocol;
    /** TimeDomainFiltering, 0x00189065, CS, 1 */
    extern DICOM_EXPORT const tag TimeDomainFiltering;
    /** TimeOfDocumentCreationOrVerbalTransactionTrial, 0x0040A112, TM, 1, RET */
    extern DICOM_EXPORT const tag TimeOfDocumentCreationOrVerbalTransactionTrial;
    /** TimeOfFlightContrast, 0x00189015, CS, 1 */
    extern DICOM_EXPORT const tag TimeOfFlightContrast;
    /** TimeOfFlightInformationUsed, 0x00189755, CS, 1 */
    extern DICOM_EXPORT const tag TimeOfFlightInformationUsed;
    /** TimeOfGainCalibration, 0x00143077, TM, 1, RET */
    extern DICOM_EXPORT const tag TimeOfGainCalibration;
    /** TimeOfLastCalibration, 0x00181201, TM, 1 */
    extern DICOM_EXPORT const tag TimeOfLastCalibration;
    /** TimeOfLastDetectorCalibration, 0x0018700E, TM, 1 */
    extern DICOM_EXPORT const tag TimeOfLastDetectorCalibration;
    /** TimeOfSecondaryCapture, 0x00181014, TM, 1 */
    extern DICOM_EXPORT const tag TimeOfSecondaryCapture;
    /** TimeRange, 0x00081163, FD, 2 */
    extern DICOM_EXPORT const tag TimeRange;
    /** TimeSeriesBlending, 0x00701B07, CS, 1 */
    extern DICOM_EXPORT const tag TimeSeriesBlending;
    /** TimeSliceVector, 0x00540100, US, 1 */
    extern DICOM_EXPORT const tag TimeSliceVector;
    /** TimeSlotInformationSequence, 0x00540072, SQ, 1 */
    extern DICOM_EXPORT const tag TimeSlotInformationSequence;
    /** TimeSlotNumber, 0x00200017, IS, 1, RET */
    extern DICOM_EXPORT const tag TimeSlotNumber;
    /** TimeSlotTime, 0x00540073, DS, 1 */
    extern DICOM_EXPORT const tag TimeSlotTime;
    /** TimeSlotVector, 0x00540070, US, 1 */
    extern DICOM_EXPORT const tag TimeSlotVector;
    /** TimeSource, 0x00181801, SH, 1 */
    extern DICOM_EXPORT const tag TimeSource;
    /** TimezoneOffsetFromUTC, 0x00080201, SH, 1 */
    extern DICOM_EXPORT const tag TimezoneOffsetFromUTC;
    /** TIPType, 0x40101039, CS, 1, RET */
    extern DICOM_EXPORT const tag TIPType;
    /** TissueHeterogeneityCorrection, 0x30040014, CS, 1 */
    extern DICOM_EXPORT const tag TissueHeterogeneityCorrection;
    /** TMLinePositionX0, 0x0018603D, SL, 1 */
    extern DICOM_EXPORT const tag TMLinePositionX0;
    /** TMLinePositionX0Retired, 0x0018603C, UL, 1, RET */
    extern DICOM_EXPORT const tag TMLinePositionX0Retired;
    /** TMLinePositionX1, 0x00186041, SL, 1 */
    extern DICOM_EXPORT const tag TMLinePositionX1;
    /** TMLinePositionX1Retired, 0x00186040, UL, 1, RET */
    extern DICOM_EXPORT const tag TMLinePositionX1Retired;
    /** TMLinePositionY0, 0x0018603F, SL, 1 */
    extern DICOM_EXPORT const tag TMLinePositionY0;
    /** TMLinePositionY0Retired, 0x0018603E, UL, 1, RET */
    extern DICOM_EXPORT const tag TMLinePositionY0Retired;
    /** TMLinePositionY1, 0x00186043, SL, 1 */
    extern DICOM_EXPORT const tag TMLinePositionY1;
    /** TMLinePositionY1Retired, 0x00186042, UL, 1, RET */
    extern DICOM_EXPORT const tag TMLinePositionY1Retired;
    /** ToleranceTableLabel, 0x300A0043, SH, 1 */
    extern DICOM_EXPORT const tag ToleranceTableLabel;
    /** ToleranceTableNumber, 0x300A0042, IS, 1 */
    extern DICOM_EXPORT const tag ToleranceTableNumber;
    /** ToleranceTableSequence, 0x300A0040, SQ, 1 */
    extern DICOM_EXPORT const tag ToleranceTableSequence;
    /** TomoAngle, 0x00181470, DS, 1 */
    extern DICOM_EXPORT const tag TomoAngle;
    /** TomoClass, 0x00181491, CS, 1 */
    extern DICOM_EXPORT const tag TomoClass;
    /** TomoLayerHeight, 0x00181460, DS, 1 */
    extern DICOM_EXPORT const tag TomoLayerHeight;
    /** TomoTime, 0x00181480, DS, 1 */
    extern DICOM_EXPORT const tag TomoTime;
    /** TomoType, 0x00181490, CS, 1 */
    extern DICOM_EXPORT const tag TomoType;
    /** TopicAuthor, 0x00880910, LO, 1, RET */
    extern DICOM_EXPORT const tag TopicAuthor;
    /** TopicKeywords, 0x00880912, LO, 1, RET */
    extern DICOM_EXPORT const tag TopicKeywords;
    /** TopicSubject, 0x00880906, ST, 1, RET */
    extern DICOM_EXPORT const tag TopicSubject;
    /** TopicTitle, 0x00880904, LO, 1, RET */
    extern DICOM_EXPORT const tag TopicTitle;
    /** TopLeftHandCornerOfLocalizerArea, 0x00480201, US, 2 */
    extern DICOM_EXPORT const tag TopLeftHandCornerOfLocalizerArea;
    /** TotalAperture, 0x00145101, DS, 1, RET */
    extern DICOM_EXPORT const tag TotalAperture;
    /** TotalBlockTrayFactor, 0x300A00F2, DS, 1 */
    extern DICOM_EXPORT const tag TotalBlockTrayFactor;
    /** TotalBlockTrayWaterEquivalentThickness, 0x300A00F3, FL, 1 */
    extern DICOM_EXPORT const tag TotalBlockTrayWaterEquivalentThickness;
    /** TotalCollimationWidth, 0x00189307, FD, 1 */
    extern DICOM_EXPORT const tag TotalCollimationWidth;
    /** TotalCompensatorTrayFactor, 0x300A00E2, DS, 1 */
    extern DICOM_EXPORT const tag TotalCompensatorTrayFactor;
    /** TotalCompensatorTrayWaterEquivalentThickness, 0x300A02E3, FL, 1 */
    extern DICOM_EXPORT const tag TotalCompensatorTrayWaterEquivalentThickness;
    /** TotalGain, 0x00185040, DS, 1, RET */
    extern DICOM_EXPORT const tag TotalGain;
    /** TotalNumberOfExposures, 0x00400301, US, 1, RET */
    extern DICOM_EXPORT const tag TotalNumberOfExposures;
    /** TotalNumberOfPiecesOfMediaCreated, 0x2200000B, US, 1 */
    extern DICOM_EXPORT const tag TotalNumberOfPiecesOfMediaCreated;
    /** TotalPixelMatrixColumns, 0x00480006, UL, 1 */
    extern DICOM_EXPORT const tag TotalPixelMatrixColumns;
    /** TotalPixelMatrixFocalPlanes, 0x00480303, UL, 1 */
    extern DICOM_EXPORT const tag TotalPixelMatrixFocalPlanes;
    /** TotalPixelMatrixOriginSequence, 0x00480008, SQ, 1 */
    extern DICOM_EXPORT const tag TotalPixelMatrixOriginSequence;
    /** TotalPixelMatrixRows, 0x00480007, UL, 1 */
    extern DICOM_EXPORT const tag TotalPixelMatrixRows;
    /** TotalProcessingTime, 0x40101069, FL, 1, RET */
    extern DICOM_EXPORT const tag TotalProcessingTime;
    /** TotalReferenceAirKerma, 0x300A0250, DS, 1 */
    extern DICOM_EXPORT const tag TotalReferenceAirKerma;
    /** TotalTime, 0x5000200A, UL, 1, RET */
    extern DICOM_EXPORT const range_tag TotalTime;
    /** TotalTimeOfFluoroscopy, 0x00400300, US, 1, RET */
    extern DICOM_EXPORT const tag TotalTimeOfFluoroscopy;
    /** TotalWedgeTrayWaterEquivalentThickness, 0x300A00D7, FL, 1 */
    extern DICOM_EXPORT const tag TotalWedgeTrayWaterEquivalentThickness;
    /** TrackingAlgorithmIdentificationSequence, 0x00660104, SQ, 1 */
    extern DICOM_EXPORT const tag TrackingAlgorithmIdentificationSequence;
    /** TrackingID, 0x00620020, UT, 1 */
    extern DICOM_EXPORT const tag TrackingID;
    /** TrackingUID, 0x00620021, UI, 1 */
    extern DICOM_EXPORT const tag TrackingUID;
    /** TrackPointIndexList, 0x00660129, OL, 1 */
    extern DICOM_EXPORT const tag TrackPointIndexList;
    /** TrackSequence, 0x00660102, SQ, 1 */
    extern DICOM_EXPORT const tag TrackSequence;
    /** TrackSetAnatomicalTypeCodeSequence, 0x00660108, SQ, 1 */
    extern DICOM_EXPORT const tag TrackSetAnatomicalTypeCodeSequence;
    /** TrackSetDescription, 0x00660107, UT, 1 */
    extern DICOM_EXPORT const tag TrackSetDescription;
    /** TrackSetLabel, 0x00660106, LO, 1 */
    extern DICOM_EXPORT const tag TrackSetLabel;
    /** TrackSetNumber, 0x00660105, UL, 1 */
    extern DICOM_EXPORT const tag TrackSetNumber;
    /** TrackSetSequence, 0x00660101, SQ, 1 */
    extern DICOM_EXPORT const tag TrackSetSequence;
    /** TrackSetStatisticsSequence, 0x00660124, SQ, 1 */
    extern DICOM_EXPORT const tag TrackSetStatisticsSequence;
    /** TrackStatisticsSequence, 0x00660130, SQ, 1 */
    extern DICOM_EXPORT const tag TrackStatisticsSequence;
    /** TransactionUID, 0x00081195, UI, 1 */
    extern DICOM_EXPORT const tag TransactionUID;
    /** TransducerApplicationCodeSequence, 0x0018980F, SQ, 1 */
    extern DICOM_EXPORT const tag TransducerApplicationCodeSequence;
    /** TransducerBeamSteeringCodeSequence, 0x0018980E, SQ, 1 */
    extern DICOM_EXPORT const tag TransducerBeamSteeringCodeSequence;
    /** TransducerData, 0x00185010, LO, 1 */
    extern DICOM_EXPORT const tag TransducerData;
    /** TransducerFrequency, 0x00186030, UL, 1 */
    extern DICOM_EXPORT const tag TransducerFrequency;
    /** TransducerGeometryCodeSequence, 0x0018980D, SQ, 1 */
    extern DICOM_EXPORT const tag TransducerGeometryCodeSequence;
    /** TransducerOrientation, 0x00082204, CS, 1, RET */
    extern DICOM_EXPORT const tag TransducerOrientation;
    /** TransducerOrientationModifierSequence, 0x00082246, SQ, 1, RET */
    extern DICOM_EXPORT const tag TransducerOrientationModifierSequence;
    /** TransducerOrientationSequence, 0x00082244, SQ, 1, RET */
    extern DICOM_EXPORT const tag TransducerOrientationSequence;
    /** TransducerPosition, 0x00082200, CS, 1, RET */
    extern DICOM_EXPORT const tag TransducerPosition;
    /** TransducerPositionModifierSequence, 0x00082242, SQ, 1, RET */
    extern DICOM_EXPORT const tag TransducerPositionModifierSequence;
    /** TransducerPositionSequence, 0x00082240, SQ, 1, RET */
    extern DICOM_EXPORT const tag TransducerPositionSequence;
    /** TransducerScanPatternCodeSequence, 0x00189809, SQ, 1 */
    extern DICOM_EXPORT const tag TransducerScanPatternCodeSequence;
    /** TransducerType, 0x00186031, CS, 1 */
    extern DICOM_EXPORT const tag TransducerType;
    /** TransferSyntaxUID, 0x00020010, UI, 1 */
    extern DICOM_EXPORT const tag TransferSyntaxUID;
    /** TransferTubeLength, 0x300A02A4, DS, 1 */
    extern DICOM_EXPORT const tag TransferTubeLength;
    /** TransferTubeNumber, 0x300A02A2, IS, 1 */
    extern DICOM_EXPORT const tag TransferTubeNumber;
    /** TransformationAlgorithmSequence, 0x00221513, SQ, 1 */
    extern DICOM_EXPORT const tag TransformationAlgorithmSequence;
    /** TransformationMethodCodeSequence, 0x00221512, SQ, 1 */
    extern DICOM_EXPORT const tag TransformationMethodCodeSequence;
    /** TransformDescription, 0x00142222, ST, 1, RET */
    extern DICOM_EXPORT const tag TransformDescription;
    /** TransformedAxisUnits, 0x00142228, CS, 1, RET */
    extern DICOM_EXPORT const tag TransformedAxisUnits;
    /** TransformLabel, 0x00280400, LO, 1, RET */
    extern DICOM_EXPORT const tag TransformLabel;
    /** TransformNumberOfAxes, 0x00142224, IS, 1, RET */
    extern DICOM_EXPORT const tag TransformNumberOfAxes;
    /** TransformOrderOfAxes, 0x00142226, IS, 1, RET */
    extern DICOM_EXPORT const tag TransformOrderOfAxes;
    /** TransformVersionNumber, 0x00280401, LO, 1, RET */
    extern DICOM_EXPORT const tag TransformVersionNumber;
    /** TranslationRateX, 0x0014409C, DS, 1, RET */
    extern DICOM_EXPORT const tag TranslationRateX;
    /** TranslationRateY, 0x0014409D, DS, 1, RET */
    extern DICOM_EXPORT const tag TranslationRateY;
    /** TransmitCoilManufacturerName, 0x00189050, LO, 1 */
    extern DICOM_EXPORT const tag TransmitCoilManufacturerName;
    /** TransmitCoilName, 0x00181251, SH, 1 */
    extern DICOM_EXPORT const tag TransmitCoilName;
    /** TransmitCoilType, 0x00189051, CS, 1 */
    extern DICOM_EXPORT const tag TransmitCoilType;
    /** TransmitterFrequency, 0x00189098, FD, 1 */
    extern DICOM_EXPORT const tag TransmitterFrequency;
    /** TransmitTransducerSequence, 0x00144010, SQ, 1, RET */
    extern DICOM_EXPORT const tag TransmitTransducerSequence;
    /** TransmitTransducerSettingsSequence, 0x00144050, SQ, 1, RET */
    extern DICOM_EXPORT const tag TransmitTransducerSettingsSequence;
    /** TransportClassification, 0x40101067, CS, 1, RET */
    extern DICOM_EXPORT const tag TransportClassification;
    /** TransverseDetectorSeparation, 0x00189726, FD, 1 */
    extern DICOM_EXPORT const tag TransverseDetectorSeparation;
    /** TransverseMash, 0x00541202, IS, 1 */
    extern DICOM_EXPORT const tag TransverseMash;
    /** TrayAccessoryCode, 0x300A0355, LO, 1 */
    extern DICOM_EXPORT const tag TrayAccessoryCode;
    /** TreatmentControlPointDate, 0x30080024, DA, 1 */
    extern DICOM_EXPORT const tag TreatmentControlPointDate;
    /** TreatmentControlPointTime, 0x30080025, TM, 1 */
    extern DICOM_EXPORT const tag TreatmentControlPointTime;
    /** TreatmentDate, 0x30080250, DA, 1 */
    extern DICOM_EXPORT const tag TreatmentDate;
    /** TreatmentDeliveryType, 0x300A00CE, CS, 1 */
    extern DICOM_EXPORT const tag TreatmentDeliveryType;
    /** TreatmentMachineName, 0x300A00B2, SH, 1 */
    extern DICOM_EXPORT const tag TreatmentMachineName;
    /** TreatmentMachineSequence, 0x300A0206, SQ, 1 */
    extern DICOM_EXPORT const tag TreatmentMachineSequence;
    /** TreatmentProtocols, 0x300A0009, LO, 1 */
    extern DICOM_EXPORT const tag TreatmentProtocols;
    /** TreatmentSessionApplicationSetupSequence, 0x30080110, SQ, 1 */
    extern DICOM_EXPORT const tag TreatmentSessionApplicationSetupSequence;
    /** TreatmentSessionBeamSequence, 0x30080020, SQ, 1 */
    extern DICOM_EXPORT const tag TreatmentSessionBeamSequence;
    /** TreatmentSessionIonBeamSequence, 0x30080021, SQ, 1 */
    extern DICOM_EXPORT const tag TreatmentSessionIonBeamSequence;
    /** TreatmentSites, 0x300A000B, LO, 1 */
    extern DICOM_EXPORT const tag TreatmentSites;
    /** TreatmentStatusComment, 0x30080202, ST, 1 */
    extern DICOM_EXPORT const tag TreatmentStatusComment;
    /** TreatmentSummaryCalculatedDoseReferenceSequence, 0x30080050, SQ, 1 */
    extern DICOM_EXPORT const tag TreatmentSummaryCalculatedDoseReferenceSequence;
    /** TreatmentSummaryMeasuredDoseReferenceSequence, 0x300800E0, SQ, 1 */
    extern DICOM_EXPORT const tag TreatmentSummaryMeasuredDoseReferenceSequence;
    /** TreatmentTerminationCode, 0x3008002B, SH, 1 */
    extern DICOM_EXPORT const tag TreatmentTerminationCode;
    /** TreatmentTerminationStatus, 0x3008002A, CS, 1 */
    extern DICOM_EXPORT const tag TreatmentTerminationStatus;
    /** TreatmentTime, 0x30080251, TM, 1 */
    extern DICOM_EXPORT const tag TreatmentTime;
    /** TreatmentVerificationStatus, 0x3008002C, CS, 1 */
    extern DICOM_EXPORT const tag TreatmentVerificationStatus;
    /** TriangleFanSequence, 0x00660027, SQ, 1 */
    extern DICOM_EXPORT const tag TriangleFanSequence;
    /** TrianglePointIndexList, 0x00660023, OW, 1, RET */
    extern DICOM_EXPORT const tag TrianglePointIndexList;
    /** TriangleStripSequence, 0x00660026, SQ, 1 */
    extern DICOM_EXPORT const tag TriangleStripSequence;
    /** TriggerSamplePosition, 0x0018106E, UL, 1 */
    extern DICOM_EXPORT const tag TriggerSamplePosition;
    /** TriggerSourceOrType, 0x00181061, LO, 1 */
    extern DICOM_EXPORT const tag TriggerSourceOrType;
    /** TriggerTime, 0x00181060, DS, 1 */
    extern DICOM_EXPORT const tag TriggerTime;
    /** TriggerTimeOffset, 0x00181069, DS, 1 */
    extern DICOM_EXPORT const tag TriggerTimeOffset;
    /** TriggerVector, 0x00540210, IS, 1 */
    extern DICOM_EXPORT const tag TriggerVector;
    /** TriggerWindow, 0x00181094, IS, 1 */
    extern DICOM_EXPORT const tag TriggerWindow;
    /** Trim, 0x20100140, CS, 1 */
    extern DICOM_EXPORT const tag Trim;
    /** TubeAngle, 0x00189303, FD, 1 */
    extern DICOM_EXPORT const tag TubeAngle;
    /** TwoDDegreeOfFreedomAxis, 0x006864F0, FD, 3 */
    extern DICOM_EXPORT const tag TwoDDegreeOfFreedomAxis;
    /** TwoDDegreeOfFreedomSequence, 0x00686470, SQ, 1 */
    extern DICOM_EXPORT const tag TwoDDegreeOfFreedomSequence;
    /** TwoDimensionalToThreeDimensionalMapData, 0x00221531, OF, 1 */
    extern DICOM_EXPORT const tag TwoDimensionalToThreeDimensionalMapData;
    /** TwoDimensionalToThreeDimensionalMapSequence, 0x00221518, SQ, 1 */
    extern DICOM_EXPORT const tag TwoDimensionalToThreeDimensionalMapSequence;
    /** TwoDImplantTemplateGroupMemberMatchingAxes, 0x007800A0, FD, 4 */
    extern DICOM_EXPORT const tag TwoDImplantTemplateGroupMemberMatchingAxes;
    /** TwoDImplantTemplateGroupMemberMatchingPoint, 0x00780090, FD, 2 */
    extern DICOM_EXPORT const tag TwoDImplantTemplateGroupMemberMatchingPoint;
    /** TwoDLineCoordinates, 0x006865B0, FD, 4 */
    extern DICOM_EXPORT const tag TwoDLineCoordinates;
    /** TwoDLineCoordinatesSequence, 0x006865A0, SQ, 1 */
    extern DICOM_EXPORT const tag TwoDLineCoordinatesSequence;
    /** TwoDMatingAxes, 0x00686460, FD, 4 */
    extern DICOM_EXPORT const tag TwoDMatingAxes;
    /** TwoDMatingFeatureCoordinatesSequence, 0x00686430, SQ, 1 */
    extern DICOM_EXPORT const tag TwoDMatingFeatureCoordinatesSequence;
    /** TwoDMatingPoint, 0x00686450, FD, 2 */
    extern DICOM_EXPORT const tag TwoDMatingPoint;
    /** TwoDPlaneCoordinatesSequence, 0x006865E0, SQ, 1 */
    extern DICOM_EXPORT const tag TwoDPlaneCoordinatesSequence;
    /** TwoDPlaneIntersection, 0x006865F0, FD, 4 */
    extern DICOM_EXPORT const tag TwoDPlaneIntersection;
    /** TwoDPointCoordinates, 0x00686560, FD, 2 */
    extern DICOM_EXPORT const tag TwoDPointCoordinates;
    /** TwoDPointCoordinatesSequence, 0x00686550, SQ, 1 */
    extern DICOM_EXPORT const tag TwoDPointCoordinatesSequence;
    /** TypeOfData, 0x50000020, CS, 1, RET */
    extern DICOM_EXPORT const range_tag TypeOfData;
    /** TypeOfDetectorMotion, 0x00540202, CS, 1 */
    extern DICOM_EXPORT const tag TypeOfDetectorMotion;
    /** TypeOfFilters, 0x00181161, LO, 1 */
    extern DICOM_EXPORT const tag TypeOfFilters;
    /** TypeOfInstances, 0x0040E020, CS, 1 */
    extern DICOM_EXPORT const tag TypeOfInstances;
    /** TypeOfPatientID, 0x00100022, CS, 1 */
    extern DICOM_EXPORT const tag TypeOfPatientID;
    /** TypeOfSynchronization, 0x00720434, CS, 1 */
    extern DICOM_EXPORT const tag TypeOfSynchronization;
    /** UDISequence, 0x0018100A, SQ, 1 */
    extern DICOM_EXPORT const tag UDISequence;
    /** UID, 0x0040A124, UI, 1 */
    extern DICOM_EXPORT const tag UID;
    /** UltrasoundAcquisitionGeometry, 0x00209307, CS, 1 */
    extern DICOM_EXPORT const tag UltrasoundAcquisitionGeometry;
    /** UltrasoundColorDataPresent, 0x00280014, US, 1 */
    extern DICOM_EXPORT const tag UltrasoundColorDataPresent;
    /** UltrasoundOphthalmicAxialLengthMeasurementsSequence, 0x00221220, SQ, 1 */
    extern DICOM_EXPORT const tag UltrasoundOphthalmicAxialLengthMeasurementsSequence;
    /** UltrasoundSelectedOphthalmicAxialLengthSequence, 0x00221230, SQ, 1 */
    extern DICOM_EXPORT const tag UltrasoundSelectedOphthalmicAxialLengthSequence;
    /** UnassignedPerFrameConvertedAttributesSequence, 0x00209171, SQ, 1 */
    extern DICOM_EXPORT const tag UnassignedPerFrameConvertedAttributesSequence;
    /** UnassignedSharedConvertedAttributesSequence, 0x00209170, SQ, 1 */
    extern DICOM_EXPORT const tag UnassignedSharedConvertedAttributesSequence;
    /** Underlined, 0x00700248, CS, 1 */
    extern DICOM_EXPORT const tag Underlined;
    /** UnformattedTextValue, 0x00700006, ST, 1 */
    extern DICOM_EXPORT const tag UnformattedTextValue;
    /** UnifiedProcedureStepListStatus, 0x00741246, CS, 1 */
    extern DICOM_EXPORT const tag UnifiedProcedureStepListStatus;
    /** UnifiedProcedureStepPerformedProcedureSequence, 0x00741216, SQ, 1 */
    extern DICOM_EXPORT const tag UnifiedProcedureStepPerformedProcedureSequence;
    /** UniformResourceLocatorTrial, 0x0040A992, ST, 1, RET */
    extern DICOM_EXPORT const tag UniformResourceLocatorTrial;
    /** UniqueDeviceIdentifier, 0x00181009, UT, 1 */
    extern DICOM_EXPORT const tag UniqueDeviceIdentifier;
    /** Units, 0x00541001, CS, 1 */
    extern DICOM_EXPORT const tag Units;
    /** UniversalEntityID, 0x00400032, UT, 1 */
    extern DICOM_EXPORT const tag UniversalEntityID;
    /** UniversalEntityIDType, 0x00400033, CS, 1 */
    extern DICOM_EXPORT const tag UniversalEntityIDType;
    /** UnspecifiedLateralityLensSequence, 0x00460016, SQ, 1 */
    extern DICOM_EXPORT const tag UnspecifiedLateralityLensSequence;
    /** UpperLowerPixelValues, 0x00181240, IS, 1, RET */
    extern DICOM_EXPORT const tag UpperLowerPixelValues;
    /** UrgencyOrPriorityAlertsTrial, 0x0040A057, CS, 1, RET */
    extern DICOM_EXPORT const tag UrgencyOrPriorityAlertsTrial;
    /** URNCodeValue, 0x00080120, UR, 1 */
    extern DICOM_EXPORT const tag URNCodeValue;
    /** UsedFiducialsSequence, 0x00700314, SQ, 1 */
    extern DICOM_EXPORT const tag UsedFiducialsSequence;
    /** UsedSegmentsSequence, 0x00620012, SQ, 1 */
    extern DICOM_EXPORT const tag UsedSegmentsSequence;
    /** UserSelectedGainY, 0x0014408B, DS, 1, RET */
    extern DICOM_EXPORT const tag UserSelectedGainY;
    /** UserSelectedOffsetX, 0x0014408D, DS, 1, RET */
    extern DICOM_EXPORT const tag UserSelectedOffsetX;
    /** UserSelectedOffsetY, 0x0014408E, DS, 1, RET */
    extern DICOM_EXPORT const tag UserSelectedOffsetY;
    /** UserSelectedPhase, 0x0014408C, DS, 1, RET */
    extern DICOM_EXPORT const tag UserSelectedPhase;
    /** USImageDescriptionSequence, 0x00189806, SQ, 1 */
    extern DICOM_EXPORT const tag USImageDescriptionSequence;
    /** UValueData, 0x00800010, OF, 1 */
    extern DICOM_EXPORT const tag UValueData;
    /** UVMappingSequence, 0x00800008, SQ, 1 */
    extern DICOM_EXPORT const tag UVMappingSequence;
    /** ValueType, 0x0040A040, CS, 1 */
    extern DICOM_EXPORT const tag ValueType;
    /** VariableCoefficientsSDDN, 0x7F000040, OW, 1, RET */
    extern DICOM_EXPORT const range_tag VariableCoefficientsSDDN;
    /** VariableCoefficientsSDHN, 0x7F000030, OW, 1, RET */
    extern DICOM_EXPORT const range_tag VariableCoefficientsSDHN;
    /** VariableCoefficientsSDVN, 0x7F000020, OW, 1, RET */
    extern DICOM_EXPORT const range_tag VariableCoefficientsSDVN;
    /** VariableFlipAngleFlag, 0x00181315, CS, 1 */
    extern DICOM_EXPORT const tag VariableFlipAngleFlag;
    /** VariableNextDataGroup, 0x7F000011, US, 1, RET */
    extern DICOM_EXPORT const range_tag VariableNextDataGroup;
    /** VariablePixelData, 0x7F000010, OB or OW, 1, RET */
    extern DICOM_EXPORT const range_tag VariablePixelData;
    /** VectorAccuracy, 0x00660020, FL, 1 */
    extern DICOM_EXPORT const tag VectorAccuracy;
    /** VectorCoordinateData, 0x00660021, OF, 1 */
    extern DICOM_EXPORT const tag VectorCoordinateData;
    /** VectorDimensionality, 0x0066001F, US, 1 */
    extern DICOM_EXPORT const tag VectorDimensionality;
    /** VectorGridData, 0x00640009, OF, 1 */
    extern DICOM_EXPORT const tag VectorGridData;
    /** VelocityEncodingAcquisitionSequence, 0x00189092, SQ, 1 */
    extern DICOM_EXPORT const tag VelocityEncodingAcquisitionSequence;
    /** VelocityEncodingDirection, 0x00189090, FD, 3 */
    extern DICOM_EXPORT const tag VelocityEncodingDirection;
    /** VelocityEncodingMaximumValue, 0x00189217, FD, 1 */
    extern DICOM_EXPORT const tag VelocityEncodingMaximumValue;
    /** VelocityEncodingMinimumValue, 0x00189091, FD, 1 */
    extern DICOM_EXPORT const tag VelocityEncodingMinimumValue;
    /** VelocityOfSound, 0x00144064, DS, 1, RET */
    extern DICOM_EXPORT const tag VelocityOfSound;
    /** VerbalSourceIdentifierCodeSequenceTrial, 0x0040A358, SQ, 1, RET */
    extern DICOM_EXPORT const tag VerbalSourceIdentifierCodeSequenceTrial;
    /** VerbalSourceTrial, 0x0040A352, PN, 1, RET */
    extern DICOM_EXPORT const tag VerbalSourceTrial;
    /** VerificationDateTime, 0x0040A030, DT, 1 */
    extern DICOM_EXPORT const tag VerificationDateTime;
    /** VerificationFlag, 0x0040A493, CS, 1 */
    extern DICOM_EXPORT const tag VerificationFlag;
    /** VerificationImageTiming, 0x00741032, CS, 1 */
    extern DICOM_EXPORT const tag VerificationImageTiming;
    /** VerifyingObserverIdentificationCodeSequence, 0x0040A088, SQ, 1 */
    extern DICOM_EXPORT const tag VerifyingObserverIdentificationCodeSequence;
    /** VerifyingObserverName, 0x0040A075, PN, 1 */
    extern DICOM_EXPORT const tag VerifyingObserverName;
    /** VerifyingObserverSequence, 0x0040A073, SQ, 1 */
    extern DICOM_EXPORT const tag VerifyingObserverSequence;
    /** VerifyingOrganization, 0x0040A027, LO, 1 */
    extern DICOM_EXPORT const tag VerifyingOrganization;
    /** VertexPointIndexList, 0x00660025, OW, 1, RET */
    extern DICOM_EXPORT const tag VertexPointIndexList;
    /** VerticalAlignment, 0x00700243, CS, 1 */
    extern DICOM_EXPORT const tag VerticalAlignment;
    /** VerticalOffsetOfSensor, 0x00143026, DS, 1, RET */
    extern DICOM_EXPORT const tag VerticalOffsetOfSensor;
    /** VerticalPrismBase, 0x00460036, CS, 1 */
    extern DICOM_EXPORT const tag VerticalPrismBase;
    /** VerticalPrismPower, 0x00460034, FD, 1 */
    extern DICOM_EXPORT const tag VerticalPrismPower;
    /** VerticesOfTheOutlineOfPupil, 0x00460208, IS, 2 */
    extern DICOM_EXPORT const tag VerticesOfTheOutlineOfPupil;
    /** VerticesOfThePolygonalCollimator, 0x00181720, IS, 2 */
    extern DICOM_EXPORT const tag VerticesOfThePolygonalCollimator;
    /** VerticesOfThePolygonalExposureControlSensingRegion, 0x00189442, SS, 2 */
    extern DICOM_EXPORT const tag VerticesOfThePolygonalExposureControlSensingRegion;
    /** VerticesOfThePolygonalShutter, 0x00181620, IS, 2 */
    extern DICOM_EXPORT const tag VerticesOfThePolygonalShutter;
    /** VerticesOfTheRegion, 0x00289503, SS, 2 */
    extern DICOM_EXPORT const tag VerticesOfTheRegion;
    /** VideoImageFormatAcquired, 0x00181022, SH, 1 */
    extern DICOM_EXPORT const tag VideoImageFormatAcquired;
    /** ViewCodeSequence, 0x00540220, SQ, 1 */
    extern DICOM_EXPORT const tag ViewCodeSequence;
    /** ViewingDistance, 0x00460106, FD, 1 */
    extern DICOM_EXPORT const tag ViewingDistance;
    /** ViewingDistanceType, 0x00460125, CS, 1 */
    extern DICOM_EXPORT const tag ViewingDistanceType;
    /** ViewModifierCodeSequence, 0x00540222, SQ, 1 */
    extern DICOM_EXPORT const tag ViewModifierCodeSequence;
    /** ViewName, 0x00082127, SH, 1 */
    extern DICOM_EXPORT const tag ViewName;
    /** ViewNumber, 0x00082128, IS, 1 */
    extern DICOM_EXPORT const tag ViewNumber;
    /** ViewOrientationCodeSequence, 0x006862E0, SQ, 1 */
    extern DICOM_EXPORT const tag ViewOrientationCodeSequence;
    /** ViewOrientationModifierCodeSequence, 0x006862F0, SQ, 1 */
    extern DICOM_EXPORT const tag ViewOrientationModifierCodeSequence;
    /** ViewpointLookAtPoint, 0x00701604, FD, 3 */
    extern DICOM_EXPORT const tag ViewpointLookAtPoint;
    /** ViewpointPosition, 0x00701603, FD, 3 */
    extern DICOM_EXPORT const tag ViewpointPosition;
    /** ViewpointUpDirection, 0x00701605, FD, 3 */
    extern DICOM_EXPORT const tag ViewpointUpDirection;
    /** ViewPosition, 0x00185101, CS, 1 */
    extern DICOM_EXPORT const tag ViewPosition;
    /** VirtualSourceAxisDistances, 0x300A030A, FL, 2 */
    extern DICOM_EXPORT const tag VirtualSourceAxisDistances;
    /** VisitComments, 0x00384000, LT, 1 */
    extern DICOM_EXPORT const tag VisitComments;
    /** VisitStatusID, 0x00380008, CS, 1 */
    extern DICOM_EXPORT const tag VisitStatusID;
    /** VisualAcuityBothEyesOpenSequence, 0x00460124, SQ, 1 */
    extern DICOM_EXPORT const tag VisualAcuityBothEyesOpenSequence;
    /** VisualAcuityLeftEyeSequence, 0x00460123, SQ, 1 */
    extern DICOM_EXPORT const tag VisualAcuityLeftEyeSequence;
    /** VisualAcuityMeasurementSequence, 0x00240110, SQ, 1 */
    extern DICOM_EXPORT const tag VisualAcuityMeasurementSequence;
    /** VisualAcuityModifiers, 0x00460135, SS, 2 */
    extern DICOM_EXPORT const tag VisualAcuityModifiers;
    /** VisualAcuityRightEyeSequence, 0x00460122, SQ, 1 */
    extern DICOM_EXPORT const tag VisualAcuityRightEyeSequence;
    /** VisualAcuityTypeCodeSequence, 0x00460121, SQ, 1 */
    extern DICOM_EXPORT const tag VisualAcuityTypeCodeSequence;
    /** VisualEvaluationMethodCodeSequence, 0x0028702E, SQ, 1 */
    extern DICOM_EXPORT const tag VisualEvaluationMethodCodeSequence;
    /** VisualEvaluationResultSequence, 0x00287015, SQ, 1 */
    extern DICOM_EXPORT const tag VisualEvaluationResultSequence;
    /** VisualEvaluationTestSequence, 0x00287028, SQ, 1 */
    extern DICOM_EXPORT const tag VisualEvaluationTestSequence;
    /** VisualFieldCatchTrialSequence, 0x00240034, SQ, 1 */
    extern DICOM_EXPORT const tag VisualFieldCatchTrialSequence;
    /** VisualFieldGlobalResultsIndexSequence, 0x00240320, SQ, 1 */
    extern DICOM_EXPORT const tag VisualFieldGlobalResultsIndexSequence;
    /** VisualFieldHorizontalExtent, 0x00240010, FL, 1 */
    extern DICOM_EXPORT const tag VisualFieldHorizontalExtent;
    /** VisualFieldMeanSensitivity, 0x00240070, FL, 1 */
    extern DICOM_EXPORT const tag VisualFieldMeanSensitivity;
    /** VisualFieldShape, 0x00240012, CS, 1 */
    extern DICOM_EXPORT const tag VisualFieldShape;
    /** VisualFieldTestDuration, 0x00240088, FL, 1 */
    extern DICOM_EXPORT const tag VisualFieldTestDuration;
    /** VisualFieldTestNormalsFlag, 0x00240063, CS, 1 */
    extern DICOM_EXPORT const tag VisualFieldTestNormalsFlag;
    /** VisualFieldTestPointNormalsSequence, 0x00240097, SQ, 1 */
    extern DICOM_EXPORT const tag VisualFieldTestPointNormalsSequence;
    /** VisualFieldTestPointSequence, 0x00240089, SQ, 1 */
    extern DICOM_EXPORT const tag VisualFieldTestPointSequence;
    /** VisualFieldTestPointXCoordinate, 0x00240090, FL, 1 */
    extern DICOM_EXPORT const tag VisualFieldTestPointXCoordinate;
    /** VisualFieldTestPointYCoordinate, 0x00240091, FL, 1 */
    extern DICOM_EXPORT const tag VisualFieldTestPointYCoordinate;
    /** VisualFieldTestReliabilityGlobalIndexSequence, 0x00240317, SQ, 1 */
    extern DICOM_EXPORT const tag VisualFieldTestReliabilityGlobalIndexSequence;
    /** VisualFieldVerticalExtent, 0x00240011, FL, 1 */
    extern DICOM_EXPORT const tag VisualFieldVerticalExtent;
    /** VitalStainCodeSequenceTrial, 0x004009F8, SQ, 1, RET */
    extern DICOM_EXPORT const tag VitalStainCodeSequenceTrial;
    /** VitreousStatusCodeSequence, 0x00221025, SQ, 1 */
    extern DICOM_EXPORT const tag VitreousStatusCodeSequence;
    /** VitreousStatusDescription, 0x00221066, LO, 1 */
    extern DICOM_EXPORT const tag VitreousStatusDescription;
    /** VOILUTFunction, 0x00281056, CS, 1 */
    extern DICOM_EXPORT const tag VOILUTFunction;
    /** VOILUTSequence, 0x00283010, SQ, 1 */
    extern DICOM_EXPORT const tag VOILUTSequence;
    /** VOIType, 0x00720702, CS, 1 */
    extern DICOM_EXPORT const tag VOIType;
    /** VolumeBasedCalculationTechnique, 0x00089207, CS, 1 */
    extern DICOM_EXPORT const tag VolumeBasedCalculationTechnique;
    /** VolumeCroppingMethod, 0x00701302, CS, 1 */
    extern DICOM_EXPORT const tag VolumeCroppingMethod;
    /** VolumeCroppingSequence, 0x00701301, SQ, 1 */
    extern DICOM_EXPORT const tag VolumeCroppingSequence;
    /** VolumeFrameOfReferenceUID, 0x00209312, UI, 1 */
    extern DICOM_EXPORT const tag VolumeFrameOfReferenceUID;
    /** VolumeLocalizationSequence, 0x00189126, SQ, 1 */
    extern DICOM_EXPORT const tag VolumeLocalizationSequence;
    /** VolumeLocalizationTechnique, 0x00189054, CS, 1 */
    extern DICOM_EXPORT const tag VolumeLocalizationTechnique;
    /** VolumeOfPTO, 0x40101023, FL, 1, RET */
    extern DICOM_EXPORT const tag VolumeOfPTO;
    /** VolumeStreamSequence, 0x00701A08, SQ, 1 */
    extern DICOM_EXPORT const tag VolumeStreamSequence;
    /** VolumeToTableMappingMatrix, 0x0020930A, FD, 16 */
    extern DICOM_EXPORT const tag VolumeToTableMappingMatrix;
    /** VolumeToTransducerMappingMatrix, 0x00209309, FD, 16 */
    extern DICOM_EXPORT const tag VolumeToTransducerMappingMatrix;
    /** VolumeToTransducerRelationship, 0x0020930B, CS, 1 */
    extern DICOM_EXPORT const tag VolumeToTransducerRelationship;
    /** VolumetricAnnotationSequence, 0x00701901, SQ, 1 */
    extern DICOM_EXPORT const tag VolumetricAnnotationSequence;
    /** VolumetricCurvePoints, 0x0070150D, OD, 1 */
    extern DICOM_EXPORT const tag VolumetricCurvePoints;
    /** VolumetricCurveUpDirections, 0x00701A07, OD, 1 */
    extern DICOM_EXPORT const tag VolumetricCurveUpDirections;
    /** VolumetricPresentationInputAnnotationSequence, 0x00701905, SQ, 1 */
    extern DICOM_EXPORT const tag VolumetricPresentationInputAnnotationSequence;
    /** VolumetricPresentationInputIndex, 0x00701804, US, 1 */
    extern DICOM_EXPORT const tag VolumetricPresentationInputIndex;
    /** VolumetricPresentationInputNumber, 0x00701207, US, 1 */
    extern DICOM_EXPORT const tag VolumetricPresentationInputNumber;
    /** VolumetricPresentationInputSetSequence, 0x0070120A, SQ, 1 */
    extern DICOM_EXPORT const tag VolumetricPresentationInputSetSequence;
    /** VolumetricPresentationInputSetUID, 0x00701209, UI, 1 */
    extern DICOM_EXPORT const tag VolumetricPresentationInputSetUID;
    /** VolumetricPresentationStateInputSequence, 0x00701201, SQ, 1 */
    extern DICOM_EXPORT const tag VolumetricPresentationStateInputSequence;
    /** VolumetricProperties, 0x00089206, CS, 1 */
    extern DICOM_EXPORT const tag VolumetricProperties;
    /** VValueData, 0x00800011, OF, 1 */
    extern DICOM_EXPORT const tag VValueData;
    /** WADORetrievalSequence, 0x0040E023, SQ, 1 */
    extern DICOM_EXPORT const tag WADORetrievalSequence;
    /** WADORSRetrievalSequence, 0x0040E025, SQ, 1 */
    extern DICOM_EXPORT const tag WADORSRetrievalSequence;
    /** WarningReason, 0x00081196, US, 1 */
    extern DICOM_EXPORT const tag WarningReason;
    /** WaterEquivalentDiameter, 0x00181271, FD, 1 */
    extern DICOM_EXPORT const tag WaterEquivalentDiameter;
    /** WaterEquivalentDiameterCalculationMethodCodeSequence, 0x00181272, SQ, 1 */
    extern DICOM_EXPORT const tag WaterEquivalentDiameterCalculationMethodCodeSequence;
    /** WaterReferenceAcquisition, 0x00189297, CS, 1 */
    extern DICOM_EXPORT const tag WaterReferenceAcquisition;
    /** WaterReferencedPhaseCorrection, 0x00189199, CS, 1 */
    extern DICOM_EXPORT const tag WaterReferencedPhaseCorrection;
    /** WaveformAnnotationSequence, 0x0040B020, SQ, 1 */
    extern DICOM_EXPORT const tag WaveformAnnotationSequence;
    /** WaveformBitsAllocated, 0x54001004, US, 1 */
    extern DICOM_EXPORT const tag WaveformBitsAllocated;
    /** WaveformBitsStored, 0x003A021A, US, 1 */
    extern DICOM_EXPORT const tag WaveformBitsStored;
    /** WaveformChannelNumber, 0x003A0202, IS, 1 */
    extern DICOM_EXPORT const tag WaveformChannelNumber;
    /** WaveformData, 0x54001010, OB or OW, 1 */
    extern DICOM_EXPORT const tag WaveformData;
    /** WaveformDataDisplayScale, 0x003A0230, FL, 1 */
    extern DICOM_EXPORT const tag WaveformDataDisplayScale;
    /** WaveformDisplayBackgroundCIELabValue, 0x003A0231, US, 3 */
    extern DICOM_EXPORT const tag WaveformDisplayBackgroundCIELabValue;
    /** WaveformOriginality, 0x003A0004, CS, 1 */
    extern DICOM_EXPORT const tag WaveformOriginality;
    /** WaveformPaddingValue, 0x5400100A, OB or OW, 1 */
    extern DICOM_EXPORT const tag WaveformPaddingValue;
    /** WaveformPresentationGroupSequence, 0x003A0240, SQ, 1 */
    extern DICOM_EXPORT const tag WaveformPresentationGroupSequence;
    /** WaveformSampleInterpretation, 0x54001006, CS, 1 */
    extern DICOM_EXPORT const tag WaveformSampleInterpretation;
    /** WaveformSequence, 0x54000100, SQ, 1 */
    extern DICOM_EXPORT const tag WaveformSequence;
    /** WedgeAngle, 0x300A00D5, IS, 1 */
    extern DICOM_EXPORT const tag WedgeAngle;
    /** WedgeAngleFloat, 0x00145107, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeAngleFloat;
    /** WedgeChamferHeight, 0x0014511D, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeChamferHeight;
    /** WedgeCurve, 0x0014511E, CS, 1, RET */
    extern DICOM_EXPORT const tag WedgeCurve;
    /** WedgeDescription, 0x00145111, LO, 1, RET */
    extern DICOM_EXPORT const tag WedgeDescription;
    /** WedgeElement1Position, 0x00145109, CS, 1, RET */
    extern DICOM_EXPORT const tag WedgeElement1Position;
    /** WedgeFactor, 0x300A00D6, DS, 1 */
    extern DICOM_EXPORT const tag WedgeFactor;
    /** WedgeFrontGap, 0x00145117, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeFrontGap;
    /** WedgeFrontHeight, 0x00145119, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeFrontHeight;
    /** WedgeID, 0x300A00D4, SH, 1 */
    extern DICOM_EXPORT const tag WedgeID;
    /** WedgeInContactLength, 0x00145116, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeInContactLength;
    /** WedgeInContactWidth, 0x0014511C, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeInContactWidth;
    /** WedgeManufacturerName, 0x00145110, SH, 1, RET */
    extern DICOM_EXPORT const tag WedgeManufacturerName;
    /** WedgeMaterial, 0x0014510B, SH, 1, RET */
    extern DICOM_EXPORT const tag WedgeMaterial;
    /** WedgeMaterialVelocity, 0x0014510A, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeMaterialVelocity;
    /** WedgeModelNumber, 0x00145106, SH, 1, RET */
    extern DICOM_EXPORT const tag WedgeModelNumber;
    /** WedgeName, 0x0014510F, SH, 1, RET */
    extern DICOM_EXPORT const tag WedgeName;
    /** WedgeNumber, 0x300A00D2, IS, 1 */
    extern DICOM_EXPORT const tag WedgeNumber;
    /** WedgeOffsetX, 0x00145113, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeOffsetX;
    /** WedgeOffsetY, 0x00145114, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeOffsetY;
    /** WedgeOffsetZ, 0x0014510C, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeOffsetZ;
    /** WedgeOrientation, 0x300A00D8, DS, 1 */
    extern DICOM_EXPORT const tag WedgeOrientation;
    /** WedgeOriginOffsetX, 0x0014510D, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeOriginOffsetX;
    /** WedgePosition, 0x300A0118, CS, 1 */
    extern DICOM_EXPORT const tag WedgePosition;
    /** WedgePositionSequence, 0x300A0116, SQ, 1 */
    extern DICOM_EXPORT const tag WedgePositionSequence;
    /** WedgeRearHeight, 0x0014511A, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeRearHeight;
    /** WedgeRoofAngle, 0x00145108, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeRoofAngle;
    /** WedgeSequence, 0x300A00D1, SQ, 1 */
    extern DICOM_EXPORT const tag WedgeSequence;
    /** WedgeThinEdgePosition, 0x300A00DB, FL, 1 */
    extern DICOM_EXPORT const tag WedgeThinEdgePosition;
    /** WedgeTimeDelay, 0x0014510E, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeTimeDelay;
    /** WedgeTotalHeight, 0x00145118, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeTotalHeight;
    /** WedgeTotalLength, 0x00145115, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeTotalLength;
    /** WedgeTotalWidth, 0x0014511B, DS, 1, RET */
    extern DICOM_EXPORT const tag WedgeTotalWidth;
    /** WedgeType, 0x300A00D3, CS, 1 */
    extern DICOM_EXPORT const tag WedgeType;
    /** WeightingLookupTableData, 0x00701808, OB, 1 */
    extern DICOM_EXPORT const tag WeightingLookupTableData;
    /** WeightingLookupTableDescriptor, 0x00701807, US, 3 */
    extern DICOM_EXPORT const tag WeightingLookupTableDescriptor;
    /** WeightingTransferFunctionSequence, 0x00701806, SQ, 1 */
    extern DICOM_EXPORT const tag WeightingTransferFunctionSequence;
    /** WhitePointFlag, 0x00287021, CS, 1 */
    extern DICOM_EXPORT const tag WhitePointFlag;
    /** WholeBodyTechnique, 0x00181301, CS, 1 */
    extern DICOM_EXPORT const tag WholeBodyTechnique;
    /** WholeSlideMicroscopyImageFrameTypeSequence, 0x00400710, SQ, 1 */
    extern DICOM_EXPORT const tag WholeSlideMicroscopyImageFrameTypeSequence;
    /** WideFieldOphthalmicPhotographyQualityRatingSequence, 0x00221525, SQ, 1 */
    extern DICOM_EXPORT const tag WideFieldOphthalmicPhotographyQualityRatingSequence;
    /** WideFieldOphthalmicPhotographyQualityThresholdSequence, 0x00221526, SQ, 1 */
    extern DICOM_EXPORT const tag WideFieldOphthalmicPhotographyQualityThresholdSequence;
    /** WideFieldOphthalmicPhotographyThresholdQualityRating, 0x00221527, FL, 1 */
    extern DICOM_EXPORT const tag WideFieldOphthalmicPhotographyThresholdQualityRating;
    /** WindowCenter, 0x00281050, DS, 1 */
    extern DICOM_EXPORT const tag WindowCenter;
    /** WindowCenterWidthExplanation, 0x00281055, LO, 1 */
    extern DICOM_EXPORT const tag WindowCenterWidthExplanation;
    /** WindowWidth, 0x00281051, DS, 1 */
    extern DICOM_EXPORT const tag WindowWidth;
    /** WorklistLabel, 0x00741202, LO, 1 */
    extern DICOM_EXPORT const tag WorklistLabel;
    /** XAXRFFrameCharacteristicsSequence, 0x00189412, SQ, 1 */
    extern DICOM_EXPORT const tag XAXRFFrameCharacteristicsSequence;
    /** XCoordinatesCenterPixelViewAngle, 0x00221528, FL, 1 */
    extern DICOM_EXPORT const tag XCoordinatesCenterPixelViewAngle;
    /** XDSRetrievalSequence, 0x0040E024, SQ, 1 */
    extern DICOM_EXPORT const tag XDSRetrievalSequence;
    /** XDSStorageSequence, 0x00404074, SQ, 1 */
    extern DICOM_EXPORT const tag XDSStorageSequence;
    /** XFocusCenter, 0x00181183, DS, 1 */
    extern DICOM_EXPORT const tag XFocusCenter;
    /** XOffsetInSlideCoordinateSystem, 0x0040072A, DS, 1 */
    extern DICOM_EXPORT const tag XOffsetInSlideCoordinateSystem;
    /** XRay3DAcquisitionSequence, 0x00189507, SQ, 1 */
    extern DICOM_EXPORT const tag XRay3DAcquisitionSequence;
    /** XRay3DFrameTypeSequence, 0x00189504, SQ, 1 */
    extern DICOM_EXPORT const tag XRay3DFrameTypeSequence;
    /** XRay3DReconstructionSequence, 0x00189530, SQ, 1 */
    extern DICOM_EXPORT const tag XRay3DReconstructionSequence;
    /** XRayAcquisitionDoseSequence, 0x00189542, SQ, 1 */
    extern DICOM_EXPORT const tag XRayAcquisitionDoseSequence;
    /** XRayFilterSequence, 0x00189556, SQ, 1 */
    extern DICOM_EXPORT const tag XRayFilterSequence;
    /** XRayGeometrySequence, 0x00189476, SQ, 1 */
    extern DICOM_EXPORT const tag XRayGeometrySequence;
    /** XRayGridSequence, 0x00189555, SQ, 1 */
    extern DICOM_EXPORT const tag XRayGridSequence;
    /** XRayImageReceptorAngle, 0x3002000E, DS, 1 */
    extern DICOM_EXPORT const tag XRayImageReceptorAngle;
    /** XRayImageReceptorTranslation, 0x3002000D, DS, 3 */
    extern DICOM_EXPORT const tag XRayImageReceptorTranslation;
    /** XRayOutput, 0x00400312, DS, 1 */
    extern DICOM_EXPORT const tag XRayOutput;
    /** XRayReceptorType, 0x00189420, CS, 1 */
    extern DICOM_EXPORT const tag XRayReceptorType;
    /** XRaySourceIsocenterPrimaryAngle, 0x00189543, FD, 1 */
    extern DICOM_EXPORT const tag XRaySourceIsocenterPrimaryAngle;
    /** XRaySourceIsocenterSecondaryAngle, 0x00189544, FD, 1 */
    extern DICOM_EXPORT const tag XRaySourceIsocenterSecondaryAngle;
    /** XRayTubeCurrent, 0x00181151, IS, 1 */
    extern DICOM_EXPORT const tag XRayTubeCurrent;
    /** XRayTubeCurrentInmA, 0x00189330, FD, 1 */
    extern DICOM_EXPORT const tag XRayTubeCurrentInmA;
    /** XRayTubeCurrentInuA, 0x00188151, DS, 1 */
    extern DICOM_EXPORT const tag XRayTubeCurrentInuA;
    /** YCoordinatesCenterPixelViewAngle, 0x00221529, FL, 1 */
    extern DICOM_EXPORT const tag YCoordinatesCenterPixelViewAngle;
    /** YFocusCenter, 0x00181184, DS, 1 */
    extern DICOM_EXPORT const tag YFocusCenter;
    /** YOffsetInSlideCoordinateSystem, 0x0040073A, DS, 1 */
    extern DICOM_EXPORT const tag YOffsetInSlideCoordinateSystem;
    /** ZEffective, 0x40101019, FL, 1, RET */
    extern DICOM_EXPORT const tag ZEffective;
    /** ZeroVelocityPixelValue, 0x00189810, US or SS, 1 */
    extern DICOM_EXPORT const tag ZeroVelocityPixelValue;
    /** ZOffsetInSlideCoordinateSystem, 0x0040074A, DS, 1 */
    extern DICOM_EXPORT const tag ZOffsetInSlideCoordinateSystem;
    /** ZonalMap, 0x10100000, US, 1, RET */
    extern DICOM_EXPORT const range_tag ZonalMap;
    /** ZonalMapFormat, 0x00280722, US, 1, RET */
    extern DICOM_EXPORT const tag ZonalMapFormat;
    /** ZonalMapLocation, 0x00280721, AT, 1, RET */
    extern DICOM_EXPORT const tag ZonalMapLocation;
    /** ZonalMapNumberFormat, 0x00280720, US, 1, RET */
    extern DICOM_EXPORT const tag ZonalMapNumberFormat;
    /** ZoomCenter, 0x00280032, DS, 2 */
    extern DICOM_EXPORT const tag ZoomCenter;
    /** ZoomFactor, 0x00280031, DS, 2 */
    extern DICOM_EXPORT const tag ZoomFactor;
}
