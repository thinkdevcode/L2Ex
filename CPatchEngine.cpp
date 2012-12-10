#ifndef _CPATCHENGINE_
	#include "CPatchEngine.h"
#endif

#pragma warning(disable: 4311)
#pragma warning(disable: 4244)

CPatchEngine::CPatchEngine()
{
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		LUID luSEDebugNameValue;
		TOKEN_PRIVILEGES tpTokenPrivs;

		if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luSEDebugNameValue))
		{
			tpTokenPrivs.PrivilegeCount = 1;
			tpTokenPrivs.Privileges[0].Luid = luSEDebugNameValue;
			tpTokenPrivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

			if (!AdjustTokenPrivileges(hToken, FALSE, &tpTokenPrivs, sizeof(tpTokenPrivs), NULL, NULL))
			{
				char szErrBuf[256];

				sprintf_s(szErrBuf, 256, "There was an error opening L2Server. Please contact RiVaL with this Info:\n"
										 "AdjustTokenPrivileges Error: %d", GetLastError());
				MessageBox(NULL, szErrBuf, "L2Ex[Interlude]", MB_OK);

				ExitProcess(0);
			}
		}

		else
		{
			char szErrBuf[256];

			sprintf_s(szErrBuf, 256, "There was an error opening L2Server. Please contact RiVaL with this Info:\n"
									 "LookupPrivilegeValue Error: %d", GetLastError());
			MessageBox(NULL, szErrBuf, "L2Ex[Interlude]", MB_OK);

			ExitProcess(0);
		}

		CloseHandle(hToken);
	}

	else
	{
		char szErrBuf[256];

		sprintf_s(szErrBuf, 256, "There was an error opening L2Server. Please contact RiVaL with this Info:\n"
								 "OpenProcessToken Error: %d", GetLastError());
		MessageBox(NULL, szErrBuf, "L2Ex[Interlude]", MB_OK);

		ExitProcess(0);
	}

	hL2Server = OpenProcess(PROCESS_ALL_ACCESS, false, GetCurrentProcessId());

	if (!hL2Server)
	{
		char szErrBuf[256];

		sprintf_s(szErrBuf, 256, "There was an error opening L2Server. Please contact RiVaL with this Info:\n"
							     "OpenProcess Error: %d", GetLastError());
		MessageBox(NULL, szErrBuf, "L2Ex[Interlude]", MB_OK);

		ExitProcess(0);
	}
}

CPatchEngine *CPatchEngine::Instance()
{
	static CPatchEngine PatchEngine;

	return &PatchEngine;
}

void CPatchEngine::WriteByte(Byte *pAddress, Byte pData)
{
	WriteMemory(pAddress, &pData, sizeof(Byte));
}

void CPatchEngine::WriteInt16(Byte *pAddress, Int16 pData)
{
	WriteMemory(pAddress, &pData, sizeof(Int16));
}

void CPatchEngine::WriteInt32(Byte *pAddress, Int32 pData)
{
	WriteMemory(pAddress, &pData, sizeof(Int32));
}

void CPatchEngine::WriteInt64(Byte *pAddress, Int64 pData)
{
	WriteMemory(pAddress, &pData, sizeof(Int64));
}

void CPatchEngine::WriteArray(Byte *pAddress, LPCVOID pData, Int32 iLen)
{
	WriteMemory(pAddress, pData, iLen);
}

void CPatchEngine::WritePointer(Byte *pAddress, Int32 pPointer)
{
	int pData = (int)pPointer - (int)pAddress - 7;

	WriteMemory(pAddress + 3, &pData, sizeof(pData));
}

void CPatchEngine::WriteUnicodeString(Byte *pAddress, WChar *pData)
{
	WriteMemory(pAddress, (LPVOID)pData, wcslen(pData));
}

void CPatchEngine::WriteAnsiString(Byte *pAddress, Char *pData)
{
	WriteMemory(pAddress, (LPVOID)pData, strlen(pData));
}

void CPatchEngine::WriteJump(Byte *pAddress, DWORD *pNewFunc)
{
	BYTE pJmp = 0xE9;
	DWORD pNewFuncAddr = (DWORD)pNewFunc - (DWORD)(pAddress + 5);

	WriteMemory(pAddress, &pJmp, sizeof(pJmp));
	WriteMemory(pAddress + 1, &pNewFuncAddr, sizeof(pNewFuncAddr));
}

void CPatchEngine::WriteCall(Byte *pAddress, DWORD *pNewFunc)
{
	BYTE pCall = 0xE8;
	DWORD pNewFuncAddr = (DWORD)pNewFunc - (DWORD)(pAddress + 5);

	WriteMemory(pAddress, &pCall, sizeof(pCall));
	WriteMemory(pAddress + 1, &pNewFuncAddr, sizeof(pNewFuncAddr));
}

void CPatchEngine::WriteNops(Byte *pAddress, Int32 iNopCount)
{
	BYTE pNop = 0x90;

	for (int i = 0; i < iNopCount; ++i)
	{
		WriteMemory(pAddress + i, &pNop, 1);
	}
}

void CPatchEngine::WriteMemory(Byte *pAddress, LPCVOID pData, SIZE_T nSize)
{
	DWORD dwOldProtect;

	if (!VirtualProtectEx(hL2Server, (LPVOID)(pAddress), nSize, PAGE_EXECUTE_READWRITE, &dwOldProtect))
	{
		char szErrorBuf[256];

		sprintf_s(szErrorBuf, 256, "There was an error while trying to write memory to L2Server. Please contact RiVaL with this Info:\n"
								   "VirtualProtectEx Failed! Error: %d", GetLastError());

		MessageBox(NULL, szErrorBuf, "L2Ex[Interlude]", MB_OK);

		delete[] &szErrorBuf;
	}

	if (!WriteProcessMemory(hL2Server, (LPVOID)(pAddress), pData, nSize, NULL))
	{
		char szErrorBuf[256];

		sprintf_s(szErrorBuf, 256, "There was an error while trying to write memory to L2Server. Please contact RiVaL with this Info:\n"
								   "WriteProcessMemory Failed! Error: %d", GetLastError());

		MessageBox(NULL, szErrorBuf, "L2Ex[Interlude]", MB_OK);

		ExitProcess(0);
	}

	if (!VirtualProtectEx(hL2Server, (LPVOID)(pAddress), nSize, dwOldProtect, &dwOldProtect))
	{
		char szErrorBuf[256];

		sprintf_s(szErrorBuf, 256, "There was an error while trying to write memory to L2Server. Please contact RiVaL with this Info:\n"
								   "VirtualProtectEx2 Failed! Error: %d", GetLastError());

		delete[] &szErrorBuf;
	}
}

CPatchEngine::~CPatchEngine()
{
	CloseHandle(hL2Server);
}