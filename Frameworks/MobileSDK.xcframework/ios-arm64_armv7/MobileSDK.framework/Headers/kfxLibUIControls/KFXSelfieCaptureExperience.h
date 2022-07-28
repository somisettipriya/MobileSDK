//
//  KFXSelfieCaptureExperience.h
//
//  Created by Kofax on 18/01/17.
//  Copyright © 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <kfxLibUIControls/kfxKUIImageCaptureControl.h>
#import <kfxLibUIControls/KFXSelfieCaptureExperienceCriteriaHolder.h>
#import <kfxLibUIControls/KFXBaseObjectCaptureExperience.h>
#import <kfxLibUIControls/kfxKUICaptureMessage.h>

//! This class renders a visual experience on top of the capture control when it is facing front side and returns an image depending on the criteria set by the user.
/**
 This class is responsible for rendering the enhanced visual experience on top of the capture control, and provides feedback to
 guide the user to take an optimal photo that meets all of the configured capture criteria.
 */

@interface KFXSelfieCaptureExperience : KFXBaseObjectCaptureExperience

/// Begins the image capture process.
/**
 Calling this method will start the process of monitoring the configured capture criteria. An image will be captured once all of the criteria are met.
 The delegate will receive a imageCaptureControl:imageCaptured: message for each captured image.
 */

- (void)takePicture;

/// Stops taking a picture.
/**
 Calling this method to stop taking pictures
 */

- (void)stopCapture;

/// Initialized for the object using the specified parameters.
/**
 Initializes a base selfie capture experience and binds it to the given image capture control.  The experience class overrides the capture control delegate to provide additional behavior and guidance useful for capturing documents.  It also forwards delegate invocations to the original delegate set on the capture control, thus acting as a proxy.
 
 If you are interested in handling any of the delegate methods on the capture control, it is important that you set your delegate before initializing the capture experience.  Setting a new delegate after initializing the capture experience will break the association with the capture control, and allow the capture experience to be shut down and deallocated if no other references to the object remain.  This is the proper protocol for cleaning up a capture experience you are no longer interested in.
 
 The selfie capture experience will add several overlays and subviews on top of the associated image capture control for visual guidance and feedback.  It will also manage some of the capture control's native properties, which could interfere with any properties you directly modify on the control.
 
 @param captureControl An instance of a kfxKUIImageCaptureControl object and cameraType set to kfxKUIFrontCamera to avoid unkonwn results.
 @param criteria A collection of constraints and attributes that control the behavior of the capture experience. Pass nil for the default experience.
 */

- (id)initWithCaptureControl:(kfxKUIImageCaptureControl*)captureControl criteria:(KFXSelfieCaptureExperienceCriteriaHolder*)criteria;

/// Document capture criteria
/**
 A collection of constraints and attributes that control the behavior of the capture experience. Pass nil to use default configuration.
 */

@property (nonatomic) KFXSelfieCaptureExperienceCriteriaHolder *criteriaHolder;


/// An instructional text box that is displayed to the user while trying to capture a selfie.
/**
 This instruction will be displayed during periods where other guidance is not available to correct a user. This may happen in particular when the user is holding a device far away from a user, preventing automated detection from recognizing the selfie.
 
 The following kfxKUICaptureMessage properties are not supported for this message:
 - messageIcons
 - backGround
 
 Default configuration:
 - message: "Center face"
 - font: HelveticaNeue with size 14. If text can't be fit in the message box tail truncation will be used.
 - text color: white
 - backGroundColor: black with 0.7 alpha component
 - position: Top
 - size: width is equal to the capture control width and height is 25 points
 - orientation: potrait
 
 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* userInstruction;

/// An instructional text box that is displayed to the user while trying to capture a selfie.
/**
 This instruction will be displayed during periods where other guidance is not available to correct a user. This may happen in particular when crieteria got matched.
 
 The following kfxKUICaptureMessage properties are not supported for this message:
 - messageIcons
 - backGround
 
 Default configuration:
 - message: "Blink now"
 - font: HelveticaNeue with size 14. If text can't be fit in the message box tail truncation will be used.
 - text color: white
 - backGroundColor: black with 0.7 alpha component
 - position: Top
 - size: width is equal to the capture control width and height is 25 points
 - orientation: potrait
 
 @see kfxKUICaptureMessage
 */

@property (nonatomic, strong) kfxKUICaptureMessage* eyesBlinkInstruction;

/// An instructional balloon that is displayed to the user for when seflie is successfully captured.
/**
 This message will be displayed when selfie is captured.
 
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

/// frame color.
/**
 Specifies the color that will be used for the guidance frame.
 
 Note: The  frame color immediately turns to red/green based on detection settings..
 */
@property (nonatomic, strong) UIColor* frameColor;

/// Outer viewfinder color.
/**
 Specifies the color that will be used for the outer viewfinder background.
 
 The default color is white.
 */
@property (nonatomic, strong) UIColor* outerViewfinderColor;

/// Whether to start vibration when an image is captured.
/**
 A boolean to turn on/off vibration when an image is captured for haptic feedback.
 
 By default is YES.
 */
@property (nonatomic) BOOL vibrationEnabled;


@end
