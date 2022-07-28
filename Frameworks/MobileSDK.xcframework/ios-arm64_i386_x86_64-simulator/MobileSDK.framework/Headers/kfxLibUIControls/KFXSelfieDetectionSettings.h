//
//  kfxSelfieDetectionSettings.h
//  kfxLibUIControls
//
//  Created by Kofax on 02/03/17.
//  Copyright © 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface KFXSelfieDetectionSettings : NSObject

/// Percentage of face fits in the target frame.
/**
 Percentage of face fits in the target frame while captureing the selfie.
 
 default value is 0.25. range is (0.25 to 1).
 */

@property (nonatomic, assign) CGFloat minimumFaceSize;

/// The face angle to detect the face.
/**
 Rotation is measured counterclockwise in degrees, with zero indicating that a line drawn between the eyes is horizontal relative to the image orientation. 
 
 The torerance will be calculated between negative angle to positve angle. ex: if faceAngleTolerance is 15 then it will be calculated between "-15" to "15".
 
 default value is 15. range is (0 to 60).
 */

@property (nonatomic, assign) CGFloat faceAngleTolerance;


//These values are used for drawing oval/ellipse on capture view.


/// The center point within the image of the target ellipse.
/**
 The center point is any point within the image that the target ellipse will be constructed around and centered over.  This value will be clamped the valid area of the image being searched, and by default is set to the center of the image.
 */

@property (nonatomic, assign) CGPoint targetFrameCenter;

/// The aspect ratio of the ellipse  that should match the document being searched.
/**
 The aspect ratio is used to construct the target ellispe that should match the document being searched.
 If targetFrameAspectRatio > 1, the long edge of the target ellipse will align with the long edge of the camera preview. If 0 < targetFrameAspectRatio < 1, the long edge of the target ellipse will align with the short edge of the camera preview.
 
 If the targetEllipseAspectRatio is set to 0, then it will be automatically reset to an image aspect ratio.
 Setting negative values has the same effect as if 0 was set.
 
 The default value is 0.
 */

@property (nonatomic, assign) CGFloat targetFrameAspectRatio;

/// The minimum padding in percent length to be maintained between the edges of the target ellipse and image.
/**
 Given a center point and aspect ratio, a ellipse frame will be constructed to cover as much of the image as possible without any the distances between a frame edge and image edge falling below the padding distance, calculated as percent of the perpendicular image edge length.  Values will be clamped to the range [1-50].  The default value is 10.
 
 For example:
 - Given detection settings with a frame center at the center of the image, and a personal check aspect ratio, the constructed frame will fill the width of the image, leaving a space on the left and right equal to the padding percent of the image width.
 
 - Given detection settings with a frame center shifted to the left of the image center, the gap on the right side of the constructed frame will exceed the gap on the left.
 */

@property (nonatomic, assign) CGFloat targetFramePaddingPercent;

@end
