//
//  KFXCaptureServerProtocol.h
//  kfxLibLogistics
//
//  Copyright (c) 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//
//

#import "kfxKLOUserProfile.h"
#import "kfxKLODocument.h"
#import "kfxKLODocumentType.h"
#import <Foundation/Foundation.h>

//! Capture Server protocol
/**
 Specifies the protocol required to implement the server operations.
 */
@protocol KFXCaptureServerProtocol<NSObject>

// ========================================================================================================
//! Register your mobile device with the server.
/**
 Use the registerDevice method to check if this device has access to a valid server license.  The method returns KMC_SUCCESS if the registration has done without any error.\n\n  If the Require Authentication for Registration setting is enabled on the KFS or KTA server, then the following response code is returned after  register method\n KMC_LO_REGISTER_REQUIRES_AUTH.  Therefore the recommended procedure is to call register method and if successful then login method.\n  If register method returns KMC_LO_REGISTER_REQUIRES_AUTH then call login method and then call register method again\n
 
 @see login:completionHandler:
 @see registerDevice:
 
 Sample code
 
 @code
 KFXCaptureServer* server = [[KFXCaptureServer alloc]initWithType:KLO_SERVER_KFS URL:@"URL"];
 [server registerDevice:^(int responseCode, NSError* error)
 {
    if (responseCode == KMC_LO_REGISTER_REQUIRES_AUTH)
    {
        //Login
        //register again
    }
    else
    {
        //Login
    }
 }];
 @endcode

 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - responseCode: response code which is coming from the server.
 - error: contains an error if there is one.

 The library returns KMC_SUCCESS response code, or one of the following response codes if the register device failed.\n
 - KMC_IP_LICENSE_INVALID, if you have not set the license through the Utilities library.\n
 - KMC_LO_SERVER_URL_NOT_SET, if you forgot to set the URL in the server object.\n
 - KMC_LO_SERVER_CONNECTION, if the library could not connect to the server.\n
 - KMC_LO_SECURE_CONNECTION_UNAVAILABLE, if the SSL connection specified in the URL could not be achieved.\n
 - KMC_LO_REQUEST_TIMEOUT, if the web services request timed out.  Currently the timeout is fixed at 20 seconds.\n
 - KMC_LO_NETWORK_NOT_REACHABLE, if you lost WiFi or network connectivity, or you have Airplane mode set on your device.\n
 - KMC_LO_NETWORK_AUTHENTICATION, if an internal request couldn't be authenticated (rare communication error).\n
 - KMC_LO_SERVER_CONNECTION, a Network error: Could not create a network connection or data transfer error, usually caused by a bad URL or services path.\n
 - KMC_LO_NETWORK_HOST_UNAVAILABLE, A Network error: The Host is not available, such as when the server URL is bogus or garbage.\n
*/

-(void)registerDevice:(void(^)(int responseCode,NSError* error))completionHandler;


