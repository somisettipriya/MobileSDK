//
//  kfxKUICaptureExperienceCriteriaHolder.h
//  kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <UIKit/UIKit.h>

//! This class allows the capture criteria to be configured.
/**
 This class allows all of the capture related parameters to be configured.The criterion are met before a picture is taken. The threshold parameters in this class are not set on image capture control directly.
 */
@interface kfxKUICaptureExperienceCriteriaHolder : NSObject

/// Whether the stability threshold is enabled.
/**
 A boolean that indicates whether the stability threshold is enabled.If enabled this criteria is checked before taking a picture.
 */
@property (nonatomic) BOOL stabilityThresholdEnabled;

/// The stability threshold value
/**
 Stability Value which needs to be met before taking a picture. It is a number from 0 to 100, where 100 indicates that the device must be near perfectly still to take a picture and 0 indicates that stability checking is turned off.
 Default value is 95

 */
@property (nonatomic) int stabilityThreshold;

/// Whether the Pitch threshold is enabled.
/**
 A boolean that indicates whether the Pitch threshold is enabled. If enabled this criteria is checked before taking a picture.
 */
@property (nonatomic) BOOL pitchThresholdEnabled;

/// The Pitch threshold value
/**
 Pitch Value which needs to be met before taking a picture.
 The default value is 15.
 Valid values are in the range [0, 45].  Values outside this range will be interpreted as 0 or 45.  A value
 of 45 disables level checking for pitch.
 
 */
@property (nonatomic) int pitchThreshold;

/// Whether the Roll threshold is enabled.
/**
 A boolean that indicates whether the Roll threshold is enabled. If enabled this criteria is checked before taking a picture.
 */
@property (nonatomic) BOOL rollThresholdEnabled;

/// The Roll threshold value
/**
 Roll Value which needs to be met before taking a picture. The default value is 15.
 Valid values are in the range [0, 45].  Values outside this range will be interpreted as 0 or 45.  A value
 of 45 disables level checking for roll.

 */
@property (nonatomic) int rollThreshold;

/**
 A boolean that indicates whether the glare detection is enabled.
 
 This criteria is checked after taking a picture and user would be asked to do one more capture by tilting the device if a glare is detected.
 
 User can use "takePicture" on capture experience to capture glare free image. And also can use "takePictureContinously" to capture glare free images continously.
 
 Default value is NO.
 */


@property (nonatomic, assign) BOOL glareDetectionEnabled;

/**
 A boolean that indicates whether the flash capture is enabled.
 
This boolean value will be used if user wants to take two images, one "without flash" image and other "with flash" image. These images will be useful for to get better verification results.
 
 Note: The second image will not have flash if "useVideoFrame" is enabled on imageCaptureVeiw and this feature will not work if launchGlareRemoverExperience or glareDetectionEnabled is enabled. And this feature is not applicable to devices which are not having flash.
 
 Default value is NO.
 */

@property (nonatomic, assign) BOOL flashCaptureEnabled;


/// Whether glare experience should be launched.
/**
 A boolean that indicates whether the glare experience is enabled. If enabled, user would be guided to capture two images of the document at different tilt angles.

 User can use "takePicture" on capture experience to capture glare free image. And also can use "takePictureContinously" to capture glare free images continously.

 Default value is NO.
 */

@property (nonatomic, assign) BOOL launchGlareRemoverExperience;

/// The reference angle that indicates how much should the device be tilted for the second capture
/** A property to get or set an angle in degrees that will be used to determine the angle of tilt for the second capture. The default value is 12, which indicates that the device's edge that is away from the user should stand higher
    than the device's edge that is closer to the user.
 
 Valid values are in the range [-20, 20].
 */

@property (nonatomic, assign) int tiltAngle;

/// The reference threshold that indicates how much glare fraction should be configured on the captured Image.

/** Configuring the Glare Threshold value will control the launch of second capture experience(Tilt capture) when glareDetectionEnabled/launchGlareRemoverExperience is set to true.
  The default value is 0.03
 
  Valid values are in the range [0, 1].
 */

@property (nonatomic, assign) double glareThreshold;

/// The default threshold for the glareThreshold property.
/** Gives the default threshold for the device. Value is 0.03
 */

@property (nonatomic, readonly) double defaultGlareThreshold;

/// Whether the Focus constraint is enabled.
/**
 A boolean that indicates whether the Focus constraint is enabled. If enabled this criteria is checked before taking a picture.
 Making it enabled is advisable. Otherwise it is highly likely that images out of focus are captured. Default value is enabled.
 */
@property (nonatomic) BOOL focusConstraintEnabled;

/// Whether to detect if the orientaion of page results in optimum overlap of page and Imagecapturecontrol
/**
 A boolean that indicates whether the orientation of the page is in best way possible for maximum overlap of page detected and Imagecapturecontrol. For instance  if a document is perpendicular to the device i.e. document is horizontal  and device is in portrait ((long edge of the document is paralled to short edge of the device) then the area overlap of document detected and the imagecapturecontrol is minimum and can result in images of poor quality. If this boolean is set enabled, document doesnot get captured in the above scenario and an error message is displayed.
 Default value is YES.
 */
@property (nonatomic) BOOL pageOrientationEnabled;

/// Whether to refocus before taking a picture.
/**
 A boolean that indicates that camera needs to be refocused right before taking a picture when all capture criteria are met. This has no effect when force taking a picture using forceTakePicture or forceTakePicture:NO calls for kfxKUIImageCaptureControl, use forceTakePicture:YES if you need refocus right befor force taking a picture.
 Default value is YES.
 */
@property (nonatomic, assign) BOOL refocusBeforeCaptureEnabled;

/// The delay for how long hold steady message should be shown before starting the capture.
/**
 A NSTimeInterval that controls the minimum duration for how long hold steady message should be shown before starting the capture. The actual hold steady duration before taking the picture may vary depending on capture conditions, but it should not be less than passed value. Valid values are in the range [0.0, 3.0]. Values outside this range will be interpreted as 0.0 or 3.0.
 Default value is 1.0 (1 second).
 */
@property (nonatomic, assign) NSTimeInterval holdSteadyDelay;

/// Whether the page detection constraint is enabled.
/**
 A boolean that indicates whether the page detection constraint is enabled. If enabled this criteria is checked before taking a picture.
 Set it to NO in order to prevent page detection and suppress guidances messages like: center, zoomIn, zoomOut, rotate, etc.
 Default value is YES.
 */
@property (nonatomic, assign) BOOL pageDetectionEnabled;

@end
