//
//  API Reference
//  kfxCreditCardCaptureViewController.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureViewController.h>

@class kfxCreditCardData;
@class kfxCreditCardCaptureParameters;
@class kfxCreditCardCaptureViewController;

//! This protocol defines methods that your delegate object should implement to interact with kfxCreditCardCaptureViewController.
/**
 The methods of this protocol notify your delegate with various messages related to credit card capture.

 @see kfxCaptureViewControllerDelegate
 */
@protocol kfxCreditCardCaptureViewControllerDelegate<kfxCaptureViewControllerDelegate>

@optional
//! Tells the delegate that the credit card capture is finished and result data is available.
/**
 The methods gets called once when credit card capture has finished and provides the credit card data depending on the specified parameters.
 Your delegate's implementation of this method should dismiss the credit card capture view controller.
 
 Implementation of this method is optional, but expected.
 
 @param creditCardCaptureViewController  The credit card capture view controller dispatching the message.
 @param creditCard  The result credit card data. Could be a nil if error is occured.
 @param error  If an internal error occurs, contains an NSError object that describes the problem.
 
 @see kfxCreditCardData
 */
- (void)creditCardCaptureViewController:(kfxCreditCardCaptureViewController*)creditCardCaptureViewController didExtractCreditCard:(kfxCreditCardData*)creditCard error:(NSError*)error;

@end

//! Credit card capture view controller.
/**
 The kfxCreditCardCaptureViewController class creates a controller object that allows the user to capture a photo of the credit card, and optionally process the captured image and extract the data.
 
 Before presenting kfxCreditCardCaptureViewController you must specify the parameters and delegate objects.
 
 @see kfxCaptureViewController
 @see kfxCreditCardCaptureParameters
 @see kfxCreditCardCaptureViewControllerDelegate
 */
@interface kfxCreditCardCaptureViewController : kfxCaptureViewController

/// The parameters of the credit card capture view controller object.
/**
 Credit card capture parameters object allows the user to customize various aspects of kfxCreditCardCaptureViewController behavior including visual look and feel, processing and extraction functonality.
 Updating parameters object is not eligible after kfxCreditCardCaptureViewController was presented into the screen.
 
 @see kfxCreditCardCaptureParameters
 */
@property (nonatomic, copy) kfxCreditCardCaptureParameters* parameters;

/// The delegate of the credit card capture view controller object.
/**
 The delegate receives notifications when credit card capture finishes or closes.

 @see kfxCreditCardCaptureViewControllerDelegate
 */
@property (nonatomic, weak) id<kfxCreditCardCaptureViewControllerDelegate> delegate;

@end
