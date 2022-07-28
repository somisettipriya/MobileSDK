//
//  kfxKUTAppStatsSessionEvent.h
//  kfxLibUtilities
//
//  Copyright (c) 2017 Kofax.Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

//! App Statistics Session Events
/**
 Session Events are used by the application to record events of interest with timestamps.
 An instance of this class contains the properties you use to set a session event. 
 Session events are completely application defined, so type can be any meaningful string
 that the application uses to describe the session event being logged.  This will show
 up in the exported data and can be reported on.
 documentID is optional, as not all session events relate to a particular document.
 \n\n
 */
@interface kfxKUTAppStatsSessionEvent : NSObject

// ===================================================
//! Type of event
/**
 Any meaningful string that would indicate what type of event is being logged.  For example, when you begin a session, you pass in a sessionKey and an application defined Category name (such as "BillPay").  So type here would be a type of event within that category.. such as "BillPayExtractionReceived"
 */

@property (nonatomic, strong) NSString * type;

// ===================================================
//! Used to indicate response to an operation
/**
 Here you can record the result of an operation, such as response returned back from a server, or whether a processing operation succeeded or failed, etc.
 */

@property (nonatomic, strong) NSString * response;

// ===================================================
//! documentID of affected document if event pertains to an operation on a document
/**
 documentID is optional, as not all session events relate to a particular document.
 */

@property (nonatomic, strong) NSString * documentID;


@end
