//
//  API Reference
//  kfxKUTLicensing.h
//  Framework: kfxLibUtilities
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKUTCertificateValidatorDelegate.h"
#import "kfxKUTCustomAcquireVolumeLicenseRequestData.h"

#define KUT_MINIMUM_LICENSE_LENGTH      20

typedef enum {
    LIC_IMAGE_PROCESSING = 0,
    LIC_IMAGE_CAPTURE = 1,
    LIC_BARCODE_CAPTURE = 2,
    /// @cond EXTRACTION
    LIC_LOGISTICS = 3,                 //not used but to keep the same index as in Android
    LIC_ON_DEVICE_EXTRACTION = 4,
    /// @endcond
} kfxKUTLicenseFeature;

/// @cond EXTRACTION

typedef enum {
    SERVER_TYPE_RTTI,
    SERVER_TYPE_TOTALAGILITY
} kfxKUTLicenseServerType;

//! This protocol must be implemented by classes whose objects are used as kfxKUTLicensing delegates
/**
 This defines protocol messages that will be sent to kfxKUTLicensing delegate
 objects.
 */

@protocol kfxKUTAcquireVolumeLicenseDelegate<NSObject>

@optional
// ===================================================
//! acquireVolumeLicenseDone delegate
/**
 The SDK calls this method when acquire volume licenses process is completed.\n
 This is an optional delegate. \n
 @param licAcquired : number of license acquired.
 @param error : Any error occurred during the volume licenses aquiring process.
 
 The SDK will return number of license acquired if no error happens during the process. otherwise it will return a NSError
 - KMC_LO_SERVER_URL_NOT_SET if the application has not set any server url
 - KMC_UT_LICENSE_UNKNOWN_LICENSE_SERVER_TYPE if the server type set by the application is neither SERVER_TYPE_RTTI nor SERVER_TYPE_TOTALAGILITY
 - Any other NSError that occurs during communication with the license server
 */
- (void)acquireVolumeLicenseDone:(int) licAcquired error: (NSError*) error;

@end

@protocol kfxKUTCustomAcquireVolumeLicenseDelegate<NSObject>

@required
// ===================================================
//! customAcquireVolumeLicenseDone delegate
/**
 This method is called after @Link{acquireVolumeLicenseDone} is triggered.\n
 This is an optional delegate. \n
 @param data : Contains the request that should be sent to a licensing server,  and the completion handler that should be called with the response.
 @see kfxKUTCustomAcquireVolumeLicenseRequestData
 */
- (void)customAcquireVolumeLicenseWithData:(kfxKUTCustomAcquireVolumeLicenseRequestData*)data;

@end


/// @endcond

//! License for unlocking library features
/**
 An instance of this class contains the properties and methods you must use to set the usage license.  Once you set your usage license, you can use included properties to determine the license end date.  Once you set the license, other library API methods work as designed.  The license remains valid while the app is still running.\n\n
 Classes that contain licensed methods will include a description that highlights that it is a license protected class. Certain methods in that object are protected by this license mechanism. If you attempt to use the instance methods without setting the license, then you will receive the KMC_IP_LICENSE_INVALID error code in most cases. Refer to the method descriptions within the class to determine what methods are license protected. You use the setMobileSDKLicense method on the kfxKUTLicensing object to set the license.\n\n 
 Examples of licensed classes include kfxKEDImage and kfxKENImageProcessor.\n\n
 */
@interface kfxKUTLicensing : NSObject

///@cond EXTRACTION

@property (nonatomic, weak) id <kfxKUTAcquireVolumeLicenseDelegate> delegate;

//! The custom acquire licenses delegate.
/**
 The delegate receives the request from SDK and would have the compeltion handler that user should call for sending the response back.
 For adding your own custom server to fetch licenses, the user must set this delegate. And while setting this
 licenseServerUrl in the below api call is optional and serverType is mandatory
 -(void)setMobileSDKLicenseServer: (NSString*) licenseServerUrl type:(kfxKUTLicenseServerType) serverType
 
 @see kfxKUTCustomAcquireVolumeLicenseDelegate
 */
@property (nonatomic, weak) id <kfxKUTCustomAcquireVolumeLicenseDelegate> customAcquireVolumeLicenseDelegate;

// ===================================================
//! The certificate validator delegate.
/**
 The delegate receives certificate validation challenge in response to an authentication request from the remote server.

 @see kfxKUTCertificateValidatorDelegate
 */
@property (nonatomic, weak) id <kfxKUTCertificateValidatorDelegate> certificateValidatorDelegate;
///@endcond

// ===================================================
//! Indicates the number of days before the license expires
/**
 After you set the license, this field indicates how many days are left in your license. The library initializes this value to 0.
 */
@property (readonly) int daysRemaining;

