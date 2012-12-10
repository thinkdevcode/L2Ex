#ifndef _SERVERPACKETS_
	#include "ServerPackets.h"
#endif

void UserInfo(CSocket *pSocket, va_list vPacket)
{
	char szUserInfo[8192];
	L2Server::VAssemble(szUserInfo, 8192, "cdddddSdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddffffddddSdddddcccddhbcdcddhhdhddddccdcccdddd", vPacket);
	CPacketDisassembler pOldUserInfo(szUserInfo);

	User *pUser = pSocket->GetUser();
	CSharedData *pSharedData = pUser->GetSharedData();

	CPacketAssembler pNewUserInfo;

	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // OpCode
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // X Location
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Y Location
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Z Location
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Heading
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Object Id
	pNewUserInfo.WriteS(pOldUserInfo.ReadS()); // Name
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Race
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Sex
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Class Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Level
	pNewUserInfo.WriteQ(pOldUserInfo.ReadD()); // Exp
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // STR
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // DEX
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // CON
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // INT
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // WIT
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // MEN
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Max HP
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Current HP
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Max MP
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Current MP
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // SP
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Current Weight
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Max Weight
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Unknown

	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Hair Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Right Ear Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Left Ear Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Necklace Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Right Finger Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Left Finger Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Head Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Right Hand Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Left Hand Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Gloves Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Chest Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Legs Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Feet Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Back Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Left/Right Hand Object Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Hair Object Id
	pNewUserInfo.WriteD(0); // Face Object Id

	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Hair Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Right Ear Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Left Ear Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Necklace Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Right Finger Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Left Finger Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Head Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Right Hand Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Left Hand Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Gloves Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Chest Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Legs Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Feet Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Back Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Left/Right Hand Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Hair Id
	pNewUserInfo.WriteD(0); // Face Id

	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteD(0); // Right Hand Augment Id
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteD(0); // Left/Right Hand Augment Id
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown
	pNewUserInfo.WriteH(0); // Unknown

	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Physical Attack
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Physical Attack Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Physical Defense
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Evasion Rate
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Accuracy
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Critical Hit
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Magical Attack
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Magical Attack Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Physical Attack Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Magical Defense
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // PvP Flag (0 = Non-PvP : 1 = PvP)
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Karma
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Run Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Walk Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Swim Run Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Swim Walk Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Fly Run Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Fly Walk Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Fly2 Run Speed
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Fly2 Walk Speed
	pNewUserInfo.WriteF(pOldUserInfo.ReadF()); // Move Multiplier
	pNewUserInfo.WriteF(pOldUserInfo.ReadF()); // Attack Speed Multiplier
	pNewUserInfo.WriteF(pOldUserInfo.ReadF()); // Collision Radius
	pNewUserInfo.WriteF(pOldUserInfo.ReadF()); // Collision Height
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Hair Style
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Hair Color
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Face
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Builder Level
	pNewUserInfo.WriteS(pOldUserInfo.ReadS()); // Title
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Clan Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Clan Crest Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Ally Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Ally Crest Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Siege Relation
	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Mount Type
	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Private Store Type
	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Dwarven Craft
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // PK Kills
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // PvP Kills

	Int16 nBufferSize = pOldUserInfo.ReadH(); // Cubic KeySet Buffer Size
	pNewUserInfo.WriteH(nBufferSize);
	for (Int16 i = 0; i < nBufferSize; i++)
		pNewUserInfo.WriteH(pOldUserInfo.ReadH()); // Cubic KeySet

	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Find Party Members
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Abnormal Effect
	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Unknown

	Int32 nClanPrivSize = pOldUserInfo.ReadD(); // Clan Priv Buffer Size
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Clan Privileges

	pNewUserInfo.WriteH(pOldUserInfo.ReadH()); // Rec Remaining
	pNewUserInfo.WriteH(pOldUserInfo.ReadH()); // Rec Received
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Unknown
	pNewUserInfo.WriteH(pOldUserInfo.ReadH()); // Inventory Limit
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Class Id
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Unknown (Special Effects?)
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Max CP
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Current CP
	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Enchant Effect
	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Special Circle (1 = Blue : 2 = Red)
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Clan Crest Large Id
	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Is Noblesse
	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Is Hero
	pNewUserInfo.WriteC(pOldUserInfo.ReadC()); // Fishing Mode
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Fishing X
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Fishing Y
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Fishing Z
	pNewUserInfo.WriteD(pOldUserInfo.ReadD()); // Name Color

	pNewUserInfo.WriteC(pSharedData->nMoveType); // Is Running
	pNewUserInfo.WriteD(pUser->GetPledgeClass()); // Pledge Class
	pNewUserInfo.WriteD(0); // Unknown
	//pNewUserInfo.WriteD(pSharedData->pExUserInfo->nTitleColor); // Title Color
	pNewUserInfo.WriteD(0); // Title Color
	pNewUserInfo.WriteD(pUser->GetCursedWeaponGlowLevel()); // Cursed Weapon Glow Level

	pSocket->Send("b", pNewUserInfo.GetSize(), pNewUserInfo.GetPacket());
}