// ========================================================================================================
//! Log into the server.
/**
 Use the asynchronous login method to log into the server.  This method uses the user userProfile parameter that contains the username and password in order to log into the server.  You must create or manage a user profile object and supply it with this method.Subsequent results of this asynchronous operation are reported in completion handler.\n
 You may need to re-register your device on some servers after a period of inactivity.\n

 @param userProfile references the kfxKLOUserProfile object that contains the credentials needed to log into the server.\n
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - responseCode: response code which is coming from server.
 - documentTypeNames: contains list of document type names if user logged into server successfully otherwise it would be nil.
 - error: contains an error if there is one.

 The library returns KMC_SUCCESS response code if user logged in successfully or one of these response codes.  If user logged in successfully then you will receive list of document type names in the completion handler.\n
 - KMC_IP_LICENSE_INVALID, if you have not set the license through the Utilities library.\n
 - KMC_LO_SERVER_URL_NOT_SET, if the server URL is invalid.\n
 - KMC_LO_USERNAME_NOT_SET, if the user name or password is invalid.\n
 - KMC_LO_DOMAIN, if the domain string in nil.\n
 - KMC_LO_EMAIL, if the email is invalid when the server type indicates that it is required.\n
 - KMC_LO_SERVER_CONNECTION, if the library could not connect to the server.\n
 - KMC_LO_SECURE_CONNECTION_UNAVAILABLE, if the SSL connection specified in the URL could not be achieved.\n
 - KMC_LO_REQUEST_TIMEOUT, if the web services request timed out.  Currently the timeout is fixed at 20 seconds.\n
 - KMC_LO_NETWORK_NOT_REACHABLE, if you lost WiFi or network connectivity, or you have Airplane mode set on your device.\n
 - KMC_LO_NETWORK_AUTHENTICATION, if an internal request couldn't be authenticated (rare communication error).\n
 - KMC_LO_SERVER_CONNECTION, a Network error: Could not create a network connection or data transfer error, usually caused by a bad URL or services path.\n
 - KMC_LO_NETWORK_HOST_UNAVAILABLE, A Network error: The Host is not available, such as when the server URL is bogus or garbage.\n

*/
-(void)login:(kfxKLOUserProfile*)userProfile completionHandler:(void(^)(int responseCode,NSArray* documentTypeNames,NSError* error))completionHandler;


// ========================================================================================================
//! Fetches the device profile shortcuts from the server.
/**
 Use the asynchronous loginAnonymously method to fetch the device profile shortcuts.Subsequent results of this asynchronous operation are reported in completion handler.\n
 You may need to re-register your device on some servers after a period of inactivity.\n

 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - responseCode: response code which is coming from server.
 - documentTypeNames: contains list of document type names if device profile shortcuts fetced from server successfully otherwise it would be nil.
 - error: contains an error if there is one.

 The library returns KMC_SUCCESS if the fetching of device profile shortcuts started successfully or one of these error codes.  If it started without error, you will receive a sessionChanged delegate when the fetching starts and completes.\n
 - KMC_IP_LICENSE_INVALID, if you have not set the license through the Utilities library.\n
 - KMC_LO_SERVER_URL_NOT_SET, if the server URL is invalid.\n
 - KMC_LO_SERVER_CONNECTION, if the library could not connect to the server.\n
 - KMC_LO_SECURE_CONNECTION_UNAVAILABLE, if the SSL connection specified in the URL could not be achieved.\n
 - KMC_LO_REQUEST_TIMEOUT, if the web services request timed out.  Currently the timeout is fixed at 20 seconds.\n
 - KMC_LO_NETWORK_NOT_REACHABLE, if you lost WiFi or network connectivity, or you have Airplane mode set on your device.\n
 - KMC_LO_NETWORK_AUTHENTICATION, if an internal request couldn't be authenticated (rare communication error).\n
 - KMC_LO_SERVER_CONNECTION, a Network error: Could not create a network connection or data transfer error, usually caused by a bad URL or services path.\n
 - KMC_LO_NETWORK_HOST_UNAVAILABLE, A Network error: The Host is not available, such as when the server URL is bogus or garbage.\n

*/
-(void)loginAnonymously:(void(^)(int responseCode,NSArray* documentTypeNames,NSError* error))completionHandler;


