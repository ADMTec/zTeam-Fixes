//Golden Invasion
//eledoradoevent.cpp

//to work it should be like this :

case 0:
strcat(szTemp, lMsg.Get(MSGGET(7, 208)));
AllSendServerMsg("Golden Dragon Invasion Lorencia !!!");
break;
case 2:
strcat(szTemp, lMsg.Get(MSGGET(7, 210)));
AllSendServerMsg("Golden Dragon Invasion Devias !!!");
break;
case 3:
strcat(szTemp, lMsg.Get(MSGGET(7, 211)));
AllSendServerMsg("Golden Dragon Invasion Noria!!!");
break;
}

strcat(szTemp, lMsg.Get(MSGGET(4, 134)));
AllSendServerMsg("Golden Dragon Invasion !!!");
}


//or this one
case 0:
strcat(szTemp, lMsg.Get(MSGGET(7, 208)));
break;
case 2:
strcat(szTemp, lMsg.Get(MSGGET(7, 210)));
break;
case 3:
strcat(szTemp, lMsg.Get(MSGGET(7, 211)));
break;
}

strcat(szTemp, lMsg.Get(MSGGET(4, 134)));
AllSendServerMsg(szTemp);
}

//search for
void CEledoradoEvent::RegenGoldDercon()
//edit
           if ( SelMap == -1 )
            {
                char szTemp[256];
                memset(szTemp, 0, sizeof(szTemp));

                switch (MapNumber)
                {
                case 0: //Lorencia
                    sprintf(szTemp, "[%s] %s", lMsg.Get(MSGGET(7, 208)), lMsg.Get(MSGGET(4, 134)));
                    break;
                case 2: //Devias
                    sprintf(szTemp, "[%s] %s", lMsg.Get(MSGGET(7, 210)), lMsg.Get(MSGGET(4, 134)));
                    break;
                case 3: //Noria
                    sprintf(szTemp, "[%s] %s", lMsg.Get(MSGGET(7, 211)), lMsg.Get(MSGGET(4, 134)));
                    break;
                }
                AllSendServerMsg(szTemp);
            }



///////////////

tarkan tantalos and atlans lizard fix.

find 
for (n=0;n<OBJ_MAXMONSTER;n++)
{
MapNumber = 7;

if ( gObj[n].Class == 80 ) // Devil Lizard King
{
gObj[n].Live = TRUE;
gObj[n].MapNumber = MapNumber;

while ( gMSetBase.GetBoxPosition(MapNumber, 50, 10, 250, 200, gObj[n].X, gObj[n].Y) == 0 )
{

}

this->m_BossDevilLizardKingMapNumber = gObj[n].MapNumber;
this->m_BossDevilLizardKingMapX = gObj[n].X;
this->m_BossDevilLizardKingMapY = gObj[n].Y;

gObj[n].Life = gObj[n].MaxLife;
replace with

for (n=0;n<OBJ_MAXMONSTER;n++)
{


if ( gObj[n].Class == 80 ) // Devil Lizard King
{
gObj[n].Live = TRUE;
MapNumber = 7;
gObj[n].MapNumber = MapNumber;

while ( gMSetBase.GetBoxPosition(MapNumber, 50, 10, 250, 200, gObj[n].X, gObj[n].Y) == 0 )
{

}

this->m_BossDevilLizardKingMapNumber = gObj[n].MapNumber;
this->m_BossDevilLizardKingMapX = gObj[n].X;
this->m_BossDevilLizardKingMapY = gObj[n].Y;

gObj[n].Life = gObj[n].MaxLife;
gObj[n].TX = gObj[n].X;
gObj[n].TY = gObj[n].Y;
gObj[n].MTX = gObj[n].X;
gObj[n].MTY = gObj[n].Y;
gObj[n].StartX = gObj[n].X;
gObj[n].StartY = gObj[n].Y;
gObj[n].m_State = 1;
gObj[n].PathCount = 0;

find

MapNumber = 8;
gObj[n].MapNumber = MapNumber;

while ( gMSetBase.GetBoxPosition(MapNumber, 50, 50, 200, 200, gObj[n].X, gObj[n].Y) == 0 )
{

}

this->m_BossKanturMapNumber = gObj[n].MapNumber;
this->m_BossKanturMapX = gObj[n].X;
this->m_BossKanturMapY = gObj[n].Y;

gObj[n].Life = gObj[n].MaxLife;
/*LogAddTD("GoldenDebug %d HP: %d", gObj[n].Class, gObj[n].Life);
gObj[n].TX = gObj[n].X;
gObj[n].TY = gObj[n].Y;
gObj[n].MTX = gObj[n].X;
gObj[n].MTY = gObj[n].Y;
gObj[n].StartX = gObj[n].X;
gObj[n].StartY = gObj[n].Y;
gObjClearBuffEffect(&gObj[n], CLEAR_TYPE_DIEREGEN);
gObj[n].m_ViewState = 0;
gObj[n].Teleport = 0;
gObj[n].m_State = 1;
gObj[n].PathCount = 0;*/
replace with 

MapNumber = 8;
gObj[n].MapNumber = MapNumber;

while ( gMSetBase.GetBoxPosition(MapNumber, 50, 50, 200, 200, gObj[n].X, gObj[n].Y) == 0 )
{

}

this->m_BossKanturMapNumber = gObj[n].MapNumber;
this->m_BossKanturMapX = gObj[n].X;
this->m_BossKanturMapY = gObj[n].Y;

gObj[n].Life = gObj[n].MaxLife;
/ /*LogAddTD("GoldenDebug %d HP: %d", gObj[n].Class, gObj[n].Life);
gObj[n].TX = gObj[n].X;
gObj[n].TY = gObj[n].Y;
gObj[n].MTX = gObj[n].X;
gObj[n].MTY = gObj[n].Y;
gObj[n].StartX = gObj[n].X;
gObj[n].StartY = gObj[n].Y;
gObjClearBuffEffect(&gObj[n], CLEAR_TYPE_DIEREGEN);
gObj[n].m_ViewState = 0;
gObj[n].Teleport = 0;
gObj[n].m_State = 1;
gObj[n].PathCount = 0;
