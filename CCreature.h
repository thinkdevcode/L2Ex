#ifndef _CCREATURE_
	#define _CCREATURE_

	#ifndef _CSHAREDDATA_
		#include "CSharedData.h"
	#endif

	#define User CCreature
	#define CNPC CCreature

class CSocket;

class CCreature
{
public:
	
	void EnterWorld()
	{
		typedef void (*_ENTER_WORLD)(User *);
		_ENTER_WORLD _EnterWorld = (_ENTER_WORLD)0x84CED0;

		_EnterWorld(this);
	}

	CSharedData *GetSharedData()
	{

		return pSharedData;
	}

	int GetPledgeClass()
	{

		return 0;
	}

	int GetCursedWeaponGlowLevel()
	{
		if (pSharedData->nBuilder > 0)
		{
			switch (pSharedData->nWeaponClassId)
			{
				case 8190:
					return 10;

				case 8689:
					return 10;

				default:
					return 0;
			}
		}

		return 0;
	}

private:

	int iUnk1[354]; // 0x00

	CSharedData *pSharedData; // 0x588

};

#endif