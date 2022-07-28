//
//  kfxKBRBarcodeReader.h
//  kfxKBRBarcodeReader
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.

#import <Foundation/Foundation.h>
#import <kfxLibEngines/kfxKEDImage.h>
#import "kfxKBRDelegate.h"

//! An enumeration containing the different possible barcode search directions
/**
 One or more of these values can be passed to a kfxKBRBarcodeReader instance to restrict
 the directions that are searched for barcodes.
 */
typedef enum {
    KBR_LEFT_RIGHT = 1 << 0,
    KBR_RIGHT_LEFT = 1 << 1,
    KBR_TOP_DOWN = 1 << 2,
    KBR_BOTTOM_UP = 1 << 3,
    KBR_ALL = KBR_LEFT_RIGHT | KBR_RIGHT_LEFT | KBR_TOP_DOWN | KBR_BOTTOM_UP
}KBRSearchDirections;

//! An enumeration containing the different barcode symbologies that can be detected
/**
 One or more of these values can be passed to a kfxKBRBarcodeReader instance to restrict
 search to those symbologies.
 */
typedef enum {
    kfxKBRcode128 = 1,
    kfxKBREan = 2,
    kfxKBRUpc = 3,
    kfxKBRCode39 = 4,
    kfxKBRCode25 = 5,
    kfxKBRCodabar = 6,
    kfxKBRPdf417 = 7,
    kfxKBRQRCode = 8,
    kfxKBRCode93 = 9,
    kfxKBRPostnet = 10,
    kfxKBRDataMatrix = 11
}KBRSymbologies;


//! The barcode recognition engine
/**
 Create an instance of this class to perform barcode recognition on a standalone image.  The engine can be configured
 to search for a specific subset of barcode symbologies, barcodes oriented in particular directions, and a maximum
 number of barcodes to return.  For best performance, each of these criteria should be restricted as much as possible.
 
 Any barcode results found will be populated in a property on the input kfxKEDImage object, and the engine will fire
 an event through the engine's delegate when recognition is completed or fails.
 */
@interface kfxKBRBarcodeReader : NSObject

//! A delegate to receive messages from the control
/**
 A property to get or set the delegate that will be notified of progress events and barcode results.
 You must set this delegate to a valid handler in order to receive results.
 
 @code
 // The class manipulating the kfxKBRBarcodeReader object implements the kfxKBRDelegate protocol.
 barcodeReader.delegate = self;
 @endcode
 */
@property (atomic, assign) id<kfxKBRDelegate> delegate;

//! The set of symbologies currently being searched for.
/**
 Each symbology represents a class of barcodes, like UPC or PDF417.  A class may
 match multiple subtypes, such as UPC-A and UPC-E within the UPC symbology.
 
 Searching for multiple symbologies slows down the speed of barcode recognition.
 You should only specify the symbologies that you are interested in reading.  The
 set of selected symbologies is empty by default.
 
 It is an error to search for barcodes with no symbologies selected.
 
 @code
 // Objective-C
 barcodeReader.symbologies = @[@(kfxKBRCode39), @(kfxKBRPdf417)];
 
 // Swift
 barcodeReader.symbologies = [Int(kfxKBRCode39.rawValue), Int(kfxKBRPdf417.rawValue)]
 @endcode
 
 @see KBRSymbologies for all supported values.
 */
@property (nonatomic, strong) NSArray* symbologies;

//! The set of directions currently being searched for barcodes.
/**
 Searching multiple directions slows down the speed of barcode recognition.  If you
 expect barcodes to only be oriented in certain directions, you should specify only
 those directions.  By default, all directions will be searched.
 
 Multiple directions can be combined using the bitwise-or operator.  The direction
 KBR_ALL is the same as specifying the combination of all other directions.
 
 It is an error to search for barcodes with no directions selected.
 
 @code
 // Find barcodes that read from left to right across the image.
 barcodeReader.searchDirection = KBR_LEFT_RIGHT;
 // Find barcodes that read left to right or top to bottom.
 barcodeReader.searchDirection = KBR_LEFT_RIGHT | KBR_TOP_DOWN;
 // Find barcodes with a horizontal direction.
 barcodeReader.searchDirection = KBR_LEFT_RIGHT | KBR_RIGHT_LEFT;
 @endcode
 
 @see KBRSearchDirections for all supported values.
 */
@property (nonatomic) KBRSearchDirections searchDirection;

//! The maximum number of barcode results to search for.
/**
 Set this value to the maximum number of barcodes you expect to find in the target image.
 
 Searching for more barcodes than exist in a document will cause the reader to fully exhaust
 its search space, resulting in slower recognition times.
 */
@property (nonatomic) int maxBarcodes;

//! Scans a kfxKEDImage for barcodes when called.
/**
 Pass in a kfxKEDImage to have the barcode reader search for barcodes.
 
 This method is asynchronous, and will return when the recognition process is started.  Results and status codes will
 be returned through an event in the reader's delegate.  Any located barcodes will be automatically populated into the
 imageBarCodes property of the image object that was initially supplied to this method.
 
 This feature requires a valid SDK license.  For feature-based SDK licenses, the Barcode Capture feature must be enabled.

 @param     image   The image to search for barcodes.
 
 @retval    KMC_SUCCESS             Recognition was started without error.
 @retval    KMC_BC_BUSY             The engine hasn't finished its previous readBarcodes operation.
 @retval    KMC_BC_NO_DIRECTIONS    No directions were specified in the searchDirection property.
 @retval    KMC_BC_NO_SYMBOLOGIES   No symbologies were specified in the symbologies property.
 @retval    KMC_ED_NOIMAGE          The supplied image was nil or invalid.
 @retval    KMC_BC_IMAGE_BUFFERED   The supplied image has a FILE_BUFFERED representation, which is not supported.
 @retval    KMC_ED_FILEPATH         The supplied image has a FILE representation for an invalid path.
 @retval    KMC_ED_NONEXISTENT_FILE The supplied image has a FILE representation and doesn't exist at the specified path.
 @retval    KMC_BC_INVALID_IMAGE    The supplied image was invalid.
 @retval    KMC_UT_LICENSE_BARCODE_CAPTURE  The SDK is not licensed for this feature.
 */
- (int) readBarcodes: (kfxKEDImage*) image;

@end
