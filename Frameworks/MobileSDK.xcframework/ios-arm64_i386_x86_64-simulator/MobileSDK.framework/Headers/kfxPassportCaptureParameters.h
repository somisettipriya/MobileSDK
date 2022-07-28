//
//  API Reference
//  kfxPassportCaptureParameters.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxIParameters.h>

//! The passport capture view controller parameters.
/**
 Encapsulates all parameters related to passport capture@if EXTRACTION, processing and extraction. @else &nbsp;and processing. @endif\n
 
 Default values for following parameters are differ with base classes:
 - Torch is OFF.
 - useMRZPageDetection is ON.
 
 @see kfxIParameters
 */
@interface kfxPassportCaptureParameters : kfxIParameters <NSCopying>
///@cond EXTRACTION

//! Passport project name
/**
 Allows to get Passport project name for asset downloading.
 
 @return project name.
 */
+ (NSString*)projectName;
///@endcond
@end
