//
//  KFXServerProjectProvider.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#ifndef KFXSERVERPROJECTPROVIDER
#define KFXSERVERPROJECTPROVIDER 1

#import <Foundation/Foundation.h>
#import "KFXProjectProviderProtocol.h"

@protocol KFXBundleCacheProviderProtocol;
@protocol kfxKUTCertificateValidatorDelegate;

extern NSString* const KFXInternalServerErrorKey;

//! Server Project Provider
/**
 A reference implementation of KFXProjectProviderProtocol that downloads assets from a Kofax Quick Updater service instance.
 
 Project and variant data are first looked in the cache. If the specified version is found, the cached data will be returned without reaching the server.
 
 If internal server error message is present, it will be accessible from callback error's userInfo via KFXInternalServerErrorKey.
 E.g. NSString* internalErrorMessage = error.userInfo[KFXInternalServerErrorKey];
 
 Default cunstructor ([KFXServerProjectProvider new] or [[KFXServerProjectProvider alloc] init]) returns nil.
 
 @see KFXProjectProviderProtocol
 */
@interface KFXServerProjectProvider : NSObject <KFXProjectProviderProtocol>

//! Certificate validator delegate
/**
 Sets a custom handler for SSL certificate validation. The delegate handles certificate validation challenges in response to an authentication request from the Kofax Quick Updater instance.
 
 @see kfxKUTCertificateValidatorDelegate
 */
@property (nonatomic, weak) id <kfxKUTCertificateValidatorDelegate> certificateValidatorDelegate;

//! Constructor
/**
 Initializes the object with serverl URL and default cache provider, which is KFXBundleCacheProvider with default cache directory.
 
 @param serverUrl - The Kofax Quick Updater instance URL. If nil, nil object will be returned.
 
 @see KFXBundleCacheProvider
 */
- (instancetype)initWithURL:(NSURL*)serverUrl;

//! Constructor
/**
 Initializes the object with server URL and custom cache provider.
 
 @param serverUrl - The Kofax Quick Updater instance URL. If nil, nil object will be returned.
 @param cacheProvider - cache provider instance that conforms to KFXBundleCacheProviderProtocol. If nil, nil object will be returned.
 
 @see KFXBundleCacheProviderProtocol
 */
- (instancetype)initWithURL:(NSURL*)serverUrl cacheProvider:(id<KFXBundleCacheProviderProtocol>)cacheProvider;

//! Load all variants
/**
 This method downloads all variants for the given project.
 It checks the lastest available version on server. If the latest server and cached version are the same, it will go through variant list and download only missing variants.
 
 @param projectName - project name.
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
    - error: contains an error if there is one.
 */
- (void)loadAllVariantsForProject:(NSString*)projectName completionHandler:(void(^)(NSError* error))completionHandler;

//! Cancel load all variants
/**
 This method cancels loadAllVariants for all projects. Already downloaded data will not be deleted.
 
 Note that cancel is not an immediate operation. When cancel is complete, completionHandler of the loadAllVariantsForProject:completionHandler: will be fired with KMC_EX_OPERATION_CANCEL_SUCCESS error.
 
 Calling loadAllVariantsForProject:completionHandler: again before receiving cancel callback for previous call is undefined behavior.
 */
- (void)cancelLoadAllVariants;

//! Set request timeout
/**
 This method allows to customize request timeout for HTTP requests.
 
 Changing the timeout value will not affect the current session, it will take effect during the next session.
 
 Default value is 10 seconds.
 
 @param requestTimeout - request timeout in seconds.
 */
- (void)setRequestTimeout:(NSTimeInterval)requestTimeout;

//! Get latest cached model data build information
/**
 Use this method to get the latest cached model data build information for the given project.
 
 @param projectName - project name.
 @return cached model data build information for project. Will be nil if model data build inforation was not found.
 */
- (NSString*)getLatestCachedModelDataInfo:(NSString*)projectName;


@end

#endif
