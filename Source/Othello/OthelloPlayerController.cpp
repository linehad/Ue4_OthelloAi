// Fill out your copyright notice in the Description page of Project Settings.


#include "OthelloPlayerController.h"
#include <Blueprint/UserWidget.h>

void AOthelloPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	// SetInputMode�� FInputModeGameAndUI�� �־�θ� ���Ӱ� UI��� �Է��� ������ ���°� �ȴ�.
	SetInputMode(FInputModeGameAndUI());
}

void AOthelloPlayerController::ChangeWidget_Implementation(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

//void AOthelloPlayerController::ShowWidget_Implementation() {
//	UE_LOG(LogTemp, Warning, TEXT("PlayerController ShowWidget Called"));
//}

