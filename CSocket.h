#ifndef _CSOCKET_
	#define _CSOCKET_

	#ifndef _WINSOCK2_
		#include "winsock2.h"
	#endif

	#ifndef _CCREATURE_
		#include "CCreature.h"
	#endif

class CCreature;

class CSocket
{
public:

	void SetAddress(in_addr addr)
	{
		typedef void (__thiscall *_SET_ADDRESS)(CSocket *, in_addr);
		_SET_ADDRESS _SetAddress = (_SET_ADDRESS)0x7D52C0;

		_SetAddress(this, addr);
	}

	in_addr GetAddress()
	{
		typedef in_addr (__thiscall *_GET_ADDRESS)(CSocket *);
		_GET_ADDRESS _GetAddress = (_GET_ADDRESS)0x7D53B0;

		return (_GetAddress(this));
	}

	void SetKey(int nKey)
	{
		typedef void (__thiscall *_SET_KEY)(CSocket *);
		_SET_KEY _SetKey = (_SET_KEY)0x7D5BF0;
		
		_SetKey(this);
	}

	void SendV(const char *format, va_list va)
	{
		typedef void (__thiscall *_SENDV)(CSocket *, const char *, va_list);
		_SENDV _SendV = (_SENDV)0x7D5D40;

		_SendV(this, format, va);
	}

	void Send(const char *format, ...)
	{
		va_list vl;
		va_start(vl, format);

		this->SendV(format, vl);

		va_end(vl);
	}

	User *GetUser()
	{

		return pUser;
	}

private:

	int iUnk1[44]; // 0x00

	in_addr pAddress; // 0x0B0

	int iUnk2[41]; // 0x0B4

	User *pUser; // 0x158

};

#endif