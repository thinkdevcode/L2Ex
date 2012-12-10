#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void ShortCutRegister(CSocket *pSocket, va_list vPacket)
{
	CPacketAssembler pNewShortCutReg;

	pNewShortCutReg.WriteC(va_arg(vPacket, BYTE)); // OpCode

	Int32 nType = va_arg(vPacket, Int32); // ShortCut Type
	pNewShortCutReg.WriteD(nType);
	pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // ShortCut Slot

	switch (nType)
	{
		case 1: // Item
		{
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Item Id
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Unknown

			break;
		}

		case 2: // Skill
		{
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Skill Id
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Skill Level
			pNewShortCutReg.WriteC(0); // Unknown
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Unknown

			break;
		}

		case 3: // Action
		{
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Action Id
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Unknown

			break;
		}

		case 4: // Macro
		{
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Macro Id
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Unknown
		
			break;
		}

		case 5: // Recipe
		{
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Recipe Id
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Unknown

			break;
		}

		default: // Other
		{
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Other Id
			pNewShortCutReg.WriteD(va_arg(vPacket, Int32)); // Unknown

			break;
		}
	}

	pSocket->Send("b", pNewShortCutReg.GetSize(), pNewShortCutReg.GetPacket());
}
