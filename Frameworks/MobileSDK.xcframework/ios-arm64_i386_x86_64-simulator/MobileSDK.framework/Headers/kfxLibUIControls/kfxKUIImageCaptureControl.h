//
//  API Reference
//  kfxKUIImageCaptureControl.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.


#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>
#import <CoreMedia/CMSampleBuffer.h>

#import "kfxKUICommon.h"
#import "kfxKUIFrame.h"
#import "kfxKUIPageDetectionEvent.h"
#import "kfxKEDImageCapturedEvent.h"

@class kfxKEDBoundingTetragon;
@class kfxKEDImage;
@class kfxKUIImageCaptureControl;

//! This protocol must be implemented by classes whose objects are used as kfxKUIImageCaptureControl delegates
/**
 This defines protocol messages that will be sent to kfxKUIImageCaptureControl delegate
 objects.
 */
@protocol kfxKUIImageCaptureControlDelegate<NSObject>

@optional
//! A message that indicates the current stability of the device.
/** A message that indicates the current stability, which is a number from
 0-100, where 100 means that the device is completely stable and 0 is the
 maximum instability.
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl*)imageCaptureControl
            stabilityDelay:(int) stabilityDelay;

//! A message that indicates that an image was captured.
/** A message that indicates that an image was captured. The control will wait until the desired
 stability, levelness, and camera adjustments are met and then capture an image and send
 it with this message.
 
 @deprecated Deprecated in 3.5.
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl
             imageCaptured:(kfxKEDImage*)image;

//! A message that indicates that an image was captured.
/** A message that indicates that an image was captured. The control will wait until the desired
 stability, levelness, and camera adjustments are met and then capture an image and send
 it with this message.
 
 If glareDetection is enabled and glare is detected the user would have glareFreeImage in the imageCapturedEvent. Otherwise, it would be nil. User will be always thrown this message, if doesn't implement this, then it would fallback to the deprecated message.
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl
        imageCapturedEvent:(kfxKEDImageCapturedEvent*)imageCapturedEvent;

//! A message that indicates the current pitch and roll.
/** A message that indicates the current angles of pitch and roll of the device.
 Both pitch and roll are angles in degrees.
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl
            pitchChangedTo:(int)pitch rollChangedTo:(int)roll;

//! A message that indicates the camera has begun or finished focusing.
/** A message that indicates the camera has begun or finished focusing, where the boolean value NO indicates the camera is focusing, or YES, that focusing is complete
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl
            focusStateChanged:(BOOL)isFocused;

//! A message that indicates that an image is about to capture.
/** A message that indicates that an image is about to capture. This message will be called just before the image is captured.
 */
-(void)imageIsAboutToCaptureForControl:(kfxKUIImageCaptureControl*)imageCaptureControl;

