//
//  API Reference
//  kfxExtractionParameters.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>

@class kfxExtractionCredentials;
@protocol KFXProjectProviderProtocol;

//! An enumeration containing the possible extraction type values.
/**
 Use one of the values of this enumeration to set the extraction type.
 */
typedef NS_ENUM (NSInteger, kfxExtractionType)
{
    kfxExtractionType_RTTI,
    kfxExtractionType_KTA,
    kfxExtractionType_OnDevice,
    kfxExtractionType_Off
};

//! The data extraction parameters class.
/**
 The parameters object allows to customize image data extraction functionality.
 The behavior and default values for some parameters could vary cross capture view controllers and details are specified in target document capture view controller parameters class.
 
 @see kfxIParameters
 */
@interface kfxExtractionParameters : NSObject <NSCopying>

/// An extraction type value.
/**
 The supported modes are:
 kfxExtractionType_RTTI: extraction should be performed on RTTI server.
 kfxExtractionType_KTA: extraction should be performed on KTA server.
 kfxExtractionType_OnDevice: extraction should be performed on device. Supported only for IDs and passports.
 kfxExtractionType_Off: extraction is disabled.
 Default value is kfxExtractionType_RTTI.
 
 When performing extraction (value set not to kfxExtractionType_Off), image processing is required for successful extraction.
 
 @see kfxProcessingParameters
 */
@property (nonatomic, assign) kfxExtractionType extractionType;

/// A string value that determines extraction server URL.
/**
 Specify the server URL in the following format: "http(s)://yourserver.com".
 The default value is nil.
 */
@property (nonatomic, copy) NSString* serverURL;

/// Extraction credentials object.
/**
 A property to get and set kfxExtractionCredentials object.
 The default value is nil.
 
 Credentials are applicable for KTA server only.
 
 @see kfxExtractionCredentials
 */
@property (nonatomic, copy) kfxExtractionCredentials* credentials;

/// A project provider instance
/**
 A property to get and set project provider.
 The default value is nil.
 
 Applicable for on-device extraction only.

 @see KFXProjectProviderProtocol
 */
@property (nonatomic, strong) id<KFXProjectProviderProtocol> projectProvider;

@end
