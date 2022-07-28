//
//  API Reference
//  kfxBillCaptureViewController.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureViewController.h>

@class kfxBillData;
@class kfxBillCaptureParameters;
@class kfxBillCaptureViewController;

//! This protocol defines methods that your delegate object should implement to interact with kfxBillCaptureViewController.
/**
 The methods of this protocol notify your delegate with various messages related to bill capture.

 @see kfxCaptureViewControllerDelegate
 */
@protocol kfxBillCaptureViewControllerDelegate<kfxCaptureViewControllerDelegate>

@optional
//! Tells the delegate that the bill capture is finished and result data is available.
/**
 The methods gets called once when bill capture has finished and provides the bill data depending on the specified parameters.
 Your delegate's implementation of this method should dismiss the bill capture view controller.
 
 Implementation of this method is optional, but expected.
 
 @param billCaptureViewController  The bill capture view controller dispatching the message.
 @param bill  The result bill data. Could be a nil if error is occured.
 @param error  An NSError object that describes the problem if an internal error occurs. In the case of a server extraction failure, the error's userInfo property will contain a "kfxInternalServerErrorInfo" field with the response from the server.
 
 @see kfxBillData
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support data extraction. @endif
 */
- (void)billCaptureViewController:(kfxBillCaptureViewController*)billCaptureViewController didExtractBill:(kfxBillData*)bill error:(NSError*)error;

@end

//! Bill capture view controller.
/**
 The kfxBillCaptureViewController class creates a controller object that allows the user to capture a photo of the bill, and optionally process the captured image and extract the data.
 
 Before presenting kfxBillCaptureViewController you must specify the parameters and delegate objects.
 
 @see kfxCaptureViewController
 @see kfxBillCaptureParameters
 @see kfxBillCaptureViewControllerDelegate
  @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support data extraction. @endif
 */
@interface kfxBillCaptureViewController : kfxCaptureViewController

/// The parameters of the bill capture view controller object.
/**
 Bill capture parameters object allows the user to customize various aspects of kfxBillCaptureViewController behavior including visual look and feel, processing and extraction functonality.
 Updating parameters object is not eligible after kfxBillCaptureViewController was presented into the screen.
 
 @see kfxBillCaptureParameters
 */
@property (nonatomic, copy) kfxBillCaptureParameters* parameters;

/// The delegate of the bill capture view controller object.
/**
 The delegate receives notifications when bill capture finishes or closes.

 @see kfxBillCaptureViewControllerDelegate
 */
@property (nonatomic, weak) id<kfxBillCaptureViewControllerDelegate> delegate;

@end
