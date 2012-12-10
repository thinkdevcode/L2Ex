#include "windows.h"
#include "stdio.h"

HANDLE hServer;
HANDLE hToken;

void WriteMemory(BYTE *pAddress, LPCVOID pData, SIZE_T nSize);
void WriteJump(BYTE *pAddress, DWORD *pNewFunc);
void WriteCall(BYTE *pAddress, DWORD *pNewFunc);
void WriteNops(BYTE *pAddress, int iNopCount);

__declspec(dllexport) BOOL WINAPI DllMain ( HINSTANCE hInstance, DWORD dwReason, LPVOID lpvReserved )
{
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		LUID luSEDebugNameValue;
		TOKEN_PRIVILEGES tpTokenPrivs;
		if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luSEDebugNameValue)) {
			tpTokenPrivs.PrivilegeCount = 1;
			tpTokenPrivs.Privileges[0].Luid = luSEDebugNameValue;
			tpTokenPrivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
			if (!AdjustTokenPrivileges(hToken, FALSE, &tpTokenPrivs, sizeof(tpTokenPrivs), NULL, NULL)) {
				MessageBox(NULL, "AdjustTokenPrivileges failed!", "Hook", MB_OK);
				ExitProcess(0);
			}
		}
		else {
			MessageBox(NULL, "LookupPrivilegeValue Error", "Hook", MB_OK);
			ExitProcess(0);
		}
		CloseHandle(hToken);
	}
	else {
		MessageBox(NULL, "OpenProcessToken Error", "Hook", MB_OK);
		ExitProcess(0);
	}
	hServer = OpenProcess(PROCESS_ALL_ACCESS, false, GetCurrentProcessId());
	if (!hServer) {
		MessageBox(NULL, "OpenProcess Error", "Hook", MB_OK);
		ExitProcess(0);
	}
}

void WriteMemory ( BYTE *pAddress, LPCVOID pData, SIZE_T nSize )
{
	DWORD dwOldProtect;
	if (!VirtualProtectEx(hServer, (LPVOID)(pAddress), nSize, PAGE_EXECUTE_READWRITE, &dwOldProtect))	{
		MessageBox(NULL, "VirtualProtectEx Failed!", "Hook", MB_OK);
	}
	if (!WriteProcessMemory(hServer, (LPVOID)(pAddress), pData, nSize, NULL))	{
		MessageBox(NULL, "WriteProcessMemory Failed!", "Hook", MB_OK);
		ExitProcess(0);
	}
	if (!VirtualProtectEx(hServer, (LPVOID)(pAddress), nSize, dwOldProtect, &dwOldProtect)) { }
}

void WriteJump ( BYTE *pAddress, DWORD *pNewFunc )
{
	BYTE pJmp = 0xE9;
	DWORD pNewFuncAddr = (DWORD)pNewFunc - (DWORD)(pAddress + 5);
	WriteMemory(pAddress, &pJmp, sizeof(pJmp));
	WriteMemory(pAddress + 1, &pNewFuncAddr, sizeof(pNewFuncAddr));
}

void WriteCall ( BYTE *pAddress, DWORD *pNewFunc )
{
	BYTE pCall = 0xE8;
	DWORD pNewFuncAddr = (DWORD)pNewFunc - (DWORD)(pAddress + 5);
	WriteMemory(pAddress, &pCall, sizeof(pCall));
	WriteMemory(pAddress + 1, &pNewFuncAddr, sizeof(pNewFuncAddr));
}

void WriteNops ( BYTE *pAddress, int iNopCount )
{
	BYTE pNop = 0x90;
	for (int i = 0; i < iNopCount; ++i)	{
		WriteMemory(pAddress + i, &pNop, 1);
	}
}