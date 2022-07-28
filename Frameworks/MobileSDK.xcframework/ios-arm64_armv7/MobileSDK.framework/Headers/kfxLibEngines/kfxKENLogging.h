//
//  API Reference
//  kfxKENLogging.h
//  Framework: kfxLibEngines
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

//! kfxLibEngines libarary logging features
/**
 A kfxKENLogging singleton provides functionality to control kfxLibEngines library logging.
 */
@interface kfxKENLogging : NSObject

//! Enables kfxLibEngines library console logging
/**
 Pass YES to turn on library logging, and NO otherwise. Disabled by default.
 */
+ (void)enableConsoleLogging:(BOOL)enable;

@end
