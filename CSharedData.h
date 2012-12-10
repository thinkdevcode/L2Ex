#ifndef _CSHAREDDATA_
	#define _CSHAREDDATA_

struct ExUserInfo
{
	int nTitleColor;
};

struct CSharedData
{
	/* 0000 */ int	_dw0000;
	/* 0004 */ int	_dw0004;
	/* 0008 */ double	x;
	/* 0010 */ double	y;
	/* 0018 */ double	z;

	/* 0020 */ int	_dw0020;
	/* 0024 */ int	nObjectID;
	/* 0028 */ int	_dw0028;	//0x06
	/* 002C */ int	nNpcIndex;	//0x5279

	/* 0030 */ int	_dw0030;
	/* 0034 */ int	_dw0034;
	/* 0038 */ int	_dw0038;
	/* 003C */ int	_dw003C;

	/* 0040 */ int	_dw0040;
	/* 0044 */ int	_dw0044;
	/* 0048 */ int	_dw0048;
	/* 004C */ int	_dw004C;

	/* 0050 */ int	_dw0050;	//1
	/* 0054 */ int	_dw0054;	//-2
	/* 0058 */ int	_dw0058;	//-1
	/* 005C */ int	_dw005C;	//0

	/* 0060 */ int	_dw0060;	//0
	/* 0064 */ int	nIsPC;	//1
	/* 0068 */ int	nIsAlive;		//???Player:1
	/* 006C */ int	_dw006C;

	/* 0070 */ int	_dw0070;
	/* 0074 */ int	_dw0074;
	/* 0078 */ int	_dw0078;
	/* 007C */ int	_dw007C;

	/* 0080 */ int	_dw0080;
	/* 0084 */ int	_dw0084;
	/* 0088 */ int	_dw0088;
	/* 008C */ int	_dw008C;
	
	/* 0090 */ int	_dw0090;
	/* 0094 */ int	_dw0094;
	/* 0098 */ int	_dw0098;
	/* 009C */ int	nIsNoblesse;
	
	/* 00A0 */ int	nIsHero;
	/* 00A4 */ int	_dw00A4;
	/* 00A8 */ int	nNoblesseType;
	/* 00AC */ int	nBaseClass;
	
	/* 00B0 */ int	_dw00B0;
	/* 00B4 */ int	_dw00B4;
	/* 00B8 */ int	_dw00B8;
	/* 00BC */ int	nRace;
	
	/* 00C0 */ int	nClass;
	/* 00C4 */ int	nSex;
	/* 00C8 */ wchar_t	wszName[14];
	/* 00E4 */ int	nNpcLevel;
	/* 00E8 */ ExUserInfo *pExUserInfo; //USERINFOEX	*pUserEx;	//pUserEx 8字节

	/* 00F0 */ int	_dw00F0;
	/* 00F4 */ int	_dw00F4;
	/* 00F8 */ short	_w00F8;
	/* 00FA */ bool	bUndying;
	/* 00FB */ bool	bCanBeAttacked;
	/* 00FC */ bool	bHide;
	/* 00FD */ bool	_b00FD;
	/* 00FE */ short	_w00FE;

	/* 0100 */ int	_dw0100;
	/* 0104 */ int	_dw0104;
	/* 0108 */ int	_dw0108;
	/* 010C */ int	_dw010C;

	/* 0110 */ int	nHairShape;	// 发型药水
	/* 0114 */ int	nHairColor;	// 染发药水
	/* 0118 */ int	nFaceIndex;	// 整形药水
	/* 011C */ int	nExp;
	/* 0120 */ int	nSp;

	/* 0124 */ int	nObjIdAdena;
	/* 0128 */ int	nObjIdUnder;
	/* 012C */ int	nObjIdLEar;

	/* 0130 */ int	nObjIdREar;
	/* 0134 */ int	nObjIdNeck;
	/* 0138 */ int	nObjIdLRing;
	/* 013C */ int	nObjIdRRing;

	/* 0140 */ int	nObjIdHead;
	/* 0144 */ int	nObjIdLHand;
	/* 0148 */ int	nObjIdRHand;
	/* 014C */ int	nObjIdGloves;

	/* 0150 */ int	nObjIdChest;
	/* 0154 */ int	nObjIdLegs;
	/* 0158 */ int	nObjIdFeet;
	/* 015C */ int	nObjIdBack;

	/* 0160 */ int	nObjId2Hand;
	/* 0164 */ int	nObjIdOnePiece;
	/* 0168 */ int	nObjIdHair;
	/* 016C */ int	nObjIdDress;
	
