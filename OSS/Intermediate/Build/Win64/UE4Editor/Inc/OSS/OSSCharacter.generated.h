// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OSS_OSSCharacter_generated_h
#error "OSSCharacter.generated.h already included, missing '#pragma once' in OSSCharacter.h"
#endif
#define OSS_OSSCharacter_generated_h

#define OSS_Source_OSS_OSSCharacter_h_12_SPARSE_DATA
#define OSS_Source_OSS_OSSCharacter_h_12_RPC_WRAPPERS
#define OSS_Source_OSS_OSSCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define OSS_Source_OSS_OSSCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOSSCharacter(); \
	friend struct Z_Construct_UClass_AOSSCharacter_Statics; \
public: \
	DECLARE_CLASS(AOSSCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OSS"), NO_API) \
	DECLARE_SERIALIZER(AOSSCharacter)


#define OSS_Source_OSS_OSSCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAOSSCharacter(); \
	friend struct Z_Construct_UClass_AOSSCharacter_Statics; \
public: \
	DECLARE_CLASS(AOSSCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OSS"), NO_API) \
	DECLARE_SERIALIZER(AOSSCharacter)


#define OSS_Source_OSS_OSSCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AOSSCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOSSCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOSSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOSSCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOSSCharacter(AOSSCharacter&&); \
	NO_API AOSSCharacter(const AOSSCharacter&); \
public:


#define OSS_Source_OSS_OSSCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AOSSCharacter(AOSSCharacter&&); \
	NO_API AOSSCharacter(const AOSSCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOSSCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOSSCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOSSCharacter)


#define OSS_Source_OSS_OSSCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AOSSCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AOSSCharacter, FollowCamera); }


#define OSS_Source_OSS_OSSCharacter_h_9_PROLOG
#define OSS_Source_OSS_OSSCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OSS_Source_OSS_OSSCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	OSS_Source_OSS_OSSCharacter_h_12_SPARSE_DATA \
	OSS_Source_OSS_OSSCharacter_h_12_RPC_WRAPPERS \
	OSS_Source_OSS_OSSCharacter_h_12_INCLASS \
	OSS_Source_OSS_OSSCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define OSS_Source_OSS_OSSCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OSS_Source_OSS_OSSCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	OSS_Source_OSS_OSSCharacter_h_12_SPARSE_DATA \
	OSS_Source_OSS_OSSCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	OSS_Source_OSS_OSSCharacter_h_12_INCLASS_NO_PURE_DECLS \
	OSS_Source_OSS_OSSCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OSS_API UClass* StaticClass<class AOSSCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID OSS_Source_OSS_OSSCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
