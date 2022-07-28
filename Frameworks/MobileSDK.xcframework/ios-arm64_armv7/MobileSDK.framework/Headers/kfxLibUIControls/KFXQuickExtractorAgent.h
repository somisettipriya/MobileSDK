//
//  KFXQuickExtractorAgent.h
//  kfxLibUIControls
//
//  Copyright (c) 2014-2018 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import <kfxLibUIControls/kfxKUIImageCaptureControl.h>
#import <kfxLibUIControls/kfxKUICaptureExperience.h>

@class kfxKEDImage;
@class KFXQuickExtractorAgent;
@class KFXQuickExtractionSettings;

//! This protocol must be implemented by classes whose objects are used as KFXQuickExtractorAgent delegates.
/**
 This defines protocol messages that will be sent to KFXQuickExtractorAgent delegate objects.
 */
@protocol KFXQuickExtractorAgentDelegate<NSObject>

@optional

/// A message that indicates the fields are extracted.
/**
 The message is invoked once a barcode or MRZ is detected, read and parsed successfully.
 
 @param quickExtractorAgent Object dispatching the message.
 @param fields An array of extracted fields. NSArray that contains kfxKOEDataField objects.
 @param previewFrame Preview frame where data was extracted.
 
 @see kfxKOEDataField
 @see kfxKEDImage
 */
- (void)quickExtractorAgent:(KFXQuickExtractorAgent*)quickExtractorAgent
            fieldsExtracted:(NSArray*)fields
               previewFrame:(kfxKEDImage*)previewFrame;

/// A message that indicates the face image is extracted.
/**
 The message is invoked once face is detected.
 
 @param quickExtractorAgent Object dispatching the message.
 @param faceImage Face image.
 @param previewFrame Preview frame where face was extracted.
 
 @see kfxKEDImage
 */
- (void)quickExtractorAgent:(KFXQuickExtractorAgent*)quickExtractorAgent
              faceExtracted:(kfxKEDImage*)faceImage
               previewFrame:(kfxKEDImage*)previewFrame;

@end

//! An extractor that extracts either a barcode or MRZ data and a face image during image capture.
/**
 This extractor processes preview frames from image capture control and calls the listener
 when a barcode or MRZ is detected, read and parsed successfully or a face image is extracted.
 Also see KFXQuickExtractor, which privides similar functionality, but works with static images.

 In order to successfully extract data with QuickExtractAgent, the identification document being
 captured must be in the same orientation as the QuickExtractAgent capture experience.
 
 @see KFXQuickExtractorAgentDelegate
 @see KFXQuickExtractor
 */
@interface KFXQuickExtractorAgent : NSObject<kfxKUIImageCaptureControlDelegate>

/// A delegate to receive messages from the extractor.
/**
 The delegate that is invoked when a barcode or MRZ is detected,
 read and parsed successfully or a face image is extracted.
 */
@property (nonatomic, weak) IBOutlet id<KFXQuickExtractorAgentDelegate> delegate;

/// Initializes a new object with the specified parameters and binds it to the given capture experience.
/** 
 @param captureExperience Capture Experience object to which extractor will be binded.
 @param settings Configuration object.
 
 @see KFXQuickExtractionSettings
 */
- (instancetype)initWithCaptureExperience:(kfxKUICaptureExperience*)captureExperience
                                 settings:(KFXQuickExtractionSettings*)settings;

@end
