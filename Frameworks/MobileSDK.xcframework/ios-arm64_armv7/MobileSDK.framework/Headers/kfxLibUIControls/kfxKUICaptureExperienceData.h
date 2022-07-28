//
//  API Reference
//  kfxUIControls.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKEDBoundingTetragon.h"
#import  <UIKit/UIKit.h>

@interface kfxKUICaptureExperienceData : NSObject

@property (nonatomic)int stability;
@property (nonatomic)int pitch;
@property (nonatomic)int roll;
@property (nonatomic)BOOL focused;

-(void)clearData;

@end
