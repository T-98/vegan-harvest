// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UMPGorePack/DetectionComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDetectionComponent() {}
// Cross Module References
	UMPGOREPACK_API UClass* Z_Construct_UClass_UDetectionComponent_NoRegister();
	UMPGOREPACK_API UClass* Z_Construct_UClass_UDetectionComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_UMPGorePack();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UDetectionComponent::execCleanup)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Cleanup();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDetectionComponent::execGetVegetableSet)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSet<TWeakObjectPtr<AActor> >*)Z_Param__Result=P_THIS->GetVegetableSet();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDetectionComponent::execStringifyMap)
	{
		P_GET_TMAP_REF(FName,int32,Z_Param_Out_map_);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->StringifyMap(Z_Param_Out_map_);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDetectionComponent::execGetMap)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FName,int32>*)Z_Param__Result=P_THIS->GetMap();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDetectionComponent::execGetCount)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Vegetable);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetCount(Z_Param_Out_Vegetable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDetectionComponent::execAddVegetable)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddVegetable(Z_Param_Actor);
		P_NATIVE_END;
	}
	void UDetectionComponent::StaticRegisterNativesUDetectionComponent()
	{
		UClass* Class = UDetectionComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddVegetable", &UDetectionComponent::execAddVegetable },
			{ "Cleanup", &UDetectionComponent::execCleanup },
			{ "GetCount", &UDetectionComponent::execGetCount },
			{ "GetMap", &UDetectionComponent::execGetMap },
			{ "GetVegetableSet", &UDetectionComponent::execGetVegetableSet },
			{ "StringifyMap", &UDetectionComponent::execStringifyMap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics
	{
		struct DetectionComponent_eventAddVegetable_Parms
		{
			AActor* Actor;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DetectionComponent_eventAddVegetable_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::NewProp_Actor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "DetectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDetectionComponent, nullptr, "AddVegetable", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::DetectionComponent_eventAddVegetable_Parms), Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDetectionComponent_AddVegetable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDetectionComponent_AddVegetable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDetectionComponent_Cleanup_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDetectionComponent_Cleanup_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "DetectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDetectionComponent_Cleanup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDetectionComponent, nullptr, "Cleanup", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDetectionComponent_Cleanup_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_Cleanup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDetectionComponent_Cleanup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDetectionComponent_Cleanup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDetectionComponent_GetCount_Statics
	{
		struct DetectionComponent_eventGetCount_Parms
		{
			FName Vegetable;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vegetable_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Vegetable;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::NewProp_Vegetable_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::NewProp_Vegetable = { "Vegetable", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DetectionComponent_eventGetCount_Parms, Vegetable), METADATA_PARAMS(Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::NewProp_Vegetable_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::NewProp_Vegetable_MetaData)) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DetectionComponent_eventGetCount_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::NewProp_Vegetable,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "DetectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDetectionComponent, nullptr, "GetCount", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::DetectionComponent_eventGetCount_Parms), Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDetectionComponent_GetCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDetectionComponent_GetCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDetectionComponent_GetMap_Statics
	{
		struct DetectionComponent_eventGetMap_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DetectionComponent_eventGetMap_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "DetectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDetectionComponent, nullptr, "GetMap", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::DetectionComponent_eventGetMap_Parms), Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDetectionComponent_GetMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDetectionComponent_GetMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics
	{
		struct DetectionComponent_eventGetVegetableSet_Parms
		{
			TSet<TWeakObjectPtr<AActor> > ReturnValue;
		};
		static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_ReturnValue_ElementProp;
		static const UECodeGen_Private::FSetPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::NewProp_ReturnValue_ElementProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DetectionComponent_eventGetVegetableSet_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::NewProp_ReturnValue_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "DetectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDetectionComponent, nullptr, "GetVegetableSet", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::DetectionComponent_eventGetVegetableSet_Parms), Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDetectionComponent_GetVegetableSet()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDetectionComponent_GetVegetableSet_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics
	{
		struct DetectionComponent_eventStringifyMap_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_map__ValueProp = { "map_", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_map__Key_KeyProp = { "map__Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_map__MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_map_ = { "map_", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DetectionComponent_eventStringifyMap_Parms, map_), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_map__MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_map__MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DetectionComponent_eventStringifyMap_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_map__ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_map__Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_map_,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "DetectionComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDetectionComponent, nullptr, "StringifyMap", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::DetectionComponent_eventStringifyMap_Parms), Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDetectionComponent_StringifyMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDetectionComponent_StringifyMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDetectionComponent);
	UClass* Z_Construct_UClass_UDetectionComponent_NoRegister()
	{
		return UDetectionComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDetectionComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDetectionComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UMPGorePack,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDetectionComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDetectionComponent_AddVegetable, "AddVegetable" }, // 1606879489
		{ &Z_Construct_UFunction_UDetectionComponent_Cleanup, "Cleanup" }, // 1319436983
		{ &Z_Construct_UFunction_UDetectionComponent_GetCount, "GetCount" }, // 1007923142
		{ &Z_Construct_UFunction_UDetectionComponent_GetMap, "GetMap" }, // 2374362470
		{ &Z_Construct_UFunction_UDetectionComponent_GetVegetableSet, "GetVegetableSet" }, // 4101591139
		{ &Z_Construct_UFunction_UDetectionComponent_StringifyMap, "StringifyMap" }, // 1497430515
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDetectionComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "DetectionComponent.h" },
		{ "ModuleRelativePath", "DetectionComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDetectionComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDetectionComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDetectionComponent_Statics::ClassParams = {
		&UDetectionComponent::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UDetectionComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDetectionComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDetectionComponent()
	{
		if (!Z_Registration_Info_UClass_UDetectionComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDetectionComponent.OuterSingleton, Z_Construct_UClass_UDetectionComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDetectionComponent.OuterSingleton;
	}
	template<> UMPGOREPACK_API UClass* StaticClass<UDetectionComponent>()
	{
		return UDetectionComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDetectionComponent);
	struct Z_CompiledInDeferFile_FID_UMPGorePack_Source_UMPGorePack_DetectionComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UMPGorePack_Source_UMPGorePack_DetectionComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDetectionComponent, UDetectionComponent::StaticClass, TEXT("UDetectionComponent"), &Z_Registration_Info_UClass_UDetectionComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDetectionComponent), 1834329616U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UMPGorePack_Source_UMPGorePack_DetectionComponent_h_1183809457(TEXT("/Script/UMPGorePack"),
		Z_CompiledInDeferFile_FID_UMPGorePack_Source_UMPGorePack_DetectionComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UMPGorePack_Source_UMPGorePack_DetectionComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
