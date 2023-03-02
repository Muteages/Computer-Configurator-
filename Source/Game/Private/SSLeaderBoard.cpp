// Fill out your copyright notice in the Description page of Project Settings.


#include "SSLeaderBoard.h"
#include "SlateOptMacros.h"

#define  LOCTEXT_NAMESPACE "MainMenu"
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSLeaderBoard::Construct(const FArguments& InArgs)
{
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FText TitleText = LOCTEXT("GameTitle", "Fantasy Computer Company");

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)   //background
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Text(TitleText)
			]
		]
	];
	
}

#undef LOCTEXT_NAMESPACE
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
