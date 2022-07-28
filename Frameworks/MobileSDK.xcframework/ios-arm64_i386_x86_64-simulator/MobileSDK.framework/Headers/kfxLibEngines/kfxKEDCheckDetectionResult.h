//
//  kfxKEDCheckDetectionResult.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved.
//

#import "kfxKEDDocumentBaseDetectionResult.h"
#import "kfxKEDCheckDetectionResultCompatibility.h"

//! An enumeration containing the possible check detection side values.
/**
 Check detection results will indicate which side of a check was found using one of these values.
 */
typedef enum kedCheckSide {
    KED_CHECK_SIDE_FRONT,
    KED_CHECK_SIDE_BACK,
    KED_CHECK_SIDE_NONE,
} KEDCheckSide;

//! An enumeration containing the possible check type values.
/**
 Check detection results will indicate which check type was detected.
 
 Preserved for future use.
 */
typedef enum kedCheckType {
    KED_CHECK_TYPE_PERSONAL,
    KED_CHECK_TYPE_BUSINESS,
} KEDCheckType;

@class kfxKEDCheckDetectionSettings;

//! A result object returned by the Check Detector.
@interface kfxKEDCheckDetectionResult : kfxKEDDocumentBaseDetectionResult

/// Reports side of the check that was detected.
/**
 An enum value indicating which side of the check was detected.
 */
@property (nonatomic, readonly) KEDCheckSide checkSide;

@end
