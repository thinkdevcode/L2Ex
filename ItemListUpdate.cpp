#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void ItemListUpdate(CSocket *pSocket, va_list vPacket)
{
	BYTE bOpCode = va_arg(vPacket, BYTE);
	Int16 nItemCount = va_arg(vPacket, Int16);

	Int32 nBufferSize = va_arg(vPacket, Int32);
	Char *szBuffer = va_arg(vPacket, Char *);
	CPacketDisassembler pOldItemListUpdate(szBuffer);

	CPacketAssembler pNewItemListUpdate;

	pNewItemListUpdate.WriteC(bOpCode); // OpCode
	pNewItemListUpdate.WriteH(nItemCount); // Item Count

	for (Int16 i = 0; i < nItemCount; i++)
	{
		pNewItemListUpdate.WriteH(pOldItemListUpdate.ReadH()); // Update Type (1 - Add | 2 - Modify | 3 - Remove)
		pNewItemListUpdate.WriteH(pOldItemListUpdate.ReadH()); // Item Type (0 - Weapon/Jewels | 1 - Armor | 4 - Other)
		pNewItemListUpdate.WriteD(pOldItemListUpdate.ReadD()); // Item Object Id
		pNewItemListUpdate.WriteD(pOldItemListUpdate.ReadD()); // Item Id
		pNewItemListUpdate.WriteD(pOldItemListUpdate.ReadD()); // Item Count
		pNewItemListUpdate.WriteH(pOldItemListUpdate.ReadH()); // Item Type 2
		pNewItemListUpdate.WriteH(pOldItemListUpdate.ReadH()); // Custom Type 1 (Filler - 0)
		pNewItemListUpdate.WriteH(pOldItemListUpdate.ReadH()); // Is Equipped 
		pNewItemListUpdate.WriteD(pOldItemListUpdate.ReadD()); // Slot
		pNewItemListUpdate.WriteH(pOldItemListUpdate.ReadH()); // Enchant
		pNewItemListUpdate.WriteH(pOldItemListUpdate.ReadH()); // Pet Name (Custom Type 2)

		pNewItemListUpdate.WriteD(0); // Augmentation Id
		pNewItemListUpdate.WriteD(0); // Mana
	}

	pSocket->Send("b", pNewItemListUpdate.GetSize(), pNewItemListUpdate.GetPacket());
}