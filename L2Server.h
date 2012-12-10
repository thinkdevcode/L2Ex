#ifndef _L2SERVER_
	#define _L2SERVER_

	#ifndef _CSOCKET_
		#include "CSocket.h"
	#endif

struct FVector
{
	double x;
	double y;
	double z;
};

namespace L2Server
{
	typedef void (*_LOADDATA)();
	static _LOADDATA LoadData = (_LOADDATA)0x6426A0;

	typedef int (*_VASSEMBLE)(char *szBuffer, int iLen, const char *szFormat, va_list vl);
	static _VASSEMBLE VAssemble = (_VASSEMBLE)0x61D8A0;

	typedef int (*_ASSEMBLE)(char *szBuffer, int iLen, const char *szFormat, ...);
	static _ASSEMBLE Assemble = (_ASSEMBLE)0x61EF80;

	typedef int (*_VDISASSEMBLE)(const unsigned char *szPacket, const char *szFormat, va_list vl);
	static _VDISASSEMBLE VDisassemble = (_VDISASSEMBLE)0x61F1E0;

	typedef const unsigned char *(*_DISASSEMBLE)(const unsigned char *szPacket, const char *szFormat, ...);
	static _DISASSEMBLE Disassemble = (_DISASSEMBLE)0x61F510;

	typedef void (*_BROADCAST_TO_NEIGHBOR)(int iObjectId, int iDistance, FVector vPos, const char *szFormat, ...);
	static _BROADCAST_TO_NEIGHBOR BroadcastToNeighbor = (_BROADCAST_TO_NEIGHBOR)0x4E8CB0;

	typedef void (*_BROADCAST_TO_ALL_USER)(const char *szFormat, ...);
	static _BROADCAST_TO_ALL_USER BroadcastToAllUser = (_BROADCAST_TO_ALL_USER)0x822F40;

	typedef void (__fastcall *_BROADCAST_TO_ALL_USER_ANNOUNCE)(const wchar_t *szMessage);
	static _BROADCAST_TO_ALL_USER_ANNOUNCE BroadcastToAllUser_Announce = (_BROADCAST_TO_ALL_USER_ANNOUNCE)0x823660;
}

#endif
