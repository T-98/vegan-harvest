// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VeganZombieCropApocalypse/PawnSwitcher.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePawnSwitcher() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_VeganZombieCropApocalypse();
	VEGANZOMBIECROPAPOCALYPSE_API UClass* Z_Construct_UClass_UPawnSwitcher();
	VEGANZOMBIECROPAPOCALYPSE_API UClass* Z_Construct_UClass_UPawnSwitcher_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UPawnSwitcher::execSwitchPawn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SwitchPawn();
		P_NATIVE_END;
	}
	void UPawnSwitcher::StaticRegisterNativesUPawnSwitcher()
	{
		UClass* Class = UPawnSwitcher::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SwitchPawn", &UPawnSwitcher::execSwitchPawn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPawnSwitcher_SwitchPawn_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPawnSwitcher_SwitchPawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PawnSwitcher.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPawnSwitcher_SwitchPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPawnSwitcher, nullptr, "SwitchPawn", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPawnSwitcher_SwitchPawn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPawnSwitcher_SwitchPawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPawnSwitcher_SwitchPawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPawnSwitcher_SwitchPawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPawnSwitcher);
	UClass* Z_Construct_UClass_UPawnSwitcher_NoRegister()
	{
		return UPawnSwitcher::StaticClass();
	}
	struct Z_Construct_UClass_UPawnSwitcher_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPawnTag_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_CurrentPawnTag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OtherPawnTag_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_OtherPawnTag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBlendTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraBlendTime;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPawnSwitcher_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VeganZombieCropApocalypse,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPawnSwitcher_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPawnSwitcher_SwitchPawn, "SwitchPawn" }, // 1725826892
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPawnSwitcher_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "PawnSwitcher.h" },
		{ "ModuleRelativePath", "PawnSwitcher.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CurrentPawnTag_MetaData[] = {
		{ "Category", "Pawn Switcher Tags" },
		{ "Comment", "// A variable that stores the tag for the current pawn. Warning! should be set in construction script of the pawn blueprint\n" },
		{ "ModuleRelativePath", "PawnSwitcher.h" },
		{ "ToolTip", "A variable that stores the tag for the current pawn. Warning! should be set in construction script of the pawn blueprint" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CurrentPawnTag = { "CurrentPawnTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPawnSwitcher, CurrentPawnTag), METADATA_PARAMS(Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CurrentPawnTag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CurrentPawnTag_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_OtherPawnTag_MetaData[] = {
		{ "Category", "Pawn Switcher Tags" },
		{ "Comment", "// A variable that stores the tag for the other pawn. Warning! should be set in construction script of the pawn blueprint\n" },
		{ "ModuleRelativePath", "PawnSwitcher.h" },
		{ "ToolTip", "A variable that stores the tag for the other pawn. Warning! should be set in construction script of the pawn blueprint" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_OtherPawnTag = { "OtherPawnTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPawnSwitcher, OtherPawnTag), METADATA_PARAMS(Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_OtherPawnTag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_OtherPawnTag_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CameraBlendTime_MetaData[] = {
		{ "Category", "Switch Variables" },
		{ "Comment", "// A variable that stores the blend time for the camera transition in seconds\n" },
		{ "ModuleRelativePath", "PawnSwitcher.h" },
		{ "ToolTip", "A variable that stores the blend time for the camera transition in seconds" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CameraBlendTime = { "CameraBlendTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPawnSwitcher, CameraBlendTime), METADATA_PARAMS(Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CameraBlendTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CameraBlendTime_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPawnSwitcher_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CurrentPawnTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_OtherPawnTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPawnSwitcher_Statics::NewProp_CameraBlendTime,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPawnSwitcher_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPawnSwitcher>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPawnSwitcher_Statics::ClassParams = {
		&UPawnSwitcher::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPawnSwitcher_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPawnSwitcher_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPawnSwitcher_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPawnSwitcher_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPawnSwitcher()
	{
		if (!Z_Registration_Info_UClass_UPawnSwitcher.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPawnSwitcher.OuterSingleton, Z_Construct_UClass_UPawnSwitcher_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPawnSwitcher.OuterSingleton;
	}
	template<> VEGANZOMBIECROPAPOCALYPSE_API UClass* StaticClass<UPawnSwitcher>()
	{
		return UPawnSwitcher::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPawnSwitcher);
	UPawnSwitcher::~UPawnSwitcher() {}
	struct Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_PawnSwitcher_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_PawnSwitcher_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPawnSwitcher, UPawnSwitcher::StaticClass, TEXT("UPawnSwitcher"), &Z_Registration_Info_UClass_UPawnSwitcher, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPawnSwitcher), 1404592431U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_PawnSwitcher_h_3781671396(TEXT("/Script/VeganZombieCropApocalypse"),
		Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_PawnSwitcher_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_PawnSwitcher_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
