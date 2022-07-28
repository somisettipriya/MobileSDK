//  API Reference
//
//  KMCEngines framework
//
//  kfxKIPImageProcessor.h
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//
#import <Foundation/Foundation.h>

#ifndef KMCKEDIMAGEPROCESSOR
#define KMCKEDIMAGEPROCESSOR 1

#import "KFXImageProcessorConfiguration.h"
#import "kfxKEDImagePerfectionProfile.h"
#import "kfxKEDBasicSettingsProfile.h"
#import "kfxKEDQuickAnalysisSettings.h"
#import "kfxKEDImage.h"
#import "kfxKIPDelegate.h"


//! The Image Processor Class
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n
 Relevant Header File: kfxKIPImageProcessor.h\n
 An instance of this class contains methods to process images.  It holds the profile that specifies the kind of image processing to perform based on a selected image processing profile.  Use the methods on this object to do standard image processing, perform a quick quality analysis, and to find a signature in the image for a particular area.\n\n
 **Licensing**
 \n\n
 This is a license protected class. Certain methods in this object are protected by a license mechanism. If you attempt to use these methods without setting the license, then you will receive the KMC_IP_LICENSE_INVALID error code. Refer to the method descriptions to determine what methods are license protected. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object. Example code is provided to show you how to set your license, which can be found in the kfxKUTLicensing class of the kfxUtilities framework.\n\n

 */
@interface kfxKENImageProcessor : NSObject


//! kfxKIPDelegate that notifies you about progress and completion of image processing operations
/**
 You must set this delegate to self in order for your app to receive the processing delegate calls during image processing.
 */
@property (atomic, weak) id<kfxKIPDelegate> delegate;


//! The Image Processor Engine factory method
/**
 Use this method to obtain a singleton object reference to the kfxKENImageProcessor.
 @code
 kfxKENImageProcessor* myEngine = [kfxKENImageProcessor instance];
 @endcode
 */
+ (kfxKENImageProcessor*) instance;


// ====================================================
//! Image Perfection Profile specifies advanced Image Processing options.
/**
 
 An instance of this class contains the advanced image processing options to perform on an image. These settings are a superset of what is possible with basic settings profiles.  These settings may have originated from a KFS Server, a Total Agility server or your own application.  This object contains more complicated image processing settings, and allows two methods of specifying these settings: with an image processing Operations string, or a settings file.  If both an ImagePerfectionProfile and a BasicSettingsProfile are supplied to an image object, the ImagePerfectionProfile takes precedence, while ignoring the basic settings.  If you include both a settings file and an operations string, the engine includes both.  Even though you should try to avoid use of conflicting settings to get expected consistent results, if there are conflicts in one or both of the settings, the last setting in a string or file takes precedence.  For instance if you requested a grayscale output and then a bitonal output in the same settings string, then the image would be bitonal.
 
 @deprecated Deprecated in SDK 3.3. Please use KFXImageProcessorConfiguration instead.
 
 */
@property (atomic, retain) kfxKEDImagePerfectionProfile * imagePerfectionProfile;


#ifdef INCLUDE_GRAYSCALE_ENHANCEMENT
// ==========================================================
//! Set to true to process image as grayscale (enhances speed of some image processing operations)
/**
 Default: 	FALSE
 
 */
@property (nonatomic, assign) bool preProcessAsGrayscale;
#endif

// ==========================================================
//! Set the desired output image representation format.
/**
 Use this property to specify the representation of the output processed image object.  When image processing completes, the library calls the imageOut delegate and provides the output image object.  This property directs the image processor to create the object with the image as a bitmap, a file or both.  You need to specify a fully qualified file path for the file format representation.\n\n
 As opposed to using the imageWriteToFile in the kfxKEDImage object, which is a synchronous method, you can use the property to write the file as part of a background process in the image processor when you set this property to IMAGE_REP_FILE.\n\n

 The image processor has four processedImage properties that specify how the file should be written when the image representation is set to IMAGE_REP_FILE or IMAGE_REP_BOTH.  When the image representation is set to IMAGE_REP_BITMAP, the other three related file properties are unused.\n
 
 If you set the processedImageRepresentation to IMAGE_REP_NONE, the library still generates an output image object, but it will contain no image.  However, the image object will contain the image metadata associated with the processing operation.\n\n
 You must always set this property to specify your desired output image format, or the default will be used.\n
 Related Properties for file storage:\n
 - processedImageRepresentation property\n
 - processedImageMimetype property\n
 - processedImageJpegQuality property\n
 - specifyProcessedImageFilePath method\n
 Default: 	IMAGE_REP_BITMAP\n
 @see specifyProcessedImageFilePath\n
 @see processedImageRepresentation property\n
 @see processedImageMimetype property\n
 @see processedImageJpegQuality property\n
 */
