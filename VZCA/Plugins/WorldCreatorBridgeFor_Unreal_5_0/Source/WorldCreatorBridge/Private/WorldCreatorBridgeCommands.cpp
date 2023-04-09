// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorldCreatorBridgeCommands.h"

#define LOCTEXT_NAMESPACE "FWorldCreatorBridgeModule"

void FWorldCreatorBridgeCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "World Creator Bridge", "Bring up WorldCreatorBridge window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
