//
//  API Reference
//  kfxUIControls.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import <kfxLibUIControls/kfxKUIImageCaptureControl.h>
#import <kfxLibUIControls/kfxKUICaptureExperienceData.h>

//! This class is a base class for the animation experience
/**
  */

@interface kfxKUICaptureExperience : NSObject<kfxKUIImageCaptureControlDelegate>

-(void)stateChanged : (kfxKUICaptureExperienceData*)data;


@end
