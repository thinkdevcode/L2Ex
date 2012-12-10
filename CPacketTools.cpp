#ifndef _CPACKETTOOLS_
	#include "CPacketTools.h"
#endif

CPacketAssembler::CPacketAssembler()
{
	iPacketSize = 0;
}

void CPacketAssembler::WriteC(Char pData)
{
	pPacket[iPacketSize] = pData;

	iPacketSize += sizeof(Char);
}

void CPacketAssembler::WriteH(Int16 pData)
{
	*(Int16 *)&pPacket[iPacketSize] = pData;

	iPacketSize += sizeof(Int16);
}

void CPacketAssembler::WriteD(Int32 pData)
{
	*(Int32 *)&pPacket[iPacketSize] = pData;

	iPacketSize += sizeof(Int32);
}

void CPacketAssembler::WriteQ(Int64 pData)
{
	*(Int64 *)&pPacket[iPacketSize] = pData;

	iPacketSize += sizeof(Int64);
}

void CPacketAssembler::WriteF(Double pData)
{
	*(Double *)&pPacket[iPacketSize] = pData;

	iPacketSize += sizeof(Double);
}

void CPacketAssembler::WriteS(WChar *pData)
{
	int i = 0;

	while (iPacketSize < sizeof(pPacket) - 2)
	{
		WriteH((Int16)pData[i]);
		if (pData[i] == 0) break;
		i++;
	}
}

void CPacketAssembler::WriteB(Char *pData, Int32 nCount)
{
	memcpy(&pPacket[iPacketSize], pData , nCount);

	iPacketSize += nCount;
}

Int32 CPacketAssembler::GetSize()
{

	return iPacketSize;
}

Char *CPacketAssembler::GetPacket()
{

	return &pPacket[0];
}

CPacketAssembler::~CPacketAssembler()
{
	delete[] &pPacket;
}

// - CPacketDisassembler - //

CPacketDisassembler::CPacketDisassembler(Char *pPacket)
{
	vPacket = pPacket;
	iPos = 0;
}

Char CPacketDisassembler::ReadC()
{
	Char pData = vPacket[iPos];
	iPos += sizeof(Char);

	return pData;
}

Int16 CPacketDisassembler::ReadH()
{
	Int16 pData = *(Int16 *)&vPacket[iPos];
	iPos += sizeof(Int16);

	return pData;
}

Int32 CPacketDisassembler::ReadD()
{
	Int32 pData = *(Int32 *)&vPacket[iPos];
	iPos += sizeof(Int32);

	return pData;
}

Int64 CPacketDisassembler::ReadQ()
{
	Int64 pData = *(Int64 *)&vPacket[iPos];
	iPos += sizeof(Int64);

	return pData;
}

Double CPacketDisassembler::ReadF()
{
	Double pData = *(Double *)&vPacket[iPos];
	iPos += sizeof(Double);

	return pData;
}

WChar *CPacketDisassembler::ReadS()
{
	WChar *pData = (WChar *)&vPacket[iPos];
	WChar *pTmp = pData;

	iPos += 2;
	while (*pTmp)
	{
		iPos += 2;
		pTmp++;
	}

	return pData;
}

char *CPacketDisassembler::ReadB(Int32 nSize)
{
	Char *pData = &vPacket[iPos];
	iPos += nSize;

	return pData;
}

Int32 CPacketDisassembler::GetSize()
{

	return iPos;
}