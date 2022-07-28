//
//  kfxUICaptureMessage.h
//  kfxLibUIControls
//
//  Copyright (c) 2014 - 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


//! This class renders the messages on the Imagecapturecontrol
/**
 This class is responsible for rendering the messages on the Imagecapturecontrol. It allows the attributes of the messages to be configured and hence enhance the visual feedback to the user.
 
 The messages are sub views of Image Capture Control. If you have custom sizes for the control and see that messages are out of the control due to the size you can configure imagecapturecontrol clipsToBounds property to YES.
 
 Objects which present kfxKUICaptureMessage objects as properties may initialize default messages with settings different than the defaults documented here.
 */

@interface kfxKUICaptureMessage : NSObject


/// The color used to display the text
/**
 Specifies the color that the message's text will be rendered with.
 
 The default color is white.
 */
@property(nonatomic,strong)UIColor* textColor;

/// The color used to display the background of the message
/**
 Specifies the color that the message's background will be rendered with.  The full area specified by the size property will be filled with the background color, excluding areas clipped outside of view bounds.
 
 If backGround is set, the backGroundColor will be ignored.
 
 The default background color is transparent.
 */
@property(nonatomic,strong)UIColor* backGroundColor;

/// The font used to display the text
/**
 Specifies the font and size that the message's text will be rendered with.
 
 The default font is size 20 HelveticaNeue.
 */

@property(nonatomic,strong)UIFont* font;

/// The text of the message
/**
 Specifies the text of the message.
 
 The default message is the empty string.  You must set a message for anything to be displayed.
 */
@property(nonatomic,strong)NSString* message;

/// The postion (center) of the text message
/**
 The message object will be overlayed on top of an Image Capture Control with the center of the message being located at this coordinate.  Changes in the size of the capture control will usually require updating the position of the message as well.
 
 The default position is (0,0), which will render most of the message outside of the view boundaries.  You must set an appropriate position for your message.  If no position is explicitly set, some managers of message objects may treat it as an "auto" position and dynamically pick a position suitable for the parent view.  Once a position is set, this auto quality will be lost.

 @see size
 */
@property(nonatomic)CGPoint position;

/// The Size of the text message
/**
 The message object will be rendered with dimensions specified by this property.  Text will be contained within this boundary, and any set background color will completely cover this area.
 
 The default size is (150, 40), appropriate for small labels.  This default is somewhat arbitrary, and you should set a size appropriate for your message content and the size of the control it will be displayed over.
 
 @see position
 @see backGroundColor
 */

@property(nonatomic)CGSize size;

/// The visibility of the message
/**
 Specifies whether the message is visible or not.  A value of "YES" or "true" will prevent the message from appearing.  A value of "NO" or "false" will show the message, if there is nothing else to prevent it from appearing.
 
 The default value is NO.  Some objects that use messages, like the capture experience objects, will automatically manage and update this state.
 */

@property(nonatomic)BOOL hidden;


//! An enumeration to control the orientation of the messages
/**
 Use one of the values of this enumeration to set the orientation of the messages displayed. Once a mode is set they stay in that mode even if the device rotates. In other words, this orientation set is sticky. If you want to handle the rotation when device rotates, orientation has to be explicitly set again on the respective message.
 */
typedef enum
{
    kfxKUIMessageOrientationPortrait = 1,
    kfxKUIMessageOrientationPortraitUpsideDown = 2,
    kfxKUIMessageOrientationLandscapeLeft = 3,
    kfxKUIMessageOrientationLandscapeRight = 4
   
    
} kfxKUIMessageOrientation;


/// Variable to take wanted orientation
/**
 Set one of the values in the enum kfxKUIMessageOrientation to set a sticky orientation.
 The default value would is kfxKUIMessageOrientationLandscapeLeft.
 
 @see kfxKUIMessageOrientation
 */


@property(nonatomic)kfxKUIMessageOrientation orientation;

/// The sequence of images for animation
/**
 Specifies an array of images used to show an animation, in addition to the text message. The animation is a repeating sequence of images.
 By default is nil and no animation will be displayed.
 */

@property (nonatomic, strong) NSArray* messageIcons;

/// The background image of the message
/**
 Specifies the background image that the message will be rendered with. If the value is set, it will override backGroundColor. The image will be scaled with aspect to fill the message view.
 The default value is nil and backGroundColor will be used instead.
 */
@property (nonatomic, strong) UIImage* backGround;

@end
