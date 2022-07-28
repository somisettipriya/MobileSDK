//  Kofax Mobile Capture API Reference File
//
//  kfxKUTAppStatistics.h
//
//  Copyright (c) 2012 - 2017 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKUTAppStatisticsDelegate.h"
#import "kfxKUTAppStatsSessionEvent.h"

//! Use the singleton App Statistics object for creating, saving, and exporting statistics related to SDK framework usage.
/**
 An instance of this singleton class contains the properties and methods you must use to setup and use app statistics.\n
 
 */

@interface kfxKUTAppStatistics : NSObject

//! Use this factory method to get a common app statistics object for use in your app.
/**
 Use this method to get a singleton object of kfxKUTAppStatistics.
 @code
 kfxKUTAppStatistics* appStatistics = [kfxKUTAppStatistics appStatisticsInstance];
 @endcode
 */
+ (kfxKUTAppStatistics*)appStatisticsInstance;

//! ramSizeThreshold is the size in bytes at which a warning will be issued to the application. The warning indicates the memory used for status recording has reached the limit established by the application.
@property int ramSizeThreshold;         // Memory usage size to trigger a warning event to the application.

//! fileSizeThreshold is the size in bytes at which a warning will be issued to the application. The warning indicates the file size has reached the limit established by the application.
@property int fileSizeThreshold;        // Flash usage size to trigger a warning event to the application.

//! The readonly ramSize variable keeps the current recording memory usage.
@property (readonly) int ramSize;                  // Current memory usage

// ===================================================
//! This property indicates the file path last set by the initAppStats method.
/**
 The readonly file path property indicates the path that was last set by the initAppStats method. This is provided as a convenience to retain the path in use. This is the file that will be written when you call the writeToFile method. It is only changed when you issue the initAppStats method, and is set to nil after the purge.
 */
@property (retain, readonly) NSString * filePath;

// ===================================================
//! This property indicates the file size of the database.
/**
 The readonly fileSize variable is the current amount of flash memory used in the database. The database file was specified by the initAppStats method. After you call the purge method, this value is set to 0. The size of the file does not grow linearly, even after a few write to file calls, but this value gives you a relative size as statistical data is written to the database.
 */
@property (readonly) int fileSize;                 // Current flash storage usage


// ===================================================
//! Determine if AppStats is currently recording.
/**
 Use the isRecording readonly boolean property to determine whether or not AppStats recording is active. It is set true after you call the startRecord method, and off after you call stopRecord. Certain methods calls are illegal while recording is on.
 */
@property (readonly) bool isRecording;             // Boolean indicating whether recording is active



// ===================================================
//! The deviceID
/**
 The device ID is set by the app to correlate a physical mobile device with the database. The app should use a GUID to specify this deviceID. The deviceID should then be stored in a dictionary and used consistently with AppStats. This device ID is saved in the environment database table. See the example code below.\n\n
 @code
 // example method to add to your app.
 -(int) setupAppStats
 {
 NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
 NSString *documentsDirectory = [paths objectAtIndex:0];
 NSString *dataBasePath = [NSString stringWithFormat: @"%@/MyAppStats.sqlite", documentsDirectory];
 
 // Let's create a new DB each time... If you don't delete the file, AppStats will append to an existing one.
 [[NSFileManager defaultManager] removeItemAtPath:dataBasePath error:NULL];
 
 appStatistics = [kfxKUTAppStatistics appStatisticsInstance]; // this should be the only one.
 
 NSString * DeviceID = nil;
 
 // See if we have already saved the Device ID
 NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
 DeviceID = [defaults objectForKey:@"appStatsDevice"];
 
 if (DeviceID == nil)
 {
 DeviceID = [[NSUUID UUID] UUIDString];
 [defaults setObject:DeviceID forKey:@"appStatsDevice"];
 [defaults synchronize];
 }
 appStatistics.deviceID = DeviceID; // set the device id for use with this session
 int error = [appStatistics initAppStats:dataBasePath]; // specify the path for the AppStats database.
 if (error != KMC_SUCCESS)
 {
 NSString * error1 = [NSString stringWithFormat:@"Error 1: AppStats Init status not equal to KMC_SUCCESS, is 0x%X reason: %@",error,[kfxError findErrMsg:error]];
 
 NSLog(@"%@",error1];
 }
 
 return error;
 }
 
 @endcode
 
 */
@property (nonatomic, copy) NSString* deviceID;


// ===================================================
//! This delegate notifies you about progress and AppStats operations.
/**
 The AppStats library calls your delegates during certain asynchronous operations. The required methods to implement the protocol are: writeFileStatusEvent and exportStatusEvent. The libarary calls the first as the writeToFile proceeds, and the second during the export operation.\n
 You must set this delegate to "self" in order for your app to receive the processing delegate calls during export and writeToFile.
 */
@property (atomic, assign) id<kfxKUTAppStatisticsDelegate>      delegate;


// ===================================================
//!  The initialize method prepares AppStats for capturing statistics.
/**
 @param filePath\n
 The input file name and path specifies the name of the file for the SQLite database. This method either verifies it, if it exists, or creates a new database with the AppStats schema if it doesn't exist. It leaves the internal database in a closed state. The startRecord method will open it again, and stopRecord will close it.
 */
