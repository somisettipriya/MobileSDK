//
//  KFXNFCExtractor.h
//  NFCExtractor
//
//  Created by SIVASANKAR YATHIRAJULA on 19/05/20.
//  Copyright © 2020 SIVASANKAR YATHIRAJULA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KFXTagData.h"
#import "KFXNFCTagParameters.h"


@interface KFXNFCTagReader  : NSObject

// API to get data from the NFC chip which is avilable on passport.
/**
 User calls this method using @Link KFXNFCTagParameters to get the data\n
 
 @param parameters : A @Link KFXNFCTagParameters should pass to this API which contains idNumber, expirationDate and dateOfBirth which are available on passport.
 @return This metod returns a @Link KFXTagData which will have information of MRZ data along with face image.
 */

-(void)readTagWithParameters:(KFXNFCTagParameters*)parameters completionHandler:(void(^)(KFXTagData * tagData, int errorCode))completionHandler;

// API to validate certificate data with master list.
/**
 User calls this method to validate certificate available in the NFC chip of passport\n
 
 @param parameters : A documentSignerCertificateData should pass to this API.
 @param parameters : A master list file path should pass to this API which should be .pem format.
 @return This metod returns isCertificateValid true when it matches certificae in the master list otherwise returns false if certificate is expired or not matched in master list.
 */

-(void)verifyDocumentSecurityObject:(NSData*)documentSecurityObject masterListPath:(NSURL*)masterListPath completionHandler:(void(^)(BOOL isCertificateValid, int errorCode))completionHandler;

@end

