//
//  kfxKUIGenericDocumentCaptureExperience.h
//  kfxLibUIControls
//
//  Copyright (c) 2017 Kofax. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <kfxLibUIControls/kfxKUIDocumentBaseCaptureExperience.h>
#import <kfxLibUIControls/kfxKUIDocumentCaptureExperienceCriteriaHolder.h>

//! This class renders a visual experience on top of the capture control and returns an image depending on the criteria set by the user.
/**
 This class is responsible for rendering the enhanced visual experience on top of the capture control, and provides feedback to
 guide the user to take a clear, legible and optimally zoomed in photo of the document.
 */
@interface kfxKUIDocumentCaptureExperience : kfxKUIDocumentBaseCaptureExperience

/// Initializes a new object using the specified parameters.
/**
 Initializes a document capture experience and binds it to the given image capture control.  The experience class overrides the capture control delegate to provide additional behavior and guidance useful for capturing documents.  It also forwards delegate invocations to the original delegate set on the capture control, thus acting as a proxy.
 
 If you are interested in handling any of the delegate methods on the capture control, it is important that you set your delegate before initializing the capture experience.  Setting a new delegate after initializing the capture experience will break the association with the capture control, and allow the capture experience to be shut down and deallocated if no other references to the object remain.  This is the proper protocol for cleaning up a capture experience you are no longer interested in.
 
 The document capture experience will add several overlays and subviews on top of the associated image capture control for visual guidance and feedback.  It will also manage some of the capture control's native properties, which could interfere with any properties you directly modify on the control.
 
 For best results, your image capture control should be configured to use video capture mode.  This will normally result in a larger preview resolution being used.  Small preview resolutions will make document detection difficult and negatively impact user guidance.  In particular, the capture experience will rarely be able to deliver zoom-related guidance with low resolution preview images.
 
 @param captureControl An instance of a kfxKUIImageCaptureControl object.
 @param criteria A collection of constraints and attributes that control the behavior of the capture experience. Pass nil for the default experience.
 */
- (instancetype)initWithCaptureControl:(kfxKUIImageCaptureControl*)captureControl criteria:(kfxKUIDocumentCaptureExperienceCriteriaHolder*)criteria;

/// Document capture criteria
/**
 A collection of constraints and attributes that control the behavior of the capture experience. Pass nil to use default configuration.
 */
@property (nonatomic, strong) kfxKUIDocumentCaptureExperienceCriteriaHolder* documentCriteria;

@end
