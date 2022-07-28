//
//  API Reference
//  kfxIParameters.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <UIKit/UIKit.h>

@class kfxLookAndFeelParameters;
@class kfxProcessingParameters;
@class kfxExtractionParameters;

//! The base class for capture view controller parameters.
/**
 Encapsulates all parameters common for capture view controllers.
 */
@interface kfxIParameters : NSObject <NSCopying>

/// Look and feel parameters object.
/**
 A property to get and set kfxLookAndFeelParameters object.
 The default value is nil.
 
 @see kfxLookAndFeelParameters
 */
@property (nonatomic, copy) kfxLookAndFeelParameters* lookAndFeelParameters;

/// Processing parameters object.
/**
 A property to get and set kfxProcessingParameters object.
 The default value is nil.
 
 @see kfxProcessingParameters
 */
@property (nonatomic, copy) kfxProcessingParameters* processingParameters;

/// Extraction parameters object.
/**
 A property to get and set kfxExtractionParameters object.
 The default value is nil.
 
 @see kfxExtractionParameters
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support extraction.@endif
 */
@property (nonatomic, copy) kfxExtractionParameters* extractionParameters;

@end