@property (atomic, assign) KEDImageRepresentation processedImageRepresentation;

// ==========================================================
//! Set the the file storage mimetype configuration
/**
 Use this setting to specify the mimetype of the output file generated by the image processor when you specified IMAGE_REP_FILE or IMAGE_REP_BOTH in the processedImageRepresentation.\n
 The library automatically sets this property for you if you use the specifyProcesedImageFilePath method and use a standard file extension recognized by the library. Otherwise, you should set this before calling processImage.  This property is write/read because you can decide what mimetype you want before starting image processing.\n
 Related Properties for file storage:\n
  - processedImageRepresentation property\n
  - processedImageMimetype property\n
  - processedImageJpegQuality property\n
  - specifyProcessedImageFilePath method\n
 Default: MIMETYPE_UNKNOWN
 @see KEDImageMimeType enumeration
 */
@property (assign, atomic) KEDImageMimeType processedImageMimetype;

// ==========================================================
//! Specify a file path for use with the object
/**
 Use this method to specify the fully qualified path to a file name that you want to contain the output processed image. Usually this file should not already exist.  You should always check for returned error codes because this specifyProcessedImageFilePath method returns errors for certain cases.  When this method returns an error, the libary will not save the file path. The valid file path extensions are: jpg, jpeg, tif, tiff, png and their upper-case equivalents.\n
 If the file name extension is valid, then the library sets up the imageMimetype setting for you.\n
 This value is only used when the processedImageRepresentation is set to IMAGE_REP_FILE or IMAGE_REP_BOTH.\n
 @return KMC_ED_OBJECT_REP_BITMAP_MISMATCH, when you try to set a file name for an existing file, when there is already a bitmap set for the object.\n
 @return KMC_ED_FILE_EXTENSION, when you try to set a file name with an illegal file extension.
 */
- (int) specifyProcessedImageFilePath: (NSString*) fullFilePath;

// ==========================================================
//! Get the current processed image file path
/**
 Use this method to retrieve the current file path associated with this object.  In some cases, the file name may not have been set if the specifyProcessedImageFilePath method returned an error.
 */
- (NSString *) getProcesedImageFilePath;


// ==========================================================
//! Set the processed Image jpeg Quality
/**
 This property indicates the desired level of quality for writing a JPEG image when you want the image processor to automatically save the image to a file.  It must be set to a value from 1 to 100.  The higher the number the less compression is used, the higher the quality and the larger the output file size in bytes.  A low setting would highly compress the output image, and some quality is sacrificed, but the file size is smaller.  Valid for color output file format only, and ignored for others.\n
 This value is only used when the processedImageRepresentation is set to IMAGE_REP_FILE or IMAGE_REP_BOTH.
 Default: 90
 */
@property (assign, atomic) int processedImageJpegQuality;


// ====================================================
//! Basic settings profile specifies Image Processing options
/**
 An instance of this class contains the simple image processing options that you want to perform on an image. These define the standard crop, deskew and rotation options.  You can also use this object to specify the output image DPI and the desired output image color.  Specify the output color by setting outputBitDepth to 1 for bitonal images, 8 for grayscale, or 24 for color.  The image processor outputs a new image with the bitmap in one of these colors.  The cropping Tetragon defines the bounding corner points of an area of an image that you want to crop, and thereby override automatic page detection.
 
 If the outputDPI is >= 300 DPI, and the outputBitDepth is 1, then the image processing includes enhanced binarization. Otherwise it uses standard binarization.
 
 @deprecated Deprecated in SDK 3.3. Please use KFXImageProcessorConfiguration instead.
 
 */
@property (atomic, retain) kfxKEDBasicSettingsProfile * basicSettingsProfile;


