#ifndef _SERVERPACKETS_
	#define _SERVERPACKETS_

	#ifndef _L2SDK_
		#include "L2SDK.h"
	#endif

extern "C"
{
	void ServerPacketHandler(CSocket *pSocket, const char *szFormat, va_list vPacket);
}

extern "C"
{
	void ProtocolVersion(CSocket *pSocket, va_list vPacket);
	void CharSelectInfo(CSocket *pSocket, va_list vPacket);
	void UserInfo(CSocket *pSocket, va_list vPacket);
	//void CharInfo(CSocket *pSocket, va_list vPacket);
	void SkillList(CSocket *pSocket, va_list vPacket);
	void ShortCutInit(CSocket *pSocket, va_list vPacket);
	void ShortCutRegister(CSocket *pSocket, va_list vPacket);
	void ItemList(CSocket *pSocket, va_list vPacket);
	void ItemListUpdate(CSocket *pSocket, va_list vPacket);
	void MultiSellList(CSocket *pSocket, va_list vPacket);
	void WarehouseDepositList(CSocket *pSocket, va_list vPacket);
	void WarehouseWithdrawalList(CSocket *pSocket, va_list vPacket);
}

#endif