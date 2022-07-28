//
//  KFXLocalBundleProjectProvider.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#ifndef KFXLOCALBUNDLEPROJECTPROVIDER
#define KFXLOCALBUNDLEPROJECTPROVIDER 1

#import <Foundation/Foundation.h>
#import "KFXProjectProviderProtocol.h"

@protocol KFXBundleCacheProviderProtocol;

//! Local Bundle Project Provider
/**
 This implementation of KFXProjectProviderProtocol allows to get assets from zip bundles stored in application resources.
 By default it uses KFXBundleCacheProvider instance with default cache directory and main bundle root location for bundles.
 
 Project zip bundles are expected to be named as %project_name%.zip (e.g. USIDs.zip).
 
 @see KFXProjectProviderProtocol
 @see KFXBundleCacheProvider
 */
@interface KFXLocalBundleProjectProvider : NSObject <KFXProjectProviderProtocol>

//! Constructor
/**
 Initializes the object with a custom cache provider instance.
 
 @param cacheProvider - custom cache provider instance. If nil, nil object will be returned.

 @see KFXBundleCacheProviderProtocol
 */
- (instancetype)initWithCacheProvider:(id<KFXBundleCacheProviderProtocol>)cacheProvider;

//! Constructor
/**
 Initializes the object with a custom path to folder containing project zip bundles.
 
 @param path - path to folder. If nil, nil object will be returned.
 */
- (instancetype)initWithPath:(NSString*)path;

//! Constructor
/**
 Initializes the object with custom path to folder containing project zip bundles and cache provider instance.
 
 @param path - path to folder. If nil, nil object will be returned.
 @param cacheProvider - custom cache provider instance. If nil, nil object will be returned.

 @see KFXBundleCacheProviderProtocol
 */
- (instancetype)initWithPath:(NSString*)path cacheProvider:(id<KFXBundleCacheProviderProtocol>)cacheProvider;


//! Get latest cached model data build information
/**
 Use this method to get the latest cached model data build information for the given project.
 
 @param projectName - project name.
 @return cached model data build information for project. Will be nil if model data build inforation was not found.
 */
- (NSString*)getLatestCachedModelDataInfo:(NSString*)projectName;


@end

#endif
