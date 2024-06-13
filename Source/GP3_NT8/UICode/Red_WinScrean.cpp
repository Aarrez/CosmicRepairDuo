#include "Red_WinScrean.h"
#include "Widgets/SViewport.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

FReply URedWinscrean::NativeOnFocusReceived(const FGeometry& InGeomentry, const FFocusEvent& InFocuseEvent)
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


FReply URedWinscrean::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply URedWinscrean::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply URedWinscrean::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply URedWinscrean::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	return FReply::Handled();
}

FReply URedWinscrean::NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	return FReply::Handled();
}

FReply URedWinscrean::NativeOnAnalogValueChanged(const FGeometry& InGeometry, const FAnalogInputEvent& InAnalogEvent)
{
	return FReply::Handled();
}

void URedWinscrean::ExitButton()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

void URedWinscrean::MainMenuButton()
{
	UGameplayStatics::OpenLevel(this, LevelToLoad);
}
