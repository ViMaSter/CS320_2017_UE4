// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerData.h"

#include "LowercaseVector2D.h"

UPlayerData::UPlayerData() {}

UPlayerData::~UPlayerData() {}

UPlayerData* UPlayerData::Create(FString name, float x, float y, int32 colorHex)
{
	UPlayerData* newObject(NewObject<UPlayerData>());
	newObject->name = name;
	newObject->position = ULowercaseVector2D::Create(x, y);
	newObject->colorHex = colorHex;
	return newObject;
}

FString UPlayerData::ToString()
{
	uint8* datablock = new uint8[4];
	FMemory::Memcpy(datablock, &this->colorHex, 4);
	FString returnValue = FString::Printf(TEXT("Name: %s | Position: %s | Color: %s"), *this->name, *this->position->ToString(), *BytesToHex(datablock, 4));
	delete[] datablock;
	return returnValue;
}