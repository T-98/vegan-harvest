// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VeganZombieCropApocalypse/Recipebuilder.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRecipebuilder() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_VeganZombieCropApocalypse();
	VEGANZOMBIECROPAPOCALYPSE_API UClass* Z_Construct_UClass_URecipebuilder();
	VEGANZOMBIECROPAPOCALYPSE_API UClass* Z_Construct_UClass_URecipebuilder_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(URecipebuilder::execGetValueArray)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetValueArray();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecipebuilder::execGetKeyArray)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FName>*)Z_Param__Result=P_THIS->GetKeyArray();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecipebuilder::execResetRecipeMap)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetRecipeMap();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecipebuilder::execIsRecipeComplete)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsRecipeComplete();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecipebuilder::execUpdateRecipeUI)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateRecipeUI();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecipebuilder::execCreateRecipe)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateRecipe();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecipebuilder::execStringifyMap)
	{
		P_GET_TMAP_REF(FName,int32,Z_Param_Out_map_);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->StringifyMap(Z_Param_Out_map_);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecipebuilder::execGetRecipeMap)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FName,int32>*)Z_Param__Result=P_THIS->GetRecipeMap();
		P_NATIVE_END;
	}
	void URecipebuilder::StaticRegisterNativesURecipebuilder()
	{
		UClass* Class = URecipebuilder::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateRecipe", &URecipebuilder::execCreateRecipe },
			{ "GetKeyArray", &URecipebuilder::execGetKeyArray },
			{ "GetRecipeMap", &URecipebuilder::execGetRecipeMap },
			{ "GetValueArray", &URecipebuilder::execGetValueArray },
			{ "IsRecipeComplete", &URecipebuilder::execIsRecipeComplete },
			{ "ResetRecipeMap", &URecipebuilder::execResetRecipeMap },
			{ "StringifyMap", &URecipebuilder::execStringifyMap },
			{ "UpdateRecipeUI", &URecipebuilder::execUpdateRecipeUI },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_URecipebuilder_CreateRecipe_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecipebuilder_CreateRecipe_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Recipebuilder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecipebuilder_CreateRecipe_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecipebuilder, nullptr, "CreateRecipe", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecipebuilder_CreateRecipe_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_CreateRecipe_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecipebuilder_CreateRecipe()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecipebuilder_CreateRecipe_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics
	{
		struct Recipebuilder_eventGetKeyArray_Parms
		{
			TArray<FName> ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(Recipebuilder_eventGetKeyArray_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Recipebuilder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecipebuilder, nullptr, "GetKeyArray", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::Recipebuilder_eventGetKeyArray_Parms), Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecipebuilder_GetKeyArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecipebuilder_GetKeyArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics
	{
		struct Recipebuilder_eventGetRecipeMap_Parms
		{
			TMap<FName,int32> ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(Recipebuilder_eventGetRecipeMap_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Recipebuilder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecipebuilder, nullptr, "GetRecipeMap", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::Recipebuilder_eventGetRecipeMap_Parms), Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecipebuilder_GetRecipeMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecipebuilder_GetRecipeMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics
	{
		struct Recipebuilder_eventGetValueArray_Parms
		{
			TArray<int32> ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(Recipebuilder_eventGetValueArray_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Recipebuilder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecipebuilder, nullptr, "GetValueArray", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::Recipebuilder_eventGetValueArray_Parms), Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecipebuilder_GetValueArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecipebuilder_GetValueArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics
	{
		struct Recipebuilder_eventIsRecipeComplete_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Recipebuilder_eventIsRecipeComplete_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(Recipebuilder_eventIsRecipeComplete_Parms), &Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Recipebuilder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecipebuilder, nullptr, "IsRecipeComplete", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::Recipebuilder_eventIsRecipeComplete_Parms), Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecipebuilder_IsRecipeComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecipebuilder_IsRecipeComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecipebuilder_ResetRecipeMap_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecipebuilder_ResetRecipeMap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Recipebuilder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecipebuilder_ResetRecipeMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecipebuilder, nullptr, "ResetRecipeMap", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecipebuilder_ResetRecipeMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_ResetRecipeMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecipebuilder_ResetRecipeMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecipebuilder_ResetRecipeMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics
	{
		struct Recipebuilder_eventStringifyMap_Parms
		{
			TMap<FName,int32> map_;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_map__ValueProp;
		static const UECodeGen_Private::FNamePropertyParams NewProp_map__Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_map__MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_map_;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_map__ValueProp = { "map_", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_map__Key_KeyProp = { "map__Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_map__MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_map_ = { "map_", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(Recipebuilder_eventStringifyMap_Parms, map_), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_map__MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_map__MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(Recipebuilder_eventStringifyMap_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_map__ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_map__Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_map_,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Recipebuilder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecipebuilder, nullptr, "StringifyMap", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::Recipebuilder_eventStringifyMap_Parms), Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecipebuilder_StringifyMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecipebuilder_StringifyMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecipebuilder_UpdateRecipeUI_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecipebuilder_UpdateRecipeUI_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Recipebuilder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecipebuilder_UpdateRecipeUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecipebuilder, nullptr, "UpdateRecipeUI", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecipebuilder_UpdateRecipeUI_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecipebuilder_UpdateRecipeUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecipebuilder_UpdateRecipeUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecipebuilder_UpdateRecipeUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URecipebuilder);
	UClass* Z_Construct_UClass_URecipebuilder_NoRegister()
	{
		return URecipebuilder::StaticClass();
	}
	struct Z_Construct_UClass_URecipebuilder_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URecipebuilder_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VeganZombieCropApocalypse,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_URecipebuilder_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_URecipebuilder_CreateRecipe, "CreateRecipe" }, // 46332662
		{ &Z_Construct_UFunction_URecipebuilder_GetKeyArray, "GetKeyArray" }, // 133546511
		{ &Z_Construct_UFunction_URecipebuilder_GetRecipeMap, "GetRecipeMap" }, // 543425410
		{ &Z_Construct_UFunction_URecipebuilder_GetValueArray, "GetValueArray" }, // 1448324520
		{ &Z_Construct_UFunction_URecipebuilder_IsRecipeComplete, "IsRecipeComplete" }, // 1015150212
		{ &Z_Construct_UFunction_URecipebuilder_ResetRecipeMap, "ResetRecipeMap" }, // 732120994
		{ &Z_Construct_UFunction_URecipebuilder_StringifyMap, "StringifyMap" }, // 3900536912
		{ &Z_Construct_UFunction_URecipebuilder_UpdateRecipeUI, "UpdateRecipeUI" }, // 1122051713
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecipebuilder_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Recipebuilder.h" },
		{ "ModuleRelativePath", "Recipebuilder.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URecipebuilder_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URecipebuilder>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URecipebuilder_Statics::ClassParams = {
		&URecipebuilder::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_URecipebuilder_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URecipebuilder_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URecipebuilder()
	{
		if (!Z_Registration_Info_UClass_URecipebuilder.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URecipebuilder.OuterSingleton, Z_Construct_UClass_URecipebuilder_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URecipebuilder.OuterSingleton;
	}
	template<> VEGANZOMBIECROPAPOCALYPSE_API UClass* StaticClass<URecipebuilder>()
	{
		return URecipebuilder::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URecipebuilder);
	URecipebuilder::~URecipebuilder() {}
	struct Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_Recipebuilder_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_Recipebuilder_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URecipebuilder, URecipebuilder::StaticClass, TEXT("URecipebuilder"), &Z_Registration_Info_UClass_URecipebuilder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URecipebuilder), 2584739051U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_Recipebuilder_h_3215597518(TEXT("/Script/VeganZombieCropApocalypse"),
		Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_Recipebuilder_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_khemb_Documents_GitHub_vegan_harvest_VZCA_5_1_Source_VeganZombieCropApocalypse_Recipebuilder_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
