//
//  kfxKOEImageField.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2018 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import "kfxKOEField.h"

@class kfxKOEDataField;
@class kfxKEDImage;

//! Image Field object
/**
 Image field object represents an image associated with document fields.
 */
@interface kfxKOEImageField : kfxKOEField

/// An image that represents the extracted field.
/**
 Default value is nil.
 */
@property (nonatomic, strong) kfxKEDImage* value;

//! Constructor
/**
 Initializes the object from a kfxKOEDataField
 
 @param field - kfxKOEDataField to initialize with.
 @param croppedImage - the resulting field value will be cropped from this image.
 
 @see kfxKOEDataField
 */
- (instancetype)initWithDataField:(kfxKOEDataField*)field croppedImage:(kfxKEDImage*)croppedImage;

@end
