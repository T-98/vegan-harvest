// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorldCreatorBridge.h"
#include "WorldCreatorBridgeStyle.h"
#include "WorldCreatorBridgeCommands.h"
#include "XmlHelper.h"
#include "LevelEditor.h"
#include "Math/Vector2D.h"
#include "Editor/EditorEngine.h"
#include "Engine/Selection.h"

#include "Dialogs/CustomDialog.h"
#include "LevelEditorActions.h"

#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Styling/SlateTypes.h"
#include "Widgets/Input/SButton.h"
#include "Runtime/SlateCore/Public/Widgets/Images/SImage.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "Factories/MaterialFactoryNew.h"
#include "Factories/Texture2dFactoryNew.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Materials/MaterialExpressionLandscapeLayerCoords.h"
#include "Landscape.h"
#include "LandscapeGizmoActiveActor.h"
#include "EngineUtils.h"
#include "Runtime/XmlParser/Public/XmlParser.h"
#include "LandscapeInfo.h"
#include "Misc/FileHelper.h"
#include "LandscapeLayerInfoObject.h"
#include "Engine/Texture.h"
#include "AutomatedAssetImportData.h"
#include "AssetToolsModule.h"
#include "Widgets/Layout/SWidgetSwitcher.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Input/SNumericEntryBox.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "Materials/MaterialExpressionLandscapeLayerBlend.h"
#include "Materials/MaterialExpressionMultiply.h"
#include "Materials/MaterialExpressionConstant2Vector.h"


#include "WorldPartition/DataLayer/WorldDataLayers.h"
#include "WorldPartition/WorldPartitionMiniMap.h"
#include "LandscapeStreamingProxy.h"

// Experimental
#include "LandscapeSubsystem.h"
#include "WorldPartition/WorldPartition.h"
#include "GenericPlatform/GenericPlatformProcess.h"
//#include "WorldPartitionEditorModule.h"
//
//#include "Misc/StringBuilder.h"
//#include "Misc/ScopedSlowTask.h"
//#include "Internationalization/Regex.h"

static const FName WorldCreatorBridgeTabName("WorldCreatorBridge");

#define LOCTEXT_NAMESPACE "FWorldCreatorBridgeModule"

void FWorldCreatorBridgeModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FWorldCreatorBridgeStyle::Initialize();
	FWorldCreatorBridgeStyle::ReloadTextures();

	FWorldCreatorBridgeCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FWorldCreatorBridgeCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FWorldCreatorBridgeModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FWorldCreatorBridgeModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(WorldCreatorBridgeTabName, FOnSpawnTab::CreateRaw(this, &FWorldCreatorBridgeModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FWorldCreatorBridgeTabTitle", "WorldCreatorBridge"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

    FString teststring = FPlatformProcess::UserDir();
    this->selectedPath = FString::Printf(TEXT("%sWorld Creator/Sync/Bridge.xml"), teststring.GetCharArray().GetData());
    this->terrainName = TEXT("WC_Terrain");
    this->terrainMaterialName = TEXT("M_Terrain");
    this->bImportTextures = true;
    this->bBuildMinimap = true;
    this->worldScale = 1.0f;
    this->worldPartitionGridSize = 8;
    // Init Brushes
    ///////////////
    auto wcbrush = FWorldCreatorBridgeStyle::Get().GetBrush("WorldCreatorBridge.WorldCreator");
    auto facebookBrush = FWorldCreatorBridgeStyle::Get().GetBrush("WorldCreatorBridge.Facebook");
    auto twitterBrush = FWorldCreatorBridgeStyle::Get().GetBrush("WorldCreatorBridge.Twitter");
    auto instagramBrush = FWorldCreatorBridgeStyle::Get().GetBrush("WorldCreatorBridge.Instagram");
    auto youtubeBrush = FWorldCreatorBridgeStyle::Get().GetBrush("WorldCreatorBridge.Youtube");
    auto vimeoBrush = FWorldCreatorBridgeStyle::Get().GetBrush("WorldCreatorBridge.Vimeo");
    auto twitchBrush = FWorldCreatorBridgeStyle::Get().GetBrush("WorldCreatorBridge.Twitch");
    auto artstationBrush = FWorldCreatorBridgeStyle::Get().GetBrush("WorldCreatorBridge.Artstation");
    auto discordBrush = FWorldCreatorBridgeStyle::Get().GetBrush("WorldCreatorBridge.Discord");

    wcButton = new FButtonStyle();
    wcButton->SetDisabled(*wcbrush);
    wcButton->SetHovered(*wcbrush);
    wcButton->SetNormal(*wcbrush);
    wcButton->SetPressed(*wcbrush);

    facebookButton = new FButtonStyle();
    facebookButton->SetDisabled(*facebookBrush);
    facebookButton->SetHovered(*facebookBrush);
    facebookButton->SetNormal(*facebookBrush);
    facebookButton->SetPressed(*facebookBrush);

    twitterButton = new FButtonStyle();
    twitterButton->SetDisabled(*twitterBrush);
    twitterButton->SetHovered(*twitterBrush);
    twitterButton->SetNormal(*twitterBrush);
    twitterButton->SetPressed(*twitterBrush);

    instagramButton = new FButtonStyle();
    instagramButton->SetDisabled(*instagramBrush);
    instagramButton->SetHovered(*instagramBrush);
    instagramButton->SetNormal(*instagramBrush);
    instagramButton->SetPressed(*instagramBrush);

    youtubeButton = new FButtonStyle();
    youtubeButton->SetDisabled(*youtubeBrush);
    youtubeButton->SetHovered(*youtubeBrush);
    youtubeButton->SetNormal(*youtubeBrush);
    youtubeButton->SetPressed(*youtubeBrush);

    vimeoButton = new FButtonStyle();
    vimeoButton->SetDisabled(*vimeoBrush);
    vimeoButton->SetHovered(*vimeoBrush);
    vimeoButton->SetNormal(*vimeoBrush);
    vimeoButton->SetPressed(*vimeoBrush);

    twitchButton = new FButtonStyle();
    twitchButton->SetDisabled(*twitchBrush);
    twitchButton->SetHovered(*twitchBrush);
    twitchButton->SetNormal(*twitchBrush);
    twitchButton->SetPressed(*twitchBrush);

    artstationButton = new FButtonStyle();
    artstationButton->SetDisabled(*artstationBrush);
    artstationButton->SetHovered(*artstationBrush);
    artstationButton->SetNormal(*artstationBrush);
    artstationButton->SetPressed(*artstationBrush);

    discordButton = new FButtonStyle();
    discordButton->SetDisabled(*discordBrush);
    discordButton->SetHovered(*discordBrush);
    discordButton->SetNormal(*discordBrush);
    discordButton->SetPressed(*discordBrush);
}


void FWorldCreatorBridgeModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FWorldCreatorBridgeStyle::Shutdown();

	FWorldCreatorBridgeCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(WorldCreatorBridgeTabName);
}

