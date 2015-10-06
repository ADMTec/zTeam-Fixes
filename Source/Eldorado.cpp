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
