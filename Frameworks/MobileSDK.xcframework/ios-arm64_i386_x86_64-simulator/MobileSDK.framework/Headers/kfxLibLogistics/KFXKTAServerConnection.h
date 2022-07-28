//
//  KFXRTTIServerConnection.h
//  kfxLibLogistics
//
//  Copyright (c) 2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import "KFXServerConnectionProtocol.h"

//! Certificate validator delegate.
/**
 This property allows to set a custom handler for SSL certificate validation.

 @see kfxKUTCertificateValidatorDelegate
 */
@protocol kfxKUTCertificateValidatorDelegate;

//! This class helps in making the connection to the KTA Server specified in the URL
/**
 This class is responsible for constructing a request necessary to perform extraction.It can perform the login to KTA Server.It then makes a connection to the Server using the request formed earlier and returns the results.
 */
@interface KFXKTAServerConnection : NSObject <KFXServerConnectionProtocol>{
    
}


//! Set request timeout.
/**
 This method allows to customize request timeout for HTTP requests.
 
 Changing the timeout value will not affect the current session, it will take effect during the next session.
 
 Default value is 20 seconds.
 */
@property (nonatomic) NSTimeInterval requestTimeout;


/// Constructor for the connection
/**
 The constructor allows to specify the required URL on which the extraction can be performed.
 
 @param serverURL  a valid KTA server url
 
 */
-(instancetype)initWithURL : (NSURL*)serverURL;

/// Method to login to KTA Server

/**
 This method allows user to login to KTA server and retrieve the necessary parameters like jobID, sessionID so that they can be subsequently passed as parameters for extraction.
 
 
 @param parameters - the parameters needed to login. e.g. user credentials 
 @retval returns the sessionId and the response received from the server during the login request
 
 */
-(void)login:(NSDictionary *)parameters : (void (^)(NSString *sessionId, NSURLResponse *response, NSError *error))completionHandler;



@end
