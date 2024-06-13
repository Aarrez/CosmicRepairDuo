#include "Red_MainMenu.h"
#include "Widgets/SViewport.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

FReply URedMainMenu::NativeOnFocusReceived(const FGeometry& InGeomentry, const FFocusEvent& InFocuseEvent)
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

FReply URedMainMenu::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}



FReply URedMainMenu::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply URedMainMenu::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	
	return FReply::Handled();
}


FReply URedMainMenu::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	return FReply::Handled();
}

FReply URedMainMenu::NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	return FReply::Handled();
}

void URedMainMenu::StartGame()
{
	UGameplayStatics::OpenLevel(this, LevelToLaod);
}

void URedMainMenu::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}


