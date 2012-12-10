#include "Packet.h"

Packet::Packet() : iPacketSize(0) { }
Packet::Packet(Char *pPacket) : vPacket(pPacket), iPos(0) { }

void Packet::WriteC(Char pData)
{
	pPacket[iPacketSize] = pData;
	iPacketSize += sizeof(Char);
}

void Packet::WriteH(Int16 pData)
{
	*(Int16 *)&pPacket[iPacketSize] = pData;
	iPacketSize += sizeof(Int16);
}

void Packet::WriteD(Int32 pData)
{
	*(Int32 *)&pPacket[iPacketSize] = pData;
	iPacketSize += sizeof(Int32);
}

void Packet::WriteQ(Int64 pData)
{
	*(Int64 *)&pPacket[iPacketSize] = pData;
	iPacketSize += sizeof(Int64);
}

void Packet::WriteF(Double pData)
{
	*(Double *)&pPacket[iPacketSize] = pData;
	iPacketSize += sizeof(Double);
}

void Packet::WriteS(WChar *pData)
{
	int i = 0;
	while (iPacketSize < sizeof(pPacket) - 2)
	{
		WriteH((Int16)pData[i]);
		if (pData[i] == 0) break;
		i++;
	}
}

void Packet::WriteB(Char *pData, Int32 nCount)
{
	memcpy(&pPacket[iPacketSize], pData , nCount);
	iPacketSize += nCount;
}

Char Packet::ReadC()
{
	Char pData = vPacket[iPos];
	iPos += sizeof(Char);
	return pData;
}

Int16 Packet::ReadH()
{
	Int16 pData = *(Int16 *)&vPacket[iPos];
	iPos += sizeof(Int16);
	return pData;
}

Int32 Packet::ReadD()
{
	Int32 pData = *(Int32 *)&vPacket[iPos];
	iPos += sizeof(Int32);
	return pData;
}

Int64 Packet::ReadQ()
{
	Int64 pData = *(Int64 *)&vPacket[iPos];
	iPos += sizeof(Int64);
	return pData;
}

Double Packet::ReadF()
{
	Double pData = *(Double *)&vPacket[iPos];
	iPos += sizeof(Double);
	return pData;
}

WChar *Packet::ReadS()
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

char *Packet::ReadB(Int32 nSize)
{
	Char *pData = &vPacket[iPos];
	iPos += nSize;
	return pData;
}

Int32 Packet::GetSizeD() { return iPos; }
Int32 Packet::GetSizeA() { return iPacketSize; }
Char *Packet::GetPacket() { return &pPacket[0]; }
Packet::~Packet() { if(pPacket != NULL) { delete[] &pPacket; } }