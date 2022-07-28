//
//  kfxKOEIDExtractor.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>
#import "kfxKOEImageField.h"

@class KFXIDExtractionParameters;
@class kfxKEDClassificationResult;
@class kfxKEDImage;
@protocol KFXProjectProviderProtocol;

extern NSString* const KFXAdditionalErrorsKey;

//! ID Extraction Result
/**
 Represents the result of ID extraction.
 
 @see kfxKOEIDExtractor
 */
@interface KFXIDExtractionResult : NSObject

//! Barcode read success indicator
/**
 YES if barcode data was provided and extracted successfully (either from image or barcode string), NO otherwise.
 
 Default value is NO.
 */
@property (nonatomic, assign) BOOL isBarcodeRead;

//! OCR success indicator
/**
 YES if data was provided and extracted successfully, NO otherwise.
 
 Default value is NO.
 */
@property (nonatomic, assign) BOOL isOcrRead;

//! ID verification confidence rating
/**
 Provides the confidence rating that specified ID was verified.
 Can take the following values:
    - 0 if front side was not provided or failed to be extracted.
    - 50 if front data was extracted successfully and back side wasn't (or wasn't provided).
    - from 50 to 100 if both sides were extracted successfully. Actual value will depend on difference between front and back values. Higher value means a better match.
 
 Default value is 0.0.
 */
@property (nonatomic, assign) float documentVerificationConfidenceRating;

//! An array of extracted fields
/**
 Array of kfxKOEDataField objects.
 
 Default value is nil.
 
 @see kfxKOEDataField
 */
@property (nonatomic, strong) NSArray* fields;

//! Front side classification result
/**
 Contains front side image classification result.
 Nil if front image was not provided for extraction or if front image classification failed.
 
 Classification is considered as failed if classification confidence value returned by classifier
 is negative. Any non-negative confidence is considered as a successful classification.
 There is no determined range confidence value can take; higher values mean higher credibility.
 
 Default value is nil.
 
 @see kfxKEDClassificationResult
*/
@property (nonatomic, strong) kfxKEDClassificationResult* frontClassification;

//! Back side classification result
/**
 Contains back side image classification result.
 Nil if back image was not provided for extraction or if back image classification failed.
 
 Classification is considered as failed if classification confidence value returned by classifier
 is negative. Any non-negative confidence is considered as a successful classification.
 There is no determined range confidence value can take; higher values mean higher credibility.
 
 Default value is nil.
 
 @see kfxKEDClassificationResult
 */
@property (nonatomic, strong) kfxKEDClassificationResult* backClassification;

//! The face image field
/**
 The optional identification photo field extracted from the front or back image.

 Will return nil if face extraction was disabled, or an identification photo was not found.
 
 Default value is nil.
 */
@property (nonatomic, strong) kfxKOEImageField* faceImageField;

//! The signature image field
/**
 The optional signature image field extracted from the front or back image.
 
 Will return nil if signature extraction was disabled, or a signature image was not found.
 
 Default value is nil.
 */
@property (nonatomic, strong) kfxKOEImageField* signatureImageField;

@end

//! ID Extraction Protocol
/**
 The kfxKOEIDExtractorDelegate defines the protocol for the delegate ID Extractor calls during extraction.
 */
@protocol kfxKOEIDExtractorDelegate<NSObject>

@required

//! Extraction Results delegate method
/**
 This method is called when the extraction is completed and provides the extraction results and errors.
 Front and back errors may contain an array of additional errors, accessible via userInfo key KFXAdditionalErrorsKey.
 E.g. NSArray* additionalFrontErrors = frontError.userInfo[KFXAdditionalErrorsKey];
 
 The implementation of this method is required.
 
 @param result : a KFXIDExtractionResult object with extraction result data. Can be nil in case of some errors like invalid parameters.
 @param frontError : a NSError object which represent front side extraction error. If there was no error or front side was not provided (but back side was) it will be nil.
 @param backError : a NSError object which represent back side extraction error. If there was no error or back side was not provided (but front side was) it will be nil.
 
 @see KFXIDExtractionResult
 @see kfxKOEIDExtractor
 */
- (void)extractionResult:(KFXIDExtractionResult*)result frontError:(NSError*)frontError backError:(NSError*)backError;

@end


//! ID Image Processing Protocol
/**
 The kfxKOEIDImageProcessingDelegate defines the protocol for the image processing calls during extraction.
 */
@protocol kfxKOEIDImageProcessingDelegate<NSObject>

@optional

//! Delegate method for front image processing
/**
 This method is called when the front image processing is complete.
 If image processing is disabled, the callback will contain the original image.
 If no front image was provided, no callback will be raised.
 If image processing failed or extraction was canceled before processing finished, no callback will be raised, and the appropriate errors will be returned from the kfxKOEIDExtractorDelegate.
 
 The implementation of this method is optional.
 
 @param processedImage : Front side processed Image.
 
 @see kfxKOEIDExtractorDelegate
 @see kfxKOEIDExtractor
 */
