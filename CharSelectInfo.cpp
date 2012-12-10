#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void CharSelectInfo(CSocket *pSocket, va_list vPacket)
{
	BYTE pPacketHeader = va_arg(vPacket, Byte);
	Int32 nCharCount = va_arg(vPacket, Int32);
	Int32 nBufferSize = va_arg(vPacket, Int32);

	Char *pBuffer = va_arg(vPacket, Char *);
	CPacketDisassembler pCSIBuffer(pBuffer);

	CPacketAssembler pCSIPacket;

	pCSIPacket.WriteC(pPacketHeader); // OpCode
	pCSIPacket.WriteD(nCharCount); // Char Count

	for (Int32 i = 0; i < nCharCount; i++)
	{
		pCSIPacket.WriteS(pCSIBuffer.ReadS()); // Character Name
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Character ID
		pCSIPacket.WriteS(pCSIBuffer.ReadS()); // Account Name
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Session ID
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Clan Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0x01)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Sex (Male ? Female)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Race (0-4)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Class Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Active?
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // X Location
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Y Location
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Z location
		pCSIPacket.WriteF(pCSIBuffer.ReadF()); // Current HP
		pCSIPacket.WriteF(pCSIBuffer.ReadF()); // Current MP
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // SP
		pCSIPacket.WriteQ(pCSIBuffer.ReadD()); // Exp
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Level
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Karma
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Unknown (0)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Hair Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Right Earring Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Left Earring Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Necklace Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Right Ring Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Left Ring Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Helmet Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Right Hand Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Left Hand Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Gloves Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Chest Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Legs Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Boots Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Back Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Left/Right Hand (Duels/Fists) Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Hair Obj Id
		pCSIPacket.WriteD(0); // Face Obj Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Hair
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Right Earring
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Left Earring
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Necklace
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Right Ring
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Left Ring
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Helmet
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Right Hand
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Left Hand
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Gloves
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Chest
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Legs
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Boots
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Back
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Left/Right Hand (Duels/Fists)
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Hair
		pCSIPacket.WriteD(0); // Face
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Hair Style
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Hair Color
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Face Style
		pCSIPacket.WriteF(pCSIBuffer.ReadF()); // Max HP
		pCSIPacket.WriteF(pCSIBuffer.ReadF()); // Max MP
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Delete Time
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Class Id
		pCSIPacket.WriteD(pCSIBuffer.ReadD()); // Auto Select
		pCSIPacket.WriteC(pCSIBuffer.ReadC()); // Enchant Effect
		pCSIPacket.WriteD(0); // Augment Id
	}

	pSocket->Send("b", pCSIPacket.GetSize(), pCSIPacket.GetPacket());
}
