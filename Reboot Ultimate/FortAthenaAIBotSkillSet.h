#pragma once

#include "Object.h"
#include "DataTable.h"
#include "CurveTable.h"

class UFortAthenaAIBotSkillSet : public UObject
{
public:
};

class UFortAthenaAIBotWarmupSkillSet : public UFortAthenaAIBotSkillSet
{
public:
	int GetWarmupPlayEmoteBehaviorWeight()
	{
		struct FScalableFloat
		{
		public:
			float                                        Value;                                             // 0x0(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			uint8                                        Pad_3BF0[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
			FCurveTableRowHandle                  Curve;                                             // 0x8(0x10)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		};

		static auto Phoebe_SkillSets = FindObject<UDataTable>("/Game/Athena/AI/Phoebe/PhoebeSkillSets/Phoebe_SkillSets.Phoebe_SkillSets");

		static auto WarmupPlayEmoteBehaviorWeightOffset = this->GetOffset("WarmupPlayEmoteBehaviorWeight");

		auto& ScalableFloat = Get<FScalableFloat>(WarmupPlayEmoteBehaviorWeightOffset);
		auto& RowMap = Phoebe_SkillSets->GetRowMap();

		if (ScalableFloat.Curve.RowName.ComparisonIndex.Value == 0)
			return ScalableFloat.Value;

		FSimpleCurve* Curve = nullptr;

		for (auto& Pair : RowMap)
		{
			if (Pair.Key() == ScalableFloat.Curve.RowName)
			{
				Curve = (FSimpleCurve*)Pair.Value();
				break;
			}
		}

		if (!Curve)
			return 60;

		return Curve->GetKeys().at(0).Value;
	}

	int GetWarmupLootAndShootBehaviorWeight()
	{
		struct FScalableFloat
		{
		public:
			float                                        Value;                                             // 0x0(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			uint8                                        Pad_3BF0[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
			FCurveTableRowHandle						 Curve;                                             // 0x8(0x10)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		};

		static auto Phoebe_SkillSets = FindObject<UDataTable>("/Game/Athena/AI/Phoebe/PhoebeSkillSets/Phoebe_SkillSets.Phoebe_SkillSets");

		static auto WarmupLootAndShootBehaviorWeightOffset = this->GetOffset("WarmupLootAndShootBehaviorWeight");

		auto& ScalableFloat = Get<FScalableFloat>(WarmupLootAndShootBehaviorWeightOffset);
		auto& RowMap = Phoebe_SkillSets->GetRowMap();

		if (ScalableFloat.Curve.RowName.ComparisonIndex.Value == 0)
			return ScalableFloat.Value;

		FSimpleCurve* Curve = nullptr;

		for (auto& Pair : RowMap)
		{
			if (Pair.Key() == ScalableFloat.Curve.RowName)
			{
				Curve = (FSimpleCurve*)Pair.Value();
				break;
			}
		}

		if (!Curve)
			return 30;

		return Curve->GetKeys().at(0).Value;
	}

	int GetWarmupIdleBehaviorWeight()
	{
		struct FScalableFloat
		{
		public:
			float                                        Value;                                             // 0x0(0x4)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
			uint8                                        Pad_3BF0[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
			FCurveTableRowHandle                  Curve;                                             // 0x8(0x10)(Edit, BlueprintVisible, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
		};

		static auto Phoebe_SkillSets = FindObject<UDataTable>("/Game/Athena/AI/Phoebe/PhoebeSkillSets/Phoebe_SkillSets.Phoebe_SkillSets");

		static auto WarmupIdleBehaviorWeightOffset = this->GetOffset("WarmupIdleBehaviorWeight");

		auto& ScalableFloat = Get<FScalableFloat>(WarmupIdleBehaviorWeightOffset);
		auto& RowMap = Phoebe_SkillSets->GetRowMap();

		if (ScalableFloat.Curve.RowName.ComparisonIndex.Value == 0)
			return ScalableFloat.Value;

		FSimpleCurve* Curve = nullptr;

		for (auto& Pair : RowMap)
		{
			if (Pair.Key() == ScalableFloat.Curve.RowName)
			{
				Curve = (FSimpleCurve*)Pair.Value();
				break;
			}
		}

		if (!Curve)
			return 10;

		return Curve->GetKeys().at(0).Value;
	}

	static UClass* StaticClass()
	{
		static auto Class = FindObject<UClass>(L"/Script/FortniteGame.FortAthenaAIBotWarmupSkillSet");
		return Class;
	}
};