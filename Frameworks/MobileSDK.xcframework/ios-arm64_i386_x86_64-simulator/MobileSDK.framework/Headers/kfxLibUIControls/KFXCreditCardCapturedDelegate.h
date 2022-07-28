//
//  KFXCreditCardCapturedDelegate.h
//  kfxLibUIControls
//
//  Copyright (c) 2014 - 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KFXCreditCard.h"

//! Defines the delegate methods for Credit Card capture.
/**
 This protocol defines delegate methods a calling view controller can implement to receive asynchronous notifications of successful extraction, or failure, of a credit card.\n
 */
@protocol KFXCreditCardCapturedDelegate<NSObject>

@required

// ! Notification of extraction failure
/**
 * This is called if the card fails to extract.  
  \param[in] failureReason An error code.  Call [kfxError findErrMsg:failureReason] to get a displayable error message.
 */
- (void) cardExtractionFailed : (int) failureReason;

// ! Notification of extraction success
/**
 * This is called when extraction succeeds.
 \param[in] image For embossed cards, this will be nil. For future use with non-embossed cards, this will be a kfxKEDImage of the captured card.
 \param[in] creditCardData The returned data from extraction.
 */
- (void) cardExtracted : (id) image andCreditCard : (KFXCreditCard *) creditCardData;

@optional
// ! Notification of image captured for custom extraction of non-embossed cards
/**
 * This is reserved for future use with non-embossed cards, if ExtractionServerUrl of the KFXCreditCardCaptureView is empty.
 \param[in] image For future use with non-embossed cards, this will be a kfxKEDImage of the captured card.
 */
- (void) cardCaptured : (id) image;

@end