// ====================================================
//! Use the processImage method to process the specified image
/**
 Use this method when you want to perform standard image processing on the image supplied with the method.  The library processes the image using the processing options contained in the profile you specified.  You can specify either a basic settings profile or an image perfection profile.  If the input image representation is file based, and a bitmap is not supplied, the library will load and process the image from the file in the image object. If the image is represented by a bitmap, then the library uses that image, even if the image representation indicates both (bitmap and file).\n\n
License Required: this is a licensed method.  You cannot use this method until you have set a valid SDK license. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object.  You must obtain a valid license from Kofax in order to use licensed methods. An example of setting your license can be found in the licensing class.\n
 This method generates a brand new kfxKEDImage object, if the image processing completes without error.  The library notifies you by calling the imageOut delegate.  The output image object does not retain much from the input image.\n
 When the processing completes normally, the library sets the following output image object properties:\n
 imageMimeType, to the MIMETYPE_UNKNOWN setting.\n
 imageBitMap, to the new processed bitmap.\n
 imageRepresentation, to IMAGE_REP_BITMAP, because the bitmap is stored.\n
 imageSourceID, to the imageID of the input image.\n
 imageMetaData, to the metadata created by the image processor.\n
 imagePerfectionProfileUsed or basicSettingsProfileUsed, to the one that was used to produce the output image.\n
 imageGPSLat, to the preserved latitude of the source input file.\n
 imageGPSLon, to the preserved longitude of the source input file.\n
 imageFileOutputColor, to the new color definition of the output image generated.\n
 imageHeight, to the height of the new output image.\n
 imageWidth, to the width of the new output image.\n
 All other image object properties are set to the default.\n
 
 @param imageToProcess the actual input image object that you want to process
 @return This method returns KMC_SUCCESS when the image processing was started up successfully.  Several error codes are returned for this method when the image processing request could not be started, due to such things as memory limitations.  In these cases, the method generates no final completion notification by calling your imageOut delegate. But, if the library returns KMC_SUCCESS, then image processing has started successfully.  Your imageOut delegate is called after the image processing completes, in which case a processing error may be indicated in the delegate. So you should always check this return value to detect if you should expect progress delegate calls or completion delegate calls.  One of these error codes may be returned immediately, in which case the background processing is not started.\n\n
 The possible error codes are:\n
 KMC_IP_LICENSE_INVALID if you have not set a valid license yet.
  KMC_ED_NO_MEMORY_FOR_METADATA if memory could not be allocated to store image metadata.\n
 KMC_ED_NOIMAGE  if you did not include an image in the input image object.\n
 KMC_IP_NO_PROFILE  if you forgot to include a profile, either a basic settings or perfection profile.\n
 KMC_ED_FILEPATH if the image object is represented by a file, but the file path is missing.\n
 KMC_ED_NONEXISTENT_FILE If the file name in the input object was set to the name of a non-existant file, and you try to process it.\n
 KMC_IP_NO_REPRESENTATION if the image representation in the input image object is invalid.\n
 KMC_ED_IMAGE_COLOR_SPACE if the library could not create a color space reference, usually a system resource issue.\n
 KMC_ED_IMAGE_CONTEXT if an image bitmap could not be created, normally caused by a resource issue.\n\n
 
 @see Use cancelProcessing to cancel an image processing operation if necessary.
 
 @deprecated as of 3.3, replaced by {@link kfxKENImageProcessor::processImage:withConfiguration:}
 */
-(int) processImage: (kfxKEDImage *) imageToProcess;


