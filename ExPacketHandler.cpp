#ifndef _CLIENTPACKETS_
	#include "ClientPackets.h"
#endif

#define PacketOK false
#define PacketBAD true

bool ExPacketHandler(CSocket *pSocket, char *pPacket)
{
	short nId = *(short *)(pPacket);

	switch (nId)
	{
		case 0x14: //RequestAskJoinPartyRoom
		{
			// No Packet

			return PacketOK;
		}

		case 0x15: //AnswerJoinPartyRoom
		{
			// No Packet

			return PacketOK;
		}

		case 0x16: //RequestListPartyMatchingWaitingRoom
		{
			// No Packet

			return PacketOK;
		}

		case 0x17: //RequestExitPartyMatchingWaitingRoom
		{
			// No Packet

			return PacketOK;
		}

		case 0x18: //RequestGetBossRecord
		{
			pSocket->Send("chddd", 0xFE, 0x33, 0, 0, 0);

			return PacketOK;
		}

		case 0x19: //RequestPledgeSetAcademyMaster
		{
			// Not Supported Yet

			return PacketOK;
		}

		case 0x1A: //RequestPledgePowerGradeList
		{
			pSocket->Send("chddddddddddddddddddd",
				0xFE, 0x3B, 9,
				1, 0,
				2, 0,
				3, 0,
				4, 0,
				5, 0,
				6, 0,
				7, 0,
				8, 0,
				9, 0);

			return PacketOK;
		}

		case 0x1B: //RequestPledgeMemberPowerInfo
		{

			return PacketOK;
		}

		case 0x1C: //RequestPledgeSetMemberGrade
		{

			return PacketOK;
		}

		case 0x1D: //RequestPledgeMemberInfo
		{

			return PacketOK;
		}

		case 0x1E: //RequestPledgeWarList
		{
			int iTab = *(int *)(pPacket + 4);

			pSocket->Send("chdddSddSdd", 0xFE, 0x3E, iTab, 0, 2, L"/enemylist", iTab, iTab, L"/attackerlist", iTab, iTab);
		

			//TODO: Find real pledge war list from those two functions.

			return PacketOK;
		}

		case 0x1F: //RequestExFishRanking
		{
			// No Packet

			return PacketOK;
		}

		case 0x20: //RequestPCCafeCouponUse
		{
			// No Packet

			return PacketOK;
		}

		case 0x21: //NotFound
		{
			// No Packet

			return PacketOK;
		}

		case 0x22: //RequestCursedWeaponList
		{
			pSocket->Send("chddd", 0xFE, 0x45, 2, 8190, 8689);

			return PacketOK;
		}

		case 0x23: //RequestCursedWeaponLocation
		{
			pSocket->Send("chd", 0xFE, 0x46, 0);

			return PacketOK;
		}

		case 0x24: //RequestPledgeReorganizeMember
		{
			// No Packet

			return PacketOK;
		}

		default:
		{

			return g_OriginalClientPackets->PacketTable[0xD0](pSocket, pPacket);
		}
	}
}