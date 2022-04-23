/*
 *   --------------------------
 *  |  TestorActor.cpp
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

#include "TestorActor.h"

// Sets default values
ATestorActor::ATestorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ATestorActor::SpitInt_Native()
{
	UE_LOG(LogTemp, Log, TEXT("Inside Pure Native function"));
	return 20;
}

