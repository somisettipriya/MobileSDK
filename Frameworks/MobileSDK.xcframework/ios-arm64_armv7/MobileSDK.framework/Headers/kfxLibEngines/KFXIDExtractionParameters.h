//
//  KFXIDExtractionParameters.h
//  kfxLibEngines
//
//  Copyright (c) 2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import "kfxKOEIDRegion.h"

@class kfxKEDImage;
@class kfxKEDBarcodeResult;

//! An enumeration containing possible ID types.
/**
 Use one of the values of this enumeration to set the ID type.
 */
typedef NS_ENUM(NSInteger, KFXIDType)
{
    KFXIDType_ID,
    KFXIDType_Passport
};

//! ID exraction parameters object
/**
 This object represents parameters for ID extractor.
 
 Initialization:
 [KFXIDExtractionParameters new] (or [[KFXIDExtractionParameters alloc] init]) - default constructor, sets parameters to default values. Not a valid object to be sent to the extractor.
 
 KFXIDExtractionParameters* params = [[KFXIDExtractionParameters alloc] initWithType:region:frontImage:frontBarcodes:backImage:backBarcodes:isProcessed]] - parameters will be initialized with provided type, region, front image, front barcodes, back image, back barcodes, isProcessed.
 
 @see kfxKOEIDExtractor
 */
@interface KFXIDExtractionParameters : NSObject

//! ID type parameter
/**
 Allows to get ID type value.

 Default value is KFXIDType_ID.

 @see KFXIDType
 */
@property (nonatomic, assign, readonly) KFXIDType type;

//! Project name parameter
/**
 Allows to get projectName parameter value.
 
 Default value is nil.
 */
@property (nonatomic, strong, readonly) NSString* projectName;

//! Front image parameter
/**
 Allows to get front image object.
 
 Default value is nil.
 
 @see kfxKEDImage
 */
@property (nonatomic, strong, readonly) kfxKEDImage* frontImage;

//! Back image parameter
/**
 Allows to get back image object.
 
 Default value is nil.
 
 @see kfxKEDImage
 */
@property (nonatomic, strong, readonly) kfxKEDImage* backImage;

//! Front barcode array parameter
/**
 Allows to get front barcodes.
 
 Default value is nil.
 
 @see kfxKEDBarcodeResult
 */
@property (nonatomic, strong, readonly) NSArray<kfxKEDBarcodeResult*>* frontBarcodes;

//! Back barcode array parameter
/**
 Allows to get back barcodes.
 
 Default value is nil.
 
 @see kfxKEDBarcodeResult
 */
@property (nonatomic, strong, readonly) NSArray<kfxKEDBarcodeResult*>* backBarcodes;

//! Is processed flag
/**
 Allows to specify if front/back image has already been processed prior to extraction.
 
 Default value is NO.
 */
@property (nonatomic, assign, readonly) BOOL isProcessed;

//! Extract face flag
/**
 Allows to specify if identification photo extraction will be attempted.
 
 Default value is NO.
 */
@property (nonatomic, assign, readonly) BOOL extractFaceImage;

//! Extract signature flag
/**
 Allows to specify if signature image extraction will be attempted.
 
 Default value is NO.
 */
@property (nonatomic, assign, readonly) BOOL extractSignatureImage;

//! Converter method
/**
 This method converts provided region value and ID type to the corresponding project name.
 
 @param region - ID region.
 @param type - ID type.
 @return project name. If provided invalid region or type value, nil will be returned.
 
 @see kfxKOEIDRegion
 @see KFXIDType
 */
+ (NSString*)projectNameForRegion:(kfxKOEIDRegion)region idType:(KFXIDType)type;

//! Converter method
/**
 This method converts provided project name to the corresponding region and ID type.
 If project in invalid, region and type will be set to default values (kfxKOEIDRegion_US and KFXIDType_ID, respectively).
 
 @param projectName - ID project.
 @param region - region value to be filled.
 @param type - ID type value to be filled.
 
 @see kfxKOEIDRegion
 @see KFXIDType
 */
