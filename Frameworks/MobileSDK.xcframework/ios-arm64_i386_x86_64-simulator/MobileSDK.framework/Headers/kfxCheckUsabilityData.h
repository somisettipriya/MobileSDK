//
//  API Reference
//  kfxCheckUsabilityData.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <UIKit/UIKit.h>

@class kfxDataField;

//! This object represents check usability data.
/**
 Contains the IQA data assosiated with extracted check data.
 */
@interface kfxCheckUsabilityData : NSObject

/// Car usability.
/**
 This property contains the car. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* CAR;

/// Lar usability.
/**
 This property contains the lar. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* LAR;

/// Signature usability.
/**
 This property contains the signature. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* signature;

/// Payee name usability.
/**
 This property contains the payee name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* payeeName;

/// Date usability.
/**
 This property contains the date. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* date;

/// Codeline usability.
/**
 This property contains the codeline. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* codeline;

/// Payee endorsement usability.
/**
 This property contains the payee endorsement. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* payeeEndorsement;

@end
