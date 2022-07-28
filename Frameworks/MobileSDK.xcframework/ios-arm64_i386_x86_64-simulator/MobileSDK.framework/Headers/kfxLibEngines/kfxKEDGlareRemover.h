//
//  kfxKEDGlareRemover.h
//  kfxLibEngines
//
//  Created by Kofax on 09/05/19.
//  Copyright © 2019 Mark Day. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "kfxKEDImage.h"


@interface kfxKEDGlareRemover : NSObject

// API to remove glare on the images that are passed in.
/**
 User calls this method to remove glare using the passed in images\n
 
 @param imageArray : An array of @Link kfxKEDImage. Should pass in two of these objects captured at different angles so that glare would be distributed at different places. Of these, the reference image that user wants to perform glare removal should be passed as the first object of the array.
 @param code : Will contain the success/error code.
 @return This metod returns a glare free image.
 */

-(kfxKEDImage*)removeGlare:(NSArray<kfxKEDImage*>*)imageArray errorCode:(int*)code;

// API to get the glare fraction for a given image
/**
 User calls this method to get the amount of glare on an image\n
 
 @param image : image that should be passed to get the glare fraction.
 @return This metod returns glare fraction.
 */

-(double)getGlareFraction:(kfxKEDImage*)image;

@end

