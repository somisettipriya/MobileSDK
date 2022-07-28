//
//  API Reference File
//  kfxKUIPageDetectionEvent.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <UIKit/UIKit.h>

@class kfxKEDBoundingTetragon;

//! This class that indicates a page was detected in the camera preview.
/**
 This event is raised in response to a page being detected in the camera preview,
 if page detection is enabled. The event includes the preview image that was processed
 by page detection, and the bounding coordinates of the detected page.
 
 See imageCaptureControl:pageDetected: from kfxKUIImageCaptureControl for sample code.
 */
@interface kfxKUIPageDetectionEvent : NSObject

//! The bounding coordinates of the detected page.
/**
 The bounding coordinates of the detected page in coordinates of preview image.  Top left point of
 detected bounds is closest point to top left corner of preview image.

 */
- (kfxKEDBoundingTetragon*) getPageBounds;

//! The preview image that the page was detected in.
/**
 The preview image that was processed by page detection.

 */
- (UIImage*) getImage;

@end

