//
//  kfxKUIDocumentBaseCaptureExperience.h
//  kfxLibUIControls
//
//  Copyright (c) 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <kfxLibUIControls/kfxKUICaptureExperience.h>
#import <kfxLibUIControls/kfxKUIDocumentBaseCaptureExperienceCriteriaHolder.h>
#import <kfxLibUIControls/kfxKUICaptureMessage.h>

@class kfxKEDDocumentBaseDetectionSettings;

//! This is the base class for check and document capture, that renders a visual experience on top of the capture control and returns an image, depending on the criteria set by the user.
/**
 This class is responsible for rendering the enhanced visual experience on top of the capture control, and provides feedback to
 guide the user to take a clear, legible and optimally zoomed in photo of a document.
 */
@interface kfxKUIDocumentBaseCaptureExperience : kfxKUICaptureExperience

/// An instructional text box that is displayed to the user while trying to capture a document.
/**
 This instruction will be displayed during periods where other guidance is not available to correct a user. This may happen in particular when the user is holding a device far away from a document, preventing automated detection from recognizing the document.
 
 The following kfxKUICaptureMessage properties are not supported for this message:
  - messageIcons
  - backGround
 
 Default configuration:
  - message: "Fill viewable area with document"
  - font: HelveticaNeue with size 25. If text can't be fit in the message box tail truncation will be used.
  - text color: white
  - backGroundColor: clear
  - position: centered inside viewfinder
  - size: width is equal to the viewfinder width and height is 100 points
  - orientation: landscape left
 
 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* userInstruction;

/// An instructional balloon that is displayed to the user to hold the device steady.
/**
 A property to configure the attributes of the message that is displayed on the capture control to direct the user to hold the device steady so that a clear focused image can be captured. This message is shown when all the constraints are met and ready to capture.
 
 Default configuration:
 - message: "Hold Steady"
 - text font: HelveticaNeue. If text can't be fit than font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: red
 - backGroundColor: black with 0.7 alpha component
 - position: centered inside viewfinder
 - size: 40% of imageCaptureControl size
 - orientation: landscape left
 - messageIcons: cameragrey.png and cameracolor.png from uiimages.bundle
   Icon is placed inside of the balloon and its position and size depends on the balloon size and text message.
   Icon will be centered inside balloon if there is no text message, otherwise it will be horizontally centered and shifted to the top to hold from 33% to 50% of vertical space depending on message length. Icon is scaled to fit available balloon space with fixed aspect ratio.
 - backGround: none
 
 @see kfxUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* holdSteadyMessage;

/// An instructional balloon that is displayed to the user for center the document.
/**
 This instruction will be displayed when document is not enough centered in the target frame for capture.
 
 Default configuration:
 - message: "Center Document"
 - text font: HelveticaNeue. If text can't be fit than font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: white
 - backGroundColor: black with 0.7 alpha component
 - position: centered inside viewfinder
 - size: 40% of imageCaptureControl size
 - orientation: landscape left
 - messageIcons: none
   Icon is placed inside of the balloon and its position and size depends on the balloon size and text message.
   Icon will be centered inside balloon if there is no text message, otherwise it will be horizontally centered and shifted to the top to hold from 33% to 50% of vertical space depending on message length. Icon is scaled to fit available balloon space with fixed aspect ratio.
 - backGround: none
 
 @see kfxUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* centerMessage;

/// An instructional balloon that is displayed to the user for when document is successfully captured.
/**
 This message will be displayed when document is captured.
 
 Default configuration:
 - message: "Done!"
 - text font: HelveticaNeue. If text can't be fit than font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: green
 - backGroundColor: black with 0.7 alpha component
 - position: centered inside viewfinder
 - size: 40% of imageCaptureControl size
 - orientation: landscape left
 - messageIcons: checkmark.png from uiimages.bundle
   Icon is placed inside of the balloon and its position and size depends on the balloon size and text message.
   Icon will be centered inside balloon if there is no text message, otherwise it will be horizontally centered and shifted to the top to hold from 33% to 50% of vertical space depending on message length. Icon is scaled to fit available balloon space with fixed aspect ratio.
 - backGround: none
 
 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* capturedMessage;

/// An instructional balloon that is displayed  to the user for zoom out action.
/**
 This message will be displayed when the capture experience needs to instruct the user to move the device farther away from the target document.
 
 Default configuration:
 - message: "Move Back"
 - text font: HelveticaNeue. If text can't be fit than font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: white
 - backGroundColor: black with 0.7 alpha component
 - position: centered inside viewfinder
 - size: 40% of imageCaptureControl size
 - orientation: landscape left
 - messageIcons: zoomoutcolor.png and zoomoutblack.png from uiimages.bundle
   Icon is placed inside of the balloon and its position and size depends on the balloon size and text message.
   Icon will be centered inside balloon if there is no text message, otherwise it will be horizontally centered and shifted to the top to hold from 33% to 50% of vertical space depending on message length. Icon is scaled to fit available balloon space with fixed aspect ratio.
 - backGround: none
 
 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* zoomOutMessage;

/// An instructional balloon that is displayed to the user for zoom in action.
/**
 This message will be displayed when the capture experience needs to instruct the user to move the device closer to the target document.
 
 Default configuration:
 - message: "Move Closer"
 - text font: HelveticaNeue. If text can't be fit than font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: white
 - backGroundColor: black with 0.7 alpha component
 - position: centered inside viewfinder
 - size: 40% of imageCaptureControl size
 - orientation: landscape left
 - messageIcons: zoomincolor.png and zoominblack.png from uiimages.bundle
   Icon is placed inside of the balloon and its position and size depends on the balloon size and text message.
   Icon will be centered inside balloon if there is no text message, otherwise it will be horizontally centered and shifted to the top to hold from 33% to 50% of vertical space depending on message length. Icon is scaled to fit available balloon space with fixed aspect ratio.
 - backGround: none
 
 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* zoomInMessage;

/// An instructional message that is displayed to the user for closing the tutorial.
/**
 This message will be displayed when the capture experience needs to instruct the user to skip tutorial demo.
 
 Default configuration:
 - message: "Tap to dismiss"
 - text font: HelveticaNeue. If text can't be fit then font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: white
 - backGroundColor: clear
 - position: left/right aligned to inside of viewfinder
 - size: width is equal to the viewfinder width and height is 100 points
 - orientation: landscape left
 
 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* tutorialDismissMessage;

/// An instructional balloon that is displayed to the user for rotate action.
/**
 This message will be displayed when the capture experience needs to instruct the user to rotate the device or the document.

 Default configuration:
 - message: "Rotate Device"
 - text font: HelveticaNeue. If text can't be fit than font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: white
 - backGroundColor: black with 0.7 alpha component
 - position: centered inside viewfinder
 - size: 40% of imageCaptureControl size
 - orientation: landscape left
 - messageIcons: rotatecolor.png and rotateblack.png from uiimages.bundle
 Icon is placed inside of the balloon and its position and size depends on the balloon size and text message.
 Icon will be centered inside balloon if there is no text message, otherwise it will be horizontally centered and shifted to the top to hold from 33% to 50% of vertical space depending on message length. Icon is scaled to fit available balloon space with fixed aspect ratio.
 - backGround: none

 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* rotateMessage;

/// An instructional balloon that is displayed to the user for holding the device more flat.
/**
 This instruction will be displayed when device is not enough parallel to the surface.
 The levelness thresholds can be set using the pitchThreshold and rollThreshold from kfxKUICaptureExperienceCriteriaHolder.

 Default configuration:
 - message: "Hold Device Level"
 - text font: HelveticaNeue. If text can't be fit than font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: white
 - backGroundColor: black with 0.7 alpha component
 - position: centered inside viewfinder
 - size: 40% of imageCaptureControl size
 - orientation: landscape left
 - messageIcons: holdparallelup.png and holdparalleldown.png from uiimages.bundle
 Icon is placed inside of the balloon and its position and size depends on the balloon size and text message.
 Icon will be centered inside balloon if there is no text message, otherwise it will be horizontally centered and shifted to the top to hold from 33% to 50% of vertical space depending on message length. Icon is scaled to fit available balloon space with fixed aspect ratio.
 - backGround: none

 @see kfxKUICaptureMessage
 @see kfxKUICaptureExperienceCriteriaHolder
 */
