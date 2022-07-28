//
//  kfxKLOServerExtractor.h
//  kfxLibLogistics
//
//  Copyright (c) 2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>

@class KFXServerExtractionParameters;
@protocol KFXServerConnectionProtocol;



//! Server Extraction Protocol
/**
 The KFXServerExtractorDelegate defines the protocol for the delegate Server Extractor calls during extraction.
 */

@protocol KFXServerExtractorDelegate<NSObject>

@required

//! Extraction Results delegate method
/**
 This method is called when the extraction is completed and provides the extraction results.
 
 The implementation of this method is required.
 
 @param extractionData : a extractionData object with extraction results data. data can be either JSON data or XML data depending on the server that extracted the data. Generally all SMC projects BillPay and Mobile ID projects return JSON data
 
 @see kfxKLOServerExtractor
 */
-(void)extractionSucceded:(NSData*)extractionData response:(NSURLResponse *)response;


//! Extraction Results delegate method
/**
 This method is called when the extraction is failed and provides the error
 
 The implementation of this method is required.
 General recommendation is to first look for the response code and if it is anything other than 200 (HTTP success), then look for errorData and the message in it and then look for error object to see any further errors.
 
 @param error : a NSError object which indicates the reason for the extraction failure. It can range from network errors to erros on the server due to quality of images and other internal server errors if any
 @param data : Sometimes Server sends a JSON error response and not necessarily a error object. In such cases, the entire error message would be in the data object.
 
 @see kfxKLOServerExtractor
 */
-(void)extractionFailed : (NSError*)error response:(NSURLResponse *)response errorData:(NSData*)data;

@end


@interface kfxKLOServerExtractor : NSObject

//! KFXServerExtractorDelegate notifies about extraction completion
/**
 This delegate must be set in order for your app to receive delegate calls.

 @see KFXServerExtractorDelegate
 */
@property(nonatomic, weak) id<KFXServerExtractorDelegate> delegate;


//! Constructor for custom request provider
/**
 This constructor allows to specify custom request provider to be used to get extraction results.
 
 @param requestProvider - a request provider instance which conforms to KFXServerConnectionProtocol protocol.

 @see KFXServerConnectionProtocol
 */
-(instancetype)initWithConnection : (id<KFXServerConnectionProtocol>)requestProvider;

//! Use this method to start extraction
/**
 This method starts the extraction with specified extraction parameters.
 Parameters will be verified before the extraction. In case of invalid parameters an appropriate error will be returned via delegate.
  
 @param parameters - a KFXServerExtractionParameters object with extraction parameters.
 
 @see KFXServerExtractionParameters
 @see KFXServerExtractorDelegate
 */

-(void)extract : (KFXServerExtractionParameters*)parameters;

//! Use this method to cancel the extraction.
/**
 If this method is called during the extraction, extractionResults:error: method of the KFXServerExtractorDelegate will be called, containing NSError object which represent cancel extraction error.If there is no error it will be nil.When the callback is received, you may start new extraction.
 
 If new extraction is started before receiving extractionResult callback, the behavior is undefined.

 @see KFXServerExtractorDelegate
 */
-(void)cancelExtraction;

@end
