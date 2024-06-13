#pragma once 
#include "Blueprint/UserWidget.h"
#include "Red_ControlsMenu.generated.h"

UCLASS(Abstract)
class URedControllsMenu : public UUserWidget 
{
	GENERATED_BODY()

public:
	FReply NativeOnFocusReceived(const FGeometry& InGeomentry, const FFocusEvent& InFocuseEvent) override;

	UFUNCTION(BlueprintCallable)
	void CloseButton();

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetDefaultFocusWiget();

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetLastOpenWiget();

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetOwningWidget();

	UPROPERTY();
	UWidget* LastWiget = nullptr;

	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	FReply NativeOnAnalogValueChanged(const FGeometry& InGeometry, const FAnalogInputEvent& InAnalogEvent)override;

};