- (void)frontProcessedImage:(kfxKEDImage*)processedImage;

@optional

//! Delegate method for back image processing
/**
 This method is called when the back image processing is complete.
 If image processing is disabled, the callback will contain the original image.
 If no back image was provided, no callback will be raised.
 If image processing failed or extraction was canceled before processing finished, no callback will be raised, and the appropriate errors will be returned from the kfxKOEIDExtractorDelegate.
 
 Note: In certain cases, if the provided unprocessed image is known to contain only a barcode and no
 other useful information, processing may be skipped, and the original image will be returned.
 
 The implementation of this method is optional.
 
 @param processedImage : Back side processed Image.
 
 @see kfxKOEIDExtractorDelegate
 @see kfxKOEIDExtractor
 */
- (void)backProcessedImage:(kfxKEDImage*)processedImage;

@end


//! The ID Extractor Class
/**
 Framework: libKfxEngines
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>
 Relevant Header File: kfxKOEIDExtractor.h
 An instance of this class contains methods to extract data from ID images.
 
 **Initialization**
 [kfxKOEIDExtractor new] (or [[kfxKOEIDExtractor alloc] init]) - default constructor, the extractor will be initialized with default KFXLocalBundleProjectProvider automatically.
 
 [[kfxKOEIDExtractor alloc] initWithProjectProvider:provider] - the extractor will be initialized with provided id<KFXProjectProviderProtocol> project provider.
 
 **Processing**
 The extractor requires the image(s) to either be cropped before performing the extraction, or the KFXIDExtractionParameters#isProcessed flag to be set to false. To get the most accurate results, send uncropped images. Otherwise, most ID images can be cropped using the kfxKENImageProcessor with the following operation string:
 "_DeviceType_2_Do90DegreeRotation_4_DoCropCorrection__DoScaleImageToDPI_500_DoSkewCorrectionPage__DocDimLarge_3.375_DocDimSmall_2.125_LoadSetting_<Property Name=\"CSkewDetect.correct_illumination.Bool\" Value=\"0\" />"
 
 If the image was preprocessed differently, the extraction results may not be accurate. For more information on preprocessing Passports or IDs with less common dimensions, please refer to the MobileID documentation.
 
 **Licensing**
 
 Extractor requires a valid license to be set. It should have enough license count for LIC_ON_DEVICE_EXTRACTION feature.

 Note: The extractor uses several Optical Character Recognition (OCR) engines for the extraction. Tesseract OCR engine is used for non-latin characters recognition. By default Tesseract OCR engine is disabled and its binaries will not influence application size. In order to enable Tesseract OCR engine, call enable class method before run kfxKOEIDExtractor's extract.

 @see KFXTesseractOCR
 @see kfxKUTLicensing
 @see KFXProjectProviderProtocol
 @see KFXLocalBundleProjectProvider
 */
@interface kfxKOEIDExtractor : NSObject

//! kfxKOEIDExtractorDelegate notifies about extraction completion
/**
 This delegate must be set in order for your app to receive delegate calls.

 @see kfxKOEIDExtractorDelegate
 */
@property (nonatomic, weak) id<kfxKOEIDExtractorDelegate> delegate;


//! kfxKOEIDImageProcessingDelegate notifies about image processing completion
/**
 The delegate is called when either the front or back image processing is complete.
 This delegate must be set before extraction is started for your app to receive delegate calls.
 Wait for the kfxKOEIDExtractorDelegate callback before clearing or editing the recieved bitmaps.
 
 @see kfxKOEIDImageProcessingDelegate
 @see kfxKOEIDExtractorDelegate
 */
@property (nonatomic, weak) id<kfxKOEIDImageProcessingDelegate> imageProcessingDelegate;


//! Constructor for custom project provider
/**
 This constructor allows to specify custom project provider to be used to get extraction assets.
 
 @param projectProvider - a project provider instance which conforms to KFXProjectProviderProtocol protocol.

 @see KFXProjectProviderProtocol
 */
- (instancetype)initWithProjectProvider:(id<KFXProjectProviderProtocol>)projectProvider;

//! Use this method to start extraction
/**
 This method starts the extraction with specified extraction parameters.
 Parameters will be verified before the extraction. In case of invalid parameters an appropriate error will be returned via delegate.
 If other extract call is received while previous extraction is in progress, KMC_EX_BUSY error will be sent.
 
 @param parameters - a KFXIDExtractionParameters object with extraction parameters.
 
 @see KFXIDExtractionParameters
 @see kfxKOEIDExtractorDelegate
 */
- (void)extract:(KFXIDExtractionParameters*)parameters;

//! Use this method to cancel the extraction.
/**
 If this method is called during the extraction, extractionResults:error: method of the kfxKOEIDExtractorDelegate will be called, containing KMC_EX_CANCEL_OPERATION_SUCCESS error for corresponding ID sides. When the callback is received, you may start new extraction.
 
 If new extraction is started before receiving extractionResult callback, the behavior is undefined.

 @see kfxKOEIDExtractorDelegate
 */
- (void)cancelExtraction;

@end
