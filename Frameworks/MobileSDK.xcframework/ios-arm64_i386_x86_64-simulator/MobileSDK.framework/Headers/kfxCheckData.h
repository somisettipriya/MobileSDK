//
//  API Reference
//  kfxCheckData.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxCaptureData.h>

@class kfxDataField;
@class kfxCheckIQAData;
@class kfxCheckUsabilityData;

//! This object represents check data.
/**
 Contains the information extracted from check image.
 
@ifnot EXTRACTION @note The Atalasoft MobileImage SDK does not support extraction. Thus only parent class kfxCaptureData data will be provided. @endif
 */
@interface kfxCheckData : kfxCaptureData

/// Check MICR.
/**
 This property contains check MICR. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* MICR;

/// Check amount.
/**
 This property contains check amount. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* amount;

/// Check number.
/**
 This property contains check number. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* checkNumber;

/// Check date.
/**
 This property contains check date. When automatically populated, the value string will contain the date in the same format as presented on the check. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* date;

/// Check payee name.
/**
 This property contains check payee name. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* payeeName;

/// Check usable.
/**
 This property specifies if check is usable. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* usable;

/// Check legal amount.
/**
 This property contains check LAR. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* LAR;

/// Check courtesy amount.
/**
 This property contains check CAR. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* CAR;

/// Check transit (routing).
/**
 This property contains check transit. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* transit;

/// Check On-Us first part.
/**
 This property contains check On-Us first part. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* onUs1;

/// Check On-Us second part.
/**
 This property contains check On-Us second part. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* onUs2;

/// Check Auxiliary On-Us.
/**
 This property contains check Auxiliary On-Us. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* auxiliaryOnUs;

/// Check external processing code.
/**
 This property contains check EPC. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* EPC;

/// Check MICR amount.
/**
 This property contains check amount specified in MICR. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* MICRAmount;

/// Check restrictive endorsement.
/**
 This property contains check restrictive endorsement. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* restrictiveEndorsement;

/// Check restrictive endorsement present.
/**
 This property specifies if check restrictive endorsement is present. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* restrictiveEndorsementPresent;

/// Check reason for rejection.
/**
 This property contains reason for check rejection. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* reasonForRejection;

/// Check IQA data.
/**
 This property contains check IQA data.
 
 @see kfxCheckIQAData
 */
@property (nonatomic, strong) kfxCheckIQAData* IQA;

/// Check usability data.
/**
 This property contains check usability data.
 
 @see kfxCheckUsabilityData
 */
@property (nonatomic, strong) kfxCheckUsabilityData* usability;

/// Raw data
/**
 This property contains raw JSON string with response from extraction server.
 */
@property (nonatomic, strong) NSString* rawData;

@end
