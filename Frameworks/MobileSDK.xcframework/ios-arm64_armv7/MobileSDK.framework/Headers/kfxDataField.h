//
//  API Reference
//  kfxDataField.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <UIKit/UIKit.h>

//! Data field object
/**
 Data field object represents data associated with document fields.
 
 @see kfxCheckData
 @see kfxCheckIQAData
 @see kfxBillData
 @see kfxPassportData
 @see kfxIDData
 @see kfxCreditCardData
 */
@interface kfxDataField : NSObject

/// A string value with field name.
/**
 Default value is nil.
 */
@property (nonatomic, strong) NSString* name;

/// A string value with field value.
/**
 Default value is nil.
 */
@property (nonatomic, strong) NSString* value;

/// A float value with field confidence.
/**
 Default value is 0.
 */
@property (nonatomic, assign) CGFloat confidence;

/// A CGRect value with field location on the document image.
/**
 Default value is CGRectZero.
 */
@property (nonatomic, assign) CGRect location;

@end
