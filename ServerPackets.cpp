#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void ServerPacketHandler(CSocket *pSocket, const char *szFormat, va_list vPacket)
{
	BYTE pPacketHeader = *vPacket;

	switch (pPacketHeader)
	{
		case 0x00:
		{
			ProtocolVersion(pSocket, vPacket);
		
			break;
		}

		case 0x04:
		{
			UserInfo(pSocket, vPacket);

			break;
		}

		case 0x13:
		{
			CharSelectInfo(pSocket, vPacket);

			break;
		}

		case 0x1B:
		{
			ItemList(pSocket, vPacket);

			break;
		}

		case 0x27:
		{
			ItemListUpdate(pSocket, vPacket);

			break;
		}

		case 0x41:
		{
			WarehouseDepositList(pSocket, vPacket);

			break;
		}

		case 0x42:
		{
			WarehouseWithdrawalList(pSocket, vPacket);

			break;
		}

		case 0x44:
		{
			ShortCutRegister(pSocket, vPacket);

			break;
		}

		case 0x45:
		{
			ShortCutInit(pSocket, vPacket);

			break;
		}

		case 0x58:
		{
			SkillList(pSocket, vPacket);

			break;
		}

		case 0xD0:
		{
			MultiSellList(pSocket, vPacket);

			break;
		}

		default:
		{
			BYTE opCode = *vPacket;
			char buf[32];
			sprintf_s(buf, "%d", opCode);
			MessageBox(NULL, buf, buf, MB_OK);

			pSocket->SendV(szFormat, vPacket);

			break;
		}
	}
}