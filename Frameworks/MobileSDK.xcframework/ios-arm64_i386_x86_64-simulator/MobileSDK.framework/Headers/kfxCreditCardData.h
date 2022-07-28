//
//  API Reference
//  kfxCreditCardData.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureData.h>

@class kfxDataField;

//! This object represents credit card data.
/**
 Contains the information extracted from credit card image.
 */
@interface kfxCreditCardData : kfxCaptureData

// ! Cardholder name.
/**
 * This property contains the cardholder name for this CreditCard object.
 */
@property (nonatomic, strong) kfxDataField* name;

// ! Card number.
/**
 * This property contains the card number for this CreditCard object. When automatically populated, the card number is 15 or 16 digits with no spaces
 */
@property (nonatomic, strong) kfxDataField* cardNumber;

// ! Expiration month.
/**
 * This property contains the expiration month for this CreditCard object. When automatically populated, the expiration month is a two-digit string. This string is empty if expiration month extraction is unsuccessful.
 */
@property (nonatomic, strong) kfxDataField* expirationMonth;

// ! Expiration year.
/**
 * This property contains the expiration year for this CreditCard object. When automatically populated, the expiration year is a four-digit string. This string is empty if expiration year extraction is unsuccessful.
 */
@property (nonatomic, strong) kfxDataField* expirationYear;

// ! Security code.
/**
 * This property contains the security code for this CreditCard object.
 */
@property (nonatomic, strong) kfxDataField* cvv;

@end