// ===================================================
//! Sets the SDK usage license
/**
 The input to this method is the VRS license string.  If the license string is valid and days remain in the license, this method returns KMC_SUCCESS, and sets the daysRemaining property to the number of days remaining in the license. If the license string is valid but no days remain in the license, this method returns KMC_IP_LICENSE_EXPIRED. If the license string is not valid, this method returns KMC_IP_LICENSE_INVALID. Any failure to set the license sets the daysRemaining property to zero.\n

 @param license is the valid license string that was contained in a distributed header file that you received from Kofax.
 @return
 This method returns an error code if the license string is invalid, or KMC_SUCCESS if the license was setup correctly.  The error codes include:\n
 - KMC_IP_LICENSE_INVALID if the license string used is nil.\n
 - EVRS_IP_LICENSING_FAILURE if the license string is invalid for setting a license.\n
 - EVRS_IP_LICENSE_EXPIRATION_ERROR if the time limit of your license has expired.\n
 \n\n
 Example code follows showing how to set your license.

 @code
 #import <kfxLibUtilities/kfxUtilities.h>
 #import "kfxEVRS_License.h"                 // the file Kofax distributes

 NSString * myTestLicense = nil;
 myLicense = [[kfxKUTLicensing alloc] init]; // create the licensing object
 myTestLicense = [NSString stringWithFormat: @"%s",PROCESS_PAGE_SDK_LICENSE]; // get the license from the distributed license.h file
 error = [self.myLicense setMobileSDKLicense:myTestLicense];                  // set the license
 if (error != KMC_SUCCESS)
 {
    NSString *msg = [kfxError findErrMsg: error];
    NSString *desc = [kfxError findErrDesc:error];
    NSLog(@"License error: %@\n%@",msg,desc);
    NSLog(@"License INVALID");
    NSLog(@"Days remain: %d",[myLicense daysRemaining]);
 }
 else
 {
    NSLog(@"License valid");
    NSLog(@"Days remain: %d",[myLicense daysRemaining]);
 }
 @endcode
 */
- (int) setMobileSDKLicense: (NSString*) license;

// ===================================================
//! Checks if the SDK has been licensed for a specific feature.
/**
 Some license keys may only unlock a subset of features within the SDK.  This method is for checking whether a particular feature is available after a license has been successfully applied.  If a valid license hasn't been set, this method will return KMC_EV_LICENSING for all features.  If a license has been set that is not feature-restricted, this method will return KMC_SUCCESS for all features.
 
 @param feature The feature being tested.
 @return KMC_SUCCESS if the feature is licensed, or KMC_EV_LICENSING if the feature is unlicensed or an internal error has occured.
 */
+ (int) isSdkLicensed : (kfxKUTLicenseFeature)feature;

///@cond EXTRACTION
// ===================================================
//! Set up the SDK license server
/**
The function is used to setup the url string of license server used for on device operation licensing. Application must call this function before any on device operation that requires license. 
 
 @param licenseServerUrl should be a valid url string of the on device operation licensing server.
 @param serverType  should be one of the server type from the kfxKUTLicenseServerType enum.
 \n\n
 Example code follows showing how to set your license server.
 
 @code
 #import <kfxLibUtilities/kfxUtilities.h>
 
 NSString * myTestLicenseServer = nil;
 myLicense = [[kfxKUTLicensing alloc] init]; // create the licensing object
 myTestLicenseServer = [NSString stringWithFormat: @"%s","http://licenseserver.example.com"];
 [self.myLicense setMobileSDKLicenseServer:myTestLicenseServer type:SERVER_TYPE_RTTI];                  // set the license server
 myLicense.delegate = self; 
 @endcode
 */

- (void) setMobileSDKLicenseServer: (NSString*) licenseServerUrl type:(kfxKUTLicenseServerType) serverType;

// ===================================================
//! Preallocate volume licenses for offline operation
/**
 The function is used to preallocate volume licenses for offline operation.
 
 @param licenseType Volume license type.
 @param count   Number of volume license requested.
 \n\n
 Example code follows showing how to preallocate volume licenses for offlince operation.
 
 @code
 #import <kfxLibUtilities/kfxUtilities.h>
 
 NSString * myTestLicenseServer = nil;
 myLicense = [[kfxKUTLicensing alloc] init]; // create the licensing object
 myTestLicenseServer = [NSString stringWithFormat: @"%s","http://licenseserver.example.com"];
 [self.myLicense setMobileSDKLicenseServer:myTestLicenseServer type:SERVER_TYPE_RTTI];                  //set the license server
 [self.myLicense acqureVolumeLicenses:LIC_ON_DEVICE_EXTRACTION withCount:20       //preallocate 20 volume licenses
 @endcode
 */
- (void) acquireVolumeLicenses: (kfxKUTLicenseFeature) licenseType withCount: (int) count;

// ===================================================
//! Get remaining license count
/**
 The function will return available license count for the offline operation
 
 @param licType Volume license type to check.
 @return this method returns count of volume license acquired.
 \n\n
 Example code follows showing how to get remaining license count.
 
 @code
 #import <kfxLibUtilities/kfxUtilities.h>
 
 NSString * myTestLicenseServer = nil;
 myLicense = [[kfxKUTLicensing alloc] init]; // create the licensing object
 myTestLicenseServer = [NSString stringWithFormat: @"%s","http://licenseserver.example.com"];
 [self.myLicense setMobileSDKLicenseServer:myTestLicenseServer type:SERVER_TYPE_RTTI];                  //set the license server
 [self.myLicense acqureVolumeLicenses:LIC_ON_DEVICE_EXTRACTION withCount:20];     //preallocate 20 volume licenses
 NSLog(@"Remain licenses %d", [self getRemainlingLicenseCount:LIC_ON_DEVICE_EXTRACTION]);
 @endcode
 */
- (int)  getRemainingLicenseCount: (kfxKUTLicenseFeature) licType;
///@endcond
@end
