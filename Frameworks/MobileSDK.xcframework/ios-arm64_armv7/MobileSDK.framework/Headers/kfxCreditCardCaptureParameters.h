//
//  API Reference
//  kfxCreditCardCaptureParameters.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxIParameters.h>

//! An enumeration containing the possible credit card styles values.
/**
 Use one of the values of this enumeration to set the credit card style.
 */
typedef NS_ENUM (NSInteger, kfxCardStyle)
{
    kfxCardStyle_Embossed,
    kfxCardStyle_Flat // Conserved for future use
};

//! The credit card capture view controller parameters.
/**
 Encapsulates all parameters related to credit card capture, processing and extraction.
 
 Current implementation does not support customization of the credit card's look and feel, processing or extraction, changing these parameters will take no effect. They are reserved for future usage.
 
 @see kfxIParameters
 */
@interface kfxCreditCardCaptureParameters : kfxIParameters <NSCopying>

/// A credit card style value that determines credit card detection functionality.
/**
 The supported modes is:
 kfxCardStyle_Embossed:  Embossed credit card numbers style.
 
 kfxCardStyle_Flat: Is not supported currently.
 
 The default value is kfxCardStyle_Embossed.
 
 @see kfxCardStyle
 */
@property (nonatomic, assign) kfxCardStyle cardStyle;

/// Extra time for expiry date scan
/**
 Once the card number has been successfully identified, allow a bit more time to figure out the expiry.
 The default value is 1 second.
 */
@property (nonatomic, assign) NSTimeInterval extraTimeForExpiry;

@end
