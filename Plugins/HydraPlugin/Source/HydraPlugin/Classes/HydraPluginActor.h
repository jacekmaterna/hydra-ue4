#pragma once

#include "GameFramework/Actor.h"
#include "HydraDelegate.h"
#include "HydraPluginActor.generated.h"



/**
 * Placeable Actor Example that receives Hydra input,
 * override any delegate functions to receive notifications.
 * Calling super is not necessary.
 *
 * NB: This is just an example actor, use the HydraPlayerController for own
 * classes.
 * Copy implementations to receive same functionality in a different class.
 */

UCLASS()
class AHydraPluginActor : public AActor, public HydraDelegate	//Multiple Inheritance, add HydraDelegate inheritance to inherit all delegate functionality
{
	GENERATED_UCLASS_BODY()

	/**
	 * We Override every delegate function to forward them to blueprint events,
	 * but if you're extending C++ class yourself you can override just the ones
	 * you are interested in.
	 */
	virtual void EventHydraPluggedIn() override;
	virtual void EventHydraUnplugged() override;
	virtual void EventHydraControllerEnabled(int32 controller) override;
	virtual void EventHydraControllerDisabled(int32 controller) override;

	virtual void EventHydraDocked(int32 controller) override;
	virtual void EventHydraUndocked(int32 controller) override;

	virtual void EventHydraAnyButtonPressed(int32 controller) override;
	virtual void EventHydraB1Pressed(int32 controller) override;
	virtual void EventHydraB1Released(int32 controller) override;
	virtual void EventHydraB2Pressed(int32 controller) override;
	virtual void EventHydraB2Released(int32 controller) override;
	virtual void EventHydraB3Pressed(int32 controller) override;
	virtual void EventHydraB3Released(int32 controller) override;
	virtual void EventHydraB4Pressed(int32 controller) override;
	virtual void EventHydraB4Released(int32 controller) override;
	virtual void EventHydraTriggerPressed(int32 controller) override;
	virtual void EventHydraTriggerReleased(int32 controller) override;
	virtual void EventHydraTriggerChanged(int32 controller, float value) override;
	virtual void EventHydraBumperPressed(int32 controller) override;
	virtual void EventHydraBumperReleased(int32 controller) override;
	virtual void EventHydraJoystickPressed(int32 controller) override;
	virtual void EventHydraJoystickReleased(int32 controller) override;
	virtual void EventHydraStartPressed(int32 controller) override;
	virtual void EventHydraStartReleased(int32 controller) override;

	virtual void EventHydraJoystickMoved(int32 controller, FVector2D movement) override;
	virtual void EventHydraControllerMoved(int32 controller,
		FVector position, FVector velocity, FVector acceleration,
		FRotator rotation) override;

	//Define blueprint events

	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraPluggedIn();
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraUnplugged();
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraControllerEnabled(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraControllerDisabled(int32 controller);

	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraDocked(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraUndocked(int32 controller);

	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraAnyButtonPressed(int32 controller);

	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraB1Pressed(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraB1Released(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraB2Pressed(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraB2Released(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraB3Pressed(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraB3Released(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraB4Pressed(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraB4Released(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraTriggerPressed(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraTriggerReleased(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraTriggerChanged(int32 controller, float value);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraBumperPressed(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraBumperReleased(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraJoystickPressed(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraJoystickReleased(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraStartPressed(int32 controller);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraStartReleased(int32 controller);

	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraJoystickMoved(int32 controller, FVector2D movement);
	UFUNCTION(BlueprintImplementableEvent, Category = HydraEvents)
	void HydraControllerMoved(int32 controller,
		FVector position, FVector velocity, FVector acceleration,
		FRotator rotation);


	//Callable Blueprint functions

	/** Check if the hydra is available/plugged in.*/
	UFUNCTION(BlueprintCallable, Category = HydraFunctions)
	bool HydraIsAvailable();
	/** Detemine which hand you're holding the hydra in. Determined and reset on docking the controller.*/
	UFUNCTION(BlueprintCallable, Category = HydraFunctions)
	int32 HydraWhichHand(int32 controller);
	/** Poll for latest data. Returns false if data is unavailable.*/
	UFUNCTION(BlueprintCallable, Category = HydraFunctions)
	bool HydraGetLatestData(int32 controller, FVector& position, FVector& velocity, FVector& acceleration, FRotator& rotation,
							FVector2D& joystick, int32& buttons, float& trigger, bool& docked);
	/** Poll for historical data. Valid index is 0-9. Returns false if data is unavailable.*/
	UFUNCTION(BlueprintCallable, Category = HydraFunctions)
	bool HydraGetHistoricalData(int32 controller, int32 historyIndex, FVector& position, FVector& velocity, FVector& acceleration, FRotator& rotation,
		FVector2D& joystick, int32& buttons, float& trigger, bool& docked);

	//Required for delegate to function
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};


