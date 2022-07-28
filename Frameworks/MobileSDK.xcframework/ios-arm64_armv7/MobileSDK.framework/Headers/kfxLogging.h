//
//  API Reference
//  kfxLogging.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

//! MobileSDK libarary logging features
/**
 A kfxLogging singleton provides functionality to control MobileSDK library logging.
 */
@interface kfxLogging : NSObject

//! Enables MobileSDK library console logging
/**
 Pass YES to turn on library logging, and NO otherwise. Disabled by default.
 */
+ (void)enableConsoleLogging:(BOOL)enable;

@end
