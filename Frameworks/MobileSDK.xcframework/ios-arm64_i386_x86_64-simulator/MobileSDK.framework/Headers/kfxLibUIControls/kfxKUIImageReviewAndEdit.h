//
//  API Reference
//  kfxKUIImageReviewAndEditNew.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <UIKit/UIKit.h>
#import "kfxKUICommon.h"

@class kfxKEDImage;
@class kfxKEDBoundingTetragon;

//! Displays an image for review, and an optional crop rectangle/tetragon for a user to manually adjust the page boundaries.
/**
The Image Edit and Review Control object provides a means for the application to display an image (processed or unprocessed) for review and/or edit purposes. The actual image processing operation that “edits” the image according to the user’s preferences is performed separately by the application using the ImageProcessing object.  The two main features supported in this image view control are zoom and set page boundaries.  Zoom allows the user, via platform specific gestures, to magnify the image in order to see more detail.  Set Page Boundaries provides a UI for setting the boundaries of a selection area (typically the page boundaries) for subsequent cropping and rectangularization by the application upon receiving the coordinates of the bounding rectangle or tetragon through an event.  The application is responsible for creating and displaying any screen overlays which offer user feedback, such as “image blurry”.
 */

@interface kfxKUIImageReviewAndEdit : UIControl
<UIGestureRecognizerDelegate>
{
    
    
}

+(void) initializeControl;

// ==========================================================
//                  P R O P E R T I E S
// ==========================================================


// ==========================================================
//! The crop tetragon specified during edit operations.
/**
 Developer can set the tetragon coordinates to initialize the control before displaying bounding tetragon (crop rectangle), or allow the control to set it to a default. The library returns this crop tetragon while edit is in progress.  After the user closes the view, this object contains the users final corner points after editing is complete. */
@property (nonatomic,strong) kfxKEDBoundingTetragon* cropTetragon;


// ==========================================================
//! Color of lines in cropping rectangle/tetragon.
@property (nonatomic, strong) UIColor * cropLineColor;

// ==========================================================
//! Color of corner handles (circles) in cropping rectangle/tetragon.
@property (nonatomic, strong) UIColor * cropCornerColor;

// ==========================================================
//! Whether crop rectangle lines should be solid or dashed.
@property (nonatomic, assign) kfxUILineStyle cropLineStyle;        


// ==========================================================
//! Color of highlighted areas specified in showHighlights method. If nil is set or highlightColor is not set then default value of Yellow would be used
@property (nonatomic,strong) UIColor *highlightColor;


// ==========================================================
//                  M E T H O D S
// ==========================================================



/// Set image to review.
/** 
 Use the setImage method to load the image to be reviewed.  It also calculates a default crop rectangle (tetragon) based on the size and layout of the imageObjectToReview.   If you want to override the default crop rectangle, change the cropTetragon property prior to calling showCropRectangle. This method will not succeed if a valid image processing license is not set.\n
 
 @param imageObjectToReview This is the kfxKEDImage object to review\n
 The kfxKEDImage object must have an image represented as a bitmap, file or buffered.  If none of these representations are found, then the library returns an error for nothing to display.\n
 
 @return Status\n
 This method returns KMC_SUCCESS if the image was accepted ok, or one of these errors:\n
  - KMC_IP_LICENSE_INVALID (no license found)\n
  - KMC_IP_NO_REPRESENTATION (No image found to display.\n
  - KMC_ED_FILEPATH if the file path is nil
  - KMC_ED_BITMAP_READ_FROM_FILE_FAILED if the image could not be read from the file for FILE_STORED case.
  - KMC_ED_BUFFERED_READ_FAILED, if the file representaton was buffered, and the image could not be initialized from the buffer.
  - KMC_ED_NOIMAGE, if the iamge representation was IMAGE_REGP_BITMAP or BOTH, and the image is nil, or the image representation is invalid.\n\n
 
 The method may also return one of these errors from the proxy call to imageReadFromFileBuffer:\n
  - KMC_ED_INVALID_FOR_OBJECT_REP, if the object is already represented as both a bitmap and a buffered file.\n
  - KMC_ED_NO_BUFFERED_IMAGE, if there is no buffered image to read from.\n
  - KMC_ED_INVALID_ISO_DATE_TIME_FORMAT if you previously set an invalid date time string.\n
  - KMC_IP_LICENSE_INVALID, if you have not set your SDK license.\n
 
 @code
    int setImageStatus = [ImageReview setImage:myImage];
    if (setImageStatus != KMC_SUCCESS) {
        // TODO Add your error handling logic for the error returned, no image will be displayed.
    }
    else {
        // TODO:  Add your own code to respond to dismissal of the image review control.
    }
 @endcode
 */
- (int)setImage: (kfxKEDImage*) imageObjectToReview;

// ==========================================================
//! Clears the image object out of review control.

-(void) clearImage;


/// Show or hide crop rectangle (tetragon).
/**
 Displays cropping rectangle with draggable corner indicators.  Corners can be repositioned independently, creating a tetragon.  Individual sides can be dragged to resize the rectangle and maintain the rectangular shape.
 
 @param shouldShow set TRUE to show it, or FALSE to hide.
 
 */

-(void) showCropRectangle:(BOOL) shouldShow;


/// Highlights the rectangles specified in the array.
/**
 This method would highlight all the rectangles in the array with the value set for highlightColor. You need to call the setImage method before you call this method.
 
 @param rectArray send an array of kfxKEDBoundingRectangle objects which need to be higlighted.
 
 */
-(void)showHighlights:(NSArray*)rectArray;

/// Clears all the areas highlighted by the method showHighlights
/**
 This method would clear all the rectangles previously highlighted by the method showHighlights
 
 */
-(void)clearHighlights;

@end

