//
//  API Reference
//  kfxKUTCertificateValidatorDelegate.h
//  Framework: kfxLibUtilities
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#ifndef KFXKUTCERTIFICATEVALIDATORDELEGATE
#define KFXKUTCERTIFICATEVALIDATORDELEGATE 1

#import <Foundation/Foundation.h>

//! This protocol defines methods that your delegate object may implement for custom certificate pinning logic.
/**
 The methods of this protocol notify your delegate with messages related to certificate validation.
 */
@protocol kfxKUTCertificateValidatorDelegate<NSObject>

@optional
//! Requests credentials from the delegate in response to an authentication request from the remote server.
/**
 This method is a wrapper around following method of NSURLSessionTaskDelegate
 - (void)URLSession:(NSURLSession *)session
 task:(NSURLSessionTask *)task
 didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
 completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition,
 NSURLCredential *credential))completionHandler
 
 Refer to an Apple Foundation Framework documentation for more details.
 
 Responding on this client may customize Certificate Pinning logic.
 
 @param session  The session containing the task whose request requires authentication.
 @param challenge  An object that contains the request for authentication.
 @param completionHandler  A handler that your delegate method must call. Its parameters are:
 - disposition  One of several constants that describes how the challenge should be handled.
 - credential  The credential that should be used for authentication if disposition is NSURLSessionAuthChallengeUseCredential; otherwise, NULL.
 
 Use NSURLSessionAuthChallengePerformDefaultHandling as disposition for default handling for the challenge as though this delegate method were not implemented. The provided credential parameter is ignored.
 
 Implementation of this method is optional, but expected for security reason.
 */
- (void)certificateValidatorForURLSession:(NSURLSession*)session
                      didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
                        completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;

@end

#endif
