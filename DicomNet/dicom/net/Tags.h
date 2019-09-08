#pragma once

#include "dicom/DataDictionary.h"

namespace dicom::net::tags {
    DICOMNET_EXPORT void populate_data_dictionary(const DataDictionaryPtr& data_dictionary);

    extern DICOMNET_EXPORT const tag ActionTypeID;
    extern DICOMNET_EXPORT const tag AffectedSOPClassUID;
    extern DICOMNET_EXPORT const tag AffectedSOPInstanceUID;
    extern DICOMNET_EXPORT const tag AttributeIdentifierList;
    extern DICOMNET_EXPORT const tag CommandDataSetType;
    extern DICOMNET_EXPORT const tag CommandField;
    extern DICOMNET_EXPORT const tag CommandGroupLength;
    extern DICOMNET_EXPORT const tag ErrorComment;
    extern DICOMNET_EXPORT const tag ErrorID;
    extern DICOMNET_EXPORT const tag EventTypeID;
    extern DICOMNET_EXPORT const tag MessageID;
    extern DICOMNET_EXPORT const tag MessageIDBeingRespondedTo;
    extern DICOMNET_EXPORT const tag MoveDestination;
    extern DICOMNET_EXPORT const tag MoveOriginatorApplicationEntityTitle;
    extern DICOMNET_EXPORT const tag MoveOriginatorMessageID;
    extern DICOMNET_EXPORT const tag NumberOfCompletedSuboperations;
    extern DICOMNET_EXPORT const tag NumberOfFailedSuboperations;
    extern DICOMNET_EXPORT const tag NumberOfRemainingSuboperations;
    extern DICOMNET_EXPORT const tag NumberOfWarningSuboperations;
    extern DICOMNET_EXPORT const tag RequestedSOPClassUID;
    extern DICOMNET_EXPORT const tag RequestedSOPInstanceUID;
    extern DICOMNET_EXPORT const tag OffendingElement;
    extern DICOMNET_EXPORT const tag Priority;
    extern DICOMNET_EXPORT const tag Status;

    // Deprecated tags
    extern DICOMNET_EXPORT const tag AddGrayScale;
    extern DICOMNET_EXPORT const tag Borders;
    extern DICOMNET_EXPORT const tag CommandLengthToEnd;
    extern DICOMNET_EXPORT const tag CommandMagnificationType;
    extern DICOMNET_EXPORT const tag CommandRecognitionCode;
    extern DICOMNET_EXPORT const tag Copies;
    extern DICOMNET_EXPORT const tag DialogReceiver;
    extern DICOMNET_EXPORT const tag DisplayFormat;
    extern DICOMNET_EXPORT const tag EndMessageID;
    extern DICOMNET_EXPORT const tag Erase;
    extern DICOMNET_EXPORT const tag FindLocation;
    extern DICOMNET_EXPORT const tag Initiator;
    extern DICOMNET_EXPORT const tag NormalReverse;
    extern DICOMNET_EXPORT const tag NumberOfMatches;
    extern DICOMNET_EXPORT const tag MessageSetID;
    extern DICOMNET_EXPORT const tag Overlays;
    extern DICOMNET_EXPORT const tag PagePositionID;
    extern DICOMNET_EXPORT const tag Print;
    extern DICOMNET_EXPORT const tag Receiver;
    extern DICOMNET_EXPORT const tag ResponseSequenceNumber;
    extern DICOMNET_EXPORT const tag TerminalType;
    extern DICOMNET_EXPORT const tag TextFormatID;
}