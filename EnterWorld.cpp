#ifndef _L2EX_
	#include "L2Ex.h"
#endif

void EnterWorld(User *pUser)
{
	pUser->GetSharedData()->pExUserInfo = new ExUserInfo;

	pUser->EnterWorld();
}