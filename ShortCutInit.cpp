#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void ShortCutInit(CSocket *pSocket, va_list vPacket)
{
	BYTE bOpCode = va_arg(vPacket, BYTE);
	Int32 nLength = va_arg(vPacket, Int32);

	Int32 nBufferSize = va_arg(vPacket, Int32);
	Char *szBuffer = va_arg(vPacket, Char *);

	CPacketDisassembler pOldShortCutInit(szBuffer);

	CPacketAssembler pNewShortCutInit;

	pNewShortCutInit.WriteC(bOpCode); // OpCode
	pNewShortCutInit.WriteD(nLength); // ShortCut Length

	for (Int32 i = 0; i < nLength; i++)
	{
		Int32 nType = pOldShortCutInit.ReadD(); // ShortCut Type
		pNewShortCutInit.WriteD(nType);
		pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // ShortCut Slot

		switch (nType)
		{
			case 1: // Item
			{
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Item Id
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Unknown
				pNewShortCutInit.WriteD(-1); // Unknown
				pNewShortCutInit.WriteD(0); // Unknown
				pNewShortCutInit.WriteD(0); // Unknown
				pNewShortCutInit.WriteH(0); // Unknown
				pNewShortCutInit.WriteH(0); // Unknown

				break;
			}

			case 2: // Skill
			{
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Skill Id
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Skill Level
				pNewShortCutInit.WriteC(0); // Unknown
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Unknown
			
				break;
			}

			case 3: // Action
			{
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Action Id
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Unknown

				break;
			}

			case 4: // Macro
			{
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Macro Id
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Unknown

				break;
			}

			case 5: // Recipe
			{
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Recipe Id
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Unknown

				break;
			}

			default: // Other
			{
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Other Id
				pNewShortCutInit.WriteD(pOldShortCutInit.ReadD()); // Unknown

				break;
			}
		}
	}

	pSocket->Send("b", pNewShortCutInit.GetSize(), pNewShortCutInit.GetPacket());
}