@property (nonatomic, strong) kfxKUICaptureMessage* holdParallelMessage;

/// An instructional balloon that is displayed to the user for tilting the device forward.
/**
 This instruction will be displayed when device is not enough tilted to the surface.
 The criteria is based on deviceDeclinationPitch and deviceDeclinationRoll
 
 Default configuration:
 - message: "Tilt Forward"
 - text font: HelveticaNeue. If text can't be fit than font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: white
 - backGroundColor: black with 0.7 alpha component
 - position: centered inside viewfinder
 - size: 40% of imageCaptureControl size
 - orientation: landscape left
 - messageIcons: holdparallelup.png and holdparalleldown.png from uiimages.bundle
 Icon is placed inside of the balloon and its position and size depends on the balloon size and text message.
 Icon will be centered inside balloon if there is no text message, otherwise it will be horizontally centered and shifted to the top to hold from 33% to 50% of vertical space depending on message length. Icon is scaled to fit available balloon space with fixed aspect ratio.
 - backGround: none
 
 @see kfxKUICaptureMessage
 @see kfxKUICaptureExperienceCriteriaHolder
 */
@property (nonatomic, strong) kfxKUICaptureMessage* tiltForwardMessage;

/// An instructional balloon that is displayed to the user for tilting the device up.
/**
 This instruction will be displayed when device is not enough tilted away from the surface.
 The criteria is based on deviceDeclinationPitch and deviceDeclinationRoll
 
 Default configuration:
 - message: "Tilt Up"
 - text font: HelveticaNeue. If text can't be fit than font size will be decreased down to 10 and tail truncation will be used if required.
 - text color: white
 - backGroundColor: black with 0.7 alpha component
 - position: centered inside viewfinder
 - size: 40% of imageCaptureControl size
 - orientation: landscape left
 - messageIcons: holdparallelup.png and holdparalleldown.png from uiimages.bundle
 Icon is placed inside of the balloon and its position and size depends on the balloon size and text message.
 Icon will be centered inside balloon if there is no text message, otherwise it will be horizontally centered and shifted to the top to hold from 33% to 50% of vertical space depending on message length. Icon is scaled to fit available balloon space with fixed aspect ratio.
 - backGround: none
 
 @see kfxKUICaptureMessage
 @see kfxKUICaptureExperienceCriteriaHolder
 */