- (int) initAppStats:(NSString *) filePath;


// ===================================================
//! The startRecord method activates statistics recording.
/**
 Use this method to start recording statistics during normal library operations. This will set the isRecording property to true, and open the SQLite database.\n
 This method is only valid if you have initialized AppStats by calling initAppStats to create the database file.\n
 @return KMC_SUCCESS if recording was started successfully. The startRecord returns errors if you have not initialized the database using initAppStats or other errors if the library cannot start recording from the current state.
 */
- (int) startRecord;

// ===================================================
//! The stopRecord method deactivates statistics recording.
/**
 Use this method to stop recording. This will set the isRecording property to false, and close the SQLite database to ensure anything in memory is flushed to the file system.\n
 This method is only valid if you previously started recording.
 @return
 KMC_SUCCESS if recording was stopped successfully or an error code that indicates that the command could not be completed in the current state.
 */
- (int) stopRecord;

// ===================================================
//! The writeToFile method writes the in-memory statistics buffer to the AppStats database.
/**
 Use this asynchronous method from your thresholdReached delegate to periodically write the buffer to the database file. You may also call this method periodically while recording or after recording is turned off. This helps conserve memory. Writing AppStats data to memory improves performance.\n\n
 
 If the database was closed, this method opens it first for writing, then closes it when finished. Else if open, the method keeps it open.\n\n
 
 After the write is complete, the AppStats internal buffer is erased, and the filesize property may or may not increase, but reflects the size of the database file after the write completes.\n\n
 @return
 KMC_SUCCESS if the write to file was started successfully, or error codes that indicate the command could not be completed in the current state. Once KMC_SUCCESS is returned, the library calls your delegate multiple times to indicate the percent progress or any errors detected during the writing process. The greater the size of the database, the longer this asynchronous operation takes.
 */
- (int) writeToFile;

// ===================================================
//! The export method creates a SQL dump file of the internal data store.
/** Use this asynchronous method to create a file containing the different statistics tables created by AppStats.\n\n
 
 The library creates a file according to the export format specified (e.g. MSSQL, etc.). This will create a series of SQL insert statements, intended to populate a destination database with the AppStats data. The destination database must already exist with the schema provided; no "Create" statements are included in this export SQL dump. Note that exportFilePath is a full file path. The export data file is expected to be a .sql file name.\n\n
 
 If you implement the optional formatExportRow delegate in your app, the library calls your delegate for each record in the database so that you can implement your own export data format. This delegate returns a string, and the library writes this string  to the file you specified with the exportFilePath parameter. If you do not implement this formatExportRow delegate, then the library will create the default SQL data.
 @param exportFilePath is a fully qualified file path and file name that the library uses to contain the export data from the AppStats database. You can then use the contents of this file in your own application as you see fit. The library only creates this file, but you must manage its life-cycle.
 @param exportFormat currently has two valid settings. KUT_EXPORT_TYPE_SQL should be used for a standard SQL export and for the user-defined export data format. KUT_EXPORT_TYPE_JSON should be used to choose the JSON export format. This may be expanded in the future to other formats.
 */
- (int) export:(NSString *) exportFilePath withFormat:(KUTappStatsExportFormat) exportFormat;


// ===================================================
//! The purge method erases the AppStats memory buffer and the AppStats recording database file.
/** The database file was specified by the initAppstats method. Recording must be disabled before calling this method. After this call, the library AppStats is set to an uninitialized state. You must call initAppStats again to begin another session. The purge method does not delete the SQL file that was created by the export method. Your app is responsible for consuming and controlling the export data file.
 */
- (int) purge;


// ===================================================
//! beginSession tells appStats to start a "session".
//
/** This method allows the application a means of recording an application-defined Session.  Each session is a grouping in which all subsequent appstats operations will be logged with the same "sessionKey", until the next endSession call.
 @param sessionKey is an application-defined string, which will be a meaningful identifier for this session.   This same sessionKey should also be passed to any server-side calls, such as RTTI, so stats collected on the server can reflect the same sessionKey.
 @param category is an application-defined string, representing the type of session this represents.  Examples of typical categories include BillPay, etc.
 */

-(int) beginSession:(NSString *) sessionKey withCategory:(NSString *) category;

// ===================================================
//! endSession tells appStats to end a "session".
//
/** This method tells appStats to stop the session.  Subsequent loggin calls will not include a sessionKey in the database, until the next time beginSession is called again.
 @param success should be set to true if the overall operation for this session succeeded.   Only the application can know overall success or not of a session.
 @param description may be used to include helpful login information, in case the session did not succeed.
 */
-(int) endSession:(Boolean) success withDescription:(NSString *) description;

// ===================================================
//! logSessionEvent records a Session event in the SessionEvent table.
/** This method allows the application a means of recording an application-defined Session event.  Each session event represents a  single operation which defines one step in a sequence of steps which collectively define a complete session.  See beginSession and endSession.
 */
-(int) logSessionEvent:(kfxKUTAppStatsSessionEvent *) sessionEvent;

@end

