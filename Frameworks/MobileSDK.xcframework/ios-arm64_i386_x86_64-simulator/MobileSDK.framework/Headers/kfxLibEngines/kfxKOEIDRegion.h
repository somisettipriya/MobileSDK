//
//  kfxKOEIDRegion.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#ifndef KFXKOEIDREGION
#define KFXKOEIDREGION 1

//! An enumeration containing the possible region values.
/**
 Use one of the values of this enumeration to set the region.
 */
typedef NS_ENUM(NSInteger, kfxKOEIDRegion)
{
    /// United States
    kfxKOEIDRegion_US,
    /// Canada
    kfxKOEIDRegion_Canada,
    /// Latin America
    /**
     Currently supported: Argentina, Brazil, Colombia, Mexico
     */
    kfxKOEIDRegion_LatinAmerica,
    /// Europe
    /**
     Currently supported: France, Germany, Poland, Spain, United Kingdom
     */
    kfxKOEIDRegion_Europe,
    /// Asia
    /**
     Currently supported: India
     */
    kfxKOEIDRegion_Asia,
    
    /// Reserved for future usage
    kfxKOEIDRegion_Australia,
    /// Reserved for future usage
    kfxKOEIDRegion_Africa,
};

#endif
