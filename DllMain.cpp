#ifndef _DLLMAIN_
	#include "DllMain.h"
#endif

DllExport BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpvReserved)
{
	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			L2Ex::Instance()->Initialize();

			break;
		}

		case DLL_PROCESS_DETACH:
		{

			break;
		}
	}

	return true;
}