// ====================================================
//! Use the processImage method to process the specified image
/**
 Use this method when you want to perform image processing on the image supplied with the method. The library processes the image using the processing options contained in the configuration you specified. If the input image representation is file based, and a bitmap is not supplied, the library will load and process the image from the file in the image object. If the image is represented by a bitmap, then the library uses that bitmap, even if the image representation indicates both (bitmap and file).\n\n
 License Required: this is a licensed method. You cannot use this method until you have set a valid SDK license. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object. An example of setting your license can be found in the licensing class.\n
 This method generates a brand new kfxKEDImage object, if the image processing completes without error. The library notifies you by calling the imageOut delegate.\n
 When the processing completes normally, the library sets the following output image object properties:\n
 imageMimeType, to the MIMETYPE_UNKNOWN setting.\n
 imageBitmap, to the new processed bitmap.\n
 imageRepresentation, to IMAGE_REP_BITMAP.\n
 imageSourceID, to the imageID of the input image.\n
 imageMetaData, to the metadata created by the image processor.\n
 imagePerfectionProfileUsed or basicSettingsProfileUsed, to the one that was used to produce the output image.\n
 imageGPSLat, to the preserved latitude of the source input file.\n
 imageGPSLon, to the preserved longitude of the source input file.\n
 imageFileOutputColor, to the new color definition of the output image generated.\n
 imageHeight, to the height of the new output image.\n
 imageWidth, to the width of the new output image.\n
 All other image object properties are set to the default.\n
 
 @param imageToProcess the actual input image object that you want to process
 @param configuration the configuration containing the image processing operations to be performed
 @return This method returns KMC_SUCCESS when the image processing was started up successfully. Several error codes are returned for this method when the image processing request could not be started, due to such things as memory limitations. In these cases, the method generates no final completion notification by calling your imageOut delegate. But, if the library returns KMC_SUCCESS, then image processing has started successfully. Your imageOut delegate is called after the image processing completes, in which case a processing error may be indicated in the delegate. So you should always check this return value to detect if you should expect progress delegate calls or completion delegate calls. One of these error codes may be returned immediately, in which case the background processing is not started.\n\n
 
 @see Use cancelProcessing to cancel an image processing operation if necessary.
 */
-(int) processImage: (kfxKEDImage *) imageToProcess withConfiguration: (KFXImageProcessorConfiguration *) configuration;


// ====================================================
//! Use the quick analysis method to check image quality.
/**
 Use this method to specify the image upon which you want to perform a quick analysis.  The image processor will check image quality and determine the page edges of a document in the image.\n
The doQuickAnalysis method does not use a profile.  The library uses an internally generated opString, and ignores the basic settings profile and the image perfection profile set in the image processor object.\n
License Required: this is a licensed method.  You cannot use this method until you have set a valid SDK license. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object.  An example of setting your license can be found in the licensing class.\n

The method returns KMC_SUCCESS if the process starts without any error.  In this case you should expect multiple analysis process progress delegate calls to indicate the progress of the analysis.  You should never make any assumptions about completion of the process when you get to 100% completion, because the library performs several post process steps and then calls the analysisComplete delegate.  You should always check the status in the analysis complete delegate to know if the process completed without error.\n
If the call to doQuickAnalysis method does not return KMC_SUCCESS, then the library will not have stored the kfxKEDQuickAnalysisFeedback object, and you will not receive any progress delegate calls nor a analysisComplete delegate call.  Therefore, you should always check the return value to make sure you have correctly initialized objects for the process and analysis starts up ok.\n
Quick analysis always returns a kfxKEDImage in the analysisComplete delegate, and this is a reference to the same input image given to quick analysis with the imageToAnalyze parameter. When Quick Analysis completes without error, it stores a kfxKEDQuickAnalysisFeedback object in the input image for your use.  If you request a reference image, by setting the generateRefImage to true, then the library returns a UIImage reference in the kfxKEDQuickAnalysisFeedback object.\n
Quick Analysis Results are always stored in the kfxKEDQuickAnalysisFeedback object in the input image specified with the imageToAnalyze parameter.  Then you can decide what to do with the results.  You should examine the various settings in the kfxKEDQuickAnalysisFeedback object, to see if the image is blurry, over saturated, under saturated or not. The library also sets the bounding tetragon corners and side equasions for the page boundaries in the feedback object and the metadata. Then if the image looks good, you can also display the reference UIImage * if you requested one.  You could display this image for user confirmation, and then a new picture could be taken if the user decides he doesn't like the results, or the green bordered image of the page seems incorrect.\n
Otherwise, if your user accepts the image, you could then process the image using a standard processImage call.  When you do so, if you want to crop to the page detection referenced by the quick analysis process, you should use a basic settings profile, and set the doCrop setting to KED_CROP_WITH_QUICK_ANALYSIS_RESULTS, and your image processing will complete sooner than if you did normal processing because the library already knows the page boundaries.\n
Note: The library ignores any supplied profiles and uses internal settings instead.  This data is returned in the quick analysis feedback object in the input imageToAnalyze object.\n
 The analysisComplete delegate returns your input image, and everything in it is retained.\n
 When the processing completes normally, the library sets the following image object properties:\n
 imageQuickAnalysisFeedback, set to an object created by the analysis, indicating the results, and a reference image if requested.
 imageMetaData, to the quick analysis metadata created by the image processor for quick analysis.\n
 Quick analysis generates large autorelease objects. If this method is to be called many times, it is recommended to wrap the calls with @autoreleasepool directive.\n
 
 @param imageToAnalyze the actual input image object that you want to check
 @param generateRefImage is a bool, when set to true, causes the image processor to return a native UIImage object.  This image incluces a green border around the page boundaries.  You can use this image to detect the correct orientation and edges, to decide if the image should be used for further processing or not.
 @return This method returns KMC_SUCCESS when image processing started without error.  Otherwise it may return one of these error codes if processing was not started.  No delegates are generated if the method returns an error.\n
 KMC_IP_LICENSE_INVALID if you have not set a valid license yet.
 KMC_ED_NOIMAGE  If you did not include an image in the input image object.\n
 KMC_ED_FILEPATH If the image object is represented by a file, but the file path is missing.\n
 KMC_ED_NONEXISTENT_FILE If the file name in the input object was specified so that the image representation is set to IMAGE_REP_FILE, an then the file used to represent the image is later deleted. The the library returns this error if you try to process it.\n
 KMC_IP_NO_REPRESENTATION If the image representation in the input image object is invalid, and not set to IMAGE_REP_FILE, or IMAGE_REP_BITMAP or BOTH.  This indicates that there is no image to process.  This is returned even if you set a file path to a non-existant file.\n
 KMC_ED_NO_MEMORY_FOR_METADATA if memory could not be allocated to store image metadata.\n
 KMC_ED_IMAGE_COLOR_SPACE If the library could not create a color space reference, usually a system resource issue.\n
 KMC_ED_IMAGE_CONTEXT, If an image bitmap could not be created, normally caused by a resource issue.\n
 @see Use cancelProcessing to cancel an ongoing quick analysis process if necessary.
 */
