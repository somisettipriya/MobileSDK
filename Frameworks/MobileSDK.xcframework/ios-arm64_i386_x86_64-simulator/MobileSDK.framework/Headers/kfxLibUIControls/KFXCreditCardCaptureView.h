//
//  KFXCreditCardCaptureView.h
//  kfxLibUIControls
//
//  Copyright (c) 2014 - 2017 Kofax. All rights reserved.
//

#import "KFXCreditCardCapturedDelegate.h"
#import "KFXCreditCard.h"

typedef NS_ENUM(NSUInteger, KFXCardStyle)
{
    KFXCreditCardNumberStyleEmbossed = 1,
    KFXCreditCardNumberStyleFlat
};

@interface KFXCreditCardCaptureView : UIView

// ! Card Number Style.
/**
 * This property identifies whether a card is either embossed or non-embossed (flat). Setting this property initiates the capture process.
 * Currently non-embossed cards are not supported. This property exists for future compatibility
 */
@property (nonatomic) KFXCardStyle CardNumberStyle;

// ! Extraction Server URL.
/**
 * This property identifies the URL to be used in extracting the card number of a flat or non-embossed card. If this property is nil, the card will be captured and an image returned to the application. In that case, extraction is the responsibility of the application.
 * Extraction from web URL is not supported currently. This property exists for future compatibility
 */

@property (nonatomic, strong) NSString *ExtractionServerUrl;

// ! Extra time for expiry date scan
/**
 * Once the card number has been successfully identified, allow a bit more time to figure out the expiry.
 * The default value is 1 second.
 */
@property (nonatomic, assign) NSTimeInterval extraTimeForExpiry;

// ! Delegate the CreditCardCapturedDelegate protocol.
/**
 * This property is set to identify the delegate to be called for the methods in this protocol.
 */
@property (nonatomic, weak) id<KFXCreditCardCapturedDelegate> delegate;

// ! cancelCreditCardCapture
/**
 * This method cancels an active credit card capture.
 */
- (void) cancelCreditCardCapture;

//! This message initializes the view and must be sent before it is used.
/**
 This message initializes the view for use and must be sent to the class before it is used.
 It is ok to send the message more than once. 
 */
+ (void) initializeView;

@end
