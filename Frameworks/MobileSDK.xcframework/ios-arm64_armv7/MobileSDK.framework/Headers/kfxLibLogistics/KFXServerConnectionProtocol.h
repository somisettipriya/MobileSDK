//
//  KFXServerConnectionProtocol.h
//  kfxLibLogistics
//
//  Copyright (c) 2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
@protocol kfxKUTCertificateValidatorDelegate;

@protocol KFXServerConnectionProtocol<NSObject>


@required

//! Certificate validator delegate
/**
 This property allows to set a custom handler for SSL certificate validation.

 @see kfxKUTCertificateValidatorDelegate
 */
@property(nonatomic,strong) id <kfxKUTCertificateValidatorDelegate> certificateValidatorDelegate;

//! Get the necessary server request
/**
 Get the request in proper format necessary for the server to carry out extraction
 
 @param parameters - parameters needed for extraction like xregion, processimage etc (see server documentation)
 @param imageBytesArray - image data objects in NSData format for each image
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - request: valid request to send to the server
 - error: contains an error if there is one.
 */


-(void)getRequest:(NSDictionary*)parameters images: (NSArray*)imageBytesArray completion:(void (^)(NSURLRequest* request,NSError* error))completionHandler;


//! Connect to the server
/**
 make a connection to the sever using the request formed
 
 @param request - request formed earlier which has all the parameters and image data required on server
  @param completionHandler - callback will be fired on completion.
 - extractionData: data received from the server It could be JSON or XML based on the server's response
 - error: contains an error if there is one.
 */
-(void)makeConnection : (NSURLRequest*)request completion : (void (^)(NSData* extractionData,NSURLResponse *response,NSError* error))completionHandler;


//! Cancel connection to the server
/**
 cancels the extraction task.
 
 @param completionHandler - callback will be fired on completion.
 
 - error: contains an error if there is one.
 */
-(void)cancelConnection :(void (^)(NSError* error))completionHandler;

@end
