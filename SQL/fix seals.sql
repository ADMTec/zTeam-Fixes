USE [MuOnline]
GO
/****** Object:  StoredProcedure [dbo].[WZ_PeriodItemInsert]    Script Date: 06/24/2014 09:31:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER Procedure [dbo].[WZ_PeriodItemInsert]

 @userGuid        int,
 @CharacterName    varchar(10),
    @ItemCode        int,
 @OptiOnType        tinyint,
 @EffectType1        tinyint,
 @EffectType2        tinyint,
 @TotalUsePeriod    int,
 @expiredate        varchar(20)
AS
BEGIN
    DECLARE @ErrorCode int
    DECLARE @periodItemIndex int

    SET @ErrorCode = 0
    SET @periodItemIndex = 0

    SET XACT_ABORT ON
    SET NOCOUNT ON

    BEGIN TRANSACTION

    SELECT  @periodItemIndex = PeriodIndex FROM T_PeriodItem_Info WHERE UserGuid = @userGuid AND CharacterName = @CharacterName AND OptionType = @OptiOnType AND UsedInfo = 1

    IF ( @periodItemIndex != 0 )
    BEGIN
        UPDATE T_PeriodItem_Info SET UsedInfo = 0 WHERE UserGuid = @userGuid AND CharacterName = @CharacterName AND OptionType = @OptiOnType AND UsedInfo = 1
    END

    INSERT INTO T_PeriodItem_Info (UserGuid, CharacterName, ItemCode, OptionType, EffectType1, EffectType2, LeftTime, BuyDate, ExpireDate, UsedInfo) VALUES
    ( @userGuid, @CharacterName, @ItemCode, @OptiOnType, @EffectType1, @EffectType2, @TotalUsePeriod, GETDATE(), CAST @expiredate AS datetime2(0)), 1 )
    IF(  @ERROR <> 0 )
    BEGIN
        SET @ErrorCode = 2
    END

    IF ( @ErrorCode  <> 0 )
        ROLLBACK TRANSACTION
    ELSE
        COMMIT TRANSACTION

    SELECT @ErrorCode

    SET NOCOUNT OFF
    SET XACT_ABORT OFF
END