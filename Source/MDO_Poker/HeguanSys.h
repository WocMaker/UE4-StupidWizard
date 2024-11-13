// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "HeguanSys.generated.h"

/**
 * 
 */
struct PlayerBasicInfo {
	int playerHealth;
	Tarray<int> magicList;
};

struct PlayerOnlineInfo {
	bool isHost;
};

struct PlayerRoundTimerInfo {
	bool isRound;
	int roundTimer;
};

struct PlayerState {
	PlayerBasicInfo baseInfo;
	PlayerOnlineInfo onlineInfo;
	PlayerRoundTimerInfo roundInfo;
};

UCLASS()
class MDO_POKER_API UHeguanSys : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection);
	int PlayerCastAttempt(int MagicId, PlayerState& PlayerS);
	void MagicDeal(PlayerState& PlayerS);
	void MagicFail();
	void PlayerTimeout();
	void FillHands(PlayerState& PlayerS);
	void MagicDragon();
	void MagicStorm();
	void MagicPotion();
	void HandleRemote();
	void SendToRemote();
	void ScheduleGuestPlayer();

};
