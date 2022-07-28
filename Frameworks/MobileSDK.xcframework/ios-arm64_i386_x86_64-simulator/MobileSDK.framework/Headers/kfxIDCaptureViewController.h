//
//  API Reference
//  kfxIDCaptureViewController.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureViewController.h>

@class kfxIDData;
@class kfxIDCaptureParameters;
@class kfxIDCaptureViewController;

//! This protocol defines methods that your delegate object should implement to interact with kfxIDCaptureViewController.
/**
 The methods of this protocol notify your delegate with various messages related to ID capture.
 
 @see kfxCaptureViewControllerDelegate
 */
@protocol kfxIDCaptureViewControllerDelegate<kfxCaptureViewControllerDelegate>

@optional
//! Tells the delegate that the ID capture is finished and result data is available.
/**
 The methods gets called once when ID capture has finished and provides the ID data depending on the specified parameters.
 Your delegate's implementation of this method should dismiss the ID capture view controller.
 
 Implementation of this method is optional, but expected.
 
 ID original image should be saved before the other side capture, otherwise it will be deleted from the image storage.
 
 @param idCaptureViewController  The ID capture view controller dispatching the message.
 @param idData  The result ID data. Could be a nil if error is occured.
 @param error  An NSError object that describes the problem if an internal error occurs. In the case of a server extraction failure, the error's userInfo property will contain a "kfxInternalServerErrorInfo" field with the response from the server.
 
 @see kfxIDData
 
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support data extraction. @endif
 */
- (void)idCaptureViewController:(kfxIDCaptureViewController*)idCaptureViewController didExtractID:(kfxIDData*)idData error:(NSError*)error;

@end

//! ID capture view controller.
/**
 The kfxIDCaptureViewController class creates a controller object that allows the user to capture a photo of the ID, and optionally process the captured image and extract the data.
 
 Before presenting kfxIDCaptureViewController you must specify the parameters and delegate objects.
 
 @see kfxCaptureViewController
 @see kfxIDCaptureParameters
 @see kfxIDCaptureViewControllerDelegate
 
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support data extraction. @endif
 */
@interface kfxIDCaptureViewController : kfxCaptureViewController

/// The parameters of the ID capture view controller object.
/**
 ID capture parameters object allows the user to customize various aspects of kfxIDCaptureViewController behavior including visual look and feel, processing and extraction functonality.
 Updating parameters object is not eligible after kfxIDCaptureViewController was presented into the screen.
 
 @see kfxIDCaptureParameters
 */
@property (nonatomic, copy) kfxIDCaptureParameters* parameters;

/// The delegate of the ID capture view controller object.
/**
 The delegate receives notifications when ID capture finishes or closes.

 @see kfxIDCaptureViewControllerDelegate
 */
@property (nonatomic, weak) id<kfxIDCaptureViewControllerDelegate> delegate;

@end
