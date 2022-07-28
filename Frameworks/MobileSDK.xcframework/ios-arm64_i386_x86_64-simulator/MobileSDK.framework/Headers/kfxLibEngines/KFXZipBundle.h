//
//  KFXZipBundle.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#ifndef KFXZIPBUNDLE
#define KFXZIPBUNDLE 1

#import <Foundation/Foundation.h>
#import "KFXBundleProtocol.h"

//! Zip bundle
/**
 Represents a zip archive. Conforms to KFXBundleProtocol.
 
 @see KFXBundleProtocol
 */
@interface KFXZipBundle : NSObject <KFXBundleProtocol>

//! Constructor
/**
 Initializes object with path to zip archive.
 
 @param path - path to zip archive.
 */
- (instancetype)initWithFile:(NSString*)path;

@end

#endif
