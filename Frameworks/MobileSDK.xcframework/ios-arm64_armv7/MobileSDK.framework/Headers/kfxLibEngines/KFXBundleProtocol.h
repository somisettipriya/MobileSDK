//
//  KFXBundleProtocol.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#ifndef KFXBUNDLEFILEPROTOCOL
#define KFXBUNDLEFILEPROTOCOL 1

#import <Foundation/Foundation.h>

//! Bundle file protocol
/**
 This class represents a single file inside a corresponding bundle.

 @see KFXBundleProtocol
 */
@protocol KFXBundleFileProtocol<NSObject>

//! Is directory
/**
 Indicates if the file is a directory.
 
 @return YES if file is a directory and NO otherwise.
 */
- (BOOL)isDirectory;

//! Get path to file
/**
 This method allows to obtain default path to file.
 Default implementations write files to application's temporary directory.
 This path may be overwritten by other files during bundle enumeration. If file is needed to be stored for future usage, use writeFileToPath: method.
 
 @param error - will contain error if there is any.
 @return path to file.
 */
- (NSString*)getFilePathWithError:(NSError**)error;

//! Write file to specified path
/**
 This method allows to write file to a custom path.
 
 @param path - custom path to the file.
 @param error - will contain error if there is any.
 */
- (void)writeFileToPath:(NSString*)path error:(NSError**)error;

//! Absolute file path
/**
 The absolute path within whatever storage container this file resides.
 
 @return absolute path to file.
 */
- (NSString*)absolutePath;

//! File name
/**
 File name without any path information.
 
 @return file name.
 */
- (NSString*)name;

@end


//! Bundle protocol
/**
 This protocol represents a generic collection of KFXBundleFileProtocol. Used to unify interaction between different containers like archives or bundles and file system.

 @see KFXBundleFileProtocol
 */
@protocol KFXBundleProtocol<NSObject>

//! Iteration through bundle contents
/**
 This methods allows to iterate through this bundle contents.
 
 @param block - enumeration callback:
    - file: current file. May be nil in case of an error.
    - stop: allows to stop iteration.
    - error: will contain an error if there is an error during iteration.
 */
- (void)enumerateUsingBlock:(void (^)(id<KFXBundleFileProtocol> file, BOOL* stop, NSError* error))block;

@end

#endif