// ========================================================================================================
//! Get a DocumentType Object
/**

 This is an asynchronous operation to get the fields associated with this document type, as well as the image processing operations to perform on images associated with this document type.\n\n

 Use the getDocumentType method to send off a request to communicate with the server in order to create a kfxKLODocumentType object, by using the given documentTypeName parameter.\n
 Subsequent results of this asynchronous operation are reported in completion handler. you will receive kfxKLODocumentType object in completionHandler.From this document type object, you can create a kfxKLODocument object.\n\n
 Once you get the document type object, you will find the array of field types that indicate the data items associated with this document type.  You will later fill in actual document fields with run-time data obtained from your app and your app user.  Fields are data items that are changeable in the document object, and these data items are sent to the server with the images during a document submission.\n

 @param documentTypeName references the document type name string, which was obtained from an element in the document type names array returned when user logged into server successfully or fetched the device profile shortcuts from the server successfully.\n\n
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - responseCode: response code which is coming from server.
 - documentTypeObject: contains the kfxKLODocumentType object if document type object downloaded from server successfully otherwise it would be nil .
 - error: contains an error if there is one.

 @see login:completionHandler:
 @see loginAnonymously:

 The library returns one of these typical response codes:\n\n

 - KMC_SUCCESS if the document type object downloaded from server successfully.\n
 - KMC_LO_INVALID_DOCUMENT_TYPE_NAME, if the documentTypeName parameter is not a name from the list of document types associated with this server and user name.\n
 - KMC_LO_SERVER_CONNECTION, if the library could not connect to the server.\n
 - KMC_LO_SECURE_CONNECTION_UNAVAILABLE, if the SSL connection specified in the URL could not be achieved.\n
 - KMC_LO_REQUEST_TIMEOUT, if the web services request timed out.  Currently the timeout is fixed at 20 seconds.\n
 - KMC_LO_NETWORK_NOT_REACHABLE, if you lost WiFi or network connectivity, or you have Airplane mode set on your device.\n
 - KMC_LO_NETWORK_AUTHENTICATION, if an internal request couldn't be authenticated (rare communication error).\n
 - KMC_LO_SERVER_CONNECTION, a Network error: Could not create a network connection or data transfer error, usually caused by a bad URL or services path.\n
 - KMC_LO_NETWORK_HOST_UNAVAILABLE, A Network error: The Host is not available, such as when the server URL is bogus or garbage.\n

*/
-(void)getDocumentType:(NSString*) documentTypeName completionHandler:(void(^)(int responseCode,kfxKLODocumentType* documentTypeObject,NSError* error))completionHandler;


// ========================================================================================================
//! Submit a Document to the server
/**

 Use the submit document method to submit a kfxKLODocument object to the server to which you already established a connection using login. You can only submit a document after you have previously registered with the server and logged in.Subsequent results of this asynchronous operation are reported in completion handler.\n

 The method also checks the document to see if it is composed of pages with valid images.  It also checks if all images in the document are represented by a file, because images that only contain a bitmap (or none at all) cannot be submitted.  If the document has anything invalid within it, the library immediately returns an error.\n

 @param document refers to the kfxKLODocument object containing pages and fields that you want to submit.\n
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - responseCode: response code which is coming from server.
 - error: contains an error if there is one.
 @param progressHandler - callback will be fired when submission is going on. If nil no work will be done.
 - progress: it contains how much percentage of submission has done.
 - submissionJobId: job id of the submission operation
 - error: contains an error if there is one.

 The library returns KMC_SUCCESS, or one of the following errors when you call submitDocument if submission has failed:\n
 - KMC_IP_LICENSE_INVALID, if you have not yet set a valid license.\n
 - KMC_LO_SUBMIT_DOCUMENT_NO_IMAGE_ERROR, if the document parameter is nil, or if no pages exist, or if one or more pages have no images.\n
 - KMC_LO_PAGE_IMAGE_INDEX_INVALID, if the current index in a page does not reference an existing image within that page.\n
 - KMC_LO_SUBMIT_DOCUMENT_IMAGE_REP_ERROR, if the image representation of an image associated with a page is incorrect for submitting, like a bitmap representation or an empty image object. Images must be of a FILE representation to be submitted.\n
 - KMC_LO_SUBMIT_DOCUMENT_MIMETYPE_ERROR, if an image object of a page in the document has an invalid mimetype specified.\n
 - KMC_LO_SUBMIT_PNG, if an image object in a page contains a PNG image.  You can only submit TIFF and JPG images.\n
*/
-(void)submitDocument:(kfxKLODocument*)document completionHandler:(void(^)(int responseCode,NSError* error))completionHandler progressHandler:(void(^)(int progress,NSString* submissionJobId,NSError* error))progressHandler;


