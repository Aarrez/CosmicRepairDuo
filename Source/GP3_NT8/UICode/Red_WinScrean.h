#pragma once
#include "Blueprint/UserWidget.h"
#include "Red_WinScrean.generated.h"

UCLASS()
class URedWinscrean : public UUserWidget 
{
GENERATED_BODY()

public:
	FReply NativeOnFocusReceived(const FGeometry& InGeomentry, const FFocusEvent& InFocuseEvent) override;

	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	FReply NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	FReply NativeOnAnalogValueChanged(const FGeometry& InGeometry, const FAnalogInputEvent& InAnalogEvent)override;

	UFUNCTION(BlueprintCallable)
	void ExitButton();

	UFUNCTION(BlueprintCallable)
	void MainMenuButton();

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetDefaultFocusWiget();

	UPROPERTY(EditAnywhere)
	FName LevelToLoad;
};