-(int) doQuickAnalysis: (kfxKEDImage *) imageToAnalyze andGenerateImage: (bool) generateRefImage;
-(int) doQuickAnalysis: (kfxKEDImage *) imageToAnalyze andGenerateImage: (bool) generateRefImage withSettings: (kfxKEDQuickAnalysisSettings*) settings;


// ====================================================
//! Use the cancel processing method to stop image processing.
/**
 Use the cancelProcessing method to cancel an image processing operation that is underway.  In, this way, the app can respond to low-memory events or, for any reason, the app user manually stops processing while the image is being processed in background.   To do this, asynchronously call a cancel method in the Image Processor engine.  Note that there may be a delay between cancelling and the imageOut delegate because the image processor will only cancel the balance of processing tasks on functional boundaries.  The image out event will indicate that the processing was cancelled if the image processing operation was incomplete.\n\n
 
 The library ignores the cancelProcessing call if the operation has already completed or hasn't started yet.  If you cancel processing beforehand, the library will not cancel immediately if you then call processImage.\n\n
 
 Background image processing and the cancel operation are both asynchronous. Depending on the current percentage last reported by the progress delegate, the image processing operation may be nearly complete. Therefore, the library may not necessarily cancel an operation, and the cancel error status may not occur.  If the operation is cancelled, the imageOut delegate will indicate the KMC_EV_USER_ABORT status.  In this case, there will be no image object included with the imageOut delegate. \n\n
 
 The cancelProcessing method will cancel either a quick analysis or an image processing operation.
 
 */
-(void) cancelProcessing;

// ====================================================
//! Begin an AppStats session.
/**
 This method begins a new AppStats session. It creates a new instance object and initializes it
 with the current time. In combination with SessionDismiss, it allows specified log information
 to be bracketed with begin and end times.
 */
- (void) SessionCreate;

// ====================================================
//! End an AppStats session.
/**
 This method ends an AppStats session. It updates a previously created instance object with a
 dismissal time.
 */
- (void) SessionDismiss;


@end

#endif

