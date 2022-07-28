//
//  kfxKUTLocalization.h
//  kfxLibUtilities
//
//  Copyright (c) 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface kfxKUTLocalization : NSObject

+ (NSString *) getLocalizedString: (NSString *) key withDefault: (NSString *)defaultString;


@end