	/* 0170 */ int	nDefaultINT;
	/* 0174 */ int	nDefaultSTR;
	/* 0178 */ int	nDefaultCON;
	/* 017C */ int	nDefaultMEN;
	/* 0180 */ int	nDefaultDEX;
	/* 0184 */ int	nDefaultWIT;
	
	/* 0188 */ double	fHP;
	/* 0190 */ double	fMP;
	/* 0198 */ double	fCP;
	
	/* 01A0 */ int _n1A0;
	/* 01A4 */ int nMoveType;
	/* 01A8 */ int _n1A8;
	/* 01AC */ int _n1AC;

	/* 01B0 */ int _n1B0;
	/* 01B4 */ int _n1B8;
	/* 01B8 */ int nTargetIndex;
	/* 01BC */ int nTargetObjId;

	/* 01C0 */ int _n1C0;
	/* 01C4 */ int _n1C4;
	/* 01C8 */ int nPvPCount;
	/* 01CC */ int _n1CC;

	/* 01D0 */ int _n1D0;
	/* 01D4 */ short wPkCount;
	/* 01D6 */ short _w1D6;
	/* 01D8 */ short wRecommRecv;
	/* 01DA */ short wRecommLeft;
	/* 01DC */ int nKarma;
	
	/* 01E0 */ int _n1E0;
	/* 01E4 */ int nTutorialQuestId;
	/* 01E8 */ int nTutotialState;
	/* 01EC */ int nTutotialJournal;

	/* 01F0 */ int quests[64];	//QUESTDATA quests[16];

	/* 02F0 */ int _n2F0;
	/* 02F4 */ int _n2F4;
	/* 02F8 */ int _n2F8;
	/* 02FC */ int _n2FC;

	/* 0300 */ int _n300;
	/* 0304 */ int nQuestLastRewardTime;
	/* 0308 */ int nLastAttackerIndex;
	/* 030C */ int _n30C;

	/* 0310 */ int _n310;
	/* 0314 */ int _n314;
	/* 0318 */ int nPledgeId;
	/* 031C */ int _n31C;

	/* 0320 */ int nIsPledgeLeader;
	/* 0324 */ int _n324;
	/* 0328 */ int _n328;
	/* 032C */ int _n32C;

	/* 0330 */ int _n330;
	/* 0334 */ int _n334;
	/* 0338 */ int _n338;
	/* 033C */ int _n33C;

	/* 0340 */ int _n340;
	/* 0344 */ int _n344;
	/* 0348 */ int _n348;
	/* 034C */ int _n34C;

	/* 0350 */ int _n350;
	/* 0354 */ int _n354;
	/* 0358 */ int _n358;
	/* 035C */ int _n35C;

	/* 0360 */ int _n360;
	/* 0364 */ int _n364;
	/* 0368 */ int _n368;
	/* 036C */ int bIsRiding;
	
	/* 0370 */ int _n370;
	/* 0374 */ int _n374;
	/* 0378 */ int _n378;
	/* 037C */ bool bSoulShot;
	/* 037D */ bool _b37D;
	/* 037E */ short _w37E;
	
	/* 0380 */ double fSoulShotPower;
	/* 0388 */ bool bSpiritShot;
	/* 0389 */ bool _b389;
	/* 038A */ short _w38A;
	/* 038C */ int _n38C;

	/* 0390 */ double fSpiritShotPower;
	/* 0398 */ int _n398;
	/* 039C */ int _n39C;

	/* 03A0 */ int _n3A0;
	/* 03A4 */ int _n3A4;
	/* 03A8 */ int _n3A8;
	/* 03AC */ int _n3AC;

	/* 03B0 */ int _n3B0;
	/* 03B4 */ int _n3B4;
	/* 03B8 */ int _n3B8;
	/* 03BC */ int _n3BC;

	/* 03C0 */ int _n3C0;
	/* 03C4 */ int _n3C4;
	/* 03C8 */ int _n3C8;
	/* 03CC */ int _n3CC;

	/* 03D0 */ int _n3D0;
	/* 03D4 */ int _n3D4;
	/* 03D8 */ int _n3D8;
	/* 03DC */ int _n3DC;

	/* 03E0 */ int _n3E0;
	/* 03E4 */ int _n3E4;
	/* 03E8 */ int _n3E8;
	/* 03EC */ int _n3EC;

	/* 03F0 */ int _n3F0;
	/* 03F4 */ int _n3F4;
	/* 03F8 */ int _n3F8;
	/* 03FC */ int _n3FC;

