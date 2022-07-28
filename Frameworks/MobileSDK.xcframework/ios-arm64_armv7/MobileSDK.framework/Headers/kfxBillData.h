//
//  API Reference
//  kfxBillData.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureData.h>

@class kfxDataField;

//! This object represents bill data.
/**
 Contains the information extracted from bill image.
 
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support extraction. Thus only parent class kfxCaptureData data will be provided. @endif
 */
@interface kfxBillData : kfxCaptureData

/// Bill amount.
/**
 This property contains the amount. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* amount;

/// Bill due date.
/**
 This property contains the due date. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* dueDate;

/// Bill name.
/**
 This property contains the name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* name;

/// Bill address line1.
/**
 This property contains the address line1. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* addressLine1;

/// Bill address line2.
/**
 This property contains the address line2. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* addressLine2;

/// Bill city.
/**
 This property contains the city. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* city;

/// Bill state.
/**
 This property contains the state. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* state;

/// Bill zip.
/**
 This property contains the zip. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* zip;

/// Bill account number.
/**
 This property contains the account number. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* accountNumber;

/// Bill phone number.
/**
 This property contains the phone number. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* phoneNumber;

/// Bill source.
/**
 This property contains the source. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* source;

/// Bill billers.
/**
 This property contains the billers. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* billers;

/// Raw data
/**
 This property contains the raw JSON string with response from extraction server.
 */
@property (nonatomic, strong) NSString* rawData;

@end
