//
//  KFXServerExtractionParameters.h
//  kfxLibLogistics
//
//  Copyright (c) 2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import <Foundation/Foundation.h>


@interface KFXServerExtractionParameters : NSObject

//! server parameters
/**
 This contains the parameters that are to be sent in the request to server as part of the request header.
 For example, If the connection is RTTI then the 'x' parameters need to be sent as key-value pairs using this dictionary.
 If the connection is KTA, below are the recommendations.
 Parameters for KTA : The parameters dictionary supports the following key-value pairs: "DocumentName","DocumentTypeID","FilePath","FolderId","FolderTypeId","ReturnFullTextOcr" in the Documents section. "ReturnAllFields" is set to true always and hence there is no support for the key "RunTimeFields"
 Keys "sessionID" - retrieved from successful login to KTA server
 "processIdentityName" - the name of the process identity. For example, KofaxMobileIDSync.
 "startDate" and "storeFolderAndDocuments" are supported.
 
 KTA API : you can add a key "syncProcessMap" which takes a boolean value to specify the KTA API to be used. Two main APIs are supported i.e. CreateJobSyncWithDocuments and CreateJobWithDocumentsAndProgress2. If the value is set to true, "CreateJobSyncWithDocuments" is used and if it is set to false "CreateJobWithDocumentsAndProgress2" is used. On a general note, extraction uses "CreateJobSyncWithDocuments". So it is recommended to set this value true for extraction. If this key is not added, a default true value is assumed.
 
 If the response from the server needs to contain certain variables you can set the key "variablesToReturn" and values as array of strings.
 For example, [parameters setObject:[NSArray arrayWithObjects:@"VariablesToReturn1",@"VariablesToReturn2",nil] forKey:@"variablesToReturn"]; Then these variables are added to the request. Please refer to KTA Server documentation for different supported variables.
 All other keys are treated as InputVariables. Hence it is highly recommended not to add any unwanted keys other than above specified for successful extraction.
 
 Please read the Server (SMC) documentation for more information on needed parameters for successful extraction.
 
 Default value is nil.
 */
@property(nonatomic,strong)NSDictionary* parameters;

//! image array parameter
/**
 Allows to get imageArray.
 
 Default value is nil.
 */
@property (nonatomic,readonly,strong)NSArray* imageArray;

//! image byte array parameter
/**
 Allows to get imageByteArray.
 
 Default value is nil.
 */
@property (nonatomic,readonly,strong)NSArray* imageByteArray;

//! Constructor
/**
 This method allows to specify images to be sent for extraction
 
 @param imageArray - array containing kfxKEDImage objects
 @see kfxKEDImage
 
 */

-(instancetype)initWithImages:(NSArray*)imageArray;

//! Constructor
/**
 This method allows to specify images in byte format (NSData*) to be sent for extraction
 
 @param imageByteArray - array containing NSData byte objects
 
 */
-(instancetype)initWithImageBytes : (NSArray*)imageByteArray;
@end
