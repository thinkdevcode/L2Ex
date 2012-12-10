#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void WarehouseWithdrawalList(CSocket *pSocket, va_list vPacket)
{
	BYTE bOpCode = va_arg(vPacket, BYTE);
	Int16 nWarehouseType = va_arg(vPacket, Int16);
	Int32 nPlayerAdena = va_arg(vPacket, Int32);
	Int16 nItemCount = va_arg(vPacket, Int16);

	Int32 nBufferSize = va_arg(vPacket, Int32);
	Char *szBuffer = va_arg(vPacket, Char *);
	CPacketDisassembler pOldWarehouseWithdrawalList(szBuffer);
	CPacketAssembler pNewWarehouseWithdrawalList;

	pNewWarehouseWithdrawalList.WriteC(bOpCode); // OpCode
	pNewWarehouseWithdrawalList.WriteH(nWarehouseType); // Warehouse Type
	pNewWarehouseWithdrawalList.WriteD(nPlayerAdena); // Player Adena
	pNewWarehouseWithdrawalList.WriteH(nItemCount); // Item Count

	for (Int32 i = 0; i < nItemCount; i++)
	{
		pNewWarehouseWithdrawalList.WriteH(pOldWarehouseWithdrawalList.ReadH()); // Item Type 1
		pNewWarehouseWithdrawalList.WriteD(pOldWarehouseWithdrawalList.ReadD()); // Item Object Id
		pNewWarehouseWithdrawalList.WriteD(pOldWarehouseWithdrawalList.ReadD()); // Item Id
		pNewWarehouseWithdrawalList.WriteD(pOldWarehouseWithdrawalList.ReadD()); // Item Count
		pNewWarehouseWithdrawalList.WriteH(pOldWarehouseWithdrawalList.ReadH()); // Item Type 2
		pNewWarehouseWithdrawalList.WriteH(pOldWarehouseWithdrawalList.ReadH()); // Unknown
		pNewWarehouseWithdrawalList.WriteD(pOldWarehouseWithdrawalList.ReadD()); // Body Part
		pNewWarehouseWithdrawalList.WriteH(pOldWarehouseWithdrawalList.ReadH()); // Enchant Level
		pNewWarehouseWithdrawalList.WriteH(pOldWarehouseWithdrawalList.ReadH()); // Unknown
		pNewWarehouseWithdrawalList.WriteH(pOldWarehouseWithdrawalList.ReadH()); // Unknown
		pNewWarehouseWithdrawalList.WriteD(pOldWarehouseWithdrawalList.ReadD()); // Item Object Id
		pNewWarehouseWithdrawalList.WriteD(0); // Augmentation Id 1
		pNewWarehouseWithdrawalList.WriteD(0); // Augmentation Id 2
	}

	pSocket->Send("b", pNewWarehouseWithdrawalList.GetSize(), pNewWarehouseWithdrawalList.GetPacket());
}