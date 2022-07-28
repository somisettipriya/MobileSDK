//
//  API Reference
//  kfxCheckCaptureViewController.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureViewController.h>

@class kfxCheckData;
@class kfxCheckCaptureParameters;
@class kfxCheckCaptureViewController;

//! This protocol defines methods that your delegate object should implement to interact with kfxCheckCaptureViewController.
/**
 The methods of this protocol notify your delegate with various messages related to check capture.

 @see kfxCaptureViewControllerDelegate
 */
@protocol kfxCheckCaptureViewControllerDelegate<kfxCaptureViewControllerDelegate>

@optional
//! Tells the delegate that the check capture is finished and result data is available.
/**
 The methods get called once when check capture has finished and provides the check data depending on the specified parameters.
 Your delegate's implementation of this method should dismiss the check capture view controller.
 
 Implementation of this method is optional, but expected.
 
 The check's original image should be saved before the other side is captured, otherwise it will be deleted from the image storage.
 
 @param checkCaptureViewController  The check capture view controller dispatching the message.
 @param check  The result check data. Could be a nil if error is occured.
 @param error  An NSError object that describes the problem if an internal error occurs. In the case of a server extraction failure, the error's userInfo property will contain a "kfxInternalServerErrorInfo" field with the response from the server.
 
 @see kfxCheckData
  @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support data extraction. @endif
 */
- (void)checkCaptureViewController:(kfxCheckCaptureViewController*)checkCaptureViewController didExtractCheck:(kfxCheckData*)check error:(NSError*)error;

@end

//! Check capture view controller.
/**
 The kfxCheckCaptureViewController class creates a controller object that allows the user to capture a photo of the check, and optionally process the captured image and extract the data.
 
 Before presenting kfxCheckCaptureViewController you must specify the parameters and delegate objects.
 
 @see kfxCaptureViewController
 @see kfxCheckCaptureParameters
 @see kfxCheckCaptureViewControllerDelegate
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support data extraction. @endif
 */
@interface kfxCheckCaptureViewController : kfxCaptureViewController

/// The parameters of the check capture view controller object.
/**
 Check capture parameters object allows the user to customize various aspects of kfxCheckCaptureViewController behavior including visual look and feel, processing and extraction functonality.
 Updating parameters object is not eligible after kfxCheckCaptureViewController was presented into the screen.
 
 @see kfxCheckCaptureParameters
 */
@property (nonatomic, copy) kfxCheckCaptureParameters* parameters;

/// The delegate of the check capture view controller object.
/**
 The delegate receives notifications when check capture finishes or closes.

 @see kfxCheckCaptureViewControllerDelegate
 */
@property (nonatomic, weak) id<kfxCheckCaptureViewControllerDelegate> delegate;

@end
