#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void SkillList(CSocket *pSocket, va_list vPacket)
{
	BYTE bOpCode = va_arg(vPacket, BYTE);
	Int32 nSkillSize = va_arg(vPacket, Int32);

	Int32 nBufferSize = va_arg(vPacket, Int32);
	Char *szBuffer = va_arg(vPacket, Char *);
	CPacketDisassembler pOldSkillList(szBuffer);

	CPacketAssembler pNewSkillList;

	pNewSkillList.WriteC(bOpCode); // OpCode
	pNewSkillList.WriteD(nSkillSize); // Number of Skills

	for (Int32 i = 0; i < nSkillSize; i++)
	{
		pNewSkillList.WriteD(pOldSkillList.ReadD()); // Is Passive
		pNewSkillList.WriteD(pOldSkillList.ReadD()); // Skill Level
		pNewSkillList.WriteD(pOldSkillList.ReadD()); // Skill Id
		pNewSkillList.WriteC(0); // Unknown
	}

	pSocket->Send("b", pNewSkillList.GetSize(), pNewSkillList.GetPacket());
}