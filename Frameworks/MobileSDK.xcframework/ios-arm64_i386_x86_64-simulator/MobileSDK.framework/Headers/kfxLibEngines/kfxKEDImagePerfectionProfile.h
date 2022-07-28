//  API Reference
//
//  kfxKEDImagePerfectionProfile.h
//  KMCEngineData Objects
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

#ifndef KEDIMAGEPERFECTIONPROFILE
#define KEDIMAGEPERFECTIONPROFILE 1

//! MRZ Document Cropping Options enumeration
/**
 Use this enumeration to specify the type of MRZ Document cropping you want to perform on the image.  The KED_USEMRZDETECTION_LAST item can be used to make sure you only give your users options less than this value.  The following options can be specified:\n
 * KED_USEMRZDETECTION_OFF to switch off using MRZ document detection for image cropping process.\n
 * KED_USEMRZDETECTION_ON to indicate you want to use MRZ document detection for image cropping process.\n
 */

typedef enum {
    KED_USEMRZDETECTION_OFF,
    KED_USEMRZDETECTION_ON,
    KED_USEMRZDETECTION_LAST
} KEDMRZDetectionOptions;

//! Target Frame Cropping Options enumeration
/**
 Use this enumeration to specify the type of target frame cropping you want to perform on the image. The KED_USETARGETFRAMECROP_LAST item can be used to make sure you only give your users options less than this value. The following options can be specified:\n
 * KED_USETARGETFRAMECROP_OFF to switch off using target frame for image cropping process.\n
 * KED_USETARGETFRAMECROP_ON to indicate you want to use target frame for image cropping process.\n
 */

typedef enum {
    KED_USETARGETFRAMECROP_OFF,
    KED_USETARGETFRAMECROP_ON,
    KED_USETARGETFRAMECROP_LAST
} KEDTargetFrameCropOptions;

//! Document Detection Based Cropping Options enumeration
/**
 Use this enumeration to specify the type of document detection based cropping you want to perform on the image. The KED_USEDOCUMENTDETECTIONBASEDCROP_LAST item can be used to make sure you only give your users options less than this value. The following options can be specified:\n
 * KED_USEDOCUMENTDETECTIONBASEDCROP_OFF to switch off using document detection for image cropping process.\n
 * KED_USEDOCUMENTDETECTIONBASEDCROP_ON to indicate you want to use document detection for image cropping process.\n
 */

typedef enum {
    KED_USEDOCUMENTDETECTIONBASEDCROP_OFF,
    KED_USEDOCUMENTDETECTIONBASEDCROP_ON,
    KED_USEDOCUMENTDETECTIONBASEDCROP_LAST
} KEDDocumentDetectionBasedCropOptions;

//! Image Perfection Profile specifies advanced Image Processing options.
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n
 
 An instance of this class contains the advanced image processing options to perform on an image. These settings are a superset of what is possible with basic settings profiles.  These settings may have originated from a KFS Server, a Total Agility server or your own application. This object contains more complicated image processing settings, and allows two methods of specifying these settings: with an Operations string or an  XML Settings file. If both an ImagePerfectionProfile and a BasicSettingsProfile are supplied to an image processing engine, the ImagePerfectionProfile takes presidence, while ignoring the basic settings.\n\n
 **Serialization**
 \n\n
 This class adopts the NSCoding protocol so that this object may be archived and unarchived using the iOS standard [NSKeyedArchiver archiveRootObject:<object> toFile: archiveFileName]; approach.  Using keyed archive files, you can save this object for later use.  The library supports backward compatibility, such that as a new version of an app that uses the API in this SDK, includes a newer versions of the SDK libraries that have data model changes, the older archive can still be read by the newer version.  However, it is not a design goal to archive and dearchive with forward compatibility, such as decoding an archive on a newer version of the class, using an older library.\n\n
 Refer to the kfxKEDImage class description, by expanding the class description, that describes how to archive and unarchive objects in this framework that adopt the NSCoding protocol.\n
 You can create keyed archives using NSKeyedArchiver objects and decoded by NSKeyedUnarchiver objects. The framework design uses keyed archives, which differ from sequential archives, in that every value encoded in a keyed archive is given a Kofax unique key name. When you decode an archive, the underlying implementation can use values by name, allowing the unarchive delegate to request values in any order or not at all.\n
 
 Please refer to the Apple documentation for more information: https://developer.apple.com/library/ios/documentation/cocoa/reference/foundation/Classes/NSCoder_Class/Reference/NSCoder.html
 \n\n
 *Keyed Archiving*
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedArchiver_Class/Reference/Reference.html#//apple_ref/occ/cl/NSKeyedArchiver
 \n\n
 *Keyed Unarchiving*
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedUnarchiver_Class/Reference/Reference.html#//apple_ref/occ/instm/NSKeyedUnarchiver
 
 */

