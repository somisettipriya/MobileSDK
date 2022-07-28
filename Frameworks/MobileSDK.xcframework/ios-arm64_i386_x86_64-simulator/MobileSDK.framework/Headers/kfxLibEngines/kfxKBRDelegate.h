//
//  kfxKBRDelegate.h
//  kfxLibEngines
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKEDImage.h"

@class kfxKBRBarcodeReader;

//! This protocol must be implemented by classes whose objects are used as kfxKBRBarcodeReader delegates
/**
 This defines protocol messages that will be sent to kfxKBRBarcodeReader delegate objects.
 */
@protocol kfxKBRDelegate<NSObject>

@optional

//! A message that indicates barcode recognition has finished.
/**
 Once started, the barcode reader will search for all barcodes matching the desired criteria as a background
 task.  After the reader has finished its search, it will send this message with the error status and original
 image being searched.  This message will be sent even if no barcodes are discovered.
 
 Any discovered barcodes will be populated into the imageBarCodes property of the kfxKEDImage as 
 kfxKEDBarcodeResult objects.
 
 @param  barcodeReader  The current instance of a barcode reader.
 @param  status : Set to KMC_SUCCESS if no error occurred, otherwise an error code.
 @param  statusMsg : A description of the error that occurred.
 @param  kfxImage : An output image reference when image processing completed without error.
 
 @see kfxKEDBarcodeResult
 */
- (void) barcodeReader: (kfxKBRBarcodeReader*) barcodeReader status:(int)status statusMsg:(NSString*) statusMsg image: (kfxKEDImage*) kfxImage;

@end
