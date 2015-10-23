bool NpcCastleHuntZoneGuard(LPOBJ lpNpc, LPOBJ lpObj)
{
if(gObjIsConnected(lpObj->m_Index) == FALSE )
{
return TRUE;
}

if ( (lpObj->m_IfState.use ) > 0 )
{
return TRUE;
}

PMSG_ANS_GUARD_IN_CASTLE_HUNTZONE pResult = {0};

PHeadSubSetB((LPBYTE)&pResult,0xB9,0x03,sizeof(PMSG_ANS_GUARD_IN_CASTLE_HUNTZONE));
pResult.btResult = TRUE;
pResult.iMaxPrice = 300000;
pResult.iUnitOfPrice = 10000;
pResult.btUsable = 0;
pResult.iCurrentPrice = 0;

pResult.iCurrentPrice = g_CastleSiegeSync.GetTaxHuntZone(lpObj->m_Index,FALSE);

if(g_CastleSiege.GetHuntZoneEnter())
{
pResult.btUsable = TRUE;
}

if(lpObj->lpGuild != NULL)
{
if(g_CastleSiege.CheckCastleOwnerUnionMember(lpObj->m_Index))
{
pResult.btResult = 2;
}

if(g_CastleSiege.CheckCastleOwnerMember(lpObj->m_Index))
{
if(lpObj->GuildStatus == G_MASTER)
{
pResult.btResult = 3;
}
}
}
else
{
if(g_CastleSiege.GetHuntZoneEnter())
{
pResult.btResult = TRUE;
}
}

DataSend(lpObj->m_Index,(LPBYTE)&pResult,pResult.h.size);

return TRUE;
}


//////////////////////// Fix in SQL ////////////////////////////////////////
To allow members to enter the Guild Castle
You must set the Guild Member count to enter.

Here's how :
Open SQL Server Management Studio
~~> Stored Procedures
~~> WZ_CS_ReqRegAttackGuild (right on it and Modify)
Search for iGuildMemberCount 
if the count > 1 change it to 20.
and save & done.

Here's how the EasyLife :
Open up Query and execute this

//===========================================================================================================
Code:
IF (@iGuildMasterLevel < 200)
BEGIN
SELECT 5 As QueryResult    
END
ELSE
BEGIN
IF (@iGuildMemberCount < 20)
//===========================================================================================================

200 ~~> Level
20 ~~> Member count.
