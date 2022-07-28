//
//  KFXMRZResult.h
//  kfxLibEngines
//
//  Created by SIVASANKAR YATHIRAJULA on 20/07/20.
//  Copyright © 2020 Mark Day. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface KFXMRZResult : NSObject

/// A string value.
/**
 * The value contains mrz raw data which is available on the document.
 */

@property (nonatomic, strong) NSString* mrz;

/// A string value.
/**
 * The value contains document code.
 */

@property (nonatomic, strong) NSString* documentCode;

/// A string value.
/**
 * The value contains issuing state code of the document.
 */

@property (nonatomic, strong) NSString* issuingStateCode;

/// A string value.
/**
 * The value contains document number of the document..
 */

@property (nonatomic, strong) NSString* documentNumber;

/// A string value.
/**
 * This value contains personal number of the document..
 */

@property (nonatomic, strong) NSString* personalNumber;

/// A string value.
/**
 * The value contains gender information.
 */

@property (nonatomic, strong) NSString* gender;

/// A string value.
/**
 * The value contains given name.
 */

@property (nonatomic, strong) NSString* givenNames;

/// A string value.
/**
 * This value contains sur name.
 */

@property (nonatomic, strong) NSString* surname;

/// A string value.
/**
 * The value contains nationality code.
 */

@property (nonatomic, strong) NSString* nationalityCode;

/// A string value.
/**
 * The value contains the date of birth which is in "YYMMDD" format.
 */
@property (nonatomic, strong) NSString* dateOfBirth;

/// A string value.
/**
 * The value contains the date of expiration of the document which is in "YYMMDD" format.
 */

@property (nonatomic, strong) NSString* dateOfExpiry;

@end

