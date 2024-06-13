#pragma once
#include "Blueprint/UserWidget.h"
#include "Red_SettingMenu.generated.h"

UCLASS(Abstract)
class URedSettingMenu : public UUserWidget 
{
GENERATED_BODY()

public:
	FReply NativeOnFocusReceived(const FGeometry& InGeomentry, const FFocusEvent& InFocuseEvent) override;
	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)override;
	FReply NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
	FReply NativeOnAnalogValueChanged(const FGeometry& InGeometry, const FAnalogInputEvent& InAnalogEvent)override;

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetDefaultFocusWiget();

};