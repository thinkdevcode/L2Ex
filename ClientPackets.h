#ifndef _CLIENTPACKETS_
	#define _CLIENTPACKETS_

	#ifndef _CSOCKET_
		#include "CSocket.h"
	#endif

typedef bool (*CP_HANDLER)(CSocket *pSocket, char *pPacket);

extern "C"
{
	bool ExPacketHandler(CSocket *pSocket, char *pPacket);
}

class ClientPackets
{
public:

	CP_HANDLER PacketTable[0xD1];

	void InitializeTable(ClientPackets *pClientPackets)
	{
		for (int i = 0; i < 0xD1; i++)
		{
			PacketTable[i] = pClientPackets->PacketTable[i];
		}

		pClientPackets->PacketTable[0xD0] = &ExPacketHandler;
	}
};

extern ClientPackets *g_ClientPackets;
extern ClientPackets *g_OriginalClientPackets;

#endif