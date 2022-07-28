//
//  KFXPassportCaptureExperience.h
//  kfxLibUIControls
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import <kfxLibUIControls/kfxKUIDocumentBaseCaptureExperience.h>
#import <kfxLibUIControls/KFXPassportCaptureExperienceCriteriaHolder.h>

//! This class renders a visual experience on top of the capture control and returns an image depending on the criteria set by the use.
/**
 This class is responsible for rendering the enhanced visual experience on top of the capture control, and provides feedback to
 guide the user to take a clear, legible and optimally zoomed in photo of a passport.
 */
@interface KFXPassportCaptureExperience : kfxKUIDocumentBaseCaptureExperience

/// Initializes a new object using the specified parameters.
/**
 Initializes a passport capture experience and binds it to the given image capture control.  The experience class overrides the capture control delegate to provide additional behavior and guidance useful for capturing passports.  It also forwards delegate invocations to the original delegate set on the capture control, thus acting as a proxy.
 
 If you are interested in handling any of the delegate methods on the capture control, it is important that you set your delegate before initializing the capture experience.  Setting a new delegate after initializing the capture experience will break the association with the capture control, and allow the capture experience to be shut down and deallocated if no other references to the object remain.  This is the proper protocol for cleaning up a capture experience you are no longer interested in.
 
 The passport capture experience will add several overlays and subviews on top of the associated image capture control for visual guidance and feedback.  It will also manage some of the capture control's native properties, which could interfere with any properties you directly modify on the control.
 
 For best results, your image capture control should be configured to use video capture mode.  This will normally result in a larger preview resolution being used.  Small preview resolutions will make passport detection difficult and negatively impact user guidance.  In particular, the capture experience will rarely be able to deliver zoom-related guidance with low resolution preview images.
 
 @param captureControl An instance of a kfxKUIImageCaptureControl object.
 @param criteria A collection of constraints and attributes that control the behavior of the capture experience. Pass nil for the default experience.
 */
- (instancetype)initWithCaptureControl:(kfxKUIImageCaptureControl*)captureControl criteria:(KFXPassportCaptureExperienceCriteriaHolder*)criteria;

/// Passport capture criteria
/**
 A collection of constraints and attributes that control the behavior of the capture experience. Pass nil to use default configuration.
 */
@property (nonatomic, strong) KFXPassportCaptureExperienceCriteriaHolder* passportCriteria;

/// An instructional text box that is displayed to the user while trying to capture a passport.
/**
 This instruction will be displayed during periods where other guidance is not available to correct a user. This may happen in particular when the user is holding a device far away from a passport, preventing automated detection from recognizing the passport.
 
 The following kfxKUICaptureMessage properties are not supported for this message:
 - messageIcons
 - backGround
 
 Default configuration:
 - message: "Fill viewable area with passport"
 - font: HelveticaNeue with size 25. If text can't be fit in the message box tail truncation will be used.
 - text color: white
 - backGroundColor: clear
 - position: centered inside viewfinder
 - size: width is equal to the viewfinder width and height is 100 points
 - orientation: landscape left
 
 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* userInstruction;

/// An instructional balloon that is displayed to the user for center the passport.
/**
 This instruction will be displayed when assport is not enough centered in the target frame for capture.
 
 Default configuration:
 - message: "Center Passport"
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
 
 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* centerMessage;

/// A tutorial image showing how to capture a passport.
/**
 A UIImage that will be displayed over the passport frame area when the tutorialEnabled field is set to YES. The set image will be stretched to fill the entire passport frame area.
 
 By default initialized with sample_passport.png from uiimages.bundle.
 */
@property (nonatomic, strong) UIImage* tutorialSampleImage;

@end