// ========================================================================================================
//! Cancel current operation.
/**

 Use this method to attempt to cancel a submission operation already in progress. The submit may or may not be cancellable at the time you asynchronously call this method during an on-going operation.\n
 The library detects and cancels an outstanding submission on document page boundaries, therefore there may be a delay between calling cancel and the submit actually completing.  This cancel operation will result in submit document completion handler, and the error with response code  KMC_LO_OPERATION_CANCELLED is returned if the operation was cancelled before it normally completes.  Otherwise, you will receive a normal completion status.\n

 @param submissionJobId - job ID of the submission operation already in progress.

 @return
 This method will return one of these response codes:
 - KMC_SUCCESS, if the cancel operation has started successfully.\n
 - KMC_IP_LICENSE_INVALID, if you have not yet set a valid license.\n
 - KMC_LO_NO_OPERATION_TO_CANCEL, if there is no operation in progress that can be cancelled.\n
 */
-(int)cancelSubmission:(NSString*)submissionJobId;


// ========================================================================================================
//! Logout from the server.
/**
 Use the logout method to log out of the server currently used for the current session.  The logout method is only valid if you have previously called server login.

 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - responseCode: response code which is coming from server.
 - error: contains an error if there is one.

 The library returns one of these response codes.
 - KMC_SUCCESS if user logged out successfully.\n
 - KMC_IP_LICENSE_INVALID if no license set.\n
 */
-(void)logout:(void(^)(int responseCode,NSError* error))completionHandler;

// ========================================================================================================
//! Initiate the submission process of a document to the server
/**
 Use the start job service method to start the submission process of images to the server to which you already established a connection. You can start job service after you have previously registered with the server and logged in.Subsequent results of this asynchronous operation are reported in completion handler.\n

 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - jobID: it represents the jobID which is coming from server after successfully initiated the submission process
 - responseCode: response code which is coming from server.
 - error: contains an error if there is one.

 The library returns KMC_SUCCESS, or one of the following errors when you call startJobService if submission process has not initiated:\n
 - KMC_IP_LICENSE_INVALID, if you have not yet set a valid license.\n
 */
-(void)startJobService:(void(^)(NSString* jobID, int responseCode,NSError* error))completionHandler;

// ========================================================================================================
//! Send an image to the server
/**

 Use send image service method to send the single image to the server to which you already established a connection. We have to send the order of the image and specify the image is last image in the document.Subsequent results of this asynchronous operation are reported in completion handler.\n
 After initiating the submission process only we have to call send image service because after initiating submission process we will get the job ID. With invalid job ID we can't send the image to the server.

 The method also checks the image is valid or not.  It also checks image has represented by a file, because images that only contain a bitmap (or none at all) cannot be submitted.  If the image is invalid, the library immediately returns an error.\n

 @param document refers to the kfxKLODocument object containing pages and fields that you want to submit.\n
 @param image refers to an image that you want to send to the server
 @param jobID job id which is coming when submission process has started.
 @param index refers to the index of an image in the document
 @param isLastImage represents the image is last image in the document or not
 @param completionHandler - callback will be fired on completion. If nil no work will be done.
 - responseCode: response code which is coming from server.
 - error: contains an error if there is one.

 The library returns KMC_SUCCESS, or one of the following errors when you call sendImageService if sending has failed:\n
 - KMC_IP_LICENSE_INVALID, if you have not yet set a valid license.\n
 - KMC_LO_SUBMIT_DOCUMENT_IMAGE_REP_ERROR, if the image representation of an image associated with a page is incorrect for submitting, like a bitmap representation or an empty image object. Images must be of a FILE representation to be submitted.\n
 - KMC_LO_SUBMIT_DOCUMENT_MIMETYPE_ERROR, if an image object of a page in the document has an invalid mimetype specified.\n
 - KMC_LO_SUBMIT_PNG, if an image object in a page contains a PNG image.  You can only submit TIFF and JPG images.\n
 */
-(void)sendImageService:(kfxKLODocument*)document image:(kfxKEDImage*)image jobID:(NSString*) jobID imageIndex:(int) index lastImage: (BOOL) isLastImage completionHandler:(void(^)(int responseCode,NSError* error))completionHandler;

@end