	/* 0400 */ int _n400;
	/* 0404 */ int _n404;
	/* 0408 */ int _n408;
	/* 040C */ int _n40C;

	/* 0410 */ int _n410;
	/* 0414 */ int nBaseAttackSpeed;
	/* 0418 */ int nBaseCritical;

	/* 041C */ int nINT;
	/* 0420 */ int nSTR;
	/* 0424 */ int nCON;
	/* 0428 */ int nMEN;
	/* 042C */ int nDEX;
	/* 0430 */ int nWIT;
	
	/* 0434 */ int _n434;
	/* 0438 */ int _n438;
	/* 043C */ int _n43C;
	/* 0440 */ int _n440;

	//=====================//

	/* 0444 */ int nLevel;
	/* 0448 */ int _n448;
	/* 044C */ int _n44C;
	/* 0450 */ int _n450;
	/* 0454 */ int _n454;
	/* 0458 */ int _n458;
	/* 045C */ int _n45C;
	/* 0460 */ int _n460;
	/* 0464 */ int _n464;
	/* 0468 */ int _n468;
	/* 046C */ int _n46C;
	/* 0470 */ int _n470;
	/* 0474 */ int _n474;
	/* 0478 */ int _n478;
	/* 047C */ int _n47C;
	/* 0480 */ int _n480;
	/* 0484 */ int _n484;
	/* 0488 */ int _n488;
	/* 048C */ int _n48C;

	/* 0490 */ int nMaxSlot;
	/* 0494 */ int nCurrSlot;
	/* 0498 */ int nCurrWeight;
	/* 049C */ int _n49C;

	/* 04A0 */ double fMaxLoad;
	/* 04A8 */ double fOrgHP;
	/* 04B0 */ double fOrgMP;
	/* 04B8 */ double fOrgCP;
	/* 04C0 */ double fMaxHP;
	/* 04C8 */ double fMaxMP;
	/* 04D0 */ double fMaxCP;
	/* 04D8 */ double _fHpRegen;
	/* 04E0 */ double _fMpRegen;
	/* 04E8 */ double fOrgSpeed;
	/* 04F0 */ double fSpeed;
	/* 04F8 */ double _f4F8;
	/* 0500 */ double _f500;
	/* 0508 */ double _f508;
	/* 0510 */ double fNoise;
	/* 0518 */ double fHit;
	/* 0520 */ double fAvoid;
	/* 0528 */ double _f528;
	/* 0530 */ double _f530;
	/* 0538 */ double _f538;
	/* 0540 */ double _f540;
	/* 0548 */ double _f548;

	/* 0550 */ int _n550;
	/* 0554 */ int _n554;
	/* 0558 */ int _n558;
	/* 055C */ int _n55C;
	/* 0560 */ int _n560;
	/* 0564 */ int _n564;
	
	/* 0568 */ int nWeaponClassId;
	/* 056C */ int nWeaponType;
	
	/* 0570 */ int _n570;
	/* 0574 */ int _n574;
	/* 0578 */ int _n578;
	/* 057C */ int _n57C;

	/* 0580 */ int _n580;
	/* 0584 */ int _n584;
	/* 0588 */ int _n588;
	/* 058C */ int _n58C;
	/* 0590 */ int _n590;
	/* 0594 */ int _n594;
	/* 0598 */ int _n598;
	/* 059C */ int _n59C;
	/* 05A0 */ int _n5A0;
	/* 05A4 */ int _n5A4;
	/* 05A8 */ int _n5A8;
	/* 05AC */ int _n5AC;

	/* 05B0 */ double fPAtk;
	/* 05B8 */ double fMAtk;
	/* 05C0 */ double fPDef;
	/* 05C8 */ double fMDef;
	/* 05D0 */ double fAtkSpeed;
	/* 05D8 */ double fBaseCritical;
	/* 05E0 */ double fBaseAtkSpeed;
	/* 05E8 */ double fBaseCastSpeed;

	/* 05F0 */ int _n5F0;
	/* 05F4 */ int _n5F4;
	/* 05F8 */ int _n5F8;
	/* 05FC */ int _n5FC;

	/* 0600 */ int _n600;
	/* 0604 */ int _n604;
	/* 0608 */ int _n608;
	/* 060C */ int _n60C;

	/* 0610 */ int _n610;
	/* 0614 */ int _n614;
	/* 0618 */ int nBuilder;
	/* 061C */ int _n61C;

	/* 08E8 */ //PledgePower
	/* 08F0 */ //PledgePower
	/* 08F8 */ //PledgePower
	/* 0900 */ //PledgePower
};

#endif