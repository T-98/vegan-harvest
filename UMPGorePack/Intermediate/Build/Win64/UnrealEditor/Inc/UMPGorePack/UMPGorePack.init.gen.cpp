// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUMPGorePack_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UMPGorePack;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UMPGorePack()
	{
		if (!Z_Registration_Info_UPackage__Script_UMPGorePack.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UMPGorePack",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x0986716A,
				0x182A1EBB,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UMPGorePack.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UMPGorePack.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UMPGorePack(Z_Construct_UPackage__Script_UMPGorePack, TEXT("/Script/UMPGorePack"), Z_Registration_Info_UPackage__Script_UMPGorePack, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0986716A, 0x182A1EBB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
