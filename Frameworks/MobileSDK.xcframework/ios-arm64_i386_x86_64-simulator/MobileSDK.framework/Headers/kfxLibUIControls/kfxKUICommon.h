//
// API Reference File
//  kfxKUICommon.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

//! An enumeration to set the flash mode of a capture control
/**
 Use one of the values of this enumeration to set the flash mode of a 
 capture control.
 */
typedef enum
{
    kfxKUIFlashOn = 0,
    kfxKUIFlashOff = 1,
    kfxKUIFlashAuto = 2,
    kfxKUITorch = 3,
    kfxKUITorchAuto = 4
    
} kfxKUIFlashSetting;

//! An enumeration to set the guiding line mode of a barcode capture control
/**
 Use one of the values of this enumeration to set the guiding line display
 mode of a barcode capture contorl.
 */
typedef enum
{
    kfxKUIGuidingLineOff = 0,
    kfxKUIGuidingLineLandscape = 1,
    kfxKUIGuidingLinePortrait = 2
} kfxKUIGuidingLine;

//! An enumeration containing the different barcode symbologies that can be detected
/**
 One or more of these values can be passed to a barcode capture control to restrict
 search to those symbologies.
 */
typedef enum
{
    kfxKUISymbologyCode39 = 0,
    kfxKUISymbologyPdf417 = 1,
    kfxKUISymbologyQR = 2,
    kfxKUISymbologyDataMatrix = 3,
    kfxKUISymbologyCode128 = 4,
    kfxKUISymbologyCode25 = 5,
    kfxKUISymbologyEAN = 6,
    kfxKUISymbologyUPC = 7,
    kfxKUISymbologyCodabar = 8,
    kfxKUISymbologyAztec = 9,
    kfxKUISymbologyCode93 = 10
} kfxKUISymbology;

//! An enumeration containing the different possible barcode search directions
/**
 One or more of these values can be passed to a barcode capture control to restrict
 the directions that are searched for barcodes.
 */
typedef enum
{
    kfxKUIDirectionHorizontal = 1 | 2,
    kfxKUIDirectionVertical = 4 | 8,
    kfxKUIDirectionAll = 1 | 2 | 4 | 8,
} kfxKUISearchDirection;

//! An enumeration to control page detection mode
/**
 Use one of the values of this enumeration to set the page detection mode of
 a capture control.
 */
typedef enum
{
    kfxKUIPageDetectOff = 0,
    kfxKUIPageDetectAutomatic = 1,
    kfxKUIPageDetectContinuous = 2
} kfxKUIPageDetect;

//! An enumeration to control use of GPS location information
/**
 Use one of the values of this enumeration to determine whether GPS location
 information is included in SDK photos.
 */
typedef enum
{
    kfxKUINeverUse = 0,
    kfxKUIAlwaysUseIfEnabled=1
} kfxKUIGPSUsageLimits;

//! An enumeration to control use of detection algorithm used for real time document detection
/**
Use one of the values of this enumeration to determine what type of algorithm is used in
real time doucment detection
*/

typedef enum{

	kfxKUIGenericDocument = 0,
	kfxKUICheckFront = 1,
	kfxKUICheckBack = 2

} kfxKUIDocumentDetectionModes;

//! An enumeration to set camera type
/**
 Use one of the values of this enumeration to camera type front or back.
 */
typedef enum
{
    kfxKUIBackCamera = 0,
    kfxKUIFrontCamera = 1,
    
} kfxKUICameraType;

// ==========================================================
//! Style of outline for cropping rectangle/tetragon (solid or dotted lines).
typedef enum LINE_STYLE_ENUM {
    LINE_STYLE_SOLID, LINE_STYLE_DOTTED
} kfxUILineStyle;
