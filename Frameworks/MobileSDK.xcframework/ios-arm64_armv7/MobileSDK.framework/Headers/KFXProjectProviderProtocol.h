//
//  ProjectProviderProtocol.h
//  kfxLibEngines
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#ifndef KFXPROJECTPROVIDERPROTOCOL
#define KFXPROJECTPROVIDERPROTOCOL 1

#import <Foundation/Foundation.h>

//! Project Provider protocol
/**
 Specifies the protocol required to satisfy extraction dependencies.
 */
@protocol KFXProjectProviderProtocol<NSObject>

//! Get latest data version
/**
 Get the highest version string that is compatible with the given SDK version.
 
 @param projectName - The name of the project. This parameter is no longer used and will be ignored.
 @param sdkVersion - SDK version.
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - version: latest data version. May be nil in case of an error.
 - error: contains an error if there is one.
 @deprecated Deprecated in SDK 3.5. Replaced by {@link #getHighestVersion:completionHandler:}
 */
- (void)getHighestVersion:(NSString*)projectName sdkVersion:(NSString*)sdkVersion completionHandler:(void(^)(NSString* version, NSError* error))completionHandler;

//! Get latest data version
/**
 Get the highest version string that is compatible with the given SDK version.
 
 @param sdkVersion - SDK version.
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - version: latest data version. May be nil in case of an error.
 - error: contains an error if there is one.
 */
- (void)getHighestVersion:(NSString*)sdkVersion completionHandler:(void(^)(NSString* version, NSError* error))completionHandler;

//! Get project data
/**
 Get path to the project data for the given version.
 
 @param projectName - The name of the project. This parameter is no longer used and will be ignored.
 @param version - version.
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - path: path to project data. May be nil in case of an error.
 - error: contains an error if there is one.
 @deprecated Deprecated in SDK 3.5. Replaced by {@link #getProject:completionHandler:}
 */
- (void)getProject:(NSString*)projectName version:(NSString*)version completionHandler:(void(^)(NSString* path, NSError* error))completionHandler;

//! Get project data
/**
 Get path to the project data for the given version.
 
 @param version - version.
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - path: path to project data. May be nil in case of an error.
 - error: contains an error if there is one.
 */
- (void)getProject:(NSString*)version completionHandler:(void(^)(NSString* path, NSError* error))completionHandler;

//! Get variant data
/**
 Get path to the variant data for the given version.
 
 @param variant - variant name.
 @param projectName - The name of the project. This parameter is no longer used and will be ignored.
 @param version - version.
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - path: path to variant data. May be nil in case of an error.
 - error: contains an error if there is one.
 @deprecated Deprecated in SDK 3.5. Replaced by {@link #getVariant:version:completionHandler:}
 */
- (void)getVariant:(NSString*)variant forProject:(NSString*)projectName version:(NSString*)version completionHandler:(void(^)(NSString* path, NSError* error))completionHandler;

//! Get variant data
/**
 Get path to the variant data for the given version.
 
 @param variant - variant name.
 @param version - version.
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - path: path to variant data. May be nil in case of an error.
 - error: contains an error if there is one.
 */
- (void)getVariant:(NSString*)variant version:(NSString*)version completionHandler:(void(^)(NSString* path, NSError* error))completionHandler;

//! Get latest cached model data build information
/**
 Use this method to get the latest cached model data build information.
 
 @param projectName - The name of the project. This parameter is no longer used and will be ignored.
 @return cached model data build information for project. Will be nil if model data build inforation was not found.
 @deprecated Deprecated in SDK 3.5. Replaced by {@link #getLatestCachedModelDataInfo}
 */
- (NSString*)getLatestCachedModelDataInfo:(NSString*)projectName;

//! Get latest cached model data build information
/**
 Use this method to get the latest cached model data build information.
 
 @return cached model data build information for project. Will be nil if model data build inforation was not found.
 */
- (NSString*)getLatestCachedModelDataInfo;


@end

#endif
