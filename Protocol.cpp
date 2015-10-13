por aca les dejo un fix para el source que encontre por ahi del mail system que si te llega un mensaje relogueas y se borra


en el protocol.cpp

busquen esta funcion
Código: [Seleccionar]
FriendMemoListReq(aIndex);

y la reemplazan por esta
Código: [Seleccionar]
FriendMemoListReq((FHP_FRIEND_MEMO_LIST *)aRecv, aIndex);

en el edsprotocol.cpp y edsprotocl.h
busquen
Código: [Seleccionar]
void FriendMemoListReq(int aIndex)

y reemplazan con esto
Código: [Seleccionar]
void FriendMemoListReq(FHP_FRIEND_MEMO_LIST * lpMsg, int aIndex)

otra cosa es que a este post le hace falta es el changelog ya que estos archivos fueron liberados con sources y practicamente hay versiones diferentes en todos los foros para saber que funciona y que no.
Modificar mensaje
