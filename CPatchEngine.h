#ifndef _CPATCHENGINE_
	#define _CPATCHENGINE_

	#ifndef _WINDOWS_
		#define WIN32_LEAN_AND_MEAN
			#include "windows.h"
	#endif

	#ifndef _INC_STDIO
		#include "stdio.h"
	#endif

class CPatchEngine
{
public:

	CPatchEngine();

	static CPatchEngine *Instance();

	void WriteByte(BYTE *pAddress, BYTE pData);
	void WriteInt16(BYTE *pAddress, Int16 pData);
	void WriteInt32(BYTE *pAddress, Int32 pData);
	void WriteInt64(BYTE *pAddress, Int64 pData);
	void WriteArray(BYTE *pAddress, LPCVOID pData, Int32 iLen);
	void WritePointer(BYTE *pAddress, Int32 pPointerAddr);
	void WriteUnicodeString(BYTE *pAddress, WChar *pData);
	void WriteAnsiString(BYTE *pAddress, Char *pData);
	void WriteJump(BYTE *pAddress, DWORD *pNewFunc);
	void WriteCall(BYTE *pAddress, DWORD *pNewFunc);
	void WriteNops(BYTE *pAddress, Int32 iNopCount);

	~CPatchEngine();

private:

	void WriteMemory(BYTE *pAddress, LPCVOID pData, SIZE_T nSize);

	HANDLE hL2Server;
	HANDLE hToken;
};

#endif