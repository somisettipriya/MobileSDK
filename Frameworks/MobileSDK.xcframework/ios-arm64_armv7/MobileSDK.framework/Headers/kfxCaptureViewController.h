//
//  API Reference
//  kfxCaptureViewController.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <UIKit/UIKit.h>

@protocol kfxKUTCertificateValidatorDelegate;

// kfxCertificateValidatorDelegate is deprecated. Use kfxKUTCertificateValidatorDelegate instead.
#define kfxCertificateValidatorDelegate kfxKUTCertificateValidatorDelegate

//! This is an abstract base class for capture view controller. kfxCaptureViewController provides entire capture control along with capture guidance experience, image processing and data extraction functionality. It has a single entry and exit point. The capture view controller behavior and visual look and feel are customized thru a set of parameters. Capture view controller supports the delegate protocol to provide feedback to a client, with result data and error object if applicable.
/**
 This class is responsible for rendering the enhanced visual experience along with capture control and provides feedback to
 guide the user to take a clear, legible and optimally zoomed in photo of various documents such as check, bill, ID and so on.
 It also provides optional steps for image processing and data extraction.
 
 This class and its subclasses only support Landscape Orientation for Capture, capture messages are shown in Landscape. User should lock orientation in Potrait while capture view controller is active.
 */
@interface kfxCaptureViewController : UIViewController

/// The certificate validator delegate.
/**
 The delegate receives certificate validation challenge in response to an authentication request from the remote server.

 @see kfxKUTCertificateValidatorDelegate
 */
@property (nonatomic, weak) id<kfxKUTCertificateValidatorDelegate> certificateValidatorDelegate;

@end

//! This protocol defines methods that your delegate object should implement to interact with inherited classes from kfxCaptureViewController.
/**
 The methods of this protocol notify your delegate with various messages common for capture view controllers.
 
 @see kfxCheckCaptureViewControllerDelegate
 @see kfxBillCaptureViewControllerDelegate
 @see kfxPassportCaptureViewControllerDelegate
 @see kfxCreditCardCaptureViewControllerDelegate
 @see kfxIDCaptureViewControllerDelegate
 */
@protocol kfxCaptureViewControllerDelegate<NSObject>

@optional
//! Tells the delegate that the user is going to close capture view controller.
/**
 Your delegate's implementation of this method should dismiss the capture view controller.
 
 Implementation of this method is optional, but expected.
 
 @param captureViewController  The capture view controller dispatching the message.
 */
- (void)captureViewControllerDidClose:(kfxCaptureViewController*)captureViewController;

@end
