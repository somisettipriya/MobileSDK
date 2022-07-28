//
//  API Reference
//  kfxKLOLogging.h
//  Framework: kfxLibLogistics
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

//! kfxLibLogistics libarary logging features
/**
 A kfxKLOLogging singleton provides functionality to control kfxLibLogistics library logging.
 */
@interface kfxKLOLogging : NSObject

//! Enables kfxLibLogistics library console logging
/**
 Pass YES to turn on library logging, and NO otherwise. Disabled by default.
 */
+ (void)enableConsoleLogging:(BOOL)enable;

@end
