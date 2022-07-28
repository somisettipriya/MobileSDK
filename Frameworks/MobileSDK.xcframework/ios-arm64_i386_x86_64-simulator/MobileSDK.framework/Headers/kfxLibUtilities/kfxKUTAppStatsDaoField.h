//
//  kfxKUTAppStatsDaoField.h
//  kfxLibUtilities
//
//  Copyright (c) 2014-2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

// ===================================================
//! The KUTdaoFieldType enum is used as part of the database export mechanism. The values defined in this enum identify export data types.
// Enum defining the AppStats DAOFieldType values
typedef NS_ENUM(NSUInteger, KUTdaoFieldType) {
    KUT_APP_STATS_DAO_FIELDTYPE_GUID = 0,
    KUT_APP_STATS_DAO_FIELDTYPE_INT,
    KUT_APP_STATS_DAO_FIELDTYPE_FLOAT,
    KUT_APP_STATS_DAO_FIELDTYPE_TEXT,
    KUT_APP_STATS_DAO_FIELDTYPE_DATETIME
};


//! The KUTdaoTableType enum is used as part of the database export mechanism. The values defined in this enum identify tables that are part of the Application Statistics database schema.
typedef NS_ENUM(NSUInteger, KUTdaoTableType) {
    KUT_APP_STATS_DAO_TABLETYPE_UNKNOWN = 0,
    KUT_APP_STATS_DAO_TABLETYPE_ENVIRONMENT,
    KUT_APP_STATS_DAO_TABLETYPE_INSTANCE,
    KUT_APP_STATS_DAO_TABLETYPE_CLASSIFICATIONEVENT,
    KUT_APP_STATS_DAO_TABLETYPE_CLASSIFICATION_ALTERNATIVE,
    KUT_APP_STATS_DAO_TABLETYPE_IMAGECAPTURECONTROL,
    KUT_APP_STATS_DAO_TABLETYPE_ERRORLOG,
    KUT_APP_STATS_DAO_TABLETYPE_FIELDCHANGE,
    KUT_APP_STATS_DAO_TABLETYPE_PROPERTYCHANGE,
    KUT_APP_STATS_DAO_TABLETYPE_IMAGE,
    KUT_APP_STATS_DAO_TABLETYPE_IMAGEPROCESSOR,
    KUT_APP_STATS_DAO_TABLETYPE_DOCUMENT,
    KUT_APP_STATS_DAO_TABLETYPE_SESSION
};

//! Used as part of custom export process, for passing Application Statistics table entries to your export handler code in the formatExportRow delegate method.
/**
 This data structure is used by the database export mechanism.  If you define a custom export handler by implementing the formatExportRow delegate method, each of the tables will be exported, calling that delegate method for each row of data, and passing in an array of this data structure for custom handling by your exporter code.\n
 
 */
@interface kfxKUTAppStatsDaoField : NSObject

//! The name of the field
@property (nonatomic, strong) NSString * fieldName;

//! The value of the field
@property (nonatomic, strong) NSString * fieldValue;

//! The type of the field (GUID, int, float, text, datetime)
@property (nonatomic, assign) KUTdaoFieldType fieldType;

//! The type of the table (one of the tables defined in the Application Statistics database schema).
@property (nonatomic, assign) KUTdaoTableType tableType;

@end