FReply FWorldCreatorBridgeModule::SyncButtonClicked()
{

    GEditor->GetSelectedActors()->DeselectAll();

    /*TSharedRef<SCustomDialog> NewLayerDlg =
        SNew(SCustomDialog)
        .Title(FText::FromString("CreateNewLayerInfo"));*/

    // prevent empty path from being loaded
    if (selectedPath.Len() <= 0)
        return FReply::Handled();

    FLevelEditorActionCallbacks::Save();

    // set start values
    if (terrainName.Len() <= 0)
    {
        terrainName = TEXT("WC_Terrain");
    }
    if (terrainName.Len() <= 0)
    {
        terrainName = TEXT("M_Terrain");
    }


    int quadsPerSection = 63;
    const float scaleFactor = 100 * worldScale;
    const float terrainBaseScale = 512.0f;
    auto context = GEditor->GetEditorWorldContext();
    auto world = context.World();
    auto level = world->GetCurrentLevel();



    const FBox AllCellsBox(FVector(-WORLDPARTITION_MAX, -WORLDPARTITION_MAX, -WORLDPARTITION_MAX), FVector(WORLDPARTITION_MAX, WORLDPARTITION_MAX, WORLDPARTITION_MAX));
    if (level)
    {
        if (level->bIsPartitioned)
        {
            world->GetWorldPartition()->LoadEditorCells(AllCellsBox, true); //2097152.0	
        }
        else if (bUseWorldPartition) {
            FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("World Creator Sync", "this map is not configured for world partition, therefore the terrain will be imported as a basic terrain. To enable world partition for this map go to tools->Convert Level..."));
        }
    }
    FString syncDir = FPaths::GetPath(selectedPath);
    auto colormapPath = FString::Printf(TEXT("%s/colormap.png"), syncDir.GetCharArray().GetData());
    // auto normalmapPath = FString::Printf(TEXT("%s/Normalmap.png"), syncDir.GetCharArray().GetData());

    //// Load Config File
    /////////////////////
    FXmlFile configFile(selectedPath);
    auto root = configFile.GetRootNode();
    if (root == NULL)
        return FReply::Handled();
    auto node = root->FindChildNode(TEXT("Surface"));
    if (node == nullptr)
    {
        UE_LOG(LogTemp, Verbose, TEXT("Could not load worldcreator sync config file"));
        configFile.Clear();
        return FReply::Handled();
	}
	// float heightCenter = XmlHelper::GetFloat(node, "HeightCenter");
	// float minHeightScale = XmlHelper::GetFloat(node, "MinHeightScale");
	// float maxHeightScale = XmlHelper::GetFloat(node, "MaxHeightScale");
	float minHeight = XmlHelper::GetFloat(node, "MinHeight");
	float maxHeight = XmlHelper::GetFloat(node, "MaxHeight");
	int width = XmlHelper::GetInt(node, "Width");
	int length = XmlHelper::GetInt(node, "Length");
	int height = XmlHelper::GetInt(node, "Height");
	int resX = XmlHelper::GetInt(node, "ResolutionX");
	int resY = XmlHelper::GetInt(node, "ResolutionY");
	float heightScale = maxHeight - minHeight;
	float terrainScale = ((heightScale * height) / terrainBaseScale) * scaleFactor;
	// float terrainOffset = heightCenter * scaleFactor;

    float scaleX = ((float)width / (resX - 1)) * scaleFactor;
    float scaleY = ((float)length / (resY - 1)) * scaleFactor;

    /// Create Texture
    /////////////////////
    FString MaterialPackageName = "/Game/";
    MaterialPackageName += this->terrainMaterialName;
    UPackage* materialPackage = CreatePackage(NULL, *MaterialPackageName);
    auto MaterialFactory = NewObject<UMaterialFactoryNew>();
    UMaterial* material = (UMaterial*)MaterialFactory->FactoryCreateNew(UMaterial::StaticClass(), materialPackage, *(this->terrainMaterialName), RF_Standalone | RF_Public, NULL, GWarn);
    
    materialPackage->FullyLoad();
    materialPackage->SetDirtyFlag(true);
    FAssetRegistryModule::AssetCreated(material);

    /// Import Textures
    //////////////////////
    FString localPath = "/Game/";
    if (bImportTextures)
    {
        TArray<FString> FilePaths;
        FilePaths.Add(colormapPath);
        // FilePaths.Add(normalmapPath);
        UAutomatedAssetImportData* ImportData = NewObject<UAutomatedAssetImportData>();
        ImportData->bReplaceExisting = true;
        ImportData->DestinationPath = localPath;
        ImportData->Filenames = FilePaths;
        FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
        AssetToolsModule.Get().ImportAssetsAutomated(ImportData);
    }

	/// create layerblend nodes in the material
	/////////////////////////////////////////////
    UMaterialExpressionLandscapeLayerBlend* AlbedoLayerBlend = NewObject<UMaterialExpressionLandscapeLayerBlend>(material);
    material->Expressions.Add(AlbedoLayerBlend);
    UMaterialExpressionLandscapeLayerBlend* NormalLayerBlend = NewObject<UMaterialExpressionLandscapeLayerBlend>(material);
    material->Expressions.Add(NormalLayerBlend);
    UMaterialExpressionLandscapeLayerBlend* AOLayerBlend = NewObject<UMaterialExpressionLandscapeLayerBlend>(material);
    material->Expressions.Add(AOLayerBlend);
    UMaterialExpressionLandscapeLayerBlend* DisplacementLayerBlend = NewObject<UMaterialExpressionLandscapeLayerBlend>(material);
    material->Expressions.Add(DisplacementLayerBlend);
    UMaterialExpressionLandscapeLayerBlend* RoughnessLayerBlend = NewObject<UMaterialExpressionLandscapeLayerBlend>(material);
    material->Expressions.Add(RoughnessLayerBlend);

    material->BaseColor.Expression = AlbedoLayerBlend;
    material->Normal.Expression = NormalLayerBlend;
    material->AmbientOcclusion.Expression = AOLayerBlend;
    material->WorldPositionOffset.Expression = DisplacementLayerBlend;
    material->Roughness.Expression = RoughnessLayerBlend;

	/// add and remap landscape coordinates to the material
	/////////////////////////////////////////////////////////
    UMaterialExpressionLandscapeLayerCoords* LandscapeCoords = NewObject<UMaterialExpressionLandscapeLayerCoords>(material);
    LandscapeCoords->MappingScale = resX;
    LandscapeCoords->MappingRotation = 180.0f;
    material->Expressions.Add(LandscapeCoords);


	/// Create empty texture nodes for the cases where a layer only has colordata. Leaving layers in a layerblend emplty has resulted in render issues
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UMaterialExpressionVectorParameter* emptyNormalVectorParam = NewObject<UMaterialExpressionVectorParameter>(material);
    emptyNormalVectorParam->ParameterName = FName(FString::Printf(TEXT("emptyNormal")));
    material->Expressions.Add(emptyNormalVectorParam);
    material->SetVectorParameterValueEditorOnly(FString::Printf(TEXT("emptyNormal")).GetCharArray().GetData(), FColor(128, 128, 255, 255));
    UMaterialExpressionVectorParameter* emptyAOVectorParam = NewObject<UMaterialExpressionVectorParameter>(material);
    emptyAOVectorParam->ParameterName = FName(FString::Printf(TEXT("emptyAO")));
    material->Expressions.Add(emptyAOVectorParam);
    material->SetVectorParameterValueEditorOnly(FString::Printf(TEXT("emptyAO")).GetCharArray().GetData(), FColor(255, 255, 255, 255));
    UMaterialExpressionVectorParameter* emptyDisplacementVectorParam = NewObject<UMaterialExpressionVectorParameter>(material);
    emptyDisplacementVectorParam->ParameterName = FName(FString::Printf(TEXT("emptyDisplacement")));
    material->Expressions.Add(emptyDisplacementVectorParam);
    material->SetVectorParameterValueEditorOnly(FString::Printf(TEXT("emptyDisplacement")).GetCharArray().GetData(), FColor(0, 0, 0, 255));
    UMaterialExpressionVectorParameter* emptyRoughnessVectorParam = NewObject<UMaterialExpressionVectorParameter>(material);
    emptyRoughnessVectorParam->ParameterName = FName(FString::Printf(TEXT("emptyRoughness")));
    material->Expressions.Add(emptyRoughnessVectorParam);
    material->SetVectorParameterValueEditorOnly(FString::Printf(TEXT("emptyRoughness")).GetCharArray().GetData(), FColor(255, 255, 255, 255));


	/// Create Textures
	//////////////////////

	/// Load Colormap
	//////////////////////
    FStringAssetReference DiffuseAssetPath("/game/colormap");
    UTexture* DiffuseTexture = Cast<UTexture>(DiffuseAssetPath.TryLoad());
    //if (DiffuseTexture)
    //{
    UMaterialExpressionTextureSample* TextureExpression = NewObject<UMaterialExpressionTextureSample>(material);
    TextureExpression->Texture = DiffuseTexture;
    TextureExpression->SamplerType = SAMPLERTYPE_Color;
    material->Expressions.Add(TextureExpression);
    TextureExpression->Coordinates.Expression = LandscapeCoords;

    //// Load Splatmap & Textures
    ///////////////////////////////
    TArray<FLandscapeImportLayerInfo> layerInfos;
    auto texturingNode = root->FindChildNode(TEXT("Texturing"));
    if (texturingNode != nullptr)
    {
        //Load From File
        auto childNodes = texturingNode->GetChildrenNodes();
        int textureCount = 0;

        int currentlayerindex = 0;
        for (auto child : childNodes)
        {
            auto splatmapName = child->GetAttribute(TEXT("Name"));
            auto textures = child->GetChildrenNodes();
            auto filePath = FString::Printf(TEXT("%s/%s"), syncDir.GetCharArray().GetData(), splatmapName.GetCharArray().GetData());

            int fileWidth, fileHeight, fileBpp;
            TArray<uint8> fileData;
            //LoadTGA(filePath.GetCharArray().GetData(), fileData, fileWidth, fileHeight, fileBpp);

            FFileHelper::LoadFileToArray(fileData, filePath.GetCharArray().GetData());
            uint8* dataPtr = (fileData).GetData();
            fileWidth = *(short*)(&dataPtr[12]);
            fileHeight = *(short*)(&dataPtr[14]);
            fileBpp = (*(uint8*)(&dataPtr[16])) / 8;
            (fileData).RemoveAt(0, 18);



            //baseColorMapExpression->A.Expression = TextureExpression;
            //baseColorMapExpression->B.Expression = vectorParam;
        //}




            for (int i = 0; i < textures.Num(); i++)
            {
                float tilescaleX;
                float tilescaleY;
                XmlHelper::GetFloat2(textures[i], "TileSize", &tilescaleX, &tilescaleY);
                TArray<uint8> layerData;
                for (int y = 0; y < fileHeight; y++)
                {
                    for (int x = 0; x < fileWidth; x++)
                    {
                        int multV = ((fileWidth * fileHeight) - ((fileHeight - 1 - y) * fileWidth + x) - 1) * fileBpp;
                        switch (i)
                        {
                        case 0:
                            layerData.Add((fileData)[multV + 2]);
                            break;
                        case 1:
                            layerData.Add((fileData)[multV + 1]);
                            break;
                        case 2:
                            layerData.Add((fileData)[multV]);
                            break;
                        case 3:
                            layerData.Add((fileData)[multV + 3]);
                            break;
                        }
                    }
                }


                FLayerBlendInput albedoLayerBlendInput;
                albedoLayerBlendInput.LayerName = FString::Printf(TEXT("Texture%d"), textureCount).GetCharArray().GetData();
                AlbedoLayerBlend->Layers.Add(albedoLayerBlendInput);
                FLayerBlendInput normalLayerBlendInput;
                normalLayerBlendInput.LayerName = FString::Printf(TEXT("Texture%d"), textureCount).GetCharArray().GetData();
                NormalLayerBlend->Layers.Add(normalLayerBlendInput);
                NormalLayerBlend->GetInput(currentlayerindex)->Expression = emptyNormalVectorParam;
                FLayerBlendInput aoLayerBlendInput;
                aoLayerBlendInput.LayerName = FString::Printf(TEXT("Texture%d"), textureCount).GetCharArray().GetData();
                AOLayerBlend->Layers.Add(aoLayerBlendInput);
                AOLayerBlend->GetInput(currentlayerindex)->Expression = emptyAOVectorParam;
                FLayerBlendInput displacementLayerBlendInput;
                displacementLayerBlendInput.LayerName = FString::Printf(TEXT("Texture%d"), textureCount).GetCharArray().GetData();
                DisplacementLayerBlend->Layers.Add(displacementLayerBlendInput);
                DisplacementLayerBlend->GetInput(currentlayerindex)->Expression = emptyDisplacementVectorParam;
                FLayerBlendInput roughnessLayerBlendInput;
                roughnessLayerBlendInput.LayerName = FString::Printf(TEXT("Texture%d"), textureCount).GetCharArray().GetData();
                RoughnessLayerBlend->Layers.Add(roughnessLayerBlendInput);
                RoughnessLayerBlend->GetInput(currentlayerindex)->Expression = emptyRoughnessVectorParam;



                UPackage* infoPackage = CreatePackage(*FString::Printf(TEXT("/Game/Texture_layerinfo_%d"), textureCount));
                FName LayerObjectName = FName(*FString::Printf(TEXT("Texture_layerinfo_%d"), textureCount));

                ULandscapeLayerInfoObject* LayerInfo = NewObject<ULandscapeLayerInfoObject>(infoPackage, LayerObjectName, RF_Public | RF_Standalone | RF_Transactional);
                
                infoPackage->MarkPackageDirty();
                // FAssetRegistryModule::AssetCreated(LayerInfo);

                FLandscapeImportLayerInfo info;
                info.LayerData = layerData;
                info.LayerName = FString::Printf(TEXT("Texture%d"), textureCount).GetCharArray().GetData();//FName(FString::Printf(TEXT("%s"), textures[i]->GetAttribute("Name").GetCharArray().GetData()).GetCharArray().GetData());

                info.LayerInfo = LayerInfo;
                info.LayerInfo->bNoWeightBlend = 0;
                info.LayerInfo->Hardness = 1;
                info.LayerInfo->IsReferencedFromLoadedData = false;
                info.LayerInfo->LayerName = info.LayerName;

                
                //LayerInfo->LayerName = LayerObjectName;
                //LayerInfo->bNoWeightBlend = 0;
                //
                //// https://blog.csdn.net/weixin_30552811/article/details/98967016
                
                
                layerInfos.Add(info);

                auto textureNode = textures[i];


                // Import Textures 
                TArray<FString> TexturePaths;
                TArray<FString> TexturePathNames;
                auto albedoFile = textureNode->GetAttribute(TEXT("AlbedoFile"));
                auto normalFile = textureNode->GetAttribute(TEXT("NormalFile"));
                auto aoFile = textureNode->GetAttribute(TEXT("AoFile"));
                auto displacementFile = textureNode->GetAttribute(TEXT("DisplacementFile"));
                auto roughnessFile = textureNode->GetAttribute(TEXT("RoughnessFile"));

                if (!albedoFile.IsEmpty())
                {
                    auto albedoPath = FString::Printf(TEXT("%s/Assets/%s"), syncDir.GetCharArray().GetData(), albedoFile.GetCharArray().GetData());
                    TexturePaths.Add(albedoPath);
                    TexturePathNames.Add(albedoFile);
                }
                if (!normalFile.IsEmpty())
                {
                    auto normalPath = FString::Printf(TEXT("%s/Assets/%s"), syncDir.GetCharArray().GetData(), normalFile.GetCharArray().GetData());
                    TexturePaths.Add(normalPath);
                    TexturePathNames.Add(normalFile);
                }
                if (!aoFile.IsEmpty())
                {
                    auto aoPath = FString::Printf(TEXT("%s/Assets/%s"), syncDir.GetCharArray().GetData(), aoFile.GetCharArray().GetData());
                    TexturePaths.Add(aoPath);
                    TexturePathNames.Add(aoFile);
                }
                if (!displacementFile.IsEmpty())
                {
                    auto displacementPath = FString::Printf(TEXT("%s/Assets/%s"), syncDir.GetCharArray().GetData(), displacementFile.GetCharArray().GetData());
                    TexturePaths.Add(displacementPath);
                    TexturePathNames.Add(displacementFile);
                }
                if (!roughnessFile.IsEmpty())
                {
                    auto roughnessPath = FString::Printf(TEXT("%s/Assets/%s"), syncDir.GetCharArray().GetData(), roughnessFile.GetCharArray().GetData());
                    TexturePaths.Add(roughnessPath);
                    TexturePathNames.Add(roughnessFile);
                }

                if (TexturePaths.Num() > 0)
                {
                    if (bImportTextures)
                    {
                        UAutomatedAssetImportData* TextureImportData = NewObject<UAutomatedAssetImportData>();
                        TextureImportData->bReplaceExisting = true;
                        TextureImportData->DestinationPath = localPath;
                        TextureImportData->Filenames = TexturePaths;
                        FAssetToolsModule& TextureAssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");

                        auto importedTextureFiles = TextureAssetToolsModule.Get().ImportAssetsAutomated(TextureImportData);
                    }

                    FString colorAtt = textureNode->GetAttribute(TEXT("Color")).GetCharArray().GetData();

                    colorAtt.RemoveFromStart(TEXT("#ff"));
                    FLinearColor color = FLinearColor(FColor::FromHex(colorAtt));

                    UMaterialExpressionVectorParameter* vectorParam = NewObject<UMaterialExpressionVectorParameter>(material);
                    vectorParam->ParameterName = FName(FString::Printf(TEXT("Color%d"), textureCount));
                    material->Expressions.Add(vectorParam);
                    material->SetVectorParameterValueEditorOnly(FString::Printf(TEXT("Color%d"), textureCount).GetCharArray().GetData(), color);

                    auto connectTextureLambda = [material, LandscapeCoords, vectorParam, tilescaleX, tilescaleY](UTexture2D* currentTexture)
                    {
                        UMaterialExpressionTextureSample* currentExpression = NewObject<UMaterialExpressionTextureSample>(material);
                        currentExpression->Texture = currentTexture;
                        material->Expressions.Add(currentExpression);
                        UMaterialExpressionMultiply* multExp = NewObject<UMaterialExpressionMultiply>(material);
                        UMaterialExpressionConstant2Vector* vec2Exp = NewObject<UMaterialExpressionConstant2Vector>(material);
                        material->Expressions.Add(multExp);
                        material->Expressions.Add(vec2Exp);
                        vec2Exp->R = tilescaleX;
                        vec2Exp->G = tilescaleY;
                        multExp->A.Expression = LandscapeCoords;
                        multExp->B.Expression = vec2Exp;
                        currentExpression->Coordinates.Expression = multExp;

                        return currentExpression;
                    };

                    for (int k = 0; k < TexturePathNames.Num(); k++)
                    {
                        FString currentfile;
                        FString _;
                        TexturePathNames[k].Split(TEXT("."), &currentfile, &_);

                        if (currentfile.EndsWith(TEXT("Albedo")))
                        {
                            FStringAssetReference currentAssetPath(FString::Printf(TEXT("/WorldCreatorBridge/%s"), currentfile.GetCharArray().GetData()));
                            UTexture2D* currentTex = Cast<UTexture2D>(currentAssetPath.TryLoad());
                            if (currentTex)
                            {
                                UMaterialExpressionMultiply* multEx = NewObject<UMaterialExpressionMultiply>(material);
                                material->Expressions.Add(multEx);
                                multEx->A.Expression = connectTextureLambda(currentTex);
                                multEx->B.Expression = vectorParam;

                                AlbedoLayerBlend->GetInput(currentlayerindex)->Expression = multEx;
                            }
                            else AlbedoLayerBlend->GetInput(currentlayerindex)->Expression = TextureExpression;
                        }
                        else if (currentfile.EndsWith(TEXT("Normal")))
                        {

                            FStringAssetReference currentAssetPath(FString::Printf(TEXT("/WorldCreatorBridge/%s"), currentfile.GetCharArray().GetData()));
                            UTexture2D* currentTex = Cast<UTexture2D>(currentAssetPath.TryLoad());
                            if (currentTex)
                            {
                                currentTex->SRGB = 0;
                                currentTex->CompressionSettings = TC_Normalmap;
                                auto ne = connectTextureLambda(currentTex);
                                NormalLayerBlend->GetInput(currentlayerindex)->Expression = ne;
                                ne->SamplerType = SAMPLERTYPE_Normal;
                            }
                            else NormalLayerBlend->GetInput(currentlayerindex)->Expression = emptyNormalVectorParam;
                        }
                        else if (currentfile.EndsWith(TEXT("Ao")))
                        {
                            FStringAssetReference currentAssetPath(FString::Printf(TEXT("/WorldCreatorBridge/%s"), currentfile.GetCharArray().GetData()));
                            UTexture2D* currentTex = Cast<UTexture2D>(currentAssetPath.TryLoad());
                            if (currentTex)
                                AOLayerBlend->GetInput(currentlayerindex)->Expression = connectTextureLambda(currentTex);
                            else AOLayerBlend->GetInput(currentlayerindex)->Expression = emptyAOVectorParam;
                        }
                        else if (currentfile.EndsWith(TEXT("Displacement")))
                        {
                            FStringAssetReference currentAssetPath(FString::Printf(TEXT("/WorldCreatorBridge/%s"), currentfile.GetCharArray().GetData()));
                            UTexture2D* currentTex = Cast<UTexture2D>(currentAssetPath.TryLoad());
                            if (currentTex)
                            {
                                UMaterialExpressionTextureSample* nd = connectTextureLambda(currentTex);
                                nd->SamplerType = SAMPLERTYPE_LinearColor;
                                DisplacementLayerBlend->GetInput(currentlayerindex)->Expression = nd;
                            }
                            else DisplacementLayerBlend->GetInput(currentlayerindex)->Expression = emptyDisplacementVectorParam;
                        }
                        else if (currentfile.EndsWith(TEXT("Roughness")))
                        {
                            FStringAssetReference currentAssetPath(FString::Printf(TEXT("/WorldCreatorBridge/%s"), currentfile.GetCharArray().GetData()));
                            UTexture2D* currentTex = Cast<UTexture2D>(currentAssetPath.TryLoad());
                            if (currentTex)
                                RoughnessLayerBlend->GetInput(currentlayerindex)->Expression = connectTextureLambda(currentTex);
                            else RoughnessLayerBlend->GetInput(currentlayerindex)->Expression = emptyRoughnessVectorParam;
                        }
                    }
                }
                else
                {
                    AlbedoLayerBlend->GetInput(currentlayerindex)->Expression = TextureExpression;
                }

                textureCount++;
                currentlayerindex++;
            }
        }
    }

    
    //// Cleanup Material
    ///////////////////////
    // Let the material update itself if necessary
    for (UMaterialExpression* v : material->Expressions)
    {
        if (v->GetOutputs().Num() <= 0)
            material->Expressions.Remove(v);
    }

    material->PreEditChange(NULL);
    material->PostEditChange();
    // make sure that any static meshes, etc using this material will stop using the FMaterialResource of the original
    // material, and will use the new FMaterialResource created when we make a new UMaterial in place
    //FGlobalComponentReregisterContext RecreateComponents;


    //// Create Landscape
    ///////////////////////
    auto landscapeClass = ALandscape::StaticClass();
    auto gizmoClass = ALandscapeGizmoActiveActor::StaticClass();
    ALandscape* landscapeActor = nullptr;
    ALandscapeGizmoActiveActor* landscapeGizmo = nullptr;



    //// Find existing landscape
    ////////////////////////////
    auto actorIter = FActorIterator(world);
    bool actorfound = false;
    while (actorIter)
    {
        if (actorIter->GetClass() == landscapeClass && actorIter->GetActorLabel() == terrainName)
        {
            landscapeActor = Cast<ALandscape>(*actorIter);
            if (actorfound) break;
            else actorfound = true;
        }
        ++actorIter;
    }

    //// Find existing gizmo
    ////////////////////////
    if (landscapeActor != nullptr)
    {
        actorIter = FActorIterator(world);
        while (actorIter)
        {
            if (actorIter->GetClass() == gizmoClass)
            {
                auto gizmo = Cast<ALandscapeGizmoActiveActor>(*actorIter);
                if (gizmo->TargetLandscapeInfo == landscapeActor->GetLandscapeInfo())
                {
                    landscapeGizmo = gizmo;
                    break;
                }
            }
            ++actorIter;
        }
    }


    //// Load Heightmap
    ///////////////////
    auto heightmapPath = FString::Printf(TEXT("%s/heightmap.raw"), syncDir.GetCharArray().GetData());
    TArray<uint8> file;
    FFileHelper::LoadFileToArray(file, heightmapPath.GetCharArray().GetData());

    uint16* originalData = (uint16*)file.GetData();
    TArray<uint16> heightData;
    heightData.Init(0, resX * resY);
    
    for (int y = 0; y < resY; y++)
    {
        for (int x = 0; x < resX; x++)
        {
            if (y * resX + x < (file.Num() / 2))
            {
                if (y == 1904)
                    int tmp = 1;
                heightData[y * resX + (resX - 1) - x] = originalData[y * resX + x];  //x < resX / 2 ? 0 : 0xFFFF;
            }
            else
            {
                FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("World Creator Sync", "Please disable all export areas in your World Creator Project. Currently there is a bug which prevents this functionality to work with the bridge"));
                configFile.Clear();
                return FReply::Handled();
            }
        }
    }
    const FGuid landscapeGuid = FGuid::FGuid();

    TMap<FGuid, TArray<uint16>> heightDataMap;
    TMap<FGuid, TArray<FLandscapeImportLayerInfo>> layerInfosMap;
    heightDataMap.Add(landscapeGuid, heightData);
    layerInfosMap.Add(landscapeGuid, MoveTemp(layerInfos));

    if (landscapeActor != nullptr)
    {
        if (landscapeGizmo != nullptr)
            landscapeGizmo->Destroy();

        auto name = landscapeActor->GetName();
        auto location = landscapeActor->GetActorLocation();
        auto rotation = landscapeActor->GetActorRotation();
        //material = landscapeActor->GetLandscapeMaterial();
        //location.Z = terrainOffset;


        auto actorIterforProxy = FActorIterator(world);
        ALandscapeStreamingProxy* streamingProxy = nullptr;
        auto streamProxyClass = ALandscapeStreamingProxy::StaticClass();

        while (actorIterforProxy)
        {
            if (actorIterforProxy->GetClass() == streamProxyClass)
            {
                streamingProxy = Cast<ALandscapeStreamingProxy>(*actorIterforProxy);
                if (streamingProxy->GetLandscapeActor()->GetActorLabel() == terrainName) 
                {
                    streamingProxy->Destroy();
                }
            }
            ++actorIterforProxy;
        }
        landscapeActor->Destroy();

        FActorSpawnParameters spawnParams;
        spawnParams.Name = name.GetCharArray().GetData();
        landscapeActor = world->SpawnActor<ALandscape>(location, rotation);
        landscapeActor->SetLandscapeGuid(FGuid::NewGuid());
        landscapeActor->LandscapeMaterial = material;
        landscapeActor->StaticLightingLOD = FMath::DivideAndRoundUp(FMath::CeilLogTwo((resX * resY) / (2048 * 2048) + 1), (uint32)2);

        landscapeActor->Import(FGuid::NewGuid(), 0, 0, resX - 1, resY - 1, 1, quadsPerSection,
            heightDataMap, L"", layerInfosMap, ELandscapeImportAlphamapType::Additive);
        auto info = landscapeActor->CreateLandscapeInfo();
        landscapeGizmo = world->SpawnActor<ALandscapeGizmoActiveActor>(location, rotation);
        landscapeGizmo->SetTargetLandscape(info);
        info->UpdateLayerInfoMap(landscapeActor, true);
        landscapeActor->SetActorScale3D(FVector(scaleX, scaleY, terrainScale));
        landscapeActor->SetActorLabel(terrainName, false);
        if(bUseWorldPartition)
            world->GetSubsystem<ULandscapeSubsystem>()->ChangeGridSize(info, worldPartitionGridSize);
    }
    else
    {
        FVector location(0, 0, 0);
        FRotator rotation(0, 0, 0);
        landscapeActor = world->SpawnActor<ALandscape>(location, rotation);
        if (material != nullptr)
            landscapeActor->LandscapeMaterial = (UMaterialInterface*)material;
        landscapeActor->StaticLightingLOD = FMath::DivideAndRoundUp(FMath::CeilLogTwo((resX * resY) / (2048 * 2048) + 1), (uint32)2);
        landscapeActor->SetLandscapeGuid(FGuid::NewGuid());
        landscapeActor->Import(FGuid::NewGuid(), 0, 0, resX - 1, resY - 1, 1, quadsPerSection,
            heightDataMap, L"", layerInfosMap, ELandscapeImportAlphamapType::Additive);
        auto info = landscapeActor->CreateLandscapeInfo();
        landscapeActor->SetActorScale3D(FVector(scaleX, scaleY, terrainScale));
        landscapeActor->SetActorLocation(FVector(-(scaleX * (resX-1)) / 2, -(scaleY * (resY-1)) / 2, 0));
        landscapeActor->SetActorLabel(terrainName, false);
        if(bUseWorldPartition)
            world->GetSubsystem<ULandscapeSubsystem>()->ChangeGridSize(info, worldPartitionGridSize);
    }

    for (int li = 0; li < layerInfos.Num(); li++) 
    {
        landscapeActor->EditorLayerSettings.Add(FLandscapeEditorLayerSettings(layerInfos[li].LayerInfo));
    }



    //// save level
    FLevelEditorActionCallbacks::Save();
    if (bBuildMinimap && bUseWorldPartition)
        FLevelEditorActionCallbacks::BuildMinimap_Execute();

    //    // Cleanup memory  
    //    ////////////////
    configFile.Clear();

    return FReply::Handled();
}

