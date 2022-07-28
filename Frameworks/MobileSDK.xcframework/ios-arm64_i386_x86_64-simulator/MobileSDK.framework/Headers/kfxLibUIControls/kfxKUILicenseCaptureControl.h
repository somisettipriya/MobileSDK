//
//  API Reference
//  kfxKUILicenseCaptureControl.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <UIKit/UIKit.h>

@class kfxKUILicenseCaptureControl;
@class kfxKUICaptureMessage;

//! This protocol must be implemented by classes whose objects are used as kfxKUILicenseCaptureControl delegates.
/**
 This defines protocol messages that will be sent to kfxKUILicenseCaptureControl delegate objects.
 */
@protocol kfxKUILicenseCaptureControlDelegate<NSObject>

@optional

//! A message that indicates that an SDK license was found.
/**
 This will only be sent after the control receives a readLicense message.
 Once the SDK license was found, the license string will be used for SDK licensing.
 
 @param licenseCaptureControl  The license capture controller dispatching the message.
 @param errorCode  An error code if the license string is invalid, or KMC_SUCCESS if the SDK license was setup correctly.
 The error codes include:
 - EVRS_IP_LICENSING_FAILURE if the license string is invalid for setting an SDK license.
 - EVRS_IP_LICENSE_EXPIRATION_ERROR if the time limit of your SDK license has expired.
 @param daysRemaining  Indicates how many days are left in your SDK license.
 @param license  The license string if errorCode is KMC_SUCCESS, or nil otherwise.
 */
- (void)licenseCaptureControl:(kfxKUILicenseCaptureControl*)licenseCaptureControl
                    errorCode:(int)errorCode
                daysRemaining:(int)daysRemaining
                      license:(NSString*)license;

@end

//! This class renders the camera preview to the screen and searches for an SDK license key in a QR code.
/**
 This class is responsible for rendering the camera preview and provides guidance to capture the SDK license from a QR code.
 Once the view has been asked to read an SDK license, it will search continuously until one is found.
 */
@interface kfxKUILicenseCaptureControl : UIView

//! This message initializes the control and must be sent to the class before it is used.
/**
 This message initializes the control for use and must be sent to the class before it is used.
 It is ok to send the message more than once. A common way to do this is in your UIViewController subclasses initialize or init methods.
 */
+ (void)initializeControl;

/// A delegate to receive messages from the control.
/** 
 A delegate that will be notified with found SDK license.

 @see kfxKUILicenseCaptureControlDelegate
 */
@property (nonatomic, strong) IBOutlet id<kfxKUILicenseCaptureControlDelegate> delegate;

/// The padding percent required between the viewfinder and camera preview frame.
/**
 This value determines how much percentage the viewfinder needs to be positioned inside the camera preview frame.
 Valid values are [0-50].
 
 The default value is 10.

 @see outerViewfinderColor
 */
@property (nonatomic, assign) CGFloat viewfinderPaddingPercent;

/// Outer viewfinder color.
/**
 Specifies the color that will be used for the outer viewfinder background.
 
 The default color is transparent grey.
 
 @see viewfinderPaddingPercent
 */
@property (nonatomic, strong) UIColor* outerViewfinderColor;

/// An instructional text box that is displayed to the user while trying to capture an SDK license.
/**
 The following kfxKUICaptureMessage properties are not supported for this message:
 - messageIcons
 - backGround
 
 Default configuration:
 - message: "Fill viewable area with license in QR Code format"
 - font: HelveticaNeue with size 23. If text can't be fit in the message box tail truncation will be used.
 - text color: white
 - backGroundColor: clear
 - position: centered inside viewfinder
 - size: width is equal to the viewfinder width and height is 100 points
 - orientation: portrait
 
 @see kfxKUICaptureMessage
 */
@property (nonatomic, strong) kfxKUICaptureMessage* userInstruction;

/// Reads an SDK license from the camera preview.
/**
 This call returns immediately and starts asynchronously searching for an SDK license.
 The search will continue indefinitely until an SDK license is found.
 
 Once an SDK license is positively read, the delegate will receive a
 licenseCaptureControl:errorCode:daysRemaining:license: message.
 
 If license string is valid it will be set into SDK for licensing.
 */
- (void)readLicense;

@end
