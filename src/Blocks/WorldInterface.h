
#pragma once

#include "BroadcastInterface.h"
#include "../Mobs/MonsterTypes.h"

class cItems;

typedef cItemCallback<cBlockEntity> cBlockEntityCallback;


class cMonster;
class cPlayer;


class cWorldInterface
{
public:
	virtual ~cWorldInterface() {}
	
	virtual int GetTimeOfDay(void) const = 0;
	virtual Int64 GetWorldAge(void)  const = 0;
	
	virtual eDimension GetDimension(void) const = 0;
	
	virtual cBroadcastInterface & GetBroadcastManager() = 0;
	
	virtual void DoExplosionAt(double a_ExplosionSize, double a_BlockX, double a_BlockY, double a_BlockZ, bool a_CanCauseFire, eExplosionSource a_Source, void * a_SourceData) = 0;
	
	/** Spawns item pickups for each item in the list. May compress pickups if too many entities: */
	virtual void SpawnItemPickups(const cItems & a_Pickups, double a_BlockX, double a_BlockY, double a_BlockZ, double a_FlyAwaySpeed = 1.0, bool IsPlayerCreated = false) = 0;
	
	/** Spawns item pickups for each item in the list. May compress pickups if too many entities. All pickups get the speed specified: */
	virtual void SpawnItemPickups(const cItems & a_Pickups, double a_BlockX, double a_BlockY, double a_BlockZ, double a_SpeedX, double a_SpeedY, double a_SpeedZ, bool IsPlayerCreated = false) = 0;
	
	/** Spawns a mob of the specified type. Returns the mob's EntityID if recognized and spawned, <0 otherwise */
	virtual int SpawnMob(double a_PosX, double a_PosY, double a_PosZ, eMonsterType a_MonsterType) = 0;

	/** Spawns an experience orb at the given location with the given reward. It returns the UniqueID of the spawned experience orb. */
	virtual int SpawnExperienceOrb(double a_X, double a_Y, double a_Z, int a_Reward) = 0;

	/** Calls the callback for the block entity at the specified coords; returns false if there's no block entity at those coords, true if found */
	virtual bool DoWithBlockEntityAt(int a_BlockX, int a_BlockY, int a_BlockZ, cBlockEntityCallback & a_Callback) = 0;

	/** Sends the block on those coords to the player */
	virtual void SendBlockTo(int a_BlockX, int a_BlockY, int a_BlockZ, cPlayer * a_Player) = 0;

	/** Calls the callback for each player in the list; returns true if all players processed, false if the callback aborted by returning true */
	virtual bool ForEachPlayer(cItemCallback<cPlayer> & a_Callback) = 0;

	virtual void SetTimeOfDay(int a_TimeOfDay) = 0;

	/** Returns true if it is raining, stormy or snowing at the specified location. This takes into account biomes. */
	virtual bool IsWeatherWetAt(int a_BlockX, int a_BlockZ) = 0;

	/** Returns the world height at the specified coords; waits for the chunk to get loaded / generated */
	virtual int GetHeight(int a_BlockX, int a_BlockZ) = 0;

	/** Wakes up the simulators for the specified block */
	virtual void WakeUpSimulators(int a_BlockX, int a_BlockY, int a_BlockZ) = 0;

};