//! A message that indicates that an image is just captured.
/** A message that indicates that an image is just captured.
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl*)imageCaptureControl
         imageJustCaptured:(kfxKEDImage*)image;

//! A message that is dispatched whenever a new video sample is available from the camera.
/**
 As the control processes video frames from the camera preview, the handler for this message will be called
 before any other processing takes place.
 
 While the handler is being run, the rest of the pipeline will block.  Any new video frames that would have been
 available from the camera during this time will be discarded.  When the handler finishes, the rest of the capture
 logic will be processed normally.  If built-in features such as page detection or stability would create
 redundant work or undesirable behavior, then they should be disabled.
 
 The handler is being invoked from internal SDK thread, and its highly recommended to make implementation lightweight with no blocking
 and avoiding sample buffer retain.
 
 @param imageCaptureControl The capture control dispatching the message.
 @param videoSample The camera preview sample buffer in kCVPixelFormatType_32BGRA format.
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl videoSampleAvailable:(CMSampleBufferRef)videoSample;

//! A message that indicates page detection has located a document in the camera preview.
/**
 When page detection locates a document, it dispatches this message with the kfxKUIPageDetectionEvent.
 The event includes the preview image that was processed by page detection, and the bounding coordinates
 of the detected page.
 
 The handler is being invoked only when ImageCaptureControl is using in conjuction with CaptureExperience.
 
 While the handler is being run, the rest of the pipeline will block.  Any new video frames that would have been
 available from the camera during this time will be discarded.  When the handler finishes, the rest of the capture
 logic will be processed normally.
 
 The handler is being invoked from internal SDK thread, and its highly recommended to make implementation lightweight
 with no blocking. Consider to access kfxKUIPageDetectionEvent properties within sender thread.
 
 Example code.
 
 @code
 - (void)imageCaptureControl:(kfxKUIImageCaptureControl*)imageCaptureControl pageDetected:(kfxKUIPageDetectionEvent*)event
 {
     UIImage* image = [event getImage];
     kfxKEDBoundingTetragon* bounds = [event getPageBounds];
 
     dispatch_async(dispatch_get_main_queue(), ^
     {
         // Update UI with using image and bounds
     });
 }
 @endcode

 @param imageCaptureControl The capture control dispatching the message.
 @param event The event with the preview image and bounding coordinates of the detected page.

 @see kfxKUIPageDetectionEvent
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl
              pageDetected:(kfxKUIPageDetectionEvent *)event;

@end


//! This class renders the camera preview to the screen and returns an image.
/**
 This class is responsible for rendering the camera preview and provides visual level and stability feedback to
 guide the user to take a clear photo.
 */
@interface kfxKUIImageCaptureControl : UIView

//! This message initializes the control and must be sent to the class before it is used.
/**
This message initializes the control for use and must be sent to the class before it is used.
 It is ok to send the message more than once. A common way to do this is in your UIViewController
 subclasses initialize or init methods.
 */
+(void) initializeControl;

/// The current camera flash mode.
/**
 A property to get or set the flash/torch mode. The supported values are:
 kfxKUIFlashOff - Indicates that the flash should always be off.
 kfxKUIFlashOn - Indicates that the flash should always be on. Supported only for still image capture mode.
 kfxKUIFlashAuto - Indicates that the flash should be used automatically depending on ambient light conditions. Supported only for still image capture mode.
 kfxKUITorch - Indicates that the torch should always be on.
 kfxKUITorchAuto - Indicates that the torch should be turned on automatically depending on ambient light conditions. Once torch is on it will not be turned off automatically.
 
 The default value is kfxKUIFlashOff.
 
 @see kfxKUIFlashSetting
 */
@property (nonatomic) kfxKUIFlashSetting flash;

/// Whether the video frame is retured, or a full-resolution image is captured
/**
 A boolean that indicates whether the video frame, or a full-resolution image is returned when capture
 is requested.  Using the video frame may speed up image classification, but will result in less accurate
 results, as there is less image data to work with.
 
 switching between video frame and full-resolution capture will cause the session preset (the capture resolution) to be reset to its default value.  For video frame capture, the default preset is 1080p if supported, or 720p.  For full-resoluton capture, the default preset is photo quality.  If you want to change the session preset, do so after changing this property.
 */
@property (nonatomic) BOOL useVideoFrame;

/// A Boolean value that indicates whether still image stabilization should be automatically enabled when available.
/**
 If Image Stabilization is supported by device, it may be applied to reduce blur commonly found in low light photos. When stabilization is enabled, still image captures incur additional latency.
 
 This setting is applicable only for a full-resolution image capture mode when useVideoFrame is set to NO.
 For devices with no stabilization support this will do nothing.
 
 The default value is YES which mean stabilization will be automatically enabled when available.
 */
@property (nonatomic) BOOL automaticallyEnablesStillImageStabilization;

/// A Boolean value that indicates whether capture control should emit still images at the highest resolution supported.
/**
 When enabled, the capture control emits still images at the highest resolution supported.
 When disabled, the capture control emits images with the same dimensions as current session preset.
 
 This setting is applicable only for a full-resolution image capture mode when useVideoFrame is set to NO.
 Supported starting iPhone 6 and 6 Plus.
 
 The default value is YES.
 */
