//
//  API Reference
//  kfxKUILogging.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

//! kfxLibUIControls libarary logging features
/**
 A kfxKUILogging singleton provides functionality to control kfxLibUIControls library logging.
 */
@interface kfxKUILogging : NSObject

//! Enables kfxLibUIControls library console logging
/**
 Pass YES to turn on library logging, and NO otherwise. Disabled by default.
 */
+ (void)enableConsoleLogging:(BOOL)enable;

@end
