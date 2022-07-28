//
//  kfxKOEDataField.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2018 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import "kfxKOEField.h"

//! Data Field object
/**
 Data field object represents data associated with document fields.
 */
@interface kfxKOEDataField : kfxKOEField

/// A string value with field value.
/**
 Default value is empty NSString.
 */
@property (nonatomic, strong) NSString* value;

@end
