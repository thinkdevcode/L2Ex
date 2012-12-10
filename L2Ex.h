#ifndef _L2EX_
	#define _L2EX_

	#ifndef _CLIENTPACKETS_
		#include "ClientPackets.h"
	#endif

	#ifndef _SERVERPACKETS_
		#include "ServerPackets.h"
	#endif

extern "C"
{
	void LoadData();
	void EnterWorld(User *pUser);
}

class L2Ex
{
public:

	static L2Ex *Instance();

	void Initialize();

	void SetProtocolRevision(char *szRevision);
	void SetMaxNpcId(int nMaxNpcId);

	void FixServerPackets();

	void InstallHooks();

private:

};

#endif