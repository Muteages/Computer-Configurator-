// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
/**
 * 
 */
class GAME_API SSLeaderBoard : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSLeaderBoard)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<class LaderboardHUD>, OwningHUD)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class LaderboardHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };
};
