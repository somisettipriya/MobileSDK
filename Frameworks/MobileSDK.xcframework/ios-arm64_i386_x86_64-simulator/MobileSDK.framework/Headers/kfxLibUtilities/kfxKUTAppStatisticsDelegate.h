//  Kofax Mobile Capture API Reference File
//
//  kfxKUTAppStatisticsDelegate.h
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

//! The KUTappStatsExport enum is used to identify status values for the exportStatusEvent delegate (indicating exporting-in-progress, exporting-complete, and exporting-failed.
/* Enum identifying export status events */
typedef NS_ENUM(NSUInteger, KUTappStatsExport) {
    KUT_EXPORT_STATUS_EXPORTING = 1,
    KUT_EXPORT_STATUS_COMPLETE,
    KUT_EXPORT_STATUS_FAILED
};

//! The KUTappStatsWriteFile enum is used to identify status values for the writeFileStatusEvent delegate (indicating writeToFile-in-progress, writeToFile-complete, and writeToFile-failed.
/* Enum identifying export status events */
typedef NS_ENUM(NSUInteger, KUTappStatsWriteFile) {
    KUT_WRITEFILE_STATUS_EXPORTING = 1,
    KUT_WRITEFILE_STATUS_COMPLETE,
    KUT_WRITEFILE_STATUS_FAILED
};


//! The KUTappStatsThreshold enum is used to identify status values for the sizeThreshold delegate (indicating that either a memory threshold or file threshold has been reached).
/* Enum identifying either file or memory operations when report size events */
typedef NS_ENUM(NSUInteger, KUTappStatsThreshold) {
    KUT_THRESH_TYPE_RAM = 1,
    KUT_THRESH_TYPE_FILE
};

//! The KUTappStatsExportFormat enum is used to identify the desired format for AppStats export operations. KUT_EXPORT_TYPE_SQL should be selected for either the default (SQL) or user-defined export format. Choose KUT_EXPORT_TYPE_JSON for a JSON export file.
/* Enum identifying the AppStats export format */
typedef NS_ENUM(NSUInteger, KUTappStatsExportFormat) {
    KUT_EXPORT_TYPE_SQL = 0,
    KUT_EXPORT_TYPE_JSON
};

@protocol kfxKUTAppStatisticsDelegate<NSObject>

@required


//! The writeFileStatusEvent delegate method reports on the status of writeToFile. If writeToFile is still in progress, it also reports the percent complete. Otherwise, it reports either write complete or write failed. In the case of failure, errorCode and errorMsg will contain a description of the specific failure.
/* Report the status of a writeToFile operation */
- (void) writeFileStatusEvent : (KUTappStatsWriteFile) type andProgress : (int) percentComplete withError: (int) errorCode withMsg: (NSString *) errorMsg;

//! The exportStatusEvent delegate method reports on the status of the export sequence. If the export is still in progress, the method also reports the percent complete. Otherwise, it reports either export complete or export failed. In the case of failure, errorCode and errorMsg will contain a description of the specific failure.
/* Report the status of an export operation */
- (void) exportStatusEvent : (KUTappStatsExport) type andProgress : (int) percentComplete  withError: (int) errorCode withMsg: (NSString *) errorMsg;

@optional

//! The formatExportRow delegate method is an optional method to allow the application to format rows of the export file in a syntax different from the default MSSQL-compatible implementation. daoFields is an array of kfxKUTAppStatsDaoField objects. See the developer's guide for more information and examples.
- (NSString *) formatExportRow:(NSString *) tableName withFields:(NSMutableArray *) daoFields;

//! The sizeThreshold delegate method indicates that either the memory buffer or the file size has reached a threshold.
/* Report size threshold events to the application */
- (void) sizeThresholdReached : (KUTappStatsThreshold) type andSize : (int) size;


@end