+ (void)regionForProject:(NSString*)projectName region:(kfxKOEIDRegion*)region idType:(KFXIDType*)type;

//! Converter method
/**
 This method converts provided project name to the corresponding subProject name.
 If project is invalid, returns nil.
 
 @param projectName - ID project.
 @return subProject name.
 */
+ (NSString*)subProjectForProject:(NSString*)project;

//! Constructor
/**
 Specify ID type, project name, front image, front barcodes, back image, back barcode, isProcessed flag. At least one of the frontImage, backImage, frontBarcodes, or backBarcodes parameters is required.
 
 @param type - ID type (optional).
 @param projectName - project name (optional). The default value is null.
 @param frontImage - front image (optional).
 @param frontBarcodes - front side barcodes(optional).
 @param backImage - back image(optional).
 @param backBarcodes - back side barcodes(optional).
 @param isProcessed - front/back image processed indicator. If true, the SDK will not pre-process images before extraction.
 
 @see kfxKEDImage
 @see KFXIDType
 @see kfxKEDBarcodeResult
 
 @deprecated Deprecated in 3.5, replaced with {@link #initWithFrontImage:frontBarcodes:backImage:backBarcodes:isProcessed:}
 */
- (instancetype)initWithType:(KFXIDType)type projectName:(NSString*)projectName frontImage:(kfxKEDImage*)frontImage frontBarcodes:(NSArray<kfxKEDBarcodeResult*>*)frontBarcodes backImage:(kfxKEDImage*)backImage backBarcodes:(NSArray<kfxKEDBarcodeResult*>*)backBarcodes isProcessed:(BOOL)isProcessed;

//! Constructor
/**
 Specify front image, front barcodes, back image, back barcodes, and isProcessed flag. At least one of the frontImage, backImage, frontBarcodes, or backBarcodes parameters is required.
 
 @param frontImage - front image (optional).
 @param frontBarcodes - front side barcodes (optional).
 @param backImage - back image (optional).
 @param backBarcodes - back side barcodes (optional).
 @param isProcessed - front/back image processed indicator. If true, the SDK will not pre-process images before extraction.
 
 @see kfxKEDImage
 @see KFXIDType
 @see kfxKEDBarcodeResult
 */
- (instancetype)initWithFrontImage:(kfxKEDImage*)frontImage frontBarcodes:(NSArray<kfxKEDBarcodeResult*>*)frontBarcodes backImage:(kfxKEDImage*)backImage backBarcodes:(NSArray<kfxKEDBarcodeResult*>*)backBarcodes isProcessed:(BOOL)isProcessed;

//! Constructor
/**
 Specify ID type, project name, front image, front barcodes, back image, back barcode, isProcessed flag, extracFaceImage flag, and extractSignatureImage flag. At least one of the frontImage, backImage, frontBarcodes, or backBarcodes parameters is required.
 
 @param type - ID type (optional).
 @param projectName - project name (optional). The default value is null.
 @param frontImage - front image (optional).
 @param frontBarcodes - front side barcodes(optional).
 @param backImage - back image(optional).
 @param backBarcodes - back side barcodes(optional).
 @param isProcessed - front/back image processed indicator. If true, the SDK will not pre-process images before extraction.
 @param extractFaceImage - whether or not identification photo extraction will be attempted.
 @param extractSignatureImage - whether or not signature image extraction will be attempted.
 
 @see kfxKEDImage
 @see KFXIDType
 @see kfxKEDBarcodeResult
 */
- (instancetype)initWithType:(KFXIDType)type projectName:(NSString*)projectName frontImage:(kfxKEDImage*)frontImage frontBarcodes:(NSArray<kfxKEDBarcodeResult*>*)frontBarcodes backImage:(kfxKEDImage*)backImage backBarcodes:(NSArray<kfxKEDBarcodeResult*>*)backBarcodes isProcessed:(BOOL)isProcessed extractFaceImage:(BOOL)extractFaceImage extractSignatureImage:(BOOL)extractSignatureImage;

@end
