//
//  API Reference
//  kfxIDData.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureData.h>

@class kfxDataField;

//! This object represents id document data.
/**
 Contains the information extracted from id image.
 
 @ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support extraction. Thus only parent class kfxCaptureData data will be provided. @endif
 */
@interface kfxIDData : kfxCaptureData

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
 This property contains the person's first name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* lastName;

/// ID number.
/**
 This property contains the id number for this this IDData object. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* idNumber;

/// Birth date.
/**
 This property contains the person's birth date. When automatically populated, the value string has yyyy-mm-dd format. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* dateOfBirth;

/// Address line.
/**
 This property contains the person's address. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* address;

/// Gender.
/**
 This property contains the person's gender. When automatically populated, the value string is "M" or "F". The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* gender;

/// Address ZIP code.
/**
 This property contains the zip code. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* zip;

/// Address state name.
/**
 This property contains the state name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* state;

/// Address city name.
/**
 This property contains the city name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* city;

/// Name suffix.
/**
 This property contains the person's name suffix. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* nameSuffix;

/// Additional address line 2.
/**
 This property contains the additional address line. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* address2;

/// Additional address line 3.
/**
 This property contains the additional address line. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* address3;

/// Additional address line 4.
/**
 This property contains the additional address line. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* address4;

/// Additional address line 5.
/**
 This property contains the additional address line. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* address5;

/// Additional address line 6.
/**
 This property contains the additional address line. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* address6;

/// Class.
/**
 This property contains the driver license class. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* idClass;

/// Country short name.
/**
 This property contains the country short identifier. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* countryShort;

/// Country full name.
/**
 This property contains the full country name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* country;

/// ID expiration date.
/**
 This property contains the ID expiration date. When automatically populated, the value string has yyyy-mm-dd format. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* expirationDate;

/// Eyes color.
/**
 This property contains the person's eyes color. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* eyes;

/// Hair color.
/**
 This property contains the person's hair color. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* hair;

/// Height.
/**
 This property contains the person's height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* height;

/// ID issue date.
/**
 This property contains the ID issue date. When automatically populated, the value string has yyyy-mm-dd format. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* issueDate;

/// Nationality.
/**
 This property contains the person's nationality. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* nationality;

/// Weight.
/**
 This property contains the person's weight. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* weight;

/// License number.
/**
 This property contains the driver license number. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* license;

/// Document state
/**
 This property contains the document state. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* documentState;

/// Document type
/**
 This property contains the document type. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* documentType;

/// isBarcodeRead value.
/**
 This property defines if the barcode has been read.
 
 Default value is false.
 */
@property (nonatomic, assign) BOOL isBarcodeRead;

/// isOcrRead value.
/**
 This property defines if the OCR has been read.
 
 Default value is false.
 */
@property (nonatomic, assign) BOOL isOcrRead;

/// isIDVerified value.
/**
 This property defines if the ID has been verified.
 
 Default value is false.
 */
@property (nonatomic, assign) BOOL isIDVerified;

/// Document verification confidence rating.
/**
 This property contains the id verification confidence rating. May take values from 0 to 100.
 
 Default value is 0.
 */
@property (nonatomic, assign) CGFloat documentVerificationConfidenceRating;

/// Identifier for the ID face image.
/**
 This property contains the identifier for ID face image. Nil if the extraction of this field is unsuccessfull.
 */
@property (nonatomic, strong) NSString* faceImageId;

/// Identifier for the ID signature image.
/**
 This property contains the identifier for ID signature image. Nil if the extraction of this field is unsuccessfull.
 */
@property (nonatomic, strong) NSString* signatureImageId;

/// Raw data
/**
 This property contains raw JSON string with response from extraction server.
 */
@property (nonatomic, strong) NSString* rawData;

/// Barcode
/**
 This property contains barcode string. Default value is nil.
 */
@property (nonatomic, strong) NSString* barcode;

@end
