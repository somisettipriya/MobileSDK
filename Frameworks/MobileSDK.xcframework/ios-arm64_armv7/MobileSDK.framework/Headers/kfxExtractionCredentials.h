//
//  API Reference
//  kfxExtractionCredentials.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>

//! The extraction credentials class.
/**
 The object allows to specify server credentials.
 The behavior and default values for some parameters could vary cross capture view controllers and details are specified in target document capture view controller parameters class.
 
 @see kfxExtractionParameters
 */
@interface kfxExtractionCredentials : NSObject <NSCopying>

/// A string value with user name.
/**
 Specify user name if applicable.
 The default value is nil.
 */
@property (nonatomic, copy) NSString* username;

/// A string value with password.
/**
 Specify password if applicable.
 The default value is nil.
 */
@property (nonatomic, copy) NSString* password;

/// A string value with session ID.
/**
 Specify session ID if applicable.
 The default value is nil.
 */
@property (nonatomic, copy) NSString* sessionId;

@end
