#ifndef _CPACKETTOOLS_
	#define _CPACKETTOOLS_

	#ifndef _WINDOWS_
		#define WIN32_LEAN_AND_MEAN
			#include "windows.h"
	#endif

	#ifndef _INC_STDIO
		#include "stdio.h"
	#endif

class CPacketAssembler
{
public:

	CPacketAssembler();

	void WriteC(Char pData);
	void WriteH(Int16 pData);
	void WriteD(Int32 pData);
	void WriteQ(Int64 pData);
	void WriteF(Double pData);
	void WriteS(WChar *pData);
	void WriteB(Char *pData, Int32 nCount);

	Int32 GetSize();
	Char *GetPacket();

	~CPacketAssembler();

private:

	Char pPacket[8192];
	Int32 iPacketSize;
};

class CPacketDisassembler
{
public:

	CPacketDisassembler(Char *pPacket);

	Char ReadC();
	Int16 ReadH();
	Int32 ReadD();
	Int64 ReadQ();
	Double ReadF();
	WChar *ReadS();
	Char *ReadB(Int32 nSize);

	Int32 GetSize();

private:

	Char *vPacket;
	Int32 iPos;
};

#endif