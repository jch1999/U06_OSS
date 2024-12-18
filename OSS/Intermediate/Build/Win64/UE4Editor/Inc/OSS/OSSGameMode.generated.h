// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OSS_OSSGameMode_generated_h
#error "OSSGameMode.generated.h already included, missing '#pragma once' in OSSGameMode.h"
#endif
#define OSS_OSSGameMode_generated_h

#define OSS_Source_OSS_OSSGameMode_h_12_SPARSE_DATA
#define OSS_Source_OSS_OSSGameMode_h_12_RPC_WRAPPERS
#define OSS_Source_OSS_OSSGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define OSS_Source_OSS_OSSGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOSSGameMode(); \
	friend struct Z_Construct_UClass_AOSSGameMode_Statics; \
public: \
	DECLARE_CLASS(AOSSGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/OSS"), OSS_API) \
	DECLARE_SERIALIZER(AOSSGameMode)


#define OSS_Source_OSS_OSSGameMode_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAOSSGameMode(); \
	friend struct Z_Construct_UClass_AOSSGameMode_Statics; \
public: \
	DECLARE_CLASS(AOSSGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/OSS"), OSS_API) \
	DECLARE_SERIALIZER(AOSSGameMode)


#define OSS_Source_OSS_OSSGameMode_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	OSS_API AOSSGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOSSGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OSS_API, AOSSGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOSSGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OSS_API AOSSGameMode(AOSSGameMode&&); \
	OSS_API AOSSGameMode(const AOSSGameMode&); \
public:


#define OSS_Source_OSS_OSSGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	OSS_API AOSSGameMode(AOSSGameMode&&); \
	OSS_API AOSSGameMode(const AOSSGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(OSS_API, AOSSGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOSSGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOSSGameMode)


#define OSS_Source_OSS_OSSGameMode_h_12_PRIVATE_PROPERTY_OFFSET
#define OSS_Source_OSS_OSSGameMode_h_9_PROLOG
#define OSS_Source_OSS_OSSGameMode_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OSS_Source_OSS_OSSGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	OSS_Source_OSS_OSSGameMode_h_12_SPARSE_DATA \
	OSS_Source_OSS_OSSGameMode_h_12_RPC_WRAPPERS \
	OSS_Source_OSS_OSSGameMode_h_12_INCLASS \
	OSS_Source_OSS_OSSGameMode_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define OSS_Source_OSS_OSSGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OSS_Source_OSS_OSSGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	OSS_Source_OSS_OSSGameMode_h_12_SPARSE_DATA \
	OSS_Source_OSS_OSSGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	OSS_Source_OSS_OSSGameMode_h_12_INCLASS_NO_PURE_DECLS \
	OSS_Source_OSS_OSSGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OSS_API UClass* StaticClass<class AOSSGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID OSS_Source_OSS_OSSGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
