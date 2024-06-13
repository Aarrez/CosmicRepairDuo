#pragma once
#include "Blueprint/UserWidget.h"
#include "Red_PauseMenu.generated.h"

UCLASS(Abstract)
class URedPauseMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	URedPauseMenu(const FObjectInitializer& ObjectInitializer);

	FReply NativeOnFocusReceived(const FGeometry& InGeomentry, const FFocusEvent& InFocuseEvent) override;
	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	FReply NativeOnAnalogValueChanged(const FGeometry& InGeometry, const FAnalogInputEvent& InAnalogEvent)override; 

	UFUNCTION(BlueprintCallable)
	void ReturnButton();

	UFUNCTION(BlueprintCallable)
	void MainMenuButton();

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetDefaultFocusWiget();

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetOwningWidget();

	UPROPERTY(EditAnywhere)
	FName LevelToLoad;



};