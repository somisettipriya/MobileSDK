//
//  KFXCreditCard.h
//  kfxLibUIControls
//
//  Copyright (c) 2014 - 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KFXCreditCard : NSObject

// ! Cardholder name.
/**
 * This property contains the cardholder name for this CreditCard object.
 */
@property (nonatomic, strong) NSString *name;

// ! Card number.
/**
 * This property contains the card number for this CreditCard object. When automatically populated, the card number is 15 or 16 digits with no spaces
 */
@property (nonatomic, strong) NSString *cardNumber;

// ! Expiration month.
/**
 * This property contains the expiration month for this CreditCard object. When automatically populated, the expiration month is a two-digit string. This string is empty if expiration month extraction is unsuccessful.
 */
@property (nonatomic, strong) NSString *expirationMonth;

// ! Expiration year.
/**
 * This property contains the expiration year for this CreditCard object. When automatically populated, the expiration year is a four-digit string. This string is empty if expiration year extraction is unsuccessful.
 */
@property (nonatomic, strong) NSString *expirationYear;

// ! Security code.
/**
 * This property contains the security code for this CreditCard object.
 */
@property (nonatomic, strong) NSString *cvv;

// ! Card Network.
/**
 * This property contains the card network for this CreditCard object.
 */
@property (nonatomic, strong) NSString *cardNetwork;

@end
