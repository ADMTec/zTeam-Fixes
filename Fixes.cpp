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
