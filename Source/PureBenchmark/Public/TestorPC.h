/*
 *   --------------------------
 *  |  TestorPC.h
 *   --------------------------
 *   This file is part of Equalizer for PureBenchmark.
 *
 *   PureBenchmark is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   PureBenchmark is distributed in the hope and belief that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with PureBenchmark.  if not, see <https://www.gnu.org/licenses/>.
 *
 *   Timeline:
 *   April, 2022: First inscription
 */


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Containers/Array.h"
#include "TestorPC.generated.h"

/**
 * 
 */
UCLASS()
class PUREBENCHMARK_API ATestorPC : public APlayerController
{
	GENERATED_BODY()

protected:

	// Defining a pure function
	UFUNCTION(BlueprintPure)
	int32 SpitInt_Native();

	UFUNCTION(BlueprintPure)
	TArray<int32> SpitIntArray_Native(int32 Length);

	UFUNCTION(BlueprintCallable)
	void ObserveCurrentTime();

	void ResetTimeCounters();

private:
	bool bIsTimeCounterOn;
	
	int32 StartTimeSeconds;
	int32 StartTimeMilliSeconds;

	int32 EndTimeSeonds;
	int32 EndTimeMilliSeconds;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	ATestorPC();
};
