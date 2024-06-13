#include "Red_ControlsMenu.h"

FReply URedControllsMenu::NativeOnFocusReceived(const FGeometry& InGeomentry, const FFocusEvent& InFocuseEvent)
{
	UWidget* DefaultFocus = GetDefaultFocusWiget();
	if (DefaultFocus)
	{
		return FReply::Handled()
			.ReleaseMouseCapture()
			.ReleaseMouseLock()
			.SetUserFocus(DefaultFocus->GetCachedWidget().ToSharedRef());
	}
	else
	{
		return FReply::Handled()
			.ReleaseMouseCapture()
			.ReleaseMouseLock();
	}
}

void URedControllsMenu::CloseButton()
{
	LastWiget = GetLastOpenWiget();
	if (LastWiget)
	{
		LastWiget->SetFocus();
	}
	else
	{
		FSlateApplication::Get().SetAllUserFocusToGameViewport();
	}
}



FReply URedControllsMenu::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply URedControllsMenu::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply URedControllsMenu::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply URedControllsMenu::NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	return FReply::Handled();
}

FReply URedControllsMenu::NativeOnAnalogValueChanged(const FGeometry& InGeometry, const FAnalogInputEvent& InAnalogEvent)
{
	return FReply::Handled();
}