@property (nonatomic, strong) kfxKUICaptureMessage* tiltUpMessage;

/// Whether to show an animated tutorial about how to capture a document.
/**
 A boolean that indicates whether to show an animated tutorial about how to capture a document. A demo animation runs, which can educate users on how to capture the document. App can add a check box to take input from the user, as to whether to show or skip this animation every time. In the action method this property can be set accordingly.
 
 By default is OFF.
 */
@property (nonatomic) BOOL tutorialEnabled;

/// A tutorial image showing how to capture a document.
/**
 A UIImage that will be displayed over the document frame area when the tutorialEnabled field is set to YES. The set image will be stretched to fill the entire document frame area while displayed.
 
 By default is nil.
 */
@property (nonatomic, strong) UIImage* tutorialSampleImage;

/// Outer viewfinder color.
/**
 Specifies the color that will be used for the outer viewfinder background.
 
 The default color is transparent grey.
 */
@property (nonatomic, strong) UIColor* outerViewfinderColor;

/// Guidance frame color.
/**
 Specifies the color that will be used for the guidance frame, for example in the case of check capture.
 
 The default color is green.
 */
@property (nonatomic, strong) UIColor* guidanceFrameColor;

/// Guidance frame thickness.
/**
 Specifies the thickness that will be used for the guidance frame, for example in the case of check capture.
 Valid values are in the range [1, 100]. Values outside this range will be interpreted as 8.
 
 The default thickness is 8.
 */
@property (nonatomic) int guidanceFrameThickness;

/// Steady guidance frame color.
/**
 Specifies the color that will be used for the guidance frame when control is ready to capture.
 If set to nil, the guidanceFrameColor will be used.
 
 By default is nil.
 */
@property (nonatomic, strong) UIColor* steadyGuidanceFrameColor;

/// Whether to start vibration when an image is captured.
/**
 A boolean to turn on/off vibration when an image is captured for haptic feedback.
 
 By default is YES.
 */
@property (nonatomic) BOOL vibrationEnabled;

/// Whether to show a diagnostics view.
/**
 A boolean to turn on/off diagnostics view.

 By default is NO.
 */
@property (nonatomic, assign) BOOL diagnosticsViewEnabled;

/// Begins the image capture process.
/**
 Calling this method will start the process of monitoring the capture criteria that was configured to determine when a document that meets all the criteria can be captured.
 The delegate will receive a imageCaptureControl:imageCaptured: message for each captured image.
 */
- (void)takePicture;

/// Starts the continuous capture of images.
/**
 Calling this method will start or stop the continuous capture of images. Images will automatically be captured when  criteria are satisfied.
 */
- (void)takePictureContinually;

/// Stops taking a picture.
/**
 This can be used in continuous mode as well to stop taking pictures
 */
- (void)stopCapture;

/// Initialized for the object using the specified parameters.
/**
 Initializes a base document capture experience and binds it to the given image capture control.  The experience class overrides the capture control delegate to provide additional behavior and guidance useful for capturing documents.  It also forwards delegate invocations to the original delegate set on the capture control, thus acting as a proxy.
 
 If you are interested in handling any of the delegate methods on the capture control, it is important that you set your delegate before initializing the capture experience.  Setting a new delegate after initializing the capture experience will break the association with the capture control, and allow the capture experience to be shut down and deallocated if no other references to the object remain.  This is the proper protocol for cleaning up a capture experience you are no longer interested in.
 
 The base document capture experience will add several overlays and subviews on top of the associated image capture control for visual guidance and feedback.  It will also manage some of the capture control's native properties, which could interfere with any properties you directly modify on the control.
 
 For best results, your image capture control should be configured to use video capture mode.  This will normally result in a larger preview resolution being used.  Small preview resolutions will make document detection difficult and negatively impact user guidance.  In particular, the capture experience will rarely be able to deliver zoom-related guidance with low resolution preview images.
 
 @param captureControl An instance of a kfxKUIImageCaptureControl object.
 @param criteria A collection of constraints and attributes that control the behavior of the capture experience. Pass nil for the default experience.
 */
- (instancetype)initWithCaptureControl:(kfxKUIImageCaptureControl*)captureControl criteria:(kfxKUIDocumentBaseCaptureExperienceCriteriaHolder*)criteria;

@end
