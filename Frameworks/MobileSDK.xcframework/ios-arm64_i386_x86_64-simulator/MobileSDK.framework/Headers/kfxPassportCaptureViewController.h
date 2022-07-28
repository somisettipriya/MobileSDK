//
//  API Reference
//  kfxPassportCaptureViewController.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureViewController.h>

@class kfxPassportData;
@class kfxPassportCaptureParameters;
@class kfxPassportCaptureViewController;

//! This protocol defines methods that your delegate object should implement to interact with kfxPassportCaptureViewController.
/**
 The methods of this protocol notify your delegate with various messages related to passport capture.

 @see kfxCaptureViewControllerDelegate
 */
@protocol kfxPassportCaptureViewControllerDelegate<kfxCaptureViewControllerDelegate>

@optional
//! Tells the delegate that the passport capture is finished and result data is available.
/**
 The methods gets called once when passport capture has finished and provides the passport data depending on the specified parameters.
 Your delegate's implementation of this method should dismiss the passport capture view controller.
 
 Implementation of this method is optional, but expected.
 
 @param passportCaptureViewController  The passport capture view controller dispatching the message.
 @param passport  The result passport data. Could be a nil if error is occured.
 @param error  An NSError object that describes the problem if an internal error occurs. In the case of a server extraction failure, the error's userInfo property will contain a "kfxInternalServerErrorInfo" field with the response from the server.
 
 @see kfxPassportData
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support data extraction. @endif
 */
- (void)passportCaptureViewController:(kfxPassportCaptureViewController*)passportCaptureViewController didExtractPassport:(kfxPassportData*)passport error:(NSError*)error;

@end

//! Passport capture view controller.
/**
 The kfxPassportCaptureViewController class creates a controller object that allows the user to capture a photo of the passport and optionally process the captured image and extract the data.
 
 Before presenting kfxPassportCaptureViewController you must specify the parameters and delegate objects.
 
 @see kfxCaptureViewController
 @see kfxPassportCaptureParameters
 @see kfxPassportCaptureViewControllerDelegate
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support data extraction. @endif
 */
@interface kfxPassportCaptureViewController : kfxCaptureViewController

/// The parameters of the passport capture view controller object.
/**
 Passport capture parameters object allows the user to customize various aspects of kfxPassportCaptureViewController behavior including visual look and feel, processing and extraction functonality.
 Updating parameters object is not eligible after kfxPassportCaptureViewController was presented into the screen.
 
 @see kfxPassportCaptureParameters
 */
@property (nonatomic, copy) kfxPassportCaptureParameters* parameters;

/// The delegate of the passport capture view controller object.
/**
 The delegate receives notifications when passport capture finishes or closes.

 @see kfxPassportCaptureViewControllerDelegate
 */
@property (nonatomic, weak) id<kfxPassportCaptureViewControllerDelegate> delegate;

@end
