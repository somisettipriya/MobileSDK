//
//  KFXCaptureServer.h
//  kfxLibLogistics
//
//  Created by Rambabu N on 7/5/16.
//  Copyright (c) 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//
//

#import <Foundation/Foundation.h>
#import "KFXCaptureServerProtocol.h"
#import "kfxKUTCertificateValidatorDelegate.h"

//! The Capture server Class
/**
 Framework: libLogistics
 Import suggestion: #import <kfxLibLogistics/kfxLogistics.h>
 Relevant Header File: KFXCaptureServer.h
 An instance of this class contains methods to interact with the server.

 **Initialization**
 Default constructor ([KFXCaptureServer new] or [[KFXCaptureServer alloc] init]) returns nil.

 [[KFXCaptureServer alloc] initWithType:KLO_SERVER_KFS URL:@"http://ip/KFS/axis2/services/"] - capture server will be initialized with provided url and type.

 **Licensing**

 Server communication requires a valid license to be set.

 @see kfxKUTLicensing
 @see KFXCaptureServerProtocol
 */
@interface KFXCaptureServer : NSObject <KFXCaptureServerProtocol>


//! Constructor for KTA or KFS
/**
 This constructor allows to specify KFS or KTA.

 @param serverType - type of the server.
 @param serverURL - url of the server that you want to do operations on

 */
-(id)initWithType: (KLOsourceServer ) serverType URL: (NSString*) serverURL;


//! Use this property to specify the timeout of server SOAP requests.
/**
 Timeout defaults to 20 seconds.  Can be overridden to any number of seconds to specify how long SOAP calls should be allowed to take before returning a timeout error.\n
 Note that providing an invalid value (such as 0 or any negative number) will reset the timeout to the default value.\n

 @code
 KFXCaptureServer *serverObject = [[KFXCaptureServer alloc]initWithType:KLO_SERVER_KFS URL:@"http://ip/KFS/axis2/services/"];
 serverObject.serverTimeout = 120;
 @endcode
 */
@property int serverTimeout;

/// The certificate validator delegate.
/**
 The delegate receives certificate validation challenge in response to an authentication request from the remote server.

 @see kfxKUTCertificateValidatorDelegate
 */
@property (nonatomic, weak) id<kfxKUTCertificateValidatorDelegate> certificateValidatorDelegate;


@end
