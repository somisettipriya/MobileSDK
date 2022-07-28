//
//  kfxKUTCustomAcquireVolumeLicenseRequestData.h
//  kfxLibUtilities
//
//  Created by Kofax on 01/05/19.
//  Copyright © 2019 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^CompletionHandler)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error);

@interface kfxKUTCustomAcquireVolumeLicenseRequestData : NSObject

//! Has the request dictionary that the app developer would get from SDK
/**
 This object would have the request that SDK passes back, user can add their own customisation to this and send it to their servers.
 */
@property(nonatomic,readonly) NSDictionary* _Nonnull request;

//! Completion Handler that an application should call after receiving a response from a licensing sever.
/**
 This object should be called by the user. The SDK would then take this response and use it for parsing and updating the licence count.
 */

@property(nonatomic,readonly) CompletionHandler _Nonnull completionHandler;

- (instancetype _Nonnull )initWithRequest:(NSDictionary* _Nonnull)request CompletionHandler:(CompletionHandler _Nonnull )completionHandler;

@end


