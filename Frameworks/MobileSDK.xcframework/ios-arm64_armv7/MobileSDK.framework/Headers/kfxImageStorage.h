//
//  API Reference
//  kfxImageStorage.h
//  MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <UIKit/UIKit.h>

//! The image storage interface.
/**
 This abstract singleton class provides the interfaces for image storage. Actual storage type (memory, disk, etc.) may vary depending on the implementation details.
 
 Current implementation provides in-memory storage of maximum capacity 5. Images are poped from the storage in FIFO style - earlier image will be deleted first.
 */
@interface kfxImageStorage : NSObject

//! This method allows to obtain image storage instance.
/**
 This method should be called to get kfxIImageStorage instance.
 */
+ (kfxImageStorage*)sharedStorage;

//! This methods allows to generate image identifier.
/**
 Generates unique string id on each call.
 
 @return Generated id.
 */
+ (NSString*)generateId;

//! This methods allows to add an image to the storage.
/**
 Image should be provided along with string identifier, which will be used to get the image from the storage. Identifier should not be nil or empty string.
 If the storage already contains an image with specified id, it will be replaced.
 If image is nil and an image with imageId exists, it will be removed from the storage.
 If imageId is nil or empty, image storage will not be changed.
 
 @param image  Image to be stored.
 @param imageId  Image id.
 */
- (void)setImage:(UIImage*)image forId:(NSString*)imageId;

//! This method allows to get the image from the storage.
/**
 Image identifier should not be nil.
 
 @param imageId  Image id.
 @return Returns image if it exists in the storage and nil otherwise.
 */
- (UIImage*)getImageForId:(NSString*)imageId;

@end
