// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
#ifdef OCEANPLUGIN_CustomVehicleController_generated_h
#error "CustomVehicleController.generated.h already included, missing '#pragma once' in CustomVehicleController.h"
#endif
#define OCEANPLUGIN_CustomVehicleController_generated_h

#define team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEnableBuoyancy) \
	{ \
		P_FINISH; \
		this->EnableBuoyancy(); \
	} \
 \
	DECLARE_FUNCTION(execDrawBuoyancyPoints) \
	{ \
		P_FINISH; \
		this->DrawBuoyancyPoints(); \
	} \
 \
	DECLARE_FUNCTION(execGetIsDriving) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->GetIsDriving(); \
	} \
 \
	DECLARE_FUNCTION(execExitVehicle) \
	{ \
		P_FINISH; \
		this->ExitVehicle(); \
	} \
 \
	DECLARE_FUNCTION(execEnterVehicle) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_Vehicle); \
		P_FINISH; \
		this->EnterVehicle(Z_Param_Vehicle); \
	}


#define team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEnableBuoyancy) \
	{ \
		P_FINISH; \
		this->EnableBuoyancy(); \
	} \
 \
	DECLARE_FUNCTION(execDrawBuoyancyPoints) \
	{ \
		P_FINISH; \
		this->DrawBuoyancyPoints(); \
	} \
 \
	DECLARE_FUNCTION(execGetIsDriving) \
	{ \
		P_FINISH; \
		*(bool*)Z_Param__Result=this->GetIsDriving(); \
	} \
 \
	DECLARE_FUNCTION(execExitVehicle) \
	{ \
		P_FINISH; \
		this->ExitVehicle(); \
	} \
 \
	DECLARE_FUNCTION(execEnterVehicle) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_Vehicle); \
		P_FINISH; \
		this->EnterVehicle(Z_Param_Vehicle); \
	}


#define team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesACustomVehicleController(); \
	friend OCEANPLUGIN_API class UClass* Z_Construct_UClass_ACustomVehicleController(); \
	public: \
	DECLARE_CLASS(ACustomVehicleController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/OceanPlugin"), NO_API) \
	DECLARE_SERIALIZER(ACustomVehicleController) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_INCLASS \
	private: \
	static void StaticRegisterNativesACustomVehicleController(); \
	friend OCEANPLUGIN_API class UClass* Z_Construct_UClass_ACustomVehicleController(); \
	public: \
	DECLARE_CLASS(ACustomVehicleController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/OceanPlugin"), NO_API) \
	DECLARE_SERIALIZER(ACustomVehicleController) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACustomVehicleController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACustomVehicleController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomVehicleController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomVehicleController); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ACustomVehicleController(const ACustomVehicleController& InCopy); \
public:


#define team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACustomVehicleController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ACustomVehicleController(const ACustomVehicleController& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomVehicleController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomVehicleController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACustomVehicleController)


#define team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_29_PROLOG
#define team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_RPC_WRAPPERS \
	team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_INCLASS \
	team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_INCLASS_NO_PURE_DECLS \
	team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h_32_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class CustomVehicleController."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID team_tzhaar_code_Plugins_OceanPlugin_Source_OceanPlugin_Classes_CustomVehicleController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS