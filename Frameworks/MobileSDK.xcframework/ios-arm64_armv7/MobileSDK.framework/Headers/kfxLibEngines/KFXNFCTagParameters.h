//
//  KFXNFCTagParameters.h
//  kfxLibEngines
//
//  Created by SIVASANKAR YATHIRAJULA on 20/07/20.
//  Copyright © 2020 Mark Day. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface KFXNFCTagParameters : NSObject

/// A string value of id number.
/**
 * A id number need to passed in Tag parameters. By default id number is empty.
 */

@property (nonatomic, strong) NSString* idNumber;

/// A string value of expiration date.
/**
 * The xpiration date of document and should be in "YYDDMM" format. By default expiration date is empty.
 */

@property (nonatomic, strong) NSString* expirationDate;

/// A string value of date of birth.
/**
 * The date of birth should be in "YYDDMM" format. By default date of birth is empty.
 */

@property (nonatomic, strong) NSString* dateOfBirth;

//A string value of Master List file path
/**
 * Need to pass file path of master list where it contains all countrys certificates and file type should be .pem type.
 */
@property (nonatomic, strong) NSString* masterListFilePath;

@end

