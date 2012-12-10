#ifndef _L2EX_
	#include "L2Ex.h"
#endif

#pragma warning(disable: 4311)

void LoadData()
{
	L2Server::LoadData();

	g_OriginalClientPackets = new ClientPackets;
	g_OriginalClientPackets->InitializeTable(g_ClientPackets);

	CPatchEngine::Instance()->WritePointer((BYTE *)0x8900E6, (Int32)g_ClientPackets);
}