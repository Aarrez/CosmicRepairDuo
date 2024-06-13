#include "Red_PauseMenu.h"
#include "Widgets/SViewport.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


URedPauseMenu::URedPauseMenu(const FObjectInitializer& ObjectInitializer)
	:UUserWidget(ObjectInitializer)
{
	SetIsFocusable(true);
}

FReply URedPauseMenu::NativeOnFocusReceived(const FGeometry& InGeomentry, const FFocusEvent& InFocuseEvent)
{
	UE_LOG(LogTemp, Log, TEXT("Focus received"));
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

FReply URedPauseMenu::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}



FReply URedPauseMenu::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply URedPauseMenu::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Handled();
}

FReply URedPauseMenu::NativeOnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	return FReply::Handled();
}

FReply URedPauseMenu::NativeOnAnalogValueChanged(const FGeometry& InGeometry, const FAnalogInputEvent& InAnalogEvent)
{
	return FReply::Handled();
}

void URedPauseMenu::ReturnButton()
{
	FSlateApplication::Get().SetAllUserFocusToGameViewport();
}

void URedPauseMenu::MainMenuButton()
{
	UGameplayStatics::OpenLevel(this, LevelToLoad);
}
