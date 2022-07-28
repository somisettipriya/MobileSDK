//
//  kfxKEDDocumentDetectionResult.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "kfxKEDBoundingTetragon.h"

typedef enum kedDocumentZoomGuidance {
    KED_DOCUMENT_ZOOM_IN,
    KED_DOCUMENT_ZOOM_OUT,
    KED_DOCUMENT_ZOOM_OK,
} KEDDocumentZoomGuidance;

typedef enum kedDocumentTurnGuidance {
    KED_DOCUMENT_TURN_COUNTER_CLOCKWISE,
    KED_DOCUMENT_TURN_CLOCKWISE,
    KED_DOCUMENT_TURN_OK,
} KEDDocumentTurnGuidance;

typedef enum kedDocumentHorizontalGuidance {
    KED_DOCUMENT_HORIZONTAL_MOVE_LEFT,
    KED_DOCUMENT_HORIZONTAL_MOVE_RIGHT,
    KED_DOCUMENT_HORIZONTAL_MOVE_OK,
} KEDDocumentHorizontalGuidance;

typedef enum kedDocumentVerticalGuidance {
    KED_DOCUMENT_VERTICAL_MOVE_UP,
    KED_DOCUMENT_VERTICAL_MOVE_DOWN,
    KED_DOCUMENT_VERTICAL_MOVE_OK,
} KEDDocumentVerticalGuidance;

typedef enum kedDocumentOrientationGuidance {
    KED_DOCUMENT_ORIENTATION_CHANGE,
    KED_DOCUMENT_ORIENTATION_OK,
} KEDDocumentOrientationGuidance;

//! A base class for detection results.
@interface kfxKEDDocumentBaseDetectionResult : NSObject
{
    KEDDocumentZoomGuidance _zoomGuidance;
    KEDDocumentTurnGuidance _turnGuidance;
    KEDDocumentHorizontalGuidance _horizontalMovementGuidance;
    KEDDocumentVerticalGuidance _verticalMovementGuidance;
    KEDDocumentOrientationGuidance _orientationGuidance;
}

//! The bounding coordinates of the detected check.
@property (nonatomic, strong, readonly) kfxKEDBoundingTetragon* bounds;

//! The original image that was supplied to the CheckDetectionManager object.
@property (nonatomic, strong, readonly) UIImage* originalImage;

//! Reports guidance for obtaining the optimal size of a check within the frame.
/**
 An enum value indicating whether the user should zoom in, zoom out, or if zoom is okay.  Guidance is based on how much of the detected check area covers the target area, and is controlled by a minimum and maximum tolerance specified in the CheckDetectionSettings object given to the detector.
 
 Matching checks with aspect ratios different than the target rectangle will require more tolerance in the upper or lower bounds to report a good zoom level.
 */
@property (nonatomic, readonly) KEDDocumentZoomGuidance zoomGuidance;

//! Reports guidance for correcting off-angle rotation for a check.
/**
 An enum value indicating whether the user should rotate or if the angle is okay.  Guidance is based on the difference between the detected check angle and target frame angle.  It is controlled by a maximum tolerance specified in the CheckDetectionSettings object given to the detector.
 */
@property (nonatomic, readonly) KEDDocumentTurnGuidance turnGuidance;

//! Reports guidance for correcting horizontal position of a check within a frame.
/**
 An enum value indicating whether the user should move the check to the left or right, or if position is okay.
 */
@property (nonatomic, readonly) KEDDocumentHorizontalGuidance horizontalMovementGuidance;

//! Reports guidance for correcting vertical position of a check within a frame.
/**
 An enum value indicating whether the user should move the check up or down, or if position is okay.
 */
@property (nonatomic, readonly) KEDDocumentVerticalGuidance verticalMovementGuidance;

//! Reports guidance for same document orientation with a frame.
/**
 An enum value indicating whether the user should rotate to match frame orientation or if the orientatoin is okay.
 */
@property (nonatomic, readonly) KEDDocumentOrientationGuidance orientationGuidance;

/// Returns the target rectangle.
/**
 The target frame is a rectangular area confined within the bounds of the image, and represents the the ideal area that should be covered by a document.
 */
@property (nonatomic) CGRect targetRect;

/// Resets cached guidance.
/**
 Call this to reset cached guidance. Once guidance is generated it will be cached, so there will be no calculation on next property access.
 */
- (void)resetCachedGuidance;

@end
