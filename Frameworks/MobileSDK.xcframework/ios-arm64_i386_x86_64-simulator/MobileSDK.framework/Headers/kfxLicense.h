//
//  API Reference
//  kfxLicense.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>
@class kfxKUTCustomAcquireVolumeLicenseRequestData;
///@cond EXTRACTION

//! This protocol must be implemented by classes whose objects are used as kfxLicense delegates
/**
 This defines protocol messages that will be sent to kfxLicense delegate objects.
 */
@protocol kfxAcquireVolumeLicenseDelegate<NSObject>
@required
//! Aquire volume license completion delegate
/**
 This method will be called when license is aquired.
 */
- (void)acquireVolumeLicenseDone:(int)licAcquired error:(NSError*)error;

@end

@protocol kfxCustomAcquireVolumeLicenseDelegate<NSObject>

@required
//! This protocol must be implemented by classes who wants to use their custom servers to fetch licenses
/**
 This defines protocol messages that will be sent to kfxLicense customAcquireVolumeLicenseDelegate objects.
 */
- (void)customAcquireVolumeLicenseWithData:(kfxKUTCustomAcquireVolumeLicenseRequestData*)data;

@end
///@endcond

//! License for unlocking library features
/**
 An instance of this class contains the properties and methods you must use to set the usage license.  Once you set the license, other library API methods work as designed.  The license remains valid while the app is still running.\n\n
 You use the setMobileSDKLicense method on the kfxLicense object to set the license.\n\n
 */
@interface kfxLicense : NSObject

///@cond EXTRACTION

/// License delegate
/**
 Set the delegate to receive licesnse callbacks.
 */
@property (nonatomic, weak) id<kfxAcquireVolumeLicenseDelegate> delegate;

//! The custom acquire licenses delegate.
/**
 Set the delegate to receive custom request data that would have request and the response handlers. Users must send the response back to the completion handler
 */
@property (nonatomic, weak) id <kfxCustomAcquireVolumeLicenseDelegate> customAcquireVolumeLicenseDelegate;

///@endcond

//! Sets the SDK usage license
/**
 The input to this method is the VRS license string.\n
 
 @param license is the valid license string that was contained in a distributed header file that you received with the purchase of the SDK.
 @return returns YES if license valid and days remain in the license and NO otherwise
 */
+ (BOOL)setMobileSDKLicense:(NSString*)license;

///@cond EXTRACTION

//! Set up the SDK license server
/**
 The function is used to setup the url string of license server used for on device operation licensing. Application must call this function before any on device operation that requires license. Outstanding license usage will be reported to the server when server connection is available.
 
 @param licenseServerUrl should be a valid url string of the on device operation licensing server.
 \n\n
 Example code follows showing how to set your license server.
 
 @code
 self.myLicense = [[kfxLicense alloc] init]; // create the licensing object
 self.myLicense.delegate = self; // set the delegate
 [self.myLicense setMobileSDKLicenseServer:@"http://licenseserver.example.com"]; // set the license server
 @endcode
 */

- (void)setMobileSDKLicenseServer:(NSString*)licenseServerUrl;

// ===================================================
//! Preallocate volume licenses for offline operation
/**
 The function is used to preallocate volume licenses for on-device extraction operation. Outstanding license usage will be reported to the server when server connection is available.
 
 @param count   Number of volume license requested.
 \n\n
 Example code follows showing how to preallocate volume licenses for offlince operation.
 
 @code
 self.myLicense = [[kfxLicense alloc] init]; // create the licensing object
 self.myLicense.delegate = self; // set the delegate
 [self.myLicense setMobileSDKLicenseServer:@"http://licenseserver.example.com"]; // set the license server
 [self.myLicense acquireOnDeviceExtractionLicensesWithCount:20]; //preallocate 20 volume licenses
 @endcode
 */
- (void)acquireOnDeviceExtractionLicensesWithCount:(int)count;

// ===================================================
//! Get remaining license count
/**
 The function will return available license count for the offline operation, application should
 
 @return this method returns count of volume license acquired.
 \n\n
 Example code follows showing how to get remaining license count.
 
 @code
 self.myLicense = [[kfxLicense alloc] init]; // create the licensing object
 self.myLicense.delegate = self; // set the delegate
 [self.myLicense setMobileSDKLicenseServer:@"http://licenseserver.example.com"]; // set the license server
 [self.myLicense acquireOnDeviceExtractionLicensesWithCount:20]; //preallocate 20 volume licenses
 NSLog(@"Remain licenses %d", [self getRemainingOnDeviceExtractionLicenseCount]);
 @endcode
 */
- (int)getRemainingOnDeviceExtractionLicenseCount;
///@endcond

@end
