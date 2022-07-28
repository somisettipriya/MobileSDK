//
//  kfxKEDCheckDetectionResultCompatibility.h
//  kfxLibEngines
//
//  Copyright (c) 2014-2017 Kofax. All rights reserved. Kofax Confidential.
//  Unauthorized use, duplication, or distribution, or disclosure is strictly prohibited.
//

#import "kfxKEDDocumentBaseDetectionResult.h"

typedef KEDDocumentZoomGuidance KEDCheckZoomGuidance;
extern const KEDCheckZoomGuidance KED_CHECK_ZOOM_IN;
extern const KEDCheckZoomGuidance KED_CHECK_ZOOM_OUT;
extern const KEDCheckZoomGuidance KED_CHECK_ZOOM_OK;

typedef KEDDocumentTurnGuidance KEDCheckTurnGuidance;
extern const KEDCheckTurnGuidance KED_CHECK_TURN_COUNTER_CLOCKWISE;
extern const KEDCheckTurnGuidance KED_CHECK_TURN_CLOCKWISE;
extern const KEDCheckTurnGuidance KED_CHECK_TURN_OK;

typedef KEDDocumentHorizontalGuidance KEDCheckHorizontalGuidance;
extern const KEDCheckHorizontalGuidance KED_CHECK_HORIZONTAL_MOVE_LEFT;
extern const KEDCheckHorizontalGuidance KED_CHECK_HORIZONTAL_MOVE_RIGHT;
extern const KEDCheckHorizontalGuidance KED_CHECK_HORIZONTAL_MOVE_OK;

typedef KEDDocumentVerticalGuidance KEDCheckVerticalGuidance;
extern const KEDCheckVerticalGuidance KED_CHECK_VERTICAL_MOVE_UP;
extern const KEDCheckVerticalGuidance KED_CHECK_VERTICAL_MOVE_DOWN;
extern const KEDCheckVerticalGuidance KED_CHECK_VERTICAL_MOVE_OK;
