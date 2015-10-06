//fix
if(strcmp(OffTradeType, "zen") == 0 && g_OfflineTrade.EnableZen == true) // IF YOU REMOVE CHECK, THIS WILL ALWAYS BE TRUE
{
g_OfflineTrade.Start(aIndex, 0);
}
ELSE if(strcmp(OffTradeType, "wcoin") == 0 && g_OfflineTrade.EnableWCoin == true) // THIS WILL NEVER BE EXECUTED.
{
g_OfflineTrade.Start(aIndex, 1);
}
ELSE if(strcmp(OffTradeType, "soul") == 0 && g_OfflineTrade.EnableSoul == true) // NEITHER WILL THIS.
{
g_OfflineTrade.Start(aIndex, 2);
}
else
{
return FALSE;
}
