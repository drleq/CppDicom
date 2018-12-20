#pragma once

#include "dicom/DataDictionary.h"
#include "dicom/tag.h"

namespace dicom {
namespace tags {
    void populate_data_dictionary(const DataDictionaryPtr& data_dictionary);

    /** AbortFlag, (4010,1024), CS, 1,  */
    extern const tag AbortFlag;
    /** AbortReason, (4010,1021), CS, 1-n,  */
    extern const tag AbortReason;
    /** AbsoluteChannelDisplayScale, (003A,0248), FL, 1,  */
    extern const tag AbsoluteChannelDisplayScale;
    /** AbstractPriorCodeSequence, (0072,003E), SQ, 1,  */
    extern const tag AbstractPriorCodeSequence;
    /** AbstractPriorValue, (0072,003C), SS, 2,  */
    extern const tag AbstractPriorValue;
    /** AccessionNumber, (0008,0050), SH, 1,  */
    extern const tag AccessionNumber;
    /** AccessoryCode, (300A,00F9), LO, 1,  */
    extern const tag AccessoryCode;
    /** AcquiredImageAreaDoseProduct, (0018,9473), FL, 1,  */
    extern const tag AcquiredImageAreaDoseProduct;
    /** AcquiredSoundpathLength, (0014,4031), DS, 1,  */
    extern const tag AcquiredSoundpathLength;
    /** AcquisitionComments, (0018,4000), LT, 1, RET */
    extern const tag AcquisitionComments;
    /** AcquisitionCompressionType, (0014,4032), CS, 1,  */
    extern const tag AcquisitionCompressionType;
    /** AcquisitionContextDescription, (0040,0556), ST, 1,  */
    extern const tag AcquisitionContextDescription;
    /** AcquisitionContextSequence, (0040,0555), SQ, 1,  */
    extern const tag AcquisitionContextSequence;
    /** AcquisitionContrast, (0008,9209), CS, 1,  */
    extern const tag AcquisitionContrast;
    /** AcquisitionDate, (0008,0022), DA, 1,  */
    extern const tag AcquisitionDate;
    /** AcquisitionDateTime, (0008,002A), DT, 1,  */
    extern const tag AcquisitionDateTime;
    /** AcquisitionDeviceProcessingCode, (0018,1401), LO, 1,  */
    extern const tag AcquisitionDeviceProcessingCode;
    /** AcquisitionDeviceProcessingDescription, (0018,1400), LO, 1,  */
    extern const tag AcquisitionDeviceProcessingDescription;
    /** AcquisitionDeviceTypeCodeSequence, (0022,0015), SQ, 1,  */
    extern const tag AcquisitionDeviceTypeCodeSequence;
    /** AcquisitionDuration, (0018,9073), FD, 1,  */
    extern const tag AcquisitionDuration;
    /** AcquisitionIndex, (0020,9518), US, 1-n,  */
    extern const tag AcquisitionIndex;
    /** AcquisitionMatrix, (0018,1310), US, 4,  */
    extern const tag AcquisitionMatrix;
    /** AcquisitionNumber, (0020,0012), IS, 1,  */
    extern const tag AcquisitionNumber;
    /** AcquisitionProtocolDescription, (0018,9424), LT, 1,  */
    extern const tag AcquisitionProtocolDescription;
    /** AcquisitionProtocolName, (0018,9423), LO, 1,  */
    extern const tag AcquisitionProtocolName;
    /** AcquisitionSampleSize, (0014,4033), IS, 1,  */
    extern const tag AcquisitionSampleSize;
    /** AcquisitionsInSeries, (0020,1001), IS, 1, RET */
    extern const tag AcquisitionsInSeries;
    /** AcquisitionsInStudy, (0020,1004), IS, 1, RET */
    extern const tag AcquisitionsInStudy;
    /** AcquisitionStartCondition, (0018,0073), CS, 1,  */
    extern const tag AcquisitionStartCondition;
    /** AcquisitionStartConditionData, (0018,0074), IS, 1,  */
    extern const tag AcquisitionStartConditionData;
    /** AcquisitionStatus, (4010,1044), CS, 1,  */
    extern const tag AcquisitionStatus;
    /** AcquisitionTerminationCondition, (0018,0071), CS, 1,  */
    extern const tag AcquisitionTerminationCondition;
    /** AcquisitionTerminationConditionData, (0018,0075), IS, 1,  */
    extern const tag AcquisitionTerminationConditionData;
    /** AcquisitionTime, (0008,0032), TM, 1,  */
    extern const tag AcquisitionTime;
    /** AcquisitionTimeSynchronized, (0018,1800), CS, 1,  */
    extern const tag AcquisitionTimeSynchronized;
    /** AcquisitionType, (0018,9302), CS, 1,  */
    extern const tag AcquisitionType;
    /** AcrossScanSpatialResolution, (0022,0048), FL, 1,  */
    extern const tag AcrossScanSpatialResolution;
    /** ActiveSourceDiameter, (300A,0218), DS, 1,  */
    extern const tag ActiveSourceDiameter;
    /** ActiveSourceLength, (300A,021A), DS, 1,  */
    extern const tag ActiveSourceLength;
    /** ActualCardiacTriggerDelayTime, (0020,9252), FD, 1,  */
    extern const tag ActualCardiacTriggerDelayTime;
    /** ActualCardiacTriggerTimePriorToRPeak, (0020,9155), FL, 1,  */
    extern const tag ActualCardiacTriggerTimePriorToRPeak;
    /** ActualEnvironmentalConditions, (0014,1010), ST, 1,  */
    extern const tag ActualEnvironmentalConditions;
    /** ActualFrameDuration, (0018,1242), IS, 1,  */
    extern const tag ActualFrameDuration;
    /** ActualHumanPerformersSequence, (0040,4035), SQ, 1,  */
    extern const tag ActualHumanPerformersSequence;
    /** ActualRespiratoryTriggerDelayTime, (0020,9257), FD, 1,  */
    extern const tag ActualRespiratoryTriggerDelayTime;
    /** AdaptiveMapFormat, (0028,0730), US, 1, RET */
    extern const tag AdaptiveMapFormat;
    /** AddIntermediateSequence, (0046,0101), SQ, 1,  */
    extern const tag AddIntermediateSequence;
    /** AdditionalDrugSequence, (0018,002A), SQ, 1,  */
    extern const tag AdditionalDrugSequence;
    /** AdditionalPatientHistory, (0010,21B0), LT, 1,  */
    extern const tag AdditionalPatientHistory;
    /** AddNearSequence, (0046,0100), SQ, 1,  */
    extern const tag AddNearSequence;
    /** AddOtherSequence, (0046,0102), SQ, 1,  */
    extern const tag AddOtherSequence;
    /** AddPower, (0046,0104), FD, 1,  */
    extern const tag AddPower;
    /** AddressTrial, (0040,A353), ST, 1, RET */
    extern const tag AddressTrial;
    /** AdministrationRouteCodeSequence, (0054,0302), SQ, 1,  */
    extern const tag AdministrationRouteCodeSequence;
    /** AdmissionID, (0038,0010), LO, 1,  */
    extern const tag AdmissionID;
    /** AdmittingDate, (0038,0020), DA, 1,  */
    extern const tag AdmittingDate;
    /** AdmittingDiagnosesCodeSequence, (0008,1084), SQ, 1,  */
    extern const tag AdmittingDiagnosesCodeSequence;
    /** AdmittingDiagnosesDescription, (0008,1080), LO, 1-n,  */
    extern const tag AdmittingDiagnosesDescription;
    /** AdmittingTime, (0038,0021), TM, 1,  */
    extern const tag AdmittingTime;
    /** AgeCorrectedSensitivityDeviationAlgorithmSequence, (0024,0065), SQ, 1,  */
    extern const tag AgeCorrectedSensitivityDeviationAlgorithmSequence;
    /** AgeCorrectedSensitivityDeviationProbabilityValue, (0024,0100), FL, 1,  */
    extern const tag AgeCorrectedSensitivityDeviationProbabilityValue;
    /** AgeCorrectedSensitivityDeviationValue, (0024,0092), FL, 1,  */
    extern const tag AgeCorrectedSensitivityDeviationValue;
    /** AirCounts, (0014,3070), OB or OW, 1,  */
    extern const tag AirCounts;
    /** AlarmDecision, (4010,1031), CS, 1,  */
    extern const tag AlarmDecision;
    /** AlarmDecisionTime, (4010,102B), DT, 1,  */
    extern const tag AlarmDecisionTime;
    /** AlgorithmCodeSequenceTrial, (0040,A296), SQ, 1, RET */
    extern const tag AlgorithmCodeSequenceTrial;
    /** AlgorithmDescription, (0018,9528), LO, 1,  */
    extern const tag AlgorithmDescription;
    /** AlgorithmDescriptionTrial, (0040,A297), ST, 1, RET */
    extern const tag AlgorithmDescriptionTrial;
    /** AlgorithmFamilyCodeSequence, (0066,002F), SQ, 1,  */
    extern const tag AlgorithmFamilyCodeSequence;
    /** AlgorithmName, (0066,0036), LO, 1,  */
    extern const tag AlgorithmName;
    /** AlgorithmNameCodeSequence, (0066,0030), SQ, 1,  */
    extern const tag AlgorithmNameCodeSequence;
    /** AlgorithmParameters, (0066,0032), LT, 1,  */
    extern const tag AlgorithmParameters;
    /** AlgorithmRoutingCodeSequence, (4010,1064), SQ, 1,  */
    extern const tag AlgorithmRoutingCodeSequence;
    /** AlgorithmSource, (0024,0202), LO, 1,  */
    extern const tag AlgorithmSource;
    /** AlgorithmType, (0018,9527), CS, 1,  */
    extern const tag AlgorithmType;
    /** AlgorithmVersion, (0066,0031), LO, 1,  */
    extern const tag AlgorithmVersion;
    /** AliasedDataType, (0018,980B), CS, 1,  */
    extern const tag AliasedDataType;
    /** ALinePixelSpacing, (0052,0014), FD, 1,  */
    extern const tag ALinePixelSpacing;
    /** ALineRate, (0052,0011), FD, 1,  */
    extern const tag ALineRate;
    /** ALinesPerFrame, (0052,0012), US, 1,  */
    extern const tag ALinesPerFrame;
    /** Allergies, (0010,2110), LO, 1-n,  */
    extern const tag Allergies;
    /** AllowLossyCompression, (2200,000F), CS, 1,  */
    extern const tag AllowLossyCompression;
    /** AllowMediaSplitting, (2200,0007), CS, 1,  */
    extern const tag AllowMediaSplitting;
    /** AlongScanSpatialResolution, (0022,0037), FL, 1,  */
    extern const tag AlongScanSpatialResolution;
    /** AlphaLUTTransferFunction, (0028,1410), CS, 1,  */
    extern const tag AlphaLUTTransferFunction;
    /** AlphaPaletteColorLookupTableData, (0028,1204), OW, 1,  */
    extern const tag AlphaPaletteColorLookupTableData;
    /** AlphaPaletteColorLookupTableDescriptor, (0028,1104), US, 3,  */
    extern const tag AlphaPaletteColorLookupTableDescriptor;
    /** AlternateContainerIdentifierSequence, (0040,0515), SQ, 1,  */
    extern const tag AlternateContainerIdentifierSequence;
    /** AlternateContentDescriptionSequence, (0070,0087), SQ, 1,  */
    extern const tag AlternateContentDescriptionSequence;
    /** AlternateRepresentationSequence, (0008,3001), SQ, 1,  */
    extern const tag AlternateRepresentationSequence;
    /** AmplifierType, (0014,400A), CS, 1,  */
    extern const tag AmplifierType;
    /** AnatomicalOrientationType, (0010,2210), CS, 1,  */
    extern const tag AnatomicalOrientationType;
    /** AnatomicApproachDirectionCodeSequenceTrial, (0008,2255), SQ, 1, RET */
    extern const tag AnatomicApproachDirectionCodeSequenceTrial;
    /** AnatomicLocationOfExaminingInstrumentCodeSequenceTrial, (0008,2259), SQ, 1, RET */
    extern const tag AnatomicLocationOfExaminingInstrumentCodeSequenceTrial;
    /** AnatomicLocationOfExaminingInstrumentDescriptionTrial, (0008,2258), ST, 1, RET */
    extern const tag AnatomicLocationOfExaminingInstrumentDescriptionTrial;
    /** AnatomicPerspectiveCodeSequenceTrial, (0008,2257), SQ, 1, RET */
    extern const tag AnatomicPerspectiveCodeSequenceTrial;
    /** AnatomicPerspectiveDescriptionTrial, (0008,2256), ST, 1, RET */
    extern const tag AnatomicPerspectiveDescriptionTrial;
    /** AnatomicPortalOfEntranceCodeSequenceTrial, (0008,2253), SQ, 1, RET */
    extern const tag AnatomicPortalOfEntranceCodeSequenceTrial;
    /** AnatomicRegionModifierSequence, (0008,2220), SQ, 1,  */
    extern const tag AnatomicRegionModifierSequence;
    /** AnatomicRegionSequence, (0008,2218), SQ, 1,  */
    extern const tag AnatomicRegionSequence;
    /** AnatomicStructure, (0008,2208), CS, 1, RET */
    extern const tag AnatomicStructure;
    /** AnatomicStructureSpaceOrRegionCodeSequenceTrial, (0008,2251), SQ, 1, RET */
    extern const tag AnatomicStructureSpaceOrRegionCodeSequenceTrial;
    /** AnatomicStructureSpaceOrRegionModifierCodeSequenceTrial, (0008,225A), SQ, 1, RET */
    extern const tag AnatomicStructureSpaceOrRegionModifierCodeSequenceTrial;
    /** AnatomicStructureSpaceOrRegionSequence, (0008,2229), SQ, 1,  */
    extern const tag AnatomicStructureSpaceOrRegionSequence;
    /** AnchorPoint, (0070,0014), FL, 2,  */
    extern const tag AnchorPoint;
    /** AnchorPointAnnotationUnits, (0070,0004), CS, 1,  */
    extern const tag AnchorPointAnnotationUnits;
    /** AnchorPointVisibility, (0070,0015), CS, 1,  */
    extern const tag AnchorPointVisibility;
    /** AngioFlag, (0018,0025), CS, 1,  */
    extern const tag AngioFlag;
    /** AngleNumber, (0020,0018), IS, 1, RET */
    extern const tag AngleNumber;
    /** AngularPosition, (0018,1141), DS, 1, RET */
    extern const tag AngularPosition;
    /** AngularStep, (0018,1144), DS, 1,  */
    extern const tag AngularStep;
    /** AngularViewVector, (0054,0090), US, 1-n,  */
    extern const tag AngularViewVector;
    /** AnnotationContentSequence, (2130,0050), SQ, 1, RET */
    extern const tag AnnotationContentSequence;
    /** AnnotationDisplayFormatID, (2010,0030), CS, 1,  */
    extern const tag AnnotationDisplayFormatID;
    /** AnnotationFlag, (2000,0065), CS, 1, RET */
    extern const tag AnnotationFlag;
    /** AnnotationGroupNumber, (0040,A180), US, 1,  */
    extern const tag AnnotationGroupNumber;
    /** AnnotationPosition, (2030,0010), US, 1,  */
    extern const tag AnnotationPosition;
    /** AnodeTargetMaterial, (0018,1191), CS, 1,  */
    extern const tag AnodeTargetMaterial;
    /** AnteriorChamberDepth, (0022,1131), FL, 1,  */
    extern const tag AnteriorChamberDepth;
    /** AnteriorChamberDepthDefinitionCodeSequence, (0022,1125), SQ, 1,  */
    extern const tag AnteriorChamberDepthDefinitionCodeSequence;
    /** AnteriorChamberDepthSequence, (0022,1128), SQ, 1,  */
    extern const tag AnteriorChamberDepthSequence;
    /** ApexPosition, (0020,9308), FD, 3,  */
    extern const tag ApexPosition;
    /** ApplicableFrameRange, (0028,6102), US, 2-2n,  */
    extern const tag ApplicableFrameRange;
    /** ApplicableSafetyStandardAgency, (0018,9174), CS, 1,  */
    extern const tag ApplicableSafetyStandardAgency;
    /** ApplicableSafetyStandardDescription, (0018,9175), LO, 1,  */
    extern const tag ApplicableSafetyStandardDescription;
    /** ApplicationManufacturer, (0018,9526), LO, 1,  */
    extern const tag ApplicationManufacturer;
    /** ApplicationMaximumRepaintTime, (0072,010E), US, 1,  */
    extern const tag ApplicationMaximumRepaintTime;
    /** ApplicationName, (0018,9524), LO, 1,  */
    extern const tag ApplicationName;
    /** ApplicationSetupCheck, (3008,0116), CS, 1,  */
    extern const tag ApplicationSetupCheck;
    /** ApplicationSetupManufacturer, (300A,0238), LO, 1,  */
    extern const tag ApplicationSetupManufacturer;
    /** ApplicationSetupName, (300A,0236), LO, 1,  */
    extern const tag ApplicationSetupName;
    /** ApplicationSetupNumber, (300A,0234), IS, 1,  */
    extern const tag ApplicationSetupNumber;
    /** ApplicationSetupSequence, (300A,0230), SQ, 1,  */
    extern const tag ApplicationSetupSequence;
    /** ApplicationSetupType, (300A,0232), CS, 1,  */
    extern const tag ApplicationSetupType;
    /** ApplicationVersion, (0018,9525), LO, 1,  */
    extern const tag ApplicationVersion;
    /** ApplicatorApertureShape, (300A,0432), CS, 1,  */
    extern const tag ApplicatorApertureShape;
    /** ApplicatorDescription, (300A,010A), LO, 1,  */
    extern const tag ApplicatorDescription;
    /** ApplicatorGeometrySequence, (300A,0431), SQ, 1,  */
    extern const tag ApplicatorGeometrySequence;
    /** ApplicatorID, (300A,0108), SH, 1,  */
    extern const tag ApplicatorID;
    /** ApplicatorOpening, (300A,0433), FL, 1,  */
    extern const tag ApplicatorOpening;
    /** ApplicatorOpeningX, (300A,0434), FL, 1,  */
    extern const tag ApplicatorOpeningX;
    /** ApplicatorOpeningY, (300A,0435), FL, 1,  */
    extern const tag ApplicatorOpeningY;
    /** ApplicatorSequence, (300A,0107), SQ, 1,  */
    extern const tag ApplicatorSequence;
    /** ApplicatorType, (300A,0109), CS, 1,  */
    extern const tag ApplicatorType;
    /** ApprovalStatus, (300E,0002), CS, 1,  */
    extern const tag ApprovalStatus;
    /** ApprovalStatusDateTime, (0044,0004), DT, 1,  */
    extern const tag ApprovalStatusDateTime;
    /** ApprovalStatusFurtherDescription, (0044,0003), LT, 1,  */
    extern const tag ApprovalStatusFurtherDescription;
    /** Arbitrary, (4000,0010), LT, 1, RET */
    extern const tag Arbitrary;
    /** ArchiveRequested, (0040,A494), CS, 1,  */
    extern const tag ArchiveRequested;
    /** ArterialSpinLabelingContrast, (0018,9250), CS, 1,  */
    extern const tag ArterialSpinLabelingContrast;
    /** ASLBolusCutoffDelayTime, (0018,925F), UL, 1,  */
    extern const tag ASLBolusCutoffDelayTime;
    /** ASLBolusCutoffFlag, (0018,925C), CS, 1,  */
    extern const tag ASLBolusCutoffFlag;
    /** ASLBolusCutoffTechnique, (0018,925E), LO, 1,  */
    extern const tag ASLBolusCutoffTechnique;
    /** ASLBolusCutoffTimingSequence, (0018,925D), SQ, 1,  */
    extern const tag ASLBolusCutoffTimingSequence;
    /** ASLContext, (0018,9257), CS, 1,  */
    extern const tag ASLContext;
    /** ASLCrusherDescription, (0018,925B), LO, 1,  */
    extern const tag ASLCrusherDescription;
    /** ASLCrusherFlag, (0018,9259), CS, 1,  */
    extern const tag ASLCrusherFlag;
    /** ASLCrusherFlow, (0018,925A), FD, 1,  */
    extern const tag ASLCrusherFlow;
    /** ASLMidSlabPosition, (0018,9256), FD, 3,  */
    extern const tag ASLMidSlabPosition;
    /** ASLPulseTrainDuration, (0018,9258), UL, 1,  */
    extern const tag ASLPulseTrainDuration;
    /** ASLSlabNumber, (0018,9253), US, 1,  */
    extern const tag ASLSlabNumber;
    /** ASLSlabOrientation, (0018,9255), FD, 3,  */
    extern const tag ASLSlabOrientation;
    /** ASLSlabSequence, (0018,9260), SQ, 1,  */
    extern const tag ASLSlabSequence;
    /** ASLSlabThickness, (0018,9254), FD, 1,  */
    extern const tag ASLSlabThickness;
    /** ASLTechniqueDescription, (0018,9252), LO, 1,  */
    extern const tag ASLTechniqueDescription;
    /** AssignedLocation, (4010,102A), SH, 1,  */
    extern const tag AssignedLocation;
    /** AssigningAgencyOrDepartmentCodeSequence, (0040,003A), SQ, 1,  */
    extern const tag AssigningAgencyOrDepartmentCodeSequence;
    /** AssigningFacilitySequence, (0040,0036), SQ, 1,  */
    extern const tag AssigningFacilitySequence;
    /** AssigningJurisdictionCodeSequence, (0040,0039), SQ, 1,  */
    extern const tag AssigningJurisdictionCodeSequence;
    /** ATDAbilityAssessment, (4010,1014), CS, 1,  */
    extern const tag ATDAbilityAssessment;
    /** ATDAssessmentFlag, (4010,1015), CS, 1,  */
    extern const tag ATDAssessmentFlag;
    /** ATDAssessmentProbability, (4010,1016), FL, 1,  */
    extern const tag ATDAssessmentProbability;
    /** ATDAssessmentSequence, (4010,1038), SQ, 1,  */
    extern const tag ATDAssessmentSequence;
    /** AttachedContours, (3006,0049), IS, 1-n,  */
    extern const tag AttachedContours;
    /** AttenuationCorrected, (0018,9759), CS, 1,  */
    extern const tag AttenuationCorrected;
    /** AttenuationCorrectionMethod, (0054,1101), LO, 1,  */
    extern const tag AttenuationCorrectionMethod;
    /** AttenuationCorrectionSource, (0018,9738), CS, 1,  */
    extern const tag AttenuationCorrectionSource;
    /** AttenuationCorrectionTemporalRelationship, (0018,9770), CS, 1,  */
    extern const tag AttenuationCorrectionTemporalRelationship;
    /** AttributeItemSelector, (0074,1054), UL, 1,  */
    extern const tag AttributeItemSelector;
    /** AttributeModificationDateTime, (0400,0562), DT, 1,  */
    extern const tag AttributeModificationDateTime;
    /** AttributeOccurrencePointer, (0074,1052), AT, 1,  */
    extern const tag AttributeOccurrencePointer;
    /** AttributeOccurrencePrivateCreator, (0074,1056), LO, 1,  */
    extern const tag AttributeOccurrencePrivateCreator;
    /** AttributeOccurrenceSequence, (0074,1050), SQ, 1,  */
    extern const tag AttributeOccurrenceSequence;
    /** AudioComments, (50XX,200E), LT, 1, RET */
    extern const range_tag AudioComments;
    /** AudioSampleData, (50XX,200C), OW or OB, 1, RET */
    extern const range_tag AudioSampleData;
    /** AudioSampleFormat, (50XX,2002), US, 1, RET */
    extern const range_tag AudioSampleFormat;
    /** AudioType, (50XX,2000), US, 1, RET */
    extern const range_tag AudioType;
    /** AuthorizationEquipmentCertificationNumber, (0100,0426), LO, 1,  */
    extern const tag AuthorizationEquipmentCertificationNumber;
    /** AuthorObserverSequence, (0040,A078), SQ, 1,  */
    extern const tag AuthorObserverSequence;
    /** AutorefractionLeftEyeSequence, (0046,0052), SQ, 1,  */
    extern const tag AutorefractionLeftEyeSequence;
    /** AutorefractionRightEyeSequence, (0046,0050), SQ, 1,  */
    extern const tag AutorefractionRightEyeSequence;
    /** AveragePulseWidth, (0018,1154), DS, 1,  */
    extern const tag AveragePulseWidth;
    /** AxialAcceptance, (0054,1200), DS, 1,  */
    extern const tag AxialAcceptance;
    /** AxialDetectorDimension, (0018,9727), FD, 1,  */
    extern const tag AxialDetectorDimension;
    /** AxialLengthOfTheEye, (0022,0030), FL, 1,  */
    extern const tag AxialLengthOfTheEye;
    /** AxialMash, (0054,1201), IS, 2,  */
    extern const tag AxialMash;
    /** AxialResolution, (0052,0008), FD, 1,  */
    extern const tag AxialResolution;
    /** AxisLabels, (50XX,0040), SH, 1-n, RET */
    extern const range_tag AxisLabels;
    /** AxisOfRotation, (0066,001B), FL, 3,  */
    extern const tag AxisOfRotation;
    /** AxisUnits, (50XX,0030), SH, 1-n, RET */
    extern const range_tag AxisUnits;
    /** BackgroundColor, (0046,0092), CS, 1,  */
    extern const tag BackgroundColor;
    /** BackgroundIlluminationColorCodeSequence, (0024,0024), SQ, 1,  */
    extern const tag BackgroundIlluminationColorCodeSequence;
    /** BackgroundLuminance, (0024,0020), FL, 1,  */
    extern const tag BackgroundLuminance;
    /** BadPixelImage, (0014,3080), OB, 1,  */
    extern const tag BadPixelImage;
    /** BarcodeSymbology, (2200,0006), CS, 1,  */
    extern const tag BarcodeSymbology;
    /** BarcodeValue, (2200,0005), LT, 1,  */
    extern const tag BarcodeValue;
    /** BaselineCorrection, (0018,9067), CS, 1,  */
    extern const tag BaselineCorrection;
    /** BasicColorImageSequence, (2020,0111), SQ, 1,  */
    extern const tag BasicColorImageSequence;
    /** BasicGrayscaleImageSequence, (2020,0110), SQ, 1,  */
    extern const tag BasicGrayscaleImageSequence;
    /** BasisMaterialsCodeSequence, (4010,1045), SQ, 1,  */
    extern const tag BasisMaterialsCodeSequence;
    /** BeamAngle, (0018,9449), FL, 1,  */
    extern const tag BeamAngle;
    /** BeamCurrentModulationID, (300A,034C), SH, 1,  */
    extern const tag BeamCurrentModulationID;
    /** BeamDescription, (300A,00C3), ST, 1,  */
    extern const tag BeamDescription;
    /** BeamDose, (300A,0084), DS, 1,  */
    extern const tag BeamDose;
    /** BeamDosePointDepth, (300A,0088), FL, 1,  */
    extern const tag BeamDosePointDepth;
    /** BeamDosePointEquivalentDepth, (300A,0089), FL, 1,  */
    extern const tag BeamDosePointEquivalentDepth;
    /** BeamDosePointSSD, (300A,008A), FL, 1,  */
    extern const tag BeamDosePointSSD;
    /** BeamDoseSpecificationPoint, (300A,0082), DS, 3,  */
    extern const tag BeamDoseSpecificationPoint;
    /** BeamLimitingDeviceAngle, (300A,0120), DS, 1,  */
    extern const tag BeamLimitingDeviceAngle;
    /** BeamLimitingDeviceAngleTolerance, (300A,0046), DS, 1,  */
    extern const tag BeamLimitingDeviceAngleTolerance;
    /** BeamLimitingDeviceLeafPairsSequence, (3008,00A0), SQ, 1,  */
    extern const tag BeamLimitingDeviceLeafPairsSequence;
    /** BeamLimitingDevicePositionSequence, (300A,011A), SQ, 1,  */
    extern const tag BeamLimitingDevicePositionSequence;
    /** BeamLimitingDevicePositionTolerance, (300A,004A), DS, 1,  */
    extern const tag BeamLimitingDevicePositionTolerance;
    /** BeamLimitingDeviceRotationDirection, (300A,0121), CS, 1,  */
    extern const tag BeamLimitingDeviceRotationDirection;
    /** BeamLimitingDeviceSequence, (300A,00B6), SQ, 1,  */
    extern const tag BeamLimitingDeviceSequence;
    /** BeamLimitingDeviceToleranceSequence, (300A,0048), SQ, 1,  */
    extern const tag BeamLimitingDeviceToleranceSequence;
    /** BeamMeterset, (300A,0086), DS, 1,  */
    extern const tag BeamMeterset;
    /** BeamName, (300A,00C2), LO, 1,  */
    extern const tag BeamName;
    /** BeamNumber, (300A,00C0), IS, 1,  */
    extern const tag BeamNumber;
    /** BeamOrderIndex, (0074,1324), UL, 1,  */
    extern const tag BeamOrderIndex;
    /** BeamOrderIndexTrial, (0074,1024), IS, 1, RET */
    extern const tag BeamOrderIndexTrial;
    /** BeamSequence, (300A,00B0), SQ, 1,  */
    extern const tag BeamSequence;
    /** BeamSpotSize, (0052,0003), FD, 1,  */
    extern const tag BeamSpotSize;
    /** BeamStopperPosition, (3008,0230), CS, 1,  */
    extern const tag BeamStopperPosition;
    /** BeamTaskSequence, (0074,1020), SQ, 1,  */
    extern const tag BeamTaskSequence;
    /** BeamTaskType, (0074,1022), CS, 1,  */
    extern const tag BeamTaskType;
    /** BeamType, (300A,00C4), CS, 1,  */
    extern const tag BeamType;
    /** BeatRejectionFlag, (0018,1080), CS, 1,  */
    extern const tag BeatRejectionFlag;
    /** BeltHeight, (4010,1062), FL, 1,  */
    extern const tag BeltHeight;
    /** BibliographicCitationTrial, (0040,A16A), ST, 1, RET */
    extern const tag BibliographicCitationTrial;
    /** BillingItemSequence, (0040,0296), SQ, 1,  */
    extern const tag BillingItemSequence;
    /** BillingProcedureStepSequence, (0040,0320), SQ, 1,  */
    extern const tag BillingProcedureStepSequence;
    /** BillingSuppliesAndDevicesSequence, (0040,0324), SQ, 1,  */
    extern const tag BillingSuppliesAndDevicesSequence;
    /** BiPlaneAcquisitionSequence, (0028,5000), SQ, 1, RET */
    extern const tag BiPlaneAcquisitionSequence;
    /** BitsAllocated, (0028,0100), US, 1,  */
    extern const tag BitsAllocated;
    /** BitsForCodeWord, (0028,08X4), US, 1, RET */
    extern const range_tag BitsForCodeWord;
    /** BitsGrouped, (0028,0069), US, 1, RET */
    extern const tag BitsGrouped;
    /** BitsMappedToColorLookupTable, (0028,1403), US, 1,  */
    extern const tag BitsMappedToColorLookupTable;
    /** BitsStored, (0028,0101), US, 1,  */
    extern const tag BitsStored;
    /** BlendingLookupTableData, (0028,1408), OW, 1,  */
    extern const tag BlendingLookupTableData;
    /** BlendingLookupTableDescriptor, (0028,1407), US, 3,  */
    extern const tag BlendingLookupTableDescriptor;
    /** BlendingLUT1Sequence, (0028,1404), SQ, 1,  */
    extern const tag BlendingLUT1Sequence;
    /** BlendingLUT1TransferFunction, (0028,1405), CS, 1,  */
    extern const tag BlendingLUT1TransferFunction;
    /** BlendingLUT2Sequence, (0028,140C), SQ, 1,  */
    extern const tag BlendingLUT2Sequence;
    /** BlendingLUT2TransferFunction, (0028,140D), CS, 1,  */
    extern const tag BlendingLUT2TransferFunction;
    /** BlendingOperationType, (0072,0500), CS, 1,  */
    extern const tag BlendingOperationType;
    /** BlendingPosition, (0070,0405), CS, 1,  */
    extern const tag BlendingPosition;
    /** BlendingSequence, (0070,0402), SQ, 1,  */
    extern const tag BlendingSequence;
    /** BlendingWeightConstant, (0028,1406), FD, 1,  */
    extern const tag BlendingWeightConstant;
    /** BlindSpotLocalized, (0024,0106), CS, 1,  */
    extern const tag BlindSpotLocalized;
    /** BlindSpotXCoordinate, (0024,0107), FL, 1,  */
    extern const tag BlindSpotXCoordinate;
    /** BlindSpotYCoordinate, (0024,0108), FL, 1,  */
    extern const tag BlindSpotYCoordinate;
    /** BlockColumns, (0028,0092), US, 1, RET */
    extern const tag BlockColumns;
    /** BlockData, (300A,0106), DS, 2-2n,  */
    extern const tag BlockData;
    /** BlockDivergence, (300A,00FA), CS, 1,  */
    extern const tag BlockDivergence;
    /** BlockedPixels, (0028,0090), CS, 1, RET */
    extern const tag BlockedPixels;
    /** BlockMountingPosition, (300A,00FB), CS, 1,  */
    extern const tag BlockMountingPosition;
    /** BlockName, (300A,00FE), LO, 1,  */
    extern const tag BlockName;
    /** BlockNumber, (300A,00FC), IS, 1,  */
    extern const tag BlockNumber;
    /** BlockNumberOfPoints, (300A,0104), IS, 1,  */
    extern const tag BlockNumberOfPoints;
    /** BlockRows, (0028,0091), US, 1, RET */
    extern const tag BlockRows;
    /** BlockSequence, (300A,00F4), SQ, 1,  */
    extern const tag BlockSequence;
    /** BlockThickness, (300A,0100), DS, 1,  */
    extern const tag BlockThickness;
    /** BlockTransmission, (300A,0102), DS, 1,  */
    extern const tag BlockTransmission;
    /** BlockTrayID, (300A,00F5), SH, 1,  */
    extern const tag BlockTrayID;
    /** BlockType, (300A,00F8), CS, 1,  */
    extern const tag BlockType;
    /** BloodSignalNulling, (0018,9022), CS, 1,  */
    extern const tag BloodSignalNulling;
    /** BluePaletteColorLookupTableData, (0028,1203), OW, 1,  */
    extern const tag BluePaletteColorLookupTableData;
    /** BluePaletteColorLookupTableDescriptor, (0028,1103), US or SS, 3,  */
    extern const tag BluePaletteColorLookupTableDescriptor;
    /** BoardingPassID, (4010,101A), SH, 1,  */
    extern const tag BoardingPassID;
    /** BodyPartExamined, (0018,0015), CS, 1,  */
    extern const tag BodyPartExamined;
    /** BodyPartThickness, (0018,11A0), DS, 1,  */
    extern const tag BodyPartThickness;
    /** Bold, (0070,0249), CS, 1,  */
    extern const tag Bold;
    /** BolusDescription, (300A,00DD), ST, 1,  */
    extern const tag BolusDescription;
    /** BolusID, (300A,00DC), SH, 1,  */
    extern const tag BolusID;
    /** BoneThermalIndex, (0018,5024), DS, 1,  */
    extern const tag BoneThermalIndex;
    /** BorderDensity, (2010,0100), CS, 1,  */
    extern const tag BorderDensity;
    /** BottomRightHandCornerOfLocalizerArea, (0048,0202), US, 2,  */
    extern const tag BottomRightHandCornerOfLocalizerArea;
    /** BoundingBoxAnnotationUnits, (0070,0003), CS, 1,  */
    extern const tag BoundingBoxAnnotationUnits;
    /** BoundingBoxBottomRightHandCorner, (0070,0011), FL, 2,  */
    extern const tag BoundingBoxBottomRightHandCorner;
    /** BoundingBoxTextHorizontalJustification, (0070,0012), CS, 1,  */
    extern const tag BoundingBoxTextHorizontalJustification;
    /** BoundingBoxTopLeftHandCorner, (0070,0010), FL, 2,  */
    extern const tag BoundingBoxTopLeftHandCorner;
    /** BoundingPolygon, (4010,101D), FL, 6-n,  */
    extern const tag BoundingPolygon;
    /** BoundingRectangle, (0068,6347), FD, 4,  */
    extern const tag BoundingRectangle;
    /** BrachyAccessoryDeviceID, (300A,0263), SH, 1,  */
    extern const tag BrachyAccessoryDeviceID;
    /** BrachyAccessoryDeviceName, (300A,0266), LO, 1,  */
    extern const tag BrachyAccessoryDeviceName;
    /** BrachyAccessoryDeviceNominalThickness, (300A,026A), DS, 1,  */
    extern const tag BrachyAccessoryDeviceNominalThickness;
    /** BrachyAccessoryDeviceNominalTransmission, (300A,026C), DS, 1,  */
    extern const tag BrachyAccessoryDeviceNominalTransmission;
    /** BrachyAccessoryDeviceNumber, (300A,0262), IS, 1,  */
    extern const tag BrachyAccessoryDeviceNumber;
    /** BrachyAccessoryDeviceSequence, (300A,0260), SQ, 1,  */
    extern const tag BrachyAccessoryDeviceSequence;
    /** BrachyAccessoryDeviceType, (300A,0264), CS, 1,  */
    extern const tag BrachyAccessoryDeviceType;
    /** BrachyApplicationSetupDose, (300A,00A4), DS, 1,  */
    extern const tag BrachyApplicationSetupDose;
    /** BrachyApplicationSetupDoseSpecificationPoint, (300A,00A2), DS, 3,  */
    extern const tag BrachyApplicationSetupDoseSpecificationPoint;
    /** BrachyControlPointDeliveredSequence, (3008,0160), SQ, 1,  */
    extern const tag BrachyControlPointDeliveredSequence;
    /** BrachyControlPointSequence, (300A,02D0), SQ, 1,  */
    extern const tag BrachyControlPointSequence;
    /** BrachyReferencedDoseReferenceSequence, (300C,0055), SQ, 1,  */
    extern const tag BrachyReferencedDoseReferenceSequence;
    /** BrachyTreatmentTechnique, (300A,0200), CS, 1,  */
    extern const tag BrachyTreatmentTechnique;
    /** BrachyTreatmentType, (300A,0202), CS, 1,  */
    extern const tag BrachyTreatmentType;
    /** BranchOfService, (0010,1081), LO, 1,  */
    extern const tag BranchOfService;
    /** BreastImplantPresent, (0028,1300), CS, 1,  */
    extern const tag BreastImplantPresent;
    /** BreedRegistrationNumber, (0010,2295), LO, 1,  */
    extern const tag BreedRegistrationNumber;
    /** BreedRegistrationSequence, (0010,2294), SQ, 1,  */
    extern const tag BreedRegistrationSequence;
    /** BreedRegistryCodeSequence, (0010,2296), SQ, 1,  */
    extern const tag BreedRegistryCodeSequence;
    /** BulkMotionCompensationTechnique, (0018,9172), CS, 1,  */
    extern const tag BulkMotionCompensationTechnique;
    /** BulkMotionSignalSource, (0018,9173), CS, 1,  */
    extern const tag BulkMotionSignalSource;
    /** BulkMotionStatus, (0018,9166), CS, 1, RET */
    extern const tag BulkMotionStatus;
    /** BurnedInAnnotation, (0028,0301), CS, 1,  */
    extern const tag BurnedInAnnotation;
    /** CADFileFormat, (0014,0023), ST, 1-n,  */
    extern const tag CADFileFormat;
    /** CalciumScoringMassFactorDevice, (0018,9352), FL, 3,  */
    extern const tag CalciumScoringMassFactorDevice;
    /** CalciumScoringMassFactorPatient, (0018,9351), FL, 1,  */
    extern const tag CalciumScoringMassFactorPatient;
    /** CalculatedAnatomyThickness, (0018,9452), FL, 1,  */
    extern const tag CalculatedAnatomyThickness;
    /** CalculatedDoseReferenceDescription, (3008,0074), ST, 1,  */
    extern const tag CalculatedDoseReferenceDescription;
    /** CalculatedDoseReferenceDoseValue, (3008,0076), DS, 1,  */
    extern const tag CalculatedDoseReferenceDoseValue;
    /** CalculatedDoseReferenceNumber, (3008,0072), IS, 1,  */
    extern const tag CalculatedDoseReferenceNumber;
    /** CalculatedDoseReferenceSequence, (3008,0070), SQ, 1,  */
    extern const tag CalculatedDoseReferenceSequence;
    /** CalculatedFrameList, (0008,1162), UL, 3-3n,  */
    extern const tag CalculatedFrameList;
    /** CalibrationDataSequence, (0054,0306), SQ, 1,  */
    extern const tag CalibrationDataSequence;
    /** CalibrationDate, (0014,407E), DA, 1-n,  */
    extern const tag CalibrationDate;
    /** CalibrationImage, (0050,0004), CS, 1,  */
    extern const tag CalibrationImage;
    /** CalibrationNotes, (0014,3099), LT, 1,  */
    extern const tag CalibrationNotes;
    /** CalibrationProcedure, (0014,4072), ST, 1,  */
    extern const tag CalibrationProcedure;
    /** CalibrationSequence, (0018,9455), SQ, 1,  */
    extern const tag CalibrationSequence;
    /** CalibrationSettingsSequence, (0014,4070), SQ, 1,  */
    extern const tag CalibrationSettingsSequence;
    /** CalibrationTime, (0014,407C), TM, 1-n,  */
    extern const tag CalibrationTime;
    /** CameraAngleOfView, (0022,001E), FL, 1,  */
    extern const tag CameraAngleOfView;
    /** CardiacBeatRejectionTechnique, (0018,9169), CS, 1,  */
    extern const tag CardiacBeatRejectionTechnique;
    /** CardiacCyclePosition, (0018,9236), CS, 1,  */
    extern const tag CardiacCyclePosition;
    /** CardiacFramingType, (0018,1064), LO, 1,  */
    extern const tag CardiacFramingType;
    /** CardiacNumberOfImages, (0018,1090), IS, 1,  */
    extern const tag CardiacNumberOfImages;
    /** CardiacRRIntervalSpecified, (0018,9070), FD, 1,  */
    extern const tag CardiacRRIntervalSpecified;
    /** CardiacSignalSource, (0018,9085), CS, 1,  */
    extern const tag CardiacSignalSource;
    /** CardiacSynchronizationSequence, (0018,9118), SQ, 1,  */
    extern const tag CardiacSynchronizationSequence;
    /** CardiacSynchronizationTechnique, (0018,9037), CS, 1,  */
    extern const tag CardiacSynchronizationTechnique;
    /** CArmPositionerTabletopRelationship, (0018,9474), CS, 1,  */
    extern const tag CArmPositionerTabletopRelationship;
    /** CarrierID, (4010,1058), SH, 1,  */
    extern const tag CarrierID;
    /** CarrierIDAssigningAuthority, (4010,1059), CS, 1,  */
    extern const tag CarrierIDAssigningAuthority;
    /** CassetteID, (0018,1007), LO, 1,  */
    extern const tag CassetteID;
    /** CassetteOrientation, (0018,1402), CS, 1,  */
    extern const tag CassetteOrientation;
    /** CassetteSize, (0018,1403), CS, 1,  */
    extern const tag CassetteSize;
    /** CatchTrialsDataFlag, (0024,0055), CS, 1,  */
    extern const tag CatchTrialsDataFlag;
    /** CatheterDirectionOfRotation, (0052,0031), CS, 1,  */
    extern const tag CatheterDirectionOfRotation;
    /** CatheterRotationalRate, (0052,0013), FD, 1,  */
    extern const tag CatheterRotationalRate;
    /** CenterOfCircularCollimator, (0018,1710), IS, 2,  */
    extern const tag CenterOfCircularCollimator;
    /** CenterOfCircularExposureControlSensingRegion, (0018,9440), SS, 2,  */
    extern const tag CenterOfCircularExposureControlSensingRegion;
    /** CenterOfCircularShutter, (0018,1610), IS, 2,  */
    extern const tag CenterOfCircularShutter;
    /** CenterOfMass, (4010,101B), FL, 3,  */
    extern const tag CenterOfMass;
    /** CenterOfPTO, (4010,101C), FL, 3,  */
    extern const tag CenterOfPTO;
    /** CenterOfRotation, (0066,001C), FL, 3,  */
    extern const tag CenterOfRotation;
    /** CenterOfRotationOffset, (0018,1145), DS, 1,  */
    extern const tag CenterOfRotationOffset;
    /** CertificateOfSigner, (0400,0115), OB, 1,  */
    extern const tag CertificateOfSigner;
    /** CertificateType, (0400,0110), CS, 1,  */
    extern const tag CertificateType;
    /** CertifiedTimestamp, (0400,0310), OB, 1,  */
    extern const tag CertifiedTimestamp;
    /** CertifiedTimestampType, (0400,0305), CS, 1,  */
    extern const tag CertifiedTimestampType;
    /** ChannelBaseline, (003A,0213), DS, 1,  */
    extern const tag ChannelBaseline;
    /** ChannelDefinitionSequence, (003A,0200), SQ, 1,  */
    extern const tag ChannelDefinitionSequence;
    /** ChannelDerivationDescription, (003A,020C), LO, 1,  */
    extern const tag ChannelDerivationDescription;
    /** ChannelDescriptionCodeSequence, (0022,001A), SQ, 1,  */
    extern const tag ChannelDescriptionCodeSequence;
    /** ChannelDisplaySequence, (003A,0242), SQ, 1,  */
    extern const tag ChannelDisplaySequence;
    /** ChannelIdentificationCode, (003A,0301), IS, 1,  */
    extern const tag ChannelIdentificationCode;
    /** ChannelLabel, (003A,0203), SH, 1,  */
    extern const tag ChannelLabel;
    /** ChannelLength, (300A,0284), DS, 1,  */
    extern const tag ChannelLength;
    /** ChannelMaximumValue, (5400,0112), OB or OW, 1,  */
    extern const tag ChannelMaximumValue;
    /** ChannelMinimumValue, (5400,0110), OB or OW, 1,  */
    extern const tag ChannelMinimumValue;
    /** ChannelMode, (003A,0302), CS, 1,  */
    extern const tag ChannelMode;
    /** ChannelNumber, (300A,0282), IS, 1,  */
    extern const tag ChannelNumber;
    /** ChannelOffset, (003A,0218), DS, 1,  */
    extern const tag ChannelOffset;
    /** ChannelPosition, (003A,0245), FL, 1,  */
    extern const tag ChannelPosition;
    /** ChannelRecommendedDisplayCIELabValue, (003A,0244), US, 3,  */
    extern const tag ChannelRecommendedDisplayCIELabValue;
    /** ChannelSampleSkew, (003A,0215), DS, 1,  */
    extern const tag ChannelSampleSkew;
    /** ChannelSensitivity, (003A,0210), DS, 1,  */
    extern const tag ChannelSensitivity;
    /** ChannelSensitivityCorrectionFactor, (003A,0212), DS, 1,  */
    extern const tag ChannelSensitivityCorrectionFactor;
    /** ChannelSensitivityUnitsSequence, (003A,0211), SQ, 1,  */
    extern const tag ChannelSensitivityUnitsSequence;
    /** ChannelSequence, (300A,0280), SQ, 1,  */
    extern const tag ChannelSequence;
    /** ChannelShieldID, (300A,02B3), SH, 1,  */
    extern const tag ChannelShieldID;
    /** ChannelShieldName, (300A,02B4), LO, 1,  */
    extern const tag ChannelShieldName;
    /** ChannelShieldNominalThickness, (300A,02B8), DS, 1,  */
    extern const tag ChannelShieldNominalThickness;
    /** ChannelShieldNominalTransmission, (300A,02BA), DS, 1,  */
    extern const tag ChannelShieldNominalTransmission;
    /** ChannelShieldNumber, (300A,02B2), IS, 1,  */
    extern const tag ChannelShieldNumber;
    /** ChannelShieldSequence, (300A,02B0), SQ, 1,  */
    extern const tag ChannelShieldSequence;
    /** ChannelSourceModifiersSequence, (003A,0209), SQ, 1,  */
    extern const tag ChannelSourceModifiersSequence;
    /** ChannelSourceSequence, (003A,0208), SQ, 1,  */
    extern const tag ChannelSourceSequence;
    /** ChannelStatus, (003A,0205), CS, 1-n,  */
    extern const tag ChannelStatus;
    /** ChannelTimeSkew, (003A,0214), DS, 1,  */
    extern const tag ChannelTimeSkew;
    /** ChannelTotalTime, (300A,0286), DS, 1,  */
    extern const tag ChannelTotalTime;
    /** ChannelWidth, (0046,0042), FD, 1,  */
    extern const tag ChannelWidth;
    /** ChemicalShiftMaximumIntegrationLimitInHz, (0018,9196), FD, 1, RET */
    extern const tag ChemicalShiftMaximumIntegrationLimitInHz;
    /** ChemicalShiftMaximumIntegrationLimitInppm, (0018,9296), FD, 1,  */
    extern const tag ChemicalShiftMaximumIntegrationLimitInppm;
    /** ChemicalShiftMinimumIntegrationLimitInHz, (0018,9195), FD, 1, RET */
    extern const tag ChemicalShiftMinimumIntegrationLimitInHz;
    /** ChemicalShiftMinimumIntegrationLimitInppm, (0018,9295), FD, 1,  */
    extern const tag ChemicalShiftMinimumIntegrationLimitInppm;
    /** ChemicalShiftReference, (0018,9053), FD, 1-2,  */
    extern const tag ChemicalShiftReference;
    /** ChemicalShiftSequence, (0018,9084), SQ, 1,  */
    extern const tag ChemicalShiftSequence;
    /** CineRate, (0018,0040), IS, 1,  */
    extern const tag CineRate;
    /** CineRelativeToRealTime, (0072,0330), FD, 1,  */
    extern const tag CineRelativeToRealTime;
    /** ClinicalTrialCoordinatingCenterName, (0012,0060), LO, 1,  */
    extern const tag ClinicalTrialCoordinatingCenterName;
    /** ClinicalTrialProtocolEthicsCommitteeApprovalNumber, (0012,0082), LO, 1,  */
    extern const tag ClinicalTrialProtocolEthicsCommitteeApprovalNumber;
    /** ClinicalTrialProtocolEthicsCommitteeName, (0012,0081), LO, 1,  */
    extern const tag ClinicalTrialProtocolEthicsCommitteeName;
    /** ClinicalTrialProtocolID, (0012,0020), LO, 1,  */
    extern const tag ClinicalTrialProtocolID;
    /** ClinicalTrialProtocolName, (0012,0021), LO, 1,  */
    extern const tag ClinicalTrialProtocolName;
    /** ClinicalTrialSeriesDescription, (0012,0072), LO, 1,  */
    extern const tag ClinicalTrialSeriesDescription;
    /** ClinicalTrialSeriesID, (0012,0071), LO, 1,  */
    extern const tag ClinicalTrialSeriesID;
    /** ClinicalTrialSiteID, (0012,0030), LO, 1,  */
    extern const tag ClinicalTrialSiteID;
    /** ClinicalTrialSiteName, (0012,0031), LO, 1,  */
    extern const tag ClinicalTrialSiteName;
    /** ClinicalTrialSponsorName, (0012,0010), LO, 1,  */
    extern const tag ClinicalTrialSponsorName;
    /** ClinicalTrialSubjectID, (0012,0040), LO, 1,  */
    extern const tag ClinicalTrialSubjectID;
    /** ClinicalTrialSubjectReadingID, (0012,0042), LO, 1,  */
    extern const tag ClinicalTrialSubjectReadingID;
    /** ClinicalTrialTimePointDescription, (0012,0051), ST, 1,  */
    extern const tag ClinicalTrialTimePointDescription;
    /** ClinicalTrialTimePointID, (0012,0050), LO, 1,  */
    extern const tag ClinicalTrialTimePointID;
    /** CoatingMaterialsCodeSequence, (0068,63A4), SQ, 1,  */
    extern const tag CoatingMaterialsCodeSequence;
    /** CodeLabel, (0028,08X0), CS, 1-n, RET */
    extern const range_tag CodeLabel;
    /** CodeMeaning, (0008,0104), LO, 1,  */
    extern const tag CodeMeaning;
    /** CodeNumberFormat, (0028,0740), US, 1, RET */
    extern const tag CodeNumberFormat;
    /** CodeTableLocation, (0028,08X3), AT, 1-n, RET */
    extern const range_tag CodeTableLocation;
    /** CodeValue, (0008,0100), SH, 1,  */
    extern const tag CodeValue;
    /** CodingSchemeDesignator, (0008,0102), SH, 1,  */
    extern const tag CodingSchemeDesignator;
    /** CodingSchemeExternalID, (0008,0114), ST, 1,  */
    extern const tag CodingSchemeExternalID;
    /** CodingSchemeIdentificationSequence, (0008,0110), SQ, 1,  */
    extern const tag CodingSchemeIdentificationSequence;
    /** CodingSchemeName, (0008,0115), ST, 1,  */
    extern const tag CodingSchemeName;
    /** CodingSchemeRegistry, (0008,0112), LO, 1,  */
    extern const tag CodingSchemeRegistry;
    /** CodingSchemeResponsibleOrganization, (0008,0116), ST, 1,  */
    extern const tag CodingSchemeResponsibleOrganization;
    /** CodingSchemeUID, (0008,010C), UI, 1,  */
    extern const tag CodingSchemeUID;
    /** CodingSchemeVersion, (0008,0103), SH, 1,  */
    extern const tag CodingSchemeVersion;
    /** CoefficientCoding, (0028,04X2), LO, 1-n, RET */
    extern const range_tag CoefficientCoding;
    /** CoefficientCodingPointers, (0028,04X3), AT, 1-n, RET */
    extern const range_tag CoefficientCodingPointers;
    /** CoefficientsSDDN, (7FE0,0040), OW, 1, RET */
    extern const tag CoefficientsSDDN;
    /** CoefficientsSDHN, (7FE0,0030), OW, 1, RET */
    extern const tag CoefficientsSDHN;
    /** CoefficientsSDVN, (7FE0,0020), OW, 1, RET */
    extern const tag CoefficientsSDVN;
    /** CoincidenceWindowWidth, (0054,1210), DS, 1,  */
    extern const tag CoincidenceWindowWidth;
    /** CollationFlag, (2000,0063), CS, 1, RET */
    extern const tag CollationFlag;
    /** CollimatorGridName, (0018,1180), SH, 1,  */
    extern const tag CollimatorGridName;
    /** CollimatorLeftVerticalEdge, (0018,1702), IS, 1,  */
    extern const tag CollimatorLeftVerticalEdge;
    /** CollimatorLowerHorizontalEdge, (0018,1708), IS, 1,  */
    extern const tag CollimatorLowerHorizontalEdge;
    /** CollimatorRightVerticalEdge, (0018,1704), IS, 1,  */
    extern const tag CollimatorRightVerticalEdge;
    /** CollimatorShape, (0018,1700), CS, 1-3,  */
    extern const tag CollimatorShape;
    /** CollimatorShapeSequence, (0018,9407), SQ, 1,  */
    extern const tag CollimatorShapeSequence;
    /** CollimatorType, (0018,1181), CS, 1,  */
    extern const tag CollimatorType;
    /** CollimatorUpperHorizontalEdge, (0018,1706), IS, 1,  */
    extern const tag CollimatorUpperHorizontalEdge;
    /** ColorImagePrintingFlag, (2000,0062), CS, 1, RET */
    extern const tag ColorImagePrintingFlag;
    /** ColumnAngulation, (0018,1450), DS, 1,  */
    extern const tag ColumnAngulation;
    /** ColumnAngulationPatient, (0018,9447), FL, 1,  */
    extern const tag ColumnAngulationPatient;
    /** ColumnOverlap, (0028,0094), US, 1, RET */
    extern const tag ColumnOverlap;
    /** ColumnPositionInTotalImagePixelMatrix, (0048,021F), SL, 1,  */
    extern const tag ColumnPositionInTotalImagePixelMatrix;
    /** Columns, (0028,0011), US, 1,  */
    extern const tag Columns;
    /** ColumnsForNthOrderCoefficients, (0028,04X1), US, 1, RET */
    extern const range_tag ColumnsForNthOrderCoefficients;
    /** CommentsOnPatientPerformanceOfVisualField, (0024,0044), LT, 1,  */
    extern const tag CommentsOnPatientPerformanceOfVisualField;
    /** CommentsOnRadiationDose, (0040,0310), ST, 1,  */
    extern const tag CommentsOnRadiationDose;
    /** CommentsOnThePerformedProcedureStep, (0040,0280), ST, 1,  */
    extern const tag CommentsOnThePerformedProcedureStep;
    /** CommentsOnTheScheduledProcedureStep, (0040,0400), LT, 1,  */
    extern const tag CommentsOnTheScheduledProcedureStep;
    /** CompensatorColumnOffset, (300A,02E5), FL, 1,  */
    extern const tag CompensatorColumnOffset;
    /** CompensatorColumns, (300A,00E8), IS, 1,  */
    extern const tag CompensatorColumns;
    /** CompensatorDescription, (300A,02EB), LT, 1,  */
    extern const tag CompensatorDescription;
    /** CompensatorDivergence, (300A,02E0), CS, 1,  */
    extern const tag CompensatorDivergence;
    /** CompensatorID, (300A,00E5), SH, 1,  */
    extern const tag CompensatorID;
    /** CompensatorMillingToolDiameter, (300A,02E8), FL, 1,  */
    extern const tag CompensatorMillingToolDiameter;
    /** CompensatorMountingPosition, (300A,02E1), CS, 1,  */
    extern const tag CompensatorMountingPosition;
    /** CompensatorNumber, (300A,00E4), IS, 1,  */
    extern const tag CompensatorNumber;
    /** CompensatorPixelSpacing, (300A,00E9), DS, 2,  */
    extern const tag CompensatorPixelSpacing;
    /** CompensatorPosition, (300A,00EA), DS, 2,  */
    extern const tag CompensatorPosition;
    /** CompensatorRelativeStoppingPowerRatio, (300A,02E7), FL, 1,  */
    extern const tag CompensatorRelativeStoppingPowerRatio;
    /** CompensatorRows, (300A,00E7), IS, 1,  */
    extern const tag CompensatorRows;
    /** CompensatorSequence, (300A,00E3), SQ, 1,  */
    extern const tag CompensatorSequence;
    /** CompensatorThicknessData, (300A,00EC), DS, 1-n,  */
    extern const tag CompensatorThicknessData;
    /** CompensatorTransmissionData, (300A,00EB), DS, 1-n,  */
    extern const tag CompensatorTransmissionData;
    /** CompensatorType, (300A,00EE), CS, 1,  */
    extern const tag CompensatorType;
    /** CompletionFlag, (0040,A491), CS, 1,  */
    extern const tag CompletionFlag;
    /** CompletionFlagDescription, (0040,A492), LO, 1,  */
    extern const tag CompletionFlagDescription;
    /** ComplexImageComponent, (0008,9208), CS, 1,  */
    extern const tag ComplexImageComponent;
    /** Component1ReferencedID, (0076,0070), US, 1,  */
    extern const tag Component1ReferencedID;
    /** Component1ReferencedMatingFeatureID, (0076,0090), US, 1,  */
    extern const tag Component1ReferencedMatingFeatureID;
    /** Component1ReferencedMatingFeatureSetID, (0076,0080), US, 1,  */
    extern const tag Component1ReferencedMatingFeatureSetID;
    /** Component2ReferencedID, (0076,00A0), US, 1,  */
    extern const tag Component2ReferencedID;
    /** Component2ReferencedMatingFeatureID, (0076,00C0), US, 1,  */
    extern const tag Component2ReferencedMatingFeatureID;
    /** Component2ReferencedMatingFeatureSetID, (0076,00B0), US, 1,  */
    extern const tag Component2ReferencedMatingFeatureSetID;
    /** ComponentAssemblySequence, (0076,0060), SQ, 1,  */
    extern const tag ComponentAssemblySequence;
    /** ComponentID, (0076,0055), US, 1,  */
    extern const tag ComponentID;
    /** ComponentManufacturer, (0014,0028), ST, 1-n,  */
    extern const tag ComponentManufacturer;
    /** ComponentManufacturingProcedure, (0014,0025), ST, 1-n,  */
    extern const tag ComponentManufacturingProcedure;
    /** ComponentReferenceSystem, (0014,0024), ST, 1-n,  */
    extern const tag ComponentReferenceSystem;
    /** ComponentSequence, (0076,0040), SQ, 1,  */
    extern const tag ComponentSequence;
    /** ComponentShape, (0014,0050), CS, 1,  */
    extern const tag ComponentShape;
    /** ComponentTypeCodeSequence, (0076,0034), CS, 1,  */
    extern const tag ComponentTypeCodeSequence;
    /** ComponentTypesSequence, (0076,0032), SQ, 1,  */
    extern const tag ComponentTypesSequence;
    /** CompoundGraphicInstanceID, (0070,0226), UL, 1,  */
    extern const tag CompoundGraphicInstanceID;
    /** CompoundGraphicSequence, (0070,0209), SQ, 1,  */
    extern const tag CompoundGraphicSequence;
    /** CompoundGraphicType, (0070,0294), CS, 1,  */
    extern const tag CompoundGraphicType;
    /** CompoundGraphicUnits, (0070,0282), CS, 1,  */
    extern const tag CompoundGraphicUnits;
    /** CompressionCode, (0028,0060), CS, 1, RET */
    extern const tag CompressionCode;
    /** CompressionDescription, (0028,0063), SH, 1, RET */
    extern const tag CompressionDescription;
    /** CompressionForce, (0018,11A2), DS, 1,  */
    extern const tag CompressionForce;
    /** CompressionLabel, (0028,0062), LO, 1, RET */
    extern const tag CompressionLabel;
    /** CompressionOriginator, (0028,0061), SH, 1, RET */
    extern const tag CompressionOriginator;
    /** CompressionRecognitionCode, (0028,005F), LO, 1, RET */
    extern const tag CompressionRecognitionCode;
    /** CompressionSequence, (0028,0065), CS, 1-n, RET */
    extern const tag CompressionSequence;
    /** CompressionStepPointers, (0028,0066), AT, 1-n, RET */
    extern const tag CompressionStepPointers;
    /** ConcatenationFrameOffsetNumber, (0020,9228), UL, 1,  */
    extern const tag ConcatenationFrameOffsetNumber;
    /** ConcatenationUID, (0020,9161), UI, 1,  */
    extern const tag ConcatenationUID;
    /** ConceptCodeSequence, (0040,A168), SQ, 1,  */
    extern const tag ConceptCodeSequence;
    /** ConceptNameCodeSequence, (0040,A043), SQ, 1,  */
    extern const tag ConceptNameCodeSequence;
    /** CondenserLensPower, (0048,0111), DS, 1,  */
    extern const tag CondenserLensPower;
    /** ConfidentialityCode, (0040,1008), LO, 1,  */
    extern const tag ConfidentialityCode;
    /** ConfidentialityConstraintOnPatientDataDescription, (0040,3001), LO, 1,  */
    extern const tag ConfidentialityConstraintOnPatientDataDescription;
    /** ConfigurationInformation, (2010,0150), ST, 1,  */
    extern const tag ConfigurationInformation;
    /** ConfigurationInformationDescription, (2010,0152), LT, 1,  */
    extern const tag ConfigurationInformationDescription;
    /** ConsentForClinicalTrialUseSequence, (0012,0083), SQ, 1,  */
    extern const tag ConsentForClinicalTrialUseSequence;
    /** ConsentForDistributionFlag, (0012,0085), CS, 1,  */
    extern const tag ConsentForDistributionFlag;
    /** ConstantVolumeFlag, (0018,9333), CS, 1,  */
    extern const tag ConstantVolumeFlag;
    /** ConstraintWeight, (300A,0021), DS, 1,  */
    extern const tag ConstraintWeight;
    /** ContactDisplayName, (0074,100C), LO, 1,  */
    extern const tag ContactDisplayName;
    /** ContactURI, (0074,100A), ST, 1,  */
    extern const tag ContactURI;
    /** ContainerComponentDescription, (0050,001E), LO, 1,  */
    extern const tag ContainerComponentDescription;
    /** ContainerComponentDiameter, (0050,001D), FD, 1,  */
    extern const tag ContainerComponentDiameter;
    /** ContainerComponentID, (0050,001B), LO, 1,  */
    extern const tag ContainerComponentID;
    /** ContainerComponentLength, (0050,001C), FD, 1,  */
    extern const tag ContainerComponentLength;
    /** ContainerComponentMaterial, (0050,001A), CS, 1,  */
    extern const tag ContainerComponentMaterial;
    /** ContainerComponentSequence, (0040,0520), SQ, 1,  */
    extern const tag ContainerComponentSequence;
    /** ContainerComponentThickness, (0050,0013), FD, 1,  */
    extern const tag ContainerComponentThickness;
    /** ContainerComponentTypeCodeSequence, (0050,0012), SQ, 1,  */
    extern const tag ContainerComponentTypeCodeSequence;
    /** ContainerComponentWidth, (0050,0015), FD, 1,  */
    extern const tag ContainerComponentWidth;
    /** ContainerDescription, (0040,051A), LO, 1,  */
    extern const tag ContainerDescription;
    /** ContainerIdentifier, (0040,0512), LO, 1,  */
    extern const tag ContainerIdentifier;
    /** ContainerTypeCodeSequence, (0040,0518), SQ, 1,  */
    extern const tag ContainerTypeCodeSequence;
    /** ContentCreatorIdentificationCodeSequence, (0070,0086), SQ, 1,  */
    extern const tag ContentCreatorIdentificationCodeSequence;
    /** ContentCreatorName, (0070,0084), PN, 1,  */
    extern const tag ContentCreatorName;
    /** ContentDate, (0008,0023), DA, 1,  */
    extern const tag ContentDate;
    /** ContentDescription, (0070,0081), LO, 1,  */
    extern const tag ContentDescription;
    /** ContentItemModifierSequence, (0040,0441), SQ, 1,  */
    extern const tag ContentItemModifierSequence;
    /** ContentLabel, (0070,0080), CS, 1,  */
    extern const tag ContentLabel;
    /** ContentQualification, (0018,9004), CS, 1,  */
    extern const tag ContentQualification;
    /** ContentSequence, (0040,A730), SQ, 1,  */
    extern const tag ContentSequence;
    /** ContentTemplateSequence, (0040,A504), SQ, 1,  */
    extern const tag ContentTemplateSequence;
    /** ContentTime, (0008,0033), TM, 1,  */
    extern const tag ContentTime;
    /** ContextGroupExtensionCreatorUID, (0008,010D), UI, 1,  */
    extern const tag ContextGroupExtensionCreatorUID;
    /** ContextGroupExtensionFlag, (0008,010B), CS, 1,  */
    extern const tag ContextGroupExtensionFlag;
    /** ContextGroupLocalVersion, (0008,0107), DT, 1,  */
    extern const tag ContextGroupLocalVersion;
    /** ContextGroupVersion, (0008,0106), DT, 1,  */
    extern const tag ContextGroupVersion;
    /** ContextIdentifier, (0008,010F), CS, 1,  */
    extern const tag ContextIdentifier;
    /** ContextUID, (0008,0117), UI, 1,  */
    extern const tag ContextUID;
    /** ContinuationEndMeterset, (0074,0121), FD, 1,  */
    extern const tag ContinuationEndMeterset;
    /** ContinuationStartMeterset, (0074,0120), FD, 1,  */
    extern const tag ContinuationStartMeterset;
    /** ContinuityOfContent, (0040,A050), CS, 1,  */
    extern const tag ContinuityOfContent;
    /** ContourData, (3006,0050), DS, 3-3n,  */
    extern const tag ContourData;
    /** ContourGeometricType, (3006,0042), CS, 1,  */
    extern const tag ContourGeometricType;
    /** ContourImageSequence, (3006,0016), SQ, 1,  */
    extern const tag ContourImageSequence;
    /** ContourNumber, (3006,0048), IS, 1,  */
    extern const tag ContourNumber;
    /** ContourOffsetVector, (3006,0045), DS, 3,  */
    extern const tag ContourOffsetVector;
    /** ContourSequence, (3006,0040), SQ, 1,  */
    extern const tag ContourSequence;
    /** ContourSlabThickness, (3006,0044), DS, 1,  */
    extern const tag ContourSlabThickness;
    /** ContourUncertaintyRadius, (0070,0312), FD, 1,  */
    extern const tag ContourUncertaintyRadius;
    /** ContrastAdministrationProfileSequence, (0018,9340), SQ, 1,  */
    extern const tag ContrastAdministrationProfileSequence;
    /** ContrastBolusAdministrationRouteSequence, (0018,0014), SQ, 1,  */
    extern const tag ContrastBolusAdministrationRouteSequence;
    /** ContrastBolusAgent, (0018,0010), LO, 1,  */
    extern const tag ContrastBolusAgent;
    /** ContrastBolusAgentAdministered, (0018,9342), CS, 1,  */
    extern const tag ContrastBolusAgentAdministered;
    /** ContrastBolusAgentDetected, (0018,9343), CS, 1,  */
    extern const tag ContrastBolusAgentDetected;
    /** ContrastBolusAgentNumber, (0018,9337), US, 1,  */
    extern const tag ContrastBolusAgentNumber;
    /** ContrastBolusAgentPhase, (0018,9344), CS, 1,  */
    extern const tag ContrastBolusAgentPhase;
    /** ContrastBolusAgentSequence, (0018,0012), SQ, 1,  */
    extern const tag ContrastBolusAgentSequence;
    /** ContrastBolusIngredient, (0018,1048), CS, 1,  */
    extern const tag ContrastBolusIngredient;
    /** ContrastBolusIngredientCodeSequence, (0018,9338), SQ, 1,  */
    extern const tag ContrastBolusIngredientCodeSequence;
    /** ContrastBolusIngredientConcentration, (0018,1049), DS, 1,  */
    extern const tag ContrastBolusIngredientConcentration;
    /** ContrastBolusIngredientOpaque, (0018,9425), CS, 1,  */
    extern const tag ContrastBolusIngredientOpaque;
    /** ContrastBolusIngredientPercentByVolume, (0052,0001), FL, 1,  */
    extern const tag ContrastBolusIngredientPercentByVolume;
    /** ContrastBolusRoute, (0018,1040), LO, 1,  */
    extern const tag ContrastBolusRoute;
    /** ContrastBolusStartTime, (0018,1042), TM, 1,  */
    extern const tag ContrastBolusStartTime;
    /** ContrastBolusStopTime, (0018,1043), TM, 1,  */
    extern const tag ContrastBolusStopTime;
    /** ContrastBolusTotalDose, (0018,1044), DS, 1,  */
    extern const tag ContrastBolusTotalDose;
    /** ContrastBolusUsageSequence, (0018,9341), SQ, 1,  */
    extern const tag ContrastBolusUsageSequence;
    /** ContrastBolusVolume, (0018,1041), DS, 1,  */
    extern const tag ContrastBolusVolume;
    /** ContrastFlowDuration, (0018,1047), DS, 1-n,  */
    extern const tag ContrastFlowDuration;
    /** ContrastFlowRate, (0018,1046), DS, 1-n,  */
    extern const tag ContrastFlowRate;
    /** ContrastFrameAveraging, (0028,6112), US, 1,  */
    extern const tag ContrastFrameAveraging;
    /** ContributingEquipmentSequence, (0018,A001), SQ, 1,  */
    extern const tag ContributingEquipmentSequence;
    /** ContributingSOPInstancesReferenceSequence, (0020,9529), SQ, 1,  */
    extern const tag ContributingSOPInstancesReferenceSequence;
    /** ContributingSourcesSequence, (0018,9506), SQ, 1,  */
    extern const tag ContributingSourcesSequence;
    /** ContributionDateTime, (0018,A002), DT, 1,  */
    extern const tag ContributionDateTime;
    /** ContributionDescription, (0018,A003), ST, 1,  */
    extern const tag ContributionDescription;
    /** ControlPoint3DPosition, (300A,02D4), DS, 3,  */
    extern const tag ControlPoint3DPosition;
    /** ControlPointDeliverySequence, (3008,0040), SQ, 1,  */
    extern const tag ControlPointDeliverySequence;
    /** ControlPointIndex, (300A,0112), IS, 1,  */
    extern const tag ControlPointIndex;
    /** ControlPointOrientation, (300A,0412), FL, 3,  */
    extern const tag ControlPointOrientation;
    /** ControlPointRelativePosition, (300A,02D2), DS, 1,  */
    extern const tag ControlPointRelativePosition;
    /** ControlPointSequence, (300A,0111), SQ, 1,  */
    extern const tag ControlPointSequence;
    /** ConventionalControlPointVerificationSequence, (0074,104C), SQ, 1,  */
    extern const tag ConventionalControlPointVerificationSequence;
    /** ConventionalMachineVerificationSequence, (0074,1044), SQ, 1,  */
    extern const tag ConventionalMachineVerificationSequence;
    /** ConversionType, (0008,0064), CS, 1,  */
    extern const tag ConversionType;
    /** ConvolutionKernel, (0018,1210), SH, 1-n,  */
    extern const tag ConvolutionKernel;
    /** ConvolutionKernelGroup, (0018,9316), CS, 1,  */
    extern const tag ConvolutionKernelGroup;
    /** CoordinatesSetGeometricTypeTrial, (0040,A290), CS, 1, RET */
    extern const tag CoordinatesSetGeometricTypeTrial;
    /** CoordinateStartValue, (50XX,0112), US, 1-n, RET */
    extern const range_tag CoordinateStartValue;
    /** CoordinateStepValue, (50XX,0114), US, 1-n, RET */
    extern const range_tag CoordinateStepValue;
    /** CoordinateSystemAxesSequence, (0014,2204), SQ, 1,  */
    extern const tag CoordinateSystemAxesSequence;
    /** CoordinateSystemAxisCodeSequence, (0040,08DA), SQ, 1, RET */
    extern const tag CoordinateSystemAxisCodeSequence;
    /** CoordinateSystemAxisDescription, (0014,2206), ST, 1,  */
    extern const tag CoordinateSystemAxisDescription;
    /** CoordinateSystemAxisNumber, (0014,220A), IS, 1,  */
    extern const tag CoordinateSystemAxisNumber;
    /** CoordinateSystemAxisType, (0014,220C), CS, 1,  */
    extern const tag CoordinateSystemAxisType;
    /** CoordinateSystemAxisUnits, (0014,220E), CS, 1,  */
    extern const tag CoordinateSystemAxisUnits;
    /** CoordinateSystemAxisValues, (0014,2210), OB, 1,  */
    extern const tag CoordinateSystemAxisValues;
    /** CoordinateSystemDataSetMapping, (0014,2208), CS, 1,  */
    extern const tag CoordinateSystemDataSetMapping;
    /** CoordinateSystemNumberOfAxes, (0014,2202), IS, 1,  */
    extern const tag CoordinateSystemNumberOfAxes;
    /** CoordinateSystemTransformRotationAndScaleMatrix, (0014,222A), DS, 1-n,  */
    extern const tag CoordinateSystemTransformRotationAndScaleMatrix;
    /** CoordinateSystemTransformSequence, (0014,2220), SQ, 1,  */
    extern const tag CoordinateSystemTransformSequence;
    /** CoordinateSystemTransformTranslationMatrix, (0014,222C), DS, 1-n,  */
    extern const tag CoordinateSystemTransformTranslationMatrix;
    /** CornealSize, (0046,0046), FD, 1,  */
    extern const tag CornealSize;
    /** CorrectedImage, (0028,0051), CS, 1-n,  */
    extern const tag CorrectedImage;
    /** CorrectedLocalizedDeviationFromNormal, (0024,0079), FL, 1,  */
    extern const tag CorrectedLocalizedDeviationFromNormal;
    /** CorrectedLocalizedDeviationFromNormalCalculated, (0024,0078), CS, 1,  */
    extern const tag CorrectedLocalizedDeviationFromNormalCalculated;
    /** CorrectedLocalizedDeviationFromNormalProbability, (0024,0081), FL, 1,  */
    extern const tag CorrectedLocalizedDeviationFromNormalProbability;
    /** CorrectedLocalizedDeviationFromNormalProbabilityCalculated, (0024,0080), CS, 1,  */
    extern const tag CorrectedLocalizedDeviationFromNormalProbabilityCalculated;
    /** CorrectedParameterSequence, (3008,0068), SQ, 1,  */
    extern const tag CorrectedParameterSequence;
    /** CorrectionValue, (3008,006A), FL, 1,  */
    extern const tag CorrectionValue;
    /** CountLossNormalizationCorrected, (0018,9764), CS, 1,  */
    extern const tag CountLossNormalizationCorrected;
    /** CountRate, (0018,1243), IS, 1,  */
    extern const tag CountRate;
    /** CountryOfResidence, (0010,2150), LO, 1,  */
    extern const tag CountryOfResidence;
    /** CountsAccumulated, (0018,0070), IS, 1,  */
    extern const tag CountsAccumulated;
    /** CountsIncluded, (0054,1400), CS, 1-n, RET */
    extern const tag CountsIncluded;
    /** CountsSource, (0054,1002), CS, 1,  */
    extern const tag CountsSource;
    /** CouplingMedium, (0014,4056), ST, 1,  */
    extern const tag CouplingMedium;
    /** CouplingTechnique, (0014,4054), ST, 1,  */
    extern const tag CouplingTechnique;
    /** CouplingVelocity, (0014,4057), DS, 1,  */
    extern const tag CouplingVelocity;
    /** CoverageOfKSpace, (0018,9094), CS, 1,  */
    extern const tag CoverageOfKSpace;
    /** CranialThermalIndex, (0018,5026), DS, 1,  */
    extern const tag CranialThermalIndex;
    /** CreationDate, (2100,0040), DA, 1,  */
    extern const tag CreationDate;
    /** CreationTime, (2100,0050), TM, 1,  */
    extern const tag CreationTime;
    /** CreatorVersionUID, (0008,9123), UI, 1,  */
    extern const tag CreatorVersionUID;
    /** CrystalCenterLocationX, (0014,4058), DS, 1,  */
    extern const tag CrystalCenterLocationX;
    /** CrystalCenterLocationZ, (0014,4059), DS, 1,  */
    extern const tag CrystalCenterLocationZ;
    /** CSSFontName, (0070,0229), LO, 1,  */
    extern const tag CSSFontName;
    /** CTAcquisitionDetailsSequence, (0018,9304), SQ, 1,  */
    extern const tag CTAcquisitionDetailsSequence;
    /** CTAcquisitionTypeSequence, (0018,9301), SQ, 1,  */
    extern const tag CTAcquisitionTypeSequence;
    /** CTAdditionalXRaySourceSequence, (0018,9360), SQ, 1,  */
    extern const tag CTAdditionalXRaySourceSequence;
    /** CTDIPhantomTypeCodeSequence, (0018,9346), SQ, 1,  */
    extern const tag CTDIPhantomTypeCodeSequence;
    /** CTDIvol, (0018,9345), FD, 1,  */
    extern const tag CTDIvol;
    /** CTExposureSequence, (0018,9321), SQ, 1,  */
    extern const tag CTExposureSequence;
    /** CTGeometrySequence, (0018,9312), SQ, 1,  */
    extern const tag CTGeometrySequence;
    /** CTImageFrameTypeSequence, (0018,9329), SQ, 1,  */
    extern const tag CTImageFrameTypeSequence;
    /** CTPositionSequence, (0018,9326), SQ, 1,  */
    extern const tag CTPositionSequence;
    /** CTReconstructionSequence, (0018,9314), SQ, 1,  */
    extern const tag CTReconstructionSequence;
    /** CTTableDynamicsSequence, (0018,9308), SQ, 1,  */
    extern const tag CTTableDynamicsSequence;
    /** CTXRayDetailsSequence, (0018,9325), SQ, 1,  */
    extern const tag CTXRayDetailsSequence;
    /** CumulativeDoseReferenceCoefficient, (300A,010C), DS, 1,  */
    extern const tag CumulativeDoseReferenceCoefficient;
    /** CumulativeDoseToDoseReference, (3008,0052), DS, 1,  */
    extern const tag CumulativeDoseToDoseReference;
    /** CumulativeMetersetWeight, (300A,0134), DS, 1,  */
    extern const tag CumulativeMetersetWeight;
    /** CumulativeTimeWeight, (300A,02D6), DS, 1,  */
    extern const tag CumulativeTimeWeight;
    /** CurrentFractionNumber, (3008,0022), IS, 1,  */
    extern const tag CurrentFractionNumber;
    /** CurrentObserverTrial, (0040,A307), PN, 1, RET */
    extern const tag CurrentObserverTrial;
    /** CurrentPatientLocation, (0038,0300), LO, 1,  */
    extern const tag CurrentPatientLocation;
    /** CurrentRequestedProcedureEvidenceSequence, (0040,A375), SQ, 1,  */
    extern const tag CurrentRequestedProcedureEvidenceSequence;
    /** CurrentTreatmentStatus, (3008,0200), CS, 1,  */
    extern const tag CurrentTreatmentStatus;
    /** CurvatureType, (0014,0052), CS, 1,  */
    extern const tag CurvatureType;
    /** CurveActivationLayer, (50XX,1001), CS, 1, RET */
    extern const range_tag CurveActivationLayer;
    /** CurveData, (50XX,3000), OW or OB, 1, RET */
    extern const range_tag CurveData;
    /** CurveDataDescriptor, (50XX,0110), US, 1-n, RET */
    extern const range_tag CurveDataDescriptor;
    /** CurveDate, (0008,0025), DA, 1, RET */
    extern const tag CurveDate;
    /** CurveDescription, (50XX,0022), LO, 1, RET */
    extern const range_tag CurveDescription;
    /** CurveDimensions, (50XX,0005), US, 1, RET */
    extern const range_tag CurveDimensions;
    /** CurveLabel, (50XX,2500), LO, 1, RET */
    extern const range_tag CurveLabel;
    /** CurveNumber, (0020,0024), IS, 1, RET */
    extern const tag CurveNumber;
    /** CurveRange, (50XX,0106), SH, 1-n, RET */
    extern const range_tag CurveRange;
    /** CurveReferencedOverlayGroup, (50XX,2610), US, 1, RET */
    extern const range_tag CurveReferencedOverlayGroup;
    /** CurveReferencedOverlaySequence, (50XX,2600), SQ, 1, RET */
    extern const range_tag CurveReferencedOverlaySequence;
    /** CurveTime, (0008,0035), TM, 1, RET */
    extern const tag CurveTime;
    /** CustodialOrganizationSequence, (0040,A07C), SQ, 1,  */
    extern const tag CustodialOrganizationSequence;
    /** CylinderAxis, (0022,0009), FL, 1,  */
    extern const tag CylinderAxis;
    /** CylinderLensPower, (0022,0008), FL, 1,  */
    extern const tag CylinderLensPower;
    /** CylinderPower, (0046,0147), FD, 1,  */
    extern const tag CylinderPower;
    /** CylinderSequence, (0046,0018), SQ, 1,  */
    extern const tag CylinderSequence;
    /** DACAmplitude, (0014,403C), DS, 1-n,  */
    extern const tag DACAmplitude;
    /** DACGainPoints, (0014,4038), DS, 1-n,  */
    extern const tag DACGainPoints;
    /** DACSequence, (0014,4035), SQ, 1,  */
    extern const tag DACSequence;
    /** DACTimePoints, (0014,403A), DS, 1-n,  */
    extern const tag DACTimePoints;
    /** DACType, (0014,4036), CS, 1,  */
    extern const tag DACType;
    /** Damping, (0014,4028), DS, 1,  */
    extern const tag Damping;
    /** DarkCurrentCounts, (0014,3050), OB or OW, 1,  */
    extern const tag DarkCurrentCounts;
    /** DarkCurrentSequence, (0014,3040), SQ, 1,  */
    extern const tag DarkCurrentSequence;
    /** DataBlock, (0028,0702), AT, 1-n, RET */
    extern const tag DataBlock;
    /** DataBlockDescription, (0028,0701), CS, 1-n, RET */
    extern const tag DataBlockDescription;
    /** DataCollectionCenterPatient, (0018,9313), FD, 3,  */
    extern const tag DataCollectionCenterPatient;
    /** DataCollectionDiameter, (0018,0090), DS, 1,  */
    extern const tag DataCollectionDiameter;
    /** DataElementsSigned, (0400,0020), AT, 1-n,  */
    extern const tag DataElementsSigned;
    /** DataFrameAssignmentSequence, (0028,1401), SQ, 1,  */
    extern const tag DataFrameAssignmentSequence;
    /** DataInformationSequence, (0054,0063), SQ, 1,  */
    extern const tag DataInformationSequence;
    /** DataObservationSequence, (0024,0325), SQ, 1,  */
    extern const tag DataObservationSequence;
    /** DataPathAssignment, (0028,1402), CS, 1,  */
    extern const tag DataPathAssignment;
    /** DataPathID, (0028,140E), CS, 1,  */
    extern const tag DataPathID;
    /** DataPointColumns, (0028,9002), UL, 1,  */
    extern const tag DataPointColumns;
    /** DataPointRows, (0028,9001), UL, 1,  */
    extern const tag DataPointRows;
    /** DataRepresentation, (0028,9108), CS, 1,  */
    extern const tag DataRepresentation;
    /** DataSetDescription, (0024,0309), LO, 1,  */
    extern const tag DataSetDescription;
    /** DataSetName, (0024,0306), LO, 1,  */
    extern const tag DataSetName;
    /** DataSetSource, (0024,0308), LO, 1,  */
    extern const tag DataSetSource;
    /** DataSetSubtype, (0008,0041), LO, 1, RET */
    extern const tag DataSetSubtype;
    /** DataSetTrailingPadding, (FFFC,FFFC), OB, 1,  */
    extern const tag DataSetTrailingPadding;
    /** DataSetType, (0008,0040), US, 1, RET */
    extern const tag DataSetType;
    /** DataSetVersion, (0024,0307), LO, 1,  */
    extern const tag DataSetVersion;
    /** DataType, (0018,9808), CS, 1,  */
    extern const tag DataType;
    /** DataValueRepresentation, (50XX,0103), US, 1, RET */
    extern const range_tag DataValueRepresentation;
    /** Date, (0040,A121), DA, 1,  */
    extern const tag Date;
    /** DateOfDocumentOrVerbalTransactionTrial, (0040,A110), DA, 1, RET */
    extern const tag DateOfDocumentOrVerbalTransactionTrial;
    /** DateOfGainCalibration, (0014,3076), DA, 1,  */
    extern const tag DateOfGainCalibration;
    /** DateOfLastCalibration, (0018,1200), DA, 1-n,  */
    extern const tag DateOfLastCalibration;
    /** DateOfLastDetectorCalibration, (0018,700C), DA, 1,  */
    extern const tag DateOfLastDetectorCalibration;
    /** DateOfSecondaryCapture, (0018,1012), DA, 1,  */
    extern const tag DateOfSecondaryCapture;
    /** DateTime, (0040,A120), DT, 1,  */
    extern const tag DateTime;
    /** dBdt, (0018,1318), DS, 1,  */
    extern const tag dBdt;
    /** DCTLabel, (0028,0700), LO, 1, RET */
    extern const tag DCTLabel;
    /** DeadTimeCorrected, (0018,9761), CS, 1,  */
    extern const tag DeadTimeCorrected;
    /** DeadTimeCorrectionFlag, (0054,1401), CS, 1, RET */
    extern const tag DeadTimeCorrectionFlag;
    /** DeadTimeFactor, (0054,1324), DS, 1,  */
    extern const tag DeadTimeFactor;
    /** DecayCorrected, (0018,9758), CS, 1,  */
    extern const tag DecayCorrected;
    /** DecayCorrection, (0054,1102), CS, 1,  */
    extern const tag DecayCorrection;
    /** DecayCorrectionDateTime, (0018,9701), DT, 1,  */
    extern const tag DecayCorrectionDateTime;
    /** DecayFactor, (0054,1321), DS, 1,  */
    extern const tag DecayFactor;
    /** DecimalVisualAcuity, (0046,0137), FD, 1,  */
    extern const tag DecimalVisualAcuity;
    /** DecimateCropResult, (2020,00A2), CS, 1,  */
    extern const tag DecimateCropResult;
    /** DecoupledNucleus, (0018,9060), CS, 1-2,  */
    extern const tag DecoupledNucleus;
    /** Decoupling, (0018,9059), CS, 1,  */
    extern const tag Decoupling;
    /** DecouplingChemicalShiftReference, (0018,9063), FD, 1-2,  */
    extern const tag DecouplingChemicalShiftReference;
    /** DecouplingFrequency, (0018,9061), FD, 1-2,  */
    extern const tag DecouplingFrequency;
    /** DecouplingMethod, (0018,9062), CS, 1,  */
    extern const tag DecouplingMethod;
    /** DefaultMagnificationType, (2010,00A6), CS, 1,  */
    extern const tag DefaultMagnificationType;
    /** DefaultPrinterResolutionID, (2010,0054), CS, 1,  */
    extern const tag DefaultPrinterResolutionID;
    /** DefaultSmoothingType, (2010,00A8), CS, 1,  */
    extern const tag DefaultSmoothingType;
    /** DeformableRegistrationGridSequence, (0064,0005), SQ, 1,  */
    extern const tag DeformableRegistrationGridSequence;
    /** DeformableRegistrationSequence, (0064,0002), SQ, 1,  */
    extern const tag DeformableRegistrationSequence;
    /** DegreeOfDilation, (0022,000E), FL, 1,  */
    extern const tag DegreeOfDilation;
    /** DegreeOfFreedomID, (0068,6410), US, 1,  */
    extern const tag DegreeOfFreedomID;
    /** DegreeOfFreedomType, (0068,6420), CS, 1,  */
    extern const tag DegreeOfFreedomType;
    /** DeidentificationMethod, (0012,0063), LO, 1-n,  */
    extern const tag DeidentificationMethod;
    /** DeidentificationMethodCodeSequence, (0012,0064), SQ, 1,  */
    extern const tag DeidentificationMethodCodeSequence;
    /** DelayLawIdentifier, (0014,405C), ST, 1,  */
    extern const tag DelayLawIdentifier;
    /** DeletionLock, (0074,1230), LO, 1,  */
    extern const tag DeletionLock;
    /** DeliveredChannelTotalTime, (3008,0134), DS, 1,  */
    extern const tag DeliveredChannelTotalTime;
    /** DeliveredMeterset, (3008,0044), DS, 1,  */
    extern const tag DeliveredMeterset;
    /** DeliveredNumberOfPulses, (3008,0138), IS, 1,  */
    extern const tag DeliveredNumberOfPulses;
    /** DeliveredPrimaryMeterset, (3008,0036), DS, 1,  */
    extern const tag DeliveredPrimaryMeterset;
    /** DeliveredPulseRepetitionInterval, (3008,013C), DS, 1,  */
    extern const tag DeliveredPulseRepetitionInterval;
    /** DeliveredSecondaryMeterset, (3008,0037), DS, 1,  */
    extern const tag DeliveredSecondaryMeterset;
    /** DeliveredTreatmentTime, (3008,003B), DS, 1,  */
    extern const tag DeliveredTreatmentTime;
    /** DeliveryMaximumDose, (300A,0023), DS, 1,  */
    extern const tag DeliveryMaximumDose;
    /** DeliveryVerificationImageSequence, (0074,1030), SQ, 1,  */
    extern const tag DeliveryVerificationImageSequence;
    /** DeliveryWarningDose, (300A,0022), DS, 1,  */
    extern const tag DeliveryWarningDose;
    /** Density, (4010,1018), FL, 1,  */
    extern const tag Density;
    /** DepthOfScanField, (0018,5050), IS, 1,  */
    extern const tag DepthOfScanField;
    /** DepthOfTransverseImage, (0022,0041), FL, 1,  */
    extern const tag DepthOfTransverseImage;
    /** DepthsOfFocus, (0018,9801), FD, 1-n,  */
    extern const tag DepthsOfFocus;
    /** DepthSpatialResolution, (0022,0035), FL, 1,  */
    extern const tag DepthSpatialResolution;
    /** DerivationCodeSequence, (0008,9215), SQ, 1,  */
    extern const tag DerivationCodeSequence;
    /** DerivationDescription, (0008,2111), ST, 1,  */
    extern const tag DerivationDescription;
    /** DerivationImageSequence, (0008,9124), SQ, 1,  */
    extern const tag DerivationImageSequence;
    /** DerivationImplantAssemblyTemplateSequence, (0076,000E), SQ, 1,  */
    extern const tag DerivationImplantAssemblyTemplateSequence;
    /** DerivationImplantTemplateSequence, (0068,6224), SQ, 1,  */
    extern const tag DerivationImplantTemplateSequence;
    /** DestinationAE, (2100,0140), AE, 1, RET */
    extern const tag DestinationAE;
    /** DetailsOfCoefficients, (0028,0404), AT, 1-n, RET */
    extern const tag DetailsOfCoefficients;
    /** DetectorActivationOffsetFromExposure, (0018,7016), DS, 1,  */
    extern const tag DetectorActivationOffsetFromExposure;
    /** DetectorActiveDimensions, (0018,7026), DS, 1-2,  */
    extern const tag DetectorActiveDimensions;
    /** DetectorActiveOrigin, (0018,7028), DS, 2,  */
    extern const tag DetectorActiveOrigin;
    /** DetectorActiveShape, (0018,7024), CS, 1,  */
    extern const tag DetectorActiveShape;
    /** DetectorActiveTime, (0018,7014), DS, 1,  */
    extern const tag DetectorActiveTime;
    /** DetectorBinning, (0018,701A), DS, 2,  */
    extern const tag DetectorBinning;
    /** DetectorCalibrationData, (4010,106C), OB, 1,  */
    extern const tag DetectorCalibrationData;
    /** DetectorConditionsNominalFlag, (0018,7000), CS, 1,  */
    extern const tag DetectorConditionsNominalFlag;
    /** DetectorConfiguration, (0018,7005), CS, 1,  */
    extern const tag DetectorConfiguration;
    /** DetectorDescription, (0018,7006), LT, 1,  */
    extern const tag DetectorDescription;
    /** DetectorElementPhysicalSize, (0018,7020), DS, 2,  */
    extern const tag DetectorElementPhysicalSize;
    /** DetectorElementSize, (0054,1203), DS, 2,  */
    extern const tag DetectorElementSize;
    /** DetectorElementSpacing, (0018,7022), DS, 2,  */
    extern const tag DetectorElementSpacing;
    /** DetectorGeometry, (0018,9725), CS, 1,  */
    extern const tag DetectorGeometry;
    /** DetectorGeometrySequence, (4010,0004), SQ, 1,  */
    extern const tag DetectorGeometrySequence;
    /** DetectorID, (0018,700A), SH, 1,  */
    extern const tag DetectorID;
    /** DetectorInformationSequence, (0054,0022), SQ, 1,  */
    extern const tag DetectorInformationSequence;
    /** DetectorLinesOfResponseUsed, (0054,1104), LO, 1,  */
    extern const tag DetectorLinesOfResponseUsed;
    /** DetectorManufacturerModelName, (0018,702B), LO, 1,  */
    extern const tag DetectorManufacturerModelName;
    /** DetectorManufacturerName, (0018,702A), LO, 1,  */
    extern const tag DetectorManufacturerName;
    /** DetectorMode, (0018,7008), LT, 1,  */
    extern const tag DetectorMode;
    /** DetectorNormalizationCorrection, (0018,9768), CS, 1,  */
    extern const tag DetectorNormalizationCorrection;
    /** DetectorPrimaryAngle, (0018,1530), DS, 1,  */
    extern const tag DetectorPrimaryAngle;
    /** DetectorSecondaryAngle, (0018,1531), DS, 1,  */
    extern const tag DetectorSecondaryAngle;
    /** DetectorTemperature, (0018,7001), DS, 1,  */
    extern const tag DetectorTemperature;
    /** DetectorTemperatureSequence, (0014,3020), SQ, 1,  */
    extern const tag DetectorTemperatureSequence;
    /** DetectorTimeSinceLastExposure, (0018,7012), DS, 1,  */
    extern const tag DetectorTimeSinceLastExposure;
    /** DetectorType, (0018,7004), CS, 1,  */
    extern const tag DetectorType;
    /** DetectorVector, (0054,0020), US, 1-n,  */
    extern const tag DetectorVector;
    /** DeviationIndex, (0018,1413), DS, 1,  */
    extern const tag DeviationIndex;
    /** DeviceDescription, (0050,0020), LO, 1,  */
    extern const tag DeviceDescription;
    /** DeviceDiameter, (0050,0016), DS, 1,  */
    extern const tag DeviceDiameter;
    /** DeviceDiameterUnits, (0050,0017), CS, 1,  */
    extern const tag DeviceDiameterUnits;
    /** DeviceID, (0018,1003), LO, 1,  */
    extern const tag DeviceID;
    /** DeviceLength, (0050,0014), DS, 1,  */
    extern const tag DeviceLength;
    /** DeviceSequence, (0050,0010), SQ, 1,  */
    extern const tag DeviceSequence;
    /** DeviceSerialNumber, (0018,1000), LO, 1,  */
    extern const tag DeviceSerialNumber;
    /** DeviceUID, (0018,1002), UI, 1,  */
    extern const tag DeviceUID;
    /** DeviceVolume, (0050,0018), DS, 1,  */
    extern const tag DeviceVolume;
    /** DiameterOfVisibility, (0070,0262), FL, 1,  */
    extern const tag DiameterOfVisibility;
    /** DiaphragmPosition, (3002,0034), DS, 4,  */
    extern const tag DiaphragmPosition;
    /** DICOMMediaRetrievalSequence, (0040,E022), SQ, 1,  */
    extern const tag DICOMMediaRetrievalSequence;
    /** DICOMRetrievalSequence, (0040,E021), SQ, 1,  */
    extern const tag DICOMRetrievalSequence;
    /** DICOSVersion, (4010,103A), CS, 1,  */
    extern const tag DICOSVersion;
    /** DiffusionAnisotropyType, (0018,9147), CS, 1,  */
    extern const tag DiffusionAnisotropyType;
    /** DiffusionBMatrixSequence, (0018,9601), SQ, 1,  */
    extern const tag DiffusionBMatrixSequence;
    /** DiffusionBValue, (0018,9087), FD, 1,  */
    extern const tag DiffusionBValue;
    /** DiffusionBValueXX, (0018,9602), FD, 1,  */
    extern const tag DiffusionBValueXX;
    /** DiffusionBValueXY, (0018,9603), FD, 1,  */
    extern const tag DiffusionBValueXY;
    /** DiffusionBValueXZ, (0018,9604), FD, 1,  */
    extern const tag DiffusionBValueXZ;
    /** DiffusionBValueYY, (0018,9605), FD, 1,  */
    extern const tag DiffusionBValueYY;
    /** DiffusionBValueYZ, (0018,9606), FD, 1,  */
    extern const tag DiffusionBValueYZ;
    /** DiffusionBValueZZ, (0018,9607), FD, 1,  */
    extern const tag DiffusionBValueZZ;
    /** DiffusionDirectionality, (0018,9075), CS, 1,  */
    extern const tag DiffusionDirectionality;
    /** DiffusionGradientDirectionSequence, (0018,9076), SQ, 1,  */
    extern const tag DiffusionGradientDirectionSequence;
    /** DiffusionGradientOrientation, (0018,9089), FD, 3,  */
    extern const tag DiffusionGradientOrientation;
    /** DigitalImageFormatAcquired, (0018,1023), LO, 1,  */
    extern const tag DigitalImageFormatAcquired;
    /** DigitalSignatureDateTime, (0400,0105), DT, 1,  */
    extern const tag DigitalSignatureDateTime;
    /** DigitalSignaturePurposeCodeSequence, (0400,0401), SQ, 1,  */
    extern const tag DigitalSignaturePurposeCodeSequence;
    /** DigitalSignaturesSequence, (FFFA,FFFA), SQ, 1,  */
    extern const tag DigitalSignaturesSequence;
    /** DigitalSignatureUID, (0400,0100), UI, 1,  */
    extern const tag DigitalSignatureUID;
    /** DigitizingDeviceTransportDirection, (0018,2020), CS, 1,  */
    extern const tag DigitizingDeviceTransportDirection;
    /** DimensionDescriptionLabel, (0020,9421), LO, 1,  */
    extern const tag DimensionDescriptionLabel;
    /** DimensionIndexPointer, (0020,9165), AT, 1,  */
    extern const tag DimensionIndexPointer;
    /** DimensionIndexPrivateCreator, (0020,9213), LO, 1,  */
    extern const tag DimensionIndexPrivateCreator;
    /** DimensionIndexSequence, (0020,9222), SQ, 1,  */
    extern const tag DimensionIndexSequence;
    /** DimensionIndexValues, (0020,9157), UL, 1-n,  */
    extern const tag DimensionIndexValues;
    /** DimensionOrganizationSequence, (0020,9221), SQ, 1,  */
    extern const tag DimensionOrganizationSequence;
    /** DimensionOrganizationType, (0020,9311), CS, 1,  */
    extern const tag DimensionOrganizationType;
    /** DimensionOrganizationUID, (0020,9164), UI, 1,  */
    extern const tag DimensionOrganizationUID;
    /** DirectoryRecordSequence, (0004,1220), SQ, 1,  */
    extern const tag DirectoryRecordSequence;
    /** DirectoryRecordType, (0004,1430), CS, 1,  */
    extern const tag DirectoryRecordType;
    /** DischargeDate, (0038,0030), DA, 1, RET */
    extern const tag DischargeDate;
    /** DischargeDiagnosisCodeSequence, (0038,0044), SQ, 1, RET */
    extern const tag DischargeDiagnosisCodeSequence;
    /** DischargeDiagnosisDescription, (0038,0040), LO, 1, RET */
    extern const tag DischargeDiagnosisDescription;
    /** DischargeTime, (0038,0032), TM, 1, RET */
    extern const tag DischargeTime;
    /** DisplayedAreaBottomRightHandCorner, (0070,0053), SL, 2,  */
    extern const tag DisplayedAreaBottomRightHandCorner;
    /** DisplayedAreaBottomRightHandCornerTrial, (0070,0051), US, 2, RET */
    extern const tag DisplayedAreaBottomRightHandCornerTrial;
    /** DisplayedAreaSelectionSequence, (0070,005A), SQ, 1,  */
    extern const tag DisplayedAreaSelectionSequence;
    /** DisplayedAreaTopLeftHandCorner, (0070,0052), SL, 2,  */
    extern const tag DisplayedAreaTopLeftHandCorner;
    /** DisplayedAreaTopLeftHandCornerTrial, (0070,0050), US, 2, RET */
    extern const tag DisplayedAreaTopLeftHandCornerTrial;
    /** DisplayEnvironmentSpatialPosition, (0072,0108), FD, 4,  */
    extern const tag DisplayEnvironmentSpatialPosition;
    /** DisplayFilterPercentage, (0028,9411), FL, 1,  */
    extern const tag DisplayFilterPercentage;
    /** DisplaySetHorizontalJustification, (0072,0717), CS, 1,  */
    extern const tag DisplaySetHorizontalJustification;
    /** DisplaySetLabel, (0072,0203), LO, 1,  */
    extern const tag DisplaySetLabel;
    /** DisplaySetNumber, (0072,0202), US, 1,  */
    extern const tag DisplaySetNumber;
    /** DisplaySetPatientOrientation, (0072,0700), CS, 2,  */
    extern const tag DisplaySetPatientOrientation;
    /** DisplaySetPresentationGroup, (0072,0204), US, 1,  */
    extern const tag DisplaySetPresentationGroup;
    /** DisplaySetPresentationGroupDescription, (0072,0206), LO, 1,  */
    extern const tag DisplaySetPresentationGroupDescription;
    /** DisplaySetScrollingGroup, (0072,0212), US, 2-n,  */
    extern const tag DisplaySetScrollingGroup;
    /** DisplaySetsSequence, (0072,0200), SQ, 1,  */
    extern const tag DisplaySetsSequence;
    /** DisplaySetVerticalJustification, (0072,0718), CS, 1,  */
    extern const tag DisplaySetVerticalJustification;
    /** DisplayShadingFlag, (003A,0246), CS, 1,  */
    extern const tag DisplayShadingFlag;
    /** DisplayWindowLabelVector, (0018,2006), SH, 1-n,  */
    extern const tag DisplayWindowLabelVector;
    /** DistanceBetweenFocalPlanes, (0048,0014), FL, 1,  */
    extern const tag DistanceBetweenFocalPlanes;
    /** DistanceObjectToTableTop, (0018,9403), FL, 1,  */
    extern const tag DistanceObjectToTableTop;
    /** DistancePupillaryDistance, (0046,0060), FD, 1,  */
    extern const tag DistancePupillaryDistance;
    /** DistanceReceptorPlaneToDetectorHousing, (0018,9426), FL, 1,  */
    extern const tag DistanceReceptorPlaneToDetectorHousing;
    /** DistanceSourceToDataCollectionCenter, (0018,9335), FD, 1,  */
    extern const tag DistanceSourceToDataCollectionCenter;
    /** DistanceSourceToDetector, (0018,1110), DS, 1,  */
    extern const tag DistanceSourceToDetector;
    /** DistanceSourceToEntrance, (0040,0306), DS, 1,  */
    extern const tag DistanceSourceToEntrance;
    /** DistanceSourceToIsocenter, (0018,9402), FL, 1,  */
    extern const tag DistanceSourceToIsocenter;
    /** DistanceSourceToPatient, (0018,1111), DS, 1,  */
    extern const tag DistanceSourceToPatient;
    /** DistanceSourceToSupport, (0040,0307), DS, 1, RET */
    extern const tag DistanceSourceToSupport;
    /** DistributionAddress, (4008,011A), LO, 1, RET */
    extern const tag DistributionAddress;
    /** DistributionName, (4008,0119), PN, 1, RET */
    extern const tag DistributionName;
    /** DistributionType, (0012,0084), CS, 1,  */
    extern const tag DistributionType;
    /** DocumentAuthorIdentifierCodeSequenceTrial, (0040,A068), SQ, 1, RET */
    extern const tag DocumentAuthorIdentifierCodeSequenceTrial;
    /** DocumentAuthorTrial, (0040,A067), PN, 1, RET */
    extern const tag DocumentAuthorTrial;
    /** DocumentClassCodeSequence, (0040,E008), SQ, 1,  */
    extern const tag DocumentClassCodeSequence;
    /** DocumentIdentifierCodeSequenceTrial, (0040,A066), SQ, 1, RET */
    extern const tag DocumentIdentifierCodeSequenceTrial;
    /** DocumentingObserverIdentifierCodeSequenceTrial, (0040,A076), SQ, 1, RET */
    extern const tag DocumentingObserverIdentifierCodeSequenceTrial;
    /** DocumentingOrganizationIdentifierCodeSequenceTrial, (0040,A028), SQ, 1, RET */
    extern const tag DocumentingOrganizationIdentifierCodeSequenceTrial;
    /** DocumentTitle, (0042,0010), ST, 1,  */
    extern const tag DocumentTitle;
    /** DopplerCorrectionAngle, (0018,6034), FD, 1,  */
    extern const tag DopplerCorrectionAngle;
    /** DopplerSampleVolumeXPosition, (0018,6039), SL, 1,  */
    extern const tag DopplerSampleVolumeXPosition;
    /** DopplerSampleVolumeXPositionRetired, (0018,6038), UL, 1, RET */
    extern const tag DopplerSampleVolumeXPositionRetired;
    /** DopplerSampleVolumeYPosition, (0018,603B), SL, 1,  */
    extern const tag DopplerSampleVolumeYPosition;
    /** DopplerSampleVolumeYPositionRetired, (0018,603A), UL, 1, RET */
    extern const tag DopplerSampleVolumeYPositionRetired;
    /** DoseCalibrationFactor, (0054,1322), DS, 1,  */
    extern const tag DoseCalibrationFactor;
    /** DoseComment, (3004,0006), LO, 1,  */
    extern const tag DoseComment;
    /** DoseGridScaling, (3004,000E), DS, 1,  */
    extern const tag DoseGridScaling;
    /** DoseRateDelivered, (3008,0048), DS, 1,  */
    extern const tag DoseRateDelivered;
    /** DoseRateSet, (300A,0115), DS, 1,  */
    extern const tag DoseRateSet;
    /** DoseReferenceDescription, (300A,0016), LO, 1,  */
    extern const tag DoseReferenceDescription;
    /** DoseReferenceNumber, (300A,0012), IS, 1,  */
    extern const tag DoseReferenceNumber;
    /** DoseReferencePointCoordinates, (300A,0018), DS, 3,  */
    extern const tag DoseReferencePointCoordinates;
    /** DoseReferenceSequence, (300A,0010), SQ, 1,  */
    extern const tag DoseReferenceSequence;
    /** DoseReferenceStructureType, (300A,0014), CS, 1,  */
    extern const tag DoseReferenceStructureType;
    /** DoseReferenceType, (300A,0020), CS, 1,  */
    extern const tag DoseReferenceType;
    /** DoseReferenceUID, (300A,0013), UI, 1,  */
    extern const tag DoseReferenceUID;
    /** DoseSummationType, (3004,000A), CS, 1,  */
    extern const tag DoseSummationType;
    /** DoseType, (3004,0004), CS, 1,  */
    extern const tag DoseType;
    /** DoseUnits, (3004,0002), CS, 1,  */
    extern const tag DoseUnits;
    /** DoseValue, (3004,0012), DS, 1,  */
    extern const tag DoseValue;
    /** DoubleExposureFieldDelta, (0074,133A), FD, 4,  */
    extern const tag DoubleExposureFieldDelta;
    /** DoubleExposureFieldDeltaTrial, (0074,103A), DS, 4, RET */
    extern const tag DoubleExposureFieldDeltaTrial;
    /** DoubleExposureFlag, (0074,1034), CS, 1,  */
    extern const tag DoubleExposureFlag;
    /** DoubleExposureMeterset, (0074,1338), FD, 1,  */
    extern const tag DoubleExposureMeterset;
    /** DoubleExposureMetersetTrial, (0074,1038), DS, 1, RET */
    extern const tag DoubleExposureMetersetTrial;
    /** DoubleExposureOrdering, (0074,1036), CS, 1,  */
    extern const tag DoubleExposureOrdering;
    /** DVHData, (3004,0058), DS, 2-2n,  */
    extern const tag DVHData;
    /** DVHDoseScaling, (3004,0052), DS, 1,  */
    extern const tag DVHDoseScaling;
    /** DVHMaximumDose, (3004,0072), DS, 1,  */
    extern const tag DVHMaximumDose;
    /** DVHMeanDose, (3004,0074), DS, 1,  */
    extern const tag DVHMeanDose;
    /** DVHMinimumDose, (3004,0070), DS, 1,  */
    extern const tag DVHMinimumDose;
    /** DVHNormalizationDoseValue, (3004,0042), DS, 1,  */
    extern const tag DVHNormalizationDoseValue;
    /** DVHNormalizationPoint, (3004,0040), DS, 3,  */
    extern const tag DVHNormalizationPoint;
    /** DVHNumberOfBins, (3004,0056), IS, 1,  */
    extern const tag DVHNumberOfBins;
    /** DVHReferencedROISequence, (3004,0060), SQ, 1,  */
    extern const tag DVHReferencedROISequence;
    /** DVHROIContributionType, (3004,0062), CS, 1,  */
    extern const tag DVHROIContributionType;
    /** DVHSequence, (3004,0050), SQ, 1,  */
    extern const tag DVHSequence;
    /** DVHType, (3004,0001), CS, 1,  */
    extern const tag DVHType;
    /** DVHVolumeUnits, (3004,0054), CS, 1,  */
    extern const tag DVHVolumeUnits;
    /** DynamicRange, (0018,5030), DS, 1, RET */
    extern const tag DynamicRange;
    /** EchoNumbers, (0018,0086), IS, 1-n,  */
    extern const tag EchoNumbers;
    /** EchoPlanarPulseSequence, (0018,9018), CS, 1,  */
    extern const tag EchoPlanarPulseSequence;
    /** EchoPulseSequence, (0018,9008), CS, 1,  */
    extern const tag EchoPulseSequence;
    /** EchoTime, (0018,0081), DS, 1,  */
    extern const tag EchoTime;
    /** EchoTrainLength, (0018,0091), IS, 1,  */
    extern const tag EchoTrainLength;
    /** EdgePointIndexList, (0066,0024), OW, 1,  */
    extern const tag EdgePointIndexList;
    /** EffectiveDateTime, (0068,6226), DT, 1,  */
    extern const tag EffectiveDateTime;
    /** EffectiveDuration, (0018,0072), DS, 1,  */
    extern const tag EffectiveDuration;
    /** EffectiveEchoTime, (0018,9082), FD, 1,  */
    extern const tag EffectiveEchoTime;
    /** EffectiveRefractiveIndex, (0052,0004), FD, 1,  */
    extern const tag EffectiveRefractiveIndex;
    /** ElementDimensionA, (0014,4014), DS, 1,  */
    extern const tag ElementDimensionA;
    /** ElementDimensionB, (0014,4015), DS, 1,  */
    extern const tag ElementDimensionB;
    /** ElementPitch, (0014,4016), DS, 1,  */
    extern const tag ElementPitch;
    /** ElementShape, (0014,4013), CS, 1,  */
    extern const tag ElementShape;
    /** EmmetropicMagnification, (0022,000A), FL, 1,  */
    extern const tag EmmetropicMagnification;
    /** EmptyImageBoxCIELabValue, (0072,0421), US, 3,  */
    extern const tag EmptyImageBoxCIELabValue;
    /** EmptyImageDensity, (2010,0110), CS, 1,  */
    extern const tag EmptyImageDensity;
    /** EncapsulatedDocument, (0042,0011), OB, 1,  */
    extern const tag EncapsulatedDocument;
    /** EncryptedAttributesSequence, (0400,0500), SQ, 1,  */
    extern const tag EncryptedAttributesSequence;
    /** EncryptedContent, (0400,0520), OB, 1,  */
    extern const tag EncryptedContent;
    /** EncryptedContentTransferSyntaxUID, (0400,0510), UI, 1,  */
    extern const tag EncryptedContentTransferSyntaxUID;
    /** EndAcquisitionDateTime, (0018,9517), DT, 1,  */
    extern const tag EndAcquisitionDateTime;
    /** EndCumulativeMetersetWeight, (300C,0009), DS, 1,  */
    extern const tag EndCumulativeMetersetWeight;
    /** EndingRespiratoryAmplitude, (0020,9248), FL, 1,  */
    extern const tag EndingRespiratoryAmplitude;
    /** EndingRespiratoryPhase, (0020,9249), CS, 1,  */
    extern const tag EndingRespiratoryPhase;
    /** EndMeterset, (3008,007A), DS, 1,  */
    extern const tag EndMeterset;
    /** EnergyWeightingFactor, (0018,9353), FL, 1,  */
    extern const tag EnergyWeightingFactor;
    /** EnergyWindowCenterline, (0018,0032), DS, 1, RET */
    extern const tag EnergyWindowCenterline;
    /** EnergyWindowInformationSequence, (0054,0012), SQ, 1,  */
    extern const tag EnergyWindowInformationSequence;
    /** EnergyWindowLowerLimit, (0054,0014), DS, 1,  */
    extern const tag EnergyWindowLowerLimit;
    /** EnergyWindowName, (0054,0018), SH, 1,  */
    extern const tag EnergyWindowName;
    /** EnergyWindowNumber, (0054,0308), US, 1,  */
    extern const tag EnergyWindowNumber;
    /** EnergyWindowRangeSequence, (0054,0013), SQ, 1,  */
    extern const tag EnergyWindowRangeSequence;
    /** EnergyWindowTotalWidth, (0018,0033), DS, 1-n, RET */
    extern const tag EnergyWindowTotalWidth;
    /** EnergyWindowUpperLimit, (0054,0015), DS, 1,  */
    extern const tag EnergyWindowUpperLimit;
    /** EnergyWindowVector, (0054,0010), US, 1-n,  */
    extern const tag EnergyWindowVector;
    /** EnhancedPaletteColorLookupTableSequence, (0028,140B), SQ, 1,  */
    extern const tag EnhancedPaletteColorLookupTableSequence;
    /** EntranceDose, (0040,0302), US, 1,  */
    extern const tag EntranceDose;
    /** EntranceDoseInmGy, (0040,8302), DS, 1,  */
    extern const tag EntranceDoseInmGy;
    /** EnvironmentalConditions, (0014,1040), ST, 1,  */
    extern const tag EnvironmentalConditions;
    /** EquipmentCoordinateSystemIdentification, (0028,9537), CS, 1,  */
    extern const tag EquipmentCoordinateSystemIdentification;
    /** EquivalentCDADocumentSequence, (0040,A090), SQ, 1, RET */
    extern const tag EquivalentCDADocumentSequence;
    /** EscapeTriplet, (1000,XXX0), US, 3, RET */
    extern const range_tag EscapeTriplet;
    /** EstimatedDoseSaving, (0018,9324), FD, 1,  */
    extern const tag EstimatedDoseSaving;
    /** EstimatedRadiographicMagnificationFactor, (0018,1114), DS, 1,  */
    extern const tag EstimatedRadiographicMagnificationFactor;
    /** EthnicGroup, (0010,2160), SH, 1,  */
    extern const tag EthnicGroup;
    /** EvaluationAttempt, (0014,2008), IS, 1,  */
    extern const tag EvaluationAttempt;
    /** EvaluatorName, (0014,2006), PN, 1,  */
    extern const tag EvaluatorName;
    /** EvaluatorNumber, (0014,2004), IS, 1,  */
    extern const tag EvaluatorNumber;
    /** EvaluatorSequence, (0014,2002), SQ, 1,  */
    extern const tag EvaluatorSequence;
    /** EventCodeSequence, (0008,2135), SQ, 1,  */
    extern const tag EventCodeSequence;
    /** EventElapsedTimes, (0008,2130), DS, 1-n,  */
    extern const tag EventElapsedTimes;
    /** EventTimeOffset, (0008,2134), FD, 1,  */
    extern const tag EventTimeOffset;
    /** EventTimerNames, (0008,2132), LO, 1-n,  */
    extern const tag EventTimerNames;
    /** EventTimerSequence, (0008,2133), SQ, 1,  */
    extern const tag EventTimerSequence;
    /** ExaminedBodyThickness, (0010,9431), FL, 1,  */
    extern const tag ExaminedBodyThickness;
    /** ExcessiveFalseNegatives, (0024,0052), CS, 1,  */
    extern const tag ExcessiveFalseNegatives;
    /** ExcessiveFalseNegativesDataFlag, (0024,0051), CS, 1,  */
    extern const tag ExcessiveFalseNegativesDataFlag;
    /** ExcessiveFalsePositives, (0024,0062), CS, 1,  */
    extern const tag ExcessiveFalsePositives;
    /** ExcessiveFalsePositivesDataFlag, (0024,0061), CS, 1,  */
    extern const tag ExcessiveFalsePositivesDataFlag;
    /** ExcessiveFixationLosses, (0024,0040), CS, 1,  */
    extern const tag ExcessiveFixationLosses;
    /** ExcessiveFixationLossesDataFlag, (0024,0039), CS, 1,  */
    extern const tag ExcessiveFixationLossesDataFlag;
    /** ExcitationFrequency, (0014,4024), DS, 1,  */
    extern const tag ExcitationFrequency;
    /** ExcludedIntervalsSequence, (0018,9803), SQ, 1,  */
    extern const tag ExcludedIntervalsSequence;
    /** ExclusionDuration, (0018,9805), FD, 1,  */
    extern const tag ExclusionDuration;
    /** ExclusionStartDatetime, (0018,9804), DT, 1,  */
    extern const tag ExclusionStartDatetime;
    /** ExclusiveComponentType, (0076,0036), CS, 1,  */
    extern const tag ExclusiveComponentType;
    /** ExecutionStatus, (2100,0020), CS, 1,  */
    extern const tag ExecutionStatus;
    /** ExecutionStatusInfo, (2100,0030), CS, 1,  */
    extern const tag ExecutionStatusInfo;
    /** ExpectedCompletionDateTime, (0040,4011), DT, 1,  */
    extern const tag ExpectedCompletionDateTime;
    /** ExpiryDate, (0014,1020), DA, 1,  */
    extern const tag ExpiryDate;
    /** ExposedArea, (0040,0303), US, 1-2,  */
    extern const tag ExposedArea;
    /** Exposure, (0018,1152), IS, 1,  */
    extern const tag Exposure;
    /** ExposureControlMode, (0018,7060), CS, 1,  */
    extern const tag ExposureControlMode;
    /** ExposureControlModeDescription, (0018,7062), LT, 1,  */
    extern const tag ExposureControlModeDescription;
    /** ExposureControlSensingRegionLeftVerticalEdge, (0018,9436), SS, 1,  */
    extern const tag ExposureControlSensingRegionLeftVerticalEdge;
    /** ExposureControlSensingRegionLowerHorizontalEdge, (0018,9439), SS, 1,  */
    extern const tag ExposureControlSensingRegionLowerHorizontalEdge;
    /** ExposureControlSensingRegionRightVerticalEdge, (0018,9437), SS, 1,  */
    extern const tag ExposureControlSensingRegionRightVerticalEdge;
    /** ExposureControlSensingRegionShape, (0018,9435), CS, 1,  */
    extern const tag ExposureControlSensingRegionShape;
    /** ExposureControlSensingRegionsSequence, (0018,9434), SQ, 1,  */
    extern const tag ExposureControlSensingRegionsSequence;
    /** ExposureControlSensingRegionUpperHorizontalEdge, (0018,9438), SS, 1,  */
    extern const tag ExposureControlSensingRegionUpperHorizontalEdge;
    /** ExposureDoseSequence, (0040,030E), SQ, 1,  */
    extern const tag ExposureDoseSequence;
    /** ExposureIndex, (0018,1411), DS, 1,  */
    extern const tag ExposureIndex;
    /** ExposureInmAs, (0018,9332), FD, 1,  */
    extern const tag ExposureInmAs;
    /** ExposureInuAs, (0018,1153), IS, 1,  */
    extern const tag ExposureInuAs;
    /** ExposureModulationType, (0018,9323), CS, 1,  */
    extern const tag ExposureModulationType;
    /** ExposureSequence, (3002,0030), SQ, 1,  */
    extern const tag ExposureSequence;
    /** ExposuresOnDetectorSinceLastCalibration, (0018,7010), IS, 1,  */
    extern const tag ExposuresOnDetectorSinceLastCalibration;
    /** ExposuresOnDetectorSinceManufactured, (0018,7011), IS, 1,  */
    extern const tag ExposuresOnDetectorSinceManufactured;
    /** ExposuresOnPlate, (0018,1404), US, 1,  */
    extern const tag ExposuresOnPlate;
    /** ExposureStatus, (0018,7064), CS, 1,  */
    extern const tag ExposureStatus;
    /** ExposureTime, (0018,1150), IS, 1,  */
    extern const tag ExposureTime;
    /** ExposureTimeInms, (0018,9328), FD, 1,  */
    extern const tag ExposureTimeInms;
    /** ExposureTimeInuS, (0018,8150), DS, 1,  */
    extern const tag ExposureTimeInuS;
    /** ExtendedDepthOfField, (0048,0012), CS, 1,  */
    extern const tag ExtendedDepthOfField;
    /** FacetSequence, (0066,0034), SQ, 1,  */
    extern const tag FacetSequence;
    /** FailedAttributesSequence, (0074,1048), SQ, 1,  */
    extern const tag FailedAttributesSequence;
    /** FailedSOPInstanceUIDList, (0008,0058), UI, 1-n,  */
    extern const tag FailedSOPInstanceUIDList;
    /** FailedSOPSequence, (0008,1198), SQ, 1,  */
    extern const tag FailedSOPSequence;
    /** FailureAttributes, (2200,000E), AT, 1-n,  */
    extern const tag FailureAttributes;
    /** FailureReason, (0008,1197), US, 1,  */
    extern const tag FailureReason;
    /** FalseNegativesEstimate, (0024,0046), FL, 1,  */
    extern const tag FalseNegativesEstimate;
    /** FalseNegativesEstimateFlag, (0024,0045), CS, 1,  */
    extern const tag FalseNegativesEstimateFlag;
    /** FalseNegativesQuantity, (0024,0050), US, 1,  */
    extern const tag FalseNegativesQuantity;
    /** FalsePositivesEstimate, (0024,0054), FL, 1,  */
    extern const tag FalsePositivesEstimate;
    /** FalsePositivesEstimateFlag, (0024,0053), CS, 1,  */
    extern const tag FalsePositivesEstimateFlag;
    /** FalsePositivesQuantity, (0024,0060), US, 1,  */
    extern const tag FalsePositivesQuantity;
    /** FiducialDescription, (0070,030F), ST, 1,  */
    extern const tag FiducialDescription;
    /** FiducialIdentifier, (0070,0310), SH, 1,  */
    extern const tag FiducialIdentifier;
    /** FiducialIdentifierCodeSequence, (0070,0311), SQ, 1,  */
    extern const tag FiducialIdentifierCodeSequence;
    /** FiducialSequence, (0070,031E), SQ, 1,  */
    extern const tag FiducialSequence;
    /** FiducialSetSequence, (0070,031C), SQ, 1,  */
    extern const tag FiducialSetSequence;
    /** FiducialUID, (0070,031A), UI, 1,  */
    extern const tag FiducialUID;
    /** FieldOfViewDescription, (0018,9433), LO, 1,  */
    extern const tag FieldOfViewDescription;
    /** FieldOfViewDimensions, (0018,1149), IS, 1-2,  */
    extern const tag FieldOfViewDimensions;
    /** FieldOfViewDimensionsInFloat, (0018,9461), FL, 1-2,  */
    extern const tag FieldOfViewDimensionsInFloat;
    /** FieldOfViewHorizontalFlip, (0018,7034), CS, 1,  */
    extern const tag FieldOfViewHorizontalFlip;
    /** FieldOfViewOrigin, (0018,7030), DS, 2,  */
    extern const tag FieldOfViewOrigin;
    /** FieldOfViewRotation, (0018,7032), DS, 1,  */
    extern const tag FieldOfViewRotation;
    /** FieldOfViewSequence, (0018,9432), SQ, 1,  */
    extern const tag FieldOfViewSequence;
    /** FieldOfViewShape, (0018,1147), CS, 1,  */
    extern const tag FieldOfViewShape;
    /** FileMetaInformationGroupLength, (0002,0000), UL, 1,  */
    extern const tag FileMetaInformationGroupLength;
    /** FileMetaInformationVersion, (0002,0001), OB, 1,  */
    extern const tag FileMetaInformationVersion;
    /** FileSetConsistencyFlag, (0004,1212), US, 1,  */
    extern const tag FileSetConsistencyFlag;
    /** FileSetDescriptorFileID, (0004,1141), CS, 1-8,  */
    extern const tag FileSetDescriptorFileID;
    /** FileSetID, (0004,1130), CS, 1,  */
    extern const tag FileSetID;
    /** FillerOrderNumberImagingServiceRequest, (0040,2017), LO, 1,  */
    extern const tag FillerOrderNumberImagingServiceRequest;
    /** FillerOrderNumberImagingServiceRequestRetired, (0040,2007), SH, 1, RET */
    extern const tag FillerOrderNumberImagingServiceRequestRetired;
    /** FillerOrderNumberProcedure, (0040,1007), SH, 1, RET */
    extern const tag FillerOrderNumberProcedure;
    /** FillMode, (0070,0257), CS, 1,  */
    extern const tag FillMode;
    /** FillPattern, (0070,0256), OB, 1,  */
    extern const tag FillPattern;
    /** FillStyleSequence, (0070,0233), SQ, 1,  */
    extern const tag FillStyleSequence;
    /** FilmBoxContentSequence, (2130,0030), SQ, 1, RET */
    extern const tag FilmBoxContentSequence;
    /** FilmConsumptionSequence, (0040,0321), SQ, 1,  */
    extern const tag FilmConsumptionSequence;
    /** FilmDestination, (2000,0040), CS, 1,  */
    extern const tag FilmDestination;
    /** FilmOrientation, (2010,0040), CS, 1,  */
    extern const tag FilmOrientation;
    /** FilmSessionLabel, (2000,0050), LO, 1,  */
    extern const tag FilmSessionLabel;
    /** FilmSizeID, (2010,0050), CS, 1,  */
    extern const tag FilmSizeID;
    /** FilterBeamPathLengthMaximum, (0018,7058), FL, 1-n,  */
    extern const tag FilterBeamPathLengthMaximum;
    /** FilterBeamPathLengthMinimum, (0018,7056), FL, 1-n,  */
    extern const tag FilterBeamPathLengthMinimum;
    /** FilterByAttributePresence, (0072,0404), CS, 1,  */
    extern const tag FilterByAttributePresence;
    /** FilterByCategory, (0072,0402), CS, 1,  */
    extern const tag FilterByCategory;
    /** FilterByOperator, (0072,0406), CS, 1,  */
    extern const tag FilterByOperator;
    /** FilterHighFrequency, (003A,0221), DS, 1,  */
    extern const tag FilterHighFrequency;
    /** FilterLowFrequency, (003A,0220), DS, 1,  */
    extern const tag FilterLowFrequency;
    /** FilterMaterial, (0018,7050), CS, 1-n,  */
    extern const tag FilterMaterial;
    /** FilterMaterialUsedInGainCalibration, (0014,3074), LO, 1,  */
    extern const tag FilterMaterialUsedInGainCalibration;
    /** FilterOperationsSequence, (0072,0400), SQ, 1,  */
    extern const tag FilterOperationsSequence;
    /** FilterThicknessMaximum, (0018,7054), DS, 1-n,  */
    extern const tag FilterThicknessMaximum;
    /** FilterThicknessMinimum, (0018,7052), DS, 1-n,  */
    extern const tag FilterThicknessMinimum;
    /** FilterThicknessUsedInGainCalibration, (0014,3075), DS, 1,  */
    extern const tag FilterThicknessUsedInGainCalibration;
    /** FilterType, (0018,1160), SH, 1,  */
    extern const tag FilterType;
    /** FinalCumulativeMetersetWeight, (300A,010E), DS, 1,  */
    extern const tag FinalCumulativeMetersetWeight;
    /** FinalCumulativeTimeWeight, (300A,02C8), DS, 1,  */
    extern const tag FinalCumulativeTimeWeight;
    /** FindingsFlagTrial, (0040,A007), CS, 1, RET */
    extern const tag FindingsFlagTrial;
    /** FindingsGroupRecordingDateTrial, (0040,A023), DA, 1, RET */
    extern const tag FindingsGroupRecordingDateTrial;
    /** FindingsGroupRecordingTimeTrial, (0040,A024), TM, 1, RET */
    extern const tag FindingsGroupRecordingTimeTrial;
    /** FindingsGroupUIDTrial, (0040,A021), UI, 1, RET */
    extern const tag FindingsGroupUIDTrial;
    /** FindingsSequenceTrial, (0040,A020), SQ, 1, RET */
    extern const tag FindingsSequenceTrial;
    /** FindingsSourceCategoryCodeSequenceTrial, (0040,A026), SQ, 1, RET */
    extern const tag FindingsSourceCategoryCodeSequenceTrial;
    /** FiniteVolume, (0066,000E), CS, 1,  */
    extern const tag FiniteVolume;
    /** FirstALineLocation, (0052,0034), FD, 1,  */
    extern const tag FirstALineLocation;
    /** FirstOrderPhaseCorrection, (0018,9198), CS, 1,  */
    extern const tag FirstOrderPhaseCorrection;
    /** FirstOrderPhaseCorrectionAngle, (5600,0010), OF, 1,  */
    extern const tag FirstOrderPhaseCorrectionAngle;
    /** FirstTreatmentDate, (3008,0054), DA, 1,  */
    extern const tag FirstTreatmentDate;
    /** FixationCheckedQuantity, (0024,0035), US, 1,  */
    extern const tag FixationCheckedQuantity;
    /** FixationDeviceDescription, (300A,0196), ST, 1,  */
    extern const tag FixationDeviceDescription;
    /** FixationDeviceLabel, (300A,0194), SH, 1,  */
    extern const tag FixationDeviceLabel;
    /** FixationDevicePitchAngle, (300A,0199), FL, 1,  */
    extern const tag FixationDevicePitchAngle;
    /** FixationDevicePosition, (300A,0198), SH, 1,  */
    extern const tag FixationDevicePosition;
    /** FixationDeviceRollAngle, (300A,019A), FL, 1,  */
    extern const tag FixationDeviceRollAngle;
    /** FixationDeviceSequence, (300A,0190), SQ, 1,  */
    extern const tag FixationDeviceSequence;
    /** FixationDeviceType, (300A,0192), CS, 1,  */
    extern const tag FixationDeviceType;
    /** FixationLightAzimuthalAngle, (300A,0356), FL, 1,  */
    extern const tag FixationLightAzimuthalAngle;
    /** FixationLightPolarAngle, (300A,0358), FL, 1,  */
    extern const tag FixationLightPolarAngle;
    /** FixationMethodCodeSequence, (0068,63AC), SQ, 1,  */
    extern const tag FixationMethodCodeSequence;
    /** FixationMonitoringCodeSequence, (0024,0033), SQ, 1,  */
    extern const tag FixationMonitoringCodeSequence;
    /** FixationSequence, (0024,0032), SQ, 1,  */
    extern const tag FixationSequence;
    /** FlatKeratometricAxisSequence, (0046,0080), SQ, 1,  */
    extern const tag FlatKeratometricAxisSequence;
    /** FlipAngle, (0018,1314), DS, 1,  */
    extern const tag FlipAngle;
    /** FlowCompensation, (0018,9010), CS, 1,  */
    extern const tag FlowCompensation;
    /** FlowCompensationDirection, (0018,9183), CS, 1,  */
    extern const tag FlowCompensationDirection;
    /** FluenceDataScale, (3002,0042), DS, 1,  */
    extern const tag FluenceDataScale;
    /** FluenceDataSource, (3002,0041), CS, 1,  */
    extern const tag FluenceDataSource;
    /** FluenceMapSequence, (3002,0040), SQ, 1,  */
    extern const tag FluenceMapSequence;
    /** FluenceMode, (3002,0051), CS, 1,  */
    extern const tag FluenceMode;
    /** FluenceModeID, (3002,0052), SH, 1,  */
    extern const tag FluenceModeID;
    /** FluoroscopyFlag, (0018,9334), CS, 1,  */
    extern const tag FluoroscopyFlag;
    /** FocalDistance, (0018,1182), IS, 1-2,  */
    extern const tag FocalDistance;
    /** FocalSpots, (0018,1190), DS, 1-n,  */
    extern const tag FocalSpots;
    /** FocusDepth, (0018,5012), DS, 1,  */
    extern const tag FocusDepth;
    /** FocusMethod, (0048,0011), CS, 1,  */
    extern const tag FocusMethod;
    /** FontName, (0070,0227), LO, 1,  */
    extern const tag FontName;
    /** FontNameType, (0070,0228), CS, 1,  */
    extern const tag FontNameType;
    /** FovealPointNormativeDataFlag, (0024,0117), CS, 1,  */
    extern const tag FovealPointNormativeDataFlag;
    /** FovealPointProbabilityValue, (0024,0118), FL, 1,  */
    extern const tag FovealPointProbabilityValue;
    /** FovealSensitivity, (0024,0087), FL, 1,  */
    extern const tag FovealSensitivity;
    /** FovealSensitivityMeasured, (0024,0086), CS, 1,  */
    extern const tag FovealSensitivityMeasured;
    /** FractionalChannelDisplayScale, (003A,0247), FL, 1,  */
    extern const tag FractionalChannelDisplayScale;
    /** FractionGroupDescription, (300A,0072), LO, 1,  */
    extern const tag FractionGroupDescription;
    /** FractionGroupNumber, (300A,0071), IS, 1,  */
    extern const tag FractionGroupNumber;
    /** FractionGroupSequence, (300A,0070), SQ, 1,  */
    extern const tag FractionGroupSequence;
    /** FractionGroupSummarySequence, (3008,0220), SQ, 1,  */
    extern const tag FractionGroupSummarySequence;
    /** FractionGroupType, (3008,0224), CS, 1,  */
    extern const tag FractionGroupType;
    /** FractionNumber, (3002,0029), IS, 1,  */
    extern const tag FractionNumber;
    /** FractionPattern, (300A,007B), LT, 1,  */
    extern const tag FractionPattern;
    /** FractionStatusSummarySequence, (3008,0240), SQ, 1,  */
    extern const tag FractionStatusSummarySequence;
    /** FrameAcquisitionDateTime, (0018,9074), DT, 1,  */
    extern const tag FrameAcquisitionDateTime;
    /** FrameAcquisitionDuration, (0018,9220), FD, 1,  */
    extern const tag FrameAcquisitionDuration;
    /** FrameAcquisitionNumber, (0020,9156), US, 1,  */
    extern const tag FrameAcquisitionNumber;
    /** FrameAcquisitionSequence, (0018,9417), SQ, 1,  */
    extern const tag FrameAcquisitionSequence;
    /** FrameAnatomySequence, (0020,9071), SQ, 1,  */
    extern const tag FrameAnatomySequence;
    /** FrameComments, (0020,9158), LT, 1,  */
    extern const tag FrameComments;
    /** FrameContentSequence, (0020,9111), SQ, 1,  */
    extern const tag FrameContentSequence;
    /** FrameDelay, (0018,1066), DS, 1,  */
    extern const tag FrameDelay;
    /** FrameDetectorParametersSequence, (0018,9451), SQ, 1,  */
    extern const tag FrameDetectorParametersSequence;
    /** FrameDimensionPointer, (0028,000A), AT, 1-n,  */
    extern const tag FrameDimensionPointer;
    /** FrameDisplaySequence, (0008,9458), SQ, 1,  */
    extern const tag FrameDisplaySequence;
    /** FrameDisplayShutterSequence, (0018,9472), SQ, 1,  */
    extern const tag FrameDisplayShutterSequence;
    /** FrameExtractionSequence, (0008,1164), SQ, 1,  */
    extern const tag FrameExtractionSequence;
    /** FrameIncrementPointer, (0028,0009), AT, 1-n,  */
    extern const tag FrameIncrementPointer;
    /** FrameLabel, (0020,9453), LO, 1,  */
    extern const tag FrameLabel;
    /** FrameLabelVector, (0018,2002), SH, 1-n,  */
    extern const tag FrameLabelVector;
    /** FrameLaterality, (0020,9072), CS, 1,  */
    extern const tag FrameLaterality;
    /** FrameNumbersOfInterest, (0028,6020), US, 1-n,  */
    extern const tag FrameNumbersOfInterest;
    /** FrameOfInterestDescription, (0028,6022), LO, 1-n,  */
    extern const tag FrameOfInterestDescription;
    /** FrameOfInterestType, (0028,6023), CS, 1-n,  */
    extern const tag FrameOfInterestType;
    /** FrameOfReferenceRelationshipSequence, (3006,00C0), SQ, 1,  */
    extern const tag FrameOfReferenceRelationshipSequence;
    /** FrameOfReferenceTransformationComment, (3006,00C8), LO, 1,  */
    extern const tag FrameOfReferenceTransformationComment;
    /** FrameOfReferenceTransformationMatrix, (3006,00C6), DS, 16,  */
    extern const tag FrameOfReferenceTransformationMatrix;
    /** FrameOfReferenceTransformationMatrixType, (0070,030C), CS, 1,  */
    extern const tag FrameOfReferenceTransformationMatrixType;
    /** FrameOfReferenceTransformationType, (3006,00C4), CS, 1,  */
    extern const tag FrameOfReferenceTransformationType;
    /** FrameOfReferenceUID, (0020,0052), UI, 1,  */
    extern const tag FrameOfReferenceUID;
    /** FramePixelDataPropertiesSequence, (0028,9443), SQ, 1,  */
    extern const tag FramePixelDataPropertiesSequence;
    /** FramePixelShiftSequence, (0028,9415), SQ, 1,  */
    extern const tag FramePixelShiftSequence;
    /** FramePrimaryAngleVector, (0018,2003), DS, 1-n,  */
    extern const tag FramePrimaryAngleVector;
    /** FrameReferenceDateTime, (0018,9151), DT, 1,  */
    extern const tag FrameReferenceDateTime;
    /** FrameReferenceTime, (0054,1300), DS, 1,  */
    extern const tag FrameReferenceTime;
    /** FrameSecondaryAngleVector, (0018,2004), DS, 1-n,  */
    extern const tag FrameSecondaryAngleVector;
    /** FrameTime, (0018,1063), DS, 1,  */
    extern const tag FrameTime;
    /** FrameTimeVector, (0018,1065), DS, 1-n,  */
    extern const tag FrameTimeVector;
    /** FrameType, (0008,9007), CS, 4,  */
    extern const tag FrameType;
    /** FrameVOILUTSequence, (0028,9132), SQ, 1,  */
    extern const tag FrameVOILUTSequence;
    /** FrequencyCorrection, (0018,9101), CS, 1,  */
    extern const tag FrequencyCorrection;
    /** FunctionalGroupPointer, (0020,9167), AT, 1,  */
    extern const tag FunctionalGroupPointer;
    /** FunctionalGroupPrivateCreator, (0020,9238), LO, 1,  */
    extern const tag FunctionalGroupPrivateCreator;
    /** GainCorrectionReferenceSequence, (0014,3060), SQ, 1,  */
    extern const tag GainCorrectionReferenceSequence;
    /** GantryAngle, (300A,011E), DS, 1,  */
    extern const tag GantryAngle;
    /** GantryAngleTolerance, (300A,0044), DS, 1,  */
    extern const tag GantryAngleTolerance;
    /** GantryDetectorSlew, (0018,1121), DS, 1,  */
    extern const tag GantryDetectorSlew;
    /** GantryDetectorTilt, (0018,1120), DS, 1,  */
    extern const tag GantryDetectorTilt;
    /** GantryID, (0018,1008), LO, 1,  */
    extern const tag GantryID;
    /** GantryMotionCorrected, (0018,9762), CS, 1,  */
    extern const tag GantryMotionCorrected;
    /** GantryPitchAngle, (300A,014A), FL, 1,  */
    extern const tag GantryPitchAngle;
    /** GantryPitchAngleTolerance, (300A,014E), FL, 1,  */
    extern const tag GantryPitchAngleTolerance;
    /** GantryPitchRotationDirection, (300A,014C), CS, 1,  */
    extern const tag GantryPitchRotationDirection;
    /** GantryRotationDirection, (300A,011F), CS, 1,  */
    extern const tag GantryRotationDirection;
    /** GantryType, (4010,1008), CS, 1,  */
    extern const tag GantryType;
    /** GapLength, (0070,0261), FL, 1,  */
    extern const tag GapLength;
    /** GatedInformationSequence, (0054,0062), SQ, 1,  */
    extern const tag GatedInformationSequence;
    /** GateSettingsSequence, (0014,4060), SQ, 1,  */
    extern const tag GateSettingsSequence;
    /** GateThreshold, (0014,4062), DS, 1,  */
    extern const tag GateThreshold;
    /** GeneralAccessoryDescription, (300A,0422), ST, 1,  */
    extern const tag GeneralAccessoryDescription;
    /** GeneralAccessoryID, (300A,0421), SH, 1,  */
    extern const tag GeneralAccessoryID;
    /** GeneralAccessoryNumber, (300A,0424), IS, 1,  */
    extern const tag GeneralAccessoryNumber;
    /** GeneralAccessorySequence, (300A,0420), SQ, 1,  */
    extern const tag GeneralAccessorySequence;
    /** GeneralAccessoryType, (300A,0423), CS, 1,  */
    extern const tag GeneralAccessoryType;
    /** GeneralizedDefectCorrectedSensitivityDeviationFlag, (0024,0102), CS, 1,  */
    extern const tag GeneralizedDefectCorrectedSensitivityDeviationFlag;
    /** GeneralizedDefectCorrectedSensitivityDeviationProbabilityValue, (0024,0104), FL, 1,  */
    extern const tag GeneralizedDefectCorrectedSensitivityDeviationProbabilityValue;
    /** GeneralizedDefectCorrectedSensitivityDeviationValue, (0024,0103), FL, 1,  */
    extern const tag GeneralizedDefectCorrectedSensitivityDeviationValue;
    /** GeneralizedDefectSensitivityDeviationAlgorithmSequence, (0024,0067), SQ, 1,  */
    extern const tag GeneralizedDefectSensitivityDeviationAlgorithmSequence;
    /** GeneralMachineVerificationSequence, (0074,1042), SQ, 1,  */
    extern const tag GeneralMachineVerificationSequence;
    /** GeneralPurposePerformedProcedureStepStatus, (0040,4002), CS, 1,  */
    extern const tag GeneralPurposePerformedProcedureStepStatus;
    /** GeneralPurposeScheduledProcedureStepPriority, (0040,4003), CS, 1,  */
    extern const tag GeneralPurposeScheduledProcedureStepPriority;
    /** GeneralPurposeScheduledProcedureStepStatus, (0040,4001), CS, 1,  */
    extern const tag GeneralPurposeScheduledProcedureStepStatus;
    /** GeneratorID, (0018,1005), LO, 1,  */
    extern const tag GeneratorID;
    /** GeneratorPower, (0018,1170), IS, 1,  */
    extern const tag GeneratorPower;
    /** GeometricalProperties, (0028,9444), CS, 1,  */
    extern const tag GeometricalProperties;
    /** GeometricMaximumDistortion, (0028,9445), FL, 1,  */
    extern const tag GeometricMaximumDistortion;
    /** GeometryOfKSpaceTraversal, (0018,9032), CS, 1,  */
    extern const tag GeometryOfKSpaceTraversal;
    /** GlobalDeviationFromNormal, (0024,0066), FL, 1,  */
    extern const tag GlobalDeviationFromNormal;
    /** GlobalDeviationProbability, (0024,0071), FL, 1,  */
    extern const tag GlobalDeviationProbability;
    /** GlobalDeviationProbabilityNormalsFlag, (0024,0059), CS, 1,  */
    extern const tag GlobalDeviationProbabilityNormalsFlag;
    /** GlobalDeviationProbabilitySequence, (0024,0083), SQ, 1,  */
    extern const tag GlobalDeviationProbabilitySequence;
    /** GradientEchoTrainLength, (0018,9241), US, 1,  */
    extern const tag GradientEchoTrainLength;
    /** GradientOutput, (0018,9182), FD, 1,  */
    extern const tag GradientOutput;
    /** GradientOutputType, (0018,9180), CS, 1,  */
    extern const tag GradientOutputType;
    /** GraphicAnnotationSequence, (0070,0001), SQ, 1,  */
    extern const tag GraphicAnnotationSequence;
    /** GraphicAnnotationUnits, (0070,0005), CS, 1,  */
    extern const tag GraphicAnnotationUnits;
    /** GraphicCoordinatesDataSequence, (0070,0318), SQ, 1,  */
    extern const tag GraphicCoordinatesDataSequence;
    /** GraphicData, (0070,0022), FL, 2-n,  */
    extern const tag GraphicData;
    /** GraphicDimensions, (0070,0020), US, 1,  */
    extern const tag GraphicDimensions;
    /** GraphicFilled, (0070,0024), CS, 1,  */
    extern const tag GraphicFilled;
    /** GraphicGroupDescription, (0070,0208), ST, 1,  */
    extern const tag GraphicGroupDescription;
    /** GraphicGroupID, (0070,0295), UL, 1,  */
    extern const tag GraphicGroupID;
    /** GraphicGroupLabel, (0070,0207), LO, 1,  */
    extern const tag GraphicGroupLabel;
    /** GraphicGroupSequence, (0070,0234), SQ, 1,  */
    extern const tag GraphicGroupSequence;
    /** GraphicLayer, (0070,0002), CS, 1,  */
    extern const tag GraphicLayer;
    /** GraphicLayerDescription, (0070,0068), LO, 1,  */
    extern const tag GraphicLayerDescription;
    /** GraphicLayerOrder, (0070,0062), IS, 1,  */
    extern const tag GraphicLayerOrder;
    /** GraphicLayerRecommendedDisplayCIELabValue, (0070,0401), US, 3,  */
    extern const tag GraphicLayerRecommendedDisplayCIELabValue;
    /** GraphicLayerRecommendedDisplayGrayscaleValue, (0070,0066), US, 1,  */
    extern const tag GraphicLayerRecommendedDisplayGrayscaleValue;
    /** GraphicLayerRecommendedDisplayRGBValue, (0070,0067), US, 3, RET */
    extern const tag GraphicLayerRecommendedDisplayRGBValue;
    /** GraphicLayerSequence, (0070,0060), SQ, 1,  */
    extern const tag GraphicLayerSequence;
    /** GraphicObjectSequence, (0070,0009), SQ, 1,  */
    extern const tag GraphicObjectSequence;
    /** GraphicType, (0070,0023), CS, 1,  */
    extern const tag GraphicType;
    /** GrayLookupTableData, (0028,1200), US or SSor OW, 1-n1, RET */
    extern const tag GrayLookupTableData;
    /** GrayLookupTableDescriptor, (0028,1100), US or SS, 3, RET */
    extern const tag GrayLookupTableDescriptor;
    /** GrayScale, (0028,1080), CS, 1, RET */
    extern const tag GrayScale;
    /** GreenPaletteColorLookupTableData, (0028,1202), OW, 1,  */
    extern const tag GreenPaletteColorLookupTableData;
    /** GreenPaletteColorLookupTableDescriptor, (0028,1102), US or SS, 3,  */
    extern const tag GreenPaletteColorLookupTableDescriptor;
    /** Grid, (0018,1166), CS, 1-n,  */
    extern const tag Grid;
    /** GridAbsorbingMaterial, (0018,7040), LT, 1,  */
    extern const tag GridAbsorbingMaterial;
    /** GridAspectRatio, (0018,7046), IS, 2,  */
    extern const tag GridAspectRatio;
    /** GridDimensions, (0064,0007), UL, 3,  */
    extern const tag GridDimensions;
    /** GridFocalDistance, (0018,704C), DS, 1,  */
    extern const tag GridFocalDistance;
    /** GridFrameOffsetVector, (3004,000C), DS, 2-n,  */
    extern const tag GridFrameOffsetVector;
    /** GridID, (0018,1006), LO, 1,  */
    extern const tag GridID;
    /** GridPeriod, (0018,7048), DS, 1,  */
    extern const tag GridPeriod;
    /** GridPitch, (0018,7044), DS, 1,  */
    extern const tag GridPitch;
    /** GridResolution, (0064,0008), FD, 3,  */
    extern const tag GridResolution;
    /** GridSpacingMaterial, (0018,7041), LT, 1,  */
    extern const tag GridSpacingMaterial;
    /** GridThickness, (0018,7042), DS, 1,  */
    extern const tag GridThickness;
    /** HalfValueLayer, (0040,0314), DS, 1,  */
    extern const tag HalfValueLayer;
    /** HangingProtocolCreationDateTime, (0072,000A), DT, 1,  */
    extern const tag HangingProtocolCreationDateTime;
    /** HangingProtocolCreator, (0072,0008), LO, 1,  */
    extern const tag HangingProtocolCreator;
    /** HangingProtocolDefinitionSequence, (0072,000C), SQ, 1,  */
    extern const tag HangingProtocolDefinitionSequence;
    /** HangingProtocolDescription, (0072,0004), LO, 1,  */
    extern const tag HangingProtocolDescription;
    /** HangingProtocolLevel, (0072,0006), CS, 1,  */
    extern const tag HangingProtocolLevel;
    /** HangingProtocolName, (0072,0002), SH, 1,  */
    extern const tag HangingProtocolName;
    /** HangingProtocolUserGroupName, (0072,0010), LO, 1,  */
    extern const tag HangingProtocolUserGroupName;
    /** HangingProtocolUserIdentificationCodeSequence, (0072,000E), SQ, 1,  */
    extern const tag HangingProtocolUserIdentificationCodeSequence;
    /** HardcopyCreationDeviceID, (0018,1011), LO, 1, RET */
    extern const tag HardcopyCreationDeviceID;
    /** HardcopyDeviceManufacturer, (0018,1017), LO, 1, RET */
    extern const tag HardcopyDeviceManufacturer;
    /** HardcopyDeviceManufacturerModelName, (0018,101B), LO, 1, RET */
    extern const tag HardcopyDeviceManufacturerModelName;
    /** HardcopyDeviceSoftwareVersion, (0018,101A), LO, 1-n, RET */
    extern const tag HardcopyDeviceSoftwareVersion;
    /** HeadFixationAngle, (300A,0148), FL, 1,  */
    extern const tag HeadFixationAngle;
    /** HeartRate, (0018,1088), IS, 1,  */
    extern const tag HeartRate;
    /** HighBit, (0028,0102), US, 1,  */
    extern const tag HighBit;
    /** HighDoseTechniqueType, (300A,00C7), CS, 1,  */
    extern const tag HighDoseTechniqueType;
    /** HighEnergyDetectors, (4010,0002), CS, 1,  */
    extern const tag HighEnergyDetectors;
    /** HighRRValue, (0018,1082), IS, 1,  */
    extern const tag HighRRValue;
    /** HistogramBinWidth, (0060,3008), US, 1,  */
    extern const tag HistogramBinWidth;
    /** HistogramData, (0060,3020), UL, 1-n,  */
    extern const tag HistogramData;
    /** HistogramExplanation, (0060,3010), LO, 1,  */
    extern const tag HistogramExplanation;
    /** HistogramFirstBinValue, (0060,3004), US or SS, 1,  */
    extern const tag HistogramFirstBinValue;
    /** HistogramLastBinValue, (0060,3006), US or SS, 1,  */
    extern const tag HistogramLastBinValue;
    /** HistogramNumberOfBins, (0060,3002), US, 1,  */
    extern const tag HistogramNumberOfBins;
    /** HistogramSequence, (0060,3000), SQ, 1,  */
    extern const tag HistogramSequence;
    /** HL7DocumentEffectiveTime, (0040,E004), DT, 1,  */
    extern const tag HL7DocumentEffectiveTime;
    /** HL7DocumentTypeCodeSequence, (0040,E006), SQ, 1,  */
    extern const tag HL7DocumentTypeCodeSequence;
    /** HL7InstanceIdentifier, (0040,E001), ST, 1,  */
    extern const tag HL7InstanceIdentifier;
    /** HL7StructuredDocumentReferenceSequence, (0040,A390), SQ, 1,  */
    extern const tag HL7StructuredDocumentReferenceSequence;
    /** HomeCommunityID, (0040,E031), UI, 1,  */
    extern const tag HomeCommunityID;
    /** HorizontalAlignment, (0070,0242), CS, 1,  */
    extern const tag HorizontalAlignment;
    /** HorizontalFieldOfView, (0022,000C), FL, 1,  */
    extern const tag HorizontalFieldOfView;
    /** HorizontalOffsetOfSensor, (0014,3024), DS, 1,  */
    extern const tag HorizontalOffsetOfSensor;
    /** HorizontalPrismBase, (0046,0032), CS, 1,  */
    extern const tag HorizontalPrismBase;
    /** HorizontalPrismPower, (0046,0030), FD, 1,  */
    extern const tag HorizontalPrismPower;
    /** HPGLContourPenNumber, (0068,6310), US, 1,  */
    extern const tag HPGLContourPenNumber;
    /** HPGLDocument, (0068,6300), OB, 1,  */
    extern const tag HPGLDocument;
    /** HPGLDocumentID, (0068,62D0), US, 1,  */
    extern const tag HPGLDocumentID;
    /** HPGLDocumentLabel, (0068,62D5), LO, 1,  */
    extern const tag HPGLDocumentLabel;
    /** HPGLDocumentScaling, (0068,62F2), FD, 1,  */
    extern const tag HPGLDocumentScaling;
    /** HPGLDocumentSequence, (0068,62C0), SQ, 1,  */
    extern const tag HPGLDocumentSequence;
    /** HPGLPenDescription, (0068,6345), ST, 1,  */
    extern const tag HPGLPenDescription;
    /** HPGLPenLabel, (0068,6340), LO, 1,  */
    extern const tag HPGLPenLabel;
    /** HPGLPenNumber, (0068,6330), US, 1,  */
    extern const tag HPGLPenNumber;
    /** HPGLPenSequence, (0068,6320), SQ, 1,  */
    extern const tag HPGLPenSequence;
    /** HuffmanTableSize, (1000,XXX2), US, 1, RET */
    extern const range_tag HuffmanTableSize;
    /** HuffmanTableTriplet, (1000,XXX3), US, 3, RET */
    extern const range_tag HuffmanTableTriplet;
    /** HumanPerformerCodeSequence, (0040,4009), SQ, 1,  */
    extern const tag HumanPerformerCodeSequence;
    /** HumanPerformerName, (0040,4037), PN, 1,  */
    extern const tag HumanPerformerName;
    /** HumanPerformerOrganization, (0040,4036), LO, 1,  */
    extern const tag HumanPerformerOrganization;
    /** ICCProfile, (0028,2000), OB, 1,  */
    extern const tag ICCProfile;
    /** IconImageSequence, (0088,0200), SQ, 1,  */
    extern const tag IconImageSequence;
    /** IdenticalDocumentsSequence, (0040,A525), SQ, 1,  */
    extern const tag IdenticalDocumentsSequence;
    /** IdentificationDescriptionTrial, (0040,A224), ST, 1, RET */
    extern const tag IdentificationDescriptionTrial;
    /** IdentifierCodeSequenceTrial, (0040,A070), SQ, 1, RET */
    extern const tag IdentifierCodeSequenceTrial;
    /** IdentifierTypeCode, (0040,0035), CS, 1,  */
    extern const tag IdentifierTypeCode;
    /** IdentifyingComments, (0008,4000), LT, 1, RET */
    extern const tag IdentifyingComments;
    /** Illumination, (2010,015E), US, 1,  */
    extern const tag Illumination;
    /** IlluminationBandwidth, (0022,0057), FL, 1,  */
    extern const tag IlluminationBandwidth;
    /** IlluminationColorCodeSequence, (0048,0108), SQ, 1,  */
    extern const tag IlluminationColorCodeSequence;
    /** IlluminationPower, (0022,0056), FL, 1,  */
    extern const tag IlluminationPower;
    /** IlluminationTypeCodeSequence, (0022,0016), SQ, 1,  */
    extern const tag IlluminationTypeCodeSequence;
    /** IlluminationWaveLength, (0022,0055), FL, 1,  */
    extern const tag IlluminationWaveLength;
    /** IlluminatorTypeCodeSequence, (0048,0100), SQ, 1,  */
    extern const tag IlluminatorTypeCodeSequence;
    /** ImageAndFluoroscopyAreaDoseProduct, (0018,115E), DS, 1,  */
    extern const tag ImageAndFluoroscopyAreaDoseProduct;
    /** ImageBoxContentSequence, (2130,0040), SQ, 1, RET */
    extern const tag ImageBoxContentSequence;
    /** ImageBoxesSequence, (0072,0300), SQ, 1,  */
    extern const tag ImageBoxesSequence;
    /** ImageBoxLargeScrollAmount, (0072,0318), US, 1,  */
    extern const tag ImageBoxLargeScrollAmount;
    /** ImageBoxLargeScrollType, (0072,0316), CS, 1,  */
    extern const tag ImageBoxLargeScrollType;
    /** ImageBoxLayoutType, (0072,0304), CS, 1,  */
    extern const tag ImageBoxLayoutType;
    /** ImageBoxNumber, (0072,0302), US, 1,  */
    extern const tag ImageBoxNumber;
    /** ImageBoxOverlapPriority, (0072,0320), US, 1,  */
    extern const tag ImageBoxOverlapPriority;
    /** ImageBoxPosition, (2020,0010), US, 1,  */
    extern const tag ImageBoxPosition;
    /** ImageBoxPresentationLUTFlag, (2000,006A), CS, 1, RET */
    extern const tag ImageBoxPresentationLUTFlag;
    /** ImageBoxScrollDirection, (0072,0310), CS, 1,  */
    extern const tag ImageBoxScrollDirection;
    /** ImageBoxSmallScrollAmount, (0072,0314), US, 1,  */
    extern const tag ImageBoxSmallScrollAmount;
    /** ImageBoxSmallScrollType, (0072,0312), CS, 1,  */
    extern const tag ImageBoxSmallScrollType;
    /** ImageBoxSynchronizationSequence, (0072,0430), SQ, 1,  */
    extern const tag ImageBoxSynchronizationSequence;
    /** ImageBoxTileHorizontalDimension, (0072,0306), US, 1,  */
    extern const tag ImageBoxTileHorizontalDimension;
    /** ImageBoxTileVerticalDimension, (0072,0308), US, 1,  */
    extern const tag ImageBoxTileVerticalDimension;
    /** ImageCenterPointCoordinatesSequence, (0040,071A), SQ, 1,  */
    extern const tag ImageCenterPointCoordinatesSequence;
    /** ImageComments, (0020,4000), LT, 1,  */
    extern const tag ImageComments;
    /** ImageDataLocation, (0028,08X8), AT, 1-n, RET */
    extern const range_tag ImageDataLocation;
    /** ImageDataTypeSequence, (0018,9807), SQ, 1,  */
    extern const tag ImageDataTypeSequence;
    /** ImageDimensions, (0028,0005), US, 1, RET */
    extern const tag ImageDimensions;
    /** ImageDisplayFormat, (2010,0010), ST, 1,  */
    extern const tag ImageDisplayFormat;
    /** ImagedNucleus, (0018,0085), SH, 1,  */
    extern const tag ImagedNucleus;
    /** ImagedVolumeDepth, (0048,0003), FL, 1,  */
    extern const tag ImagedVolumeDepth;
    /** ImagedVolumeHeight, (0048,0002), FL, 1,  */
    extern const tag ImagedVolumeHeight;
    /** ImagedVolumeWidth, (0048,0001), FL, 1,  */
    extern const tag ImagedVolumeWidth;
    /** ImageFilter, (0018,9320), SH, 1,  */
    extern const tag ImageFilter;
    /** ImageFormat, (0028,0040), CS, 1, RET */
    extern const tag ImageFormat;
    /** ImageFrameOrigin, (60XX,0051), US, 1,  */
    extern const range_tag ImageFrameOrigin;
    /** ImageGeometryType, (0020,0070), LO, 1, RET */
    extern const tag ImageGeometryType;
    /** ImageHorizontalFlip, (0070,0041), CS, 1,  */
    extern const tag ImageHorizontalFlip;
    /** ImageID, (0054,0400), SH, 1,  */
    extern const tag ImageID;
    /** ImageIndex, (0054,1330), US, 1,  */
    extern const tag ImageIndex;
    /** ImageLaterality, (0020,0062), CS, 1,  */
    extern const tag ImageLaterality;
    /** ImageLocation, (0028,0200), US, 1, RET */
    extern const tag ImageLocation;
    /** ImageOrientation, (0020,0035), DS, 6, RET */
    extern const tag ImageOrientation;
    /** ImageOrientationPatient, (0020,0037), DS, 6,  */
    extern const tag ImageOrientationPatient;
    /** ImageOrientationSlide, (0048,0102), DS, 6,  */
    extern const tag ImageOrientationSlide;
    /** ImageOrientationVolume, (0020,9302), FD, 6,  */
    extern const tag ImageOrientationVolume;
    /** ImageOverlayBoxContentSequence, (2130,0060), SQ, 1, RET */
    extern const tag ImageOverlayBoxContentSequence;
    /** ImageOverlayFlag, (2000,0067), CS, 1, RET */
    extern const tag ImageOverlayFlag;
    /** ImagePathFilterPassBand, (0022,0004), US, 2,  */
    extern const tag ImagePathFilterPassBand;
    /** ImagePathFilterPassThroughWavelength, (0022,0003), US, 1,  */
    extern const tag ImagePathFilterPassThroughWavelength;
    /** ImagePathFilterTypeStackCodeSequence, (0022,0018), SQ, 1,  */
    extern const tag ImagePathFilterTypeStackCodeSequence;
    /** ImagePlanePixelSpacing, (3002,0011), DS, 2,  */
    extern const tag ImagePlanePixelSpacing;
    /** ImagePosition, (0020,0030), DS, 3, RET */
    extern const tag ImagePosition;
    /** ImagePositionPatient, (0020,0032), DS, 3,  */
    extern const tag ImagePositionPatient;
    /** ImagePositionVolume, (0020,9301), FD, 3,  */
    extern const tag ImagePositionVolume;
    /** ImagePresentationComments, (0028,4000), LT, 1, RET */
    extern const tag ImagePresentationComments;
    /** ImageProcessingApplied, (0028,9446), CS, 1-n,  */
    extern const tag ImageProcessingApplied;
    /** ImageRotation, (0070,0042), US, 1,  */
    extern const tag ImageRotation;
    /** ImageRotationRetired, (0070,0040), IS, 1, RET */
    extern const tag ImageRotationRetired;
    /** ImagerPixelSpacing, (0018,1164), DS, 2,  */
    extern const tag ImagerPixelSpacing;
    /** ImageSetLabel, (0072,0040), LO, 1,  */
    extern const tag ImageSetLabel;
    /** ImageSetNumber, (0072,0032), US, 1,  */
    extern const tag ImageSetNumber;
    /** ImageSetSelectorCategory, (0072,0034), CS, 1,  */
    extern const tag ImageSetSelectorCategory;
    /** ImageSetSelectorSequence, (0072,0022), SQ, 1,  */
    extern const tag ImageSetSelectorSequence;
    /** ImageSetSelectorUsageFlag, (0072,0024), CS, 1,  */
    extern const tag ImageSetSelectorUsageFlag;
    /** ImageSetsSequence, (0072,0020), SQ, 1,  */
    extern const tag ImageSetsSequence;
    /** ImagesInAcquisition, (0020,1002), IS, 1,  */
    extern const tag ImagesInAcquisition;
    /** ImagesInSeries, (0020,1003), IS, 1, RET */
    extern const tag ImagesInSeries;
    /** ImagesInStudy, (0020,1005), IS, 1, RET */
    extern const tag ImagesInStudy;
    /** ImageToEquipmentMappingMatrix, (0028,9520), DS, 16,  */
    extern const tag ImageToEquipmentMappingMatrix;
    /** ImageTransformationMatrix, (0018,5210), DS, 6, RET */
    extern const tag ImageTransformationMatrix;
    /** ImageTranslationVector, (0018,5212), DS, 3, RET */
    extern const tag ImageTranslationVector;
    /** ImageTriggerDelay, (0018,1067), DS, 1,  */
    extern const tag ImageTriggerDelay;
    /** ImageType, (0008,0008), CS, 2-n,  */
    extern const tag ImageType;
    /** ImagingDeviceSpecificAcquisitionParameters, (300A,00CC), LO, 1-n,  */
    extern const tag ImagingDeviceSpecificAcquisitionParameters;
    /** ImagingFrequency, (0018,0084), DS, 1,  */
    extern const tag ImagingFrequency;
    /** ImagingServiceRequestComments, (0040,2400), LT, 1,  */
    extern const tag ImagingServiceRequestComments;
    /** ImplantAssemblyTemplateIssuer, (0076,0003), LO, 1,  */
    extern const tag ImplantAssemblyTemplateIssuer;
    /** ImplantAssemblyTemplateName, (0076,0001), LO, 1,  */
    extern const tag ImplantAssemblyTemplateName;
    /** ImplantAssemblyTemplateTargetAnatomySequence, (0076,0010), SQ, 1,  */
    extern const tag ImplantAssemblyTemplateTargetAnatomySequence;
    /** ImplantAssemblyTemplateType, (0076,000A), CS, 1,  */
    extern const tag ImplantAssemblyTemplateType;
    /** ImplantAssemblyTemplateVersion, (0076,0006), LO, 1,  */
    extern const tag ImplantAssemblyTemplateVersion;
    /** ImplantName, (0022,1095), LO, 1,  */
    extern const tag ImplantName;
    /** ImplantPartNumber, (0022,1097), LO, 1,  */
    extern const tag ImplantPartNumber;
    /** ImplantRegulatoryDisapprovalCodeSequence, (0068,62A0), SQ, 1,  */
    extern const tag ImplantRegulatoryDisapprovalCodeSequence;
    /** ImplantSize, (0068,6210), LO, 1,  */
    extern const tag ImplantSize;
    /** ImplantTargetAnatomySequence, (0068,6230), SQ, 1,  */
    extern const tag ImplantTargetAnatomySequence;
    /** ImplantTemplate3DModelSurfaceNumber, (0068,6350), US, 1-n,  */
    extern const tag ImplantTemplate3DModelSurfaceNumber;
    /** ImplantTemplateGroupDescription, (0078,0010), ST, 1,  */
    extern const tag ImplantTemplateGroupDescription;
    /** ImplantTemplateGroupIssuer, (0078,0020), LO, 1,  */
    extern const tag ImplantTemplateGroupIssuer;
    /** ImplantTemplateGroupMemberID, (0078,002E), US, 1,  */
    extern const tag ImplantTemplateGroupMemberID;
    /** ImplantTemplateGroupMemberMatching2DCoordinatesSequence, (0078,0070), SQ, 1,  */
    extern const tag ImplantTemplateGroupMemberMatching2DCoordinatesSequence;
    /** ImplantTemplateGroupMembersSequence, (0078,002A), SQ, 1,  */
    extern const tag ImplantTemplateGroupMembersSequence;
    /** ImplantTemplateGroupName, (0078,0001), LO, 1,  */
    extern const tag ImplantTemplateGroupName;
    /** ImplantTemplateGroupTargetAnatomySequence, (0078,0028), SQ, 1,  */
    extern const tag ImplantTemplateGroupTargetAnatomySequence;
    /** ImplantTemplateGroupVariationDimensionName, (0078,00B2), LO, 1,  */
    extern const tag ImplantTemplateGroupVariationDimensionName;
    /** ImplantTemplateGroupVariationDimensionRank, (0078,00B8), US, 1,  */
    extern const tag ImplantTemplateGroupVariationDimensionRank;
    /** ImplantTemplateGroupVariationDimensionRankSequence, (0078,00B4), SQ, 1,  */
    extern const tag ImplantTemplateGroupVariationDimensionRankSequence;
    /** ImplantTemplateGroupVariationDimensionSequence, (0078,00B0), SQ, 1,  */
    extern const tag ImplantTemplateGroupVariationDimensionSequence;
    /** ImplantTemplateGroupVersion, (0078,0024), LO, 1,  */
    extern const tag ImplantTemplateGroupVersion;
    /** ImplantTemplateVersion, (0068,6221), LO, 1,  */
    extern const tag ImplantTemplateVersion;
    /** ImplantType, (0068,6223), CS, 1,  */
    extern const tag ImplantType;
    /** ImplantTypeCodeSequence, (0068,63A8), SQ, 1,  */
    extern const tag ImplantTypeCodeSequence;
    /** ImplementationClassUID, (0002,0012), UI, 1,  */
    extern const tag ImplementationClassUID;
    /** ImplementationVersionName, (0002,0013), SH, 1,  */
    extern const tag ImplementationVersionName;
    /** Impressions, (4008,0300), ST, 1, RET */
    extern const tag Impressions;
    /** InboundArrivalType, (4010,1056), CS, 1,  */
    extern const tag InboundArrivalType;
    /** IncidentAngle, (0014,4052), DS, 1,  */
    extern const tag IncidentAngle;
    /** IncludeDisplayApplication, (2200,0009), CS, 1,  */
    extern const tag IncludeDisplayApplication;
    /** IncludeNonDICOMObjects, (2200,0008), CS, 1,  */
    extern const tag IncludeNonDICOMObjects;
    /** InConcatenationNumber, (0020,9162), US, 1,  */
    extern const tag InConcatenationNumber;
    /** InConcatenationTotalNumber, (0020,9163), US, 1,  */
    extern const tag InConcatenationTotalNumber;
    /** IndexNormalsFlag, (0024,0338), CS, 1,  */
    extern const tag IndexNormalsFlag;
    /** IndexProbability, (0024,0341), FL, 1,  */
    extern const tag IndexProbability;
    /** IndexProbabilitySequence, (0024,0344), SQ, 1,  */
    extern const tag IndexProbabilitySequence;
    /** IndicationDescription, (0014,2018), ST, 1,  */
    extern const tag IndicationDescription;
    /** IndicationDisposition, (0014,201C), CS, 1,  */
    extern const tag IndicationDisposition;
    /** IndicationLabel, (0014,2016), SH, 1,  */
    extern const tag IndicationLabel;
    /** IndicationNumber, (0014,2014), IS, 1,  */
    extern const tag IndicationNumber;
    /** IndicationPhysicalPropertySequence, (0014,2030), SQ, 1,  */
    extern const tag IndicationPhysicalPropertySequence;
    /** IndicationROISequence, (0014,201E), SQ, 1,  */
    extern const tag IndicationROISequence;
    /** IndicationSequence, (0014,2012), SQ, 1,  */
    extern const tag IndicationSequence;
    /** IndicationType, (0014,201A), CS, 1-n,  */
    extern const tag IndicationType;
    /** InformationFromManufacturerSequence, (0068,6260), SQ, 1,  */
    extern const tag InformationFromManufacturerSequence;
    /** InformationIssueDateTime, (0068,6270), DT, 1,  */
    extern const tag InformationIssueDateTime;
    /** InformationSummary, (0068,6280), ST, 1,  */
    extern const tag InformationSummary;
    /** InitialCineRunState, (0018,0042), CS, 1,  */
    extern const tag InitialCineRunState;
    /** InnerDiameter, (0014,0056), DS, 1,  */
    extern const tag InnerDiameter;
    /** InPlanePhaseEncodingDirection, (0018,1312), CS, 1,  */
    extern const tag InPlanePhaseEncodingDirection;
    /** InputAvailabilityFlag, (0040,4020), CS, 1,  */
    extern const tag InputAvailabilityFlag;
    /** InputInformationSequence, (0040,4021), SQ, 1,  */
    extern const tag InputInformationSequence;
    /** InputReadinessState, (0040,4041), CS, 1,  */
    extern const tag InputReadinessState;
    /** InStackPositionNumber, (0020,9057), UL, 1,  */
    extern const tag InStackPositionNumber;
    /** InstanceAvailability, (0008,0056), CS, 1,  */
    extern const tag InstanceAvailability;
    /** InstanceCreationDate, (0008,0012), DA, 1,  */
    extern const tag InstanceCreationDate;
    /** InstanceCreationTime, (0008,0013), TM, 1,  */
    extern const tag InstanceCreationTime;
    /** InstanceCreatorUID, (0008,0014), UI, 1,  */
    extern const tag InstanceCreatorUID;
    /** InstanceNumber, (0020,0013), IS, 1,  */
    extern const tag InstanceNumber;
    /** InstitutionAddress, (0008,0081), ST, 1,  */
    extern const tag InstitutionAddress;
    /** InstitutionalDepartmentName, (0008,1040), LO, 1,  */
    extern const tag InstitutionalDepartmentName;
    /** InstitutionCodeSequence, (0008,0082), SQ, 1,  */
    extern const tag InstitutionCodeSequence;
    /** InstitutionName, (0008,0080), LO, 1,  */
    extern const tag InstitutionName;
    /** InsurancePlanIdentification, (0010,1050), LO, 1-n, RET */
    extern const tag InsurancePlanIdentification;
    /** IntendedRecipientsOfResultsIdentificationSequence, (0040,1011), SQ, 1,  */
    extern const tag IntendedRecipientsOfResultsIdentificationSequence;
    /** IntensifierActiveDimensions, (0018,9428), FL, 1-2,  */
    extern const tag IntensifierActiveDimensions;
    /** IntensifierActiveShape, (0018,9427), CS, 1,  */
    extern const tag IntensifierActiveShape;
    /** IntensifierSize, (0018,1162), DS, 1,  */
    extern const tag IntensifierSize;
    /** InterMarkerDistance, (0050,0019), DS, 1,  */
    extern const tag InterMarkerDistance;
    /** IntermediatePupillaryDistance, (0046,0063), FD, 1,  */
    extern const tag IntermediatePupillaryDistance;
    /** InternalDetectorFrameTime, (0014,3011), DS, 1,  */
    extern const tag InternalDetectorFrameTime;
    /** InternationalRouteSegment, (4010,1028), CS, 1,  */
    extern const tag InternationalRouteSegment;
    /** InterpolationType, (0052,0039), CS, 1,  */
    extern const tag InterpolationType;
    /** InterpretationApprovalDate, (4008,0112), DA, 1, RET */
    extern const tag InterpretationApprovalDate;
    /** InterpretationApprovalTime, (4008,0113), TM, 1, RET */
    extern const tag InterpretationApprovalTime;
    /** InterpretationApproverSequence, (4008,0111), SQ, 1, RET */
    extern const tag InterpretationApproverSequence;
    /** InterpretationAuthor, (4008,010C), PN, 1, RET */
    extern const tag InterpretationAuthor;
    /** InterpretationDiagnosisCodeSequence, (4008,0117), SQ, 1, RET */
    extern const tag InterpretationDiagnosisCodeSequence;
    /** InterpretationDiagnosisDescription, (4008,0115), LT, 1, RET */
    extern const tag InterpretationDiagnosisDescription;
    /** InterpretationID, (4008,0200), SH, 1, RET */
    extern const tag InterpretationID;
    /** InterpretationIDIssuer, (4008,0202), LO, 1, RET */
    extern const tag InterpretationIDIssuer;
    /** InterpretationRecordedDate, (4008,0100), DA, 1, RET */
    extern const tag InterpretationRecordedDate;
    /** InterpretationRecordedTime, (4008,0101), TM, 1, RET */
    extern const tag InterpretationRecordedTime;
    /** InterpretationRecorder, (4008,0102), PN, 1, RET */
    extern const tag InterpretationRecorder;
    /** InterpretationStatusID, (4008,0212), CS, 1, RET */
    extern const tag InterpretationStatusID;
    /** InterpretationText, (4008,010B), ST, 1, RET */
    extern const tag InterpretationText;
    /** InterpretationTranscriber, (4008,010A), PN, 1, RET */
    extern const tag InterpretationTranscriber;
    /** InterpretationTranscriptionDate, (4008,0108), DA, 1, RET */
    extern const tag InterpretationTranscriptionDate;
    /** InterpretationTranscriptionTime, (4008,0109), TM, 1, RET */
    extern const tag InterpretationTranscriptionTime;
    /** InterpretationTypeID, (4008,0210), CS, 1, RET */
    extern const tag InterpretationTypeID;
    /** IntervalNumber, (0020,0016), IS, 1, RET */
    extern const tag IntervalNumber;
    /** IntervalsAcquired, (0018,1083), IS, 1,  */
    extern const tag IntervalsAcquired;
    /** IntervalsRejected, (0018,1084), IS, 1,  */
    extern const tag IntervalsRejected;
    /** InterventionDescription, (0018,003A), ST, 1,  */
    extern const tag InterventionDescription;
    /** InterventionDrugCodeSequence, (0018,0029), SQ, 1,  */
    extern const tag InterventionDrugCodeSequence;
    /** InterventionDrugDose, (0018,0028), DS, 1,  */
    extern const tag InterventionDrugDose;
    /** InterventionDrugInformationSequence, (0018,0026), SQ, 1,  */
    extern const tag InterventionDrugInformationSequence;
    /** InterventionDrugName, (0018,0034), LO, 1,  */
    extern const tag InterventionDrugName;
    /** InterventionDrugStartTime, (0018,0035), TM, 1,  */
    extern const tag InterventionDrugStartTime;
    /** InterventionDrugStopTime, (0018,0027), TM, 1,  */
    extern const tag InterventionDrugStopTime;
    /** InterventionSequence, (0018,0036), SQ, 1,  */
    extern const tag InterventionSequence;
    /** InterventionStatus, (0018,0038), CS, 1,  */
    extern const tag InterventionStatus;
    /** IntraocularLensCalculationsLeftEyeSequence, (0022,1310), SQ, 1,  */
    extern const tag IntraocularLensCalculationsLeftEyeSequence;
    /** IntraocularLensCalculationsRightEyeSequence, (0022,1300), SQ, 1,  */
    extern const tag IntraocularLensCalculationsRightEyeSequence;
    /** IntraOcularPressure, (0022,000B), FL, 1,  */
    extern const tag IntraOcularPressure;
    /** IntravascularFrameContentSequence, (0052,0027), SQ, 1,  */
    extern const tag IntravascularFrameContentSequence;
    /** IntravascularLongitudinalDistance, (0052,0028), FD, 1,  */
    extern const tag IntravascularLongitudinalDistance;
    /** IntravascularOCTFrameContentSequence, (0052,0029), SQ, 1,  */
    extern const tag IntravascularOCTFrameContentSequence;
    /** IntravascularOCTFrameTypeSequence, (0052,0025), SQ, 1,  */
    extern const tag IntravascularOCTFrameTypeSequence;
    /** InversionRecovery, (0018,9009), CS, 1,  */
    extern const tag InversionRecovery;
    /** InversionTime, (0018,0082), DS, 1,  */
    extern const tag InversionTime;
    /** InversionTimes, (0018,9079), FD, 1-n,  */
    extern const tag InversionTimes;
    /** IOLFormulaCodeSequence, (0022,1028), SQ, 1,  */
    extern const tag IOLFormulaCodeSequence;
    /** IOLFormulaDetail, (0022,1029), LO, 1,  */
    extern const tag IOLFormulaDetail;
    /** IOLManufacturer, (0022,1093), LO, 1,  */
    extern const tag IOLManufacturer;
    /** IOLPower, (0022,1053), FL, 1,  */
    extern const tag IOLPower;
    /** IOLPowerForExactEmmetropia, (0022,1121), FL, 1,  */
    extern const tag IOLPowerForExactEmmetropia;
    /** IOLPowerForExactTargetRefraction, (0022,1122), FL, 1,  */
    extern const tag IOLPowerForExactTargetRefraction;
    /** IOLPowerSequence, (0022,1090), SQ, 1,  */
    extern const tag IOLPowerSequence;
    /** IonBeamLimitingDeviceSequence, (300A,03A4), SQ, 1,  */
    extern const tag IonBeamLimitingDeviceSequence;
    /** IonBeamSequence, (300A,03A2), SQ, 1,  */
    extern const tag IonBeamSequence;
    /** IonBlockSequence, (300A,03A6), SQ, 1,  */
    extern const tag IonBlockSequence;
    /** IonControlPointDeliverySequence, (3008,0041), SQ, 1,  */
    extern const tag IonControlPointDeliverySequence;
    /** IonControlPointSequence, (300A,03A8), SQ, 1,  */
    extern const tag IonControlPointSequence;
    /** IonControlPointVerificationSequence, (0074,104E), SQ, 1,  */
    extern const tag IonControlPointVerificationSequence;
    /** IonMachineVerificationSequence, (0074,1046), SQ, 1,  */
    extern const tag IonMachineVerificationSequence;
    /** IonRangeCompensatorSequence, (300A,02EA), SQ, 1,  */
    extern const tag IonRangeCompensatorSequence;
    /** IonToleranceTableSequence, (300A,03A0), SQ, 1,  */
    extern const tag IonToleranceTableSequence;
    /** IonWedgePositionSequence, (300A,03AC), SQ, 1,  */
    extern const tag IonWedgePositionSequence;
    /** IonWedgeSequence, (300A,03AA), SQ, 1,  */
    extern const tag IonWedgeSequence;
    /** IrradiationEventIdentificationSequence, (0018,9477), SQ, 1,  */
    extern const tag IrradiationEventIdentificationSequence;
    /** IrradiationEventUID, (0008,3010), UI, 1,  */
    extern const tag IrradiationEventUID;
    /** IsocenterPosition, (300A,012C), DS, 3,  */
    extern const tag IsocenterPosition;
    /** IsocenterReferenceSystemSequence, (0018,9462), SQ, 1,  */
    extern const tag IsocenterReferenceSystemSequence;
    /** IsocenterToBeamLimitingDeviceDistance, (300A,00BB), FL, 1,  */
    extern const tag IsocenterToBeamLimitingDeviceDistance;
    /** IsocenterToBlockTrayDistance, (300A,00F7), FL, 1,  */
    extern const tag IsocenterToBlockTrayDistance;
    /** IsocenterToCompensatorDistances, (300A,02E6), FL, 1-n,  */
    extern const tag IsocenterToCompensatorDistances;
    /** IsocenterToCompensatorTrayDistance, (300A,02E4), FL, 1,  */
    extern const tag IsocenterToCompensatorTrayDistance;
    /** IsocenterToLateralSpreadingDeviceDistance, (300A,0374), FL, 1,  */
    extern const tag IsocenterToLateralSpreadingDeviceDistance;
    /** IsocenterToRangeModulatorDistance, (300A,038A), FL, 1,  */
    extern const tag IsocenterToRangeModulatorDistance;
    /** IsocenterToRangeShifterDistance, (300A,0364), FL, 1,  */
    extern const tag IsocenterToRangeShifterDistance;
    /** IsocenterToWedgeTrayDistance, (300A,00D9), FL, 1,  */
    extern const tag IsocenterToWedgeTrayDistance;
    /** IsotopeNumber, (0020,0014), IS, 1, RET */
    extern const tag IsotopeNumber;
    /** IssueDateOfImagingServiceRequest, (0040,2004), DA, 1,  */
    extern const tag IssueDateOfImagingServiceRequest;
    /** IssuerOfAccessionNumberSequence, (0008,0051), SQ, 1,  */
    extern const tag IssuerOfAccessionNumberSequence;
    /** IssuerOfAdmissionID, (0038,0011), LO, 1, RET */
    extern const tag IssuerOfAdmissionID;
    /** IssuerOfAdmissionIDSequence, (0038,0014), SQ, 1,  */
    extern const tag IssuerOfAdmissionIDSequence;
    /** IssuerOfPatientID, (0010,0021), LO, 1,  */
    extern const tag IssuerOfPatientID;
    /** IssuerOfPatientIDQualifiersSequence, (0010,0024), SQ, 1,  */
    extern const tag IssuerOfPatientIDQualifiersSequence;
    /** IssuerOfServiceEpisodeID, (0038,0061), LO, 1, RET */
    extern const tag IssuerOfServiceEpisodeID;
    /** IssuerOfServiceEpisodeIDSequence, (0038,0064), SQ, 1,  */
    extern const tag IssuerOfServiceEpisodeIDSequence;
    /** IssuerOfTheContainerIdentifierSequence, (0040,0513), SQ, 1,  */
    extern const tag IssuerOfTheContainerIdentifierSequence;
    /** IssuerOfTheSpecimenIdentifierSequence, (0040,0562), SQ, 1,  */
    extern const tag IssuerOfTheSpecimenIdentifierSequence;
    /** IssueTimeOfImagingServiceRequest, (0040,2005), TM, 1,  */
    extern const tag IssueTimeOfImagingServiceRequest;
    /** Italic, (0070,0250), CS, 1,  */
    extern const tag Italic;
    /** ItemNumber, (0020,0019), IS, 1,  */
    extern const tag ItemNumber;
    /** IterativeReconstructionMethod, (0018,9769), CS, 1,  */
    extern const tag IterativeReconstructionMethod;
    /** ItineraryID, (4010,1051), LO, 1,  */
    extern const tag ItineraryID;
    /** ItineraryIDAssigningAuthority, (4010,1053), LO, 1,  */
    extern const tag ItineraryIDAssigningAuthority;
    /** ItineraryIDType, (4010,1052), SH, 1,  */
    extern const tag ItineraryIDType;
    /** IVUSAcquisition, (0018,3100), CS, 1,  */
    extern const tag IVUSAcquisition;
    /** IVUSGatedRate, (0018,3102), DS, 1,  */
    extern const tag IVUSGatedRate;
    /** IVUSPullbackRate, (0018,3101), DS, 1,  */
    extern const tag IVUSPullbackRate;
    /** IVUSPullbackStartFrameNumber, (0018,3103), IS, 1,  */
    extern const tag IVUSPullbackStartFrameNumber;
    /** IVUSPullbackStopFrameNumber, (0018,3104), IS, 1,  */
    extern const tag IVUSPullbackStopFrameNumber;
    /** KeratometerIndex, (0022,1033), FL, 1,  */
    extern const tag KeratometerIndex;
    /** KeratometricAxis, (0046,0077), FD, 1,  */
    extern const tag KeratometricAxis;
    /** KeratometricPower, (0046,0076), FD, 1,  */
    extern const tag KeratometricPower;
    /** KeratometryLeftEyeSequence, (0046,0071), SQ, 1,  */
    extern const tag KeratometryLeftEyeSequence;
    /** KeratometryMeasurementTypeCodeSequence, (0022,1096), SQ, 1,  */
    extern const tag KeratometryMeasurementTypeCodeSequence;
    /** KeratometryRightEyeSequence, (0046,0070), SQ, 1,  */
    extern const tag KeratometryRightEyeSequence;
    /** KSpaceFiltering, (0018,9064), CS, 1,  */
    extern const tag KSpaceFiltering;
    /** KVP, (0018,0060), DS, 1,  */
    extern const tag KVP;
    /** KVUsedInGainCalibration, (0014,3071), DS, 1,  */
    extern const tag KVUsedInGainCalibration;
    /** LabelStyleSelection, (2200,0003), CS, 1,  */
    extern const tag LabelStyleSelection;
    /** LabelText, (2200,0002), UT, 1,  */
    extern const tag LabelText;
    /** LabelUsingInformationExtractedFromInstances, (2200,0001), CS, 1,  */
    extern const tag LabelUsingInformationExtractedFromInstances;
    /** LanguageCodeSequence, (0008,0006), SQ, 1,  */
    extern const tag LanguageCodeSequence;
    /** LanguageCodeSequenceTrial, (0040,A744), SQ, 1, RET */
    extern const tag LanguageCodeSequenceTrial;
    /** LargeBluePaletteColorLookupTableData, (0028,1213), OW, 1, RET */
    extern const tag LargeBluePaletteColorLookupTableData;
    /** LargeBluePaletteColorLookupTableDescriptor, (0028,1113), US or SS, 4, RET */
    extern const tag LargeBluePaletteColorLookupTableDescriptor;
    /** LargeGreenPaletteColorLookupTableData, (0028,1212), OW, 1, RET */
    extern const tag LargeGreenPaletteColorLookupTableData;
    /** LargeGreenPaletteColorLookupTableDescriptor, (0028,1112), US or SS, 4, RET */
    extern const tag LargeGreenPaletteColorLookupTableDescriptor;
    /** LargePaletteColorLookupTableUID, (0028,1214), UI, 1, RET */
    extern const tag LargePaletteColorLookupTableUID;
    /** LargeRedPaletteColorLookupTableData, (0028,1211), OW, 1, RET */
    extern const tag LargeRedPaletteColorLookupTableData;
    /** LargeRedPaletteColorLookupTableDescriptor, (0028,1111), US or SS, 4, RET */
    extern const tag LargeRedPaletteColorLookupTableDescriptor;
    /** LargestImagePixelValue, (0028,0107), US or SS, 1,  */
    extern const tag LargestImagePixelValue;
    /** LargestImagePixelValueInPlane, (0028,0111), US or SS, 1, RET */
    extern const tag LargestImagePixelValueInPlane;
    /** LargestMonochromePixelValue, (0028,9099), US, 1, RET */
    extern const tag LargestMonochromePixelValue;
    /** LargestPixelValueInSeries, (0028,0109), US or SS, 1,  */
    extern const tag LargestPixelValueInSeries;
    /** LargestValidPixelValue, (0028,0105), US or SS, 1, RET */
    extern const tag LargestValidPixelValue;
    /** LastMenstrualDate, (0010,21D0), DA, 1,  */
    extern const tag LastMenstrualDate;
    /** Laterality, (0020,0060), CS, 1,  */
    extern const tag Laterality;
    /** LateralSpreadingDeviceDescription, (300A,033A), LO, 1,  */
    extern const tag LateralSpreadingDeviceDescription;
    /** LateralSpreadingDeviceID, (300A,0336), SH, 1,  */
    extern const tag LateralSpreadingDeviceID;
    /** LateralSpreadingDeviceNumber, (300A,0334), IS, 1,  */
    extern const tag LateralSpreadingDeviceNumber;
    /** LateralSpreadingDeviceSequence, (300A,0332), SQ, 1,  */
    extern const tag LateralSpreadingDeviceSequence;
    /** LateralSpreadingDeviceSetting, (300A,0372), LO, 1,  */
    extern const tag LateralSpreadingDeviceSetting;
    /** LateralSpreadingDeviceSettingsSequence, (300A,0370), SQ, 1,  */
    extern const tag LateralSpreadingDeviceSettingsSequence;
    /** LateralSpreadingDeviceType, (300A,0338), CS, 1,  */
    extern const tag LateralSpreadingDeviceType;
    /** LateralSpreadingDeviceWaterEquivalentThickness, (300A,033C), FL, 1,  */
    extern const tag LateralSpreadingDeviceWaterEquivalentThickness;
    /** LeafJawPositions, (300A,011C), DS, 2-2n,  */
    extern const tag LeafJawPositions;
    /** LeafPositionBoundaries, (300A,00BE), DS, 3-n,  */
    extern const tag LeafPositionBoundaries;
    /** LeftImageSequence, (0022,0021), SQ, 1,  */
    extern const tag LeftImageSequence;
    /** LeftLensSequence, (0046,0015), SQ, 1,  */
    extern const tag LeftLensSequence;
    /** LengthToEnd, (0008,0001), UL, 1, RET */
    extern const tag LengthToEnd;
    /** LensConstantDescription, (0022,1094), LO, 1,  */
    extern const tag LensConstantDescription;
    /** LensConstantSequence, (0022,1092), SQ, 1,  */
    extern const tag LensConstantSequence;
    /** LensDescription, (0046,0012), LO, 1,  */
    extern const tag LensDescription;
    /** LensesCodeSequence, (0022,0019), SQ, 1,  */
    extern const tag LensesCodeSequence;
    /** LensSegmentType, (0046,0038), CS, 1,  */
    extern const tag LensSegmentType;
    /** LensStatusCodeSequence, (0022,1024), SQ, 1,  */
    extern const tag LensStatusCodeSequence;
    /** LensStatusDescription, (0022,1065), LO, 1,  */
    extern const tag LensStatusDescription;
    /** LensThickness, (0022,1130), FL, 1,  */
    extern const tag LensThickness;
    /** LensThicknessSequence, (0022,1127), SQ, 1,  */
    extern const tag LensThicknessSequence;
    /** LesionNumber, (0018,3105), IS, 1-n,  */
    extern const tag LesionNumber;
    /** LightPathFilterPassBand, (0022,0002), US, 2,  */
    extern const tag LightPathFilterPassBand;
    /** LightPathFilterPassThroughWavelength, (0022,0001), US, 1,  */
    extern const tag LightPathFilterPassThroughWavelength;
    /** LightPathFilterTypeStackCodeSequence, (0022,0017), SQ, 1,  */
    extern const tag LightPathFilterTypeStackCodeSequence;
    /** LINACEnergy, (0014,5002), IS, 1,  */
    extern const tag LINACEnergy;
    /** LINACOutput, (0014,5004), IS, 1,  */
    extern const tag LINACOutput;
    /** LineDashingStyle, (0070,0254), CS, 1,  */
    extern const tag LineDashingStyle;
    /** LinePattern, (0070,0255), UL, 1,  */
    extern const tag LinePattern;
    /** LineSequence, (0066,0028), SQ, 1,  */
    extern const tag LineSequence;
    /** LineStyleSequence, (0070,0232), SQ, 1,  */
    extern const tag LineStyleSequence;
    /** LineThickness, (0070,0253), FL, 1,  */
    extern const tag LineThickness;
    /** ListOfMIMETypes, (0042,0014), LO, 1-n,  */
    extern const tag ListOfMIMETypes;
    /** LocalDeviationProbabilityNormalsFlag, (0024,0072), CS, 1,  */
    extern const tag LocalDeviationProbabilityNormalsFlag;
    /** LocalizedDeviationfromNormal, (0024,0068), FL, 1,  */
    extern const tag LocalizedDeviationfromNormal;
    /** LocalizedDeviationProbability, (0024,0073), FL, 1,  */
    extern const tag LocalizedDeviationProbability;
    /** LocalizedDeviationProbabilitySequence, (0024,0085), SQ, 1,  */
    extern const tag LocalizedDeviationProbabilitySequence;
    /** LocalNamespaceEntityID, (0040,0031), UT, 1,  */
    extern const tag LocalNamespaceEntityID;
    /** Location, (0020,0050), DS, 1, RET */
    extern const tag Location;
    /** LocationOfMeasuredBeamDiameter, (0014,4019), DS, 1,  */
    extern const tag LocationOfMeasuredBeamDiameter;
    /** LongitudinalTemporalInformationModified, (0028,0303), CS, 1,  */
    extern const tag LongitudinalTemporalInformationModified;
    /** LossyImageCompression, (0028,2110), CS, 1,  */
    extern const tag LossyImageCompression;
    /** LossyImageCompressionMethod, (0028,2114), CS, 1-n,  */
    extern const tag LossyImageCompressionMethod;
    /** LossyImageCompressionRatio, (0028,2112), DS, 1-n,  */
    extern const tag LossyImageCompressionRatio;
    /** LossyImageCompressionRetired, (0008,2110), CS, 1, RET */
    extern const tag LossyImageCompressionRetired;
    /** LowEnergyDetectors, (4010,0001), CS, 1,  */
    extern const tag LowEnergyDetectors;
    /** LowRRValue, (0018,1081), IS, 1,  */
    extern const tag LowRRValue;
    /** LUTData, (0028,3006), US or OW, 1-n1,  */
    extern const tag LUTData;
    /** LUTDescriptor, (0028,3002), US or SS, 3,  */
    extern const tag LUTDescriptor;
    /** LUTExplanation, (0028,3003), LO, 1,  */
    extern const tag LUTExplanation;
    /** LUTFrameRange, (0028,9507), US, 2-2n,  */
    extern const tag LUTFrameRange;
    /** LUTFunction, (0028,9474), CS, 1,  */
    extern const tag LUTFunction;
    /** LUTLabel, (0040,9210), SH, 1,  */
    extern const tag LUTLabel;
    /** LUTNumber, (0020,0026), IS, 1, RET */
    extern const tag LUTNumber;
    /** MAC, (0400,0404), OB, 1,  */
    extern const tag MAC;
    /** MACAlgorithm, (0400,0015), CS, 1,  */
    extern const tag MACAlgorithm;
    /** MACCalculationTransferSyntaxUID, (0400,0010), UI, 1,  */
    extern const tag MACCalculationTransferSyntaxUID;
    /** MACIDNumber, (0400,0005), US, 1,  */
    extern const tag MACIDNumber;
    /** MACParametersSequence, (4FFE,0001), SQ, 1,  */
    extern const tag MACParametersSequence;
    /** MagneticFieldStrength, (0018,0087), DS, 1,  */
    extern const tag MagneticFieldStrength;
    /** MagnetizationTransfer, (0018,9020), CS, 1,  */
    extern const tag MagnetizationTransfer;
    /** MagnificationType, (2010,0060), CS, 1,  */
    extern const tag MagnificationType;
    /** MagnifyToNumberOfColumns, (2040,0074), US, 1, RET */
    extern const tag MagnifyToNumberOfColumns;
    /** MajorTicksSequence, (0070,0287), SQ, 1,  */
    extern const tag MajorTicksSequence;
    /** MandatoryComponentType, (0076,0038), CS, 1,  */
    extern const tag MandatoryComponentType;
    /** Manifold, (0066,0010), CS, 1,  */
    extern const tag Manifold;
    /** ManipulatedImage, (0028,0050), LO, 1-n, RET */
    extern const tag ManipulatedImage;
    /** Manufacturer, (0008,0070), LO, 1,  */
    extern const tag Manufacturer;
    /** ManufacturerModelName, (0008,1090), LO, 1,  */
    extern const tag ManufacturerModelName;
    /** MappingResource, (0008,0105), CS, 1,  */
    extern const tag MappingResource;
    /** MaskFrameNumbers, (0028,6110), US, 1-n,  */
    extern const tag MaskFrameNumbers;
    /** MaskingImage, (0020,0080), CS, 1-n, RET */
    extern const tag MaskingImage;
    /** MaskOperation, (0028,6101), CS, 1,  */
    extern const tag MaskOperation;
    /** MaskOperationExplanation, (0028,6190), ST, 1,  */
    extern const tag MaskOperationExplanation;
    /** MaskPointers, (0028,6030), US, 1-n, RET */
    extern const tag MaskPointers;
    /** MaskSelectionMode, (0028,9454), CS, 1,  */
    extern const tag MaskSelectionMode;
    /** MaskSubPixelShift, (0028,6114), FL, 2,  */
    extern const tag MaskSubPixelShift;
    /** MaskSubtractionSequence, (0028,6100), SQ, 1,  */
    extern const tag MaskSubtractionSequence;
    /** MaskVisibilityPercentage, (0028,9478), FL, 1,  */
    extern const tag MaskVisibilityPercentage;
    /** Mass, (4010,1017), FL, 1,  */
    extern const tag Mass;
    /** MaterialGrade, (0014,0042), ST, 1-n,  */
    extern const tag MaterialGrade;
    /** MaterialID, (300A,00E1), SH, 1,  */
    extern const tag MaterialID;
    /** MaterialIsolationDiameter, (0014,0034), DS, 1-n,  */
    extern const tag MaterialIsolationDiameter;
    /** MaterialNotes, (0014,0046), LT, 1,  */
    extern const tag MaterialNotes;
    /** MaterialPipeDiameter, (0014,0032), DS, 1-n,  */
    extern const tag MaterialPipeDiameter;
    /** MaterialPropertiesFileFormat, (0014,0045), ST, 1-n,  */
    extern const tag MaterialPropertiesFileFormat;
    /** MaterialPropertiesFileID, (0014,0044), ST, 1-n,  */
    extern const tag MaterialPropertiesFileID;
    /** MaterialsCodeSequence, (0068,63A0), SQ, 1,  */
    extern const tag MaterialsCodeSequence;
    /** MaterialThickness, (0014,0030), DS, 1-n,  */
    extern const tag MaterialThickness;
    /** MatingFeatureDegreeOfFreedomSequence, (0068,6400), SQ, 1,  */
    extern const tag MatingFeatureDegreeOfFreedomSequence;
    /** MatingFeatureID, (0068,63F0), US, 1,  */
    extern const tag MatingFeatureID;
    /** MatingFeatureSequence, (0068,63E0), SQ, 1,  */
    extern const tag MatingFeatureSequence;
    /** MatingFeatureSetID, (0068,63C0), US, 1,  */
    extern const tag MatingFeatureSetID;
    /** MatingFeatureSetLabel, (0068,63D0), LO, 1,  */
    extern const tag MatingFeatureSetLabel;
    /** MatingFeatureSetsSequence, (0068,63B0), SQ, 1,  */
    extern const tag MatingFeatureSetsSequence;
    /** MatrixRegistrationSequence, (0070,0309), SQ, 1,  */
    extern const tag MatrixRegistrationSequence;
    /** MatrixSequence, (0070,030A), SQ, 1,  */
    extern const tag MatrixSequence;
    /** MAUsedInGainCalibration, (0014,3072), DS, 1,  */
    extern const tag MAUsedInGainCalibration;
    /** MaxDensity, (2010,0130), US, 1,  */
    extern const tag MaxDensity;
    /** MaximumAcrossScanDistortion, (0022,0049), FL, 1,  */
    extern const tag MaximumAcrossScanDistortion;
    /** MaximumAlongScanDistortion, (0022,0038), FL, 1,  */
    extern const tag MaximumAlongScanDistortion;
    /** MaximumCollatedFilms, (2010,0154), IS, 1,  */
    extern const tag MaximumCollatedFilms;
    /** MaximumCoordinateValue, (50XX,0105), US, 1-n, RET */
    extern const range_tag MaximumCoordinateValue;
    /** MaximumDepthDistortion, (0022,0036), FL, 1,  */
    extern const tag MaximumDepthDistortion;
    /** MaximumFractionalValue, (0062,000E), US, 1,  */
    extern const tag MaximumFractionalValue;
    /** MaximumMemoryAllocation, (2000,0061), IS, 1,  */
    extern const tag MaximumMemoryAllocation;
    /** MaximumPointDistance, (0066,0019), FL, 1,  */
    extern const tag MaximumPointDistance;
    /** MaximumStimulusLuminance, (0024,0018), FL, 1,  */
    extern const tag MaximumStimulusLuminance;
    /** MeanPointDistance, (0066,0018), FL, 1,  */
    extern const tag MeanPointDistance;
    /** MeasuredBandwidth, (0014,401C), DS, 1,  */
    extern const tag MeasuredBandwidth;
    /** MeasuredBeamDimensionA, (0014,4017), DS, 1,  */
    extern const tag MeasuredBeamDimensionA;
    /** MeasuredBeamDimensionB, (0014,4018), DS, 1,  */
    extern const tag MeasuredBeamDimensionB;
    /** MeasuredCenterFrequency, (0014,401B), DS, 1,  */
    extern const tag MeasuredCenterFrequency;
    /** MeasuredDoseDescription, (3008,0012), ST, 1,  */
    extern const tag MeasuredDoseDescription;
    /** MeasuredDoseReferenceNumber, (3008,0064), IS, 1,  */
    extern const tag MeasuredDoseReferenceNumber;
    /** MeasuredDoseReferenceSequence, (3008,0010), SQ, 1,  */
    extern const tag MeasuredDoseReferenceSequence;
    /** MeasuredDoseType, (3008,0014), CS, 1,  */
    extern const tag MeasuredDoseType;
    /** MeasuredDoseValue, (3008,0016), DS, 1,  */
    extern const tag MeasuredDoseValue;
    /** MeasuredValueSequence, (0040,A300), SQ, 1,  */
    extern const tag MeasuredValueSequence;
    /** MeasurementAutomationTrial, (0040,A194), CS, 1, RET */
    extern const tag MeasurementAutomationTrial;
    /** MeasurementLaterality, (0024,0113), CS, 1,  */
    extern const tag MeasurementLaterality;
    /** MeasurementPrecisionDescriptionTrial, (0040,A047), LO, 1, RET */
    extern const tag MeasurementPrecisionDescriptionTrial;
    /** MeasurementUnitsCodeSequence, (0040,08EA), SQ, 1,  */
    extern const tag MeasurementUnitsCodeSequence;
    /** MeasuringUnitsSequence, (0040,0295), SQ, 1,  */
    extern const tag MeasuringUnitsSequence;
    /** MechanicalIndex, (0018,5022), DS, 1,  */
    extern const tag MechanicalIndex;
    /** MediaDisposition, (2200,0004), LT, 1,  */
    extern const tag MediaDisposition;
    /** MediaInstalledSequence, (2000,00A2), SQ, 1,  */
    extern const tag MediaInstalledSequence;
    /** MediaStorageSOPClassUID, (0002,0002), UI, 1,  */
    extern const tag MediaStorageSOPClassUID;
    /** MediaStorageSOPInstanceUID, (0002,0003), UI, 1,  */
    extern const tag MediaStorageSOPInstanceUID;
    /** MedicalAlerts, (0010,2000), LO, 1-n,  */
    extern const tag MedicalAlerts;
    /** MedicalRecordLocator, (0010,1090), LO, 1,  */
    extern const tag MedicalRecordLocator;
    /** MediumType, (2000,0030), CS, 1,  */
    extern const tag MediumType;
    /** MemoryAllocation, (2000,0060), IS, 1,  */
    extern const tag MemoryAllocation;
    /** MemoryBitDepth, (2000,00A0), US, 1,  */
    extern const tag MemoryBitDepth;
    /** MetaboliteMapCodeSequence, (0018,9083), SQ, 1,  */
    extern const tag MetaboliteMapCodeSequence;
    /** MetaboliteMapDescription, (0018,9080), ST, 1,  */
    extern const tag MetaboliteMapDescription;
    /** MetersetExposure, (3002,0032), DS, 1,  */
    extern const tag MetersetExposure;
    /** MetersetRate, (300A,035A), FL, 1,  */
    extern const tag MetersetRate;
    /** MetersetRateDelivered, (3008,0046), FL, 1,  */
    extern const tag MetersetRateDelivered;
    /** MetersetRateSet, (3008,0045), FL, 1,  */
    extern const tag MetersetRateSet;
    /** MidSlabPosition, (0018,9106), FD, 3,  */
    extern const tag MidSlabPosition;
    /** MilitaryRank, (0010,1080), LO, 1,  */
    extern const tag MilitaryRank;
    /** MIMETypeOfEncapsulatedDocument, (0042,0012), LO, 1,  */
    extern const tag MIMETypeOfEncapsulatedDocument;
    /** MinDensity, (2010,0120), US, 1,  */
    extern const tag MinDensity;
    /** MinimumCoordinateValue, (50XX,0104), US, 1-n, RET */
    extern const range_tag MinimumCoordinateValue;
    /** MinimumSensitivityValue, (0024,0105), FL, 1,  */
    extern const tag MinimumSensitivityValue;
    /** ModalitiesInStudy, (0008,0061), CS, 1-n,  */
    extern const tag ModalitiesInStudy;
    /** Modality, (0008,0060), CS, 1,  */
    extern const tag Modality;
    /** ModalityLUTSequence, (0028,3000), SQ, 1,  */
    extern const tag ModalityLUTSequence;
    /** ModalityLUTType, (0028,3004), LO, 1,  */
    extern const tag ModalityLUTType;
    /** ModeOfPercutaneousAccessSequence, (0052,0016), SQ, 1,  */
    extern const tag ModeOfPercutaneousAccessSequence;
    /** ModifiedAttributesSequence, (0400,0550), SQ, 1,  */
    extern const tag ModifiedAttributesSequence;
    /** ModifiedImageDate, (0020,3403), DA, 1, RET */
    extern const tag ModifiedImageDate;
    /** ModifiedImageDescription, (0020,3406), LO, 1, RET */
    extern const tag ModifiedImageDescription;
    /** ModifiedImageID, (0020,3402), CS, 1, RET */
    extern const tag ModifiedImageID;
    /** ModifiedImageTime, (0020,3405), TM, 1, RET */
    extern const tag ModifiedImageTime;
    /** ModifierCodeSequence, (0040,A195), SQ, 1,  */
    extern const tag ModifierCodeSequence;
    /** ModifyingDeviceID, (0020,3401), CS, 1, RET */
    extern const tag ModifyingDeviceID;
    /** ModifyingDeviceManufacturer, (0020,3404), LO, 1, RET */
    extern const tag ModifyingDeviceManufacturer;
    /** ModifyingSystem, (0400,0563), LO, 1,  */
    extern const tag ModifyingSystem;
    /** ModulationType, (0014,4026), CS, 1,  */
    extern const tag ModulationType;
    /** MostRecentTreatmentDate, (3008,0056), DA, 1,  */
    extern const tag MostRecentTreatmentDate;
    /** MotionSynchronizationSequence, (300A,0410), SQ, 1,  */
    extern const tag MotionSynchronizationSequence;
    /** MRAcquisitionFrequencyEncodingSteps, (0018,9058), US, 1,  */
    extern const tag MRAcquisitionFrequencyEncodingSteps;
    /** MRAcquisitionPhaseEncodingStepsInPlane, (0018,9231), US, 1,  */
    extern const tag MRAcquisitionPhaseEncodingStepsInPlane;
    /** MRAcquisitionPhaseEncodingStepsOutOfPlane, (0018,9232), US, 1,  */
    extern const tag MRAcquisitionPhaseEncodingStepsOutOfPlane;
    /** MRAcquisitionType, (0018,0023), CS, 1,  */
    extern const tag MRAcquisitionType;
    /** MRArterialSpinLabelingSequence, (0018,9251), SQ, 1,  */
    extern const tag MRArterialSpinLabelingSequence;
    /** MRAveragesSequence, (0018,9119), SQ, 1,  */
    extern const tag MRAveragesSequence;
    /** MRDiffusionSequence, (0018,9117), SQ, 1,  */
    extern const tag MRDiffusionSequence;
    /** MRDRDirectoryRecordOffset, (0004,1504), UL, 1, RET */
    extern const tag MRDRDirectoryRecordOffset;
    /** MREchoSequence, (0018,9114), SQ, 1,  */
    extern const tag MREchoSequence;
    /** MRFOVGeometrySequence, (0018,9125), SQ, 1,  */
    extern const tag MRFOVGeometrySequence;
    /** MRImageFrameTypeSequence, (0018,9226), SQ, 1,  */
    extern const tag MRImageFrameTypeSequence;
    /** MRImagingModifierSequence, (0018,9006), SQ, 1,  */
    extern const tag MRImagingModifierSequence;
    /** MRMetaboliteMapSequence, (0018,9152), SQ, 1,  */
    extern const tag MRMetaboliteMapSequence;
    /** MRModifierSequence, (0018,9115), SQ, 1,  */
    extern const tag MRModifierSequence;
    /** MRReceiveCoilSequence, (0018,9042), SQ, 1,  */
    extern const tag MRReceiveCoilSequence;
    /** MRSpatialSaturationSequence, (0018,9107), SQ, 1,  */
    extern const tag MRSpatialSaturationSequence;
    /** MRSpectroscopyAcquisitionType, (0018,9200), CS, 1,  */
    extern const tag MRSpectroscopyAcquisitionType;
    /** MRSpectroscopyFOVGeometrySequence, (0018,9103), SQ, 1,  */
    extern const tag MRSpectroscopyFOVGeometrySequence;
    /** MRSpectroscopyFrameTypeSequence, (0018,9227), SQ, 1,  */
    extern const tag MRSpectroscopyFrameTypeSequence;
    /** MRTimingAndRelatedParametersSequence, (0018,9112), SQ, 1,  */
    extern const tag MRTimingAndRelatedParametersSequence;
    /** MRTransmitCoilSequence, (0018,9049), SQ, 1,  */
    extern const tag MRTransmitCoilSequence;
    /** MRVelocityEncodingSequence, (0018,9197), SQ, 1,  */
    extern const tag MRVelocityEncodingSequence;
    /** MultiCoilConfiguration, (0018,9046), LO, 1,  */
    extern const tag MultiCoilConfiguration;
    /** MultiCoilDefinitionSequence, (0018,9045), SQ, 1,  */
    extern const tag MultiCoilDefinitionSequence;
    /** MultiCoilElementName, (0018,9047), SH, 1,  */
    extern const tag MultiCoilElementName;
    /** MultiCoilElementUsed, (0018,9048), CS, 1,  */
    extern const tag MultiCoilElementUsed;
    /** MultiFramePresentationSequence, (0028,9505), SQ, 1,  */
    extern const tag MultiFramePresentationSequence;
    /** MultiFrameSourceSOPInstanceUID, (0008,1167), UI, 1,  */
    extern const tag MultiFrameSourceSOPInstanceUID;
    /** MultiPlanarExcitation, (0018,9012), CS, 1,  */
    extern const tag MultiPlanarExcitation;
    /** MultipleCopiesFlag, (0040,4006), CS, 1,  */
    extern const tag MultipleCopiesFlag;
    /** MultipleSpinEcho, (0018,9011), CS, 1,  */
    extern const tag MultipleSpinEcho;
    /** MultiplexedAudioChannelsDescriptionCodeSequence, (003A,0300), SQ, 1,  */
    extern const tag MultiplexedAudioChannelsDescriptionCodeSequence;
    /** MultiplexGroupLabel, (003A,0020), SH, 1,  */
    extern const tag MultiplexGroupLabel;
    /** MultiplexGroupTimeOffset, (0018,1068), DS, 1,  */
    extern const tag MultiplexGroupTimeOffset;
    /** MydriaticAgentCodeSequence, (0022,001C), SQ, 1,  */
    extern const tag MydriaticAgentCodeSequence;
    /** MydriaticAgentConcentration, (0022,004E), DS, 1,  */
    extern const tag MydriaticAgentConcentration;
    /** MydriaticAgentConcentrationUnitsSequence, (0022,0042), SQ, 1,  */
    extern const tag MydriaticAgentConcentrationUnitsSequence;
    /** MydriaticAgentSequence, (0022,0058), SQ, 1,  */
    extern const tag MydriaticAgentSequence;
    /** NameOfPhysiciansReadingStudy, (0008,1060), PN, 1-n,  */
    extern const tag NameOfPhysiciansReadingStudy;
    /** NamesOfIntendedRecipientsOfResults, (0040,1010), PN, 1-n,  */
    extern const tag NamesOfIntendedRecipientsOfResults;
    /** NavigationDisplaySet, (0072,0216), US, 1,  */
    extern const tag NavigationDisplaySet;
    /** NavigationIndicatorSequence, (0072,0214), SQ, 1,  */
    extern const tag NavigationIndicatorSequence;
    /** NearPupillaryDistance, (0046,0062), FD, 1,  */
    extern const tag NearPupillaryDistance;
    /** NegativeCatchTrialsQuantity, (0024,0048), US, 1,  */
    extern const tag NegativeCatchTrialsQuantity;
    /** NetworkID, (0008,1000), AE, 1, RET */
    extern const tag NetworkID;
    /** NominalBeamEnergy, (300A,0114), DS, 1,  */
    extern const tag NominalBeamEnergy;
    /** NominalBeamEnergyUnit, (300A,0015), CS, 1,  */
    extern const tag NominalBeamEnergyUnit;
    /** NominalCardiacTriggerDelayTime, (0020,9153), FD, 1,  */
    extern const tag NominalCardiacTriggerDelayTime;
    /** NominalCardiacTriggerTimePriorToRPeak, (0020,9154), FL, 1,  */
    extern const tag NominalCardiacTriggerTimePriorToRPeak;
    /** NominalFrequency, (0014,401A), DS, 1,  */
    extern const tag NominalFrequency;
    /** NominalInterval, (0018,1062), IS, 1,  */
    extern const tag NominalInterval;
    /** NominalPercentageOfCardiacPhase, (0020,9241), FL, 1,  */
    extern const tag NominalPercentageOfCardiacPhase;
    /** NominalPercentageOfRespiratoryPhase, (0020,9245), FL, 1,  */
    extern const tag NominalPercentageOfRespiratoryPhase;
    /** NominalPriorDose, (300A,001A), DS, 1,  */
    extern const tag NominalPriorDose;
    /** NominalRespiratoryTriggerDelayTime, (0020,9255), FD, 1,  */
    extern const tag NominalRespiratoryTriggerDelayTime;
    /** NominalScannedPixelSpacing, (0018,2010), DS, 2,  */
    extern const tag NominalScannedPixelSpacing;
    /** NominalScreenDefinitionSequence, (0072,0102), SQ, 1,  */
    extern const tag NominalScreenDefinitionSequence;
    /** NonDICOMOutputCodeSequence, (0040,4032), SQ, 1,  */
    extern const tag NonDICOMOutputCodeSequence;
    /** NonUniformRadialSamplingCorrected, (0018,9766), CS, 1,  */
    extern const tag NonUniformRadialSamplingCorrected;
    /** NormalizationFactorFormat, (0028,0710), US, 1, RET */
    extern const tag NormalizationFactorFormat;
    /** NormalizationPoint, (3004,0008), DS, 3,  */
    extern const tag NormalizationPoint;
    /** NotchFilterBandwidth, (003A,0223), DS, 1,  */
    extern const tag NotchFilterBandwidth;
    /** NotchFilterFrequency, (003A,0222), DS, 1,  */
    extern const tag NotchFilterFrequency;
    /** NotificationFromManufacturerSequence, (0068,6265), SQ, 1,  */
    extern const tag NotificationFromManufacturerSequence;
    /** NTPSourceAddress, (0018,1803), LO, 1,  */
    extern const tag NTPSourceAddress;
    /** NuclearMedicineSeriesType, (0008,0042), CS, 1, RET */
    extern const tag NuclearMedicineSeriesType;
    /** NumberOfAlarmObjects, (4010,1034), US, 1,  */
    extern const tag NumberOfAlarmObjects;
    /** NumberOfAverages, (0018,0083), DS, 1,  */
    extern const tag NumberOfAverages;
    /** NumberOfBeams, (300A,0080), IS, 1,  */
    extern const tag NumberOfBeams;
    /** NumberOfBlocks, (300A,00F0), IS, 1,  */
    extern const tag NumberOfBlocks;
    /** NumberOfBoli, (300A,00ED), IS, 1,  */
    extern const tag NumberOfBoli;
    /** NumberOfBrachyApplicationSetups, (300A,00A0), IS, 1,  */
    extern const tag NumberOfBrachyApplicationSetups;
    /** NumberOfChannels, (50XX,2004), US, 1, RET */
    extern const range_tag NumberOfChannels;
    /** NumberOfCompensators, (300A,00E0), IS, 1,  */
    extern const tag NumberOfCompensators;
    /** NumberOfContourPoints, (3006,0046), IS, 1,  */
    extern const tag NumberOfContourPoints;
    /** NumberOfControlPoints, (300A,0110), IS, 1,  */
    extern const tag NumberOfControlPoints;
    /** NumberOfCopies, (2000,0010), IS, 1,  */
    extern const tag NumberOfCopies;
    /** NumberOfDetectors, (0054,0021), US, 1,  */
    extern const tag NumberOfDetectors;
    /** NumberOfElements, (0014,4012), US, 1,  */
    extern const tag NumberOfElements;
    /** NumberOfEnergyWindows, (0054,0011), US, 1,  */
    extern const tag NumberOfEnergyWindows;
    /** NumberOfEventTimers, (0008,2129), IS, 1,  */
    extern const tag NumberOfEventTimers;
    /** NumberOfFilms, (2100,0170), IS, 1,  */
    extern const tag NumberOfFilms;
    /** NumberOfFocalPlanes, (0048,0013), US, 1,  */
    extern const tag NumberOfFocalPlanes;
    /** NumberOfFractionPatternDigitsPerDay, (300A,0079), IS, 1,  */
    extern const tag NumberOfFractionPatternDigitsPerDay;
    /** NumberOfFractionsDelivered, (3008,005A), IS, 1,  */
    extern const tag NumberOfFractionsDelivered;
    /** NumberOfFractionsPlanned, (300A,0078), IS, 1,  */
    extern const tag NumberOfFractionsPlanned;
    /** NumberOfFrames, (0028,0008), IS, 1,  */
    extern const tag NumberOfFrames;
    /** NumberOfFramesInOverlay, (60XX,0015), IS, 1,  */
    extern const range_tag NumberOfFramesInOverlay;
    /** NumberOfFramesInPhase, (0054,0033), US, 1,  */
    extern const tag NumberOfFramesInPhase;
    /** NumberOfFramesInRotation, (0054,0053), US, 1,  */
    extern const tag NumberOfFramesInRotation;
    /** NumberOfFramesIntegrated, (0014,3012), DS, 1,  */
    extern const tag NumberOfFramesIntegrated;
    /** NumberOfFramesUsedForIntegration, (0014,3073), DS, 1,  */
    extern const tag NumberOfFramesUsedForIntegration;
    /** NumberOfGraphicPoints, (0070,0021), US, 1,  */
    extern const tag NumberOfGraphicPoints;
    /** NumberOfHorizontalPixels, (0072,0106), US, 1,  */
    extern const tag NumberOfHorizontalPixels;
    /** NumberOfIterations, (0018,9739), US, 1,  */
    extern const tag NumberOfIterations;
    /** NumberOfKSpaceTrajectories, (0018,9093), US, 1,  */
    extern const tag NumberOfKSpaceTrajectories;
    /** NumberOfLateralSpreadingDevices, (300A,0330), IS, 1,  */
    extern const tag NumberOfLateralSpreadingDevices;
    /** NumberOfLeafJawPairs, (300A,00BC), IS, 1,  */
    extern const tag NumberOfLeafJawPairs;
    /** NumberOfPaddedAlines, (0052,0038), US, 1,  */
    extern const tag NumberOfPaddedAlines;
    /** NumberOfPaintings, (300A,039A), IS, 1,  */
    extern const tag NumberOfPaintings;
    /** NumberOfPatientRelatedInstances, (0020,1204), IS, 1,  */
    extern const tag NumberOfPatientRelatedInstances;
    /** NumberOfPatientRelatedSeries, (0020,1202), IS, 1,  */
    extern const tag NumberOfPatientRelatedSeries;
    /** NumberOfPatientRelatedStudies, (0020,1200), IS, 1,  */
    extern const tag NumberOfPatientRelatedStudies;
    /** NumberOfPhaseEncodingSteps, (0018,0089), IS, 1,  */
    extern const tag NumberOfPhaseEncodingSteps;
    /** NumberOfPhases, (0054,0031), US, 1,  */
    extern const tag NumberOfPhases;
    /** NumberOfPoints, (50XX,0010), US, 1, RET */
    extern const range_tag NumberOfPoints;
    /** NumberOfPriorsReferenced, (0072,0014), US, 1,  */
    extern const tag NumberOfPriorsReferenced;
    /** NumberOfPulses, (300A,028A), IS, 1,  */
    extern const tag NumberOfPulses;
    /** NumberOfRangeModulators, (300A,0340), IS, 1,  */
    extern const tag NumberOfRangeModulators;
    /** NumberOfRangeShifters, (300A,0312), IS, 1,  */
    extern const tag NumberOfRangeShifters;
    /** NumberOfReferences, (0004,1600), UL, 1, RET */
    extern const tag NumberOfReferences;
    /** NumberOfRotations, (0054,0051), US, 1,  */
    extern const tag NumberOfRotations;
    /** NumberOfRRIntervals, (0054,0061), US, 1,  */
    extern const tag NumberOfRRIntervals;
    /** NumberOfSamples, (50XX,2006), UL, 1, RET */
    extern const range_tag NumberOfSamples;
    /** NumberOfScanSpotPositions, (300A,0392), IS, 1,  */
    extern const tag NumberOfScanSpotPositions;
    /** NumberOfScreens, (0072,0100), US, 1,  */
    extern const tag NumberOfScreens;
    /** NumberOfSeriesRelatedInstances, (0020,1209), IS, 1,  */
    extern const tag NumberOfSeriesRelatedInstances;
    /** NumberOfSlices, (0054,0081), US, 1,  */
    extern const tag NumberOfSlices;
    /** NumberOfStages, (0008,2124), IS, 1,  */
    extern const tag NumberOfStages;
    /** NumberOfStudyRelatedInstances, (0020,1208), IS, 1,  */
    extern const tag NumberOfStudyRelatedInstances;
    /** NumberOfStudyRelatedSeries, (0020,1206), IS, 1,  */
    extern const tag NumberOfStudyRelatedSeries;
    /** NumberOfSubsets, (0018,9740), US, 1,  */
    extern const tag NumberOfSubsets;
    /** NumberOfSurfacePoints, (0066,0015), UL, 1,  */
    extern const tag NumberOfSurfacePoints;
    /** NumberOfSurfaces, (0066,0001), UL, 1,  */
    extern const tag NumberOfSurfaces;
    /** NumberOfTableBreakPoints, (0018,6050), UL, 1,  */
    extern const tag NumberOfTableBreakPoints;
    /** NumberOfTableEntries, (0018,6056), UL, 1,  */
    extern const tag NumberOfTableEntries;
    /** NumberOfTables, (0028,08X2), US, 1, RET */
    extern const range_tag NumberOfTables;
    /** NumberOfTemporalPositions, (0020,0105), IS, 1,  */
    extern const tag NumberOfTemporalPositions;
    /** NumberOfTimeSlices, (0054,0101), US, 1,  */
    extern const tag NumberOfTimeSlices;
    /** NumberOfTimeSlots, (0054,0071), US, 1,  */
    extern const tag NumberOfTimeSlots;
    /** NumberOfTomosynthesisSourceImages, (0018,1495), IS, 1,  */
    extern const tag NumberOfTomosynthesisSourceImages;
    /** NumberOfTotalObjects, (4010,1033), US, 1,  */
    extern const tag NumberOfTotalObjects;
    /** NumberOfTransformSteps, (0028,0402), US, 1, RET */
    extern const tag NumberOfTransformSteps;
    /** NumberOfTriggersInPhase, (0054,0211), US, 1,  */
    extern const tag NumberOfTriggersInPhase;
    /** NumberOfVectors, (0066,001E), UL, 1,  */
    extern const tag NumberOfVectors;
    /** NumberOfVerticalPixels, (0072,0104), US, 1,  */
    extern const tag NumberOfVerticalPixels;
    /** NumberOfViewsInStage, (0008,212A), IS, 1,  */
    extern const tag NumberOfViewsInStage;
    /** NumberOfVisualStimuli, (0024,0038), US, 1,  */
    extern const tag NumberOfVisualStimuli;
    /** NumberOfWaveformChannels, (003A,0005), US, 1,  */
    extern const tag NumberOfWaveformChannels;
    /** NumberOfWaveformSamples, (003A,0010), UL, 1,  */
    extern const tag NumberOfWaveformSamples;
    /** NumberOfWedges, (300A,00D0), IS, 1,  */
    extern const tag NumberOfWedges;
    /** NumberOfZeroFills, (0018,9066), US, 1-2,  */
    extern const tag NumberOfZeroFills;
    /** NumericValue, (0040,A30A), DS, 1-n,  */
    extern const tag NumericValue;
    /** NumericValueQualifierCodeSequence, (0040,A301), SQ, 1,  */
    extern const tag NumericValueQualifierCodeSequence;
    /** ObjectBinaryIdentifierTrial, (0040,A074), OB, 1, RET */
    extern const tag ObjectBinaryIdentifierTrial;
    /** ObjectDirectoryBinaryIdentifierTrial, (0040,A089), OB, 1, RET */
    extern const tag ObjectDirectoryBinaryIdentifierTrial;
    /** ObjectiveLensNumericalAperture, (0048,0113), DS, 1,  */
    extern const tag ObjectiveLensNumericalAperture;
    /** ObjectiveLensPower, (0048,0112), DS, 1,  */
    extern const tag ObjectiveLensPower;
    /** ObjectPixelSpacingInCenterOfBeam, (0018,9404), FL, 2,  */
    extern const tag ObjectPixelSpacingInCenterOfBeam;
    /** ObjectThicknessSequence, (0018,9456), SQ, 1,  */
    extern const tag ObjectThicknessSequence;
    /** ObservationCategoryCodeSequenceTrial, (0040,A167), SQ, 1, RET */
    extern const tag ObservationCategoryCodeSequenceTrial;
    /** ObservationDateTime, (0040,A032), DT, 1,  */
    extern const tag ObservationDateTime;
    /** ObservationDateTrial, (0040,A192), DA, 1, RET */
    extern const tag ObservationDateTrial;
    /** ObservationNumber, (3006,0082), IS, 1,  */
    extern const tag ObservationNumber;
    /** ObservationSubjectClassTrial, (0040,A403), CS, 1, RET */
    extern const tag ObservationSubjectClassTrial;
    /** ObservationSubjectContextFlagTrial, (0040,A600), CS, 1, RET */
    extern const tag ObservationSubjectContextFlagTrial;
    /** ObservationSubjectTypeCodeSequenceTrial, (0040,A404), SQ, 1, RET */
    extern const tag ObservationSubjectTypeCodeSequenceTrial;
    /** ObservationSubjectUIDTrial, (0040,A402), UI, 1, RET */
    extern const tag ObservationSubjectUIDTrial;
    /** ObservationTimeTrial, (0040,A193), TM, 1, RET */
    extern const tag ObservationTimeTrial;
    /** ObservationUIDTrial, (0040,A171), UI, 1, RET */
    extern const tag ObservationUIDTrial;
    /** ObserverContextFlagTrial, (0040,A601), CS, 1, RET */
    extern const tag ObserverContextFlagTrial;
    /** ObserverType, (0040,A084), CS, 1,  */
    extern const tag ObserverType;
    /** Occupation, (0010,2180), SH, 1,  */
    extern const tag Occupation;
    /** OCTAcquisitionDomain, (0052,0006), CS, 1,  */
    extern const tag OCTAcquisitionDomain;
    /** OCTFocalDistance, (0052,0002), FD, 1,  */
    extern const tag OCTFocalDistance;
    /** OCTOpticalCenterWavelength, (0052,0007), FD, 1,  */
    extern const tag OCTOpticalCenterWavelength;
    /** OCTZOffsetApplied, (0052,0026), CS, 1,  */
    extern const tag OCTZOffsetApplied;
    /** OCTZOffsetCorrection, (0052,0030), SS, 1,  */
    extern const tag OCTZOffsetCorrection;
    /** OffsetOfReferencedLowerLevelDirectoryEntity, (0004,1420), UL, 1,  */
    extern const tag OffsetOfReferencedLowerLevelDirectoryEntity;
    /** OffsetOfTheFirstDirectoryRecordOfTheRootDirectoryEntity, (0004,1200), UL, 1,  */
    extern const tag OffsetOfTheFirstDirectoryRecordOfTheRootDirectoryEntity;
    /** OffsetOfTheLastDirectoryRecordOfTheRootDirectoryEntity, (0004,1202), UL, 1,  */
    extern const tag OffsetOfTheLastDirectoryRecordOfTheRootDirectoryEntity;
    /** OffsetOfTheNextDirectoryRecord, (0004,1400), UL, 1,  */
    extern const tag OffsetOfTheNextDirectoryRecord;
    /** OnAxisBackgroundAnatomicStructureCodeSequenceTrial, (0008,225C), SQ, 1, RET */
    extern const tag OnAxisBackgroundAnatomicStructureCodeSequenceTrial;
    /** OOIOwnerCreationTime, (4010,1041), DT, 1,  */
    extern const tag OOIOwnerCreationTime;
    /** OOIOwnerSequence, (4010,1047), SQ, 1,  */
    extern const tag OOIOwnerSequence;
    /** OOIOwnerType, (4010,1009), CS, 1,  */
    extern const tag OOIOwnerType;
    /** OOISize, (4010,1043), FL, 3,  */
    extern const tag OOISize;
    /** OOIType, (4010,1042), CS, 1,  */
    extern const tag OOIType;
    /** OOITypeDescriptor, (4010,1068), LT, 1,  */
    extern const tag OOITypeDescriptor;
    /** OperatingMode, (0018,9178), CS, 1,  */
    extern const tag OperatingMode;
    /** OperatingModeSequence, (0018,9176), SQ, 1,  */
    extern const tag OperatingModeSequence;
    /** OperatingModeType, (0018,9177), CS, 1,  */
    extern const tag OperatingModeType;
    /** OperatorIdentificationSequence, (0008,1072), SQ, 1,  */
    extern const tag OperatorIdentificationSequence;
    /** OperatorsName, (0008,1070), PN, 1-n,  */
    extern const tag OperatorsName;
    /** OphthalmicAxialLength, (0022,1019), FL, 1,  */
    extern const tag OphthalmicAxialLength;
    /** OphthalmicAxialLengthAcquisitionMethodCodeSequence, (0022,1153), SQ, 1,  */
    extern const tag OphthalmicAxialLengthAcquisitionMethodCodeSequence;
    /** OphthalmicAxialLengthDataSourceCodeSequence, (0022,1150), SQ, 1,  */
    extern const tag OphthalmicAxialLengthDataSourceCodeSequence;
    /** OphthalmicAxialLengthDataSourceDescription, (0022,1159), LO, 1,  */
    extern const tag OphthalmicAxialLengthDataSourceDescription;
    /** OphthalmicAxialLengthMeasurementModified, (0022,1140), CS, 1,  */
    extern const tag OphthalmicAxialLengthMeasurementModified;
    /** OphthalmicAxialLengthMeasurementsLengthSummationSequence, (0022,1212), SQ, 1,  */
    extern const tag OphthalmicAxialLengthMeasurementsLengthSummationSequence;
    /** OphthalmicAxialLengthMeasurementsSegmentalLengthSequence, (0022,1211), SQ, 1,  */
    extern const tag OphthalmicAxialLengthMeasurementsSegmentalLengthSequence;
    /** OphthalmicAxialLengthMeasurementsSegmentNameCodeSequence, (0022,1101), SQ, 1,  */
    extern const tag OphthalmicAxialLengthMeasurementsSegmentNameCodeSequence;
    /** OphthalmicAxialLengthMeasurementsSequence, (0022,1050), SQ, 1,  */
    extern const tag OphthalmicAxialLengthMeasurementsSequence;
    /** OphthalmicAxialLengthMeasurementsTotalLengthSequence, (0022,1210), SQ, 1,  */
    extern const tag OphthalmicAxialLengthMeasurementsTotalLengthSequence;
    /** OphthalmicAxialLengthMeasurementsType, (0022,1010), CS, 1,  */
    extern const tag OphthalmicAxialLengthMeasurementsType;
    /** OphthalmicAxialLengthQualityMetricSequence, (0022,1262), SQ, 1,  */
    extern const tag OphthalmicAxialLengthQualityMetricSequence;
    /** OphthalmicAxialLengthQualityMetricTypeDescription, (0022,1273), LO, 1,  */
    extern const tag OphthalmicAxialLengthQualityMetricTypeDescription;
    /** OphthalmicAxialLengthSelectionMethodCodeSequence, (0022,1250), SQ, 1,  */
    extern const tag OphthalmicAxialLengthSelectionMethodCodeSequence;
    /** OphthalmicAxialLengthSequence, (0022,1012), SQ, 1,  */
    extern const tag OphthalmicAxialLengthSequence;
    /** OphthalmicAxialLengthVelocity, (0022,1059), FL, 1,  */
    extern const tag OphthalmicAxialLengthVelocity;
    /** OphthalmicAxialMeasurementsDeviceType, (0022,1009), CS, 1,  */
    extern const tag OphthalmicAxialMeasurementsDeviceType;
    /** OphthalmicAxialMeasurementsLeftEyeSequence, (0022,1008), SQ, 1,  */
    extern const tag OphthalmicAxialMeasurementsLeftEyeSequence;
    /** OphthalmicAxialMeasurementsRightEyeSequence, (0022,1007), SQ, 1,  */
    extern const tag OphthalmicAxialMeasurementsRightEyeSequence;
    /** OphthalmicFrameLocationSequence, (0022,0031), SQ, 1,  */
    extern const tag OphthalmicFrameLocationSequence;
    /** OphthalmicImageOrientation, (0022,0039), CS, 1,  */
    extern const tag OphthalmicImageOrientation;
    /** OphthalmicPatientClinicalInformationLeftEyeSequence, (0024,0114), SQ, 1,  */
    extern const tag OphthalmicPatientClinicalInformationLeftEyeSequence;
    /** OphthalmicPatientClinicalInformationRightEyeSequence, (0024,0115), SQ, 1,  */
    extern const tag OphthalmicPatientClinicalInformationRightEyeSequence;
    /** OphthalmicUltrasoundAxialMeasurementsTypeCodeSequence, (0022,1044), SQ, 1,  */
    extern const tag OphthalmicUltrasoundAxialMeasurementsTypeCodeSequence;
    /** OpticalOphthalmicAxialLengthMeasurementsSequence, (0022,1225), SQ, 1,  */
    extern const tag OpticalOphthalmicAxialLengthMeasurementsSequence;
    /** OpticalPathDescription, (0048,0107), ST, 1,  */
    extern const tag OpticalPathDescription;
    /** OpticalPathIdentificationSequence, (0048,0207), SQ, 1,  */
    extern const tag OpticalPathIdentificationSequence;
    /** OpticalPathIdentifier, (0048,0106), SH, 1,  */
    extern const tag OpticalPathIdentifier;
    /** OpticalPathSequence, (0048,0105), SQ, 1,  */
    extern const tag OpticalPathSequence;
    /** OpticalSelectedOphthalmicAxialLengthSequence, (0022,1255), SQ, 1,  */
    extern const tag OpticalSelectedOphthalmicAxialLengthSequence;
    /** OpticalTransmittance, (0046,0040), FD, 1,  */
    extern const tag OpticalTransmittance;
    /** Optotype, (0046,0094), CS, 1,  */
    extern const tag Optotype;
    /** OptotypeDetailedDefinition, (0046,0139), LO, 1,  */
    extern const tag OptotypeDetailedDefinition;
    /** OptotypePresentation, (0046,0095), CS, 1,  */
    extern const tag OptotypePresentation;
    /** OrderCallbackPhoneNumber, (0040,2010), SH, 1,  */
    extern const tag OrderCallbackPhoneNumber;
    /** OrderEnteredBy, (0040,2008), PN, 1,  */
    extern const tag OrderEnteredBy;
    /** OrderEntererLocation, (0040,2009), SH, 1,  */
    extern const tag OrderEntererLocation;
    /** OrderFillerIdentifierSequence, (0040,0027), SQ, 1,  */
    extern const tag OrderFillerIdentifierSequence;
    /** OrderPlacerIdentifierSequence, (0040,0026), SQ, 1,  */
    extern const tag OrderPlacerIdentifierSequence;
    /** OrganAtRiskFullVolumeDose, (300A,002A), DS, 1,  */
    extern const tag OrganAtRiskFullVolumeDose;
    /** OrganAtRiskLimitDose, (300A,002B), DS, 1,  */
    extern const tag OrganAtRiskLimitDose;
    /** OrganAtRiskMaximumDose, (300A,002C), DS, 1,  */
    extern const tag OrganAtRiskMaximumDose;
    /** OrganAtRiskOverdoseVolumeFraction, (300A,002D), DS, 1,  */
    extern const tag OrganAtRiskOverdoseVolumeFraction;
    /** OrganDose, (0040,0316), DS, 1,  */
    extern const tag OrganDose;
    /** OrganExposed, (0040,0318), CS, 1,  */
    extern const tag OrganExposed;
    /** OriginalAttributesSequence, (0400,0561), SQ, 1,  */
    extern const tag OriginalAttributesSequence;
    /** OriginalImageIdentification, (0020,5000), AT, 1-n, RET */
    extern const tag OriginalImageIdentification;
    /** OriginalImageIdentificationNomenclature, (0020,5002), LO, 1-n, RET */
    extern const tag OriginalImageIdentificationNomenclature;
    /** OriginalImageSequence, (2130,00C0), SQ, 1, RET */
    extern const tag OriginalImageSequence;
    /** OriginalImplantAssemblyTemplateSequence, (0076,000C), SQ, 1,  */
    extern const tag OriginalImplantAssemblyTemplateSequence;
    /** OriginalImplantTemplateSequence, (0068,6225), SQ, 1,  */
    extern const tag OriginalImplantTemplateSequence;
    /** OriginalSpecializedSOPClassUID, (0008,001B), UI, 1,  */
    extern const tag OriginalSpecializedSOPClassUID;
    /** Originator, (2100,0070), AE, 1,  */
    extern const tag Originator;
    /** OtherMagnificationTypesAvailable, (2010,00A7), CS, 1-n,  */
    extern const tag OtherMagnificationTypesAvailable;
    /** OtherMediaAvailableSequence, (2000,00A4), SQ, 1,  */
    extern const tag OtherMediaAvailableSequence;
    /** OtherPatientIDs, (0010,1000), LO, 1-n,  */
    extern const tag OtherPatientIDs;
    /** OtherPatientIDsSequence, (0010,1002), SQ, 1,  */
    extern const tag OtherPatientIDsSequence;
    /** OtherPatientNames, (0010,1001), PN, 1-n,  */
    extern const tag OtherPatientNames;
    /** OtherPupillaryDistance, (0046,0064), FD, 1,  */
    extern const tag OtherPupillaryDistance;
    /** OtherSmoothingTypesAvailable, (2010,00A9), CS, 1-n,  */
    extern const tag OtherSmoothingTypesAvailable;
    /** OtherStudyNumbers, (0020,1070), IS, 1-n, RET */
    extern const tag OtherStudyNumbers;
    /** OuterDiameter, (0014,0054), DS, 1,  */
    extern const tag OuterDiameter;
    /** OutputInformationSequence, (0040,4033), SQ, 1,  */
    extern const tag OutputInformationSequence;
    /** OutputPower, (0018,5000), SH, 1-n,  */
    extern const tag OutputPower;
    /** OverallTemplateSpatialTolerance, (0068,62A5), FD, 1,  */
    extern const tag OverallTemplateSpatialTolerance;
    /** OverlayActivationLayer, (60XX,1001), CS, 1,  */
    extern const range_tag OverlayActivationLayer;
    /** OverlayBackgroundDensity, (2040,0082), CS, 1, RET */
    extern const tag OverlayBackgroundDensity;
    /** OverlayBitPosition, (60XX,0102), US, 1,  */
    extern const range_tag OverlayBitPosition;
    /** OverlayBitsAllocated, (60XX,0100), US, 1,  */
    extern const range_tag OverlayBitsAllocated;
    /** OverlayBitsForCodeWord, (60XX,0804), US, 1, RET */
    extern const range_tag OverlayBitsForCodeWord;
    /** OverlayBitsGrouped, (60XX,0069), US, 1, RET */
    extern const range_tag OverlayBitsGrouped;
    /** OverlayCodeLabel, (60XX,0800), CS, 1-n, RET */
    extern const range_tag OverlayCodeLabel;
    /** OverlayCodeTableLocation, (60XX,0803), AT, 1-n, RET */
    extern const range_tag OverlayCodeTableLocation;
    /** OverlayColumns, (60XX,0011), US, 1,  */
    extern const range_tag OverlayColumns;
    /** OverlayComments, (60XX,4000), LT, 1, RET */
    extern const range_tag OverlayComments;
    /** OverlayCompressionCode, (60XX,0060), CS, 1, RET */
    extern const range_tag OverlayCompressionCode;
    /** OverlayCompressionDescription, (60XX,0063), CS, 1, RET */
    extern const range_tag OverlayCompressionDescription;
    /** OverlayCompressionLabel, (60XX,0062), SH, 1, RET */
    extern const range_tag OverlayCompressionLabel;
    /** OverlayCompressionOriginator, (60XX,0061), SH, 1, RET */
    extern const range_tag OverlayCompressionOriginator;
    /** OverlayCompressionStepPointers, (60XX,0066), AT, 1-n, RET */
    extern const range_tag OverlayCompressionStepPointers;
    /** OverlayData, (60XX,3000), OB or OW, 1,  */
    extern const range_tag OverlayData;
    /** OverlayDate, (0008,0024), DA, 1, RET */
    extern const tag OverlayDate;
    /** OverlayDescription, (60XX,0022), LO, 1,  */
    extern const range_tag OverlayDescription;
    /** OverlayDescriptorBlue, (60XX,1103), US, 1, RET */
    extern const range_tag OverlayDescriptorBlue;
    /** OverlayDescriptorGray, (60XX,1100), US, 1, RET */
    extern const range_tag OverlayDescriptorGray;
    /** OverlayDescriptorGreen, (60XX,1102), US, 1, RET */
    extern const range_tag OverlayDescriptorGreen;
    /** OverlayDescriptorRed, (60XX,1101), US, 1, RET */
    extern const range_tag OverlayDescriptorRed;
    /** OverlayForegroundDensity, (2040,0080), CS, 1, RET */
    extern const tag OverlayForegroundDensity;
    /** OverlayFormat, (60XX,0110), CS, 1, RET */
    extern const range_tag OverlayFormat;
    /** OverlayLabel, (60XX,1500), LO, 1,  */
    extern const range_tag OverlayLabel;
    /** OverlayLocation, (60XX,0200), US, 1, RET */
    extern const range_tag OverlayLocation;
    /** OverlayMagnificationType, (2040,0060), CS, 1, RET */
    extern const tag OverlayMagnificationType;
    /** OverlayMode, (2040,0090), CS, 1, RET */
    extern const tag OverlayMode;
    /** OverlayNumber, (0020,0022), IS, 1, RET */
    extern const tag OverlayNumber;
    /** OverlayNumberOfTables, (60XX,0802), US, 1, RET */
    extern const range_tag OverlayNumberOfTables;
    /** OverlayOrigin, (60XX,0050), SS, 2,  */
    extern const range_tag OverlayOrigin;
    /** OverlayOrImageMagnification, (2040,0072), CS, 1, RET */
    extern const tag OverlayOrImageMagnification;
    /** OverlayPixelDataSequence, (2040,0020), SQ, 1, RET */
    extern const tag OverlayPixelDataSequence;
    /** OverlayPlaneOrigin, (60XX,0052), US, 1, RET */
    extern const range_tag OverlayPlaneOrigin;
    /** OverlayPlanes, (60XX,0012), US, 1, RET */
    extern const range_tag OverlayPlanes;
    /** OverlayRepeatInterval, (60XX,0068), US, 1, RET */
    extern const range_tag OverlayRepeatInterval;
    /** OverlayRows, (60XX,0010), US, 1,  */
    extern const range_tag OverlayRows;
    /** OverlaysBlue, (60XX,1203), US, 1-n, RET */
    extern const range_tag OverlaysBlue;
    /** OverlaysGray, (60XX,1200), US, 1-n, RET */
    extern const range_tag OverlaysGray;
    /** OverlaysGreen, (60XX,1202), US, 1-n, RET */
    extern const range_tag OverlaysGreen;
    /** OverlaySmoothingType, (2040,0070), CS, 1, RET */
    extern const tag OverlaySmoothingType;
    /** OverlaysRed, (60XX,1201), US, 1-n, RET */
    extern const range_tag OverlaysRed;
    /** OverlaySubtype, (60XX,0045), LO, 1,  */
    extern const range_tag OverlaySubtype;
    /** OverlayTime, (0008,0034), TM, 1, RET */
    extern const tag OverlayTime;
    /** OverlayType, (60XX,0040), CS, 1,  */
    extern const range_tag OverlayType;
    /** OverriddenAttributesSequence, (0074,104A), SQ, 1,  */
    extern const tag OverriddenAttributesSequence;
    /** OverrideParameterPointer, (3008,0062), AT, 1,  */
    extern const tag OverrideParameterPointer;
    /** OverrideReason, (3008,0066), ST, 1,  */
    extern const tag OverrideReason;
    /** OverrideSequence, (3008,0060), SQ, 1,  */
    extern const tag OverrideSequence;
    /** OversamplingPhase, (0018,9029), CS, 1,  */
    extern const tag OversamplingPhase;
    /** OwnerID, (2100,0160), SH, 1,  */
    extern const tag OwnerID;
    /** PageNumberVector, (0018,2001), IS, 1-n,  */
    extern const tag PageNumberVector;
    /** PaletteColorLookupTableSequence, (0048,0120), SQ, 1,  */
    extern const tag PaletteColorLookupTableSequence;
    /** PaletteColorLookupTableUID, (0028,1199), UI, 1,  */
    extern const tag PaletteColorLookupTableUID;
    /** ParallelAcquisition, (0018,9077), CS, 1,  */
    extern const tag ParallelAcquisition;
    /** ParallelAcquisitionTechnique, (0018,9078), CS, 1,  */
    extern const tag ParallelAcquisitionTechnique;
    /** ParallelReductionFactorInPlane, (0018,9069), FD, 1,  */
    extern const tag ParallelReductionFactorInPlane;
    /** ParallelReductionFactorInPlaneRetired, (0018,9096), FD, 1, RET */
    extern const tag ParallelReductionFactorInPlaneRetired;
    /** ParallelReductionFactorOutOfPlane, (0018,9155), FD, 1,  */
    extern const tag ParallelReductionFactorOutOfPlane;
    /** ParallelReductionFactorSecondInPlane, (0018,9168), FD, 1,  */
    extern const tag ParallelReductionFactorSecondInPlane;
    /** ParameterItemIndex, (3008,0063), IS, 1,  */
    extern const tag ParameterItemIndex;
    /** ParameterPointer, (3008,0065), AT, 1,  */
    extern const tag ParameterPointer;
    /** ParameterSequencePointer, (3008,0061), AT, 1,  */
    extern const tag ParameterSequencePointer;
    /** PartialDataDisplayHandling, (0072,0208), CS, 1,  */
    extern const tag PartialDataDisplayHandling;
    /** PartialFourier, (0018,9081), CS, 1,  */
    extern const tag PartialFourier;
    /** PartialFourierDirection, (0018,9036), CS, 1,  */
    extern const tag PartialFourierDirection;
    /** PartialView, (0028,1350), CS, 1,  */
    extern const tag PartialView;
    /** PartialViewCodeSequence, (0028,1352), SQ, 1,  */
    extern const tag PartialViewCodeSequence;
    /** PartialViewDescription, (0028,1351), ST, 1,  */
    extern const tag PartialViewDescription;
    /** ParticipantSequence, (0040,A07A), SQ, 1,  */
    extern const tag ParticipantSequence;
    /** ParticipationDateTime, (0040,A082), DT, 1,  */
    extern const tag ParticipationDateTime;
    /** ParticipationType, (0040,A080), CS, 1,  */
    extern const tag ParticipationType;
    /** PatientAdditionalPosition, (300A,0184), LO, 1,  */
    extern const tag PatientAdditionalPosition;
    /** PatientAddress, (0010,1040), LO, 1,  */
    extern const tag PatientAddress;
    /** PatientAge, (0010,1010), AS, 1,  */
    extern const tag PatientAge;
    /** PatientBirthDate, (0010,0030), DA, 1,  */
    extern const tag PatientBirthDate;
    /** PatientBirthName, (0010,1005), PN, 1,  */
    extern const tag PatientBirthName;
    /** PatientBirthTime, (0010,0032), TM, 1,  */
    extern const tag PatientBirthTime;
    /** PatientBreedCodeSequence, (0010,2293), SQ, 1,  */
    extern const tag PatientBreedCodeSequence;
    /** PatientBreedDescription, (0010,2292), LO, 1,  */
    extern const tag PatientBreedDescription;
    /** PatientClinicalTrialParticipationSequence, (0038,0502), SQ, 1,  */
    extern const tag PatientClinicalTrialParticipationSequence;
    /** PatientComments, (0010,4000), LT, 1,  */
    extern const tag PatientComments;
    /** PatientEyeMovementCommandCodeSequence, (0022,0006), SQ, 1,  */
    extern const tag PatientEyeMovementCommandCodeSequence;
    /** PatientEyeMovementCommanded, (0022,0005), CS, 1,  */
    extern const tag PatientEyeMovementCommanded;
    /** PatientFrameOfReferenceSource, (0020,930C), CS, 1,  */
    extern const tag PatientFrameOfReferenceSource;
    /** PatientGantryRelationshipCodeSequence, (0054,0414), SQ, 1,  */
    extern const tag PatientGantryRelationshipCodeSequence;
    /** PatientID, (0010,0020), LO, 1,  */
    extern const tag PatientID;
    /** PatientIdentityRemoved, (0012,0062), CS, 1,  */
    extern const tag PatientIdentityRemoved;
    /** PatientInstitutionResidence, (0038,0400), LO, 1,  */
    extern const tag PatientInstitutionResidence;
    /** PatientInsurancePlanCodeSequence, (0010,0050), SQ, 1,  */
    extern const tag PatientInsurancePlanCodeSequence;
    /** PatientMotherBirthName, (0010,1060), PN, 1,  */
    extern const tag PatientMotherBirthName;
    /** PatientMotionCorrected, (0018,9763), CS, 1,  */
    extern const tag PatientMotionCorrected;
    /** PatientName, (0010,0010), PN, 1,  */
    extern const tag PatientName;
    /** PatientNotProperlyFixatedQuantity, (0024,0036), US, 1,  */
    extern const tag PatientNotProperlyFixatedQuantity;
    /** PatientOrientation, (0020,0020), CS, 2,  */
    extern const tag PatientOrientation;
    /** PatientOrientationCodeSequence, (0054,0410), SQ, 1,  */
    extern const tag PatientOrientationCodeSequence;
    /** PatientOrientationInFrameSequence, (0020,9450), SQ, 1,  */
    extern const tag PatientOrientationInFrameSequence;
    /** PatientOrientationModifierCodeSequence, (0054,0412), SQ, 1,  */
    extern const tag PatientOrientationModifierCodeSequence;
    /** PatientPhysiologicalStateCodeSequence, (0018,9772), SQ, 1,  */
    extern const tag PatientPhysiologicalStateCodeSequence;
    /** PatientPhysiologicalStateSequence, (0018,9771), SQ, 1,  */
    extern const tag PatientPhysiologicalStateSequence;
    /** PatientPosition, (0018,5100), CS, 1,  */
    extern const tag PatientPosition;
    /** PatientPrimaryLanguageCodeSequence, (0010,0101), SQ, 1,  */
    extern const tag PatientPrimaryLanguageCodeSequence;
    /** PatientPrimaryLanguageModifierCodeSequence, (0010,0102), SQ, 1,  */
    extern const tag PatientPrimaryLanguageModifierCodeSequence;
    /** PatientReliabilityIndicator, (0024,0069), LO, 1,  */
    extern const tag PatientReliabilityIndicator;
    /** PatientReligiousPreference, (0010,21F0), LO, 1,  */
    extern const tag PatientReligiousPreference;
    /** PatientSetupLabel, (300A,0183), LO, 1,  */
    extern const tag PatientSetupLabel;
    /** PatientSetupNumber, (300A,0182), IS, 1,  */
    extern const tag PatientSetupNumber;
    /** PatientSetupSequence, (300A,0180), SQ, 1,  */
    extern const tag PatientSetupSequence;
    /** PatientSex, (0010,0040), CS, 1,  */
    extern const tag PatientSex;
    /** PatientSexNeutered, (0010,2203), CS, 1,  */
    extern const tag PatientSexNeutered;
    /** PatientSize, (0010,1020), DS, 1,  */
    extern const tag PatientSize;
    /** PatientSizeCodeSequence, (0010,1021), SQ, 1,  */
    extern const tag PatientSizeCodeSequence;
    /** PatientSpeciesCodeSequence, (0010,2202), SQ, 1,  */
    extern const tag PatientSpeciesCodeSequence;
    /** PatientSpeciesDescription, (0010,2201), LO, 1,  */
    extern const tag PatientSpeciesDescription;
    /** PatientState, (0038,0500), LO, 1,  */
    extern const tag PatientState;
    /** PatientSupportAccessoryCode, (300A,0354), LO, 1,  */
    extern const tag PatientSupportAccessoryCode;
    /** PatientSupportAdjustedAngle, (0074,102A), FD, 1,  */
    extern const tag PatientSupportAdjustedAngle;
    /** PatientSupportAngle, (300A,0122), DS, 1,  */
    extern const tag PatientSupportAngle;
    /** PatientSupportAngleTolerance, (300A,004C), DS, 1,  */
    extern const tag PatientSupportAngleTolerance;
    /** PatientSupportID, (300A,0352), SH, 1,  */
    extern const tag PatientSupportID;
    /** PatientSupportRotationDirection, (300A,0123), CS, 1,  */
    extern const tag PatientSupportRotationDirection;
    /** PatientSupportType, (300A,0350), CS, 1,  */
    extern const tag PatientSupportType;
    /** PatientTelephoneNumbers, (0010,2154), SH, 1-n,  */
    extern const tag PatientTelephoneNumbers;
    /** PatientTransportArrangements, (0040,1004), LO, 1,  */
    extern const tag PatientTransportArrangements;
    /** PatientWeight, (0010,1030), DS, 1,  */
    extern const tag PatientWeight;
    /** PatternOffColorCIELabValue, (0070,0252), US, 3,  */
    extern const tag PatternOffColorCIELabValue;
    /** PatternOffOpacity, (0070,0285), FL, 1,  */
    extern const tag PatternOffOpacity;
    /** PatternOnColorCIELabValue, (0070,0251), US, 3,  */
    extern const tag PatternOnColorCIELabValue;
    /** PatternOnOpacity, (0070,0284), FL, 1,  */
    extern const tag PatternOnOpacity;
    /** PauseBetweenFrames, (0054,0038), IS, 1,  */
    extern const tag PauseBetweenFrames;
    /** PercentPhaseFieldOfView, (0018,0094), DS, 1,  */
    extern const tag PercentPhaseFieldOfView;
    /** PercentSampling, (0018,0093), DS, 1,  */
    extern const tag PercentSampling;
    /** PerformedLocation, (0040,0243), SH, 1,  */
    extern const tag PerformedLocation;
    /** PerformedProcedureCodeSequence, (0040,A372), SQ, 1,  */
    extern const tag PerformedProcedureCodeSequence;
    /** PerformedProcedureStepDescription, (0040,0254), LO, 1,  */
    extern const tag PerformedProcedureStepDescription;
    /** PerformedProcedureStepDiscontinuationReasonCodeSequence, (0040,0281), SQ, 1,  */
    extern const tag PerformedProcedureStepDiscontinuationReasonCodeSequence;
    /** PerformedProcedureStepEndDate, (0040,0250), DA, 1,  */
    extern const tag PerformedProcedureStepEndDate;
    /** PerformedProcedureStepEndDateTime, (0040,4051), DT, 1,  */
    extern const tag PerformedProcedureStepEndDateTime;
    /** PerformedProcedureStepEndTime, (0040,0251), TM, 1,  */
    extern const tag PerformedProcedureStepEndTime;
    /** PerformedProcedureStepID, (0040,0253), SH, 1,  */
    extern const tag PerformedProcedureStepID;
    /** PerformedProcedureStepStartDate, (0040,0244), DA, 1,  */
    extern const tag PerformedProcedureStepStartDate;
    /** PerformedProcedureStepStartDateTime, (0040,4050), DT, 1,  */
    extern const tag PerformedProcedureStepStartDateTime;
    /** PerformedProcedureStepStartTime, (0040,0245), TM, 1,  */
    extern const tag PerformedProcedureStepStartTime;
    /** PerformedProcedureStepStatus, (0040,0252), CS, 1,  */
    extern const tag PerformedProcedureStepStatus;
    /** PerformedProcedureTypeDescription, (0040,0255), LO, 1,  */
    extern const tag PerformedProcedureTypeDescription;
    /** PerformedProcessingApplicationsCodeSequence, (0040,4007), SQ, 1,  */
    extern const tag PerformedProcessingApplicationsCodeSequence;
    /** PerformedProcessingParametersSequence, (0074,1212), SQ, 1,  */
    extern const tag PerformedProcessingParametersSequence;
    /** PerformedProtocolCodeSequence, (0040,0260), SQ, 1,  */
    extern const tag PerformedProtocolCodeSequence;
    /** PerformedProtocolType, (0040,0261), CS, 1,  */
    extern const tag PerformedProtocolType;
    /** PerformedSeriesSequence, (0040,0340), SQ, 1,  */
    extern const tag PerformedSeriesSequence;
    /** PerformedStationAETitle, (0040,0241), AE, 1,  */
    extern const tag PerformedStationAETitle;
    /** PerformedStationClassCodeSequence, (0040,4029), SQ, 1,  */
    extern const tag PerformedStationClassCodeSequence;
    /** PerformedStationGeographicLocationCodeSequence, (0040,4030), SQ, 1,  */
    extern const tag PerformedStationGeographicLocationCodeSequence;
    /** PerformedStationName, (0040,0242), SH, 1,  */
    extern const tag PerformedStationName;
    /** PerformedStationNameCodeSequence, (0040,4028), SQ, 1,  */
    extern const tag PerformedStationNameCodeSequence;
    /** PerformedWorkitemCodeSequence, (0040,4019), SQ, 1,  */
    extern const tag PerformedWorkitemCodeSequence;
    /** PerformingPhysicianIdentificationSequence, (0008,1052), SQ, 1,  */
    extern const tag PerformingPhysicianIdentificationSequence;
    /** PerformingPhysicianName, (0008,1050), PN, 1-n,  */
    extern const tag PerformingPhysicianName;
    /** PerFrameFunctionalGroupsSequence, (5200,9230), SQ, 1,  */
    extern const tag PerFrameFunctionalGroupsSequence;
    /** PerimeterTable, (0028,0070), US, 1-n, RET */
    extern const tag PerimeterTable;
    /** PerimeterValue, (0028,0071), US or SS, 1, RET */
    extern const tag PerimeterValue;
    /** PerProjectionAcquisitionSequence, (0018,9538), SQ, 1,  */
    extern const tag PerProjectionAcquisitionSequence;
    /** PersonAddress, (0040,1102), ST, 1,  */
    extern const tag PersonAddress;
    /** PersonIdentificationCodeSequence, (0040,1101), SQ, 1,  */
    extern const tag PersonIdentificationCodeSequence;
    /** PersonName, (0040,A123), PN, 1,  */
    extern const tag PersonName;
    /** PersonTelephoneNumbers, (0040,1103), LO, 1-n,  */
    extern const tag PersonTelephoneNumbers;
    /** PertinentDocumentsSequence, (0038,0100), SQ, 1,  */
    extern const tag PertinentDocumentsSequence;
    /** PertinentOtherEvidenceSequence, (0040,A385), SQ, 1,  */
    extern const tag PertinentOtherEvidenceSequence;
    /** PETDetectorMotionDetailsSequence, (0018,9733), SQ, 1,  */
    extern const tag PETDetectorMotionDetailsSequence;
    /** PETFrameAcquisitionSequence, (0018,9732), SQ, 1,  */
    extern const tag PETFrameAcquisitionSequence;
    /** PETFrameCorrectionFactorsSequence, (0018,9736), SQ, 1,  */
    extern const tag PETFrameCorrectionFactorsSequence;
    /** PETFrameTypeSequence, (0018,9751), SQ, 1,  */
    extern const tag PETFrameTypeSequence;
    /** PETPositionSequence, (0018,9735), SQ, 1,  */
    extern const tag PETPositionSequence;
    /** PETReconstructionSequence, (0018,9749), SQ, 1,  */
    extern const tag PETReconstructionSequence;
    /** PETTableDynamicsSequence, (0018,9734), SQ, 1,  */
    extern const tag PETTableDynamicsSequence;
    /** PhantomType, (4010,1046), CS, 1,  */
    extern const tag PhantomType;
    /** PhaseContrast, (0018,9014), CS, 1,  */
    extern const tag PhaseContrast;
    /** PhaseDelay, (0054,0036), IS, 1,  */
    extern const tag PhaseDelay;
    /** PhaseDescription, (0054,0039), CS, 1,  */
    extern const tag PhaseDescription;
    /** PhaseInformationSequence, (0054,0032), SQ, 1,  */
    extern const tag PhaseInformationSequence;
    /** PhaseNumber, (0020,0015), IS, 1, RET */
    extern const tag PhaseNumber;
    /** PhaseVector, (0054,0030), US, 1-n,  */
    extern const tag PhaseVector;
    /** PhosphorType, (0018,1261), LO, 1,  */
    extern const tag PhosphorType;
    /** PhotometricInterpretation, (0028,0004), CS, 1,  */
    extern const tag PhotometricInterpretation;
    /** PhototimerSetting, (0018,7065), DS, 1,  */
    extern const tag PhototimerSetting;
    /** PhysicalDeltaX, (0018,602C), FD, 1,  */
    extern const tag PhysicalDeltaX;
    /** PhysicalDeltaY, (0018,602E), FD, 1,  */
    extern const tag PhysicalDeltaY;
    /** PhysicalDetectorSize, (0018,9429), FL, 2,  */
    extern const tag PhysicalDetectorSize;
    /** PhysicalUnitsXDirection, (0018,6024), US, 1,  */
    extern const tag PhysicalUnitsXDirection;
    /** PhysicalUnitsYDirection, (0018,6026), US, 1,  */
    extern const tag PhysicalUnitsYDirection;
    /** PhysicianApprovingInterpretation, (4008,0114), PN, 1, RET */
    extern const tag PhysicianApprovingInterpretation;
    /** PhysiciansOfRecord, (0008,1048), PN, 1-n,  */
    extern const tag PhysiciansOfRecord;
    /** PhysiciansOfRecordIdentificationSequence, (0008,1049), SQ, 1,  */
    extern const tag PhysiciansOfRecordIdentificationSequence;
    /** PhysiciansReadingStudyIdentificationSequence, (0008,1062), SQ, 1,  */
    extern const tag PhysiciansReadingStudyIdentificationSequence;
    /** PixelAspectRatio, (0028,0034), IS, 2,  */
    extern const tag PixelAspectRatio;
    /** PixelBandwidth, (0018,0095), DS, 1,  */
    extern const tag PixelBandwidth;
    /** PixelComponentDataType, (0018,604E), US, 1,  */
    extern const tag PixelComponentDataType;
    /** PixelComponentMask, (0018,6046), UL, 1,  */
    extern const tag PixelComponentMask;
    /** PixelComponentOrganization, (0018,6044), US, 1,  */
    extern const tag PixelComponentOrganization;
    /** PixelComponentPhysicalUnits, (0018,604C), US, 1,  */
    extern const tag PixelComponentPhysicalUnits;
    /** PixelComponentRangeStart, (0018,6048), UL, 1,  */
    extern const tag PixelComponentRangeStart;
    /** PixelComponentRangeStop, (0018,604A), UL, 1,  */
    extern const tag PixelComponentRangeStop;
    /** PixelCoordinatesSetTrial, (0040,A29A), SL, 2-2n, RET */
    extern const tag PixelCoordinatesSetTrial;
    /** PixelData, (7FE0,0010), OW or OB, 1,  */
    extern const tag PixelData;
    /** PixelDataAreaOriginRelativeToFOV, (0018,7036), FL, 2,  */
    extern const tag PixelDataAreaOriginRelativeToFOV;
    /** PixelDataAreaRotationAngleRelativeToFOV, (0018,7038), FL, 1,  */
    extern const tag PixelDataAreaRotationAngleRelativeToFOV;
    /** PixelDataProviderURL, (0028,7FE0), UT, 1,  */
    extern const tag PixelDataProviderURL;
    /** PixelIntensityRelationship, (0028,1040), CS, 1,  */
    extern const tag PixelIntensityRelationship;
    /** PixelIntensityRelationshipLUTSequence, (0028,9422), SQ, 1,  */
    extern const tag PixelIntensityRelationshipLUTSequence;
    /** PixelIntensityRelationshipSign, (0028,1041), SS, 1,  */
    extern const tag PixelIntensityRelationshipSign;
    /** PixelMeasuresSequence, (0028,9110), SQ, 1,  */
    extern const tag PixelMeasuresSequence;
    /** PixelOriginInterpretation, (0048,0301), CS, 1,  */
    extern const tag PixelOriginInterpretation;
    /** PixelPaddingRangeLimit, (0028,0121), US or SS, 1,  */
    extern const tag PixelPaddingRangeLimit;
    /** PixelPaddingValue, (0028,0120), US or SS, 1,  */
    extern const tag PixelPaddingValue;
    /** PixelPresentation, (0008,9205), CS, 1,  */
    extern const tag PixelPresentation;
    /** PixelRepresentation, (0028,0103), US, 1,  */
    extern const tag PixelRepresentation;
    /** PixelShiftFrameRange, (0028,9506), US, 2-2n,  */
    extern const tag PixelShiftFrameRange;
    /** PixelShiftSequence, (0028,9501), SQ, 1,  */
    extern const tag PixelShiftSequence;
    /** PixelSpacing, (0028,0030), DS, 2,  */
    extern const tag PixelSpacing;
    /** PixelSpacingCalibrationDescription, (0028,0A04), LO, 1,  */
    extern const tag PixelSpacingCalibrationDescription;
    /** PixelSpacingCalibrationType, (0028,0A02), CS, 1,  */
    extern const tag PixelSpacingCalibrationType;
    /** PixelSpacingSequence, (0040,08D8), SQ, 1, RET */
    extern const tag PixelSpacingSequence;
    /** PixelValueMappingCodeSequence, (0040,9098), SQ, 1,  */
    extern const tag PixelValueMappingCodeSequence;
    /** PixelValueTransformationSequence, (0028,9145), SQ, 1,  */
    extern const tag PixelValueTransformationSequence;
    /** PlacerOrderNumberImagingServiceRequest, (0040,2016), LO, 1,  */
    extern const tag PlacerOrderNumberImagingServiceRequest;
    /** PlacerOrderNumberImagingServiceRequestRetired, (0040,2006), SH, 1, RET */
    extern const tag PlacerOrderNumberImagingServiceRequestRetired;
    /** PlacerOrderNumberProcedure, (0040,1006), SH, 1, RET */
    extern const tag PlacerOrderNumberProcedure;
    /** PlanarConfiguration, (0028,0006), US, 1,  */
    extern const tag PlanarConfiguration;
    /** PlaneIdentification, (0018,9457), CS, 1,  */
    extern const tag PlaneIdentification;
    /** PlaneOrientationSequence, (0020,9116), SQ, 1,  */
    extern const tag PlaneOrientationSequence;
    /** PlaneOrientationVolumeSequence, (0020,930F), SQ, 1,  */
    extern const tag PlaneOrientationVolumeSequence;
    /** PlanePositionSequence, (0020,9113), SQ, 1,  */
    extern const tag PlanePositionSequence;
    /** PlanePositionSlideSequence, (0048,021A), SQ, 1,  */
    extern const tag PlanePositionSlideSequence;
    /** PlanePositionVolumeSequence, (0020,930E), SQ, 1,  */
    extern const tag PlanePositionVolumeSequence;
    /** Planes, (0028,0012), US, 1, RET */
    extern const tag Planes;
    /** PlanesInAcquisition, (0018,9410), CS, 1,  */
    extern const tag PlanesInAcquisition;
    /** PlanIntent, (300A,000A), CS, 1,  */
    extern const tag PlanIntent;
    /** PlannedVerificationImageSequence, (300A,00CA), SQ, 1,  */
    extern const tag PlannedVerificationImageSequence;
    /** PlanningLandmarkDescription, (0068,6540), LO, 1,  */
    extern const tag PlanningLandmarkDescription;
    /** PlanningLandmarkID, (0068,6530), US, 1,  */
    extern const tag PlanningLandmarkID;
    /** PlanningLandmarkIdentificationCodeSequence, (0068,6545), SQ, 1,  */
    extern const tag PlanningLandmarkIdentificationCodeSequence;
    /** PlanningLandmarkLineSequence, (0068,6510), SQ, 1,  */
    extern const tag PlanningLandmarkLineSequence;
    /** PlanningLandmarkPlaneSequence, (0068,6520), SQ, 1,  */
    extern const tag PlanningLandmarkPlaneSequence;
    /** PlanningLandmarkPointSequence, (0068,6500), SQ, 1,  */
    extern const tag PlanningLandmarkPointSequence;
    /** PlateID, (0018,1004), LO, 1,  */
    extern const tag PlateID;
    /** PlateType, (0018,1260), SH, 1,  */
    extern const tag PlateType;
    /** PointCoordinatesData, (0066,0016), OF, 1,  */
    extern const tag PointCoordinatesData;
    /** PointPositionAccuracy, (0066,0017), FL, 3,  */
    extern const tag PointPositionAccuracy;
    /** PointsBoundingBoxCoordinates, (0066,001A), FL, 6,  */
    extern const tag PointsBoundingBoxCoordinates;
    /** Polarity, (2020,0020), CS, 1,  */
    extern const tag Polarity;
    /** PositionerIsocenterDetectorRotationAngle, (0018,9465), FL, 1,  */
    extern const tag PositionerIsocenterDetectorRotationAngle;
    /** PositionerIsocenterPrimaryAngle, (0018,9463), FL, 1,  */
    extern const tag PositionerIsocenterPrimaryAngle;
    /** PositionerIsocenterSecondaryAngle, (0018,9464), FL, 1,  */
    extern const tag PositionerIsocenterSecondaryAngle;
    /** PositionerMotion, (0018,1500), CS, 1,  */
    extern const tag PositionerMotion;
    /** PositionerPositionSequence, (0018,9405), SQ, 1,  */
    extern const tag PositionerPositionSequence;
    /** PositionerPrimaryAngle, (0018,1510), DS, 1,  */
    extern const tag PositionerPrimaryAngle;
    /** PositionerPrimaryAngleIncrement, (0018,1520), DS, 1-n,  */
    extern const tag PositionerPrimaryAngleIncrement;
    /** PositionerSecondaryAngle, (0018,1511), DS, 1,  */
    extern const tag PositionerSecondaryAngle;
    /** PositionerSecondaryAngleIncrement, (0018,1521), DS, 1-n,  */
    extern const tag PositionerSecondaryAngleIncrement;
    /** PositionerType, (0018,1508), CS, 1,  */
    extern const tag PositionerType;
    /** PositionMeasuringDeviceUsed, (0018,980C), CS, 1,  */
    extern const tag PositionMeasuringDeviceUsed;
    /** PositionOfIsocenterProjection, (0018,9430), FL, 2,  */
    extern const tag PositionOfIsocenterProjection;
    /** PositionReferenceIndicator, (0020,1040), LO, 1,  */
    extern const tag PositionReferenceIndicator;
    /** PositiveCatchTrialsQuantity, (0024,0056), US, 1,  */
    extern const tag PositiveCatchTrialsQuantity;
    /** PostDeformationMatrixRegistrationSequence, (0064,0010), SQ, 1,  */
    extern const tag PostDeformationMatrixRegistrationSequence;
    /** PostprocessingFunction, (0018,5021), LO, 1, RET */
    extern const tag PostprocessingFunction;
    /** PotentialThreatObjectID, (4010,1010), US, 1,  */
    extern const tag PotentialThreatObjectID;
    /** PreAmplifierEquipmentSequence, (0014,400E), SQ, 1,  */
    extern const tag PreAmplifierEquipmentSequence;
    /** PreAmplifierNotes, (0014,400F), LT, 1,  */
    extern const tag PreAmplifierNotes;
    /** PreAmplifierSettingsSequence, (0014,4040), SQ, 1,  */
    extern const tag PreAmplifierSettingsSequence;
    /** PredecessorDocumentsSequence, (0040,A360), SQ, 1,  */
    extern const tag PredecessorDocumentsSequence;
    /** PreDeformationMatrixRegistrationSequence, (0064,000F), SQ, 1,  */
    extern const tag PreDeformationMatrixRegistrationSequence;
    /** PredictedRefractiveError, (0022,1054), FL, 1,  */
    extern const tag PredictedRefractiveError;
    /** PredictorColumns, (0028,0081), US, 1, RET */
    extern const tag PredictorColumns;
    /** PredictorConstants, (0028,0082), US, 1-n, RET */
    extern const tag PredictorConstants;
    /** PredictorRows, (0028,0080), US, 1, RET */
    extern const tag PredictorRows;
    /** PreferredPlaybackSequencing, (0018,1244), US, 1,  */
    extern const tag PreferredPlaybackSequencing;
    /** PregnancyStatus, (0010,21C0), US, 1,  */
    extern const tag PregnancyStatus;
    /** PreliminaryFlag, (0040,A496), CS, 1,  */
    extern const tag PreliminaryFlag;
    /** PreMedication, (0040,0012), LO, 1,  */
    extern const tag PreMedication;
    /** PrescriptionDescription, (300A,000E), ST, 1,  */
    extern const tag PrescriptionDescription;
    /** PresentationCreationDate, (0070,0082), DA, 1,  */
    extern const tag PresentationCreationDate;
    /** PresentationCreationTime, (0070,0083), TM, 1,  */
    extern const tag PresentationCreationTime;
    /** PresentationGroupNumber, (003A,0241), US, 1,  */
    extern const tag PresentationGroupNumber;
    /** PresentationIntentType, (0008,0068), CS, 1,  */
    extern const tag PresentationIntentType;
    /** PresentationLUTContentSequence, (2130,0080), SQ, 1, RET */
    extern const tag PresentationLUTContentSequence;
    /** PresentationLUTFlag, (2000,0069), CS, 1, RET */
    extern const tag PresentationLUTFlag;
    /** PresentationLUTSequence, (2050,0010), SQ, 1,  */
    extern const tag PresentationLUTSequence;
    /** PresentationLUTShape, (2050,0020), CS, 1,  */
    extern const tag PresentationLUTShape;
    /** PresentationPixelAspectRatio, (0070,0102), IS, 2,  */
    extern const tag PresentationPixelAspectRatio;
    /** PresentationPixelMagnificationRatio, (0070,0103), FL, 1,  */
    extern const tag PresentationPixelMagnificationRatio;
    /** PresentationPixelSpacing, (0070,0101), DS, 2,  */
    extern const tag PresentationPixelSpacing;
    /** PresentationSizeMode, (0070,0100), CS, 1,  */
    extern const tag PresentationSizeMode;
    /** PresentedVisualStimuliDataFlag, (0024,0037), CS, 1,  */
    extern const tag PresentedVisualStimuliDataFlag;
    /** PreserveCompositeInstancesAfterMediaCreation, (2200,000A), CS, 1,  */
    extern const tag PreserveCompositeInstancesAfterMediaCreation;
    /** PrimaryAnatomicStructureModifierSequence, (0008,2230), SQ, 1,  */
    extern const tag PrimaryAnatomicStructureModifierSequence;
    /** PrimaryAnatomicStructureSequence, (0008,2228), SQ, 1,  */
    extern const tag PrimaryAnatomicStructureSequence;
    /** PrimaryDosimeterUnit, (300A,00B3), CS, 1,  */
    extern const tag PrimaryDosimeterUnit;
    /** PrimaryFluenceModeSequence, (3002,0050), SQ, 1,  */
    extern const tag PrimaryFluenceModeSequence;
    /** PrimaryPositionerIncrement, (0018,9514), FL, 1,  */
    extern const tag PrimaryPositionerIncrement;
    /** PrimaryPositionerScanArc, (0018,9508), FL, 1,  */
    extern const tag PrimaryPositionerScanArc;
    /** PrimaryPositionerScanStartAngle, (0018,9510), FL, 1,  */
    extern const tag PrimaryPositionerScanStartAngle;
    /** PrimaryPromptsCountsAccumulated, (0054,1310), IS, 1,  */
    extern const tag PrimaryPromptsCountsAccumulated;
    /** PrimitivePointIndexList, (0066,0029), OW, 1,  */
    extern const tag PrimitivePointIndexList;
    /** PrinterCharacteristicsSequence, (2130,0015), SQ, 1, RET */
    extern const tag PrinterCharacteristicsSequence;
    /** PrinterConfigurationSequence, (2000,001E), SQ, 1,  */
    extern const tag PrinterConfigurationSequence;
    /** PrinterName, (2110,0030), LO, 1,  */
    extern const tag PrinterName;
    /** PrinterPixelSpacing, (2010,0376), DS, 2,  */
    extern const tag PrinterPixelSpacing;
    /** PrinterResolutionID, (2010,0052), CS, 1,  */
    extern const tag PrinterResolutionID;
    /** PrinterStatus, (2110,0010), CS, 1,  */
    extern const tag PrinterStatus;
    /** PrinterStatusInfo, (2110,0020), CS, 1,  */
    extern const tag PrinterStatusInfo;
    /** PrintingBitDepth, (2000,00A1), US, 1,  */
    extern const tag PrintingBitDepth;
    /** PrintJobDescriptionSequence, (2120,0050), SQ, 1, RET */
    extern const tag PrintJobDescriptionSequence;
    /** PrintJobID, (2100,0010), SH, 1, RET */
    extern const tag PrintJobID;
    /** PrintManagementCapabilitiesSequence, (2130,0010), SQ, 1, RET */
    extern const tag PrintManagementCapabilitiesSequence;
    /** PrintPriority, (2000,0020), CS, 1,  */
    extern const tag PrintPriority;
    /** PrintQueueID, (2110,0099), SH, 1, RET */
    extern const tag PrintQueueID;
    /** PrismSequence, (0046,0028), SQ, 1,  */
    extern const tag PrismSequence;
    /** PrivateInformation, (0002,0102), OB, 1,  */
    extern const tag PrivateInformation;
    /** PrivateInformationCreatorUID, (0002,0100), UI, 1,  */
    extern const tag PrivateInformationCreatorUID;
    /** PrivateRecordUID, (0004,1432), UI, 1,  */
    extern const tag PrivateRecordUID;
    /** ProcedureCodeSequence, (0008,1032), SQ, 1,  */
    extern const tag ProcedureCodeSequence;
    /** ProcedureContextFlagTrial, (0040,A603), CS, 1, RET */
    extern const tag ProcedureContextFlagTrial;
    /** ProcedureContextSequenceTrial, (0040,A340), SQ, 1, RET */
    extern const tag ProcedureContextSequenceTrial;
    /** ProcedureCreationDate, (0014,4076), DA, 1,  */
    extern const tag ProcedureCreationDate;
    /** ProcedureExpirationDate, (0014,4078), DA, 1,  */
    extern const tag ProcedureExpirationDate;
    /** ProcedureIdentifierCodeSequenceTrial, (0040,A085), SQ, 1, RET */
    extern const tag ProcedureIdentifierCodeSequenceTrial;
    /** ProcedureLastModifiedDate, (0014,407A), DA, 1,  */
    extern const tag ProcedureLastModifiedDate;
    /** ProcedureStepCancellationDateTime, (0040,4052), DT, 1,  */
    extern const tag ProcedureStepCancellationDateTime;
    /** ProcedureStepCommunicationsURISequence, (0074,1008), SQ, 1,  */
    extern const tag ProcedureStepCommunicationsURISequence;
    /** ProcedureStepDiscontinuationReasonCodeSequence, (0074,100E), SQ, 1,  */
    extern const tag ProcedureStepDiscontinuationReasonCodeSequence;
    /** ProcedureStepLabel, (0074,1204), LO, 1,  */
    extern const tag ProcedureStepLabel;
    /** ProcedureStepProgress, (0074,1004), DS, 1,  */
    extern const tag ProcedureStepProgress;
    /** ProcedureStepProgressDescription, (0074,1006), ST, 1,  */
    extern const tag ProcedureStepProgressDescription;
    /** ProcedureStepProgressInformationSequence, (0074,1002), SQ, 1,  */
    extern const tag ProcedureStepProgressInformationSequence;
    /** ProcedureStepRelationshipType, (0074,1222), LO, 1, RET */
    extern const tag ProcedureStepRelationshipType;
    /** ProcedureStepState, (0074,1000), CS, 1,  */
    extern const tag ProcedureStepState;
    /** ProcedureTypeCodeSequence, (0076,0020), SQ, 1,  */
    extern const tag ProcedureTypeCodeSequence;
    /** ProcedureVersion, (0014,4074), SH, 1,  */
    extern const tag ProcedureVersion;
    /** ProcessingFunction, (0018,5020), LO, 1,  */
    extern const tag ProcessingFunction;
    /** ProductDescription, (0044,0009), LT, 1,  */
    extern const tag ProductDescription;
    /** ProductExpirationDateTime, (0044,000B), DT, 1,  */
    extern const tag ProductExpirationDateTime;
    /** ProductLotIdentifier, (0044,000A), LO, 1,  */
    extern const tag ProductLotIdentifier;
    /** ProductName, (0044,0008), LO, 1-n,  */
    extern const tag ProductName;
    /** ProductPackageIdentifier, (0044,0001), ST, 1,  */
    extern const tag ProductPackageIdentifier;
    /** ProductParameterSequence, (0044,0013), SQ, 1,  */
    extern const tag ProductParameterSequence;
    /** ProductTypeCodeSequence, (0044,0007), SQ, 1,  */
    extern const tag ProductTypeCodeSequence;
    /** ProjectionEponymousNameCodeSequence, (0018,5104), SQ, 1,  */
    extern const tag ProjectionEponymousNameCodeSequence;
    /** ProjectionPixelCalibrationSequence, (0018,9401), SQ, 1,  */
    extern const tag ProjectionPixelCalibrationSequence;
    /** PropertyLabel, (0014,2032), SH, 1,  */
    extern const tag PropertyLabel;
    /** ProposedStudySequence, (2130,00A0), SQ, 1, RET */
    extern const tag ProposedStudySequence;
    /** ProtocolContextSequence, (0040,0440), SQ, 1,  */
    extern const tag ProtocolContextSequence;
    /** ProtocolName, (0018,1030), LO, 1,  */
    extern const tag ProtocolName;
    /** PseudoColorPaletteInstanceReferenceSequence, (0072,0705), SQ, 1,  */
    extern const tag PseudoColorPaletteInstanceReferenceSequence;
    /** PseudoColorType, (0072,0704), CS, 1,  */
    extern const tag PseudoColorType;
    /** PTORepresentationSequence, (4010,1037), SQ, 1,  */
    extern const tag PTORepresentationSequence;
    /** PulseRepetitionFrequency, (0018,6032), UL, 1,  */
    extern const tag PulseRepetitionFrequency;
    /** PulseRepetitionInterval, (300A,028C), DS, 1,  */
    extern const tag PulseRepetitionInterval;
    /** PulserEquipmentSequence, (0014,4002), SQ, 1,  */
    extern const tag PulserEquipmentSequence;
    /** PulserNotes, (0014,4006), LT, 1,  */
    extern const tag PulserNotes;
    /** PulserSettingsSequence, (0014,4020), SQ, 1,  */
    extern const tag PulserSettingsSequence;
    /** PulserType, (0014,4004), CS, 1,  */
    extern const tag PulserType;
    /** PulseSequenceName, (0018,9005), SH, 1,  */
    extern const tag PulseSequenceName;
    /** PulseWidth, (0014,4022), DS, 1,  */
    extern const tag PulseWidth;
    /** PupilDilated, (0022,000D), CS, 1,  */
    extern const tag PupilDilated;
    /** PupilSize, (0046,0044), FD, 1,  */
    extern const tag PupilSize;
    /** PurposeOfReferenceCodeSequence, (0040,A170), SQ, 1,  */
    extern const tag PurposeOfReferenceCodeSequence;
    /** PVCRejection, (0018,1085), LO, 1,  */
    extern const tag PVCRejection;
    /** QuadratureReceiveCoil, (0018,9044), CS, 1,  */
    extern const tag QuadratureReceiveCoil;
    /** QualityControlImage, (0028,0300), CS, 1,  */
    extern const tag QualityControlImage;
    /** QuantifiedDefect, (0024,0098), FL, 1,  */
    extern const tag QuantifiedDefect;
    /** Quantity, (0040,0294), DS, 1,  */
    extern const tag Quantity;
    /** QuantitySequence, (0040,0293), SQ, 1,  */
    extern const tag QuantitySequence;
    /** QueryRetrieveLevel, (0008,0052), CS, 1,  */
    extern const tag QueryRetrieveLevel;
    /** QueueStatus, (2120,0010), CS, 1, RET */
    extern const tag QueueStatus;
    /** RadialPosition, (0018,1142), DS, 1-n,  */
    extern const tag RadialPosition;
    /** RadiationAtomicNumber, (300A,0304), IS, 1,  */
    extern const tag RadiationAtomicNumber;
    /** RadiationChargeState, (300A,0306), SS, 1,  */
    extern const tag RadiationChargeState;
    /** RadiationMachineName, (3002,0020), SH, 1,  */
    extern const tag RadiationMachineName;
    /** RadiationMachineSAD, (3002,0022), DS, 1,  */
    extern const tag RadiationMachineSAD;
    /** RadiationMachineSSD, (3002,0024), DS, 1,  */
    extern const tag RadiationMachineSSD;
    /** RadiationMassNumber, (300A,0302), IS, 1,  */
    extern const tag RadiationMassNumber;
    /** RadiationMode, (0018,115A), CS, 1,  */
    extern const tag RadiationMode;
    /** RadiationSetting, (0018,1155), CS, 1,  */
    extern const tag RadiationSetting;
    /** RadiationType, (300A,00C6), CS, 1,  */
    extern const tag RadiationType;
    /** Radionuclide, (0018,0030), LO, 1-n, RET */
    extern const tag Radionuclide;
    /** RadionuclideCodeSequence, (0054,0300), SQ, 1,  */
    extern const tag RadionuclideCodeSequence;
    /** RadionuclideHalfLife, (0018,1075), DS, 1,  */
    extern const tag RadionuclideHalfLife;
    /** RadionuclidePositronFraction, (0018,1076), DS, 1,  */
    extern const tag RadionuclidePositronFraction;
    /** RadionuclideTotalDose, (0018,1074), DS, 1,  */
    extern const tag RadionuclideTotalDose;
    /** Radiopharmaceutical, (0018,0031), LO, 1,  */
    extern const tag Radiopharmaceutical;
    /** RadiopharmaceuticalAgentNumber, (0018,9729), US, 1,  */
    extern const tag RadiopharmaceuticalAgentNumber;
    /** RadiopharmaceuticalCodeSequence, (0054,0304), SQ, 1,  */
    extern const tag RadiopharmaceuticalCodeSequence;
    /** RadiopharmaceuticalInformationSequence, (0054,0016), SQ, 1,  */
    extern const tag RadiopharmaceuticalInformationSequence;
    /** RadiopharmaceuticalRoute, (0018,1070), LO, 1,  */
    extern const tag RadiopharmaceuticalRoute;
    /** RadiopharmaceuticalSpecificActivity, (0018,1077), DS, 1,  */
    extern const tag RadiopharmaceuticalSpecificActivity;
    /** RadiopharmaceuticalStartDateTime, (0018,1078), DT, 1,  */
    extern const tag RadiopharmaceuticalStartDateTime;
    /** RadiopharmaceuticalStartTime, (0018,1072), TM, 1,  */
    extern const tag RadiopharmaceuticalStartTime;
    /** RadiopharmaceuticalStopDateTime, (0018,1079), DT, 1,  */
    extern const tag RadiopharmaceuticalStopDateTime;
    /** RadiopharmaceuticalStopTime, (0018,1073), TM, 1,  */
    extern const tag RadiopharmaceuticalStopTime;
    /** RadiopharmaceuticalUsageSequence, (0018,9737), SQ, 1,  */
    extern const tag RadiopharmaceuticalUsageSequence;
    /** RadiopharmaceuticalVolume, (0018,1071), DS, 1,  */
    extern const tag RadiopharmaceuticalVolume;
    /** RadiusOfCircularCollimator, (0018,1712), IS, 1,  */
    extern const tag RadiusOfCircularCollimator;
    /** RadiusOfCircularExposureControlSensingRegion, (0018,9441), US, 1,  */
    extern const tag RadiusOfCircularExposureControlSensingRegion;
    /** RadiusOfCircularShutter, (0018,1612), IS, 1,  */
    extern const tag RadiusOfCircularShutter;
    /** RadiusOfCurvature, (0046,0075), FD, 1,  */
    extern const tag RadiusOfCurvature;
    /** RandomsCorrected, (0018,9765), CS, 1,  */
    extern const tag RandomsCorrected;
    /** RandomsCorrectionMethod, (0054,1100), CS, 1,  */
    extern const tag RandomsCorrectionMethod;
    /** RangeModulatorDescription, (300A,034A), LO, 1,  */
    extern const tag RangeModulatorDescription;
    /** RangeModulatorGatingStartValue, (300A,0382), FL, 1,  */
    extern const tag RangeModulatorGatingStartValue;
    /** RangeModulatorGatingStartWaterEquivalentThickness, (300A,0386), FL, 1,  */
    extern const tag RangeModulatorGatingStartWaterEquivalentThickness;
    /** RangeModulatorGatingStopValue, (300A,0384), FL, 1,  */
    extern const tag RangeModulatorGatingStopValue;
    /** RangeModulatorGatingStopWaterEquivalentThickness, (300A,0388), FL, 1,  */
    extern const tag RangeModulatorGatingStopWaterEquivalentThickness;
    /** RangeModulatorID, (300A,0346), SH, 1,  */
    extern const tag RangeModulatorID;
    /** RangeModulatorNumber, (300A,0344), IS, 1,  */
    extern const tag RangeModulatorNumber;
    /** RangeModulatorSequence, (300A,0342), SQ, 1,  */
    extern const tag RangeModulatorSequence;
    /** RangeModulatorSettingsSequence, (300A,0380), SQ, 1,  */
    extern const tag RangeModulatorSettingsSequence;
    /** RangeModulatorType, (300A,0348), CS, 1,  */
    extern const tag RangeModulatorType;
    /** RangeOfFreedom, (0068,64A0), FD, 2,  */
    extern const tag RangeOfFreedom;
    /** RangeShifterDescription, (300A,0322), LO, 1,  */
    extern const tag RangeShifterDescription;
    /** RangeShifterID, (300A,0318), SH, 1,  */
    extern const tag RangeShifterID;
    /** RangeShifterNumber, (300A,0316), IS, 1,  */
    extern const tag RangeShifterNumber;
    /** RangeShifterSequence, (300A,0314), SQ, 1,  */
    extern const tag RangeShifterSequence;
    /** RangeShifterSetting, (300A,0362), LO, 1,  */
    extern const tag RangeShifterSetting;
    /** RangeShifterSettingsSequence, (300A,0360), SQ, 1,  */
    extern const tag RangeShifterSettingsSequence;
    /** RangeShifterType, (300A,0320), CS, 1,  */
    extern const tag RangeShifterType;
    /** RangeShifterWaterEquivalentThickness, (300A,0366), FL, 1,  */
    extern const tag RangeShifterWaterEquivalentThickness;
    /** RangingDepth, (0052,0009), FD, 1,  */
    extern const tag RangingDepth;
    /** RawDataHandling, (0040,4040), CS, 1,  */
    extern const tag RawDataHandling;
    /** RealWorldValueFirstValueMapped, (0040,9216), US or SS, 1,  */
    extern const tag RealWorldValueFirstValueMapped;
    /** RealWorldValueIntercept, (0040,9224), FD, 1,  */
    extern const tag RealWorldValueIntercept;
    /** RealWorldValueLastValueMapped, (0040,9211), US or SS, 1,  */
    extern const tag RealWorldValueLastValueMapped;
    /** RealWorldValueLUTData, (0040,9212), FD, 1-n,  */
    extern const tag RealWorldValueLUTData;
    /** RealWorldValueMappingSequence, (0040,9096), SQ, 1,  */
    extern const tag RealWorldValueMappingSequence;
    /** RealWorldValueSlope, (0040,9225), FD, 1,  */
    extern const tag RealWorldValueSlope;
    /** ReasonForCancellation, (0074,1238), LT, 1,  */
    extern const tag ReasonForCancellation;
    /** ReasonForPerformedProcedureCodeSequence, (0040,1012), SQ, 1,  */
    extern const tag ReasonForPerformedProcedureCodeSequence;
    /** ReasonForRequestedProcedureCodeSequence, (0040,100A), SQ, 1,  */
    extern const tag ReasonForRequestedProcedureCodeSequence;
    /** ReasonForStudy, (0032,1030), LO, 1, RET */
    extern const tag ReasonForStudy;
    /** ReasonForTheAttributeModification, (0400,0565), CS, 1,  */
    extern const tag ReasonForTheAttributeModification;
    /** ReasonForTheImagingServiceRequest, (0040,2001), LO, 1, RET */
    extern const tag ReasonForTheImagingServiceRequest;
    /** ReasonForTheRequestedProcedure, (0040,1002), LO, 1,  */
    extern const tag ReasonForTheRequestedProcedure;
    /** ReceiveCoilManufacturerName, (0018,9041), LO, 1,  */
    extern const tag ReceiveCoilManufacturerName;
    /** ReceiveCoilName, (0018,1250), SH, 1,  */
    extern const tag ReceiveCoilName;
    /** ReceiveCoilType, (0018,9043), CS, 1,  */
    extern const tag ReceiveCoilType;
    /** ReceiverEquipmentSequence, (0014,4008), SQ, 1,  */
    extern const tag ReceiverEquipmentSequence;
    /** ReceiverNotes, (0014,400C), LT, 1,  */
    extern const tag ReceiverNotes;
    /** ReceiverSettingsSequence, (0014,4030), SQ, 1,  */
    extern const tag ReceiverSettingsSequence;
    /** ReceiveTransducerSequence, (0014,4011), SQ, 1,  */
    extern const tag ReceiveTransducerSequence;
    /** ReceiveTransducerSettingsSequence, (0014,4051), SQ, 1,  */
    extern const tag ReceiveTransducerSettingsSequence;
    /** ReceivingAE, (0074,1234), AE, 1,  */
    extern const tag ReceivingAE;
    /** RecognitionCode, (0008,0010), SH, 1, RET */
    extern const tag RecognitionCode;
    /** RecognizableVisualFeatures, (0028,0302), CS, 1,  */
    extern const tag RecognizableVisualFeatures;
    /** RecommendedAbsentPixelCIELabValue, (0048,0015), US, 3,  */
    extern const tag RecommendedAbsentPixelCIELabValue;
    /** RecommendedDisplayCIELabValue, (0062,000D), US, 3,  */
    extern const tag RecommendedDisplayCIELabValue;
    /** RecommendedDisplayFrameRate, (0008,2144), IS, 1,  */
    extern const tag RecommendedDisplayFrameRate;
    /** RecommendedDisplayFrameRateInFloat, (0008,9459), FL, 1,  */
    extern const tag RecommendedDisplayFrameRateInFloat;
    /** RecommendedDisplayGrayscaleValue, (0062,000C), US, 1,  */
    extern const tag RecommendedDisplayGrayscaleValue;
    /** RecommendedPresentationOpacity, (0066,000C), FL, 1,  */
    extern const tag RecommendedPresentationOpacity;
    /** RecommendedPresentationType, (0066,000D), CS, 1,  */
    extern const tag RecommendedPresentationType;
    /** RecommendedRotationPoint, (0068,6346), FD, 2,  */
    extern const tag RecommendedRotationPoint;
    /** RecommendedViewingMode, (0028,1090), CS, 1,  */
    extern const tag RecommendedViewingMode;
    /** ReconstructionAlgorithm, (0018,9315), CS, 1,  */
    extern const tag ReconstructionAlgorithm;
    /** ReconstructionAngle, (0018,9319), FD, 1,  */
    extern const tag ReconstructionAngle;
    /** ReconstructionDescription, (0018,9531), LO, 1,  */
    extern const tag ReconstructionDescription;
    /** ReconstructionDiameter, (0018,1100), DS, 1,  */
    extern const tag ReconstructionDiameter;
    /** ReconstructionFieldOfView, (0018,9317), FD, 2,  */
    extern const tag ReconstructionFieldOfView;
    /** ReconstructionIndex, (0020,9536), US, 1,  */
    extern const tag ReconstructionIndex;
    /** ReconstructionMethod, (0054,1103), LO, 1,  */
    extern const tag ReconstructionMethod;
    /** ReconstructionPixelSpacing, (0018,9322), FD, 2,  */
    extern const tag ReconstructionPixelSpacing;
    /** ReconstructionTargetCenterPatient, (0018,9318), FD, 3,  */
    extern const tag ReconstructionTargetCenterPatient;
    /** ReconstructionType, (0018,9756), CS, 1,  */
    extern const tag ReconstructionType;
    /** RecordedBlockSequence, (3008,00D0), SQ, 1,  */
    extern const tag RecordedBlockSequence;
    /** RecordedBrachyAccessoryDeviceSequence, (3008,0120), SQ, 1,  */
    extern const tag RecordedBrachyAccessoryDeviceSequence;
    /** RecordedChannelSequence, (3008,0130), SQ, 1,  */
    extern const tag RecordedChannelSequence;
    /** RecordedChannelShieldSequence, (3008,0150), SQ, 1,  */
    extern const tag RecordedChannelShieldSequence;
    /** RecordedCompensatorSequence, (3008,00C0), SQ, 1,  */
    extern const tag RecordedCompensatorSequence;
    /** RecordedLateralSpreadingDeviceSequence, (3008,00F4), SQ, 1,  */
    extern const tag RecordedLateralSpreadingDeviceSequence;
    /** RecordedRangeModulatorSequence, (3008,00F6), SQ, 1,  */
    extern const tag RecordedRangeModulatorSequence;
    /** RecordedRangeShifterSequence, (3008,00F2), SQ, 1,  */
    extern const tag RecordedRangeShifterSequence;
    /** RecordedSnoutSequence, (3008,00F0), SQ, 1,  */
    extern const tag RecordedSnoutSequence;
    /** RecordedSourceApplicatorSequence, (3008,0140), SQ, 1,  */
    extern const tag RecordedSourceApplicatorSequence;
    /** RecordedSourceSequence, (3008,0100), SQ, 1,  */
    extern const tag RecordedSourceSequence;
    /** RecordedWedgeSequence, (3008,00B0), SQ, 1,  */
    extern const tag RecordedWedgeSequence;
    /** RecordInUseFlag, (0004,1410), US, 1,  */
    extern const tag RecordInUseFlag;
    /** RectificationType, (0018,1156), CS, 1,  */
    extern const tag RectificationType;
    /** RectifierSmoothing, (0014,4034), DS, 1,  */
    extern const tag RectifierSmoothing;
    /** RectilinearPhaseEncodeReordering, (0018,9034), CS, 1,  */
    extern const tag RectilinearPhaseEncodeReordering;
    /** RedPaletteColorLookupTableData, (0028,1201), OW, 1,  */
    extern const tag RedPaletteColorLookupTableData;
    /** RedPaletteColorLookupTableDescriptor, (0028,1101), US or SS, 3,  */
    extern const tag RedPaletteColorLookupTableDescriptor;
    /** Reference, (0020,1020), LO, 1-n, RET */
    extern const tag Reference;
    /** ReferenceAirKermaRate, (300A,022A), DS, 1,  */
    extern const tag ReferenceAirKermaRate;
    /** ReferenceCoordinates, (0022,0032), FL, 2-2n,  */
    extern const tag ReferenceCoordinates;
    /** ReferencedAccessionSequenceTrial, (0040,A313), SQ, 1, RET */
    extern const tag ReferencedAccessionSequenceTrial;
    /** ReferencedBasicAnnotationBoxSequence, (2010,0520), SQ, 1,  */
    extern const tag ReferencedBasicAnnotationBoxSequence;
    /** ReferencedBeamNumber, (300C,0006), IS, 1,  */
    extern const tag ReferencedBeamNumber;
    /** ReferencedBeamSequence, (300C,0004), SQ, 1,  */
    extern const tag ReferencedBeamSequence;
    /** ReferencedBlockNumber, (300C,00E0), IS, 1,  */
    extern const tag ReferencedBlockNumber;
    /** ReferencedBolusSequence, (300C,00B0), SQ, 1,  */
    extern const tag ReferencedBolusSequence;
    /** ReferencedBrachyAccessoryDeviceNumber, (3008,0122), IS, 1,  */
    extern const tag ReferencedBrachyAccessoryDeviceNumber;
    /** ReferencedBrachyApplicationSetupNumber, (300C,000C), IS, 1,  */
    extern const tag ReferencedBrachyApplicationSetupNumber;
    /** ReferencedBrachyApplicationSetupSequence, (300C,000A), SQ, 1,  */
    extern const tag ReferencedBrachyApplicationSetupSequence;
    /** ReferencedCalculatedDoseReferenceNumber, (3008,0092), IS, 1,  */
    extern const tag ReferencedCalculatedDoseReferenceNumber;
    /** ReferencedCalculatedDoseReferenceSequence, (3008,0090), SQ, 1,  */
    extern const tag ReferencedCalculatedDoseReferenceSequence;
    /** ReferencedChannelShieldNumber, (3008,0152), IS, 1,  */
    extern const tag ReferencedChannelShieldNumber;
    /** ReferencedColorPaletteInstanceUID, (0028,0304), UI, 1,  */
    extern const tag ReferencedColorPaletteInstanceUID;
    /** ReferencedCompensatorNumber, (300C,00D0), IS, 1,  */
    extern const tag ReferencedCompensatorNumber;
    /** ReferencedContentItemIdentifier, (0040,DB73), UL, 1-n,  */
    extern const tag ReferencedContentItemIdentifier;
    /** ReferencedControlPointIndex, (300C,00F0), IS, 1,  */
    extern const tag ReferencedControlPointIndex;
    /** ReferencedControlPointSequence, (300C,00F2), SQ, 1,  */
    extern const tag ReferencedControlPointSequence;
    /** ReferencedCurveSequence, (0008,1145), SQ, 1, RET */
    extern const tag ReferencedCurveSequence;
    /** ReferencedDateTime, (0040,A13A), DT, 1-n,  */
    extern const tag ReferencedDateTime;
    /** ReferencedDigitalSignatureSequence, (0400,0402), SQ, 1,  */
    extern const tag ReferencedDigitalSignatureSequence;
    /** ReferencedDoseReferenceNumber, (300C,0051), IS, 1,  */
    extern const tag ReferencedDoseReferenceNumber;
    /** ReferencedDoseReferenceSequence, (300C,0050), SQ, 1,  */
    extern const tag ReferencedDoseReferenceSequence;
    /** ReferencedDoseSequence, (300C,0080), SQ, 1,  */
    extern const tag ReferencedDoseSequence;
    /** ReferencedFileID, (0004,1500), CS, 1-8,  */
    extern const tag ReferencedFileID;
    /** ReferencedFilmBoxSequence, (2000,0500), SQ, 1,  */
    extern const tag ReferencedFilmBoxSequence;
    /** ReferencedFilmSessionSequence, (2010,0500), SQ, 1,  */
    extern const tag ReferencedFilmSessionSequence;
    /** ReferencedFindingsGroupUIDTrial, (0040,A022), UI, 1, RET */
    extern const tag ReferencedFindingsGroupUIDTrial;
    /** ReferencedFirstFrameSequence, (0072,0427), SQ, 1,  */
    extern const tag ReferencedFirstFrameSequence;
    /** ReferencedFractionGroupNumber, (300C,0022), IS, 1,  */
    extern const tag ReferencedFractionGroupNumber;
    /** ReferencedFractionGroupSequence, (300C,0020), SQ, 1,  */
    extern const tag ReferencedFractionGroupSequence;
    /** ReferencedFractionNumber, (3008,0223), IS, 1,  */
    extern const tag ReferencedFractionNumber;
    /** ReferencedFrameNumber, (0008,1160), IS, 1-n,  */
    extern const tag ReferencedFrameNumber;
    /** ReferencedFrameNumbers, (0040,A136), US, 1-n,  */
    extern const tag ReferencedFrameNumbers;
    /** ReferencedFrameOfReferenceSequence, (3006,0010), SQ, 1,  */
    extern const tag ReferencedFrameOfReferenceSequence;
    /** ReferencedFrameOfReferenceUID, (3006,0024), UI, 1,  */
    extern const tag ReferencedFrameOfReferenceUID;
    /** ReferencedGeneralPurposeScheduledProcedureStepSequence, (0040,4016), SQ, 1,  */
    extern const tag ReferencedGeneralPurposeScheduledProcedureStepSequence;
    /** ReferencedGeneralPurposeScheduledProcedureStepTransactionUID, (0040,4023), UI, 1,  */
    extern const tag ReferencedGeneralPurposeScheduledProcedureStepTransactionUID;
    /** ReferencedHPGLDocumentID, (0068,6440), US, 1,  */
    extern const tag ReferencedHPGLDocumentID;
    /** ReferencedImageBoxSequence, (2010,0510), SQ, 1,  */
    extern const tag ReferencedImageBoxSequence;
    /** ReferencedImageBoxSequenceRetired, (2040,0500), SQ, 1, RET */
    extern const tag ReferencedImageBoxSequenceRetired;
    /** ReferencedImageEvidenceSequence, (0008,9092), SQ, 1,  */
    extern const tag ReferencedImageEvidenceSequence;
    /** ReferencedImageNavigationSequence, (0048,0200), SQ, 1,  */
    extern const tag ReferencedImageNavigationSequence;
    /** ReferencedImageOverlayBoxSequence, (2020,0130), SQ, 1, RET */
    extern const tag ReferencedImageOverlayBoxSequence;
    /** ReferencedImageRealWorldValueMappingSequence, (0040,9094), SQ, 1,  */
    extern const tag ReferencedImageRealWorldValueMappingSequence;
    /** ReferencedImageSequence, (0008,1140), SQ, 1,  */
    extern const tag ReferencedImageSequence;
    /** ReferencedImplantTemplateGroupMemberID, (0078,00B6), US, 1,  */
    extern const tag ReferencedImplantTemplateGroupMemberID;
    /** ReferencedInstanceSequence, (0008,114A), SQ, 1,  */
    extern const tag ReferencedInstanceSequence;
    /** ReferencedInterpretationSequence, (4008,0050), SQ, 1, RET */
    extern const tag ReferencedInterpretationSequence;
    /** ReferenceDisplaySets, (0072,0218), US, 1-n,  */
    extern const tag ReferenceDisplaySets;
    /** ReferencedLateralSpreadingDeviceNumber, (300C,0102), IS, 1,  */
    extern const tag ReferencedLateralSpreadingDeviceNumber;
    /** ReferencedMeasuredDoseReferenceNumber, (3008,0082), IS, 1,  */
    extern const tag ReferencedMeasuredDoseReferenceNumber;
    /** ReferencedMeasuredDoseReferenceSequence, (3008,0080), SQ, 1,  */
    extern const tag ReferencedMeasuredDoseReferenceSequence;
    /** ReferencedNonImageCompositeSOPInstanceSequence, (0040,0220), SQ, 1,  */
    extern const tag ReferencedNonImageCompositeSOPInstanceSequence;
    /** ReferencedObjectObservationClassTrial, (0040,A174), CS, 1, RET */
    extern const tag ReferencedObjectObservationClassTrial;
    /** ReferencedObservationClassTrial, (0040,A173), CS, 1, RET */
    extern const tag ReferencedObservationClassTrial;
    /** ReferencedObservationUIDTrial, (0040,A172), UI, 1, RET */
    extern const tag ReferencedObservationUIDTrial;
    /** ReferencedOphthalmicAxialLengthMeasurementQCImageSequence, (0022,1330), SQ, 1,  */
    extern const tag ReferencedOphthalmicAxialLengthMeasurementQCImageSequence;
    /** ReferencedOphthalmicAxialMeasurementsSequence, (0022,1100), SQ, 1,  */
    extern const tag ReferencedOphthalmicAxialMeasurementsSequence;
    /** ReferencedOtherPlaneSequence, (0008,9410), SQ, 1,  */
    extern const tag ReferencedOtherPlaneSequence;
    /** ReferencedOverlayPlaneGroups, (2040,0011), US, 1-99, RET */
    extern const tag ReferencedOverlayPlaneGroups;
    /** ReferencedOverlayPlaneSequence, (2040,0010), SQ, 1, RET */
    extern const tag ReferencedOverlayPlaneSequence;
    /** ReferencedOverlaySequence, (0008,1130), SQ, 1, RET */
    extern const tag ReferencedOverlaySequence;
    /** ReferencedPatientAliasSequence, (0038,0004), SQ, 1,  */
    extern const tag ReferencedPatientAliasSequence;
    /** ReferencedPatientSequence, (0008,1120), SQ, 1,  */
    extern const tag ReferencedPatientSequence;
    /** ReferencedPatientSetupNumber, (300C,006A), IS, 1,  */
    extern const tag ReferencedPatientSetupNumber;
    /** ReferencedPerformedProcedureStepSequence, (0008,1111), SQ, 1,  */
    extern const tag ReferencedPerformedProcedureStepSequence;
    /** ReferencedPresentationLUTSequence, (2050,0500), SQ, 1,  */
    extern const tag ReferencedPresentationLUTSequence;
    /** ReferencedPresentationStateSequence, (0008,9237), SQ, 1,  */
    extern const tag ReferencedPresentationStateSequence;
    /** ReferencedPrintJobSequence, (2120,0070), SQ, 1, RET */
    extern const tag ReferencedPrintJobSequence;
    /** ReferencedPrintJobSequencePullStoredPrint, (2100,0500), SQ, 1, RET */
    extern const tag ReferencedPrintJobSequencePullStoredPrint;
    /** ReferencedProcedureStepSequence, (0040,0330), SQ, 1, RET */
    extern const tag ReferencedProcedureStepSequence;
    /** ReferencedRangeModulatorNumber, (300C,0104), IS, 1,  */
    extern const tag ReferencedRangeModulatorNumber;
    /** ReferencedRangeShifterNumber, (300C,0100), IS, 1,  */
    extern const tag ReferencedRangeShifterNumber;
    /** ReferencedRawDataSequence, (0008,9121), SQ, 1,  */
    extern const tag ReferencedRawDataSequence;
    /** ReferencedRealWorldValueMappingInstanceSequence, (0008,114B), SQ, 1,  */
    extern const tag ReferencedRealWorldValueMappingInstanceSequence;
    /** ReferencedReferenceImageNumber, (300C,0007), IS, 1,  */
    extern const tag ReferencedReferenceImageNumber;
    /** ReferencedReferenceImageSequence, (300C,0042), SQ, 1,  */
    extern const tag ReferencedReferenceImageSequence;
    /** ReferencedRefractiveMeasurementsSequence, (0046,0145), SQ, 1,  */
    extern const tag ReferencedRefractiveMeasurementsSequence;
    /** ReferencedRelatedGeneralSOPClassUIDInFile, (0004,151A), UI, 1-n,  */
    extern const tag ReferencedRelatedGeneralSOPClassUIDInFile;
    /** ReferencedRequestSequence, (0040,A370), SQ, 1,  */
    extern const tag ReferencedRequestSequence;
    /** ReferencedResultsSequence, (0008,1100), SQ, 1, RET */
    extern const tag ReferencedResultsSequence;
    /** ReferencedROINumber, (3006,0084), IS, 1,  */
    extern const tag ReferencedROINumber;
    /** ReferencedRTPlanSequence, (300C,0002), SQ, 1,  */
    extern const tag ReferencedRTPlanSequence;
    /** ReferencedSamplePositions, (0040,A132), UL, 1-n,  */
    extern const tag ReferencedSamplePositions;
    /** ReferencedSegmentNumber, (0062,000B), US, 1-n,  */
    extern const tag ReferencedSegmentNumber;
    /** ReferencedSeriesSequence, (0008,1115), SQ, 1,  */
    extern const tag ReferencedSeriesSequence;
    /** ReferencedSetupImageSequence, (300A,0401), SQ, 1,  */
    extern const tag ReferencedSetupImageSequence;
    /** ReferencedSOPClassUID, (0008,1150), UI, 1,  */
    extern const tag ReferencedSOPClassUID;
    /** ReferencedSOPClassUIDInFile, (0004,1510), UI, 1,  */
    extern const tag ReferencedSOPClassUIDInFile;
    /** ReferencedSOPInstanceMACSequence, (0400,0403), SQ, 1,  */
    extern const tag ReferencedSOPInstanceMACSequence;
    /** ReferencedSOPInstanceUID, (0008,1155), UI, 1,  */
    extern const tag ReferencedSOPInstanceUID;
    /** ReferencedSOPInstanceUIDInFile, (0004,1511), UI, 1,  */
    extern const tag ReferencedSOPInstanceUIDInFile;
    /** ReferencedSOPSequence, (0008,1199), SQ, 1,  */
    extern const tag ReferencedSOPSequence;
    /** ReferencedSourceApplicatorNumber, (3008,0142), IS, 1,  */
    extern const tag ReferencedSourceApplicatorNumber;
    /** ReferencedSourceNumber, (300C,000E), IS, 1,  */
    extern const tag ReferencedSourceNumber;
    /** ReferencedSpatialRegistrationSequence, (0070,0404), SQ, 1,  */
    extern const tag ReferencedSpatialRegistrationSequence;
    /** ReferencedStartControlPointIndex, (300C,00F4), IS, 1,  */
    extern const tag ReferencedStartControlPointIndex;
    /** ReferencedStereometricInstanceSequence, (0008,1134), SQ, 1,  */
    extern const tag ReferencedStereometricInstanceSequence;
    /** ReferencedStopControlPointIndex, (300C,00F6), IS, 1,  */
    extern const tag ReferencedStopControlPointIndex;
    /** ReferencedStorageMediaSequence, (2200,000D), SQ, 1,  */
    extern const tag ReferencedStorageMediaSequence;
    /** ReferencedStoredPrintSequence, (2000,0510), SQ, 1, RET */
    extern const tag ReferencedStoredPrintSequence;
    /** ReferencedStructureSetSequence, (300C,0060), SQ, 1,  */
    extern const tag ReferencedStructureSetSequence;
    /** ReferencedStudySequence, (0008,1110), SQ, 1,  */
    extern const tag ReferencedStudySequence;
    /** ReferencedSurfaceNumber, (0066,002C), UL, 1,  */
    extern const tag ReferencedSurfaceNumber;
    /** ReferencedSurfaceSequence, (0066,002B), SQ, 1,  */
    extern const tag ReferencedSurfaceSequence;
    /** ReferencedTimeOffsets, (0040,A138), DS, 1-n,  */
    extern const tag ReferencedTimeOffsets;
    /** ReferencedToleranceTableNumber, (300C,00A0), IS, 1,  */
    extern const tag ReferencedToleranceTableNumber;
    /** ReferencedTransferSyntaxUIDInFile, (0004,1512), UI, 1,  */
    extern const tag ReferencedTransferSyntaxUIDInFile;
    /** ReferencedTreatmentRecordSequence, (3008,0030), SQ, 1,  */
    extern const tag ReferencedTreatmentRecordSequence;
    /** ReferencedVerificationImageSequence, (300C,0040), SQ, 1,  */
    extern const tag ReferencedVerificationImageSequence;
    /** ReferencedVisitSequence, (0008,1125), SQ, 1,  */
    extern const tag ReferencedVisitSequence;
    /** ReferencedVOILUTBoxSequence, (2020,0140), SQ, 1, RET */
    extern const tag ReferencedVOILUTBoxSequence;
    /** ReferencedWaveformChannels, (0040,A0B0), US, 2-2n,  */
    extern const tag ReferencedWaveformChannels;
    /** ReferencedWaveformSequence, (0008,113A), SQ, 1,  */
    extern const tag ReferencedWaveformSequence;
    /** ReferencedWedgeNumber, (300C,00C0), IS, 1,  */
    extern const tag ReferencedWedgeNumber;
    /** ReferenceImageNumber, (300A,00C8), IS, 1,  */
    extern const tag ReferenceImageNumber;
    /** ReferencePixelPhysicalValueX, (0018,6028), FD, 1,  */
    extern const tag ReferencePixelPhysicalValueX;
    /** ReferencePixelPhysicalValueY, (0018,602A), FD, 1,  */
    extern const tag ReferencePixelPhysicalValueY;
    /** ReferencePixelX0, (0018,6020), SL, 1,  */
    extern const tag ReferencePixelX0;
    /** ReferencePixelY0, (0018,6022), SL, 1,  */
    extern const tag ReferencePixelY0;
    /** ReferenceToRecordedSound, (4008,0103), LO, 1, RET */
    extern const tag ReferenceToRecordedSound;
    /** ReferringPhysicianAddress, (0008,0092), ST, 1,  */
    extern const tag ReferringPhysicianAddress;
    /** ReferringPhysicianIdentificationSequence, (0008,0096), SQ, 1,  */
    extern const tag ReferringPhysicianIdentificationSequence;
    /** ReferringPhysicianName, (0008,0090), PN, 1,  */
    extern const tag ReferringPhysicianName;
    /** ReferringPhysicianTelephoneNumbers, (0008,0094), SH, 1-n,  */
    extern const tag ReferringPhysicianTelephoneNumbers;
    /** ReflectedAmbientLight, (2010,0160), US, 1,  */
    extern const tag ReflectedAmbientLight;
    /** ReformattingInterval, (0072,0514), FD, 1,  */
    extern const tag ReformattingInterval;
    /** ReformattingOperationInitialViewDirection, (0072,0516), CS, 1,  */
    extern const tag ReformattingOperationInitialViewDirection;
    /** ReformattingOperationType, (0072,0510), CS, 1,  */
    extern const tag ReformattingOperationType;
    /** ReformattingThickness, (0072,0512), FD, 1,  */
    extern const tag ReformattingThickness;
    /** RefractiveErrorBeforeRefractiveSurgeryCodeSequence, (0022,1103), SQ, 1,  */
    extern const tag RefractiveErrorBeforeRefractiveSurgeryCodeSequence;
    /** RefractiveIndexApplied, (0052,003A), CS, 1,  */
    extern const tag RefractiveIndexApplied;
    /** RefractiveParametersUsedOnPatientSequence, (0024,0112), SQ, 1,  */
    extern const tag RefractiveParametersUsedOnPatientSequence;
    /** RefractiveProcedureOccurred, (0022,1039), CS, 1,  */
    extern const tag RefractiveProcedureOccurred;
    /** RefractiveStateSequence, (0022,001B), SQ, 1,  */
    extern const tag RefractiveStateSequence;
    /** RefractiveSurgeryTypeCodeSequence, (0022,1040), SQ, 1,  */
    extern const tag RefractiveSurgeryTypeCodeSequence;
    /** RegionDataType, (0018,6014), US, 1,  */
    extern const tag RegionDataType;
    /** RegionFlags, (0018,6016), UL, 1,  */
    extern const tag RegionFlags;
    /** RegionLocationMaxX1, (0018,601C), UL, 1,  */
    extern const tag RegionLocationMaxX1;
    /** RegionLocationMaxY1, (0018,601E), UL, 1,  */
    extern const tag RegionLocationMaxY1;
    /** RegionLocationMinX0, (0018,6018), UL, 1,  */
    extern const tag RegionLocationMinX0;
    /** RegionLocationMinY0, (0018,601A), UL, 1,  */
    extern const tag RegionLocationMinY0;
    /** RegionOfResidence, (0010,2152), LO, 1,  */
    extern const tag RegionOfResidence;
    /** RegionPixelShiftSequence, (0028,9502), SQ, 1,  */
    extern const tag RegionPixelShiftSequence;
    /** RegionSpatialFormat, (0018,6012), US, 1,  */
    extern const tag RegionSpatialFormat;
    /** RegistrationSequence, (0070,0308), SQ, 1,  */
    extern const tag RegistrationSequence;
    /** RegistrationTypeCodeSequence, (0070,030D), SQ, 1,  */
    extern const tag RegistrationTypeCodeSequence;
    /** RelatedFrameOfReferenceUID, (3006,00C2), UI, 1,  */
    extern const tag RelatedFrameOfReferenceUID;
    /** RelatedGeneralSOPClassUID, (0008,001A), UI, 1-n,  */
    extern const tag RelatedGeneralSOPClassUID;
    /** RelatedProcedureStepSequence, (0074,1220), SQ, 1, RET */
    extern const tag RelatedProcedureStepSequence;
    /** RelatedReferenceRTImageSequence, (0074,1040), SQ, 1,  */
    extern const tag RelatedReferenceRTImageSequence;
    /** RelatedRTROIObservationsSequence, (3006,00A0), SQ, 1,  */
    extern const tag RelatedRTROIObservationsSequence;
    /** RelatedSeriesSequence, (0008,1250), SQ, 1,  */
    extern const tag RelatedSeriesSequence;
    /** RelationshipSequenceTrial, (0040,A731), SQ, 1, RET */
    extern const tag RelationshipSequenceTrial;
    /** RelationshipType, (0040,A010), CS, 1,  */
    extern const tag RelationshipType;
    /** RelationshipTypeCodeSequenceTrial, (0040,A732), SQ, 1, RET */
    extern const tag RelationshipTypeCodeSequenceTrial;
    /** RelativeImagePositionCodeSequence, (0022,001D), SQ, 1,  */
    extern const tag RelativeImagePositionCodeSequence;
    /** RelativeOpacity, (0070,0403), FL, 1,  */
    extern const tag RelativeOpacity;
    /** RelativeTime, (0072,0038), US, 2,  */
    extern const tag RelativeTime;
    /** RelativeTimeUnits, (0072,003A), CS, 1,  */
    extern const tag RelativeTimeUnits;
    /** RelativeXRayExposure, (0018,1405), IS, 1,  */
    extern const tag RelativeXRayExposure;
    /** RelevantInformationSequence, (0040,4022), SQ, 1,  */
    extern const tag RelevantInformationSequence;
    /** RepeatFractionCycleLength, (300A,007A), IS, 1,  */
    extern const tag RepeatFractionCycleLength;
    /** RepeatInterval, (0028,0068), US, 1, RET */
    extern const tag RepeatInterval;
    /** RepetitionTime, (0018,0080), DS, 1,  */
    extern const tag RepetitionTime;
    /** ReplacedImplantAssemblyTemplateSequence, (0076,0008), SQ, 1,  */
    extern const tag ReplacedImplantAssemblyTemplateSequence;
    /** ReplacedImplantTemplateGroupSequence, (0078,0026), SQ, 1,  */
    extern const tag ReplacedImplantTemplateGroupSequence;
    /** ReplacedImplantTemplateSequence, (0068,6222), SQ, 1,  */
    extern const tag ReplacedImplantTemplateSequence;
    /** ReplacedProcedureStepSequence, (0074,1224), SQ, 1,  */
    extern const tag ReplacedProcedureStepSequence;
    /** ReportDetailSequenceTrial, (0040,A380), SQ, 1, RET */
    extern const tag ReportDetailSequenceTrial;
    /** ReportedValuesOrigin, (3002,000A), CS, 1,  */
    extern const tag ReportedValuesOrigin;
    /** ReportingPriority, (0040,1009), SH, 1,  */
    extern const tag ReportingPriority;
    /** ReportNumber, (0020,00AA), IS, 1, RET */
    extern const tag ReportNumber;
    /** ReportProductionStatusTrial, (4008,00FF), CS, 1, RET */
    extern const tag ReportProductionStatusTrial;
    /** ReportStatusCommentTrial, (0040,A33A), ST, 1, RET */
    extern const tag ReportStatusCommentTrial;
    /** ReportStatusIDTrial, (0040,A125), CS, 2, RET */
    extern const tag ReportStatusIDTrial;
    /** RepositoryUniqueID, (0040,E030), UI, 1,  */
    extern const tag RepositoryUniqueID;
    /** RepresentativeFrameNumber, (0028,6010), US, 1,  */
    extern const tag RepresentativeFrameNumber;
    /** ReprojectionMethod, (0054,1004), CS, 1,  */
    extern const tag ReprojectionMethod;
    /** RequestAttributesSequence, (0040,0275), SQ, 1,  */
    extern const tag RequestAttributesSequence;
    /** RequestedContrastAgent, (0032,1070), LO, 1,  */
    extern const tag RequestedContrastAgent;
    /** RequestedDecimateCropBehavior, (2020,0040), CS, 1,  */
    extern const tag RequestedDecimateCropBehavior;
    /** RequestedImageSize, (2020,0030), DS, 1,  */
    extern const tag RequestedImageSize;
    /** RequestedImageSizeFlag, (2020,00A0), CS, 1,  */
    extern const tag RequestedImageSizeFlag;
    /** RequestedMediaApplicationProfile, (2200,000C), LO, 1,  */
    extern const tag RequestedMediaApplicationProfile;
    /** RequestedProcedureCodeSequence, (0032,1064), SQ, 1,  */
    extern const tag RequestedProcedureCodeSequence;
    /** RequestedProcedureComments, (0040,1400), LT, 1,  */
    extern const tag RequestedProcedureComments;
    /** RequestedProcedureDescription, (0032,1060), LO, 1,  */
    extern const tag RequestedProcedureDescription;
    /** RequestedProcedureDescriptionTrial, (0040,1060), LO, 1, RET */
    extern const tag RequestedProcedureDescriptionTrial;
    /** RequestedProcedureID, (0040,1001), SH, 1,  */
    extern const tag RequestedProcedureID;
    /** RequestedProcedureLocation, (0040,1005), LO, 1,  */
    extern const tag RequestedProcedureLocation;
    /** RequestedProcedurePriority, (0040,1003), SH, 1,  */
    extern const tag RequestedProcedurePriority;
    /** RequestedResolutionID, (2020,0050), CS, 1,  */
    extern const tag RequestedResolutionID;
    /** RequestedSubsequentWorkitemCodeSequence, (0040,4031), SQ, 1,  */
    extern const tag RequestedSubsequentWorkitemCodeSequence;
    /** RequestingAE, (0074,1236), AE, 1,  */
    extern const tag RequestingAE;
    /** RequestingPhysician, (0032,1032), PN, 1,  */
    extern const tag RequestingPhysician;
    /** RequestingPhysicianIdentificationSequence, (0032,1031), SQ, 1,  */
    extern const tag RequestingPhysicianIdentificationSequence;
    /** RequestingService, (0032,1033), LO, 1,  */
    extern const tag RequestingService;
    /** RequestingServiceCodeSequence, (0032,1034), SQ, 1,  */
    extern const tag RequestingServiceCodeSequence;
    /** RequestPriority, (2200,0020), CS, 1,  */
    extern const tag RequestPriority;
    /** RescaleIntercept, (0028,1052), DS, 1,  */
    extern const tag RescaleIntercept;
    /** RescaleSlope, (0028,1053), DS, 1,  */
    extern const tag RescaleSlope;
    /** RescaleType, (0028,1054), LO, 1,  */
    extern const tag RescaleType;
    /** ResidualSyringeCounts, (0054,0017), IS, 1,  */
    extern const tag ResidualSyringeCounts;
    /** ResonantNucleus, (0018,9100), CS, 1-2,  */
    extern const tag ResonantNucleus;
    /** RespiratoryCyclePosition, (0018,9214), CS, 1,  */
    extern const tag RespiratoryCyclePosition;
    /** RespiratoryIntervalTime, (0020,9254), FD, 1,  */
    extern const tag RespiratoryIntervalTime;
    /** RespiratoryMotionCompensationTechnique, (0018,9170), CS, 1,  */
    extern const tag RespiratoryMotionCompensationTechnique;
    /** RespiratoryMotionCompensationTechniqueDescription, (0018,9185), ST, 1,  */
    extern const tag RespiratoryMotionCompensationTechniqueDescription;
    /** RespiratorySignalSource, (0018,9171), CS, 1,  */
    extern const tag RespiratorySignalSource;
    /** RespiratorySignalSourceID, (0018,9186), SH, 1,  */
    extern const tag RespiratorySignalSourceID;
    /** RespiratorySynchronizationSequence, (0020,9253), SQ, 1,  */
    extern const tag RespiratorySynchronizationSequence;
    /** RespiratoryTriggerDelayThreshold, (0020,9256), FD, 1,  */
    extern const tag RespiratoryTriggerDelayThreshold;
    /** RespiratoryTriggerType, (0020,9250), CS, 1,  */
    extern const tag RespiratoryTriggerType;
    /** ResponsibleOrganization, (0010,2299), LO, 1,  */
    extern const tag ResponsibleOrganization;
    /** ResponsiblePerson, (0010,2297), PN, 1,  */
    extern const tag ResponsiblePerson;
    /** ResponsiblePersonRole, (0010,2298), CS, 1,  */
    extern const tag ResponsiblePersonRole;
    /** ResultingGeneralPurposePerformedProcedureStepsSequence, (0040,4015), SQ, 1,  */
    extern const tag ResultingGeneralPurposePerformedProcedureStepsSequence;
    /** ResultsComments, (4008,4000), ST, 1, RET */
    extern const tag ResultsComments;
    /** ResultsDistributionListSequence, (4008,0118), SQ, 1, RET */
    extern const tag ResultsDistributionListSequence;
    /** ResultsID, (4008,0040), SH, 1, RET */
    extern const tag ResultsID;
    /** ResultsIDIssuer, (4008,0042), LO, 1, RET */
    extern const tag ResultsIDIssuer;
    /** ResultsNormalsSequence, (0024,0064), SQ, 1,  */
    extern const tag ResultsNormalsSequence;
    /** RetestSensitivityValue, (0024,0096), FL, 1,  */
    extern const tag RetestSensitivityValue;
    /** RetestStimulusSeen, (0024,0095), CS, 1,  */
    extern const tag RetestStimulusSeen;
    /** RetrieveAETitle, (0008,0054), AE, 1-n,  */
    extern const tag RetrieveAETitle;
    /** RetrieveLocationUID, (0040,E011), UI, 1,  */
    extern const tag RetrieveLocationUID;
    /** RetrieveURI, (0040,E010), UT, 1,  */
    extern const tag RetrieveURI;
    /** ReviewDate, (300E,0004), DA, 1,  */
    extern const tag ReviewDate;
    /** ReviewerName, (300E,0008), PN, 1,  */
    extern const tag ReviewerName;
    /** ReviewTime, (300E,0005), TM, 1,  */
    extern const tag ReviewTime;
    /** RevolutionTime, (0018,9305), FD, 1,  */
    extern const tag RevolutionTime;
    /** RFEchoTrainLength, (0018,9240), US, 1,  */
    extern const tag RFEchoTrainLength;
    /** RGBLUTTransferFunction, (0028,140F), CS, 1,  */
    extern const tag RGBLUTTransferFunction;
    /** RightImageSequence, (0022,0022), SQ, 1,  */
    extern const tag RightImageSequence;
    /** RightLensSequence, (0046,0014), SQ, 1,  */
    extern const tag RightLensSequence;
    /** ROIArea, (60XX,1301), IS, 1,  */
    extern const range_tag ROIArea;
    /** ROIContourSequence, (3006,0039), SQ, 1,  */
    extern const tag ROIContourSequence;
    /** ROIDescription, (3006,0028), ST, 1,  */
    extern const tag ROIDescription;
    /** ROIDisplayColor, (3006,002A), IS, 3,  */
    extern const tag ROIDisplayColor;
    /** ROIElementalCompositionAtomicMassFraction, (3006,00B8), FL, 1,  */
    extern const tag ROIElementalCompositionAtomicMassFraction;
    /** ROIElementalCompositionAtomicNumber, (3006,00B7), US, 1,  */
    extern const tag ROIElementalCompositionAtomicNumber;
    /** ROIElementalCompositionSequence, (3006,00B6), SQ, 1,  */
    extern const tag ROIElementalCompositionSequence;
    /** ROIGenerationAlgorithm, (3006,0036), CS, 1,  */
    extern const tag ROIGenerationAlgorithm;
    /** ROIGenerationDescription, (3006,0038), LO, 1,  */
    extern const tag ROIGenerationDescription;
    /** ROIInterpreter, (3006,00A6), PN, 1,  */
    extern const tag ROIInterpreter;
    /** ROIMean, (60XX,1302), DS, 1,  */
    extern const range_tag ROIMean;
    /** ROIName, (3006,0026), LO, 1,  */
    extern const tag ROIName;
    /** ROINumber, (3006,0022), IS, 1,  */
    extern const tag ROINumber;
    /** ROIObservationDescription, (3006,0088), ST, 1,  */
    extern const tag ROIObservationDescription;
    /** ROIObservationLabel, (3006,0085), SH, 1,  */
    extern const tag ROIObservationLabel;
    /** ROIPhysicalPropertiesSequence, (3006,00B0), SQ, 1,  */
    extern const tag ROIPhysicalPropertiesSequence;
    /** ROIPhysicalProperty, (3006,00B2), CS, 1,  */
    extern const tag ROIPhysicalProperty;
    /** ROIPhysicalPropertyValue, (3006,00B4), DS, 1,  */
    extern const tag ROIPhysicalPropertyValue;
    /** ROIStandardDeviation, (60XX,1303), DS, 1,  */
    extern const range_tag ROIStandardDeviation;
    /** ROIVolume, (3006,002C), DS, 1,  */
    extern const tag ROIVolume;
    /** RotationAngle, (0070,0230), FD, 1,  */
    extern const tag RotationAngle;
    /** RotationDirection, (0018,1140), CS, 1,  */
    extern const tag RotationDirection;
    /** RotationInformationSequence, (0054,0052), SQ, 1,  */
    extern const tag RotationInformationSequence;
    /** RotationOffset, (0018,1146), DS, 1-n, RET */
    extern const tag RotationOffset;
    /** RotationOfScannedFilm, (0018,2030), DS, 1,  */
    extern const tag RotationOfScannedFilm;
    /** RotationPoint, (0070,0273), FL, 2,  */
    extern const tag RotationPoint;
    /** RotationVector, (0054,0050), US, 1-n,  */
    extern const tag RotationVector;
    /** RouteID, (4010,1054), SH, 1,  */
    extern const tag RouteID;
    /** RouteIDAssigningAuthority, (4010,1055), SH, 1,  */
    extern const tag RouteIDAssigningAuthority;
    /** RouteOfAdmissions, (0038,0016), LO, 1,  */
    extern const tag RouteOfAdmissions;
    /** RouteSegmentEndLocationID, (4010,101F), SH, 1,  */
    extern const tag RouteSegmentEndLocationID;
    /** RouteSegmentEndTime, (4010,1026), DT, 1,  */
    extern const tag RouteSegmentEndTime;
    /** RouteSegmentID, (4010,1007), SH, 1,  */
    extern const tag RouteSegmentID;
    /** RouteSegmentLocationIDType, (4010,1020), CS, 1,  */
    extern const tag RouteSegmentLocationIDType;
    /** RouteSegmentSequence, (4010,100A), SQ, 1,  */
    extern const tag RouteSegmentSequence;
    /** RouteSegmentStartLocationID, (4010,101E), SH, 1,  */
    extern const tag RouteSegmentStartLocationID;
    /** RouteSegmentStartTime, (4010,1025), DT, 1,  */
    extern const tag RouteSegmentStartTime;
    /** RowOverlap, (0028,0093), US, 1, RET */
    extern const tag RowOverlap;
    /** RowPositionInTotalImagePixelMatrix, (0048,021E), SL, 1,  */
    extern const tag RowPositionInTotalImagePixelMatrix;
    /** Rows, (0028,0010), US, 1,  */
    extern const tag Rows;
    /** RowsForNthOrderCoefficients, (0028,04X0), US, 1, RET */
    extern const range_tag RowsForNthOrderCoefficients;
    /** RRIntervalTimeNominal, (0020,9251), FD, 1,  */
    extern const tag RRIntervalTimeNominal;
    /** RRIntervalVector, (0054,0060), US, 1-n,  */
    extern const tag RRIntervalVector;
    /** RTBeamLimitingDeviceType, (300A,00B8), CS, 1,  */
    extern const tag RTBeamLimitingDeviceType;
    /** RTDoseROISequence, (3004,0010), SQ, 1,  */
    extern const tag RTDoseROISequence;
    /** RTImageDescription, (3002,0004), ST, 1,  */
    extern const tag RTImageDescription;
    /** RTImageLabel, (3002,0002), SH, 1,  */
    extern const tag RTImageLabel;
    /** RTImageName, (3002,0003), LO, 1,  */
    extern const tag RTImageName;
    /** RTImageOrientation, (3002,0010), DS, 6,  */
    extern const tag RTImageOrientation;
    /** RTImagePlane, (3002,000C), CS, 1,  */
    extern const tag RTImagePlane;
    /** RTImagePosition, (3002,0012), DS, 2,  */
    extern const tag RTImagePosition;
    /** RTImageSID, (3002,0026), DS, 1,  */
    extern const tag RTImageSID;
    /** RTPlanDate, (300A,0006), DA, 1,  */
    extern const tag RTPlanDate;
    /** RTPlanDescription, (300A,0004), ST, 1,  */
    extern const tag RTPlanDescription;
    /** RTPlanGeometry, (300A,000C), CS, 1,  */
    extern const tag RTPlanGeometry;
    /** RTPlanLabel, (300A,0002), SH, 1,  */
    extern const tag RTPlanLabel;
    /** RTPlanName, (300A,0003), LO, 1,  */
    extern const tag RTPlanName;
    /** RTPlanRelationship, (300A,0055), CS, 1,  */
    extern const tag RTPlanRelationship;
    /** RTPlanTime, (300A,0007), TM, 1,  */
    extern const tag RTPlanTime;
    /** RTReferencedSeriesSequence, (3006,0014), SQ, 1,  */
    extern const tag RTReferencedSeriesSequence;
    /** RTReferencedStudySequence, (3006,0012), SQ, 1,  */
    extern const tag RTReferencedStudySequence;
    /** RTRelatedROISequence, (3006,0030), SQ, 1,  */
    extern const tag RTRelatedROISequence;
    /** RTROIIdentificationCodeSequence, (3006,0086), SQ, 1,  */
    extern const tag RTROIIdentificationCodeSequence;
    /** RTROIInterpretedType, (3006,00A4), CS, 1,  */
    extern const tag RTROIInterpretedType;
    /** RTROIObservationsSequence, (3006,0080), SQ, 1,  */
    extern const tag RTROIObservationsSequence;
    /** RTROIRelationship, (3006,0033), CS, 1,  */
    extern const tag RTROIRelationship;
    /** RunLengthTriplet, (1000,XXX1), US, 3, RET */
    extern const range_tag RunLengthTriplet;
    /** RWavePointer, (0028,6040), US, 1-n,  */
    extern const tag RWavePointer;
    /** RWaveTimeVector, (0018,6060), FL, 1-n,  */
    extern const tag RWaveTimeVector;
    /** SafePositionExitDate, (3008,0162), DA, 1,  */
    extern const tag SafePositionExitDate;
    /** SafePositionExitTime, (3008,0164), TM, 1,  */
    extern const tag SafePositionExitTime;
    /** SafePositionReturnDate, (3008,0166), DA, 1,  */
    extern const tag SafePositionReturnDate;
    /** SafePositionReturnTime, (3008,0168), TM, 1,  */
    extern const tag SafePositionReturnTime;
    /** SampleRate, (50XX,2008), UL, 1, RET */
    extern const range_tag SampleRate;
    /** SamplesPerPixel, (0028,0002), US, 1,  */
    extern const tag SamplesPerPixel;
    /** SamplesPerPixelUsed, (0028,0003), US, 1,  */
    extern const tag SamplesPerPixelUsed;
    /** SamplingFrequency, (003A,001A), DS, 1,  */
    extern const tag SamplingFrequency;
    /** SAR, (0018,1316), DS, 1,  */
    extern const tag SAR;
    /** SaturationRecovery, (0018,9024), CS, 1,  */
    extern const tag SaturationRecovery;
    /** ScanArc, (0018,1143), DS, 1,  */
    extern const tag ScanArc;
    /** ScanLength, (0018,1302), IS, 1,  */
    extern const tag ScanLength;
    /** ScanMode, (300A,0308), CS, 1,  */
    extern const tag ScanMode;
    /** ScanningSequence, (0018,0020), CS, 1-n,  */
    extern const tag ScanningSequence;
    /** ScanningSpotSize, (300A,0398), FL, 2,  */
    extern const tag ScanningSpotSize;
    /** ScanOptions, (0018,0022), CS, 1-n,  */
    extern const tag ScanOptions;
    /** ScanSpotMetersetsDelivered, (3008,0047), FL, 1-n,  */
    extern const tag ScanSpotMetersetsDelivered;
    /** ScanSpotMetersetWeights, (300A,0396), FL, 1-n,  */
    extern const tag ScanSpotMetersetWeights;
    /** ScanSpotPositionMap, (300A,0394), FL, 1-n,  */
    extern const tag ScanSpotPositionMap;
    /** ScanSpotTuneID, (300A,0390), SH, 1,  */
    extern const tag ScanSpotTuneID;
    /** ScanType, (4010,1048), CS, 1,  */
    extern const tag ScanType;
    /** ScanVelocity, (0018,1300), DS, 1,  */
    extern const tag ScanVelocity;
    /** ScatterCorrected, (0018,9760), CS, 1,  */
    extern const tag ScatterCorrected;
    /** ScatterCorrectionMethod, (0054,1105), LO, 1,  */
    extern const tag ScatterCorrectionMethod;
    /** ScatterFractionFactor, (0054,1323), DS, 1,  */
    extern const tag ScatterFractionFactor;
    /** ScheduledAdmissionDate, (0038,001A), DA, 1, RET */
    extern const tag ScheduledAdmissionDate;
    /** ScheduledAdmissionTime, (0038,001B), TM, 1, RET */
    extern const tag ScheduledAdmissionTime;
    /** ScheduledDischargeDate, (0038,001C), DA, 1, RET */
    extern const tag ScheduledDischargeDate;
    /** ScheduledDischargeTime, (0038,001D), TM, 1, RET */
    extern const tag ScheduledDischargeTime;
    /** ScheduledHumanPerformersSequence, (0040,4034), SQ, 1,  */
    extern const tag ScheduledHumanPerformersSequence;
    /** ScheduledPatientInstitutionResidence, (0038,001E), LO, 1, RET */
    extern const tag ScheduledPatientInstitutionResidence;
    /** ScheduledPerformingPhysicianIdentificationSequence, (0040,000B), SQ, 1,  */
    extern const tag ScheduledPerformingPhysicianIdentificationSequence;
    /** ScheduledPerformingPhysicianName, (0040,0006), PN, 1,  */
    extern const tag ScheduledPerformingPhysicianName;
    /** ScheduledProcedureStepDescription, (0040,0007), LO, 1,  */
    extern const tag ScheduledProcedureStepDescription;
    /** ScheduledProcedureStepEndDate, (0040,0004), DA, 1,  */
    extern const tag ScheduledProcedureStepEndDate;
    /** ScheduledProcedureStepEndTime, (0040,0005), TM, 1,  */
    extern const tag ScheduledProcedureStepEndTime;
    /** ScheduledProcedureStepID, (0040,0009), SH, 1,  */
    extern const tag ScheduledProcedureStepID;
    /** ScheduledProcedureStepLocation, (0040,0011), SH, 1,  */
    extern const tag ScheduledProcedureStepLocation;
    /** ScheduledProcedureStepModificationDateTime, (0040,4010), DT, 1,  */
    extern const tag ScheduledProcedureStepModificationDateTime;
    /** ScheduledProcedureStepPriority, (0074,1200), CS, 1,  */
    extern const tag ScheduledProcedureStepPriority;
    /** ScheduledProcedureStepSequence, (0040,0100), SQ, 1,  */
    extern const tag ScheduledProcedureStepSequence;
    /** ScheduledProcedureStepStartDate, (0040,0002), DA, 1,  */
    extern const tag ScheduledProcedureStepStartDate;
    /** ScheduledProcedureStepStartDateTime, (0040,4005), DT, 1,  */
    extern const tag ScheduledProcedureStepStartDateTime;
    /** ScheduledProcedureStepStartTime, (0040,0003), TM, 1,  */
    extern const tag ScheduledProcedureStepStartTime;
    /** ScheduledProcedureStepStatus, (0040,0020), CS, 1,  */
    extern const tag ScheduledProcedureStepStatus;
    /** ScheduledProcessingApplicationsCodeSequence, (0040,4004), SQ, 1,  */
    extern const tag ScheduledProcessingApplicationsCodeSequence;
    /** ScheduledProcessingParametersSequence, (0074,1210), SQ, 1,  */
    extern const tag ScheduledProcessingParametersSequence;
    /** ScheduledProtocolCodeSequence, (0040,0008), SQ, 1,  */
    extern const tag ScheduledProtocolCodeSequence;
    /** ScheduledSpecimenSequence, (0040,0500), SQ, 1,  */
    extern const tag ScheduledSpecimenSequence;
    /** ScheduledStationAETitle, (0040,0001), AE, 1-n,  */
    extern const tag ScheduledStationAETitle;
    /** ScheduledStationClassCodeSequence, (0040,4026), SQ, 1,  */
    extern const tag ScheduledStationClassCodeSequence;
    /** ScheduledStationGeographicLocationCodeSequence, (0040,4027), SQ, 1,  */
    extern const tag ScheduledStationGeographicLocationCodeSequence;
    /** ScheduledStationName, (0040,0010), SH, 1-n,  */
    extern const tag ScheduledStationName;
    /** ScheduledStationNameCodeSequence, (0040,4025), SQ, 1,  */
    extern const tag ScheduledStationNameCodeSequence;
    /** ScheduledStepAttributesSequence, (0040,0270), SQ, 1,  */
    extern const tag ScheduledStepAttributesSequence;
    /** ScheduledStudyLocation, (0032,1020), LO, 1, RET */
    extern const tag ScheduledStudyLocation;
    /** ScheduledStudyLocationAETitle, (0032,1021), AE, 1-n, RET */
    extern const tag ScheduledStudyLocationAETitle;
    /** ScheduledStudyStartDate, (0032,1000), DA, 1, RET */
    extern const tag ScheduledStudyStartDate;
    /** ScheduledStudyStartTime, (0032,1001), TM, 1, RET */
    extern const tag ScheduledStudyStartTime;
    /** ScheduledStudyStopDate, (0032,1010), DA, 1, RET */
    extern const tag ScheduledStudyStopDate;
    /** ScheduledStudyStopTime, (0032,1011), TM, 1, RET */
    extern const tag ScheduledStudyStopTime;
    /** ScheduledWorkitemCodeSequence, (0040,4018), SQ, 1,  */
    extern const tag ScheduledWorkitemCodeSequence;
    /** SCPStatus, (0074,1242), CS, 1,  */
    extern const tag SCPStatus;
    /** ScreeningBaselineMeasured, (0024,0120), CS, 1,  */
    extern const tag ScreeningBaselineMeasured;
    /** ScreeningBaselineMeasuredSequence, (0024,0122), SQ, 1,  */
    extern const tag ScreeningBaselineMeasuredSequence;
    /** ScreeningBaselineType, (0024,0124), CS, 1,  */
    extern const tag ScreeningBaselineType;
    /** ScreeningBaselineValue, (0024,0126), FL, 1,  */
    extern const tag ScreeningBaselineValue;
    /** ScreeningTestModeCodeSequence, (0024,0016), SQ, 1,  */
    extern const tag ScreeningTestModeCodeSequence;
    /** ScreenMinimumColorBitDepth, (0072,010C), US, 1,  */
    extern const tag ScreenMinimumColorBitDepth;
    /** ScreenMinimumGrayscaleBitDepth, (0072,010A), US, 1,  */
    extern const tag ScreenMinimumGrayscaleBitDepth;
    /** SeamLineIndex, (0052,0036), US, 1,  */
    extern const tag SeamLineIndex;
    /** SeamLineLocation, (0052,0033), FD, 1,  */
    extern const tag SeamLineLocation;
    /** SecondaryCaptureDeviceID, (0018,1010), LO, 1,  */
    extern const tag SecondaryCaptureDeviceID;
    /** SecondaryCaptureDeviceManufacturer, (0018,1016), LO, 1,  */
    extern const tag SecondaryCaptureDeviceManufacturer;
    /** SecondaryCaptureDeviceManufacturerModelName, (0018,1018), LO, 1,  */
    extern const tag SecondaryCaptureDeviceManufacturerModelName;
    /** SecondaryCaptureDeviceSoftwareVersions, (0018,1019), LO, 1-n,  */
    extern const tag SecondaryCaptureDeviceSoftwareVersions;
    /** SecondaryCountsAccumulated, (0054,1311), IS, 1-n,  */
    extern const tag SecondaryCountsAccumulated;
    /** SecondaryCountsType, (0054,1220), CS, 1-n,  */
    extern const tag SecondaryCountsType;
    /** SecondaryPositionerIncrement, (0018,9515), FL, 1,  */
    extern const tag SecondaryPositionerIncrement;
    /** SecondaryPositionerScanArc, (0018,9509), FL, 1,  */
    extern const tag SecondaryPositionerScanArc;
    /** SecondaryPositionerScanStartAngle, (0018,9511), FL, 1,  */
    extern const tag SecondaryPositionerScanStartAngle;
    /** SegmentAlgorithmName, (0062,0009), LO, 1,  */
    extern const tag SegmentAlgorithmName;
    /** SegmentAlgorithmType, (0062,0008), CS, 1,  */
    extern const tag SegmentAlgorithmType;
    /** SegmentationFractionalType, (0062,0010), CS, 1,  */
    extern const tag SegmentationFractionalType;
    /** SegmentationType, (0062,0001), CS, 1,  */
    extern const tag SegmentationType;
    /** SegmentDescription, (0062,0006), ST, 1,  */
    extern const tag SegmentDescription;
    /** SegmentedBluePaletteColorLookupTableData, (0028,1223), OW, 1,  */
    extern const tag SegmentedBluePaletteColorLookupTableData;
    /** SegmentedGreenPaletteColorLookupTableData, (0028,1222), OW, 1,  */
    extern const tag SegmentedGreenPaletteColorLookupTableData;
    /** SegmentedKSpaceTraversal, (0018,9033), CS, 1,  */
    extern const tag SegmentedKSpaceTraversal;
    /** SegmentedPropertyCategoryCodeSequence, (0062,0003), SQ, 1,  */
    extern const tag SegmentedPropertyCategoryCodeSequence;
    /** SegmentedPropertyTypeCodeSequence, (0062,000F), SQ, 1,  */
    extern const tag SegmentedPropertyTypeCodeSequence;
    /** SegmentedRedPaletteColorLookupTableData, (0028,1221), OW, 1,  */
    extern const tag SegmentedRedPaletteColorLookupTableData;
    /** SegmentIdentificationSequence, (0062,000A), SQ, 1,  */
    extern const tag SegmentIdentificationSequence;
    /** SegmentLabel, (0062,0005), LO, 1,  */
    extern const tag SegmentLabel;
    /** SegmentNumber, (0062,0004), US, 1,  */
    extern const tag SegmentNumber;
    /** SegmentSequence, (0062,0002), SQ, 1,  */
    extern const tag SegmentSequence;
    /** SegmentSurfaceGenerationAlgorithmIdentificationSequence, (0066,002D), SQ, 1,  */
    extern const tag SegmentSurfaceGenerationAlgorithmIdentificationSequence;
    /** SegmentSurfaceSourceInstanceSequence, (0066,002E), SQ, 1,  */
    extern const tag SegmentSurfaceSourceInstanceSequence;
    /** SelectedSegmentalOphthalmicAxialLengthSequence, (0022,1257), SQ, 1,  */
    extern const tag SelectedSegmentalOphthalmicAxialLengthSequence;
    /** SelectedTotalOphthalmicAxialLengthSequence, (0022,1260), SQ, 1,  */
    extern const tag SelectedTotalOphthalmicAxialLengthSequence;
    /** SelectorAttribute, (0072,0026), AT, 1,  */
    extern const tag SelectorAttribute;
    /** SelectorAttributePrivateCreator, (0072,0056), LO, 1,  */
    extern const tag SelectorAttributePrivateCreator;
    /** SelectorAttributeVR, (0072,0050), CS, 1,  */
    extern const tag SelectorAttributeVR;
    /** SelectorATValue, (0072,0060), AT, 1-n,  */
    extern const tag SelectorATValue;
    /** SelectorCodeSequenceValue, (0072,0080), SQ, 1,  */
    extern const tag SelectorCodeSequenceValue;
    /** SelectorCSValue, (0072,0062), CS, 1-n,  */
    extern const tag SelectorCSValue;
    /** SelectorDSValue, (0072,0072), DS, 1-n,  */
    extern const tag SelectorDSValue;
    /** SelectorFDValue, (0072,0074), FD, 1-n,  */
    extern const tag SelectorFDValue;
    /** SelectorFLValue, (0072,0076), FL, 1-n,  */
    extern const tag SelectorFLValue;
    /** SelectorISValue, (0072,0064), IS, 1-n,  */
    extern const tag SelectorISValue;
    /** SelectorLOValue, (0072,0066), LO, 1-n,  */
    extern const tag SelectorLOValue;
    /** SelectorLTValue, (0072,0068), LT, 1,  */
    extern const tag SelectorLTValue;
    /** SelectorPNValue, (0072,006A), PN, 1-n,  */
    extern const tag SelectorPNValue;
    /** SelectorSequencePointer, (0072,0052), AT, 1-n,  */
    extern const tag SelectorSequencePointer;
    /** SelectorSequencePointerItems, (0074,1057), IS, 1-n,  */
    extern const tag SelectorSequencePointerItems;
    /** SelectorSequencePointerPrivateCreator, (0072,0054), LO, 1-n,  */
    extern const tag SelectorSequencePointerPrivateCreator;
    /** SelectorSHValue, (0072,006C), SH, 1-n,  */
    extern const tag SelectorSHValue;
    /** SelectorSLValue, (0072,007C), SL, 1-n,  */
    extern const tag SelectorSLValue;
    /** SelectorSSValue, (0072,007E), SS, 1-n,  */
    extern const tag SelectorSSValue;
    /** SelectorSTValue, (0072,006E), ST, 1,  */
    extern const tag SelectorSTValue;
    /** SelectorULValue, (0072,0078), UL, 1-n,  */
    extern const tag SelectorULValue;
    /** SelectorUSValue, (0072,007A), US, 1-n,  */
    extern const tag SelectorUSValue;
    /** SelectorUTValue, (0072,0070), UT, 1,  */
    extern const tag SelectorUTValue;
    /** SelectorValueNumber, (0072,0028), US, 1,  */
    extern const tag SelectorValueNumber;
    /** Sensitivity, (0018,6000), DS, 1,  */
    extern const tag Sensitivity;
    /** SensitivityCalibrated, (0018,9767), CS, 1,  */
    extern const tag SensitivityCalibrated;
    /** SensitivityValue, (0024,0094), FL, 1,  */
    extern const tag SensitivityValue;
    /** SensorName, (0014,3022), DS, 1,  */
    extern const tag SensorName;
    /** SensorTemperature, (0014,3028), DS, 1,  */
    extern const tag SensorTemperature;
    /** SequenceName, (0018,0024), SH, 1,  */
    extern const tag SequenceName;
    /** SequenceOfCompressedData, (0028,0403), LO, 1-n, RET */
    extern const tag SequenceOfCompressedData;
    /** SequenceOfUltrasoundRegions, (0018,6011), SQ, 1,  */
    extern const tag SequenceOfUltrasoundRegions;
    /** SequenceVariant, (0018,0021), CS, 1-n,  */
    extern const tag SequenceVariant;
    /** SequencingIndicatorTrial, (0040,A060), LO, 1, RET */
    extern const tag SequencingIndicatorTrial;
    /** SeriesDate, (0008,0021), DA, 1,  */
    extern const tag SeriesDate;
    /** SeriesDescription, (0008,103E), LO, 1,  */
    extern const tag SeriesDescription;
    /** SeriesDescriptionCodeSequence, (0008,103F), SQ, 1,  */
    extern const tag SeriesDescriptionCodeSequence;
    /** SeriesInstanceUID, (0020,000E), UI, 1,  */
    extern const tag SeriesInstanceUID;
    /** SeriesInStudy, (0020,1000), IS, 1, RET */
    extern const tag SeriesInStudy;
    /** SeriesNumber, (0020,0011), IS, 1,  */
    extern const tag SeriesNumber;
    /** SeriesTime, (0008,0031), TM, 1,  */
    extern const tag SeriesTime;
    /** SeriesType, (0054,1000), CS, 2,  */
    extern const tag SeriesType;
    /** ServiceEpisodeDescription, (0038,0062), LO, 1,  */
    extern const tag ServiceEpisodeDescription;
    /** ServiceEpisodeID, (0038,0060), LO, 1,  */
    extern const tag ServiceEpisodeID;
    /** SetupDeviceDescription, (300A,01BA), ST, 1,  */
    extern const tag SetupDeviceDescription;
    /** SetupDeviceLabel, (300A,01B8), SH, 1,  */
    extern const tag SetupDeviceLabel;
    /** SetupDeviceParameter, (300A,01BC), DS, 1,  */
    extern const tag SetupDeviceParameter;
    /** SetupDeviceSequence, (300A,01B4), SQ, 1,  */
    extern const tag SetupDeviceSequence;
    /** SetupDeviceType, (300A,01B6), CS, 1,  */
    extern const tag SetupDeviceType;
    /** SetupImageComment, (300A,0402), ST, 1,  */
    extern const tag SetupImageComment;
    /** SetupReferenceDescription, (300A,01D0), ST, 1,  */
    extern const tag SetupReferenceDescription;
    /** SetupTechnique, (300A,01B0), CS, 1,  */
    extern const tag SetupTechnique;
    /** SetupTechniqueDescription, (300A,01B2), ST, 1,  */
    extern const tag SetupTechniqueDescription;
    /** ShadowColorCIELabValue, (0070,0247), US, 3,  */
    extern const tag ShadowColorCIELabValue;
    /** ShadowOffsetX, (0070,0245), FL, 1,  */
    extern const tag ShadowOffsetX;
    /** ShadowOffsetY, (0070,0246), FL, 1,  */
    extern const tag ShadowOffsetY;
    /** ShadowOpacity, (0070,0258), FL, 1,  */
    extern const tag ShadowOpacity;
    /** ShadowStyle, (0070,0244), CS, 1,  */
    extern const tag ShadowStyle;
    /** ShapeType, (0070,0306), CS, 1,  */
    extern const tag ShapeType;
    /** SharedFunctionalGroupsSequence, (5200,9229), SQ, 1,  */
    extern const tag SharedFunctionalGroupsSequence;
    /** ShieldingDeviceDescription, (300A,01A6), ST, 1,  */
    extern const tag ShieldingDeviceDescription;
    /** ShieldingDeviceLabel, (300A,01A4), SH, 1,  */
    extern const tag ShieldingDeviceLabel;
    /** ShieldingDevicePosition, (300A,01A8), SH, 1,  */
    extern const tag ShieldingDevicePosition;
    /** ShieldingDeviceSequence, (300A,01A0), SQ, 1,  */
    extern const tag ShieldingDeviceSequence;
    /** ShieldingDeviceType, (300A,01A2), CS, 1,  */
    extern const tag ShieldingDeviceType;
    /** ShiftTableSize, (1000,XXX4), US, 1, RET */
    extern const range_tag ShiftTableSize;
    /** ShiftTableTriplet, (1000,XXX5), US, 3, RET */
    extern const range_tag ShiftTableTriplet;
    /** ShortTermFluctuation, (0024,0075), FL, 1,  */
    extern const tag ShortTermFluctuation;
    /** ShortTermFluctuationCalculated, (0024,0074), CS, 1,  */
    extern const tag ShortTermFluctuationCalculated;
    /** ShortTermFluctuationProbability, (0024,0077), FL, 1,  */
    extern const tag ShortTermFluctuationProbability;
    /** ShortTermFluctuationProbabilityCalculated, (0024,0076), CS, 1,  */
    extern const tag ShortTermFluctuationProbabilityCalculated;
    /** ShowAcquisitionTechniquesFlag, (0072,0716), CS, 1,  */
    extern const tag ShowAcquisitionTechniquesFlag;
    /** ShowGraphicAnnotationFlag, (0072,0712), CS, 1,  */
    extern const tag ShowGraphicAnnotationFlag;
    /** ShowGrayscaleInverted, (0072,0706), CS, 1,  */
    extern const tag ShowGrayscaleInverted;
    /** ShowImageTrueSizeFlag, (0072,0710), CS, 1,  */
    extern const tag ShowImageTrueSizeFlag;
    /** ShowPatientDemographicsFlag, (0072,0714), CS, 1,  */
    extern const tag ShowPatientDemographicsFlag;
    /** ShowTickLabel, (0070,0278), CS, 1,  */
    extern const tag ShowTickLabel;
    /** ShutterLeftVerticalEdge, (0018,1602), IS, 1,  */
    extern const tag ShutterLeftVerticalEdge;
    /** ShutterLowerHorizontalEdge, (0018,1608), IS, 1,  */
    extern const tag ShutterLowerHorizontalEdge;
    /** ShutterOverlayGroup, (0018,1623), US, 1,  */
    extern const tag ShutterOverlayGroup;
    /** ShutterPresentationColorCIELabValue, (0018,1624), US, 3,  */
    extern const tag ShutterPresentationColorCIELabValue;
    /** ShutterPresentationValue, (0018,1622), US, 1,  */
    extern const tag ShutterPresentationValue;
    /** ShutterRightVerticalEdge, (0018,1604), IS, 1,  */
    extern const tag ShutterRightVerticalEdge;
    /** ShutterShape, (0018,1600), CS, 1-3,  */
    extern const tag ShutterShape;
    /** ShutterUpperHorizontalEdge, (0018,1606), IS, 1,  */
    extern const tag ShutterUpperHorizontalEdge;
    /** SignalDomainColumns, (0028,9003), CS, 1,  */
    extern const tag SignalDomainColumns;
    /** SignalDomainRows, (0028,9235), CS, 1,  */
    extern const tag SignalDomainRows;
    /** SignalToNoiseRatio, (0022,1155), FL, 1,  */
    extern const tag SignalToNoiseRatio;
    /** Signature, (0400,0120), OB, 1,  */
    extern const tag Signature;
    /** SimpleFrameList, (0008,1161), UL, 1-n,  */
    extern const tag SimpleFrameList;
    /** SingleCollimationWidth, (0018,9306), FD, 1,  */
    extern const tag SingleCollimationWidth;
    /** SkipBeats, (0018,1086), IS, 1,  */
    extern const tag SkipBeats;
    /** SkipFrameRangeFlag, (0008,9460), CS, 1,  */
    extern const tag SkipFrameRangeFlag;
    /** SlabOrientation, (0018,9105), FD, 3,  */
    extern const tag SlabOrientation;
    /** SlabThickness, (0018,9104), FD, 1,  */
    extern const tag SlabThickness;
    /** SliceLocation, (0020,1041), DS, 1,  */
    extern const tag SliceLocation;
    /** SliceLocationVector, (0018,2005), DS, 1-n,  */
    extern const tag SliceLocationVector;
    /** SliceProgressionDirection, (0054,0500), CS, 1,  */
    extern const tag SliceProgressionDirection;
    /** SliceSensitivityFactor, (0054,1320), DS, 1,  */
    extern const tag SliceSensitivityFactor;
    /** SliceThickness, (0018,0050), DS, 1,  */
    extern const tag SliceThickness;
    /** SliceVector, (0054,0080), US, 1-n,  */
    extern const tag SliceVector;
    /** SlideIdentifier, (0040,06FA), LO, 1, RET */
    extern const tag SlideIdentifier;
    /** SmallestImagePixelValue, (0028,0106), US or SS, 1,  */
    extern const tag SmallestImagePixelValue;
    /** SmallestImagePixelValueInPlane, (0028,0110), US or SS, 1, RET */
    extern const tag SmallestImagePixelValueInPlane;
    /** SmallestPixelValueInSeries, (0028,0108), US or SS, 1,  */
    extern const tag SmallestPixelValueInSeries;
    /** SmallestValidPixelValue, (0028,0104), US or SS, 1, RET */
    extern const tag SmallestValidPixelValue;
    /** SmokingStatus, (0010,21A0), CS, 1,  */
    extern const tag SmokingStatus;
    /** SmoothingType, (2010,0080), CS, 1,  */
    extern const tag SmoothingType;
    /** SnoutID, (300A,030F), SH, 1,  */
    extern const tag SnoutID;
    /** SnoutPosition, (300A,030D), FL, 1,  */
    extern const tag SnoutPosition;
    /** SnoutPositionTolerance, (300A,004B), FL, 1,  */
    extern const tag SnoutPositionTolerance;
    /** SnoutSequence, (300A,030C), SQ, 1,  */
    extern const tag SnoutSequence;
    /** SoftcopyVOILUTSequence, (0028,3110), SQ, 1,  */
    extern const tag SoftcopyVOILUTSequence;
    /** SoftTissueFocusThermalIndex, (0018,5028), DS, 1,  */
    extern const tag SoftTissueFocusThermalIndex;
    /** SoftTissueSurfaceThermalIndex, (0018,5029), DS, 1,  */
    extern const tag SoftTissueSurfaceThermalIndex;
    /** SoftTissueThermalIndex, (0018,5027), DS, 1,  */
    extern const tag SoftTissueThermalIndex;
    /** SoftwareVersions, (0018,1020), LO, 1-n,  */
    extern const tag SoftwareVersions;
    /** SOPAuthorizationComment, (0100,0424), LT, 1,  */
    extern const tag SOPAuthorizationComment;
    /** SOPAuthorizationDateTime, (0100,0420), DT, 1,  */
    extern const tag SOPAuthorizationDateTime;
    /** SOPClassesInStudy, (0008,0062), UI, 1-n,  */
    extern const tag SOPClassesInStudy;
    /** SOPClassesSupported, (0008,115A), UI, 1-n,  */
    extern const tag SOPClassesSupported;
    /** SOPClassUID, (0008,0016), UI, 1,  */
    extern const tag SOPClassUID;
    /** SOPInstanceStatus, (0100,0410), CS, 1,  */
    extern const tag SOPInstanceStatus;
    /** SOPInstanceUID, (0008,0018), UI, 1,  */
    extern const tag SOPInstanceUID;
    /** SOPInstanceUIDOfConcatenationSource, (0020,0242), UI, 1,  */
    extern const tag SOPInstanceUIDOfConcatenationSource;
    /** SortByCategory, (0072,0602), CS, 1,  */
    extern const tag SortByCategory;
    /** SortingDirection, (0072,0604), CS, 1,  */
    extern const tag SortingDirection;
    /** SortingOperationsSequence, (0072,0600), SQ, 1,  */
    extern const tag SortingOperationsSequence;
    /** SoundPathLength, (0014,405A), DS, 1,  */
    extern const tag SoundPathLength;
    /** SourceApplicationEntityTitle, (0002,0016), AE, 1,  */
    extern const tag SourceApplicationEntityTitle;
    /** SourceApplicatorID, (300A,0291), SH, 1,  */
    extern const tag SourceApplicatorID;
    /** SourceApplicatorLength, (300A,0296), DS, 1,  */
    extern const tag SourceApplicatorLength;
    /** SourceApplicatorManufacturer, (300A,0298), LO, 1,  */
    extern const tag SourceApplicatorManufacturer;
    /** SourceApplicatorName, (300A,0294), LO, 1,  */
    extern const tag SourceApplicatorName;
    /** SourceApplicatorNumber, (300A,0290), IS, 1,  */
    extern const tag SourceApplicatorNumber;
    /** SourceApplicatorStepSize, (300A,02A0), DS, 1,  */
    extern const tag SourceApplicatorStepSize;
    /** SourceApplicatorType, (300A,0292), CS, 1,  */
    extern const tag SourceApplicatorType;
    /** SourceApplicatorWallNominalThickness, (300A,029C), DS, 1,  */
    extern const tag SourceApplicatorWallNominalThickness;
    /** SourceApplicatorWallNominalTransmission, (300A,029E), DS, 1,  */
    extern const tag SourceApplicatorWallNominalTransmission;
    /** SourceAxisDistance, (300A,00B4), DS, 1,  */
    extern const tag SourceAxisDistance;
    /** SourceEncapsulationNominalThickness, (300A,0222), DS, 1,  */
    extern const tag SourceEncapsulationNominalThickness;
    /** SourceEncapsulationNominalTransmission, (300A,0224), DS, 1,  */
    extern const tag SourceEncapsulationNominalTransmission;
    /** SourceFrameOfReferenceUID, (0064,0003), UI, 1,  */
    extern const tag SourceFrameOfReferenceUID;
    /** SourceHangingProtocolSequence, (0072,0012), SQ, 1,  */
    extern const tag SourceHangingProtocolSequence;
    /** SourceImageEvidenceSequence, (0008,9154), SQ, 1,  */
    extern const tag SourceImageEvidenceSequence;
    /** SourceImageIDs, (0020,31XX), CS, 1-n, RET */
    extern const range_tag SourceImageIDs;
    /** SourceImageSequence, (0008,2112), SQ, 1,  */
    extern const tag SourceImageSequence;
    /** SourceInstanceSequence, (0042,0013), SQ, 1,  */
    extern const tag SourceInstanceSequence;
    /** SourceIsotopeHalfLife, (300A,0228), DS, 1,  */
    extern const tag SourceIsotopeHalfLife;
    /** SourceIsotopeName, (300A,0226), LO, 1,  */
    extern const tag SourceIsotopeName;
    /** SourceManufacturer, (300A,0216), LO, 1,  */
    extern const tag SourceManufacturer;
    /** SourceMovementType, (300A,0288), CS, 1,  */
    extern const tag SourceMovementType;
    /** SourceNumber, (300A,0212), IS, 1,  */
    extern const tag SourceNumber;
    /** SourceOfAnteriorChamberDepthDataCodeSequence, (0022,1133), SQ, 1,  */
    extern const tag SourceOfAnteriorChamberDepthDataCodeSequence;
    /** SourceOfLensThicknessDataCodeSequence, (0022,1132), SQ, 1,  */
    extern const tag SourceOfLensThicknessDataCodeSequence;
    /** SourceOfOphthalmicAxialLengthCodeSequence, (0022,1035), SQ, 1,  */
    extern const tag SourceOfOphthalmicAxialLengthCodeSequence;
    /** SourceOfPreviousValues, (0400,0564), LO, 1,  */
    extern const tag SourceOfPreviousValues;
    /** SourceOfRefractiveErrorDataCodeSequence, (0022,1135), SQ, 1,  */
    extern const tag SourceOfRefractiveErrorDataCodeSequence;
    /** SourceOfRefractiveMeasurementsSequence, (0022,1134), SQ, 1,  */
    extern const tag SourceOfRefractiveMeasurementsSequence;
    /** SourceOrientation, (4010,1060), FL, 3,  */
    extern const tag SourceOrientation;
    /** SourcePosition, (4010,1061), FL, 3,  */
    extern const tag SourcePosition;
    /** SourceSequence, (300A,0210), SQ, 1,  */
    extern const tag SourceSequence;
    /** SourceSerialNumber, (3008,0105), LO, 1,  */
    extern const tag SourceSerialNumber;
    /** SourceStrength, (300A,022B), DS, 1,  */
    extern const tag SourceStrength;
    /** SourceStrengthReferenceDate, (300A,022C), DA, 1,  */
    extern const tag SourceStrengthReferenceDate;
    /** SourceStrengthReferenceTime, (300A,022E), TM, 1,  */
    extern const tag SourceStrengthReferenceTime;
    /** SourceStrengthUnits, (300A,0229), CS, 1,  */
    extern const tag SourceStrengthUnits;
    /** SourceToApplicatorMountingPositionDistance, (300A,0436), FL, 1,  */
    extern const tag SourceToApplicatorMountingPositionDistance;
    /** SourceToBeamLimitingDeviceDistance, (300A,00BA), DS, 1,  */
    extern const tag SourceToBeamLimitingDeviceDistance;
    /** SourceToBlockTrayDistance, (300A,00F6), DS, 1,  */
    extern const tag SourceToBlockTrayDistance;
    /** SourceToCompensatorDistance, (300A,02E2), DS, 1-n,  */
    extern const tag SourceToCompensatorDistance;
    /** SourceToCompensatorTrayDistance, (300A,00E6), DS, 1,  */
    extern const tag SourceToCompensatorTrayDistance;
    /** SourceToReferenceObjectDistance, (3002,0028), DS, 1,  */
    extern const tag SourceToReferenceObjectDistance;
    /** SourceToSurfaceDistance, (300A,0130), DS, 1,  */
    extern const tag SourceToSurfaceDistance;
    /** SourceToWedgeTrayDistance, (300A,00DA), DS, 1,  */
    extern const tag SourceToWedgeTrayDistance;
    /** SourceType, (300A,0214), CS, 1,  */
    extern const tag SourceType;
    /** SourceWaveformSequence, (003A,020A), SQ, 1,  */
    extern const tag SourceWaveformSequence;
    /** SpacingBetweenSlices, (0018,0088), DS, 1,  */
    extern const tag SpacingBetweenSlices;
    /** SpatialLocationsPreserved, (0028,135A), CS, 1,  */
    extern const tag SpatialLocationsPreserved;
    /** SpatialPresaturation, (0018,9027), CS, 1,  */
    extern const tag SpatialPresaturation;
    /** SpatialResolution, (0018,1050), DS, 1,  */
    extern const tag SpatialResolution;
    /** SpecialNeeds, (0038,0050), LO, 1,  */
    extern const tag SpecialNeeds;
    /** SpecificAbsorptionRateDefinition, (0018,9179), CS, 1,  */
    extern const tag SpecificAbsorptionRateDefinition;
    /** SpecificAbsorptionRateSequence, (0018,9239), SQ, 1,  */
    extern const tag SpecificAbsorptionRateSequence;
    /** SpecificAbsorptionRateValue, (0018,9181), FD, 1,  */
    extern const tag SpecificAbsorptionRateValue;
    /** SpecificCharacterSet, (0008,0005), CS, 1-n,  */
    extern const tag SpecificCharacterSet;
    /** SpecificCharacterSetOfFileSetDescriptorFile, (0004,1142), CS, 1,  */
    extern const tag SpecificCharacterSetOfFileSetDescriptorFile;
    /** SpecifiedChannelTotalTime, (3008,0132), DS, 1,  */
    extern const tag SpecifiedChannelTotalTime;
    /** SpecifiedMeterset, (3008,0042), DS, 1,  */
    extern const tag SpecifiedMeterset;
    /** SpecifiedNumberOfPulses, (3008,0136), IS, 1,  */
    extern const tag SpecifiedNumberOfPulses;
    /** SpecifiedPrimaryMeterset, (3008,0032), DS, 1,  */
    extern const tag SpecifiedPrimaryMeterset;
    /** SpecifiedPulseRepetitionInterval, (3008,013A), DS, 1,  */
    extern const tag SpecifiedPulseRepetitionInterval;
    /** SpecifiedSecondaryMeterset, (3008,0033), DS, 1,  */
    extern const tag SpecifiedSecondaryMeterset;
    /** SpecifiedTreatmentTime, (3008,003A), DS, 1,  */
    extern const tag SpecifiedTreatmentTime;
    /** SpecimenAccessionNumber, (0040,050A), LO, 1, RET */
    extern const tag SpecimenAccessionNumber;
    /** SpecimenDescriptionSequence, (0040,0560), SQ, 1,  */
    extern const tag SpecimenDescriptionSequence;
    /** SpecimenDescriptionSequenceTrial, (0040,0552), SQ, 1, RET */
    extern const tag SpecimenDescriptionSequenceTrial;
    /** SpecimenDescriptionTrial, (0040,0553), ST, 1, RET */
    extern const tag SpecimenDescriptionTrial;
    /** SpecimenDetailedDescription, (0040,0602), UT, 1,  */
    extern const tag SpecimenDetailedDescription;
    /** SpecimenIdentifier, (0040,0551), LO, 1,  */
    extern const tag SpecimenIdentifier;
    /** SpecimenLabelInImage, (0048,0010), CS, 1,  */
    extern const tag SpecimenLabelInImage;
    /** SpecimenLocalizationContentItemSequence, (0040,0620), SQ, 1,  */
    extern const tag SpecimenLocalizationContentItemSequence;
    /** SpecimenPreparationSequence, (0040,0610), SQ, 1,  */
    extern const tag SpecimenPreparationSequence;
    /** SpecimenPreparationStepContentItemSequence, (0040,0612), SQ, 1,  */
    extern const tag SpecimenPreparationStepContentItemSequence;
    /** SpecimenReferenceSequence, (0048,0110), SQ, 1,  */
    extern const tag SpecimenReferenceSequence;
    /** SpecimenSequence, (0040,0550), SQ, 1, RET */
    extern const tag SpecimenSequence;
    /** SpecimenShortDescription, (0040,0600), LO, 1,  */
    extern const tag SpecimenShortDescription;
    /** SpecimenTypeCodeSequence, (0040,059A), SQ, 1,  */
    extern const tag SpecimenTypeCodeSequence;
    /** SpecimenUID, (0040,0554), UI, 1,  */
    extern const tag SpecimenUID;
    /** SpectrallySelectedExcitation, (0018,9026), CS, 1,  */
    extern const tag SpectrallySelectedExcitation;
    /** SpectrallySelectedSuppression, (0018,9025), CS, 1,  */
    extern const tag SpectrallySelectedSuppression;
    /** SpectralWidth, (0018,9052), FD, 1-2,  */
    extern const tag SpectralWidth;
    /** SpectroscopyAcquisitionDataColumns, (0018,9127), UL, 1,  */
    extern const tag SpectroscopyAcquisitionDataColumns;
    /** SpectroscopyAcquisitionOutOfPlanePhaseSteps, (0018,9159), UL, 1,  */
    extern const tag SpectroscopyAcquisitionOutOfPlanePhaseSteps;
    /** SpectroscopyAcquisitionPhaseColumns, (0018,9234), UL, 1,  */
    extern const tag SpectroscopyAcquisitionPhaseColumns;
    /** SpectroscopyAcquisitionPhaseRows, (0018,9095), UL, 1,  */
    extern const tag SpectroscopyAcquisitionPhaseRows;
    /** SpectroscopyData, (5600,0020), OF, 1,  */
    extern const tag SpectroscopyData;
    /** SpherePower, (0046,0146), FD, 1,  */
    extern const tag SpherePower;
    /** SphericalLensPower, (0022,0007), FL, 1,  */
    extern const tag SphericalLensPower;
    /** SpiralPitchFactor, (0018,9311), FD, 1,  */
    extern const tag SpiralPitchFactor;
    /** Spoiling, (0018,9016), CS, 1,  */
    extern const tag Spoiling;
    /** StackID, (0020,9056), SH, 1,  */
    extern const tag StackID;
    /** StageCodeSequence, (0040,000A), SQ, 1,  */
    extern const tag StageCodeSequence;
    /** StageName, (0008,2120), SH, 1,  */
    extern const tag StageName;
    /** StageNumber, (0008,2122), IS, 1,  */
    extern const tag StageNumber;
    /** StartAcquisitionDateTime, (0018,9516), DT, 1,  */
    extern const tag StartAcquisitionDateTime;
    /** StartAngle, (0054,0200), DS, 1,  */
    extern const tag StartAngle;
    /** StartCardiacTriggerCountThreshold, (0018,9717), FD, 1,  */
    extern const tag StartCardiacTriggerCountThreshold;
    /** StartCumulativeMetersetWeight, (300C,0008), DS, 1,  */
    extern const tag StartCumulativeMetersetWeight;
    /** StartDensityThreshold, (0018,9715), FD, 1,  */
    extern const tag StartDensityThreshold;
    /** StartingRespiratoryAmplitude, (0020,9246), FL, 1,  */
    extern const tag StartingRespiratoryAmplitude;
    /** StartingRespiratoryPhase, (0020,9247), CS, 1,  */
    extern const tag StartingRespiratoryPhase;
    /** StartMeterset, (3008,0078), DS, 1,  */
    extern const tag StartMeterset;
    /** StartRelativeDensityDifferenceThreshold, (0018,9716), FD, 1,  */
    extern const tag StartRelativeDensityDifferenceThreshold;
    /** StartRespiratoryTriggerCountThreshold, (0018,9718), FD, 1,  */
    extern const tag StartRespiratoryTriggerCountThreshold;
    /** StartTrim, (0008,2142), IS, 1,  */
    extern const tag StartTrim;
    /** StationName, (0008,1010), SH, 1,  */
    extern const tag StationName;
    /** SteadyStatePulseSequence, (0018,9017), CS, 1,  */
    extern const tag SteadyStatePulseSequence;
    /** SteepKeratometricAxisSequence, (0046,0074), SQ, 1,  */
    extern const tag SteepKeratometricAxisSequence;
    /** SteeringAngle, (0018,6036), FD, 1,  */
    extern const tag SteeringAngle;
    /** StereoBaselineAngle, (0022,0010), FL, 1,  */
    extern const tag StereoBaselineAngle;
    /** StereoBaselineDisplacement, (0022,0011), FL, 1,  */
    extern const tag StereoBaselineDisplacement;
    /** StereoHorizontalPixelOffset, (0022,0012), FL, 1,  */
    extern const tag StereoHorizontalPixelOffset;
    /** StereoPairsSequence, (0022,0020), SQ, 1,  */
    extern const tag StereoPairsSequence;
    /** StereoRotation, (0022,0014), FL, 1,  */
    extern const tag StereoRotation;
    /** StereoVerticalPixelOffset, (0022,0013), FL, 1,  */
    extern const tag StereoVerticalPixelOffset;
    /** StimuliRetestingQuantity, (0024,0042), US, 1,  */
    extern const tag StimuliRetestingQuantity;
    /** StimulusArea, (0024,0025), FL, 1,  */
    extern const tag StimulusArea;
    /** StimulusColorCodeSequence, (0024,0021), SQ, 1,  */
    extern const tag StimulusColorCodeSequence;
    /** StimulusPresentationTime, (0024,0028), FL, 1,  */
    extern const tag StimulusPresentationTime;
    /** StimulusResults, (0024,0093), CS, 1,  */
    extern const tag StimulusResults;
    /** StopTrim, (0008,2143), IS, 1,  */
    extern const tag StopTrim;
    /** StorageMediaFileSetID, (0088,0130), SH, 1,  */
    extern const tag StorageMediaFileSetID;
    /** StorageMediaFileSetUID, (0088,0140), UI, 1,  */
    extern const tag StorageMediaFileSetUID;
    /** StructuredDisplayBackgroundCIELabValue, (0072,0420), US, 3,  */
    extern const tag StructuredDisplayBackgroundCIELabValue;
    /** StructuredDisplayImageBoxSequence, (0072,0422), SQ, 1,  */
    extern const tag StructuredDisplayImageBoxSequence;
    /** StructuredDisplayTextBoxSequence, (0072,0424), SQ, 1,  */
    extern const tag StructuredDisplayTextBoxSequence;
    /** StructureSetDate, (3006,0008), DA, 1,  */
    extern const tag StructureSetDate;
    /** StructureSetDescription, (3006,0006), ST, 1,  */
    extern const tag StructureSetDescription;
    /** StructureSetLabel, (3006,0002), SH, 1,  */
    extern const tag StructureSetLabel;
    /** StructureSetName, (3006,0004), LO, 1,  */
    extern const tag StructureSetName;
    /** StructureSetROISequence, (3006,0020), SQ, 1,  */
    extern const tag StructureSetROISequence;
    /** StructureSetTime, (3006,0009), TM, 1,  */
    extern const tag StructureSetTime;
    /** StudiesContainingOtherReferencedInstancesSequence, (0008,1200), SQ, 1,  */
    extern const tag StudiesContainingOtherReferencedInstancesSequence;
    /** StudyArrivalDate, (0032,1040), DA, 1, RET */
    extern const tag StudyArrivalDate;
    /** StudyArrivalTime, (0032,1041), TM, 1, RET */
    extern const tag StudyArrivalTime;
    /** StudyComments, (0032,4000), LT, 1, RET */
    extern const tag StudyComments;
    /** StudyCompletionDate, (0032,1050), DA, 1, RET */
    extern const tag StudyCompletionDate;
    /** StudyCompletionTime, (0032,1051), TM, 1, RET */
    extern const tag StudyCompletionTime;
    /** StudyComponentStatusID, (0032,1055), CS, 1, RET */
    extern const tag StudyComponentStatusID;
    /** StudyDate, (0008,0020), DA, 1,  */
    extern const tag StudyDate;
    /** StudyDescription, (0008,1030), LO, 1,  */
    extern const tag StudyDescription;
    /** StudyID, (0020,0010), SH, 1,  */
    extern const tag StudyID;
    /** StudyIDIssuer, (0032,0012), LO, 1, RET */
    extern const tag StudyIDIssuer;
    /** StudyInstanceUID, (0020,000D), UI, 1,  */
    extern const tag StudyInstanceUID;
    /** StudyPriorityID, (0032,000C), CS, 1, RET */
    extern const tag StudyPriorityID;
    /** StudyReadDate, (0032,0034), DA, 1, RET */
    extern const tag StudyReadDate;
    /** StudyReadTime, (0032,0035), TM, 1, RET */
    extern const tag StudyReadTime;
    /** StudyStatusID, (0032,000A), CS, 1, RET */
    extern const tag StudyStatusID;
    /** StudyTime, (0008,0030), TM, 1,  */
    extern const tag StudyTime;
    /** StudyVerifiedDate, (0032,0032), DA, 1, RET */
    extern const tag StudyVerifiedDate;
    /** StudyVerifiedTime, (0032,0033), TM, 1, RET */
    extern const tag StudyVerifiedTime;
    /** SubjectiveRefractionLeftEyeSequence, (0046,0098), SQ, 1,  */
    extern const tag SubjectiveRefractionLeftEyeSequence;
    /** SubjectiveRefractionRightEyeSequence, (0046,0097), SQ, 1,  */
    extern const tag SubjectiveRefractionRightEyeSequence;
    /** SubscriptionListStatus, (0074,1244), CS, 1,  */
    extern const tag SubscriptionListStatus;
    /** SubstanceAdministrationApproval, (0044,0002), CS, 1,  */
    extern const tag SubstanceAdministrationApproval;
    /** SubstanceAdministrationDateTime, (0044,0010), DT, 1,  */
    extern const tag SubstanceAdministrationDateTime;
    /** SubstanceAdministrationDeviceID, (0044,0012), LO, 1,  */
    extern const tag SubstanceAdministrationDeviceID;
    /** SubstanceAdministrationNotes, (0044,0011), LO, 1,  */
    extern const tag SubstanceAdministrationNotes;
    /** SubstanceAdministrationParameterSequence, (0044,0019), SQ, 1,  */
    extern const tag SubstanceAdministrationParameterSequence;
    /** SubtractionItemID, (0028,9416), US, 1,  */
    extern const tag SubtractionItemID;
    /** SupportedImageDisplayFormatsSequence, (2000,00A8), SQ, 1,  */
    extern const tag SupportedImageDisplayFormatsSequence;
    /** SurfaceComments, (0066,0004), LT, 1,  */
    extern const tag SurfaceComments;
    /** SurfaceCount, (0066,002A), UL, 1,  */
    extern const tag SurfaceCount;
    /** SurfaceEntryPoint, (300A,012E), DS, 3,  */
    extern const tag SurfaceEntryPoint;
    /** SurfaceMeshPrimitivesSequence, (0066,0013), SQ, 1,  */
    extern const tag SurfaceMeshPrimitivesSequence;
    /** SurfaceModelDescriptionSequence, (0068,6360), SQ, 1,  */
    extern const tag SurfaceModelDescriptionSequence;
    /** SurfaceModelLabel, (0068,6380), LO, 1,  */
    extern const tag SurfaceModelLabel;
    /** SurfaceModelScalingFactor, (0068,6390), FD, 1,  */
    extern const tag SurfaceModelScalingFactor;
    /** SurfaceNumber, (0066,0003), UL, 1,  */
    extern const tag SurfaceNumber;
    /** SurfacePointsNormalsSequence, (0066,0012), SQ, 1,  */
    extern const tag SurfacePointsNormalsSequence;
    /** SurfacePointsSequence, (0066,0011), SQ, 1,  */
    extern const tag SurfacePointsSequence;
    /** SurfaceProcessing, (0066,0009), CS, 1,  */
    extern const tag SurfaceProcessing;
    /** SurfaceProcessingAlgorithmIdentificationSequence, (0066,0035), SQ, 1,  */
    extern const tag SurfaceProcessingAlgorithmIdentificationSequence;
    /** SurfaceProcessingDescription, (0066,000B), LO, 1,  */
    extern const tag SurfaceProcessingDescription;
    /** SurfaceProcessingRatio, (0066,000A), FL, 1,  */
    extern const tag SurfaceProcessingRatio;
    /** SurfaceSequence, (0066,0002), SQ, 1,  */
    extern const tag SurfaceSequence;
    /** SurgicalTechnique, (0076,0030), LO, 1,  */
    extern const tag SurgicalTechnique;
    /** SUVType, (0054,1006), CS, 1,  */
    extern const tag SUVType;
    /** SynchronizationChannel, (0018,106C), US, 2,  */
    extern const tag SynchronizationChannel;
    /** SynchronizationFrameOfReferenceUID, (0020,0200), UI, 1,  */
    extern const tag SynchronizationFrameOfReferenceUID;
    /** SynchronizationTrigger, (0018,106A), CS, 1,  */
    extern const tag SynchronizationTrigger;
    /** SynchronizedImageBoxList, (0072,0432), US, 2-n,  */
    extern const tag SynchronizedImageBoxList;
    /** SynchronizedScrollingSequence, (0072,0210), SQ, 1,  */
    extern const tag SynchronizedScrollingSequence;
    /** SyringeCounts, (0018,1045), IS, 1,  */
    extern const tag SyringeCounts;
    /** T2Preparation, (0018,9021), CS, 1,  */
    extern const tag T2Preparation;
    /** TableAngle, (0018,1138), DS, 1,  */
    extern const tag TableAngle;
    /** TableCradleTiltAngle, (0018,9471), FL, 1,  */
    extern const tag TableCradleTiltAngle;
    /** TableFeedPerRotation, (0018,9310), FD, 1,  */
    extern const tag TableFeedPerRotation;
    /** TableFrameOfReferenceUID, (0020,9313), UI, 1,  */
    extern const tag TableFrameOfReferenceUID;
    /** TableHeadTiltAngle, (0018,9470), FL, 1,  */
    extern const tag TableHeadTiltAngle;
    /** TableHeight, (0018,1130), DS, 1,  */
    extern const tag TableHeight;
    /** TableHorizontalRotationAngle, (0018,9469), FL, 1,  */
    extern const tag TableHorizontalRotationAngle;
    /** TableLateralIncrement, (0018,1136), DS, 1-n,  */
    extern const tag TableLateralIncrement;
    /** TableLongitudinalIncrement, (0018,1137), DS, 1-n,  */
    extern const tag TableLongitudinalIncrement;
    /** TableMotion, (0018,1134), CS, 1,  */
    extern const tag TableMotion;
    /** TableOfParameterValues, (0018,605A), FL, 1-n,  */
    extern const tag TableOfParameterValues;
    /** TableOfPixelValues, (0018,6058), UL, 1-n,  */
    extern const tag TableOfPixelValues;
    /** TableOfXBreakPoints, (0018,6052), UL, 1-n,  */
    extern const tag TableOfXBreakPoints;
    /** TableOfYBreakPoints, (0018,6054), FD, 1-n,  */
    extern const tag TableOfYBreakPoints;
    /** TablePosition, (0018,9327), FD, 1,  */
    extern const tag TablePosition;
    /** TablePositionSequence, (0018,9406), SQ, 1,  */
    extern const tag TablePositionSequence;
    /** TableSpeed, (0018,9309), FD, 1,  */
    extern const tag TableSpeed;
    /** TableTopEccentricAdjustedAngle, (0074,102B), FD, 1,  */
    extern const tag TableTopEccentricAdjustedAngle;
    /** TableTopEccentricAngle, (300A,0125), DS, 1,  */
    extern const tag TableTopEccentricAngle;
    /** TableTopEccentricAngleTolerance, (300A,004E), DS, 1,  */
    extern const tag TableTopEccentricAngleTolerance;
    /** TableTopEccentricAxisDistance, (300A,0124), DS, 1,  */
    extern const tag TableTopEccentricAxisDistance;
    /** TableTopEccentricRotationDirection, (300A,0126), CS, 1,  */
    extern const tag TableTopEccentricRotationDirection;
    /** TableTopLateralAdjustedPosition, (0074,1028), FD, 1,  */
    extern const tag TableTopLateralAdjustedPosition;
    /** TableTopLateralPosition, (300A,012A), DS, 1,  */
    extern const tag TableTopLateralPosition;
    /** TableTopLateralPositionTolerance, (300A,0053), DS, 1,  */
    extern const tag TableTopLateralPositionTolerance;
    /** TableTopLateralSetupDisplacement, (300A,01D6), DS, 1,  */
    extern const tag TableTopLateralSetupDisplacement;
    /** TableTopLongitudinalAdjustedPosition, (0074,1027), FD, 1,  */
    extern const tag TableTopLongitudinalAdjustedPosition;
    /** TableTopLongitudinalPosition, (300A,0129), DS, 1,  */
    extern const tag TableTopLongitudinalPosition;
    /** TableTopLongitudinalPositionTolerance, (300A,0052), DS, 1,  */
    extern const tag TableTopLongitudinalPositionTolerance;
    /** TableTopLongitudinalSetupDisplacement, (300A,01D4), DS, 1,  */
    extern const tag TableTopLongitudinalSetupDisplacement;
    /** TableTopPitchAdjustedAngle, (0074,102C), FD, 1,  */
    extern const tag TableTopPitchAdjustedAngle;
    /** TableTopPitchAngle, (300A,0140), FL, 1,  */
    extern const tag TableTopPitchAngle;
    /** TableTopPitchAngleTolerance, (300A,004F), FL, 1,  */
    extern const tag TableTopPitchAngleTolerance;
    /** TableTopPitchRotationDirection, (300A,0142), CS, 1,  */
    extern const tag TableTopPitchRotationDirection;
    /** TableTopRollAdjustedAngle, (0074,102D), FD, 1,  */
    extern const tag TableTopRollAdjustedAngle;
    /** TableTopRollAngle, (300A,0144), FL, 1,  */
    extern const tag TableTopRollAngle;
    /** TableTopRollAngleTolerance, (300A,0050), FL, 1,  */
    extern const tag TableTopRollAngleTolerance;
    /** TableTopRollRotationDirection, (300A,0146), CS, 1,  */
    extern const tag TableTopRollRotationDirection;
    /** TableTopVerticalAdjustedPosition, (0074,1026), FD, 1,  */
    extern const tag TableTopVerticalAdjustedPosition;
    /** TableTopVerticalPosition, (300A,0128), DS, 1,  */
    extern const tag TableTopVerticalPosition;
    /** TableTopVerticalPositionTolerance, (300A,0051), DS, 1,  */
    extern const tag TableTopVerticalPositionTolerance;
    /** TableTopVerticalSetupDisplacement, (300A,01D2), DS, 1,  */
    extern const tag TableTopVerticalSetupDisplacement;
    /** TableTraverse, (0018,1131), DS, 1,  */
    extern const tag TableTraverse;
    /** TableType, (0018,113A), CS, 1,  */
    extern const tag TableType;
    /** TableVerticalIncrement, (0018,1135), DS, 1-n,  */
    extern const tag TableVerticalIncrement;
    /** TableXPositionToIsocenter, (0018,9466), FL, 1,  */
    extern const tag TableXPositionToIsocenter;
    /** TableYPositionToIsocenter, (0018,9467), FL, 1,  */
    extern const tag TableYPositionToIsocenter;
    /** TableZPositionToIsocenter, (0018,9468), FL, 1,  */
    extern const tag TableZPositionToIsocenter;
    /** TagAngleFirstAxis, (0018,9019), FD, 1,  */
    extern const tag TagAngleFirstAxis;
    /** TagAngleSecondAxis, (0018,9219), SS, 1,  */
    extern const tag TagAngleSecondAxis;
    /** Tagging, (0018,9028), CS, 1,  */
    extern const tag Tagging;
    /** TaggingDelay, (0018,9184), FD, 1,  */
    extern const tag TaggingDelay;
    /** TagSpacingFirstDimension, (0018,9030), FD, 1,  */
    extern const tag TagSpacingFirstDimension;
    /** TagSpacingSecondDimension, (0018,9218), FD, 1,  */
    extern const tag TagSpacingSecondDimension;
    /** TagThickness, (0018,9035), FD, 1,  */
    extern const tag TagThickness;
    /** TargetExposureIndex, (0018,1412), DS, 1,  */
    extern const tag TargetExposureIndex;
    /** TargetMaximumDose, (300A,0027), DS, 1,  */
    extern const tag TargetMaximumDose;
    /** TargetMinimumDose, (300A,0025), DS, 1,  */
    extern const tag TargetMinimumDose;
    /** TargetPrescriptionDose, (300A,0026), DS, 1,  */
    extern const tag TargetPrescriptionDose;
    /** TargetRefraction, (0022,1037), FL, 1,  */
    extern const tag TargetRefraction;
    /** TargetUnderdoseVolumeFraction, (300A,0028), DS, 1,  */
    extern const tag TargetUnderdoseVolumeFraction;
    /** TDRType, (4010,1027), CS, 1,  */
    extern const tag TDRType;
    /** TelephoneNumberTrial, (0040,A354), LO, 1, RET */
    extern const tag TelephoneNumberTrial;
    /** TemplateExtensionCreatorUID, (0040,DB0D), UI, 1, RET */
    extern const tag TemplateExtensionCreatorUID;
    /** TemplateExtensionFlag, (0040,DB0B), CS, 1, RET */
    extern const tag TemplateExtensionFlag;
    /** TemplateExtensionOrganizationUID, (0040,DB0C), UI, 1, RET */
    extern const tag TemplateExtensionOrganizationUID;
    /** TemplateIdentifier, (0040,DB00), CS, 1,  */
    extern const tag TemplateIdentifier;
    /** TemplateLocalVersion, (0040,DB07), DT, 1, RET */
    extern const tag TemplateLocalVersion;
    /** TemplateName, (300A,0244), LO, 1,  */
    extern const tag TemplateName;
    /** TemplateNumber, (300A,0240), IS, 1,  */
    extern const tag TemplateNumber;
    /** TemplateType, (300A,0242), SH, 1,  */
    extern const tag TemplateType;
    /** TemplateVersion, (0040,DB06), DT, 1, RET */
    extern const tag TemplateVersion;
    /** TemporalPositionIdentifier, (0020,0100), IS, 1,  */
    extern const tag TemporalPositionIdentifier;
    /** TemporalPositionIndex, (0020,9128), UL, 1,  */
    extern const tag TemporalPositionIndex;
    /** TemporalPositionSequence, (0020,9310), SQ, 1,  */
    extern const tag TemporalPositionSequence;
    /** TemporalPositionTimeOffset, (0020,930D), FD, 1,  */
    extern const tag TemporalPositionTimeOffset;
    /** TemporalRangeType, (0040,A130), CS, 1,  */
    extern const tag TemporalRangeType;
    /** TemporalResolution, (0020,0110), DS, 1,  */
    extern const tag TemporalResolution;
    /** TerminationCardiacTriggerCountThreshold, (0018,9723), FD, 1,  */
    extern const tag TerminationCardiacTriggerCountThreshold;
    /** TerminationCountsThreshold, (0018,9719), FD, 1,  */
    extern const tag TerminationCountsThreshold;
    /** TerminationDensityThreshold, (0018,9720), FD, 1,  */
    extern const tag TerminationDensityThreshold;
    /** TerminationRelativeDensityThreshold, (0018,9721), FD, 1,  */
    extern const tag TerminationRelativeDensityThreshold;
    /** TerminationRespiratoryTriggerCountThreshold, (0018,9724), FD, 1,  */
    extern const tag TerminationRespiratoryTriggerCountThreshold;
    /** TerminationTimeThreshold, (0018,9722), FD, 1,  */
    extern const tag TerminationTimeThreshold;
    /** TestPointNormalsDataFlag, (0024,0057), CS, 1,  */
    extern const tag TestPointNormalsDataFlag;
    /** TestPointNormalsSequence, (0024,0058), SQ, 1,  */
    extern const tag TestPointNormalsSequence;
    /** TextColorCIELabValue, (0070,0241), US, 3,  */
    extern const tag TextColorCIELabValue;
    /** TextComments, (4000,4000), LT, 1, RET */
    extern const tag TextComments;
    /** TextObjectSequence, (0070,0008), SQ, 1,  */
    extern const tag TextObjectSequence;
    /** TextString, (2030,0020), LO, 1,  */
    extern const tag TextString;
    /** TextStyleSequence, (0070,0231), SQ, 1,  */
    extern const tag TextStyleSequence;
    /** TextValue, (0040,A160), UT, 1,  */
    extern const tag TextValue;
    /** TherapyDescription, (0018,0039), CS, 1, RET */
    extern const tag TherapyDescription;
    /** TherapyType, (0018,0037), CS, 1, RET */
    extern const tag TherapyType;
    /** ThreatCategory, (4010,1012), CS, 1,  */
    extern const tag ThreatCategory;
    /** ThreatCategoryDescription, (4010,1013), LT, 1,  */
    extern const tag ThreatCategoryDescription;
    /** ThreatDetectionAlgorithmandVersion, (4010,1029), LO, 1-n,  */
    extern const tag ThreatDetectionAlgorithmandVersion;
    /** ThreatROIBase, (4010,1004), FL, 3,  */
    extern const tag ThreatROIBase;
    /** ThreatROIBitmap, (4010,1006), OB, 1,  */
    extern const tag ThreatROIBitmap;
    /** ThreatROIExtents, (4010,1005), FL, 3,  */
    extern const tag ThreatROIExtents;
    /** ThreatROIVoxelSequence, (4010,1001), SQ, 1,  */
    extern const tag ThreatROIVoxelSequence;
    /** ThreatSequence, (4010,1011), SQ, 1,  */
    extern const tag ThreatSequence;
    /** ThreeDDegreeOfFreedomAxis, (0068,6490), FD, 3,  */
    extern const tag ThreeDDegreeOfFreedomAxis;
    /** ThreeDImplantTemplateGroupMemberMatchingAxes, (0078,0060), FD, 9,  */
    extern const tag ThreeDImplantTemplateGroupMemberMatchingAxes;
    /** ThreeDImplantTemplateGroupMemberMatchingPoint, (0078,0050), FD, 3,  */
    extern const tag ThreeDImplantTemplateGroupMemberMatchingPoint;
    /** ThreeDLineCoordinates, (0068,65D0), FD, 6,  */
    extern const tag ThreeDLineCoordinates;
    /** ThreeDMatingAxes, (0068,64D0), FD, 9,  */
    extern const tag ThreeDMatingAxes;
    /** ThreeDMatingPoint, (0068,64C0), FD, 3,  */
    extern const tag ThreeDMatingPoint;
    /** ThreeDPlaneNormal, (0068,6620), FD, 3,  */
    extern const tag ThreeDPlaneNormal;
    /** ThreeDPlaneOrigin, (0068,6610), FD, 3,  */
    extern const tag ThreeDPlaneOrigin;
    /** ThreeDPointCoordinates, (0068,6590), FD, 3,  */
    extern const tag ThreeDPointCoordinates;
    /** ThreeDRenderingType, (0072,0520), CS, 1-n,  */
    extern const tag ThreeDRenderingType;
    /** ThresholdDensity, (2040,0100), CS, 1, RET */
    extern const tag ThresholdDensity;
    /** TickAlignment, (0070,0274), CS, 1,  */
    extern const tag TickAlignment;
    /** TickLabel, (0070,0289), SH, 1,  */
    extern const tag TickLabel;
    /** TickLabelAlignment, (0070,0279), CS, 1,  */
    extern const tag TickLabelAlignment;
    /** TickPosition, (0070,0288), FL, 1,  */
    extern const tag TickPosition;
    /** TIDOffset, (0028,6120), SS, 1,  */
    extern const tag TIDOffset;
    /** Time, (0040,A122), TM, 1,  */
    extern const tag Time;
    /** TimeBasedImageSetsSequence, (0072,0030), SQ, 1,  */
    extern const tag TimeBasedImageSetsSequence;
    /** TimeDistributionProtocol, (0018,1802), CS, 1,  */
    extern const tag TimeDistributionProtocol;
    /** TimeDomainFiltering, (0018,9065), CS, 1-2,  */
    extern const tag TimeDomainFiltering;
    /** TimeOfDocumentCreationOrVerbalTransactionTrial, (0040,A112), TM, 1, RET */
    extern const tag TimeOfDocumentCreationOrVerbalTransactionTrial;
    /** TimeOfFlightContrast, (0018,9015), CS, 1,  */
    extern const tag TimeOfFlightContrast;
    /** TimeOfFlightInformationUsed, (0018,9755), CS, 1,  */
    extern const tag TimeOfFlightInformationUsed;
    /** TimeOfGainCalibration, (0014,3077), TM, 1,  */
    extern const tag TimeOfGainCalibration;
    /** TimeOfLastCalibration, (0018,1201), TM, 1-n,  */
    extern const tag TimeOfLastCalibration;
    /** TimeOfLastDetectorCalibration, (0018,700E), TM, 1,  */
    extern const tag TimeOfLastDetectorCalibration;
    /** TimeOfSecondaryCapture, (0018,1014), TM, 1,  */
    extern const tag TimeOfSecondaryCapture;
    /** TimeRange, (0008,1163), FD, 2,  */
    extern const tag TimeRange;
    /** TimeSliceVector, (0054,0100), US, 1-n,  */
    extern const tag TimeSliceVector;
    /** TimeSlotInformationSequence, (0054,0072), SQ, 1,  */
    extern const tag TimeSlotInformationSequence;
    /** TimeSlotNumber, (0020,0017), IS, 1, RET */
    extern const tag TimeSlotNumber;
    /** TimeSlotTime, (0054,0073), DS, 1,  */
    extern const tag TimeSlotTime;
    /** TimeSlotVector, (0054,0070), US, 1-n,  */
    extern const tag TimeSlotVector;
    /** TimeSource, (0018,1801), SH, 1,  */
    extern const tag TimeSource;
    /** TimezoneOffsetFromUTC, (0008,0201), SH, 1,  */
    extern const tag TimezoneOffsetFromUTC;
    /** TIPType, (4010,1039), CS, 1,  */
    extern const tag TIPType;
    /** TissueHeterogeneityCorrection, (3004,0014), CS, 1-3,  */
    extern const tag TissueHeterogeneityCorrection;
    /** TMLinePositionX0, (0018,603D), SL, 1,  */
    extern const tag TMLinePositionX0;
    /** TMLinePositionX0Retired, (0018,603C), UL, 1, RET */
    extern const tag TMLinePositionX0Retired;
    /** TMLinePositionX1, (0018,6041), SL, 1,  */
    extern const tag TMLinePositionX1;
    /** TMLinePositionX1Retired, (0018,6040), UL, 1, RET */
    extern const tag TMLinePositionX1Retired;
    /** TMLinePositionY0, (0018,603F), SL, 1,  */
    extern const tag TMLinePositionY0;
    /** TMLinePositionY0Retired, (0018,603E), UL, 1, RET */
    extern const tag TMLinePositionY0Retired;
    /** TMLinePositionY1, (0018,6043), SL, 1,  */
    extern const tag TMLinePositionY1;
    /** TMLinePositionY1Retired, (0018,6042), UL, 1, RET */
    extern const tag TMLinePositionY1Retired;
    /** ToleranceTableLabel, (300A,0043), SH, 1,  */
    extern const tag ToleranceTableLabel;
    /** ToleranceTableNumber, (300A,0042), IS, 1,  */
    extern const tag ToleranceTableNumber;
    /** ToleranceTableSequence, (300A,0040), SQ, 1,  */
    extern const tag ToleranceTableSequence;
    /** TomoAngle, (0018,1470), DS, 1,  */
    extern const tag TomoAngle;
    /** TomoClass, (0018,1491), CS, 1,  */
    extern const tag TomoClass;
    /** TomoLayerHeight, (0018,1460), DS, 1,  */
    extern const tag TomoLayerHeight;
    /** TomoTime, (0018,1480), DS, 1,  */
    extern const tag TomoTime;
    /** TomoType, (0018,1490), CS, 1,  */
    extern const tag TomoType;
    /** TopicAuthor, (0088,0910), LO, 1, RET */
    extern const tag TopicAuthor;
    /** TopicKeywords, (0088,0912), LO, 1-32, RET */
    extern const tag TopicKeywords;
    /** TopicSubject, (0088,0906), ST, 1, RET */
    extern const tag TopicSubject;
    /** TopicTitle, (0088,0904), LO, 1, RET */
    extern const tag TopicTitle;
    /** TopLeftHandCornerOfLocalizerArea, (0048,0201), US, 2,  */
    extern const tag TopLeftHandCornerOfLocalizerArea;
    /** TotalBlockTrayFactor, (300A,00F2), DS, 1,  */
    extern const tag TotalBlockTrayFactor;
    /** TotalBlockTrayWaterEquivalentThickness, (300A,00F3), FL, 1,  */
    extern const tag TotalBlockTrayWaterEquivalentThickness;
    /** TotalCollimationWidth, (0018,9307), FD, 1,  */
    extern const tag TotalCollimationWidth;
    /** TotalCompensatorTrayFactor, (300A,00E2), DS, 1,  */
    extern const tag TotalCompensatorTrayFactor;
    /** TotalCompensatorTrayWaterEquivalentThickness, (300A,02E3), FL, 1,  */
    extern const tag TotalCompensatorTrayWaterEquivalentThickness;
    /** TotalGain, (0018,5040), DS, 1, RET */
    extern const tag TotalGain;
    /** TotalNumberOfExposures, (0040,0301), US, 1,  */
    extern const tag TotalNumberOfExposures;
    /** TotalNumberOfPiecesOfMediaCreated, (2200,000B), US, 1,  */
    extern const tag TotalNumberOfPiecesOfMediaCreated;
    /** TotalPixelMatrixColumns, (0048,0006), UL, 1,  */
    extern const tag TotalPixelMatrixColumns;
    /** TotalPixelMatrixOriginSequence, (0048,0008), SQ, 1,  */
    extern const tag TotalPixelMatrixOriginSequence;
    /** TotalPixelMatrixRows, (0048,0007), UL, 1,  */
    extern const tag TotalPixelMatrixRows;
    /** TotalProcessingTime, (4010,1069), FL, 1,  */
    extern const tag TotalProcessingTime;
    /** TotalReferenceAirKerma, (300A,0250), DS, 1,  */
    extern const tag TotalReferenceAirKerma;
    /** TotalTime, (50XX,200A), UL, 1, RET */
    extern const range_tag TotalTime;
    /** TotalTimeOfFluoroscopy, (0040,0300), US, 1,  */
    extern const tag TotalTimeOfFluoroscopy;
    /** TotalWedgeTrayWaterEquivalentThickness, (300A,00D7), FL, 1,  */
    extern const tag TotalWedgeTrayWaterEquivalentThickness;
    /** TransactionUID, (0008,1195), UI, 1,  */
    extern const tag TransactionUID;
    /** TransducerApplicationCodeSequence, (0018,980F), SQ, 1,  */
    extern const tag TransducerApplicationCodeSequence;
    /** TransducerBeamSteeringCodeSequence, (0018,980E), SQ, 1,  */
    extern const tag TransducerBeamSteeringCodeSequence;
    /** TransducerData, (0018,5010), LO, 1-n,  */
    extern const tag TransducerData;
    /** TransducerFrequency, (0018,6030), UL, 1,  */
    extern const tag TransducerFrequency;
    /** TransducerGeometryCodeSequence, (0018,980D), SQ, 1,  */
    extern const tag TransducerGeometryCodeSequence;
    /** TransducerOrientation, (0008,2204), CS, 1, RET */
    extern const tag TransducerOrientation;
    /** TransducerOrientationModifierSequence, (0008,2246), SQ, 1, RET */
    extern const tag TransducerOrientationModifierSequence;
    /** TransducerOrientationSequence, (0008,2244), SQ, 1, RET */
    extern const tag TransducerOrientationSequence;
    /** TransducerPosition, (0008,2200), CS, 1, RET */
    extern const tag TransducerPosition;
    /** TransducerPositionModifierSequence, (0008,2242), SQ, 1, RET */
    extern const tag TransducerPositionModifierSequence;
    /** TransducerPositionSequence, (0008,2240), SQ, 1, RET */
    extern const tag TransducerPositionSequence;
    /** TransducerScanPatternCodeSequence, (0018,9809), SQ, 1,  */
    extern const tag TransducerScanPatternCodeSequence;
    /** TransducerType, (0018,6031), CS, 1,  */
    extern const tag TransducerType;
    /** TransferSyntaxUID, (0002,0010), UI, 1,  */
    extern const tag TransferSyntaxUID;
    /** TransferTubeLength, (300A,02A4), DS, 1,  */
    extern const tag TransferTubeLength;
    /** TransferTubeNumber, (300A,02A2), IS, 1,  */
    extern const tag TransferTubeNumber;
    /** TransformDescription, (0014,2222), ST, 1,  */
    extern const tag TransformDescription;
    /** TransformedAxisUnits, (0014,2228), CS, 1,  */
    extern const tag TransformedAxisUnits;
    /** TransformLabel, (0028,0400), LO, 1, RET */
    extern const tag TransformLabel;
    /** TransformNumberOfAxes, (0014,2224), IS, 1,  */
    extern const tag TransformNumberOfAxes;
    /** TransformOrderOfAxes, (0014,2226), IS, 1-n,  */
    extern const tag TransformOrderOfAxes;
    /** TransformVersionNumber, (0028,0401), LO, 1, RET */
    extern const tag TransformVersionNumber;
    /** TransmitCoilManufacturerName, (0018,9050), LO, 1,  */
    extern const tag TransmitCoilManufacturerName;
    /** TransmitCoilName, (0018,1251), SH, 1,  */
    extern const tag TransmitCoilName;
    /** TransmitCoilType, (0018,9051), CS, 1,  */
    extern const tag TransmitCoilType;
    /** TransmitterFrequency, (0018,9098), FD, 1-2,  */
    extern const tag TransmitterFrequency;
    /** TransmitTransducerSequence, (0014,4010), SQ, 1,  */
    extern const tag TransmitTransducerSequence;
    /** TransmitTransducerSettingsSequence, (0014,4050), SQ, 1,  */
    extern const tag TransmitTransducerSettingsSequence;
    /** TransportClassification, (4010,1067), CS, 1,  */
    extern const tag TransportClassification;
    /** TransverseDetectorSeparation, (0018,9726), FD, 1,  */
    extern const tag TransverseDetectorSeparation;
    /** TransverseMash, (0054,1202), IS, 1,  */
    extern const tag TransverseMash;
    /** TreatmentControlPointDate, (3008,0024), DA, 1,  */
    extern const tag TreatmentControlPointDate;
    /** TreatmentControlPointTime, (3008,0025), TM, 1,  */
    extern const tag TreatmentControlPointTime;
    /** TreatmentDate, (3008,0250), DA, 1,  */
    extern const tag TreatmentDate;
    /** TreatmentDeliveryType, (300A,00CE), CS, 1,  */
    extern const tag TreatmentDeliveryType;
    /** TreatmentMachineName, (300A,00B2), SH, 1,  */
    extern const tag TreatmentMachineName;
    /** TreatmentMachineSequence, (300A,0206), SQ, 1,  */
    extern const tag TreatmentMachineSequence;
    /** TreatmentProtocols, (300A,0009), LO, 1-n,  */
    extern const tag TreatmentProtocols;
    /** TreatmentSessionApplicationSetupSequence, (3008,0110), SQ, 1,  */
    extern const tag TreatmentSessionApplicationSetupSequence;
    /** TreatmentSessionBeamSequence, (3008,0020), SQ, 1,  */
    extern const tag TreatmentSessionBeamSequence;
    /** TreatmentSessionIonBeamSequence, (3008,0021), SQ, 1,  */
    extern const tag TreatmentSessionIonBeamSequence;
    /** TreatmentSites, (300A,000B), LO, 1-n,  */
    extern const tag TreatmentSites;
    /** TreatmentStatusComment, (3008,0202), ST, 1,  */
    extern const tag TreatmentStatusComment;
    /** TreatmentSummaryCalculatedDoseReferenceSequence, (3008,0050), SQ, 1,  */
    extern const tag TreatmentSummaryCalculatedDoseReferenceSequence;
    /** TreatmentSummaryMeasuredDoseReferenceSequence, (3008,00E0), SQ, 1,  */
    extern const tag TreatmentSummaryMeasuredDoseReferenceSequence;
    /** TreatmentTerminationCode, (3008,002B), SH, 1,  */
    extern const tag TreatmentTerminationCode;
    /** TreatmentTerminationStatus, (3008,002A), CS, 1,  */
    extern const tag TreatmentTerminationStatus;
    /** TreatmentTime, (3008,0251), TM, 1,  */
    extern const tag TreatmentTime;
    /** TreatmentVerificationStatus, (3008,002C), CS, 1,  */
    extern const tag TreatmentVerificationStatus;
    /** TriangleFanSequence, (0066,0027), SQ, 1,  */
    extern const tag TriangleFanSequence;
    /** TrianglePointIndexList, (0066,0023), OW, 1,  */
    extern const tag TrianglePointIndexList;
    /** TriangleStripSequence, (0066,0026), SQ, 1,  */
    extern const tag TriangleStripSequence;
    /** TriggerSamplePosition, (0018,106E), UL, 1,  */
    extern const tag TriggerSamplePosition;
    /** TriggerSourceOrType, (0018,1061), LO, 1,  */
    extern const tag TriggerSourceOrType;
    /** TriggerTime, (0018,1060), DS, 1,  */
    extern const tag TriggerTime;
    /** TriggerTimeOffset, (0018,1069), DS, 1,  */
    extern const tag TriggerTimeOffset;
    /** TriggerVector, (0054,0210), IS, 1-n,  */
    extern const tag TriggerVector;
    /** TriggerWindow, (0018,1094), IS, 1,  */
    extern const tag TriggerWindow;
    /** Trim, (2010,0140), CS, 1,  */
    extern const tag Trim;
    /** TubeAngle, (0018,9303), FD, 1,  */
    extern const tag TubeAngle;
    /** TwoDDegreeOfFreedomAxis, (0068,64F0), FD, 3,  */
    extern const tag TwoDDegreeOfFreedomAxis;
    /** TwoDDegreeOfFreedomSequence, (0068,6470), SQ, 1,  */
    extern const tag TwoDDegreeOfFreedomSequence;
    /** TwoDImplantTemplateGroupMemberMatchingAxes, (0078,00A0), FD, 4,  */
    extern const tag TwoDImplantTemplateGroupMemberMatchingAxes;
    /** TwoDImplantTemplateGroupMemberMatchingPoint, (0078,0090), FD, 2,  */
    extern const tag TwoDImplantTemplateGroupMemberMatchingPoint;
    /** TwoDLineCoordinates, (0068,65B0), FD, 4,  */
    extern const tag TwoDLineCoordinates;
    /** TwoDLineCoordinatesSequence, (0068,65A0), SQ, 1,  */
    extern const tag TwoDLineCoordinatesSequence;
    /** TwoDMatingAxes, (0068,6460), FD, 4,  */
    extern const tag TwoDMatingAxes;
    /** TwoDMatingFeatureCoordinatesSequence, (0068,6430), SQ, 1,  */
    extern const tag TwoDMatingFeatureCoordinatesSequence;
    /** TwoDMatingPoint, (0068,6450), FD, 2,  */
    extern const tag TwoDMatingPoint;
    /** TwoDPlaneCoordinatesSequence, (0068,65E0), SQ, 1,  */
    extern const tag TwoDPlaneCoordinatesSequence;
    /** TwoDPlaneIntersection, (0068,65F0), FD, 4,  */
    extern const tag TwoDPlaneIntersection;
    /** TwoDPointCoordinates, (0068,6560), FD, 2,  */
    extern const tag TwoDPointCoordinates;
    /** TwoDPointCoordinatesSequence, (0068,6550), SQ, 1,  */
    extern const tag TwoDPointCoordinatesSequence;
    /** TypeOfData, (50XX,0020), CS, 1, RET */
    extern const range_tag TypeOfData;
    /** TypeOfDetectorMotion, (0054,0202), CS, 1,  */
    extern const tag TypeOfDetectorMotion;
    /** TypeOfFilters, (0018,1161), LO, 1-n,  */
    extern const tag TypeOfFilters;
    /** TypeOfInstances, (0040,E020), CS, 1,  */
    extern const tag TypeOfInstances;
    /** TypeOfPatientID, (0010,0022), CS, 1,  */
    extern const tag TypeOfPatientID;
    /** TypeOfSynchronization, (0072,0434), CS, 1,  */
    extern const tag TypeOfSynchronization;
    /** UID, (0040,A124), UI, 1,  */
    extern const tag UID;
    /** UltrasoundAcquisitionGeometry, (0020,9307), CS, 1,  */
    extern const tag UltrasoundAcquisitionGeometry;
    /** UltrasoundColorDataPresent, (0028,0014), US, 1,  */
    extern const tag UltrasoundColorDataPresent;
    /** UltrasoundOphthalmicAxialLengthMeasurementsSequence, (0022,1220), SQ, 1,  */
    extern const tag UltrasoundOphthalmicAxialLengthMeasurementsSequence;
    /** UltrasoundSelectedOphthalmicAxialLengthSequence, (0022,1230), SQ, 1,  */
    extern const tag UltrasoundSelectedOphthalmicAxialLengthSequence;
    /** Underlined, (0070,0248), CS, 1,  */
    extern const tag Underlined;
    /** UnformattedTextValue, (0070,0006), ST, 1,  */
    extern const tag UnformattedTextValue;
    /** UnifiedProcedureStepListStatus, (0074,1246), CS, 1,  */
    extern const tag UnifiedProcedureStepListStatus;
    /** UnifiedProcedureStepPerformedProcedureSequence, (0074,1216), SQ, 1,  */
    extern const tag UnifiedProcedureStepPerformedProcedureSequence;
    /** UniformResourceLocatorTrial, (0040,A992), ST, 1, RET */
    extern const tag UniformResourceLocatorTrial;
    /** Units, (0054,1001), CS, 1,  */
    extern const tag Units;
    /** UniversalEntityID, (0040,0032), UT, 1,  */
    extern const tag UniversalEntityID;
    /** UniversalEntityIDType, (0040,0033), CS, 1,  */
    extern const tag UniversalEntityIDType;
    /** UnspecifiedLateralityLensSequence, (0046,0016), SQ, 1,  */
    extern const tag UnspecifiedLateralityLensSequence;
    /** UpperLowerPixelValues, (0018,1240), IS, 1-n, RET */
    extern const tag UpperLowerPixelValues;
    /** UrgencyOrPriorityAlertsTrial, (0040,A057), CS, 1-n, RET */
    extern const tag UrgencyOrPriorityAlertsTrial;
    /** UsedFiducialsSequence, (0070,0314), SQ, 1,  */
    extern const tag UsedFiducialsSequence;
    /** USImageDescriptionSequence, (0018,9806), SQ, 1,  */
    extern const tag USImageDescriptionSequence;
    /** ValueType, (0040,A040), CS, 1,  */
    extern const tag ValueType;
    /** VariableCoefficientsSDDN, (7FXX,0040), OW, 1, RET */
    extern const range_tag VariableCoefficientsSDDN;
    /** VariableCoefficientsSDHN, (7FXX,0030), OW, 1, RET */
    extern const range_tag VariableCoefficientsSDHN;
    /** VariableCoefficientsSDVN, (7FXX,0020), OW, 1, RET */
    extern const range_tag VariableCoefficientsSDVN;
    /** VariableFlipAngleFlag, (0018,1315), CS, 1,  */
    extern const tag VariableFlipAngleFlag;
    /** VariableNextDataGroup, (7FXX,0011), US, 1, RET */
    extern const range_tag VariableNextDataGroup;
    /** VariablePixelData, (7FXX,0010), OW or OB, 1, RET */
    extern const range_tag VariablePixelData;
    /** VectorAccuracy, (0066,0020), FL, 1-n,  */
    extern const tag VectorAccuracy;
    /** VectorCoordinateData, (0066,0021), OF, 1,  */
    extern const tag VectorCoordinateData;
    /** VectorDimensionality, (0066,001F), US, 1,  */
    extern const tag VectorDimensionality;
    /** VectorGridData, (0064,0009), OF, 1,  */
    extern const tag VectorGridData;
    /** VelocityEncodingAcquisitionSequence, (0018,9092), SQ, 1,  */
    extern const tag VelocityEncodingAcquisitionSequence;
    /** VelocityEncodingDirection, (0018,9090), FD, 3,  */
    extern const tag VelocityEncodingDirection;
    /** VelocityEncodingMaximumValue, (0018,9217), FD, 1,  */
    extern const tag VelocityEncodingMaximumValue;
    /** VelocityEncodingMinimumValue, (0018,9091), FD, 1,  */
    extern const tag VelocityEncodingMinimumValue;
    /** VelocityOfSound, (0014,4064), DS, 1,  */
    extern const tag VelocityOfSound;
    /** VerbalSourceIdentifierCodeSequenceTrial, (0040,A358), SQ, 1, RET */
    extern const tag VerbalSourceIdentifierCodeSequenceTrial;
    /** VerbalSourceTrial, (0040,A352), PN, 1, RET */
    extern const tag VerbalSourceTrial;
    /** VerificationDateTime, (0040,A030), DT, 1,  */
    extern const tag VerificationDateTime;
    /** VerificationFlag, (0040,A493), CS, 1,  */
    extern const tag VerificationFlag;
    /** VerificationImageTiming, (0074,1032), CS, 1,  */
    extern const tag VerificationImageTiming;
    /** VerifyingObserverIdentificationCodeSequence, (0040,A088), SQ, 1,  */
    extern const tag VerifyingObserverIdentificationCodeSequence;
    /** VerifyingObserverName, (0040,A075), PN, 1,  */
    extern const tag VerifyingObserverName;
    /** VerifyingObserverSequence, (0040,A073), SQ, 1,  */
    extern const tag VerifyingObserverSequence;
    /** VerifyingOrganization, (0040,A027), LO, 1,  */
    extern const tag VerifyingOrganization;
    /** VertexPointIndexList, (0066,0025), OW, 1,  */
    extern const tag VertexPointIndexList;
    /** VerticalAlignment, (0070,0243), CS, 1,  */
    extern const tag VerticalAlignment;
    /** VerticalOffsetOfSensor, (0014,3026), DS, 1,  */
    extern const tag VerticalOffsetOfSensor;
    /** VerticalPrismBase, (0046,0036), CS, 1,  */
    extern const tag VerticalPrismBase;
    /** VerticalPrismPower, (0046,0034), FD, 1,  */
    extern const tag VerticalPrismPower;
    /** VerticesOfThePolygonalCollimator, (0018,1720), IS, 2-2n,  */
    extern const tag VerticesOfThePolygonalCollimator;
    /** VerticesOfThePolygonalExposureControlSensingRegion, (0018,9442), SS, 2-n,  */
    extern const tag VerticesOfThePolygonalExposureControlSensingRegion;
    /** VerticesOfThePolygonalShutter, (0018,1620), IS, 2-2n,  */
    extern const tag VerticesOfThePolygonalShutter;
    /** VerticesOfTheRegion, (0028,9503), SS, 2-2n,  */
    extern const tag VerticesOfTheRegion;
    /** VideoImageFormatAcquired, (0018,1022), SH, 1,  */
    extern const tag VideoImageFormatAcquired;
    /** ViewCodeSequence, (0054,0220), SQ, 1,  */
    extern const tag ViewCodeSequence;
    /** ViewingDistance, (0046,0106), FD, 1,  */
    extern const tag ViewingDistance;
    /** ViewingDistanceType, (0046,0125), CS, 1,  */
    extern const tag ViewingDistanceType;
    /** ViewModifierCodeSequence, (0054,0222), SQ, 1,  */
    extern const tag ViewModifierCodeSequence;
    /** ViewName, (0008,2127), SH, 1,  */
    extern const tag ViewName;
    /** ViewNumber, (0008,2128), IS, 1,  */
    extern const tag ViewNumber;
    /** ViewOrientationCodeSequence, (0068,62E0), SQ, 1,  */
    extern const tag ViewOrientationCodeSequence;
    /** ViewOrientationModifier, (0068,62F0), FD, 9,  */
    extern const tag ViewOrientationModifier;
    /** ViewPosition, (0018,5101), CS, 1,  */
    extern const tag ViewPosition;
    /** VirtualSourceAxisDistances, (300A,030A), FL, 2,  */
    extern const tag VirtualSourceAxisDistances;
    /** VisitComments, (0038,4000), LT, 1,  */
    extern const tag VisitComments;
    /** VisitStatusID, (0038,0008), CS, 1,  */
    extern const tag VisitStatusID;
    /** VisualAcuityBothEyesOpenSequence, (0046,0124), SQ, 1,  */
    extern const tag VisualAcuityBothEyesOpenSequence;
    /** VisualAcuityLeftEyeSequence, (0046,0123), SQ, 1,  */
    extern const tag VisualAcuityLeftEyeSequence;
    /** VisualAcuityMeasurementSequence, (0024,0110), SQ, 1,  */
    extern const tag VisualAcuityMeasurementSequence;
    /** VisualAcuityModifiers, (0046,0135), SS, 2,  */
    extern const tag VisualAcuityModifiers;
    /** VisualAcuityRightEyeSequence, (0046,0122), SQ, 1,  */
    extern const tag VisualAcuityRightEyeSequence;
    /** VisualAcuityTypeCodeSequence, (0046,0121), SQ, 1,  */
    extern const tag VisualAcuityTypeCodeSequence;
    /** VisualFieldCatchTrialSequence, (0024,0034), SQ, 1,  */
    extern const tag VisualFieldCatchTrialSequence;
    /** VisualFieldGlobalResultsIndexSequence, (0024,0320), SQ, 1,  */
    extern const tag VisualFieldGlobalResultsIndexSequence;
    /** VisualFieldHorizontalExtent, (0024,0010), FL, 1,  */
    extern const tag VisualFieldHorizontalExtent;
    /** VisualFieldMeanSensitivity, (0024,0070), FL, 1,  */
    extern const tag VisualFieldMeanSensitivity;
    /** VisualFieldShape, (0024,0012), CS, 1,  */
    extern const tag VisualFieldShape;
    /** VisualFieldTestDuration, (0024,0088), FL, 1,  */
    extern const tag VisualFieldTestDuration;
    /** VisualFieldTestNormalsFlag, (0024,0063), CS, 1,  */
    extern const tag VisualFieldTestNormalsFlag;
    /** VisualFieldTestPointNormalsSequence, (0024,0097), SQ, 1,  */
    extern const tag VisualFieldTestPointNormalsSequence;
    /** VisualFieldTestPointSequence, (0024,0089), SQ, 1,  */
    extern const tag VisualFieldTestPointSequence;
    /** VisualFieldTestPointXCoordinate, (0024,0090), FL, 1,  */
    extern const tag VisualFieldTestPointXCoordinate;
    /** VisualFieldTestPointYCoordinate, (0024,0091), FL, 1,  */
    extern const tag VisualFieldTestPointYCoordinate;
    /** VisualFieldTestReliabilityGlobalIndexSequence, (0024,0317), SQ, 1,  */
    extern const tag VisualFieldTestReliabilityGlobalIndexSequence;
    /** VisualFieldVerticalExtent, (0024,0011), FL, 1,  */
    extern const tag VisualFieldVerticalExtent;
    /** VitalStainCodeSequenceTrial, (0040,09F8), SQ, 1, RET */
    extern const tag VitalStainCodeSequenceTrial;
    /** VitreousStatusCodeSequence, (0022,1025), SQ, 1,  */
    extern const tag VitreousStatusCodeSequence;
    /** VitreousStatusDescription, (0022,1066), LO, 1,  */
    extern const tag VitreousStatusDescription;
    /** VOILUTFunction, (0028,1056), CS, 1,  */
    extern const tag VOILUTFunction;
    /** VOILUTSequence, (0028,3010), SQ, 1,  */
    extern const tag VOILUTSequence;
    /** VOIType, (0072,0702), CS, 1,  */
    extern const tag VOIType;
    /** VolumeBasedCalculationTechnique, (0008,9207), CS, 1,  */
    extern const tag VolumeBasedCalculationTechnique;
    /** VolumeFrameOfReferenceUID, (0020,9312), UI, 1,  */
    extern const tag VolumeFrameOfReferenceUID;
    /** VolumeLocalizationSequence, (0018,9126), SQ, 1,  */
    extern const tag VolumeLocalizationSequence;
    /** VolumeLocalizationTechnique, (0018,9054), CS, 1,  */
    extern const tag VolumeLocalizationTechnique;
    /** VolumeOfPTO, (4010,1023), FL, 1,  */
    extern const tag VolumeOfPTO;
    /** VolumeToTableMappingMatrix, (0020,930A), FD, 16,  */
    extern const tag VolumeToTableMappingMatrix;
    /** VolumeToTransducerMappingMatrix, (0020,9309), FD, 16,  */
    extern const tag VolumeToTransducerMappingMatrix;
    /** VolumetricProperties, (0008,9206), CS, 1,  */
    extern const tag VolumetricProperties;
    /** WADORetrievalSequence, (0040,E023), SQ, 1,  */
    extern const tag WADORetrievalSequence;
    /** WaterReferencedPhaseCorrection, (0018,9199), CS, 1,  */
    extern const tag WaterReferencedPhaseCorrection;
    /** WaveformAnnotationSequence, (0040,B020), SQ, 1,  */
    extern const tag WaveformAnnotationSequence;
    /** WaveformBitsAllocated, (5400,1004), US, 1,  */
    extern const tag WaveformBitsAllocated;
    /** WaveformBitsStored, (003A,021A), US, 1,  */
    extern const tag WaveformBitsStored;
    /** WaveformChannelNumber, (003A,0202), IS, 1,  */
    extern const tag WaveformChannelNumber;
    /** WaveformData, (5400,1010), OB or OW, 1,  */
    extern const tag WaveformData;
    /** WaveformDataDisplayScale, (003A,0230), FL, 1,  */
    extern const tag WaveformDataDisplayScale;
    /** WaveformDisplayBackgroundCIELabValue, (003A,0231), US, 3,  */
    extern const tag WaveformDisplayBackgroundCIELabValue;
    /** WaveformOriginality, (003A,0004), CS, 1,  */
    extern const tag WaveformOriginality;
    /** WaveformPaddingValue, (5400,100A), OB or OW, 1,  */
    extern const tag WaveformPaddingValue;
    /** WaveformPresentationGroupSequence, (003A,0240), SQ, 1,  */
    extern const tag WaveformPresentationGroupSequence;
    /** WaveformSampleInterpretation, (5400,1006), CS, 1,  */
    extern const tag WaveformSampleInterpretation;
    /** WaveformSequence, (5400,0100), SQ, 1,  */
    extern const tag WaveformSequence;
    /** WedgeAngle, (300A,00D5), IS, 1,  */
    extern const tag WedgeAngle;
    /** WedgeFactor, (300A,00D6), DS, 1,  */
    extern const tag WedgeFactor;
    /** WedgeID, (300A,00D4), SH, 1,  */
    extern const tag WedgeID;
    /** WedgeNumber, (300A,00D2), IS, 1,  */
    extern const tag WedgeNumber;
    /** WedgeOrientation, (300A,00D8), DS, 1,  */
    extern const tag WedgeOrientation;
    /** WedgePosition, (300A,0118), CS, 1,  */
    extern const tag WedgePosition;
    /** WedgePositionSequence, (300A,0116), SQ, 1,  */
    extern const tag WedgePositionSequence;
    /** WedgeSequence, (300A,00D1), SQ, 1,  */
    extern const tag WedgeSequence;
    /** WedgeThinEdgePosition, (300A,00DB), FL, 1,  */
    extern const tag WedgeThinEdgePosition;
    /** WedgeType, (300A,00D3), CS, 1,  */
    extern const tag WedgeType;
    /** WholeBodyTechnique, (0018,1301), CS, 1-n,  */
    extern const tag WholeBodyTechnique;
    /** WindowCenter, (0028,1050), DS, 1-n,  */
    extern const tag WindowCenter;
    /** WindowCenterWidthExplanation, (0028,1055), LO, 1-n,  */
    extern const tag WindowCenterWidthExplanation;
    /** WindowWidth, (0028,1051), DS, 1-n,  */
    extern const tag WindowWidth;
    /** WorklistLabel, (0074,1202), LO, 1,  */
    extern const tag WorklistLabel;
    /** XAXRFFrameCharacteristicsSequence, (0018,9412), SQ, 1,  */
    extern const tag XAXRFFrameCharacteristicsSequence;
    /** XDSRetrievalSequence, (0040,E024), SQ, 1,  */
    extern const tag XDSRetrievalSequence;
    /** XFocusCenter, (0018,1183), DS, 1-2,  */
    extern const tag XFocusCenter;
    /** XOffsetInSlideCoordinateSystem, (0040,072A), DS, 1,  */
    extern const tag XOffsetInSlideCoordinateSystem;
    /** XRay3DAcquisitionSequence, (0018,9507), SQ, 1,  */
    extern const tag XRay3DAcquisitionSequence;
    /** XRay3DFrameTypeSequence, (0018,9504), SQ, 1,  */
    extern const tag XRay3DFrameTypeSequence;
    /** XRay3DReconstructionSequence, (0018,9530), SQ, 1,  */
    extern const tag XRay3DReconstructionSequence;
    /** XRayGeometrySequence, (0018,9476), SQ, 1,  */
    extern const tag XRayGeometrySequence;
    /** XRayImageReceptorAngle, (3002,000E), DS, 1,  */
    extern const tag XRayImageReceptorAngle;
    /** XRayImageReceptorTranslation, (3002,000D), DS, 3,  */
    extern const tag XRayImageReceptorTranslation;
    /** XRayOutput, (0040,0312), DS, 1,  */
    extern const tag XRayOutput;
    /** XRayReceptorType, (0018,9420), CS, 1,  */
    extern const tag XRayReceptorType;
    /** XRayTubeCurrent, (0018,1151), IS, 1,  */
    extern const tag XRayTubeCurrent;
    /** XRayTubeCurrentInmA, (0018,9330), FD, 1,  */
    extern const tag XRayTubeCurrentInmA;
    /** XRayTubeCurrentInuA, (0018,8151), DS, 1,  */
    extern const tag XRayTubeCurrentInuA;
    /** YFocusCenter, (0018,1184), DS, 1-2,  */
    extern const tag YFocusCenter;
    /** YOffsetInSlideCoordinateSystem, (0040,073A), DS, 1,  */
    extern const tag YOffsetInSlideCoordinateSystem;
    /** ZEffective, (4010,1019), FL, 1,  */
    extern const tag ZEffective;
    /** ZOffsetInSlideCoordinateSystem, (0040,074A), DS, 1,  */
    extern const tag ZOffsetInSlideCoordinateSystem;
    /** ZonalMap, (1010,XXXX), US, 1-n, RET */
    extern const range_tag ZonalMap;
    /** ZonalMapFormat, (0028,0722), US, 1, RET */
    extern const tag ZonalMapFormat;
    /** ZonalMapLocation, (0028,0721), AT, 1-n, RET */
    extern const tag ZonalMapLocation;
    /** ZonalMapNumberFormat, (0028,0720), US, 1, RET */
    extern const tag ZonalMapNumberFormat;
    /** ZoomCenter, (0028,0032), DS, 2,  */
    extern const tag ZoomCenter;
    /** ZoomFactor, (0028,0031), DS, 2,  */
    extern const tag ZoomFactor;
} // namespace tags
}
