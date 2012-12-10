#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void ItemList(CSocket *pSocket, va_list vPacket)
{
	BYTE bOpCode = va_arg(vPacket, BYTE);
	Int16 nShowWindow = va_arg(vPacket, Int16);
	Int16 nItemCount = va_arg(vPacket, Int16);

	Int32 nBufferSize = va_arg(vPacket, Int32);
	Char *szBuffer = va_arg(vPacket, Char *);
	CPacketDisassembler pOldItemList(szBuffer);

	CPacketAssembler pNewItemList;

	pNewItemList.WriteC(bOpCode);
	pNewItemList.WriteH(nShowWindow);
	pNewItemList.WriteH(nItemCount);

	for (Int16 i = 0; i < nItemCount; i++)
	{
		pNewItemList.WriteH(pOldItemList.ReadH()); // Item Type 1
		pNewItemList.WriteD(pOldItemList.ReadD()); // Item Obj Id
		pNewItemList.WriteD(pOldItemList.ReadD()); // Item Id
		pNewItemList.WriteD(pOldItemList.ReadD()); // Item Count
		pNewItemList.WriteH(pOldItemList.ReadH()); // Item Type 2
		pNewItemList.WriteH(pOldItemList.ReadH()); // Item Type 3
		pNewItemList.WriteH(pOldItemList.ReadH()); // Is Equipped
		pNewItemList.WriteD(pOldItemList.ReadD()); // Body Part
		pNewItemList.WriteH(pOldItemList.ReadH()); // Enchant Level
		pNewItemList.WriteH(pOldItemList.ReadH()); // Item Type 3

		pNewItemList.WriteD(0); // Augment Id
		pNewItemList.WriteD(0); // Mana
	}
	
	pSocket->Send("b", pNewItemList.GetSize(), pNewItemList.GetPacket());
}