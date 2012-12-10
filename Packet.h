	#ifndef _WINDOWS_
		#define WIN32_LEAN_AND_MEAN
			#include "windows.h"
	#endif

	#ifndef _INC_STDIO
		#include "stdio.h"
	#endif

class Packet
{
public:
	Packet();
	Packet(Char *pPacket);

	void WriteC(Char pData);
	void WriteH(Int16 pData);
	void WriteD(Int32 pData);
	void WriteQ(Int64 pData);
	void WriteF(Double pData);
	void WriteS(WChar *pData);
	void WriteB(Char *pData, Int32 nCount);

	Char ReadC();
	Int16 ReadH();
	Int32 ReadD();
	Int64 ReadQ();
	Double ReadF();
	WChar *ReadS();
	Char *ReadB(Int32 nSize);

	Int32 GetSizeD();
	Int32 GetSizeA();
	Char *GetPacket();

	~Packet();

private:
	Char pPacket[8192];
	Int32 iPacketSize;
	Char *vPacket;
	Int32 iPos;
};