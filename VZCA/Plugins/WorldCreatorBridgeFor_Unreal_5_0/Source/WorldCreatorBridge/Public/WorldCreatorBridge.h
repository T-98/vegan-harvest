// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FWorldCreatorBridgeModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command (by default it will bring up plugin window) */
	void PluginButtonClicked();
	
private:

	void RegisterMenus();

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

private:
	TSharedPtr<class FUICommandList> PluginCommands;

	//// World Creator
//////////////////
	FReply SyncButtonClicked();
	FReply BrowseButtonClicked();

	const bool GetIsButtonEnabled();

	//void LoadTGA(const TCHAR* path, TArray<uint8>& data, int& width, int& height, int& bpp);

	//void OnSetReference(UObject* drop);

	FButtonStyle* wcButton;
	FButtonStyle* youtubeButton;
	FButtonStyle* twitterButton;
	FButtonStyle* twitchButton;
	FButtonStyle* facebookButton;
	FButtonStyle* discordButton;
	FButtonStyle* artstationButton;
	FButtonStyle* instagramButton;
	FButtonStyle* vimeoButton;

	//UObject* meshReference;


	FString selectedPath;
	FString terrainName;
	FString terrainMaterialName;
	bool bImportTextures;
	bool bUseWorldPartition;
	bool bBuildMinimap;
	float worldScale;
	int worldPartitionGridSize;
	TOptional<float> GetTransformDelta() const;
	TOptional<int> GetGridSizeDelta() const;
	TOptional<FString> GetSelectedPath() const;
	TSharedPtr<SEditableTextBox> selectedPathBox;

	int32 TabIndex;

	int32 GetCurrentTabIndex() const
	{
		return TabIndex;
	}
};
