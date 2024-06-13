#pragma once 
#include "Blueprint/UserWidget.h"
#include "Red_MainMenu.generated.h"

UCLASS(Abstract)
class URedMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	FReply NativeOnFocusReceived(const FGeometry& InGeomentry, const FFocusEvent& InFocuseEvent) override;
	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	FReply NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetOwningWidget();

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetDefaultFocusWiget();

	UPROPERTY(EditAnywhere)
	FName LevelToLaod;

	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION(BlueprintCallable)
	void QuitGame();

};