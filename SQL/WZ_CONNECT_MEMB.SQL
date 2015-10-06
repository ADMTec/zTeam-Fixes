CREATE PROCEDURE WZ_CONNECT_MEMB

@uid varchar(20), @Server varchar(20),
@uip varchar(20)
AS

Begin

BEGIN TRANSACTION

SET NOCOUNT ON

IF EXISTS ( SELECT memb___id FROM MEMB_STAT WITH (READUNCOMMITTED)
WHERE memb___id = @uid )
Begin
UPDATE MEMB_STAT
SET ip = @uip , connectstat = 1 , servername = @Server , ConnectTM = (getdate())
WHERE memb___id = @uid
End
ELSE
Begin
INSERT INTO MEMB_STAT ( memb___id,ip,connectstat,servername) valueS (
@uid,
@uip,
1, @Server
)
End


IF(@@Error <> 0 )
ROLLBACK TRANSACTION
ELSE
COMMIT TRANSACTION

SET NOCOUNT OFF
End
GO
SET QUOTED_IDENTIFIER OFF
GO
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO
SET ANSI_NULLS OFF
GO