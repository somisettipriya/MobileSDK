//
//  API Reference
//  kfxKUTVoiceover.h
//  Framework: kfxLibUtilities
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <AVFoundation/AVFoundation.h>

//! Accessibiity support.
/**
 Use the Voiceover class for checking for the existience of voiceover, and for calling speech synthsis explicity.
 */
@interface kfxKUTVoiceover : NSObject

// ===================================================
//! Get Singleton instance
/**
 Methods and properties of this class should be accessed using the sharedInstance class method to get back a Singleton object.  This will ensure that only once instance of the speech synthesizer is running, and speaking a phrase will immediately stop the previous phrase.
 */
+ (instancetype)sharedInstance;

// ===================================================
//! Determine if voiceover (acessibility) is active or not
/**
 This method can be called to determine if iOS system voiceover is enabled.  An application can call this to decide if it should play any unsolicited voice messages using the speakPhrase method.
 */
- (BOOL)isVoiceoverActive;

// ===================================================
//! Uses the built-in speech synthesizer to speak a phrase
/**
 This method allows the application a means of calling the internal speech synthesize to speak a phrase, to support voiceover enabled applications.  Although the voiceover system will automatically speak words on the screen for controls that the user can interact with, such as buttons, there are times when an application may want to play an unsolicated spoken message.  In this case, the normal workflow will be to call isVoiceoverActive to see if it is enabled, and then if so, make the call to speakPhrase.   Calling speakPhrase will immediately terminate the previous phrase if it is still in the process of being spoken, and speak the new phrase.
 
 @param phrase is the message to be spoken.
 */
- (void)speakPhrase:(NSString*)phrase;

// ===================================================
//! Stop the current phrase being spoken
/**
 This method can be called to immediately stop a currently speaking phrase, if any.
 */
- (void)stopSpeaking;

@end
