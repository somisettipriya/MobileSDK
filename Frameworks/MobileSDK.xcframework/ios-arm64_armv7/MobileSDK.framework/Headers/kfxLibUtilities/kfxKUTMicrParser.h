//  Kofax Mobile Capture API Reference File
//
//  kfxKUTMicrParser.h
//
//  Copyright (c) 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKUTMicrLine.h"

@interface kfxKUTMicrParser : NSObject

//! Initializes a new object using the specified MICR string.
/**
 This method is provided to instantiate this object and decode the provided MICR string. An example follows:
 @code
 NSArray *fieldTypeArray = nil;
 kfxKUTMicrParser *theMicrData = nil;
 theMicrData = [[kfxKUTMicrParser alloc] initWithMicr: micrString];
 @endcode
 */
- (instancetype) initWithMicr: (NSString *)micrString;

// ===================================================
//! Parses an input MICR string and sets the object properties with the MICR data.
/** This method parses the provided MICR string and sets the object properties with the components of the MICR.
 */
- (void) parseMicr: (NSString *)micrString;

// ===================================================
//! Returns the account number.
/** This method returns the onUs string when this method is called.
 */
- (NSString *) getAccountNumber;

// ===================================================
//! Returns the check number.
/** This method chooses either auxiliaryOnUs or onUs2 to return as the check number. The auxiliaryOnUs string is returned if set. Otherwise onUs2 is returned.
 */
- (NSString *) getCheckNumber;

// ===================================================
//! Returns the transit number.
/** This method returns the transit number from the parsed Micr Line.
 */
- (NSString *) getTransitNumber;

// ===================================================
//! Returns the type of check.
/** This method returns an enum indicating whether the check was a business or personal check..
 */
-(KUTCheckType) getCheckType;

// ===================================================
//! Returns a value indicating if any micrLine fields have been set.
/** This method returns a Boolean value of YES if any of the micrLine fields have been set. If NO, the micrLine string could not be extracted and\or parsed.
 */
- (BOOL) getValueSet;

// ===================================================
//! Returns the micrline object.
/** This method returns the associated instance of the kfxKUTMicrLine object.
 */
- (kfxKUTMicrLine *) getMicrLine;

// ===================================================
//! Returns validity of parsed micr line.
/** This method returns a flag indicating the provided MICR string was valid.
 */
- (BOOL) isMicrValid;

@end
