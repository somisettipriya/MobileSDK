//
//  API Reference
//  kfxCheckUsabilityData.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>

@class kfxDataField;

//! This object represents check IQA data.
/**
 Contains the IQA data assosiated with extracted check data.
 */
@interface kfxCheckIQAData : NSObject

/// Image width.
/**
 This property contains the image width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* imageWidth;

/// Image height.
/**
 This property contains the image height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* imageHeight;

/// Top left corner width.
/**
 This property contains the top left corner width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* topLeftCornerWidth;

/// Top left corner height.
/**
 This property contains the top left corner height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* topLeftCornerHeight;

/// Bottom left corner width.
/**
 This property contains the bottom left corner width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* bottomLeftCornerWidth;

/// Bottom left corner height.
/**
 This property contains the bottom left corner height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* bottomLeftCornerHeight;

/// Top right corner width.
/**
 This property contains the top right corner width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* topRightCornerWidth;

/// Top right corner height.
/**
 This property contains the top right corner height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* topRightCornerHeight;

/// Bottom right corner width.
/**
 This property contains the bottom right corner width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* bottomRightCornerWidth;

/// Bottom right corner height.
/**
 This property contains the bottom right corner height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* bottomRightCornerHeight;

/// Top edge tear width.
/**
 This property contains the top edge tear width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* topEdgeTearWidth;

/// Top edge tear height.
/**
 This property contains the top edge tear height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* topEdgeTearHeight;

/// Right edge tear width.
/**
 This property contains the right edge tear width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* rightEdgeTearWidth;

/// Right edge tear height.
/**
 This property contains the right edge tear height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* rightEdgeTearHeight;

/// Bottom edge tear width.
/**
 This property contains the bottom edge tear width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* bottomEdgeTearWidth;

/// Bottom edge tear height.
/**
 This property contains the bottom edge tear height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* bottomEdgeTearHeight;

/// Left edge tear width.
/**
 This property contains the left edge tear width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* leftEdgeTearWidth;

/// Left edge tear height.
/**
 This property contains the left edge tear height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* leftEdgeTearHeight;

/// Additional left scan lines width.
/**
 This property contains the additional left scan lines width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* additionalLeftScanLinesWidth;

/// Additional top scan lines height.
/**
 This property contains the additional top scan lines height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* additionalTopScanLinesHeight;

/// Additional right scan lines width.
/**
 This property contains the additional right scan lines width. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* additionalRightScanLinesWidth;

/// Additional bottom scan lines height.
/**
 This property contains the additional bottom scan lines height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* additionalBottomScanLinesHeight;

/// Document skew angle.
/**
 This property contains the document skew angle. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* documentSkewAngle;

/// Percent black pixels.
/**
 This property contains the percent black pixels. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* percentBlackPixels;

/// Percent average image brightness.
/**
 This property contains the percent average image brightness. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* percentAverageImageBrightness;

/// Percent average image contrast.
/**
 This property contains the percent average image contrast. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* percentAverageImageContrast;

/// Black streak count.
/**
 This property contains the black streak count. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* blackStreakCount;

/// Black streak max height.
/**
 This property contains the black streak max height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* blackStreakMaxHeight;

/// Gray level streak count.
/**
 This property contains the gray level streak count. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* grayLevelStreakCount;

/// Gray level streak max height.
/**
 This property contains the gray level streak max height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* grayLevelStreakMaxHeight;

/// Average spot noise groupings per square inch.
/**
 This property contains the average spot noise groupings per square inch. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* averageSpotNoiseGroupingsPerSquareInch;

/// Front rear width difference.
/**
 This property contains the front rear width difference. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* frontRearWidthDifference;

/// Front rear height difference.
/**
 This property contains the front rear height difference. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* frontRearHeightDifference;

/// Carbon strip height.
/**
 This property contains the carbon strip height. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* carbonStripHeight;

/// Image focus score.
/**
 This property contains the image focus score. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* imageFocusScore;

/// Compressed front image size.
/**
 This property contains the compressed front image size. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* compressedFrontImageSize;

/// Compressed rear image size.
/**
 This property contains the compressed rear image size. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* compressedRearImageSize;

/// Undersize image.
/**
 This property contains the undersize image. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* undersizeImage;

/// Folded or torn document corners.
/**
 This property contains the folded or torn document corners. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* foldedOrTornDocumentCorners;

/// Folded or torn document edges.
/**
 This property contains the folded or torn document edges. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* foldedOrTornDocumentEdges;

/// Document framing error.
/**
 This property contains the document framing error. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* documentFramingError;

/// Document skew.
/**
 This property contains the document skew. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* documentSkew;

/// Oversize image.
/**
 This property contains the oversize image. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* oversizeImage;

/// Piggyback document.
/**
 This property contains the piggyback document. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* piggybackDocument;

/// Image too light.
/**
 This property contains the image too light. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* imageTooLight;

/// Image too dark.
/**
 This property contains the image too dark. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* imageTooDark;

/// Horizontal streaks.
/**
 This property contains the horizontal streaks. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* horizontalStreaks;

/// Below min front image size.
/**
 This property contains the below min front image size. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* belowMinFrontImageSize;

/// Above max front image size.
/**
 This property contains the above max front image size. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* aboveMaxFrontImageSize;

/// Below min rear image size.
/**
 This property contains the below min rear image size. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* belowMinRearImageSize;

/// Above max rear image size.
/**
 This property contains the above max rear image size. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* aboveMaxRearImageSize;

/// Spot noise.
/**
 This property contains the spot noise. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* spotNoise;

/// Image dimension mismatch.
/**
 This property contains the image dimension mismatch. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* imageDimensionMismatch;

/// Carbon strip.
/**
 This property contains the carbon strip. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* carbonStrip;

/// Out of focus.
/**
 This property contains the out of focus. The value string is empty if the extraction of this field is unsuccessfull.
 
 @see kfxDataField
 */
@property (nonatomic, strong) kfxDataField* outOfFocus;

@end
