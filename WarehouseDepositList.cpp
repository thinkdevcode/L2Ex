#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void WarehouseDepositList(CSocket *pSocket, va_list vPacket)
{
	BYTE bOpCode = va_arg(vPacket, BYTE);
	Int16 nWarehouseType = va_arg(vPacket, Int16);
	Int32 nPlayerAdena = va_arg(vPacket, Int32);
	Int16 nItemCount = va_arg(vPacket, Int16);

	Int32 nBufferSize = va_arg(vPacket, Int32);
	Char *szBuffer = va_arg(vPacket, Char *);
	CPacketDisassembler pOldWarehouseDepositList(szBuffer);
	CPacketAssembler pNewWarehouseDepositList;

	pNewWarehouseDepositList.WriteC(bOpCode); // OpCode
	pNewWarehouseDepositList.WriteH(nWarehouseType); // Warehouse Type
	pNewWarehouseDepositList.WriteD(nPlayerAdena); // Player Adena
	pNewWarehouseDepositList.WriteH(nItemCount); // Item Count

	for (Int32 i = 0; i < nItemCount; i++)
	{
		pNewWarehouseDepositList.WriteH(pOldWarehouseDepositList.ReadH()); // Item Type 1
		pNewWarehouseDepositList.WriteD(pOldWarehouseDepositList.ReadD()); // Item Object Id
		pNewWarehouseDepositList.WriteD(pOldWarehouseDepositList.ReadD()); // Item Id
		pNewWarehouseDepositList.WriteD(pOldWarehouseDepositList.ReadD()); // Item Count
		pNewWarehouseDepositList.WriteH(pOldWarehouseDepositList.ReadH()); // Item Type 2
		pNewWarehouseDepositList.WriteH(pOldWarehouseDepositList.ReadH()); // Unknown
		pNewWarehouseDepositList.WriteD(pOldWarehouseDepositList.ReadD()); // Body Part
		pNewWarehouseDepositList.WriteH(pOldWarehouseDepositList.ReadH()); // Enchant Level
		pNewWarehouseDepositList.WriteH(pOldWarehouseDepositList.ReadH()); // Unknown
		pNewWarehouseDepositList.WriteH(pOldWarehouseDepositList.ReadH()); // Unknown
		pNewWarehouseDepositList.WriteD(pOldWarehouseDepositList.ReadD()); // Item Object Id
		pNewWarehouseDepositList.WriteD(0); // Augmentation Id 1
		pNewWarehouseDepositList.WriteD(0); // Augmentation Id 2
	}

	pSocket->Send("b", pNewWarehouseDepositList.GetSize(), pNewWarehouseDepositList.GetPacket());
}