FReply FWorldCreatorBridgeModule::BrowseButtonClicked()
{
    TArray<FString> filenames;
    if (FDesktopPlatformModule::Get()->OpenFileDialog(nullptr,
        TEXT("Select World Creator Bridge .xml file "), TEXT(""), TEXT(""), TEXT("World Creator Bridge File | *.xml"), 0, filenames))
    {
        this->selectedPath = filenames[0];
        selectedPathBox->SetText(FText::FromString(selectedPath));
    }
    return FReply::Handled();
}

const bool FWorldCreatorBridgeModule::GetIsButtonEnabled()
{
	return !this->selectedPath.IsEmpty();
}

TSharedRef<SDockTab> FWorldCreatorBridgeModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
    return SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
        [
            SNew(SScrollBox)
            // SNew(SVerticalBox)
            // + SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center)
        + SScrollBox::Slot().HAlign(HAlign_Center)
        [
            SNew(SButton).ButtonStyle(wcButton).OnClicked(
                FOnClicked::CreateLambda([]
                    {
                        system("start https://www.world-creator.com/");
                        return FReply::Handled();
                    }))
        ]
    + SScrollBox::Slot().HAlign(HAlign_Center)
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SButton).ButtonStyle(facebookButton).OnClicked(
                FOnClicked::CreateLambda([]
                    {
                        system("start https://www.facebook.com/worldcreator3d/");
                        return FReply::Handled();
                    }))
        ]

    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SButton).ButtonStyle(twitterButton).OnClicked(
                FOnClicked::CreateLambda([]
                    {
                        system("start https://twitter.com/worldcreator3d/");
                        return FReply::Handled();
                    }))
        ]

    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SButton).ButtonStyle(instagramButton).OnClicked(
                FOnClicked::CreateLambda([]
                    {
                        system("start https://www.instagram.com/worldcreator3d/");
                        return FReply::Handled();
                    }))
        ]

    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SButton).ButtonStyle(youtubeButton).OnClicked(
                FOnClicked::CreateLambda([]
                    {
                        system("start https://www.youtube.com/channel/UClabqa6PHVjXzR2Y7s1MP0Q/");
                        return FReply::Handled();
                    }))
        ]
        ]
    + SScrollBox::Slot().HAlign(HAlign_Center)
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SButton).ButtonStyle(vimeoButton).OnClicked(
                FOnClicked::CreateLambda([]
                    {
                        system("start https://vimeo.com/user82114310/");
                        return FReply::Handled();
                    }))
        ]
    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SButton).ButtonStyle(twitchButton).OnClicked(
                FOnClicked::CreateLambda([]
                    {
                        system("start https://www.twitch.tv/worldcreator3d/");
                        return FReply::Handled();
                    }))
        ]
    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SButton).ButtonStyle(artstationButton).OnClicked(
                FOnClicked::CreateLambda([]
                    {
                        system("start https://www.artstation.com/worldcreator/");
                        return FReply::Handled();
                    }))
        ]
    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SButton).ButtonStyle(discordButton).OnClicked(
                FOnClicked::CreateLambda([]
                    {
                        system("start https://discordapp.com/invite/bjMteus");
                        return FReply::Handled();
                    }))
        ]
        ]

    //+ SVerticalBox::Slot().HAlign(HAlign_Center)
    //  [
    //    SNew(SContentReference)
    //    .OnSetReference(SContentReference::FOnSetReference::CreateRaw(this, &FWorldCreatorSyncModule::OnSetReference))
    //    .AllowSelectingNewAsset(true)
    //    .AllowClearingReference(true)      
    //    //.AllowedClass(UStaticMesh::StaticClass())
    //    .AssetReference(meshReference)
    //  ]
    +SScrollBox::Slot().HAlign(HAlign_Left).Padding(FMargin(10.0f, 10.0f, 10.0f, 10.0f))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().FillWidth(1)
        [
            SNew(STextBlock).Text(FText::FromString(FString::Printf(TEXT("If you moved the sync folder, please select your \nBridge.xml file here. Its default location is \n[USER]/Documents/World Creator/Sync/bridge.xml"))))
            .ToolTipText(FText::FromString("By default the path points to the World Creator Sync Folder. You only need to change it if you want to sync a file from a different location."))
        ]
        ]
    + SScrollBox::Slot().Padding(10, 0, 10, 5)
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().FillWidth(1)
        [
            SNew(SButton)
            .Text(FText::FromString("Select Bridge File")).OnClicked(
                FOnClicked::CreateRaw(this, &FWorldCreatorBridgeModule::BrowseButtonClicked))
        .ToolTipText(FText::FromString("By default the path points to the World Creator Sync Folder. You only need to change it if you want to sync a file from a different location."))
        ]
        ]
    + SScrollBox::Slot().Padding(10, 0, 10, 35)
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().FillWidth(1)
        [
            SAssignNew(selectedPathBox, SEditableTextBox)
            .Text(FText::FromString(selectedPath))
        .IsReadOnly(true)

        ]
        ]
    + SScrollBox::Slot().Padding(FMargin(10.0f, 10.0f, 10.0f, 0.0f))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SBox).WidthOverride(100)
            [
            SNew(STextBlock).Text(FText::FromString("Actor Name"))
            .ToolTipText(FText::FromString("Name of the Actor that holds your terrain Object"))
            ]
        ]
    + SHorizontalBox::Slot().FillWidth(1)
        [
            SNew(SEditableTextBox).Text(FText::FromString("WC_Terrain")).OnTextChanged(
                FOnTextChanged::CreateLambda([this](const FText& InText)
                    {
                        this->terrainName = InText.ToString();
                    }
                )
            )
        ]
        ]
    + SScrollBox::Slot().Padding(FMargin(10.0f, 10.0f, 10.0f, 0.0f))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SBox).WidthOverride(100)
            [
            SNew(STextBlock).Text(FText::FromString("Material Name"))
            .ToolTipText(FText::FromString("Name of the material created for the Landscape"))
            ]
        ]
    + SHorizontalBox::Slot().FillWidth(1)
        [
            SNew(SEditableTextBox).Text(FText::FromString("M_Terrain")).OnTextChanged(
                FOnTextChanged::CreateLambda([this](const FText& InText)
                    {
                        this->terrainMaterialName = InText.ToString();
                    }
                )
            )
        ]
        ]
    + SScrollBox::Slot().HAlign(HAlign_Left).Padding(FMargin(10.0f, 10.0f, 0.0f, 0.0f))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SBox).WidthOverride(100)
            [
            SNew(STextBlock).Text(FText::FromString("Import Textures"))
            .ToolTipText(FText::FromString("Choose whether textures are automatically imported."))
            ]
        ]

    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SCheckBox).IsChecked(ECheckBoxState::Checked).OnCheckStateChanged(
                FOnCheckStateChanged::CreateLambda([this](const ECheckBoxState& state)
                    {
                        this->bImportTextures = state == ECheckBoxState::Checked;
                    })
            )
        ]
        ]

	+ SScrollBox::Slot().HAlign(HAlign_Left).Padding(FMargin(10.0f, 10.0f, 0.0f, 0.0f))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()
		[
			SNew(SBox).WidthOverride(100)
			[
				SNew(STextBlock).Text(FText::FromString("World Partition"))
				.ToolTipText(FText::FromString("Choose whether to import the entire heightmap or to split it to enable world partition"))
			]
		]

	+ SHorizontalBox::Slot().AutoWidth()
		[
			SNew(SCheckBox).IsChecked(ECheckBoxState::Unchecked).OnCheckStateChanged(
				FOnCheckStateChanged::CreateLambda([this](const ECheckBoxState& state)
					{
						this->bUseWorldPartition = state == ECheckBoxState::Checked;
					})
			)
		]
		]
    + SScrollBox::Slot().HAlign(HAlign_Left).Padding(FMargin(0.0f, 10.0f, 0.0f, 0.0f))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().AutoWidth().Padding(10.0f, 0, 0, 0)
        [
            SNew(SBox).WidthOverride(100)
            [
                SNew(STextBlock).Text(FText::FromString("Grid Size"))
                .ToolTipText(FText::FromString("Set the world partition grid size"))
            ]
        ]

    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SNumericEntryBox<int>)
            .AllowSpin(true)
        .MinValue(1)
        .MaxValue(16)
        .Value_Raw(this, &FWorldCreatorBridgeModule::GetGridSizeDelta)
        .MinSliderValue(1)
        .MaxSliderValue(16)
        .OnValueChanged(FOnInt32ValueChanged::CreateLambda([this](int value)
            {
                this->worldPartitionGridSize = value;
            }))

        ]
        ]
    + SScrollBox::Slot().HAlign(HAlign_Left).Padding(FMargin(10.0f, 10.0f, 0.0f, 0.0f))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SBox).WidthOverride(100)
            [
                SNew(STextBlock).Text(FText::FromString("Build Minimap"))
                .ToolTipText(FText::FromString("Choose Weather to build the World Partition Minimap or not."))
            ]
        ]

    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SCheckBox).IsChecked(ECheckBoxState::Checked).OnCheckStateChanged(
                FOnCheckStateChanged::CreateLambda([this](const ECheckBoxState& state)
                    {
                        this->bBuildMinimap = state == ECheckBoxState::Checked;
                    })
            )
        ]
        ]
    //+ SVerticalBox::Slot().HAlign(HAlign_Left).AutoHeight()
    //	[
    //		SNew(SHorizontalBox)
    //		+ SHorizontalBox::Slot().AutoWidth()
    //	[
    //		SNew(STextBlock).Text(FText::FromString("Clamp Values"))
    //		.ToolTipText(FText::FromString("If the terrain size you would like to synchronize does not follow the power-of-two + 1 rule of Unreal terrain system, you can choose to clamp the values."))
    //	]
    /*+ SHorizontalBox::Slot().AutoWidth().Padding(FMargin(41.0f, 0.0f, 0.0f, 0.0f))
        [
            SNew(SCheckBox)
        ]
        ]*/
    +SScrollBox::Slot().HAlign(HAlign_Left).Padding(FMargin(0.0f, 10.0f, 0.0f, 0.0f))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot().AutoWidth().Padding(10.0f, 0, 0, 0)
        [
            SNew(SBox).WidthOverride(100)
            [
            SNew(STextBlock).Text(FText::FromString("World Scale"))
            .ToolTipText(FText::FromString("Allows you to scale the terrain to a different value."))
            ]
        ]

    + SHorizontalBox::Slot().AutoWidth()
        [
            SNew(SNumericEntryBox<float>)
            .AllowSpin(true)
        .MinValue(0)
        .MaxValue(1000)
        .Value_Raw(this, &FWorldCreatorBridgeModule::GetTransformDelta)
        .MinSliderValue(0)
        .MaxSliderValue(1000)
        .OnValueChanged(FOnFloatValueChanged::CreateLambda([this](float value)
            {
                this->worldScale = value;
            }))

        ]
        ]


    + SScrollBox::Slot()
        [
            SNew(SBox).HeightOverride(60.0f)
            [
                SNew(SHorizontalBox)
                + SHorizontalBox::Slot().FillWidth(1).Padding(10, 20, 10, 0)
        [
            SNew(SButton)
            .OnClicked(FOnClicked::CreateRaw(
                this, &FWorldCreatorBridgeModule::SyncButtonClicked))
        [
            SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)
            [
                SNew(STextBlock)
                .Text(FText::FromString("Synchronize"))
            ]
        ]
        ]
            ]
        ]
        ];
}

void FWorldCreatorBridgeModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(WorldCreatorBridgeTabName);
}

void FWorldCreatorBridgeModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FWorldCreatorBridgeCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FWorldCreatorBridgeCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}


TOptional<float> FWorldCreatorBridgeModule::GetTransformDelta() const
{
    return worldScale;
}

TOptional<int> FWorldCreatorBridgeModule::GetGridSizeDelta() const
{
    return worldPartitionGridSize;
}

TOptional<FString> FWorldCreatorBridgeModule::GetSelectedPath() const
{
    return selectedPath;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWorldCreatorBridgeModule, WorldCreatorBridge)