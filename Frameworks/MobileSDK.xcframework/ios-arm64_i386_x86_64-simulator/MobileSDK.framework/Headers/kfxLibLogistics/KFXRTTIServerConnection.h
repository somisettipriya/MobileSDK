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

//! This class helps in making the connection to the RTTI Server specified in the URL
/**
 This class is responsible for constructing a multi-part request necessary to perform extraction. It then makes a connection to the Server using the request formed earlier and returns the results.
 */
@interface KFXRTTIServerConnection : NSObject <KFXServerConnectionProtocol>


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
 
 @param serverURL  a valid RTTI server url
 
 */

-(instancetype)initWithURL : (NSURL*)serverURL;
 

@end
