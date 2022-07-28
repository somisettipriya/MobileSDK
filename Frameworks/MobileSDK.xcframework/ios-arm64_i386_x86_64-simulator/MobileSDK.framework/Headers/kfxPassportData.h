//
//  API Reference
//  kfxPassportData.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureData.h>

@class kfxDataField;

//! This object represents passport data.
/**
 Contains the information extracted from passport image.
 
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support extraction. Thus only parent class kfxCaptureData data will be provided. @endif
 */
@interface kfxPassportData : kfxCaptureData

/// First name.
/**
 This property contains the person's first name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* firstName;

/// Middle name.
/**
 This property contains the person's middle name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* middleName;

/// Last name.
/**
 This property contains the person's last name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* lastName;

/// Birth date.
/**
 This property contains the person's birth date. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* dateOfBirth;

/// Gender.
/**
 This property contains the person's gender. When automatically populated, the value string is "M" or "F". The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* gender;

/// ID issue date.
/**
 This property contains the ID issue date. When automatically populated, the value string has yyyy-mm-dd format. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* issueDate;

/// ID expiration date.
/**
 This property contains the ID expiration date. When automatically populated, the value string has yyyy-mm-dd format. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* expirationDate;

/// Passport number.
/**
 This property contains the passport number. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* passportNumber;

/// Country short name.
/**
 This property contains the short country name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* country;

/// Country full name.
/**
 This property contains the full country name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* countryLong;

/// Nationality.
/**
 This property contains the person's nationality. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* nationality;

/// Personal number.
/**
 This property contains the personal number. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* personalNumber;

/// Machine readable zone 1.
/**
 This property contains the MRZ1. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* MRZ1;

/// Machine readable zone 2.
/**
 This property contains the MRZ2. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* MRZ2;

/// Raw data
/**
 This property contains raw JSON string with response from extraction server.
 */
@property (nonatomic, strong) NSString* rawData;

@end
