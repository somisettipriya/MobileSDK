//
//  kfxKUTMicrLine.h
//  kfxLibUtilities
//
//  Copyright (c) 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, KUTCheckType)
{
    CHECK_NONE = 0,
    PERSONAL_CHECK,
    BUSINESS_CHECK,
};

@interface kfxKUTMicrLine : NSObject
    //! The auxiliaryOnUs property contains the contents of the Auxiliary On-Us field in the MICR. It usually contains the check number. It is generally not present on personal checks. This property is nil if this field is not present.
    @property (nonatomic, strong) NSString* auxiliaryOnUs;

    //! The EPC property contains the contents of the External Processing Code. It is a one character field, and is usually not present in the MICR. This property is nil if the field is not present.
    @property (nonatomic, strong) NSString* EPC;

    //! This required MICR field identifies the financial institution.
    @property (nonatomic, strong) NSString* transitNumber;

    //! The onUS property. Returns all characters from the MICR from transitNumber to amount (if present), or to the right of the string if amount is not present.
    @property (nonatomic, strong) NSString* onUs;

    //! The onUS1 property contains the contents of the first portion of the On-Us field in the MICR. It generally contains the account number.
    @property (nonatomic, strong) NSString* onUs1;

    //! The onUS2 property contains the contents of the second portion of the On-Us MICR field. If present, it contains the check number. This property is nil if the field is not present.
    @property (nonatomic, strong) NSString* onUs2;

    //! The amount field contains the check amount. This is generally not present unless the check has been processed by a bank. This property is nil if the field is not present.
    @property (nonatomic, strong) NSString* amount;

    //! The checkType field contains the type of check detected. If the auxiliaryOnUs field is present, this field is set to BUSINESS_CHECK. Otherwise, this field is set to PERSONAL_CHECK.
    @property (nonatomic) KUTCheckType checkType;

    //! The valueSet field indicates whether any of the micrLine fields have been set. If NO, the micrLine string could not be extracted and\or parsed.
    @property (nonatomic) BOOL valueSet;

@end