@property (nonatomic) BOOL highResolutionStillImageEnabled;

/// A Boolean value that indicates whether to use ultrawidelens or not
/**
 When enabled, checks device has ultrawidelens are available or not, if available, sets to the ultrawidelens camera.
 otherwise default camera will be used.
 
 The default value is False.
 */

@property (nonatomic) BOOL useUltraWideLensIfPresent;

/// The reference pitch that indicates what angle means that the device is level
/** A property to get or set an angle in degrees that will be used to determine that the device
 is level. The default value is 0, which indicates that the top and bottom of the device are in 
 the same horizontal plane. A positive value indicates that the top of the device should be higher 
 than the bottom for the device to be considered level, and a negative value means that the bottom should be higher.
 
 Valid values are in the range [-180, 180].
 */
@property (nonatomic) int deviceDeclinationPitch;

/// The reference roll that indicates what angle means that the device is level
/** A property to get or set an angle in degrees that will be used to determine that the device
 is level. The default value is 0, which indicates that the left and right sides of the device are in
 the same horizontal plane. A positive value indicates that the left side of the device should be higher 
 than the right for the device to be considered level, and a negative value means that the right side should be higher.
 
 Valid values are in the range [-180, 180].
 */
@property (nonatomic) int deviceDeclinationRoll;

/// Gets the camera preview resolution.
/**
 A read-only property to get the resolution of the camera preview.  This value will vary depending
 on the target device and its camera capabilities.
 
 Note, this property can only return an accurate value after the camera has been initialized and
 processed its first preview frame.  This property cannot be reliably called anywhere in the view
 construction lifecycle, including the methods viewDidLoad and viewDidAppear.
 */
@property (readonly, nonatomic) CGSize imagePreviewSize;

/// Gets the default camera focus point.
/**
 @see focusPoint
 */
@property (readonly) CGPoint defaultFocusPoint;

/// The camera focus point.
/**
 Specifies the point where the camera should adjust focus.  The camera will analyze the image data
 in a small area around the focus point to determine the optimal focus.
 
 The camera focus point is specified in the control's local coordinate space.  The valid coordinate
 range is (0, 0) to (width, height) using the dimensions of the ImageCaptureControl.  The property
 will translate these coordinates into the camera's coordinate space.
 
 If a coordinate is specified outside an area covered by the camera preview, then the closest valid
 point will be used instead.  For example, if the camera preview aspect ratio does not match the
 aspect ratio of the control, black margins will be present on sides.  Specifying a point in the margin
 area will result in the closest point on the preview edge being used instead.
 
 A set focus point will remain in effect until the control is invalidated.  Resizing the control,
 changing camera parameters, or suspending the application are all sufficient to invalidate the
 set focus point.  The value of the focus point is undefined once it is invalided.
 
 If setting the focus point is not supported on the device, setting this property will raise an
 exception.
 
 @see defaultFocusPoint
 */
@property (nonatomic) CGPoint focusPoint;

/// A delegate to receive messages from the control
/** A property to get or set the delegate that will be notified of stability, levelness and 
 captured images.
 */
@property (nonatomic, weak) IBOutlet id<kfxKUIImageCaptureControlDelegate> delegate;

/// The motion manager being used to detect the levelness of the device
/** A property to get or set the motion manager to use to detect the levelness of the device.
 If this is never set, one will be allocated which is available to use if the application wants
 to get motion events at the same time as the control.  It may also be set, but that must be done
 in the view controller's viewDidLoad or before.
 */
@property (nonatomic, strong) CMMotionManager* motionManager;

