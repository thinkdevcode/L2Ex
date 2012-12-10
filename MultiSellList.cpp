#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void MultiSellList(CSocket *pSocket, va_list vPacket)
{
	BYTE bOpCode = va_arg(vPacket, BYTE);
	Int32 nListId = va_arg(vPacket, Int32);
	Int32 nPage = va_arg(vPacket, Int32);
	Int32 nFinished = va_arg(vPacket, Int32);
	Int32 nPageSize = va_arg(vPacket, Int32);
	Int32 nListLength = va_arg(vPacket, Int32);

	Int32 nBufferSize = va_arg(vPacket, Int32);
	Char *szBuffer = va_arg(vPacket, Char *);
	CPacketDisassembler pOldMultiSellList(szBuffer);
	CPacketAssembler pNewMultiSellList;

	pNewMultiSellList.WriteC(bOpCode); // OpCode
	pNewMultiSellList.WriteD(nListId); // List Id
	pNewMultiSellList.WriteD(nPage); // Page
	pNewMultiSellList.WriteD(nFinished); // Finished
	pNewMultiSellList.WriteD(nPageSize); // Page Size
	pNewMultiSellList.WriteD(nListLength); // ListLength

	for (Int32 i = 0; i < nListLength; i++)
	{
		pNewMultiSellList.WriteD(pOldMultiSellList.ReadD()); // Entry Id
		pNewMultiSellList.WriteD(0); // Unknown
		pNewMultiSellList.WriteD(0); // Unknown
		pNewMultiSellList.WriteC(pOldMultiSellList.ReadC()); // Unknown
		Int16 nProductSize = pOldMultiSellList.ReadH(); // Product Size
		Int16 nIngredientsSize = pOldMultiSellList.ReadH(); // Ingredients Size
		pNewMultiSellList.WriteH(nProductSize);
		pNewMultiSellList.WriteH(nIngredientsSize);

		for (Int16 x = 0; x < nProductSize; x++)
		{
			pNewMultiSellList.WriteH(pOldMultiSellList.ReadH()); // Item Id
			pNewMultiSellList.WriteD(pOldMultiSellList.ReadD()); // Unknown
			pNewMultiSellList.WriteH(pOldMultiSellList.ReadH()); // Item Type 2
			pNewMultiSellList.WriteD(pOldMultiSellList.ReadD()); // Item Count
			pNewMultiSellList.WriteH(pOldMultiSellList.ReadH()); // Enchant Level
			pNewMultiSellList.WriteD(0); // Unknown
			pNewMultiSellList.WriteD(0); // Unknown
		}

		for (Int16 j = 0; j < nIngredientsSize; j++)
		{
			pNewMultiSellList.WriteH(pOldMultiSellList.ReadH()); // Items Id
			pNewMultiSellList.WriteH(pOldMultiSellList.ReadH()); // Item Type 2
			pNewMultiSellList.WriteD(pOldMultiSellList.ReadD()); // Item Count
			pNewMultiSellList.WriteH(pOldMultiSellList.ReadH()); // Enchant Level
			pNewMultiSellList.WriteD(0); // Unknown
			pNewMultiSellList.WriteD(0); // Unknown
		}
	}

	pSocket->Send("b", pNewMultiSellList.GetSize(), pNewMultiSellList.GetPacket());
}
