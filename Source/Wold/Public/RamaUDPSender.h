/*

By Rama

*/

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Networking.h"
#include "RamaUDPBPLibrary.h"
#include "RamaUDPSender.generated.h"

UCLASS()
class WOLD_API ARamaUDPSender : public AActor
{
	GENERATED_BODY()

		bool IsUDP;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	TSharedPtr<FInternetAddr>	RemoteAddr;

	FSocket* SenderSocket;

	UFUNCTION(BlueprintCallable, Category = "RamaUDPSender")
		bool StartUDPSender(
			const FString& YourChosenSocketName,
			const FString& TheIP,
			const int32 ThePort,
			bool UDP = false
		);

	UFUNCTION(BlueprintCallable, Category = "RamaUDPSender")
		bool RamaUDPSender_SendData(FAnyCustomData StructToSend);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rama UDP Sender")
		bool ShowOnScreenDebugMessages;


	//ScreenMsg
	FORCEINLINE void ScreenMsg(const FString& Msg)
	{
		if (!ShowOnScreenDebugMessages) return;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *Msg);
	}
	FORCEINLINE void ScreenMsg(const FString& Msg, const float Value)
	{
		if (!ShowOnScreenDebugMessages) return;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s %f"), *Msg, Value));
	}
	FORCEINLINE void ScreenMsg(const FString& Msg, const FString& Msg2)
	{
		if (!ShowOnScreenDebugMessages) return;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s %s"), *Msg, *Msg2));
	}

	/** Called whenever this actor is being removed from a level */
	UFUNCTION(BlueprintCallable, Category = "RamaUDPSender")
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};
