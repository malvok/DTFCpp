// Fill out your copyright notice in the Description page of Project Settings.

#include "DTFCpp.h"
#include "DTFCppPlayerController.h"
#include "UnrealNetwork.h"
#include "DTFCppGameMode.h"
#include "Blueprint/UserWidget.h"





ADTFCppPlayerController::ADTFCppPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UDTFCppUserWidget>UWidBP(TEXT("WidgetBlueprint'/Game/Blueprints/DTFCppGameHUD.DTFCppGameHUD_C'"));
	if (UWidBP.Class)
	{
		DTFCppGameHUD = UWidBP.Class;
	}
	//static ConstructorHelpers::FClassFinder<ADTFCppChatSystem>CSys(TEXT("Blueprint'/Game/BPChatSystem/Blueprints/Chat_System.Chat_System_C'"));
	//ChatSystem = CSys.Class;
	bShowMouseCursor = true;
	//promotion = 0;
}

void ADTFCppPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//if (Role == ROLE_Authority)
	//{
	//	SetPromotion();
	//}
	/*
	FPlatformProcess::Sleep(1);

	if (1)
	{
		FOutputDeviceNull ar;
		ChatSystem->CallFunctionByNameWithArguments(TEXT("Spawn It"), ar, NULL, false);
	}
	*/
	if (!DTFCppGameHUD)
	{
	return;
	}
	if (!MyGameHUD)
	{
	MyGameHUD = CreateWidget<UDTFCppUserWidget>(GetWorld()->GetFirstPlayerController(), DTFCppGameHUD);
	}
	if (!MyGameHUD)
	{
	return;
	}
	
	MyGameHUD->AddToViewport();
}



/*
void ADTFCppPlayerController::PlayerTick(float DeltaTime)
{
	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, FString::FromInt(ps->PlayerId));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::FromInt(promotion));
	}
}
*/
