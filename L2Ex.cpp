#ifndef _L2EX_
	#include "L2Ex.h"
#endif

#pragma warning(disable: 4311)

L2Ex *L2Ex::Instance()
{
	static L2Ex Interlude;

	return &Interlude;
}

void L2Ex::Initialize()
{
	SetProtocolRevision("746");
	SetMaxNpcId(1090000);

	FixServerPackets();
	InstallHooks();
}

void L2Ex::SetProtocolRevision(char *szRevision)
{
	CPatchEngine::Instance()->WriteAnsiString((BYTE *)0x9BA9B3, szRevision);
}

void L2Ex::SetMaxNpcId(int nMaxNpcId)
{
	CPatchEngine::Instance()->WriteInt32((BYTE *)0x95F5A4, nMaxNpcId);
}

void L2Ex::FixServerPackets()
{
	// Disable CSocket Key
	CPatchEngine::Instance()->WriteNops((BYTE *)0x87872C, 5);

	// Hook Packet Handler
	CPatchEngine::Instance()->WriteCall((BYTE *)0x7D5FCA, (DWORD *)ServerPacketHandler);
}

void L2Ex::InstallHooks()
{
	// Hook LoadData
	CPatchEngine::Instance()->WriteCall((BYTE *)0x64357B, (DWORD *)LoadData);

	// Hook EnterWorld
	BYTE szEnterWorld[4];
	*(DWORD *)(szEnterWorld) = (DWORD)EnterWorld;
	CPatchEngine::Instance()->WriteArray((BYTE *)0xA87738, szEnterWorld, 3);
}