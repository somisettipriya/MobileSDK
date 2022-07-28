//
//  KFXBundleCacheProviderProtocol.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#ifndef KFXBUNDLECACHEPROVIDERPROTOCOL
#define KFXBUNDLECACHEPROVIDERPROTOCOL 1

#import <Foundation/Foundation.h>

@protocol KFXBundleProtocol;

//! Bundle Cache Provider protocol
/**
 This protocol defines the methods that should be implemented by cache provider.
 */
@protocol KFXBundleCacheProviderProtocol<NSObject>

//! Get project path
/**
 Use this method to get the path to specified project files.
 
 @param projectName - project name.
 @param version - project data version.
 @return path to folder containing cached project files. Will be nil in default implementations if cached data for specified project and version was not found.
 */
- (NSString*)getProjectWithName:(NSString*)projectName version:(NSString*)version;

//! Cache project
/**
 Use this method to cache project data.
 
 @param projectName - project name.
 @param bundle - bundle object which generalize file container.
 @param version - project data version.
 @param error - error object instance which will contain error info if cache failed.
 @return path to folder containing cached project files. Will be nil in default implementations if cache failed.
 */
- (NSString*)cacheProjectWithName:(NSString*)projectName bundle:(id<KFXBundleProtocol>)bundle version:(NSString*)version error:(NSError**)error;

//! Get variant path
/**
 Use this method to get the path to specified variant files.
 
 @param variantName - variant name. This must be the full variant name that contains the Project and Category names.\n
 For example: "United States|Alabama|AL_2010".
 @param projectName - variant Solution name.
 @param version - variant data version.
 @return path to folder containing cached variant files. Will be nil in default implementations if cached data for specified variant, project and version was not found.
 */
- (NSString*)getVariantWithName:(NSString*)variantName forProject:(NSString*)projectName version:(NSString*)version;

//! Cache project
/**
 Use this method to cache variant data.
 
 @param variantName - variant name. This must be the full variant name that contains the Project and Category names.\n
 For example: "United States|Alabama|AL_2010".
 @param projectName - variant Solution name.
 @param bundle - bundle object which generalize file container.
 @param version - variant data version.
 @param error - error object instance which will contain error info if cache failed.
 @return path to folder containing cached variant files. Will be nil in default implementations if cache failed.
 */
- (NSString*)cacheVariantWithName:(NSString*)variantName forProject:(NSString*)projectName bundle:(id<KFXBundleProtocol>)bundle version:(NSString*)version error:(NSError**)error;

//! Get latest cached version
/**
 Use this method to get the latest cached version for the given project.
 
 @param projectName - project name.
 @return latest version for project. Will be nil if project data was not found.
 */
- (NSString*)latestVersionForProject:(NSString*)projectName;

//! Get latest cached model data build information
/**
 Use this method to get the latest cached model data build information for the given project.
 
 @param projectName - project name.
 @return cached model data build information for project. Will be nil if model data build inforation was not found.
 */
- (NSString*)getLatestModelDataBuildInfo:(NSString*)projectName;

@end

#endif
