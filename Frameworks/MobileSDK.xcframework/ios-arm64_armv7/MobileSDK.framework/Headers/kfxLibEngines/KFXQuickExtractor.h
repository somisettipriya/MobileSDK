//
//  KFXQuickExtractor.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2018 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>

@class kfxKEDImage;
@class KFXQuickExtractionSettings;

//! An extractor that extracts either a barcode or MRZ data and a face image from a static source image.
/**
 This extractor works with static images, see KFXQuickExtractorAgent for a version that processes preview frames during image capture.

 In order to successfully extract data with QuickExtract, the identification document being
 captured must be in the same orientation as the QuickExtract capture experience.
 
 @see KFXQuickExtractorAgent
*/
@interface KFXQuickExtractor : NSObject

/// Initializes a new object using the specified parameters.
/**
 @param settings Configuration object.
 
 @see KFXQuickExtractionSettings
 */
- (instancetype)initWithSettings:(KFXQuickExtractionSettings*)settings;

/// Runs extraction for static image.
/**
 @param image Source image for extraction.
 @param completionBlock Completion handler where fields is a NSArray that contains kfxKOEDataField objects of extracted data. faceImage is face image object. error is an error object if failure occurred or nil otherwise.
 
 @see kfxKOEDataField
 @see kfxKEDImage
 */
- (void)processImage:(kfxKEDImage*)image completionHandler:(void(^)(NSArray* fields, kfxKEDImage* faceImage, NSError* error))completionBlock;

@end
