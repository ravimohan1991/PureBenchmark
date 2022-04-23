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


#include "TestorPC.h"

 // Sets default values
ATestorPC::ATestorPC()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bIsTimeCounterOn = false;

	ResetTimeCounters();
}

void ATestorPC::ResetTimeCounters()
{
	StartTimeSeconds = 0;
	StartTimeMilliSeconds = 0;

	EndTimeSeonds = 0;
	EndTimeMilliSeconds = 0;
}

 // Called every frame
void ATestorPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int ATestorPC::SpitInt_Native()
{
	UE_LOG(LogTemp, Log, TEXT("Inside Pure Native function"));
	return 20;
}

void ATestorPC::ObserveCurrentTime()
{
	if (bIsTimeCounterOn)
	{
		FDateTime CurrentDateAndTime = FDateTime::UtcNow();

		EndTimeSeonds = CurrentDateAndTime.GetSecond();
		EndTimeMilliSeconds = CurrentDateAndTime.GetMillisecond();

		UE_LOG(LogTemp, Log, TEXT("| Observervation End Clip ----> "));
		UE_LOG(LogTemp, Log, TEXT("| Current seconds are: %d"), EndTimeSeonds);
		UE_LOG(LogTemp, Log, TEXT("| Current milliseconds are: %d"), EndTimeMilliSeconds);

		int32 SecondDifference = EndTimeSeonds - StartTimeSeconds;
		int32 MilliSecondDifference = EndTimeMilliSeconds - StartTimeMilliSeconds;

		int32 TotalMilliSecondDifference = SecondDifference * 1000 + MilliSecondDifference;

		UE_LOG(LogTemp, Log, TEXT("| Total Elapsed Time (milli): %d"), TotalMilliSecondDifference);
		UE_LOG(LogTemp, Log, TEXT("+------------------------------------------------"));
		

		ResetTimeCounters();
		bIsTimeCounterOn = false;
	}
	else
	{
		FDateTime CurrentDateAndTime = FDateTime::UtcNow();

		StartTimeSeconds = CurrentDateAndTime.GetSecond();
		StartTimeMilliSeconds = CurrentDateAndTime.GetMillisecond();

		UE_LOG(LogTemp, Log, TEXT("+------------------------------------------------"));
		UE_LOG(LogTemp, Log, TEXT("| Observervation Begin Clip ----> "));
		UE_LOG(LogTemp, Log, TEXT("| Current seconds are: %d"), StartTimeSeconds);
		UE_LOG(LogTemp, Log, TEXT("| Current milliseconds are: %d"), StartTimeMilliSeconds);
		UE_LOG(LogTemp, Log, TEXT("|   ===========================  "));

		bIsTimeCounterOn = true;
	}
}

TArray<int32> ATestorPC::SpitIntArray_Native(int32 Length)
{
	TArray<int32> returnArray;
	returnArray.Init(10, Length);
	//UE_LOG(LogTemp, Log, TEXT("Inside Pure Native function"));
	return returnArray;
}