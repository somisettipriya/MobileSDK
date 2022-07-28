//
//  KFXBundleCacheProvider.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#ifndef KFXBUNDLECACHEPROVIDER
#define KFXBUNDLECACHEPROVIDER 1

#import <Foundation/Foundation.h>
#import "KFXBundleCacheProviderProtocol.h"

//! Bundle Cache Provider
/**
 The KFXBundleCacheProvider handles extracting/copying entries from a bundle into a cache folder.
 Default implementation of KFXBundleCacheProviderProtocol. It stores only one version per project.

 By default, the files are stored at:
 [path_to_app]/Library/KFXExtractionAssets
 
 Cache structure is:
 [path]/[version]/[project files, variant folders].

 @see KFXBundleCacheProviderProtocol
 */
@interface KFXBundleCacheProvider : NSObject <KFXBundleCacheProviderProtocol>

//! Cache path
/**
 Path to cache root folder.
 
 Default value is [path_to_app]/Library/KFXExtractionAssets.
 */
@property (nonatomic, strong, readonly) NSString* path;

//! Constructor
/**
 Initializes the object with a custom path to the folder where cached files should be stored.
 
 @param path - path to custom cache directory.
 */
- (instancetype)initWithPath:(NSString*)path;

@end

#endif
