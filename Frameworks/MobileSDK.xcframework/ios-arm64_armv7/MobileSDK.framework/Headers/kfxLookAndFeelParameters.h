//
//  API Reference
//  kfxLookAndFeelParameters.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>

//! An enumeration containing the possible torch mode values.
/**
 Use one of the values of this enumeration to set the torch mode of a capture control.
 */
typedef NS_ENUM (NSInteger, kfxTorchMode)
{
    kfxTorchMode_Off,
    kfxTorchMode_On,
    kfxTorchMode_Auto
};

//! The look and feel parameters class.
/**
 The parameters object allows the user to customize visual look and feel for capture view controller.
 The behavior and default values for some parameters could vary across capture view controllers, and details are specified in target document capture view controller parameters class.
 
 @see kfxIParameters
 */
@interface kfxLookAndFeelParameters : NSObject <NSCopying>

/// A boolean value that determines whether gallery button is enabled.
/**
 The gallery button launches the native photo gallery to select a photo of the document, instead of capturing it with a camera.
 Specify YES to make the gallery button enabled; otherwise, specify NO to make it disabled.
 The default value is NO. If the enabled state is NO, the gallery button is hidden.
 */
@property (nonatomic, assign) BOOL galleryEnabled;

/// A boolean value that determines whether force capture button is enabled.
/**
 The Force capture button allows the user to manually capture a photo of the document.
 Specify YES to make the force capture button enabled; otherwise, specify NO to make it disabled.
 The default value is YES. If the enabled state is YES capture button is visible depending on manualCaptureTimer timeout.
 
 @see manualCaptureTimer
 */
@property (nonatomic, assign) BOOL forceCaptureEnabled;

/// The number of seconds to show force capture button after presenting capture controller.
/**
 If manualCaptureTimer is less than or equal to 0.0 and forceCaptureEnabled state is YES, the force capture button will be shown immediately after presenting capture controller.
 The default value is 10 seconds. If the forceCaptureEnabled state is NO, the value has no affect.
 
 @see forceCaptureEnabled
 */
@property (nonatomic, assign) NSTimeInterval manualCaptureTimer;

/// A boolean value that determines whether exit button is enabled.
/**
 The Exit button allows the user to close capture view controller and cancel current operation.
 Specify YES to make the exit button enabled; otherwise, specify NO to make it disabled.
 The default value is YES. If the enabled state is NO, the exit button is hidden.
 */
@property (nonatomic, assign) BOOL exitEnabled;

/// A torch mode value that determines camera torch behavior.
/**
 The supported modes are:
 kfxTorchMode_Off:  Torch is turned off and torch button is visible.
 kfxTorchMode_On:  Torch is turned on and torch button is visible.
 kfxTorchMode_Auto:  Torch will turn on automatically based on curent lighting. Torch button is hidden.

 The default value is kfxTorchMode_Auto.
 
 @see kfxTorchMode
 */
@property (nonatomic, assign) kfxTorchMode torch;

/// A boolean value that determines whether to show captured image review flow.
/**
 This flow allows to user visually review the captured photo of the document by choose accept or retake action.
 The default value is NO, which mean there is no captured image review flow.
 */
@property (nonatomic, assign) BOOL reviewCapturedImageEnabled;

/// A boolean value that determines whether to show processed image review flow.
/**
 This flow allows to user visually review the processed image by choose accept or retake action.
 The default value is NO, which mean there is no processed image review flow.
 */
@property (nonatomic, assign) BOOL reviewProcessedImageEnabled;

@end
