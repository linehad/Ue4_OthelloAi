// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameBoard.generated.h"

/**
 * 
 */
UCLASS()
class OTHELLO_API UGameBoard : public UUserWidget
{
	GENERATED_BODY()
private:
	int m_Board_Size = 0;
	int m_Turn_time = 0;

	int seconds = 0;

	int m_wScore = 0;
	int m_bScore = 0;

	UPROPERTY()
		TArray<int8> arr_dX = { -1, -1, -1, 0, 0 , 1, 1, 1 };
	UPROPERTY()
		TArray<int8> arr_dY = { -1, 0, 1, -1, 1 , -1, 0, 1 };

public:
	virtual void NativeConstruct() override;
	
	UPROPERTY()
		TArray <class UOthelloPices_UserWidget*>Arr_OthelloButton;

		UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* Board_UniformGridPanel = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf <class UOthelloPices_UserWidget>OthelloButton;

	// �浹, �鵹 �̹���
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* WhiteImage = nullptr;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* BlackImage = nullptr;

	// �ð� �̹���
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* Time_Image0 = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* Time_Image1 = nullptr;

	// �浹 ���� �̹���
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* Black_Image0 = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* Black_Image1 = nullptr;

	// �鵹 ���� �̹���
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* White_Image0 = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* White_Image1 = nullptr;

	// ���ӿ��� ���� ���ε� �̹���
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UGridPanel* GameOver_GridPanel = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* WinBlack_Image = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* WinWhite_Image = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ReStart_Button = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* MainMenu_Button = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* Quit_Button = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<UTexture2D*> BigFont;

	// �ִϸ��̼� ���ε�
	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* Time_Image0_Anim = nullptr;
	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* Time_Image1_Anim = nullptr;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* Black_Image0_Anim = nullptr;
	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* Black_Image1_Anim = nullptr;

	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* White_Image0_Anim = nullptr;
	UPROPERTY(BlueprintReadWrite, Transient, meta = (BindWidgetAnim))
		class UWidgetAnimation* White_Image1_Anim = nullptr;


public:
	UFUNCTION()
		void ChangePices(int x, int y, int8 piceColor);
	UFUNCTION()
		void OthelloChangeturn();
	UFUNCTION()
		inline int16 Board_index(int x, int y) { return (m_Board_Size * y) + x; }
	UFUNCTION()
		bool PutOthello(int x, int y, int8 piceColor); // �Ѽ� �ִ� ��ġ�� ǥ���ϴ� �Լ�
	UFUNCTION()
		void SetScore(int BScore, int WScore);
	UFUNCTION()
		void SetTime(int Time);
	UFUNCTION()
		void GameOver(int8 gameWinner); // 0 ���º� 1 �浹 �� 2 �鵹 ��
	UFUNCTION()
		void GoMainMenu();
	UFUNCTION()
		void QuitGame();
	UFUNCTION()
		void ReStartGame();

	UFUNCTION(BlueprintCallable)
		void OthelloNextturn();
	UFUNCTION(BlueprintCallable)
		void CountDown();

	inline void Set_BoardSize(int size) { m_Board_Size = size; }
	inline int Get_BoardSize() { return m_Board_Size; }

// ai ���� ����	��� �� = ai
private:
	TArray<int32>aiBoard;
	// 0�浹 1 �鵹
	TArray<int>aiPice = { -10, -11 };
	bool aiTurn = false;
	TArray<TPair<int32, int32>>ai_ReverseIndex; // �ش� ��ġ�� �ξ����� ������ �� �ִ� ���� ������ ��ġ ù�� ° ��ġ 2 ��° ������ ����
	int32 AireverseNum = 0;
public:
	void AiPlayer();
};