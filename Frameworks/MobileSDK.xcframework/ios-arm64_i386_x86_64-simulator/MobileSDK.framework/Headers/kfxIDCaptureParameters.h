//
//  API Reference
//  kfxIDCaptureParameters.h
//  Framework: MobileSDK
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <MobileSDK/kfxIParameters.h>
#import <MobileSDK/kfxKOEIDRegion.h>

@class kfxIDData;

//! An enumeration containing the possible ID side values.
/**
 Use one of the values of this enumeration to set the ID side for detection.
 */
typedef NS_ENUM (NSInteger, kfxIDSide)
{
    kfxIDSide_Front,
    kfxIDSide_Back
};
///@cond EXTRACTION

//! The ID state class.
/**
 This class determines ID state of the specified ID region. Please do not create the instance of this class by yourself, use one of the state methods from category kfxIDState (kfxIDStateCreation) instead.
 */
@interface kfxIDState : NSObject <NSCopying>

/// ID region value.
/**
 Connects ID state to the ID region, allow to create region-state hierarchy.
 
 This readonly property contains one of the available values from kfxKOEIDRegion enumeration.
 
 @see kfxKOEIDRegion
 */
@property (nonatomic, readonly, assign) kfxKOEIDRegion idRegion;

/// Compares the receiving state to another state.
/**
 YES if the content of otherState is equal to the content of the receiving state, otherwise NO.
 */
- (BOOL)isEqualToState:(kfxIDState*)otherState;

@end

//! The ID state creation category.
/**
 Used for creation ID state.
 */
@interface kfxIDState (kfxIDStateCreation)

//! NotSpecified state.
/**
 Creates NotSpecified state instance of kfxKOEIDRegion_US region.
*/
+ (instancetype)NotSpecified;

//! United States state.
/**
 Creates United States state instance of kfxKOEIDRegion_US region.
 */
+ (instancetype)UnitedStates;

//! Canada state.
/**
 Creates Canada state instance of kfxKOEIDRegion_Canada region.
 */
+ (instancetype)Canada;

//! Other Africa state
/**
 Creates other Africa state instance of kfxKOEIDRegion_Africa region.
 */
+ (instancetype)AfricaOther;

//! Cameroon state.
/**
 Creates Cameroon state instance of kfxKOEIDRegion_Africa region.
 */
+ (instancetype)Cameroon;

//! Other Asia state
/**
 Creates other Asia state instance of kfxKOEIDRegion_Asia region.
 */
+ (instancetype)AsiaOther;

//! China state.
/**
 Creates China state instance of kfxKOEIDRegion_Asia region.
 */
+ (instancetype)China;

//! India state.
/**
 Creates India state instance of kfxKOEIDRegion_Asia region.
 */
+ (instancetype)India;

//! Singapore state.
/**
 Creates Singapore state instance of kfxKOEIDRegion_Asia region.
 */
+ (instancetype)Singapore;

//! South Korea state.
/**
 Creates South Korea state instance of kfxKOEIDRegion_Asia region.
 */
+ (instancetype)SouthKorea;

//! Japan state.
/**
 Creates Japan state instance of kfxKOEIDRegion_Asia region.
 */
+ (instancetype)Japan;

//! Other Australia state
/**
 Creates other Australia state instance of kfxKOEIDRegion_Australia region.
 */
+ (instancetype)AustraliaOther;

//! Key Pass state.
/**
 Creates Key Pass state instance of kfxKOEIDRegion_Australia region.
 */
+ (instancetype)KeyPass;

//! Other Europe state.
/**
 Creates other Europe state instance of kfxKOEIDRegion_Europe region.
 */
+ (instancetype)EuropeOther;

//! Albania state.
/**
 Creates Albania state instance of kfxKOEIDRegion_Europe region.
 */
+ (instancetype)Albania;

//! Germany state.
/**
 Creates Germany state instance of kfxKOEIDRegion_Europe region.
 */
+ (instancetype)Germany;

//! Lithuania state.
/**
 Creates Lithuania state instance of kfxKOEIDRegion_Europe region.
 */
+ (instancetype)Lithuania;

//! Luxembourg state.
/**
 Creates Luxembourg state instance of kfxKOEIDRegion_Europe region.
 */
+ (instancetype)Luxembourg;

//! Other Latin America state.
/**
 Creates other Latin America state instance of kfxKOEIDRegion_LatinAmerica region.
 */
+ (instancetype)LatinAmericaOther;

//! Brazil state.
/**
 Creates Brazil state instance of kfxKOEIDRegion_LatinAmerica region.
 */
+ (instancetype)Brazil;

//! Ecuador state.
/**
 Creates Ecuador state instance of kfxKOEIDRegion_LatinAmerica region.
 */
+ (instancetype)Ecuador;

//! ElSalvador state.
/**
 Creates ElSalvador state instance of kfxKOEIDRegion_LatinAmerica region.
 */
+ (instancetype)ElSalvador;

//! Guatemala state.
/**
 Creates Guatemala state instance of kfxKOEIDRegion_LatinAmerica region.
 */
+ (instancetype)Guatemala;

//! StChristNevis state.
/**
 Creates StChristNevis state instance of kfxKOEIDRegion_LatinAmerica region.
 */
+ (instancetype)StChristNevis;

@end
///@endcond

//! The ID capture view controller parameters.
/**
 Encapsulates all parameters related to ID capture@if EXTRACTION, processing and extraction.@else &nbsp;and processing.@endif\n

 Default values for following parameters are differ with base classes:
 - useTargetFrameCrop is ON.
 
 @see kfxIParameters
 */
@interface kfxIDCaptureParameters : kfxIParameters <NSCopying>

/// An ID side value that determines ID detection functionality.
/**
 The supported modes are:
 kfxIDSide_Front:  Front ID side.
 kfxIDSide_Back:  Back ID side.
 
 The default value is kfxIDSide_Front.
 
 @see kfxIDSide
 */
@property (nonatomic, assign) kfxIDSide idSide;
///@cond EXTRACTION

/// Data for reverse side of the ID.
/**
 This data will be used for extraction along with the image for the current side of the ID.
 The field is used when capturing both sides of the ID.
 
 @see kfxIDData
 */
@property (nonatomic, strong) kfxIDData* reverseSideID;

/// A value that determines state.
/**
 This value is used for the extraction.
 
 Specify one of the available values from kfxIDState predefines.
 The default value is [kfxIDState NotSpecified]. For this value extractor assumes the region is United States.
 
 @see kfxIDState
 */
@property (nonatomic, copy) kfxIDState* state;

//! ID project name
/**
 Allows to get specific for state project name for asset downloading.
 
 @param state - ID state.
 @return project name.
 
 @see kfxIDState
 */
+ (NSString*)projectNameForState:(kfxIDState*)state;
///@endcond
@end
