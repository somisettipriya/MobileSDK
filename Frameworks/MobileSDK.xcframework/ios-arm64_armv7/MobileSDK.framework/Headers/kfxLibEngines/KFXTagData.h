//
//  KFXPassportDetails.h
//  NFCExtractor
//
//  Created by SIVASANKAR YATHIRAJULA on 19/05/20.
//  Copyright © 2020 SIVASANKAR YATHIRAJULA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KFXMRZResult.h"



@interface KFXTagData : NSObject

/// The mrz result.
/**
 * This mrz result will have information like document code, issuing code, given name and document number etc.
 */

@property (nonatomic, strong) KFXMRZResult* mrzResult;

/// The face image.
/**
 * This contains the high quality face image which is available in NFC chip.
 */

@property (nonatomic, strong) UIImage* faceImage;


/// NSData value contains document secuirty object data.
/**
 * This will return the documentSecurityObject from the Passport and will be used to do a certificate validation externally.
 */

@property (nonatomic, strong) NSData *documentSecurityObject;

@end


