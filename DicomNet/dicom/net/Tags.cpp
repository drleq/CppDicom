#include "dicomnet_pch.h"
#include "dicom/net/Tags.cpp"

namespace dicom::net::tags {
    const tag ActionTypeID = { 0x00001008, {1, 1}, VRType::US, false };
    const tag AffectedSOPClassUID = { 0x00000002, {1, 1}, VRType::UI, false };
    const tag AffectedSOPInstanceUID = { 0x00001000, {1, 1}, VRType::UI, false };
    const tag AttributeIdentifierList = { 0x00001005, {1, -1}, VRType::AT, false };
    const tag CommandDataSetType = { 0x00000800, {1, 1}, VRType::US, false };
    const tag CommandField = { 0x00000100, {1, 1}, VRType::US, false };
    const tag CommandGroupLength = { 0x00000000, {1, 1}, VRType::UL, false };
    const tag ErrorComment = { 0x00000902, {1, 1}, VRType::LO, false };
    const tag ErrorID = { 0x00000903, {1, 1}, VRType::US, false };
    const tag EventTypeID = { 0x00001002, {1, 1}, VRType::US, false };
    const tag MessageID = { 0x00000110, {1, 1}, VRType::US, false };
    const tag MessageIDBeingRespondedTo = { 0x00000120, {1, 1}, VRType::US, false };
    const tag MoveDestination = { 0x00000600, {1, 1}, VRType::AE, false };
    const tag MoveOriginatorApplicationEntityTitle = { 0x00001030, {1, 1}, VRType::AE, false };
    const tag MoveOriginatorMessageID = { 0x00001031, {1, 1}, VRType::US, false };
    const tag NumberOfCompletedSuboperations = { 0x00001021, {1, 1}, VRType::US, false };
    const tag NumberOfFailedSuboperations = { 0x00001022, {1, 1}, VRType::US, false };
    const tag NumberOfRemainingSuboperations = { 0x00001020, {1, 1}, VRType::US, false };
    const tag NumberOfWarningSuboperations = { 0x00001023, {1, 1}, VRType::US, false };
    const tag RequestedSOPClassUID = { 0x00000003, {1, 1}, VRType::UI, false };
    const tag RequestedSOPInstanceUID = { 0x00001001, {1, 1}, VRType::UI, false };
    const tag OffendingElement = { 0x00000901, {1, -1}, VRType::AT, false };
    const tag Priority = { 0x00000700, {1, 1}, VRType::US, false };
    const tag Status = { 0x00000900, {1, 1}, VRType::US, false };

    // Deprecated tags
    const tag AddGrayScale = { 0x00005150, {1, 1}, VRType::CS, false };
    const tag Borders = { 0x00005160, {1, 1}, VRType::CS, false };
    const tag CommandLengthToEnd = { 0x00000001, {1, 1}, VRType::UL, false };
    const tag CommandMagnificationType = { 0x00005180, {1, 1}, VRType::CS, false };
    const tag CommandRecognitionCode = { 0x00000010, {1, 1}, VRType::SH, false };
    const tag Copies = { 0x00005170, {1, 1}, VRType::IS, false };
    const tag DialogReceiver = { 0x00004000, {1, 1}, VRType::LT, false };
    const tag DisplayFormat = { 0x00005110, {1, 1}, VRType::LT, false };
    const tag EndMessageID = { 0x00005020, {1, 1}, VRType::SH, false };
    const tag Erase = { 0x00005190, {1, 1}, VRType::CS, false };
    const tag FindLocation = { 0x00000400, {1, 1}, VRType::AE, false };
    const tag Initiator = { 0x00000200, {1, 1}, VRType::AE, false };
    const tag NormalReverse = { 0x00005140, {1, 1}, VRType::CS, false };
    const tag NumberOfMatches = { 0x00000850, {1, 1}, VRType::US, false };
    const tag MessageSetID = { 0x00005010, {1, 1}, VRType::SH, false };
    const tag Overlays = { 0x000051B0, {1, -1}, VRType::US, false };
    const tag PagePositionID = { 0x00005120, {1, 1}, VRType::LT, false };
    const tag Print = { 0x000051A0, {1, 1}, VRType::CS, false };
    const tag Receiver = { 0x00000300, {1, 1}, VRType::AE, false };
    const tag ResponseSequenceNumber = { 0x00000860, {1, 1}, VRType::US, false };
    const tag TerminalType = { 0x00004010, {1, 1}, VRType::LT, false };
    const tag TextFormatID = { 0x00005130, {1, 1}, VRType::CS, false };

    //--------------------------------------------------------------------------------------------------------

    void populate_data_dictionary(const DataDictionaryPtr& data_dictionary) {
        data_dictionary->Add(&ActionTypeID);
        data_dictionary->Add(&AffectedSOPClassUID);
        data_dictionary->Add(&AffectedSOPInstanceUID);
        data_dictionary->Add(&AttributeIdentifierList);
        data_dictionary->Add(&CommandDataSetType);
        data_dictionary->Add(&CommandField);
        data_dictionary->Add(&CommandGroupLength);
        data_dictionary->Add(&ErrorComment);
        data_dictionary->Add(&ErrorID);
        data_dictionary->Add(&EventTypeID);
        data_dictionary->Add(&MessageID);
        data_dictionary->Add(&MessageIDBeingRespondedTo);
        data_dictionary->Add(&MoveDestination);
        data_dictionary->Add(&MoveOriginatorApplicationEntityTitle);
        data_dictionary->Add(&MoveOriginatorMessageID);
        data_dictionary->Add(&NumberOfCompletedSuboperations);
        data_dictionary->Add(&NumberOfFailedSuboperations);
        data_dictionary->Add(&NumberOfRemainingSuboperations);
        data_dictionary->Add(&NumberOfWarningSuboperations);
        data_dictionary->Add(&RequestedSOPClassUID);
        data_dictionary->Add(&RequestedSOPInstanceUID);
        data_dictionary->Add(&OffendingElement);
        data_dictionary->Add(&Priority);
        data_dictionary->Add(&Status);

        // Deprecated tags
        data_dictionary->Add(&AddGrayScale);
        data_dictionary->Add(&Borders);
        data_dictionary->Add(&CommandLengthToEnd);
        data_dictionary->Add(&CommandMagnificationType);
        data_dictionary->Add(&CommandRecognitionCode);
        data_dictionary->Add(&Copies);
        data_dictionary->Add(&DialogReceiver);
        data_dictionary->Add(&DisplayFormat);
        data_dictionary->Add(&EndMessageID);
        data_dictionary->Add(&Erase);
        data_dictionary->Add(&FindLocation);
        data_dictionary->Add(&Initiator);
        data_dictionary->Add(&NormalReverse);
        data_dictionary->Add(&NumberOfMatches);
        data_dictionary->Add(&MessageSetID);
        data_dictionary->Add(&Overlays);
        data_dictionary->Add(&PagePositionID);
        data_dictionary->Add(&Print);
        data_dictionary->Add(&Receiver);
        data_dictionary->Add(&ResponseSequenceNumber);
        data_dictionary->Add(&TerminalType);
        data_dictionary->Add(&TextFormatID);
    }
}