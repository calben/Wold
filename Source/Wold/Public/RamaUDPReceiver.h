// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Networking.h"
#include "RamaUDPBPLibrary.h"
#include "RamaUDPReceiver.generated.h"

UCLASS()
class WOLD_API ARamaUDPReceiver : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//====================================================
	//		Data Received Events!
public:
	/** Data has been received!! */
	UFUNCTION(BlueprintImplementableEvent)
		void OnDataReceived(const FAnyCustomData& ReceivedData);

	//====================================================

	FSocket* ListenSocket;

	FUdpSocketReceiver* UDPReceiver = nullptr;
	void Recv(const FArrayReaderPtr& ArrayReaderPtr, const FIPv4Endpoint& EndPt);

	UFUNCTION(BlueprintCallable)
		bool StartUDPReceiver(
			const FString& YourChosenSocketName,
			const FString& TheIP,
			const int32 ThePort
		);

	//ScreenMsg
	FORCEINLINE void ScreenMsg(const FString& Msg)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *Msg);
	}
	FORCEINLINE void ScreenMsg(const FString& Msg, const float Value)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s %f"), *Msg, Value));
	}
	FORCEINLINE void ScreenMsg(const FString& Msg, const FString& Msg2)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s %s"), *Msg, *Msg2));
	}

	/** Called whenever this actor is being removed from a level */
	UFUNCTION(BlueprintCallable, Category = "RamaUDPSender")
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};