/// gpsUsageLimits - controls whether GPS location information is captured with the image.
/** The property allows the app to determine whether the Image Capture Control includes GPS location
 information with the captured image. The kfxKUIGPSUsageLimits enum has two settings:
 
 kfxKUINeverUse - GPS information will not be gathered under any circumstances. When using
    kfxKUINeverUse, the user is not queried for permission to collect location information.
 kfxKUIAlwaysUseIfEnabled - GPS information will be gathered if permitted by the operating system.
    With kfxKUIAlwaysUseIfEnabled, the user may be queried for permission if no user preference has
    previously been determined. This is the default setting of this property.
 
 This property should be set in the viewDidLoad method (before the control is displayed).
 
 @deprecated Deprecated in 3.7.
 
 */
@property (nonatomic) kfxKUIGPSUsageLimits gpsUsageLimits;


/// Begins the image capture process and ignores all capture constraints.
/**
 Calling this method will stat the image capture process, but constraints like levelness, stability, and page
 detection will be ignored.  The control will attempt to take a picture as quickly as possible.  The delegate will receive a imageCaptureControl:imageCaptured: message for each captured iamge.
 
 @retval    KMC_SUCCESS         The control will attempt to capture a picture.
 @retval    KMC_EV_LICENSING    The control did attempt attempt to capture a picture due to a licensing error.
 */
-(int)forceTakePicture;

/// Begins the image capture process and ignores all capture constraints.
/**
 Calling this method will start the image capture process, but constraints like levelness, stability, and page
 detection will be ignored.  The control will attempt to take a picture as quickly as possible.  The delegate will receive a imageCaptureControl:imageCaptured: message for each captured iamge.
 
 @param     waitForFocus          YES to check focus check Criteria, NO to take picture without checking any crieteria.
 
 @retval    KMC_SUCCESS         The control will attempt to capture a picture.
 @retval    KMC_EV_LICENSING    The control did not attempt to capture a picture due to a licensing error.
 */
-(int)forceTakePicture:(BOOL)waitForFocus;

/// Sets the desired preset for image capture.
/**
 * Sets the desired preset for image capture.  The actual resolution of a captured image may
 * be reversed from what is given (e.g. a 960x1280 image may be returned for a 1280x960 request).
 * Presets may select different image resolutions depending on device.
 *
 * After calling this method, the kfxUIImageCaptureControl instance may resize itself.
 *
 * <b>Note:</b> The AVCaptureControlInputPriority preset is not supported.
 *
 * @param   resolution    A session preset
 *
 * @retval  KMC_SUCCESS The desired preset was accepted
 * @retval  KMC_GN_UNSUPPORTED_OPERATION The desired preset is not supported
 *
 * @see useVideoFrame
 */
-(int)setImageResolution:(NSString*)resolution;

/// Returns whether the given preset can be used.
/**
 The preset values accepted by this method are the same session presets defined by Apple in AVFoundation.
 
 The camera session must be active before this method can return correct results.  If your instance of the
 ImageCaptureControl is being attached to your view implicitly by a storyboard or Interface Builder, then
 the earliest place you should query this method is in your view's viewDidAppear method.
 
 If you are explicitly attaching an ImageCaptureControl to your view in code, then you can query this method 
 at any point after, as long as the control remains attached to the active view hierarchy.
 
 @param resolution    A session preset
 
 @see setImageResolution:
 */
-(BOOL)canSetResolution:(NSString*)resolution;

/// Begin an AppStats session.
/**
 This method begins a new AppStats session. It creates a new instance object and initializes it
 with the current time. In combination with SessionDismiss, it allows specified log information
 to be bracketed with begin and end times.
 */
- (void) SessionCreate;

/// End an AppStats session.
/**
 This method ends an AppStats session. It updates a previously created instance object with a
 dismissal time.
 */
- (void) SessionDismiss;

/// Sets the camera type for capture experience.
/**
 *
 * @param   cameraType    A enumaration value to set front/back camera.
 *
 * @retval  KMC_SUCCESS when camera type is available
 * @retval  KMC_GN_UNSUPPORTED_OPERATION when camera type is not available
 *
 */
-(int)setCameraType:(kfxKUICameraType)cameraType;

@end


