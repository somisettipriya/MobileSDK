//
//  kfxKOEField.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2018 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "kfxKEDBoundingRectangle.h"

//! Field object
/**
 Field object represents data associated with document fields.
 */
@interface kfxKOEField: NSObject

/// A string value with field name.
/**
 Default value is empty NSString.
 */
@property (nonatomic, strong) NSString* name;

/// A bounding rectangle value with field location.
/**
 Default value is kfxKEDBoundingRectangle with all coordinates set to 0.
 
 @see kfxKEDBoundingRectangle
 */
@property (nonatomic, strong) kfxKEDBoundingRectangle* rect;

/// A float value with field confidence.
/**
 * The confidence field is a continuous value in the range (0,1) that reflects an overall
 * estimate of the probability that the value is correct.
 *
 * @return The field confidence
 */
@property (nonatomic) CGFloat confidence;

@end