__deprecated_msg("This class was deprecated in SDK 3.3. Please use KFXImageProcessorConfiguration instead.")
@interface kfxKEDImagePerfectionProfile : NSObject <NSCoding>


// ===================================================
//! Name of this particular image perfection profile.
/**
App specific reference name, used to associate a name with this profile, usually describing its purpose.
 */
@property (retain,atomic) NSString *name;

// ===================================================
//! Unique IP Operations string.
/**
 App specific definition of the encoded imaged processing (IP) options desired. The string is composed of a concatonation of individual IP tokens, each of which enable an option. Please refer to the developers guide for a list of IP tokens.
 */
@property (retain,atomic) NSString *ipOperations;         // a valid operations string

// ===================================================
//! Filepath of a unique settings file.
/**
 App specific definition of the encoded imaged processing (IP) options desired stored in an XML file. Please refer to the developers guide for a definition of the XML file format.
 */
@property (retain,atomic) NSString *ipOperationsFilePath;   // a path to an XML settings file in the app's bundle

// ==========================================================
//! Initialize the image perfection profile object
/**
 Use this method in your typical initialization of the object.  This initializes the object with the standard defaults.
 @code
 kfxKEDImagePerfectionProfile * myProfile = [[kfxKEDImagePerfectionProfile alloc] init];
 @endcode
  @return A kfxKEDImagePerfectionProfile object
 */

//=============================
//! Specify image processor to use MRZ passport detection for cropping process or not
/*
 Application should set the property to KED_USEMRZDETECTION_ON to enable MRZ passport detection during document processing.
 Default:KED_USEMRZDETECTION_OFF
 */
@property (atomic) KEDMRZDetectionOptions useMRZPassportDetection;

// ===================================================
//! Specify image processor to run target frame cropping prior to page detection
/**
 Set it to KED_USETARGETFRAMECROP_ON to enable target frame cropping during image processing; kfxKEDImage's targetFrame property is used as cropping region.
 Turn it ON to run crop based on targetFrame from kfxKEDImage.
 By default is KED_USETARGETFRAMECROP_OFF.
 */
@property (atomic) KEDTargetFrameCropOptions useTargetFrameCrop;

// ===================================================
//! Specify image processor to run document detection based cropping prior to page detection
/**
 Set it to KED_USEDOCUMENTDETECTIONBASEDCROP_ON to enable document detection based cropping during image processing.
 By default is KED_USEDOCUMENTDETECTIONBASEDCROP_OFF.
 */
@property (atomic) KEDDocumentDetectionBasedCropOptions useDocumentDetectionBasedCrop;

-(id)init;


// ==========================================================
//! Initialize the image perfection profile instance with a given name
/**
 Use this method in your typical [[kfxKEDImagePerfectionProfile alloc] initWithName: @"ProfileName"]; code lines to initialize an instance of this class with the standard defaults.
 */
-(id)initWithName:(NSString*)name;


// ==========================================================
//! Initialize the image perfection profile instance with a given name and a settings file path.
/**
 Use this method in your typical [[kfxKEDImagePerfectionProfile alloc] initWithName: @"ProfileName andFilePath: @"yourFilePath"]; code lines to initialize an instance of this class with the standard defaults.
 */
-(id)initWithName:(NSString*)name andFilePath: (NSString*) filePath;


// ==========================================================
//! Initialize the image perfection profile instance with a given operation string.
/**
 Use this method in your typical [[kfxKEDImagePerfectionProfile alloc] initWithName: @"ProfileName andOperations: @"_DoBinarization_"]; code lines to initialize an instance of this class with the standard defaults, and the specified operations string with individual image processing tokens.
 */

-(id)initWithName:(NSString*)name andOperations: (NSString*) ops;


@end

#endif
