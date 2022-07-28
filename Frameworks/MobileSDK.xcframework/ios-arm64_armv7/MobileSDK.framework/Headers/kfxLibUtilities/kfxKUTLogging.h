//
//  API Reference
//  kfxKUTLogging.h
//  Framework: kfxLibUtilities
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

//! kfxLibUtilities libarary logging features
/**
 A kfxKUTLogging singleton provides functionality to control kfxLibUtilities library logging.
 */
@interface kfxKUTLogging : NSObject

//! Enables kfxLibUtilities library console logging
/**
 Pass YES to turn on library logging, and NO otherwise. Disabled by default.
 */
+ (void)enableConsoleLogging:(BOOL)enable;

@end
