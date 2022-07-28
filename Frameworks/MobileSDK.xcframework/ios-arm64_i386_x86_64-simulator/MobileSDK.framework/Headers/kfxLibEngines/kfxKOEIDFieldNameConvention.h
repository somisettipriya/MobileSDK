/// @cond NODOXYGEN
//
//  kfxKOEIDFieldNameConvention.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>

//! Field names convention object
/**
 This object allows to get field names for ID-related entities.
 
 @see kfxKOEIDExtractor
 */
@interface kfxKOEIDFieldNameConvention : NSObject

//! Address first line field name
/**
 @return address first line field name
 */
+ (NSString*)address1FieldName;

//! Address second line field name
/**
 @return address second line field name
 */
+ (NSString*)address2FieldName;

//! Address third line field name
/**
 @return address third line field name
 */
+ (NSString*)address3FieldName;

//! Address forth line field name
/**
 @return address forth line field name
 */
+ (NSString*)address4FieldName;

//! Address fifth line field name
/**
 @return address fifth line field name
 */
+ (NSString*)address5FieldName;

//! Address sixth line field name
/**
 @return address sixth line field name
 */
+ (NSString*)address6FieldName;

//! Full name field name
/**
 @return full field name
 */
+ (NSString*)fullNameFieldName;

//! First name field name
/**
 @return first field name
 */
+ (NSString*)firstNameFieldName;

//! Middle name field name
/**
 @return middle field name
 */
+ (NSString*)middleNameFieldName;

//! Last name field name
/**
 @return last field name
 */
+ (NSString*)lastNameFieldName;

//! Last name 1 field name
/**
 @return last field name 1
 */
+ (NSString*)lastName1FieldName;

//! Name suffix field name
/**
 @return name suffix field name
 */
+ (NSString*)nameSuffixFieldName;

//! City field name
/**
 @return city field name
 */
+ (NSString*)cityFieldName;

//! State field name
/**
 @return state field name
 */
+ (NSString*)stateFieldName;

//! Zip field name
/**
 @return zip field name
 */
+ (NSString*)zipFieldName;

//! Gender field name
/**
 @return gender field name
 */
+ (NSString*)genderFieldName;

//! Weight field name
/**
 @return weight field name
 */
+ (NSString*)weightFieldName;

//! Height field name
/**
 @return height field name
 */
+ (NSString*)heightFieldName;

//! Hair field name
/**
 @return hair field name
 */
+ (NSString*)hairFieldName;

//! Eyes field name
/**
 @return eyes field name
 */
+ (NSString*)eyesFieldName;

//! Id class field name
/**
 @return id class field name
 */
+ (NSString*)idClassFieldName;

//! Id number field name
/**
 @return id number field name
 */
+ (NSString*)idNumberFieldName;

//! CPF field name
/**
 @return CPF field name
 */
+ (NSString*)cpfFieldName;

//! Date of birth field name
/**
 @return date of birth field name
 */
+ (NSString*)dateOfBirthFieldName;

//! Issue date field name
/**
 @return issue date field name
 */
+ (NSString*)issueDateFieldName;

//! Expiration date field name
/**
 @return expiration date field name
 */
+ (NSString*)expirationDateFieldName;

//! Barcode field name
/**
 @return barcode field name
 */
+ (NSString*)barcodeFieldName;

//! License number field name
/**
 @return license number field name
 */
+ (NSString*)licenseNumberFieldName;

//! Id type field name
/**
 @return id type field name
 */
+ (NSString*)idTypeFieldName;

//! Street address field name
/**
 @return street address field name
 */
+ (NSString*)streetAddressFieldName;

//! Unit number field name
/**
 @return unit number field name
 */
+ (NSString*)unitNumberFieldName;

//! Country field name
/**
 @return country field name
 */
+ (NSString*)countryFieldName;

//! Country short field name
/**
 @return country short field name
 */
+ (NSString*)countryShortFieldName;

//! Is barcode read field name
/**
 @return is barcode read field name
 */
+ (NSString*)isBarcodeReadFieldName;

//! Is ocr read field name
/**
 @return is ocr read field name
 */
+ (NSString*)isOcrReadFieldName;

//! Is id verified field name
/**
 @return is id verified field name
 */
+ (NSString*)isIDVerifiedFieldName;

//! Document verification confidence rating field name
/**
 @return document verification confidence rating field name
 */
+ (NSString*)documentVerificationConfidenceRatingFieldName;

//! Nationality field name
/**
 @return nationality field name
 */
+ (NSString*)nationalityFieldName;

//! Document state field name
/**
 @return document state field name
 */
+ (NSString*)documentStateFieldName;

//! MRZ line 1
/**
 @return MRZ line 1 field name
 */
+ (NSString*)mrz1FieldName;

//! MRZ line 2
/**
 @return MRZ line 2 field name
 */
+ (NSString*)mrz2FieldName;

//! MRZ line 3
/**
 @return MRZ line 3 field name
 */
+ (NSString*)mrz3FieldName;

//! Issuing Authority
/**
 @return IssuingAuthority field name
 */

+ (NSString*)issuingAuthority;


//! Is Key Field
/**
 Indicates if the fieldName is a key field.

 @param fieldName - Name of field.
 @return YES if fieldName is a key field and NO otherwise.
 */
+ (BOOL)isKeyField:(NSString*)fieldName;

@end
///@endcond
