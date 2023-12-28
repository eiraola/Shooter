// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"


/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void MenuSetup(int32 NumberOfPublicConnections = 4, FString TypeOfMatch = TEXT("FreeForAll"), FString LobbyPath = TEXT("/Game/Maps/Lobby"));
private:

	class UMultiplayerSessionSubsystem* MultiplayerSessionsSubsystem;
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;
	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;
	UFUNCTION()
	void HostButtonClicked();
	UFUNCTION()
	void JoinButtonClicked();
	void MenuTeardown();
	int32 NumPublicConnections{ 4 };
	FString MatchType{ TEXT("FreeForAll") };
	FString PathToLobby{ TEXT("") };
protected:
	virtual bool Initialize() override; 
	virtual void NativeDestruct() override;
	UFUNCTION()
	void OnCreateSession(bool bWasSeccesful);
	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccesful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSeccesful);
	UFUNCTION()
	void OnStartSession(bool bWasSeccesful);
};
