#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

// Packet Format
// ccddd

void ProtocolVersion(CSocket *pSocket, va_list vPacket)
{
	CPacketAssembler pNewProtocolVersion;

	pNewProtocolVersion.WriteC(va_arg(vPacket, Byte));
	pNewProtocolVersion.WriteC(va_arg(vPacket, Byte));
	pNewProtocolVersion.WriteD(va_arg(vPacket, Int32));
	
	Int32 nOldKey = va_arg(vPacket, Int32);
	Int32 nNewKey = 0;
	pNewProtocolVersion.WriteD(nNewKey); // Zero Key

	pNewProtocolVersion.WriteD(va_arg(vPacket, Int32));

	pSocket->Send("b", pNewProtocolVersion.GetSize(), pNewProtocolVersion.GetPacket());
}