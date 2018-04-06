#include "MessageUtils.h"

QString MessageUtils::getName(const MessageEnum &messageEnum)
{
  if(messageEnum == MessageEnum::ADMINCOMMANDMESSAGE)
      return "AdminCommandMessage";
  
  else if(messageEnum == MessageEnum::ADMINQUIETCOMMANDMESSAGE)
      return "AdminQuietCommandMessage";
  
  else if(messageEnum == MessageEnum::CONSOLECOMMANDSLISTMESSAGE)
      return "ConsoleCommandsListMessage";
  
  else if(messageEnum == MessageEnum::CONSOLEMESSAGE)
      return "ConsoleMessage";
  
  else if(messageEnum == MessageEnum::AGGREGATESTATMESSAGE)
      return "AggregateStatMessage";
  
  else if(messageEnum == MessageEnum::AGGREGATESTATWITHDATAMESSAGE)
      return "AggregateStatWithDataMessage";
  
  else if(messageEnum == MessageEnum::BASICPINGMESSAGE)
      return "BasicPingMessage";
  
  else if(messageEnum == MessageEnum::BASICPONGMESSAGE)
      return "BasicPongMessage";
  
  else if(messageEnum == MessageEnum::BASICSTATMESSAGE)
      return "BasicStatMessage";
  
  else if(messageEnum == MessageEnum::BASICSTATWITHDATAMESSAGE)
      return "BasicStatWithDataMessage";
  
  else if(messageEnum == MessageEnum::NETWORKDATACONTAINERMESSAGE)
      return "NetworkDataContainerMessage";
  
  else if(messageEnum == MessageEnum::CREDENTIALSACKNOWLEDGEMENTMESSAGE)
      return "CredentialsAcknowledgementMessage";
  
  else if(messageEnum == MessageEnum::HELLOCONNECTMESSAGE)
      return "HelloConnectMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONACCOUNTFORCEMESSAGE)
      return "IdentificationAccountForceMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONFAILEDBANNEDMESSAGE)
      return "IdentificationFailedBannedMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE)
      return "IdentificationFailedForBadVersionMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONFAILEDMESSAGE)
      return "IdentificationFailedMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONMESSAGE)
      return "IdentificationMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONSUCCESSMESSAGE)
      return "IdentificationSuccessMessage";
  
  else if(messageEnum == MessageEnum::IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE)
      return "IdentificationSuccessWithLoginTokenMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTLINKREQUIREDMESSAGE)
      return "AccountLinkRequiredMessage";
  
  else if(messageEnum == MessageEnum::NICKNAMEACCEPTEDMESSAGE)
      return "NicknameAcceptedMessage";
  
  else if(messageEnum == MessageEnum::NICKNAMECHOICEREQUESTMESSAGE)
      return "NicknameChoiceRequestMessage";
  
  else if(messageEnum == MessageEnum::NICKNAMEREFUSEDMESSAGE)
      return "NicknameRefusedMessage";
  
  else if(messageEnum == MessageEnum::NICKNAMEREGISTRATIONMESSAGE)
      return "NicknameRegistrationMessage";
  
  else if(messageEnum == MessageEnum::ACQUAINTANCESEARCHERRORMESSAGE)
      return "AcquaintanceSearchErrorMessage";
  
  else if(messageEnum == MessageEnum::ACQUAINTANCESEARCHMESSAGE)
      return "AcquaintanceSearchMessage";
  
  else if(messageEnum == MessageEnum::ACQUAINTANCESERVERLISTMESSAGE)
      return "AcquaintanceServerListMessage";
  
  else if(messageEnum == MessageEnum::SELECTEDSERVERDATAEXTENDEDMESSAGE)
      return "SelectedServerDataExtendedMessage";
  
  else if(messageEnum == MessageEnum::SELECTEDSERVERDATAMESSAGE)
      return "SelectedServerDataMessage";
  
  else if(messageEnum == MessageEnum::SELECTEDSERVERREFUSEDMESSAGE)
      return "SelectedServerRefusedMessage";
  
  else if(messageEnum == MessageEnum::SERVERSELECTIONMESSAGE)
      return "ServerSelectionMessage";
  
  else if(messageEnum == MessageEnum::SERVERSLISTMESSAGE)
      return "ServersListMessage";
  
  else if(messageEnum == MessageEnum::SERVERSTATUSUPDATEMESSAGE)
      return "ServerStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::DEBUGCLEARHIGHLIGHTCELLSMESSAGE)
      return "DebugClearHighlightCellsMessage";
  
  else if(messageEnum == MessageEnum::DEBUGHIGHLIGHTCELLSMESSAGE)
      return "DebugHighlightCellsMessage";
  
  else if(messageEnum == MessageEnum::DEBUGINCLIENTMESSAGE)
      return "DebugInClientMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTDETAILEDLISTMESSAGE)
      return "AchievementDetailedListMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE)
      return "AchievementDetailedListRequestMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTDETAILSMESSAGE)
      return "AchievementDetailsMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTDETAILSREQUESTMESSAGE)
      return "AchievementDetailsRequestMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTFINISHEDINFORMATIONMESSAGE)
      return "AchievementFinishedInformationMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTFINISHEDMESSAGE)
      return "AchievementFinishedMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTLISTMESSAGE)
      return "AchievementListMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTREWARDERRORMESSAGE)
      return "AchievementRewardErrorMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTREWARDREQUESTMESSAGE)
      return "AchievementRewardRequestMessage";
  
  else if(messageEnum == MessageEnum::ACHIEVEMENTREWARDSUCCESSMESSAGE)
      return "AchievementRewardSuccessMessage";
  
  else if(messageEnum == MessageEnum::FRIENDGUILDSETWARNONACHIEVEMENTCOMPLETEMESSAGE)
      return "FriendGuildSetWarnOnAchievementCompleteMessage";
  
  else if(messageEnum == MessageEnum::FRIENDGUILDWARNONACHIEVEMENTCOMPLETESTATEMESSAGE)
      return "FriendGuildWarnOnAchievementCompleteStateMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTGAMEACTIONMESSAGE)
      return "AbstractGameActionMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTGAMEACTIONWITHACKMESSAGE)
      return "AbstractGameActionWithAckMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE)
      return "AbstractGameActionFightTargetedAbilityMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE)
      return "GameActionFightActivateGlyphTrapMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCARRYCHARACTERMESSAGE)
      return "GameActionFightCarryCharacterMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE)
      return "GameActionFightCastOnTargetRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCASTREQUESTMESSAGE)
      return "GameActionFightCastRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCHANGELOOKMESSAGE)
      return "GameActionFightChangeLookMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTCLOSECOMBATMESSAGE)
      return "GameActionFightCloseCombatMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDEATHMESSAGE)
      return "GameActionFightDeathMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE)
      return "GameActionFightDispellableEffectMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDISPELLEFFECTMESSAGE)
      return "GameActionFightDispellEffectMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDISPELLMESSAGE)
      return "GameActionFightDispellMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDISPELLSPELLMESSAGE)
      return "GameActionFightDispellSpellMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDODGEPOINTLOSSMESSAGE)
      return "GameActionFightDodgePointLossMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTDROPCHARACTERMESSAGE)
      return "GameActionFightDropCharacterMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTEXCHANGEPOSITIONSMESSAGE)
      return "GameActionFightExchangePositionsMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTINVISIBILITYMESSAGE)
      return "GameActionFightInvisibilityMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTINVISIBLEDETECTEDMESSAGE)
      return "GameActionFightInvisibleDetectedMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTKILLMESSAGE)
      return "GameActionFightKillMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTLIFEANDSHIELDPOINTSLOSTMESSAGE)
      return "GameActionFightLifeAndShieldPointsLostMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTLIFEPOINTSGAINMESSAGE)
      return "GameActionFightLifePointsGainMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTLIFEPOINTSLOSTMESSAGE)
      return "GameActionFightLifePointsLostMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTMARKCELLSMESSAGE)
      return "GameActionFightMarkCellsMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE)
      return "GameActionFightModifyEffectsDurationMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTNOSPELLCASTMESSAGE)
      return "GameActionFightNoSpellCastMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE)
      return "GameActionFightPointsVariationMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTREDUCEDAMAGESMESSAGE)
      return "GameActionFightReduceDamagesMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTREFLECTDAMAGESMESSAGE)
      return "GameActionFightReflectDamagesMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTREFLECTSPELLMESSAGE)
      return "GameActionFightReflectSpellMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSLIDEMESSAGE)
      return "GameActionFightSlideMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSPELLCASTMESSAGE)
      return "GameActionFightSpellCastMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE)
      return "GameActionFightSpellCooldownVariationMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE)
      return "GameActionFightSpellImmunityMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSTEALKAMAMESSAGE)
      return "GameActionFightStealKamaMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTSUMMONMESSAGE)
      return "GameActionFightSummonMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTACKLEDMESSAGE)
      return "GameActionFightTackledMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE)
      return "GameActionFightTeleportOnSameMapMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTHROWCHARACTERMESSAGE)
      return "GameActionFightThrowCharacterMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE)
      return "GameActionFightTriggerEffectMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE)
      return "GameActionFightTriggerGlyphTrapMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTUNMARKCELLSMESSAGE)
      return "GameActionFightUnmarkCellsMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONFIGHTVANISHMESSAGE)
      return "GameActionFightVanishMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONACKNOWLEDGEMENTMESSAGE)
      return "GameActionAcknowledgementMessage";
  
  else if(messageEnum == MessageEnum::GAMEACTIONNOOPMESSAGE)
      return "GameActionNoopMessage";
  
  else if(messageEnum == MessageEnum::SEQUENCEENDMESSAGE)
      return "SequenceEndMessage";
  
  else if(messageEnum == MessageEnum::SEQUENCESTARTMESSAGE)
      return "SequenceStartMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEBULLETINMESSAGE)
      return "AllianceBulletinMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEBULLETINSETERRORMESSAGE)
      return "AllianceBulletinSetErrorMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEBULLETINSETREQUESTMESSAGE)
      return "AllianceBulletinSetRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCECHANGEGUILDRIGHTSMESSAGE)
      return "AllianceChangeGuildRightsMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCECREATIONRESULTMESSAGE)
      return "AllianceCreationResultMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCECREATIONSTARTEDMESSAGE)
      return "AllianceCreationStartedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCECREATIONVALIDMESSAGE)
      return "AllianceCreationValidMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFACTSERRORMESSAGE)
      return "AllianceFactsErrorMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFACTSMESSAGE)
      return "AllianceFactsMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEFACTSREQUESTMESSAGE)
      return "AllianceFactsRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEGUILDLEAVINGMESSAGE)
      return "AllianceGuildLeavingMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINSIDERINFOMESSAGE)
      return "AllianceInsiderInfoMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINSIDERINFOREQUESTMESSAGE)
      return "AllianceInsiderInfoRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITATIONANSWERMESSAGE)
      return "AllianceInvitationAnswerMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITATIONMESSAGE)
      return "AllianceInvitationMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITATIONSTATERECRUTEDMESSAGE)
      return "AllianceInvitationStateRecrutedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITATIONSTATERECRUTERMESSAGE)
      return "AllianceInvitationStateRecruterMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEINVITEDMESSAGE)
      return "AllianceInvitedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEJOINEDMESSAGE)
      return "AllianceJoinedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEKICKREQUESTMESSAGE)
      return "AllianceKickRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCELEFTMESSAGE)
      return "AllianceLeftMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCELISTMESSAGE)
      return "AllianceListMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMEMBERSHIPMESSAGE)
      return "AllianceMembershipMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE)
      return "AllianceModificationEmblemValidMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE)
      return "AllianceModificationNameAndTagValidMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMODIFICATIONSTARTEDMESSAGE)
      return "AllianceModificationStartedMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMODIFICATIONVALIDMESSAGE)
      return "AllianceModificationValidMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMOTDMESSAGE)
      return "AllianceMotdMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMOTDSETERRORMESSAGE)
      return "AllianceMotdSetErrorMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEMOTDSETREQUESTMESSAGE)
      return "AllianceMotdSetRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEPARTIALLISTMESSAGE)
      return "AlliancePartialListMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEVERSATILEINFOLISTMESSAGE)
      return "AllianceVersatileInfoListMessage";
  
  else if(messageEnum == MessageEnum::KOHUPDATEMESSAGE)
      return "KohUpdateMessage";
  
  else if(messageEnum == MessageEnum::ALMANACHCALENDARDATEMESSAGE)
      return "AlmanachCalendarDateMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTCAPABILITIESMESSAGE)
      return "AccountCapabilitiesMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTLOGGINGKICKEDMESSAGE)
      return "AccountLoggingKickedMessage";
  
  else if(messageEnum == MessageEnum::ALREADYCONNECTEDMESSAGE)
      return "AlreadyConnectedMessage";
  
  else if(messageEnum == MessageEnum::AUTHENTICATIONTICKETACCEPTEDMESSAGE)
      return "AuthenticationTicketAcceptedMessage";
  
  else if(messageEnum == MessageEnum::AUTHENTICATIONTICKETMESSAGE)
      return "AuthenticationTicketMessage";
  
  else if(messageEnum == MessageEnum::AUTHENTICATIONTICKETREFUSEDMESSAGE)
      return "AuthenticationTicketRefusedMessage";
  
  else if(messageEnum == MessageEnum::HELLOGAMEMESSAGE)
      return "HelloGameMessage";
  
  else if(messageEnum == MessageEnum::RELOGINTOKENREQUESTMESSAGE)
      return "ReloginTokenRequestMessage";
  
  else if(messageEnum == MessageEnum::RELOGINTOKENSTATUSMESSAGE)
      return "ReloginTokenStatusMessage";
  
  else if(messageEnum == MessageEnum::SERVEROPTIONALFEATURESMESSAGE)
      return "ServerOptionalFeaturesMessage";
  
  else if(messageEnum == MessageEnum::SERVERSESSIONCONSTANTSMESSAGE)
      return "ServerSessionConstantsMessage";
  
  else if(messageEnum == MessageEnum::SERVERSETTINGSMESSAGE)
      return "ServerSettingsMessage";
  
  else if(messageEnum == MessageEnum::ATLASPOINTINFORMATIONSMESSAGE)
      return "AtlasPointInformationsMessage";
  
  else if(messageEnum == MessageEnum::COMPASSRESETMESSAGE)
      return "CompassResetMessage";
  
  else if(messageEnum == MessageEnum::COMPASSUPDATEMESSAGE)
      return "CompassUpdateMessage";
  
  else if(messageEnum == MessageEnum::COMPASSUPDATEPARTYMEMBERMESSAGE)
      return "CompassUpdatePartyMemberMessage";
  
  else if(messageEnum == MessageEnum::COMPASSUPDATEPVPSEEKMESSAGE)
      return "CompassUpdatePvpSeekMessage";
  
  else if(messageEnum == MessageEnum::BASICACKMESSAGE)
      return "BasicAckMessage";
  
  else if(messageEnum == MessageEnum::BASICDATEMESSAGE)
      return "BasicDateMessage";
  
  else if(messageEnum == MessageEnum::BASICLATENCYSTATSMESSAGE)
      return "BasicLatencyStatsMessage";
  
  else if(messageEnum == MessageEnum::BASICLATENCYSTATSREQUESTMESSAGE)
      return "BasicLatencyStatsRequestMessage";
  
  else if(messageEnum == MessageEnum::BASICNOOPERATIONMESSAGE)
      return "BasicNoOperationMessage";
  
  else if(messageEnum == MessageEnum::BASICTIMEMESSAGE)
      return "BasicTimeMessage";
  
  else if(messageEnum == MessageEnum::BASICWHOAMIREQUESTMESSAGE)
      return "BasicWhoAmIRequestMessage";
  
  else if(messageEnum == MessageEnum::BASICWHOISMESSAGE)
      return "BasicWhoIsMessage";
  
  else if(messageEnum == MessageEnum::BASICWHOISNOMATCHMESSAGE)
      return "BasicWhoIsNoMatchMessage";
  
  else if(messageEnum == MessageEnum::BASICWHOISREQUESTMESSAGE)
      return "BasicWhoIsRequestMessage";
  
  else if(messageEnum == MessageEnum::CURRENTSERVERSTATUSUPDATEMESSAGE)
      return "CurrentServerStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::NUMERICWHOISMESSAGE)
      return "NumericWhoIsMessage";
  
  else if(messageEnum == MessageEnum::NUMERICWHOISREQUESTMESSAGE)
      return "NumericWhoIsRequestMessage";
  
  else if(messageEnum == MessageEnum::SEQUENCENUMBERMESSAGE)
      return "SequenceNumberMessage";
  
  else if(messageEnum == MessageEnum::SEQUENCENUMBERREQUESTMESSAGE)
      return "SequenceNumberRequestMessage";
  
  else if(messageEnum == MessageEnum::TEXTINFORMATIONMESSAGE)
      return "TextInformationMessage";
  
  else if(messageEnum == MessageEnum::BASICCHARACTERSLISTMESSAGE)
      return "BasicCharactersListMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERFIRSTSELECTIONMESSAGE)
      return "CharacterFirstSelectionMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERREPLAYWITHREMODELREQUESTMESSAGE)
      return "CharacterReplayWithRemodelRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTEDERRORMESSAGE)
      return "CharacterSelectedErrorMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTEDFORCEMESSAGE)
      return "CharacterSelectedForceMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTEDFORCEREADYMESSAGE)
      return "CharacterSelectedForceReadyMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTEDSUCCESSMESSAGE)
      return "CharacterSelectedSuccessMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTIONMESSAGE)
      return "CharacterSelectionMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSELECTIONWITHREMODELMESSAGE)
      return "CharacterSelectionWithRemodelMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSLISTERRORMESSAGE)
      return "CharactersListErrorMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSLISTMESSAGE)
      return "CharactersListMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSLISTREQUESTMESSAGE)
      return "CharactersListRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSLISTWITHMODIFICATIONSMESSAGE)
      return "CharactersListWithModificationsMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSLISTWITHREMODELINGMESSAGE)
      return "CharactersListWithRemodelingMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERCREATIONREQUESTMESSAGE)
      return "CharacterCreationRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERCREATIONRESULTMESSAGE)
      return "CharacterCreationResultMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERNAMESUGGESTIONFAILUREMESSAGE)
      return "CharacterNameSuggestionFailureMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERNAMESUGGESTIONREQUESTMESSAGE)
      return "CharacterNameSuggestionRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERNAMESUGGESTIONSUCCESSMESSAGE)
      return "CharacterNameSuggestionSuccessMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERDELETIONERRORMESSAGE)
      return "CharacterDeletionErrorMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERDELETIONREQUESTMESSAGE)
      return "CharacterDeletionRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERREPLAYREQUESTMESSAGE)
      return "CharacterReplayRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTEREXPERIENCEGAINMESSAGE)
      return "CharacterExperienceGainMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERLEVELUPINFORMATIONMESSAGE)
      return "CharacterLevelUpInformationMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERLEVELUPMESSAGE)
      return "CharacterLevelUpMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERSTATSLISTMESSAGE)
      return "CharacterStatsListMessage";
  
  else if(messageEnum == MessageEnum::FIGHTERSTATSLISTMESSAGE)
      return "FighterStatsListMessage";
  
  else if(messageEnum == MessageEnum::LIFEPOINTSREGENBEGINMESSAGE)
      return "LifePointsRegenBeginMessage";
  
  else if(messageEnum == MessageEnum::LIFEPOINTSREGENENDMESSAGE)
      return "LifePointsRegenEndMessage";
  
  else if(messageEnum == MessageEnum::UPDATELIFEPOINTSMESSAGE)
      return "UpdateLifePointsMessage";
  
  else if(messageEnum == MessageEnum::PLAYERSTATUSUPDATEERRORMESSAGE)
      return "PlayerStatusUpdateErrorMessage";
  
  else if(messageEnum == MessageEnum::PLAYERSTATUSUPDATEMESSAGE)
      return "PlayerStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::PLAYERSTATUSUPDATEREQUESTMESSAGE)
      return "PlayerStatusUpdateRequestMessage";
  
  else if(messageEnum == MessageEnum::CHANNELENABLINGCHANGEMESSAGE)
      return "ChannelEnablingChangeMessage";
  
  else if(messageEnum == MessageEnum::CHANNELENABLINGMESSAGE)
      return "ChannelEnablingMessage";
  
  else if(messageEnum == MessageEnum::ENABLEDCHANNELSMESSAGE)
      return "EnabledChannelsMessage";
  
  else if(messageEnum == MessageEnum::CHATABSTRACTCLIENTMESSAGE)
      return "ChatAbstractClientMessage";
  
  else if(messageEnum == MessageEnum::CHATABSTRACTSERVERMESSAGE)
      return "ChatAbstractServerMessage";
  
  else if(messageEnum == MessageEnum::CHATADMINSERVERMESSAGE)
      return "ChatAdminServerMessage";
  
  else if(messageEnum == MessageEnum::CHATCLIENTMULTIMESSAGE)
      return "ChatClientMultiMessage";
  
  else if(messageEnum == MessageEnum::CHATCLIENTMULTIWITHOBJECTMESSAGE)
      return "ChatClientMultiWithObjectMessage";
  
  else if(messageEnum == MessageEnum::CHATCLIENTPRIVATEMESSAGE)
      return "ChatClientPrivateMessage";
  
  else if(messageEnum == MessageEnum::CHATCLIENTPRIVATEWITHOBJECTMESSAGE)
      return "ChatClientPrivateWithObjectMessage";
  
  else if(messageEnum == MessageEnum::CHATERRORMESSAGE)
      return "ChatErrorMessage";
  
  else if(messageEnum == MessageEnum::CHATSERVERCOPYMESSAGE)
      return "ChatServerCopyMessage";
  
  else if(messageEnum == MessageEnum::CHATSERVERCOPYWITHOBJECTMESSAGE)
      return "ChatServerCopyWithObjectMessage";
  
  else if(messageEnum == MessageEnum::CHATSERVERMESSAGE)
      return "ChatServerMessage";
  
  else if(messageEnum == MessageEnum::CHATSERVERWITHOBJECTMESSAGE)
      return "ChatServerWithObjectMessage";
  
  else if(messageEnum == MessageEnum::CHATMESSAGEREPORTMESSAGE)
      return "ChatMessageReportMessage";
  
  else if(messageEnum == MessageEnum::CHATSMILEYEXTRAPACKLISTMESSAGE)
      return "ChatSmileyExtraPackListMessage";
  
  else if(messageEnum == MessageEnum::CHATSMILEYMESSAGE)
      return "ChatSmileyMessage";
  
  else if(messageEnum == MessageEnum::CHATSMILEYREQUESTMESSAGE)
      return "ChatSmileyRequestMessage";
  
  else if(messageEnum == MessageEnum::LOCALIZEDCHATSMILEYMESSAGE)
      return "LocalizedChatSmileyMessage";
  
  else if(messageEnum == MessageEnum::MOODSMILEYREQUESTMESSAGE)
      return "MoodSmileyRequestMessage";
  
  else if(messageEnum == MessageEnum::MOODSMILEYRESULTMESSAGE)
      return "MoodSmileyResultMessage";
  
  else if(messageEnum == MessageEnum::MOODSMILEYUPDATEMESSAGE)
      return "MoodSmileyUpdateMessage";
  
  else if(messageEnum == MessageEnum::DISPLAYNUMERICALVALUEPADDOCKMESSAGE)
      return "DisplayNumericalValuePaddockMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONKEYRINGMESSAGE)
      return "DungeonKeyRingMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONKEYRINGUPDATEMESSAGE)
      return "DungeonKeyRingUpdateMessage";
  
  else if(messageEnum == MessageEnum::ARENAFIGHTERLEAVEMESSAGE)
      return "ArenaFighterLeaveMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEINFOMESSAGE)
      return "ChallengeInfoMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGERESULTMESSAGE)
      return "ChallengeResultMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGETARGETSLISTMESSAGE)
      return "ChallengeTargetsListMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGETARGETSLISTREQUESTMESSAGE)
      return "ChallengeTargetsListRequestMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGETARGETUPDATEMESSAGE)
      return "ChallengeTargetUpdateMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTREFRESHFIGHTERMESSAGE)
      return "GameFightRefreshFighterMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSHOWFIGHTERMESSAGE)
      return "GameFightShowFighterMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE)
      return "GameFightShowFighterRandomStaticPoseMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTENDMESSAGE)
      return "GameFightEndMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTHUMANREADYSTATEMESSAGE)
      return "GameFightHumanReadyStateMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTJOINMESSAGE)
      return "GameFightJoinMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTJOINREQUESTMESSAGE)
      return "GameFightJoinRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTLEAVEMESSAGE)
      return "GameFightLeaveMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTNEWROUNDMESSAGE)
      return "GameFightNewRoundMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTNEWWAVEMESSAGE)
      return "GameFightNewWaveMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTOPTIONSTATEUPDATEMESSAGE)
      return "GameFightOptionStateUpdateMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTOPTIONTOGGLEMESSAGE)
      return "GameFightOptionToggleMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE)
      return "GameFightPlacementPositionRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE)
      return "GameFightPlacementPossiblePositionsMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSACCEPTMESSAGE)
      return "GameFightPlacementSwapPositionsAcceptMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELLEDMESSAGE)
      return "GameFightPlacementSwapPositionsCancelledMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSCANCELMESSAGE)
      return "GameFightPlacementSwapPositionsCancelMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSERRORMESSAGE)
      return "GameFightPlacementSwapPositionsErrorMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE)
      return "GameFightPlacementSwapPositionsMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSOFFERMESSAGE)
      return "GameFightPlacementSwapPositionsOfferMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSREQUESTMESSAGE)
      return "GameFightPlacementSwapPositionsRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTREADYMESSAGE)
      return "GameFightReadyMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTREMOVETEAMMEMBERMESSAGE)
      return "GameFightRemoveTeamMemberMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTRESUMEMESSAGE)
      return "GameFightResumeMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTRESUMEWITHSLAVESMESSAGE)
      return "GameFightResumeWithSlavesMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSPECTATEMESSAGE)
      return "GameFightSpectateMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE)
      return "GameFightSpectatePlayerRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSPECTATORJOINMESSAGE)
      return "GameFightSpectatorJoinMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSTARTINGMESSAGE)
      return "GameFightStartingMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSTARTMESSAGE)
      return "GameFightStartMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTSYNCHRONIZEMESSAGE)
      return "GameFightSynchronizeMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNENDMESSAGE)
      return "GameFightTurnEndMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNFINISHMESSAGE)
      return "GameFightTurnFinishMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNLISTMESSAGE)
      return "GameFightTurnListMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNREADYMESSAGE)
      return "GameFightTurnReadyMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNREADYREQUESTMESSAGE)
      return "GameFightTurnReadyRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNRESUMEMESSAGE)
      return "GameFightTurnResumeMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNSTARTMESSAGE)
      return "GameFightTurnStartMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTTURNSTARTPLAYINGMESSAGE)
      return "GameFightTurnStartPlayingMessage";
  
  else if(messageEnum == MessageEnum::GAMEFIGHTUPDATETEAMMESSAGE)
      return "GameFightUpdateTeamMessage";
  
  else if(messageEnum == MessageEnum::REFRESHCHARACTERSTATSMESSAGE)
      return "RefreshCharacterStatsMessage";
  
  else if(messageEnum == MessageEnum::SLAVESWITCHCONTEXTMESSAGE)
      return "SlaveSwitchContextMessage";
  
  else if(messageEnum == MessageEnum::GAMECAUTIOUSMAPMOVEMENTMESSAGE)
      return "GameCautiousMapMovementMessage";
  
  else if(messageEnum == MessageEnum::GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE)
      return "GameCautiousMapMovementRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTCREATEERRORMESSAGE)
      return "GameContextCreateErrorMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTCREATEMESSAGE)
      return "GameContextCreateMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTCREATEREQUESTMESSAGE)
      return "GameContextCreateRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTDESTROYMESSAGE)
      return "GameContextDestroyMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTKICKMESSAGE)
      return "GameContextKickMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTMOVEELEMENTMESSAGE)
      return "GameContextMoveElementMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE)
      return "GameContextMoveMultipleElementsMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTQUITMESSAGE)
      return "GameContextQuitMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREADYMESSAGE)
      return "GameContextReadyMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREFRESHENTITYLOOKMESSAGE)
      return "GameContextRefreshEntityLookMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREMOVEELEMENTMESSAGE)
      return "GameContextRemoveElementMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE)
      return "GameContextRemoveElementWithEventMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE)
      return "GameContextRemoveMultipleElementsMessage";
  
  else if(messageEnum == MessageEnum::GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE)
      return "GameContextRemoveMultipleElementsWithEventsMessage";
  
  else if(messageEnum == MessageEnum::GAMEENTITIESDISPOSITIONMESSAGE)
      return "GameEntitiesDispositionMessage";
  
  else if(messageEnum == MessageEnum::GAMEENTITYDISPOSITIONERRORMESSAGE)
      return "GameEntityDispositionErrorMessage";
  
  else if(messageEnum == MessageEnum::GAMEENTITYDISPOSITIONMESSAGE)
      return "GameEntityDispositionMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPCHANGEORIENTATIONMESSAGE)
      return "GameMapChangeOrientationMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE)
      return "GameMapChangeOrientationRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPCHANGEORIENTATIONSMESSAGE)
      return "GameMapChangeOrientationsMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPMOVEMENTCANCELMESSAGE)
      return "GameMapMovementCancelMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPMOVEMENTCONFIRMMESSAGE)
      return "GameMapMovementConfirmMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPMOVEMENTMESSAGE)
      return "GameMapMovementMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPMOVEMENTREQUESTMESSAGE)
      return "GameMapMovementRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEMAPNOMOVEMENTMESSAGE)
      return "GameMapNoMovementMessage";
  
  else if(messageEnum == MessageEnum::GAMEREFRESHMONSTERBOOSTSMESSAGE)
      return "GameRefreshMonsterBoostsMessage";
  
  else if(messageEnum == MessageEnum::GAMEDATAPADDOCKOBJECTADDMESSAGE)
      return "GameDataPaddockObjectAddMessage";
  
  else if(messageEnum == MessageEnum::GAMEDATAPADDOCKOBJECTLISTADDMESSAGE)
      return "GameDataPaddockObjectListAddMessage";
  
  else if(messageEnum == MessageEnum::GAMEDATAPADDOCKOBJECTREMOVEMESSAGE)
      return "GameDataPaddockObjectRemoveMessage";
  
  else if(messageEnum == MessageEnum::MOUNTDATAERRORMESSAGE)
      return "MountDataErrorMessage";
  
  else if(messageEnum == MessageEnum::MOUNTDATAMESSAGE)
      return "MountDataMessage";
  
  else if(messageEnum == MessageEnum::MOUNTEMOTEICONUSEDOKMESSAGE)
      return "MountEmoteIconUsedOkMessage";
  
  else if(messageEnum == MessageEnum::MOUNTEQUIPEDERRORMESSAGE)
      return "MountEquipedErrorMessage";
  
  else if(messageEnum == MessageEnum::MOUNTFEEDREQUESTMESSAGE)
      return "MountFeedRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE)
      return "MountHarnessColorsUpdateRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTHARNESSDISSOCIATEREQUESTMESSAGE)
      return "MountHarnessDissociateRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTINFORMATIONINPADDOCKREQUESTMESSAGE)
      return "MountInformationInPaddockRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTINFORMATIONREQUESTMESSAGE)
      return "MountInformationRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRELEASEDMESSAGE)
      return "MountReleasedMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRELEASEREQUESTMESSAGE)
      return "MountReleaseRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRENAMEDMESSAGE)
      return "MountRenamedMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRENAMEREQUESTMESSAGE)
      return "MountRenameRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTRIDINGMESSAGE)
      return "MountRidingMessage";
  
  else if(messageEnum == MessageEnum::MOUNTSETMESSAGE)
      return "MountSetMessage";
  
  else if(messageEnum == MessageEnum::MOUNTSETXPRATIOREQUESTMESSAGE)
      return "MountSetXpRatioRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTSTERILIZEDMESSAGE)
      return "MountSterilizedMessage";
  
  else if(messageEnum == MessageEnum::MOUNTSTERILIZEREQUESTMESSAGE)
      return "MountSterilizeRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTTOGGLERIDINGREQUESTMESSAGE)
      return "MountToggleRidingRequestMessage";
  
  else if(messageEnum == MessageEnum::MOUNTUNSETMESSAGE)
      return "MountUnSetMessage";
  
  else if(messageEnum == MessageEnum::MOUNTXPRATIOMESSAGE)
      return "MountXpRatioMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKBUYREQUESTMESSAGE)
      return "PaddockBuyRequestMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKBUYRESULTMESSAGE)
      return "PaddockBuyResultMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKMOVEITEMREQUESTMESSAGE)
      return "PaddockMoveItemRequestMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKREMOVEITEMREQUESTMESSAGE)
      return "PaddockRemoveItemRequestMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKSELLREQUESTMESSAGE)
      return "PaddockSellRequestMessage";
  
  else if(messageEnum == MessageEnum::NOTIFICATIONBYSERVERMESSAGE)
      return "NotificationByServerMessage";
  
  else if(messageEnum == MessageEnum::NOTIFICATIONLISTMESSAGE)
      return "NotificationListMessage";
  
  else if(messageEnum == MessageEnum::NOTIFICATIONRESETMESSAGE)
      return "NotificationResetMessage";
  
  else if(messageEnum == MessageEnum::NOTIFICATIONUPDATEFLAGMESSAGE)
      return "NotificationUpdateFlagMessage";
  
  else if(messageEnum == MessageEnum::CHANGEMAPMESSAGE)
      return "ChangeMapMessage";
  
  else if(messageEnum == MessageEnum::CURRENTMAPMESSAGE)
      return "CurrentMapMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYFREESOULREQUESTMESSAGE)
      return "GameRolePlayFreeSoulRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYGAMEOVERMESSAGE)
      return "GameRolePlayGameOverMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE)
      return "GameRolePlayPlayerLifeStatusMessage";
  
  else if(messageEnum == MessageEnum::WARNONPERMADEATHMESSAGE)
      return "WarnOnPermaDeathMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYDELAYEDACTIONFINISHEDMESSAGE)
      return "GameRolePlayDelayedActionFinishedMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYDELAYEDACTIONMESSAGE)
      return "GameRolePlayDelayedActionMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYDELAYEDOBJECTUSEMESSAGE)
      return "GameRolePlayDelayedObjectUseMessage";
  
  else if(messageEnum == MessageEnum::COMICREADINGBEGINMESSAGE)
      return "ComicReadingBeginMessage";
  
  else if(messageEnum == MessageEnum::DOCUMENTREADINGBEGINMESSAGE)
      return "DocumentReadingBeginMessage";
  
  else if(messageEnum == MessageEnum::EMOTEADDMESSAGE)
      return "EmoteAddMessage";
  
  else if(messageEnum == MessageEnum::EMOTELISTMESSAGE)
      return "EmoteListMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYABSTRACTMESSAGE)
      return "EmotePlayAbstractMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYERRORMESSAGE)
      return "EmotePlayErrorMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYMASSIVEMESSAGE)
      return "EmotePlayMassiveMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYMESSAGE)
      return "EmotePlayMessage";
  
  else if(messageEnum == MessageEnum::EMOTEPLAYREQUESTMESSAGE)
      return "EmotePlayRequestMessage";
  
  else if(messageEnum == MessageEnum::EMOTEREMOVEMESSAGE)
      return "EmoteRemoveMessage";
  
  else if(messageEnum == MessageEnum::ERRORMAPNOTFOUNDMESSAGE)
      return "ErrorMapNotFoundMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAFIGHTANSWERMESSAGE)
      return "GameRolePlayArenaFightAnswerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAFIGHTERSTATUSMESSAGE)
      return "GameRolePlayArenaFighterStatusMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAFIGHTPROPOSITIONMESSAGE)
      return "GameRolePlayArenaFightPropositionMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAREGISTERMESSAGE)
      return "GameRolePlayArenaRegisterMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE)
      return "GameRolePlayArenaRegistrationStatusMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE)
      return "GameRolePlayArenaSwitchToFightServerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE)
      return "GameRolePlayArenaSwitchToGameServerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAUNREGISTERMESSAGE)
      return "GameRolePlayArenaUnregisterMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSMESSAGE)
      return "GameRolePlayArenaUpdatePlayerInfosMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYARENAUPDATEPLAYERINFOSWITHTEAMMESSAGE)
      return "GameRolePlayArenaUpdatePlayerInfosWithTeamMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYAGGRESSIONMESSAGE)
      return "GameRolePlayAggressionMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE)
      return "GameRolePlayAttackMonsterRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE)
      return "GameRolePlayFightRequestCanceledMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWEREDMESSAGE)
      return "GameRolePlayPlayerFightFriendlyAnsweredMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYANSWERMESSAGE)
      return "GameRolePlayPlayerFightFriendlyAnswerMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERFIGHTFRIENDLYREQUESTEDMESSAGE)
      return "GameRolePlayPlayerFightFriendlyRequestedMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE)
      return "GameRolePlayPlayerFightRequestMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYREMOVECHALLENGEMESSAGE)
      return "GameRolePlayRemoveChallengeMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYSHOWCHALLENGEMESSAGE)
      return "GameRolePlayShowChallengeMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYSHOWACTORMESSAGE)
      return "GameRolePlayShowActorMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE)
      return "GameRolePlayShowActorWithEventMessage";
  
  else if(messageEnum == MessageEnum::CHANGEHAVENBAGROOMREQUESTMESSAGE)
      return "ChangeHavenBagRoomRequestMessage";
  
  else if(messageEnum == MessageEnum::CHANGETHEMEREQUESTMESSAGE)
      return "ChangeThemeRequestMessage";
  
  else if(messageEnum == MessageEnum::CLOSEHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE)
      return "CloseHavenBagFurnitureSequenceRequestMessage";
  
  else if(messageEnum == MessageEnum::EDITHAVENBAGCANCELREQUESTMESSAGE)
      return "EditHavenBagCancelRequestMessage";
  
  else if(messageEnum == MessageEnum::EDITHAVENBAGFINISHEDMESSAGE)
      return "EditHavenBagFinishedMessage";
  
  else if(messageEnum == MessageEnum::EDITHAVENBAGREQUESTMESSAGE)
      return "EditHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::EDITHAVENBAGSTARTMESSAGE)
      return "EditHavenBagStartMessage";
  
  else if(messageEnum == MessageEnum::ENTERHAVENBAGREQUESTMESSAGE)
      return "EnterHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::EXITHAVENBAGREQUESTMESSAGE)
      return "ExitHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGDAILYLOTERYMESSAGE)
      return "HavenBagDailyLoteryMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGFURNITURESMESSAGE)
      return "HavenBagFurnituresMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGFURNITURESREQUESTMESSAGE)
      return "HavenBagFurnituresRequestMessage";
  
  else if(messageEnum == MessageEnum::HAVENBAGPACKLISTMESSAGE)
      return "HavenBagPackListMessage";
  
  else if(messageEnum == MessageEnum::KICKHAVENBAGREQUESTMESSAGE)
      return "KickHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::INVITEINHAVENBAGCLOSEDMESSAGE)
      return "InviteInHavenBagClosedMessage";
  
  else if(messageEnum == MessageEnum::INVITEINHAVENBAGMESSAGE)
      return "InviteInHavenBagMessage";
  
  else if(messageEnum == MessageEnum::INVITEINHAVENBAGOFFERMESSAGE)
      return "InviteInHavenBagOfferMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTHAVENBAGANSWERMESSAGE)
      return "TeleportHavenBagAnswerMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTHAVENBAGREQUESTMESSAGE)
      return "TeleportHavenBagRequestMessage";
  
  else if(messageEnum == MessageEnum::OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE)
      return "OpenHavenBagFurnitureSequenceRequestMessage";
  
  else if(messageEnum == MessageEnum::ROOMAVAILABLEUPDATEMESSAGE)
      return "RoomAvailableUpdateMessage";
  
  else if(messageEnum == MessageEnum::ACCOUNTHOUSEMESSAGE)
      return "AccountHouseMessage";
  
  else if(messageEnum == MessageEnum::HOUSEGUILDNONEMESSAGE)
      return "HouseGuildNoneMessage";
  
  else if(messageEnum == MessageEnum::HOUSEGUILDRIGHTSMESSAGE)
      return "HouseGuildRightsMessage";
  
  else if(messageEnum == MessageEnum::HOUSEGUILDRIGHTSVIEWMESSAGE)
      return "HouseGuildRightsViewMessage";
  
  else if(messageEnum == MessageEnum::HOUSEGUILDSHAREREQUESTMESSAGE)
      return "HouseGuildShareRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSEBUYREQUESTMESSAGE)
      return "HouseBuyRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSEBUYRESULTMESSAGE)
      return "HouseBuyResultMessage";
  
  else if(messageEnum == MessageEnum::HOUSEKICKINDOORMERCHANTREQUESTMESSAGE)
      return "HouseKickIndoorMerchantRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSEKICKREQUESTMESSAGE)
      return "HouseKickRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSELOCKFROMINSIDEREQUESTMESSAGE)
      return "HouseLockFromInsideRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSEPROPERTIESMESSAGE)
      return "HousePropertiesMessage";
  
  else if(messageEnum == MessageEnum::HOUSESELLFROMINSIDEREQUESTMESSAGE)
      return "HouseSellFromInsideRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSESELLREQUESTMESSAGE)
      return "HouseSellRequestMessage";
  
  else if(messageEnum == MessageEnum::HOUSESOLDMESSAGE)
      return "HouseSoldMessage";
  
  else if(messageEnum == MessageEnum::HOUSETOSELLFILTERMESSAGE)
      return "HouseToSellFilterMessage";
  
  else if(messageEnum == MessageEnum::HOUSETOSELLLISTMESSAGE)
      return "HouseToSellListMessage";
  
  else if(messageEnum == MessageEnum::HOUSETOSELLLISTREQUESTMESSAGE)
      return "HouseToSellListRequestMessage";
  
  else if(messageEnum == MessageEnum::JOBALLOWMULTICRAFTREQUESTMESSAGE)
      return "JobAllowMultiCraftRequestMessage";
  
  else if(messageEnum == MessageEnum::JOBBOOKSUBSCRIPTIONMESSAGE)
      return "JobBookSubscriptionMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYADDMESSAGE)
      return "JobCrafterDirectoryAddMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE)
      return "JobCrafterDirectoryDefineSettingsMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYENTRYMESSAGE)
      return "JobCrafterDirectoryEntryMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE)
      return "JobCrafterDirectoryEntryRequestMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYLISTMESSAGE)
      return "JobCrafterDirectoryListMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE)
      return "JobCrafterDirectoryListRequestMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYREMOVEMESSAGE)
      return "JobCrafterDirectoryRemoveMessage";
  
  else if(messageEnum == MessageEnum::JOBCRAFTERDIRECTORYSETTINGSMESSAGE)
      return "JobCrafterDirectorySettingsMessage";
  
  else if(messageEnum == MessageEnum::JOBDESCRIPTIONMESSAGE)
      return "JobDescriptionMessage";
  
  else if(messageEnum == MessageEnum::JOBEXPERIENCEMULTIUPDATEMESSAGE)
      return "JobExperienceMultiUpdateMessage";
  
  else if(messageEnum == MessageEnum::JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE)
      return "JobExperienceOtherPlayerUpdateMessage";
  
  else if(messageEnum == MessageEnum::JOBEXPERIENCEUPDATEMESSAGE)
      return "JobExperienceUpdateMessage";
  
  else if(messageEnum == MessageEnum::JOBLEVELUPMESSAGE)
      return "JobLevelUpMessage";
  
  else if(messageEnum == MessageEnum::JOBMULTICRAFTAVAILABLESKILLSMESSAGE)
      return "JobMultiCraftAvailableSkillsMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLECHANGECODEMESSAGE)
      return "LockableChangeCodeMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLECODERESULTMESSAGE)
      return "LockableCodeResultMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLESHOWCODEDIALOGMESSAGE)
      return "LockableShowCodeDialogMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLESTATEUPDATEABSTRACTMESSAGE)
      return "LockableStateUpdateAbstractMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLESTATEUPDATEHOUSEDOORMESSAGE)
      return "LockableStateUpdateHouseDoorMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLESTATEUPDATESTORAGEMESSAGE)
      return "LockableStateUpdateStorageMessage";
  
  else if(messageEnum == MessageEnum::LOCKABLEUSECODEMESSAGE)
      return "LockableUseCodeMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE)
      return "MapComplementaryInformationsDataInHavenBagMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE)
      return "MapComplementaryInformationsDataInHouseMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE)
      return "MapComplementaryInformationsDataMessage";
  
  else if(messageEnum == MessageEnum::MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE)
      return "MapComplementaryInformationsWithCoordsMessage";
  
  else if(messageEnum == MessageEnum::MAPFIGHTCOUNTMESSAGE)
      return "MapFightCountMessage";
  
  else if(messageEnum == MessageEnum::MAPINFORMATIONSREQUESTMESSAGE)
      return "MapInformationsRequestMessage";
  
  else if(messageEnum == MessageEnum::MAPOBSTACLEUPDATEMESSAGE)
      return "MapObstacleUpdateMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTDETAILSEXTENDEDMESSAGE)
      return "MapRunningFightDetailsExtendedMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTDETAILSMESSAGE)
      return "MapRunningFightDetailsMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE)
      return "MapRunningFightDetailsRequestMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTLISTMESSAGE)
      return "MapRunningFightListMessage";
  
  else if(messageEnum == MessageEnum::MAPRUNNINGFIGHTLISTREQUESTMESSAGE)
      return "MapRunningFightListRequestMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCEPRISMDIALOGQUESTIONMESSAGE)
      return "AlliancePrismDialogQuestionMessage";
  
  else if(messageEnum == MessageEnum::ALLIANCETAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE)
      return "AllianceTaxCollectorDialogQuestionExtendedMessage";
  
  else if(messageEnum == MessageEnum::ENTITYTALKMESSAGE)
      return "EntityTalkMessage";
  
  else if(messageEnum == MessageEnum::MAPNPCSQUESTSTATUSUPDATEMESSAGE)
      return "MapNpcsQuestStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::NPCDIALOGCREATIONMESSAGE)
      return "NpcDialogCreationMessage";
  
  else if(messageEnum == MessageEnum::NPCDIALOGQUESTIONMESSAGE)
      return "NpcDialogQuestionMessage";
  
  else if(messageEnum == MessageEnum::NPCDIALOGREPLYMESSAGE)
      return "NpcDialogReplyMessage";
  
  else if(messageEnum == MessageEnum::NPCGENERICACTIONFAILUREMESSAGE)
      return "NpcGenericActionFailureMessage";
  
  else if(messageEnum == MessageEnum::NPCGENERICACTIONREQUESTMESSAGE)
      return "NpcGenericActionRequestMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORDIALOGQUESTIONBASICMESSAGE)
      return "TaxCollectorDialogQuestionBasicMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE)
      return "TaxCollectorDialogQuestionExtendedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTGROUNDADDEDMESSAGE)
      return "ObjectGroundAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTGROUNDLISTADDEDMESSAGE)
      return "ObjectGroundListAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTGROUNDREMOVEDMESSAGE)
      return "ObjectGroundRemovedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTGROUNDREMOVEDMULTIPLEMESSAGE)
      return "ObjectGroundRemovedMultipleMessage";
  
  else if(messageEnum == MessageEnum::GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE)
      return "GameDataPlayFarmObjectAnimationMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKPROPERTIESMESSAGE)
      return "PaddockPropertiesMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKSELLBUYDIALOGMESSAGE)
      return "PaddockSellBuyDialogMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKTOSELLFILTERMESSAGE)
      return "PaddockToSellFilterMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKTOSELLLISTMESSAGE)
      return "PaddockToSellListMessage";
  
  else if(messageEnum == MessageEnum::PADDOCKTOSELLLISTREQUESTMESSAGE)
      return "PaddockToSellListRequestMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTPARTYEVENTMESSAGE)
      return "AbstractPartyEventMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTPARTYMESSAGE)
      return "AbstractPartyMessage";
  
  else if(messageEnum == MessageEnum::PARTYCOMPANIONUPDATELIGHTMESSAGE)
      return "PartyCompanionUpdateLightMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE)
      return "DungeonPartyFinderAvailableDungeonsMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE)
      return "DungeonPartyFinderAvailableDungeonsRequestMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERLISTENERRORMESSAGE)
      return "DungeonPartyFinderListenErrorMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERLISTENREQUESTMESSAGE)
      return "DungeonPartyFinderListenRequestMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERREGISTERERRORMESSAGE)
      return "DungeonPartyFinderRegisterErrorMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE)
      return "DungeonPartyFinderRegisterRequestMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERREGISTERSUCCESSMESSAGE)
      return "DungeonPartyFinderRegisterSuccessMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERROOMCONTENTMESSAGE)
      return "DungeonPartyFinderRoomContentMessage";
  
  else if(messageEnum == MessageEnum::DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE)
      return "DungeonPartyFinderRoomContentUpdateMessage";
  
  else if(messageEnum == MessageEnum::PARTYABDICATETHRONEMESSAGE)
      return "PartyAbdicateThroneMessage";
  
  else if(messageEnum == MessageEnum::PARTYACCEPTINVITATIONMESSAGE)
      return "PartyAcceptInvitationMessage";
  
  else if(messageEnum == MessageEnum::PARTYCANCELINVITATIONMESSAGE)
      return "PartyCancelInvitationMessage";
  
  else if(messageEnum == MessageEnum::PARTYCANCELINVITATIONNOTIFICATIONMESSAGE)
      return "PartyCancelInvitationNotificationMessage";
  
  else if(messageEnum == MessageEnum::PARTYCANNOTJOINERRORMESSAGE)
      return "PartyCannotJoinErrorMessage";
  
  else if(messageEnum == MessageEnum::PARTYDELETEDMESSAGE)
      return "PartyDeletedMessage";
  
  else if(messageEnum == MessageEnum::PARTYFOLLOWMEMBERREQUESTMESSAGE)
      return "PartyFollowMemberRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYFOLLOWSTATUSUPDATEMESSAGE)
      return "PartyFollowStatusUpdateMessage";
  
  else if(messageEnum == MessageEnum::PARTYFOLLOWTHISMEMBERREQUESTMESSAGE)
      return "PartyFollowThisMemberRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONARENAREQUESTMESSAGE)
      return "PartyInvitationArenaRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONCANCELLEDFORGUESTMESSAGE)
      return "PartyInvitationCancelledForGuestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDETAILSMESSAGE)
      return "PartyInvitationDetailsMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDETAILSREQUESTMESSAGE)
      return "PartyInvitationDetailsRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDUNGEONDETAILSMESSAGE)
      return "PartyInvitationDungeonDetailsMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDUNGEONMESSAGE)
      return "PartyInvitationDungeonMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONDUNGEONREQUESTMESSAGE)
      return "PartyInvitationDungeonRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONMESSAGE)
      return "PartyInvitationMessage";
  
  else if(messageEnum == MessageEnum::PARTYINVITATIONREQUESTMESSAGE)
      return "PartyInvitationRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYJOINMESSAGE)
      return "PartyJoinMessage";
  
  else if(messageEnum == MessageEnum::PARTYKICKEDBYMESSAGE)
      return "PartyKickedByMessage";
  
  else if(messageEnum == MessageEnum::PARTYKICKREQUESTMESSAGE)
      return "PartyKickRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYLEADERUPDATEMESSAGE)
      return "PartyLeaderUpdateMessage";
  
  else if(messageEnum == MessageEnum::PARTYLEAVEMESSAGE)
      return "PartyLeaveMessage";
  
  else if(messageEnum == MessageEnum::PARTYLEAVEREQUESTMESSAGE)
      return "PartyLeaveRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYLOCATEMEMBERSMESSAGE)
      return "PartyLocateMembersMessage";
  
  else if(messageEnum == MessageEnum::PARTYLOCATEMEMBERSREQUESTMESSAGE)
      return "PartyLocateMembersRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYLOYALTYSTATUSMESSAGE)
      return "PartyLoyaltyStatusMessage";
  
  else if(messageEnum == MessageEnum::PARTYMEMBEREJECTEDMESSAGE)
      return "PartyMemberEjectedMessage";
  
  else if(messageEnum == MessageEnum::PARTYMEMBERINFIGHTMESSAGE)
      return "PartyMemberInFightMessage";
  
  else if(messageEnum == MessageEnum::PARTYMEMBERREMOVEMESSAGE)
      return "PartyMemberRemoveMessage";
  
  else if(messageEnum == MessageEnum::PARTYMODIFIABLESTATUSMESSAGE)
      return "PartyModifiableStatusMessage";
  
  else if(messageEnum == MessageEnum::PARTYNAMESETERRORMESSAGE)
      return "PartyNameSetErrorMessage";
  
  else if(messageEnum == MessageEnum::PARTYNAMESETREQUESTMESSAGE)
      return "PartyNameSetRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYNAMEUPDATEMESSAGE)
      return "PartyNameUpdateMessage";
  
  else if(messageEnum == MessageEnum::PARTYNEWGUESTMESSAGE)
      return "PartyNewGuestMessage";
  
  else if(messageEnum == MessageEnum::PARTYNEWMEMBERMESSAGE)
      return "PartyNewMemberMessage";
  
  else if(messageEnum == MessageEnum::PARTYPLEDGELOYALTYREQUESTMESSAGE)
      return "PartyPledgeLoyaltyRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYREFUSEINVITATIONMESSAGE)
      return "PartyRefuseInvitationMessage";
  
  else if(messageEnum == MessageEnum::PARTYREFUSEINVITATIONNOTIFICATIONMESSAGE)
      return "PartyRefuseInvitationNotificationMessage";
  
  else if(messageEnum == MessageEnum::PARTYRESTRICTEDMESSAGE)
      return "PartyRestrictedMessage";
  
  else if(messageEnum == MessageEnum::PARTYSTOPFOLLOWREQUESTMESSAGE)
      return "PartyStopFollowRequestMessage";
  
  else if(messageEnum == MessageEnum::PARTYUPDATELIGHTMESSAGE)
      return "PartyUpdateLightMessage";
  
  else if(messageEnum == MessageEnum::PARTYUPDATEMESSAGE)
      return "PartyUpdateMessage";
  
  else if(messageEnum == MessageEnum::PURCHASABLEDIALOGMESSAGE)
      return "PurchasableDialogMessage";
  
  else if(messageEnum == MessageEnum::GUIDEDMODEQUITREQUESTMESSAGE)
      return "GuidedModeQuitRequestMessage";
  
  else if(messageEnum == MessageEnum::GUIDEDMODERETURNREQUESTMESSAGE)
      return "GuidedModeReturnRequestMessage";
  
  else if(messageEnum == MessageEnum::QUESTLISTMESSAGE)
      return "QuestListMessage";
  
  else if(messageEnum == MessageEnum::QUESTLISTREQUESTMESSAGE)
      return "QuestListRequestMessage";
  
  else if(messageEnum == MessageEnum::QUESTOBJECTIVEVALIDATEDMESSAGE)
      return "QuestObjectiveValidatedMessage";
  
  else if(messageEnum == MessageEnum::QUESTOBJECTIVEVALIDATIONMESSAGE)
      return "QuestObjectiveValidationMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTARTEDMESSAGE)
      return "QuestStartedMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTARTREQUESTMESSAGE)
      return "QuestStartRequestMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTEPINFOMESSAGE)
      return "QuestStepInfoMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTEPINFOREQUESTMESSAGE)
      return "QuestStepInfoRequestMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTEPSTARTEDMESSAGE)
      return "QuestStepStartedMessage";
  
  else if(messageEnum == MessageEnum::QUESTSTEPVALIDATEDMESSAGE)
      return "QuestStepValidatedMessage";
  
  else if(messageEnum == MessageEnum::QUESTVALIDATEDMESSAGE)
      return "QuestValidatedMessage";
  
  else if(messageEnum == MessageEnum::SPELLITEMBOOSTMESSAGE)
      return "SpellItemBoostMessage";
  
  else if(messageEnum == MessageEnum::SPELLMODIFYFAILUREMESSAGE)
      return "SpellModifyFailureMessage";
  
  else if(messageEnum == MessageEnum::SPELLMODIFYREQUESTMESSAGE)
      return "SpellModifyRequestMessage";
  
  else if(messageEnum == MessageEnum::SPELLMODIFYSUCCESSMESSAGE)
      return "SpellModifySuccessMessage";
  
  else if(messageEnum == MessageEnum::SPELLVARIANTACTIVATIONMESSAGE)
      return "SpellVariantActivationMessage";
  
  else if(messageEnum == MessageEnum::SPELLVARIANTACTIVATIONREQUESTMESSAGE)
      return "SpellVariantActivationRequestMessage";
  
  else if(messageEnum == MessageEnum::STATSUPGRADEREQUESTMESSAGE)
      return "StatsUpgradeRequestMessage";
  
  else if(messageEnum == MessageEnum::STATSUPGRADERESULTMESSAGE)
      return "StatsUpgradeResultMessage";
  
  else if(messageEnum == MessageEnum::STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE)
      return "StopToListenRunningFightRequestMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTONSAMEMAPMESSAGE)
      return "TeleportOnSameMapMessage";
  
  else if(messageEnum == MessageEnum::PORTALUSEREQUESTMESSAGE)
      return "PortalUseRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE)
      return "TreasureHuntAvailableRetryCountUpdateMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE)
      return "TreasureHuntDigRequestAnswerFailedMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTDIGREQUESTANSWERMESSAGE)
      return "TreasureHuntDigRequestAnswerMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTDIGREQUESTMESSAGE)
      return "TreasureHuntDigRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTFINISHEDMESSAGE)
      return "TreasureHuntFinishedMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTFLAGREMOVEREQUESTMESSAGE)
      return "TreasureHuntFlagRemoveRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTFLAGREQUESTANSWERMESSAGE)
      return "TreasureHuntFlagRequestAnswerMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTFLAGREQUESTMESSAGE)
      return "TreasureHuntFlagRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTGIVEUPREQUESTMESSAGE)
      return "TreasureHuntGiveUpRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTLEGENDARYREQUESTMESSAGE)
      return "TreasureHuntLegendaryRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTMESSAGE)
      return "TreasureHuntMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTREQUESTANSWERMESSAGE)
      return "TreasureHuntRequestAnswerMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTREQUESTMESSAGE)
      return "TreasureHuntRequestMessage";
  
  else if(messageEnum == MessageEnum::TREASUREHUNTSHOWLEGENDARYUIMESSAGE)
      return "TreasureHuntShowLegendaryUIMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYSPELLANIMMESSAGE)
      return "GameRolePlaySpellAnimMessage";
  
  else if(messageEnum == MessageEnum::SHOWCELLMESSAGE)
      return "ShowCellMessage";
  
  else if(messageEnum == MessageEnum::SHOWCELLREQUESTMESSAGE)
      return "ShowCellRequestMessage";
  
  else if(messageEnum == MessageEnum::SHOWCELLSPECTATORMESSAGE)
      return "ShowCellSpectatorMessage";
  
  else if(messageEnum == MessageEnum::DARECANCELEDMESSAGE)
      return "DareCanceledMessage";
  
  else if(messageEnum == MessageEnum::DARECANCELREQUESTMESSAGE)
      return "DareCancelRequestMessage";
  
  else if(messageEnum == MessageEnum::DARECREATEDLISTMESSAGE)
      return "DareCreatedListMessage";
  
  else if(messageEnum == MessageEnum::DARECREATEDMESSAGE)
      return "DareCreatedMessage";
  
  else if(messageEnum == MessageEnum::DARECREATIONREQUESTMESSAGE)
      return "DareCreationRequestMessage";
  
  else if(messageEnum == MessageEnum::DAREERRORMESSAGE)
      return "DareErrorMessage";
  
  else if(messageEnum == MessageEnum::DAREINFORMATIONSMESSAGE)
      return "DareInformationsMessage";
  
  else if(messageEnum == MessageEnum::DAREINFORMATIONSREQUESTMESSAGE)
      return "DareInformationsRequestMessage";
  
  else if(messageEnum == MessageEnum::DARELISTMESSAGE)
      return "DareListMessage";
  
  else if(messageEnum == MessageEnum::DAREREWARDCONSUMEREQUESTMESSAGE)
      return "DareRewardConsumeRequestMessage";
  
  else if(messageEnum == MessageEnum::DAREREWARDCONSUMEVALIDATIONMESSAGE)
      return "DareRewardConsumeValidationMessage";
  
  else if(messageEnum == MessageEnum::DAREREWARDSLISTMESSAGE)
      return "DareRewardsListMessage";
  
  else if(messageEnum == MessageEnum::DAREREWARDWONMESSAGE)
      return "DareRewardWonMessage";
  
  else if(messageEnum == MessageEnum::DARESUBSCRIBEDLISTMESSAGE)
      return "DareSubscribedListMessage";
  
  else if(messageEnum == MessageEnum::DARESUBSCRIBEDMESSAGE)
      return "DareSubscribedMessage";
  
  else if(messageEnum == MessageEnum::DARESUBSCRIBEREQUESTMESSAGE)
      return "DareSubscribeRequestMessage";
  
  else if(messageEnum == MessageEnum::DAREVERSATILELISTMESSAGE)
      return "DareVersatileListMessage";
  
  else if(messageEnum == MessageEnum::DAREWONLISTMESSAGE)
      return "DareWonListMessage";
  
  else if(messageEnum == MessageEnum::DAREWONMESSAGE)
      return "DareWonMessage";
  
  else if(messageEnum == MessageEnum::LEAVEDIALOGMESSAGE)
      return "LeaveDialogMessage";
  
  else if(messageEnum == MessageEnum::LEAVEDIALOGREQUESTMESSAGE)
      return "LeaveDialogRequestMessage";
  
  else if(messageEnum == MessageEnum::PAUSEDIALOGMESSAGE)
      return "PauseDialogMessage";
  
  else if(messageEnum == MessageEnum::FINISHMOVELISTMESSAGE)
      return "FinishMoveListMessage";
  
  else if(messageEnum == MessageEnum::FINISHMOVELISTREQUESTMESSAGE)
      return "FinishMoveListRequestMessage";
  
  else if(messageEnum == MessageEnum::FINISHMOVESETREQUESTMESSAGE)
      return "FinishMoveSetRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDADDEDMESSAGE)
      return "FriendAddedMessage";
  
  else if(messageEnum == MessageEnum::FRIENDADDFAILUREMESSAGE)
      return "FriendAddFailureMessage";
  
  else if(messageEnum == MessageEnum::FRIENDADDREQUESTMESSAGE)
      return "FriendAddRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDDELETEREQUESTMESSAGE)
      return "FriendDeleteRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDDELETERESULTMESSAGE)
      return "FriendDeleteResultMessage";
  
  else if(messageEnum == MessageEnum::FRIENDJOINREQUESTMESSAGE)
      return "FriendJoinRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSETWARNONCONNECTIONMESSAGE)
      return "FriendSetWarnOnConnectionMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSETWARNONLEVELGAINMESSAGE)
      return "FriendSetWarnOnLevelGainMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSGETLISTMESSAGE)
      return "FriendsGetListMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSLISTMESSAGE)
      return "FriendsListMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSPOUSEFOLLOWWITHCOMPASSREQUESTMESSAGE)
      return "FriendSpouseFollowWithCompassRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDSPOUSEJOINREQUESTMESSAGE)
      return "FriendSpouseJoinRequestMessage";
  
  else if(messageEnum == MessageEnum::FRIENDUPDATEMESSAGE)
      return "FriendUpdateMessage";
  
  else if(messageEnum == MessageEnum::FRIENDWARNONCONNECTIONSTATEMESSAGE)
      return "FriendWarnOnConnectionStateMessage";
  
  else if(messageEnum == MessageEnum::FRIENDWARNONLEVELGAINSTATEMESSAGE)
      return "FriendWarnOnLevelGainStateMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERSETWARNONCONNECTIONMESSAGE)
      return "GuildMemberSetWarnOnConnectionMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERWARNONCONNECTIONSTATEMESSAGE)
      return "GuildMemberWarnOnConnectionStateMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDADDEDMESSAGE)
      return "IgnoredAddedMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDADDFAILUREMESSAGE)
      return "IgnoredAddFailureMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDADDREQUESTMESSAGE)
      return "IgnoredAddRequestMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDDELETEREQUESTMESSAGE)
      return "IgnoredDeleteRequestMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDDELETERESULTMESSAGE)
      return "IgnoredDeleteResultMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDGETLISTMESSAGE)
      return "IgnoredGetListMessage";
  
  else if(messageEnum == MessageEnum::IGNOREDLISTMESSAGE)
      return "IgnoredListMessage";
  
  else if(messageEnum == MessageEnum::SPOUSEGETINFORMATIONSMESSAGE)
      return "SpouseGetInformationsMessage";
  
  else if(messageEnum == MessageEnum::SPOUSEINFORMATIONSMESSAGE)
      return "SpouseInformationsMessage";
  
  else if(messageEnum == MessageEnum::SPOUSESTATUSMESSAGE)
      return "SpouseStatusMessage";
  
  else if(messageEnum == MessageEnum::WARNONPERMADEATHSTATEMESSAGE)
      return "WarnOnPermaDeathStateMessage";
  
  else if(messageEnum == MessageEnum::GUESTLIMITATIONMESSAGE)
      return "GuestLimitationMessage";
  
  else if(messageEnum == MessageEnum::GUESTMODEMESSAGE)
      return "GuestModeMessage";
  
  else if(messageEnum == MessageEnum::CHALLENGEFIGHTJOINREFUSEDMESSAGE)
      return "ChallengeFightJoinRefusedMessage";
  
  else if(messageEnum == MessageEnum::GUILDBULLETINMESSAGE)
      return "GuildBulletinMessage";
  
  else if(messageEnum == MessageEnum::GUILDBULLETINSETERRORMESSAGE)
      return "GuildBulletinSetErrorMessage";
  
  else if(messageEnum == MessageEnum::GUILDBULLETINSETREQUESTMESSAGE)
      return "GuildBulletinSetRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDCHANGEMEMBERPARAMETERSMESSAGE)
      return "GuildChangeMemberParametersMessage";
  
  else if(messageEnum == MessageEnum::GUILDCHARACSUPGRADEREQUESTMESSAGE)
      return "GuildCharacsUpgradeRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDCREATIONRESULTMESSAGE)
      return "GuildCreationResultMessage";
  
  else if(messageEnum == MessageEnum::GUILDCREATIONSTARTEDMESSAGE)
      return "GuildCreationStartedMessage";
  
  else if(messageEnum == MessageEnum::GUILDCREATIONVALIDMESSAGE)
      return "GuildCreationValidMessage";
  
  else if(messageEnum == MessageEnum::GUILDFACTSERRORMESSAGE)
      return "GuildFactsErrorMessage";
  
  else if(messageEnum == MessageEnum::GUILDFACTSMESSAGE)
      return "GuildFactsMessage";
  
  else if(messageEnum == MessageEnum::GUILDFACTSREQUESTMESSAGE)
      return "GuildFactsRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDGETINFORMATIONSMESSAGE)
      return "GuildGetInformationsMessage";
  
  else if(messageEnum == MessageEnum::GUILDHOUSEREMOVEMESSAGE)
      return "GuildHouseRemoveMessage";
  
  else if(messageEnum == MessageEnum::GUILDHOUSESINFORMATIONMESSAGE)
      return "GuildHousesInformationMessage";
  
  else if(messageEnum == MessageEnum::GUILDHOUSETELEPORTREQUESTMESSAGE)
      return "GuildHouseTeleportRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDHOUSEUPDATEINFORMATIONMESSAGE)
      return "GuildHouseUpdateInformationMessage";
  
  else if(messageEnum == MessageEnum::GUILDINALLIANCEFACTSMESSAGE)
      return "GuildInAllianceFactsMessage";
  
  else if(messageEnum == MessageEnum::GUILDINFORMATIONSGENERALMESSAGE)
      return "GuildInformationsGeneralMessage";
  
  else if(messageEnum == MessageEnum::GUILDINFORMATIONSMEMBERSMESSAGE)
      return "GuildInformationsMembersMessage";
  
  else if(messageEnum == MessageEnum::GUILDINFORMATIONSMEMBERUPDATEMESSAGE)
      return "GuildInformationsMemberUpdateMessage";
  
  else if(messageEnum == MessageEnum::GUILDINFORMATIONSPADDOCKSMESSAGE)
      return "GuildInformationsPaddocksMessage";
  
  else if(messageEnum == MessageEnum::GUILDINFOSUPGRADEMESSAGE)
      return "GuildInfosUpgradeMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITATIONANSWERMESSAGE)
      return "GuildInvitationAnswerMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITATIONBYNAMEMESSAGE)
      return "GuildInvitationByNameMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITATIONMESSAGE)
      return "GuildInvitationMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITATIONSTATERECRUTEDMESSAGE)
      return "GuildInvitationStateRecrutedMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITATIONSTATERECRUTERMESSAGE)
      return "GuildInvitationStateRecruterMessage";
  
  else if(messageEnum == MessageEnum::GUILDINVITEDMESSAGE)
      return "GuildInvitedMessage";
  
  else if(messageEnum == MessageEnum::GUILDJOINEDMESSAGE)
      return "GuildJoinedMessage";
  
  else if(messageEnum == MessageEnum::GUILDKICKREQUESTMESSAGE)
      return "GuildKickRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDLEFTMESSAGE)
      return "GuildLeftMessage";
  
  else if(messageEnum == MessageEnum::GUILDLEVELUPMESSAGE)
      return "GuildLevelUpMessage";
  
  else if(messageEnum == MessageEnum::GUILDLISTMESSAGE)
      return "GuildListMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERLEAVINGMESSAGE)
      return "GuildMemberLeavingMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERONLINESTATUSMESSAGE)
      return "GuildMemberOnlineStatusMessage";
  
  else if(messageEnum == MessageEnum::GUILDMEMBERSHIPMESSAGE)
      return "GuildMembershipMessage";
  
  else if(messageEnum == MessageEnum::GUILDMODIFICATIONEMBLEMVALIDMESSAGE)
      return "GuildModificationEmblemValidMessage";
  
  else if(messageEnum == MessageEnum::GUILDMODIFICATIONNAMEVALIDMESSAGE)
      return "GuildModificationNameValidMessage";
  
  else if(messageEnum == MessageEnum::GUILDMODIFICATIONSTARTEDMESSAGE)
      return "GuildModificationStartedMessage";
  
  else if(messageEnum == MessageEnum::GUILDMODIFICATIONVALIDMESSAGE)
      return "GuildModificationValidMessage";
  
  else if(messageEnum == MessageEnum::GUILDMOTDMESSAGE)
      return "GuildMotdMessage";
  
  else if(messageEnum == MessageEnum::GUILDMOTDSETERRORMESSAGE)
      return "GuildMotdSetErrorMessage";
  
  else if(messageEnum == MessageEnum::GUILDMOTDSETREQUESTMESSAGE)
      return "GuildMotdSetRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDPADDOCKBOUGHTMESSAGE)
      return "GuildPaddockBoughtMessage";
  
  else if(messageEnum == MessageEnum::GUILDPADDOCKREMOVEDMESSAGE)
      return "GuildPaddockRemovedMessage";
  
  else if(messageEnum == MessageEnum::GUILDPADDOCKTELEPORTREQUESTMESSAGE)
      return "GuildPaddockTeleportRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDSPELLUPGRADEREQUESTMESSAGE)
      return "GuildSpellUpgradeRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDVERSATILEINFOLISTMESSAGE)
      return "GuildVersatileInfoListMessage";
  
  else if(messageEnum == MessageEnum::ABSTRACTTAXCOLLECTORLISTMESSAGE)
      return "AbstractTaxCollectorListMessage";
  
  else if(messageEnum == MessageEnum::GAMEROLEPLAYTAXCOLLECTORFIGHTREQUESTMESSAGE)
      return "GameRolePlayTaxCollectorFightRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDFIGHTJOINREQUESTMESSAGE)
      return "GuildFightJoinRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDFIGHTLEAVEREQUESTMESSAGE)
      return "GuildFightLeaveRequestMessage";
  
  else if(messageEnum == MessageEnum::GUILDFIGHTPLAYERSENEMIESLISTMESSAGE)
      return "GuildFightPlayersEnemiesListMessage";
  
  else if(messageEnum == MessageEnum::GUILDFIGHTPLAYERSENEMYREMOVEMESSAGE)
      return "GuildFightPlayersEnemyRemoveMessage";
  
  else if(messageEnum == MessageEnum::GUILDFIGHTPLAYERSHELPERSJOINMESSAGE)
      return "GuildFightPlayersHelpersJoinMessage";
  
  else if(messageEnum == MessageEnum::GUILDFIGHTPLAYERSHELPERSLEAVEMESSAGE)
      return "GuildFightPlayersHelpersLeaveMessage";
  
  else if(messageEnum == MessageEnum::GUILDFIGHTTAKEPLACEREQUESTMESSAGE)
      return "GuildFightTakePlaceRequestMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORATTACKEDMESSAGE)
      return "TaxCollectorAttackedMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORATTACKEDRESULTMESSAGE)
      return "TaxCollectorAttackedResultMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORERRORMESSAGE)
      return "TaxCollectorErrorMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORLISTMESSAGE)
      return "TaxCollectorListMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORMOVEMENTADDMESSAGE)
      return "TaxCollectorMovementAddMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORMOVEMENTMESSAGE)
      return "TaxCollectorMovementMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORMOVEMENTREMOVEMESSAGE)
      return "TaxCollectorMovementRemoveMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE)
      return "TaxCollectorMovementsOfflineMessage";
  
  else if(messageEnum == MessageEnum::TAXCOLLECTORSTATEUPDATEMESSAGE)
      return "TaxCollectorStateUpdateMessage";
  
  else if(messageEnum == MessageEnum::TOPTAXCOLLECTORLISTMESSAGE)
      return "TopTaxCollectorListMessage";
  
  else if(messageEnum == MessageEnum::IDOLFIGHTPREPARATIONUPDATEMESSAGE)
      return "IdolFightPreparationUpdateMessage";
  
  else if(messageEnum == MessageEnum::IDOLLISTMESSAGE)
      return "IdolListMessage";
  
  else if(messageEnum == MessageEnum::IDOLPARTYLOSTMESSAGE)
      return "IdolPartyLostMessage";
  
  else if(messageEnum == MessageEnum::IDOLPARTYREFRESHMESSAGE)
      return "IdolPartyRefreshMessage";
  
  else if(messageEnum == MessageEnum::IDOLPARTYREGISTERREQUESTMESSAGE)
      return "IdolPartyRegisterRequestMessage";
  
  else if(messageEnum == MessageEnum::IDOLSELECTEDMESSAGE)
      return "IdolSelectedMessage";
  
  else if(messageEnum == MessageEnum::IDOLSELECTERRORMESSAGE)
      return "IdolSelectErrorMessage";
  
  else if(messageEnum == MessageEnum::IDOLSELECTREQUESTMESSAGE)
      return "IdolSelectRequestMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERCAPABILITIESMESSAGE)
      return "CharacterCapabilitiesMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERLOADINGCOMPLETEMESSAGE)
      return "CharacterLoadingCompleteMessage";
  
  else if(messageEnum == MessageEnum::ONCONNECTIONEVENTMESSAGE)
      return "OnConnectionEventMessage";
  
  else if(messageEnum == MessageEnum::SERVEREXPERIENCEMODIFICATORMESSAGE)
      return "ServerExperienceModificatorMessage";
  
  else if(messageEnum == MessageEnum::SETCHARACTERRESTRICTIONSMESSAGE)
      return "SetCharacterRestrictionsMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEELEMENTUPDATEDMESSAGE)
      return "InteractiveElementUpdatedMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEMAPUPDATEMESSAGE)
      return "InteractiveMapUpdateMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEUSEDMESSAGE)
      return "InteractiveUsedMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEUSEENDEDMESSAGE)
      return "InteractiveUseEndedMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEUSEERRORMESSAGE)
      return "InteractiveUseErrorMessage";
  
  else if(messageEnum == MessageEnum::INTERACTIVEUSEREQUESTMESSAGE)
      return "InteractiveUseRequestMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTBUDDIESANSWERMESSAGE)
      return "TeleportBuddiesAnswerMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTBUDDIESMESSAGE)
      return "TeleportBuddiesMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTBUDDIESREQUESTEDMESSAGE)
      return "TeleportBuddiesRequestedMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTTOBUDDYANSWERMESSAGE)
      return "TeleportToBuddyAnswerMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTTOBUDDYCLOSEMESSAGE)
      return "TeleportToBuddyCloseMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTTOBUDDYOFFERMESSAGE)
      return "TeleportToBuddyOfferMessage";
  
  else if(messageEnum == MessageEnum::STATEDELEMENTUPDATEDMESSAGE)
      return "StatedElementUpdatedMessage";
  
  else if(messageEnum == MessageEnum::STATEDMAPUPDATEMESSAGE)
      return "StatedMapUpdateMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTDESTINATIONSLISTMESSAGE)
      return "TeleportDestinationsListMessage";
  
  else if(messageEnum == MessageEnum::TELEPORTREQUESTMESSAGE)
      return "TeleportRequestMessage";
  
  else if(messageEnum == MessageEnum::ZAAPLISTMESSAGE)
      return "ZaapListMessage";
  
  else if(messageEnum == MessageEnum::ZAAPRESPAWNSAVEREQUESTMESSAGE)
      return "ZaapRespawnSaveRequestMessage";
  
  else if(messageEnum == MessageEnum::ZAAPRESPAWNUPDATEDMESSAGE)
      return "ZaapRespawnUpdatedMessage";
  
  else if(messageEnum == MessageEnum::DECRAFTRESULTMESSAGE)
      return "DecraftResultMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEACCEPTMESSAGE)
      return "ExchangeAcceptMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEBUYMESSAGE)
      return "ExchangeBidHouseBuyMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEBUYRESULTMESSAGE)
      return "ExchangeBidHouseBuyResultMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE)
      return "ExchangeBidHouseGenericItemAddedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE)
      return "ExchangeBidHouseGenericItemRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEINLISTADDEDMESSAGE)
      return "ExchangeBidHouseInListAddedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE)
      return "ExchangeBidHouseInListRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEINLISTUPDATEDMESSAGE)
      return "ExchangeBidHouseInListUpdatedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEITEMADDOKMESSAGE)
      return "ExchangeBidHouseItemAddOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEITEMREMOVEOKMESSAGE)
      return "ExchangeBidHouseItemRemoveOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSELISTMESSAGE)
      return "ExchangeBidHouseListMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEPRICEMESSAGE)
      return "ExchangeBidHousePriceMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSESEARCHMESSAGE)
      return "ExchangeBidHouseSearchMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSETYPEMESSAGE)
      return "ExchangeBidHouseTypeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDHOUSEUNSOLDITEMSMESSAGE)
      return "ExchangeBidHouseUnsoldItemsMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDPRICEFORSELLERMESSAGE)
      return "ExchangeBidPriceForSellerMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDPRICEMESSAGE)
      return "ExchangeBidPriceMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBIDSEARCHOKMESSAGE)
      return "ExchangeBidSearchOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBUYMESSAGE)
      return "ExchangeBuyMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEBUYOKMESSAGE)
      return "ExchangeBuyOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTCOUNTMODIFIEDMESSAGE)
      return "ExchangeCraftCountModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTCOUNTREQUESTMESSAGE)
      return "ExchangeCraftCountRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTERJOBLEVELUPMESSAGE)
      return "ExchangeCrafterJobLevelupMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTINFORMATIONOBJECTMESSAGE)
      return "ExchangeCraftInformationObjectMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTPAYMENTMODIFICATIONREQUESTMESSAGE)
      return "ExchangeCraftPaymentModificationRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTPAYMENTMODIFIEDMESSAGE)
      return "ExchangeCraftPaymentModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE)
      return "ExchangeCraftResultMagicWithObjectDescMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTRESULTMESSAGE)
      return "ExchangeCraftResultMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE)
      return "ExchangeCraftResultWithObjectDescMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE)
      return "ExchangeCraftResultWithObjectIdMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEERRORMESSAGE)
      return "ExchangeErrorMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEGUILDTAXCOLLECTORGETMESSAGE)
      return "ExchangeGuildTaxCollectorGetMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEHANDLEMOUNTSSTABLEMESSAGE)
      return "ExchangeHandleMountsStableMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEISREADYMESSAGE)
      return "ExchangeIsReadyMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEITEMAUTOCRAFTSTOPEDMESSAGE)
      return "ExchangeItemAutoCraftStopedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGELEAVEMESSAGE)
      return "ExchangeLeaveMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE)
      return "ExchangeMountFreeFromPaddockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSPADDOCKADDMESSAGE)
      return "ExchangeMountsPaddockAddMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE)
      return "ExchangeMountsPaddockRemoveMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSSTABLEADDMESSAGE)
      return "ExchangeMountsStableAddMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSSTABLEBORNADDMESSAGE)
      return "ExchangeMountsStableBornAddMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSSTABLEREMOVEMESSAGE)
      return "ExchangeMountsStableRemoveMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSTABLEERRORMESSAGE)
      return "ExchangeMountStableErrorMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE)
      return "ExchangeMountsTakenFromPaddockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE)
      return "ExchangeMountSterilizeFromPaddockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTADDEDMESSAGE)
      return "ExchangeObjectAddedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMESSAGE)
      return "ExchangeObjectMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMODIFYPRICEDMESSAGE)
      return "ExchangeObjectModifyPricedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMOVEKAMAMESSAGE)
      return "ExchangeObjectMoveKamaMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMOVEMESSAGE)
      return "ExchangeObjectMoveMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMOVEPRICEDMESSAGE)
      return "ExchangeObjectMovePricedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTSADDEDMESSAGE)
      return "ExchangeObjectsAddedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTALLFROMINVMESSAGE)
      return "ExchangeObjectTransfertAllFromInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTALLTOINVMESSAGE)
      return "ExchangeObjectTransfertAllToInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTEXISTINGFROMINVMESSAGE)
      return "ExchangeObjectTransfertExistingFromInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTEXISTINGTOINVMESSAGE)
      return "ExchangeObjectTransfertExistingToInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTLISTFROMINVMESSAGE)
      return "ExchangeObjectTransfertListFromInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTLISTTOINVMESSAGE)
      return "ExchangeObjectTransfertListToInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTTRANSFERTLISTWITHQUANTITYTOINVMESSAGE)
      return "ExchangeObjectTransfertListWithQuantityToInvMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTUSEINWORKSHOPMESSAGE)
      return "ExchangeObjectUseInWorkshopMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOFFLINESOLDITEMSMESSAGE)
      return "ExchangeOfflineSoldItemsMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOKMULTICRAFTMESSAGE)
      return "ExchangeOkMultiCraftMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEONHUMANVENDORREQUESTMESSAGE)
      return "ExchangeOnHumanVendorRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEPLAYERMULTICRAFTREQUESTMESSAGE)
      return "ExchangePlayerMultiCraftRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEPLAYERREQUESTMESSAGE)
      return "ExchangePlayerRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREADYMESSAGE)
      return "ExchangeReadyMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREPLAYSTOPMESSAGE)
      return "ExchangeReplayStopMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREPLYTAXVENDORMESSAGE)
      return "ExchangeReplyTaxVendorMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTEDMESSAGE)
      return "ExchangeRequestedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTEDTRADEMESSAGE)
      return "ExchangeRequestedTradeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTMESSAGE)
      return "ExchangeRequestMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTONMOUNTSTOCKMESSAGE)
      return "ExchangeRequestOnMountStockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTONSHOPSTOCKMESSAGE)
      return "ExchangeRequestOnShopStockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEREQUESTONTAXCOLLECTORMESSAGE)
      return "ExchangeRequestOnTaxCollectorMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESELLMESSAGE)
      return "ExchangeSellMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESELLOKMESSAGE)
      return "ExchangeSellOkMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESETCRAFTRECIPEMESSAGE)
      return "ExchangeSetCraftRecipeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESHOPSTOCKMOVEMENTREMOVEDMESSAGE)
      return "ExchangeShopStockMovementRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESHOPSTOCKMOVEMENTUPDATEDMESSAGE)
      return "ExchangeShopStockMovementUpdatedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTREMOVEDMESSAGE)
      return "ExchangeShopStockMultiMovementRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESHOPSTOCKMULTIMOVEMENTUPDATEDMESSAGE)
      return "ExchangeShopStockMultiMovementUpdatedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESHOPSTOCKSTARTEDMESSAGE)
      return "ExchangeShopStockStartedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESHOWVENDORTAXMESSAGE)
      return "ExchangeShowVendorTaxMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTASVENDORMESSAGE)
      return "ExchangeStartAsVendorMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDBIDBUYERMESSAGE)
      return "ExchangeStartedBidBuyerMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDBIDSELLERMESSAGE)
      return "ExchangeStartedBidSellerMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDMESSAGE)
      return "ExchangeStartedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDMOUNTSTOCKMESSAGE)
      return "ExchangeStartedMountStockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDTAXCOLLECTORSHOPMESSAGE)
      return "ExchangeStartedTaxCollectorShopMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDWITHPODSMESSAGE)
      return "ExchangeStartedWithPodsMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTEDWITHSTORAGEMESSAGE)
      return "ExchangeStartedWithStorageMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKCRAFTMESSAGE)
      return "ExchangeStartOkCraftMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKCRAFTWITHINFORMATIONMESSAGE)
      return "ExchangeStartOkCraftWithInformationMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKHUMANVENDORMESSAGE)
      return "ExchangeStartOkHumanVendorMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKJOBINDEXMESSAGE)
      return "ExchangeStartOkJobIndexMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKMOUNTMESSAGE)
      return "ExchangeStartOkMountMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE)
      return "ExchangeStartOkMountWithOutPaddockMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE)
      return "ExchangeStartOkMulticraftCrafterMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKMULTICRAFTCUSTOMERMESSAGE)
      return "ExchangeStartOkMulticraftCustomerMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKNPCSHOPMESSAGE)
      return "ExchangeStartOkNpcShopMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKNPCTRADEMESSAGE)
      return "ExchangeStartOkNpcTradeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKRECYCLETRADEMESSAGE)
      return "ExchangeStartOkRecycleTradeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTARTOKRUNESTRADEMESSAGE)
      return "ExchangeStartOkRunesTradeMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGESTOPPEDMESSAGE)
      return "ExchangeStoppedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE)
      return "ExchangeTypesExchangerDescriptionForUserMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE)
      return "ExchangeTypesItemsExchangerDescriptionForUserMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEWAITINGRESULTMESSAGE)
      return "ExchangeWaitingResultMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEWEIGHTMESSAGE)
      return "ExchangeWeightMessage";
  
  else if(messageEnum == MessageEnum::FOCUSEDEXCHANGEREADYMESSAGE)
      return "FocusedExchangeReadyMessage";
  
  else if(messageEnum == MessageEnum::ITEMNOMOREAVAILABLEMESSAGE)
      return "ItemNoMoreAvailableMessage";
  
  else if(messageEnum == MessageEnum::JOBBOOKSUBSCRIBEREQUESTMESSAGE)
      return "JobBookSubscribeRequestMessage";
  
  else if(messageEnum == MessageEnum::RECYCLERESULTMESSAGE)
      return "RecycleResultMessage";
  
  else if(messageEnum == MessageEnum::UPDATEMOUNTBOOSTMESSAGE)
      return "UpdateMountBoostMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEKAMAMODIFIEDMESSAGE)
      return "ExchangeKamaModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE)
      return "ExchangeMultiCraftCrafterCanUseHisRessourcesMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE)
      return "ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMODIFIEDINBAGMESSAGE)
      return "ExchangeObjectModifiedInBagMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTMODIFIEDMESSAGE)
      return "ExchangeObjectModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTPUTINBAGMESSAGE)
      return "ExchangeObjectPutInBagMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTREMOVEDFROMBAGMESSAGE)
      return "ExchangeObjectRemovedFromBagMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTREMOVEDMESSAGE)
      return "ExchangeObjectRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTSMODIFIEDMESSAGE)
      return "ExchangeObjectsModifiedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEOBJECTSREMOVEDMESSAGE)
      return "ExchangeObjectsRemovedMessage";
  
  else if(messageEnum == MessageEnum::EXCHANGEPODSMODIFIEDMESSAGE)
      return "ExchangePodsModifiedMessage";
  
  else if(messageEnum == MessageEnum::GOLDADDEDMESSAGE)
      return "GoldAddedMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYCONTENTANDPRESETMESSAGE)
      return "InventoryContentAndPresetMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYCONTENTMESSAGE)
      return "InventoryContentMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYWEIGHTMESSAGE)
      return "InventoryWeightMessage";
  
  else if(messageEnum == MessageEnum::LIVINGOBJECTCHANGESKINREQUESTMESSAGE)
      return "LivingObjectChangeSkinRequestMessage";
  
  else if(messageEnum == MessageEnum::LIVINGOBJECTDISSOCIATEMESSAGE)
      return "LivingObjectDissociateMessage";
  
  else if(messageEnum == MessageEnum::LIVINGOBJECTMESSAGEMESSAGE)
      return "LivingObjectMessageMessage";
  
  else if(messageEnum == MessageEnum::LIVINGOBJECTMESSAGEREQUESTMESSAGE)
      return "LivingObjectMessageRequestMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTASSOCIATEDMESSAGE)
      return "MimicryObjectAssociatedMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTERASEREQUESTMESSAGE)
      return "MimicryObjectEraseRequestMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTERRORMESSAGE)
      return "MimicryObjectErrorMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE)
      return "MimicryObjectFeedAndAssociateRequestMessage";
  
  else if(messageEnum == MessageEnum::MIMICRYOBJECTPREVIEWMESSAGE)
      return "MimicryObjectPreviewMessage";
  
  else if(messageEnum == MessageEnum::OBJECTADDEDMESSAGE)
      return "ObjectAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTDELETEDMESSAGE)
      return "ObjectDeletedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTDELETEMESSAGE)
      return "ObjectDeleteMessage";
  
  else if(messageEnum == MessageEnum::OBJECTDROPMESSAGE)
      return "ObjectDropMessage";
  
  else if(messageEnum == MessageEnum::OBJECTERRORMESSAGE)
      return "ObjectErrorMessage";
  
  else if(messageEnum == MessageEnum::OBJECTFEEDMESSAGE)
      return "ObjectFeedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTFOUNDWHILERECOLTINGMESSAGE)
      return "ObjectFoundWhileRecoltingMessage";
  
  else if(messageEnum == MessageEnum::OBJECTJOBADDEDMESSAGE)
      return "ObjectJobAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTMODIFIEDMESSAGE)
      return "ObjectModifiedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTMOVEMENTMESSAGE)
      return "ObjectMovementMessage";
  
  else if(messageEnum == MessageEnum::OBJECTQUANTITYMESSAGE)
      return "ObjectQuantityMessage";
  
  else if(messageEnum == MessageEnum::OBJECTSADDEDMESSAGE)
      return "ObjectsAddedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTSDELETEDMESSAGE)
      return "ObjectsDeletedMessage";
  
  else if(messageEnum == MessageEnum::OBJECTSETPOSITIONMESSAGE)
      return "ObjectSetPositionMessage";
  
  else if(messageEnum == MessageEnum::OBJECTSQUANTITYMESSAGE)
      return "ObjectsQuantityMessage";
  
  else if(messageEnum == MessageEnum::OBJECTUSEMESSAGE)
      return "ObjectUseMessage";
  
  else if(messageEnum == MessageEnum::OBJECTUSEMULTIPLEMESSAGE)
      return "ObjectUseMultipleMessage";
  
  else if(messageEnum == MessageEnum::OBJECTUSEONCELLMESSAGE)
      return "ObjectUseOnCellMessage";
  
  else if(messageEnum == MessageEnum::OBJECTUSEONCHARACTERMESSAGE)
      return "ObjectUseOnCharacterMessage";
  
  else if(messageEnum == MessageEnum::OBTAINEDITEMMESSAGE)
      return "ObtainedItemMessage";
  
  else if(messageEnum == MessageEnum::OBTAINEDITEMWITHBONUSMESSAGE)
      return "ObtainedItemWithBonusMessage";
  
  else if(messageEnum == MessageEnum::SETUPDATEMESSAGE)
      return "SetUpdateMessage";
  
  else if(messageEnum == MessageEnum::SYMBIOTICOBJECTASSOCIATEDMESSAGE)
      return "SymbioticObjectAssociatedMessage";
  
  else if(messageEnum == MessageEnum::SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE)
      return "SymbioticObjectAssociateRequestMessage";
  
  else if(messageEnum == MessageEnum::SYMBIOTICOBJECTERRORMESSAGE)
      return "SymbioticObjectErrorMessage";
  
  else if(messageEnum == MessageEnum::WRAPPEROBJECTASSOCIATEDMESSAGE)
      return "WrapperObjectAssociatedMessage";
  
  else if(messageEnum == MessageEnum::WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE)
      return "WrapperObjectDissociateRequestMessage";
  
  else if(messageEnum == MessageEnum::WRAPPEROBJECTERRORMESSAGE)
      return "WrapperObjectErrorMessage";
  
  else if(messageEnum == MessageEnum::KAMASUPDATEMESSAGE)
      return "KamasUpdateMessage";
  
  else if(messageEnum == MessageEnum::OBJECTAVERAGEPRICESERRORMESSAGE)
      return "ObjectAveragePricesErrorMessage";
  
  else if(messageEnum == MessageEnum::OBJECTAVERAGEPRICESGETMESSAGE)
      return "ObjectAveragePricesGetMessage";
  
  else if(messageEnum == MessageEnum::OBJECTAVERAGEPRICESMESSAGE)
      return "ObjectAveragePricesMessage";
  
  else if(messageEnum == MessageEnum::IDOLSPRESETDELETEMESSAGE)
      return "IdolsPresetDeleteMessage";
  
  else if(messageEnum == MessageEnum::IDOLSPRESETDELETERESULTMESSAGE)
      return "IdolsPresetDeleteResultMessage";
  
  else if(messageEnum == MessageEnum::IDOLSPRESETSAVEMESSAGE)
      return "IdolsPresetSaveMessage";
  
  else if(messageEnum == MessageEnum::IDOLSPRESETSAVERESULTMESSAGE)
      return "IdolsPresetSaveResultMessage";
  
  else if(messageEnum == MessageEnum::IDOLSPRESETUPDATEMESSAGE)
      return "IdolsPresetUpdateMessage";
  
  else if(messageEnum == MessageEnum::IDOLSPRESETUSEMESSAGE)
      return "IdolsPresetUseMessage";
  
  else if(messageEnum == MessageEnum::IDOLSPRESETUSERESULTMESSAGE)
      return "IdolsPresetUseResultMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETDELETEMESSAGE)
      return "InventoryPresetDeleteMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETDELETERESULTMESSAGE)
      return "InventoryPresetDeleteResultMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETITEMUPDATEERRORMESSAGE)
      return "InventoryPresetItemUpdateErrorMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETITEMUPDATEMESSAGE)
      return "InventoryPresetItemUpdateMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETITEMUPDATEREQUESTMESSAGE)
      return "InventoryPresetItemUpdateRequestMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETSAVECUSTOMMESSAGE)
      return "InventoryPresetSaveCustomMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETSAVEMESSAGE)
      return "InventoryPresetSaveMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETSAVERESULTMESSAGE)
      return "InventoryPresetSaveResultMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETUPDATEMESSAGE)
      return "InventoryPresetUpdateMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETUSEMESSAGE)
      return "InventoryPresetUseMessage";
  
  else if(messageEnum == MessageEnum::INVENTORYPRESETUSERESULTMESSAGE)
      return "InventoryPresetUseResultMessage";
  
  else if(messageEnum == MessageEnum::SPELLLISTMESSAGE)
      return "SpellListMessage";
  
  else if(messageEnum == MessageEnum::STORAGEINVENTORYCONTENTMESSAGE)
      return "StorageInventoryContentMessage";
  
  else if(messageEnum == MessageEnum::STORAGEKAMASUPDATEMESSAGE)
      return "StorageKamasUpdateMessage";
  
  else if(messageEnum == MessageEnum::STORAGEOBJECTREMOVEMESSAGE)
      return "StorageObjectRemoveMessage";
  
  else if(messageEnum == MessageEnum::STORAGEOBJECTSREMOVEMESSAGE)
      return "StorageObjectsRemoveMessage";
  
  else if(messageEnum == MessageEnum::STORAGEOBJECTSUPDATEMESSAGE)
      return "StorageObjectsUpdateMessage";
  
  else if(messageEnum == MessageEnum::STORAGEOBJECTUPDATEMESSAGE)
      return "StorageObjectUpdateMessage";
  
  else if(messageEnum == MessageEnum::ACCESSORYPREVIEWERRORMESSAGE)
      return "AccessoryPreviewErrorMessage";
  
  else if(messageEnum == MessageEnum::ACCESSORYPREVIEWMESSAGE)
      return "AccessoryPreviewMessage";
  
  else if(messageEnum == MessageEnum::ACCESSORYPREVIEWREQUESTMESSAGE)
      return "AccessoryPreviewRequestMessage";
  
  else if(messageEnum == MessageEnum::POPUPWARNINGMESSAGE)
      return "PopupWarningMessage";
  
  else if(messageEnum == MessageEnum::AREAFIGHTMODIFICATORUPDATEMESSAGE)
      return "AreaFightModificatorUpdateMessage";
  
  else if(messageEnum == MessageEnum::PRISMATTACKREQUESTMESSAGE)
      return "PrismAttackRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMFIGHTADDEDMESSAGE)
      return "PrismFightAddedMessage";
  
  else if(messageEnum == MessageEnum::PRISMFIGHTATTACKERADDMESSAGE)
      return "PrismFightAttackerAddMessage";
  
  else if(messageEnum == MessageEnum::PRISMFIGHTATTACKERREMOVEMESSAGE)
      return "PrismFightAttackerRemoveMessage";
  
  else if(messageEnum == MessageEnum::PRISMFIGHTDEFENDERADDMESSAGE)
      return "PrismFightDefenderAddMessage";
  
  else if(messageEnum == MessageEnum::PRISMFIGHTDEFENDERLEAVEMESSAGE)
      return "PrismFightDefenderLeaveMessage";
  
  else if(messageEnum == MessageEnum::PRISMFIGHTJOINLEAVEREQUESTMESSAGE)
      return "PrismFightJoinLeaveRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMFIGHTREMOVEDMESSAGE)
      return "PrismFightRemovedMessage";
  
  else if(messageEnum == MessageEnum::PRISMFIGHTSTATEUPDATEMESSAGE)
      return "PrismFightStateUpdateMessage";
  
  else if(messageEnum == MessageEnum::PRISMFIGHTSWAPREQUESTMESSAGE)
      return "PrismFightSwapRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMINFOCLOSEMESSAGE)
      return "PrismInfoCloseMessage";
  
  else if(messageEnum == MessageEnum::PRISMINFOINVALIDMESSAGE)
      return "PrismInfoInValidMessage";
  
  else if(messageEnum == MessageEnum::PRISMINFOJOINLEAVEREQUESTMESSAGE)
      return "PrismInfoJoinLeaveRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMMODULEEXCHANGEREQUESTMESSAGE)
      return "PrismModuleExchangeRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMSETSABOTAGEDREFUSEDMESSAGE)
      return "PrismSetSabotagedRefusedMessage";
  
  else if(messageEnum == MessageEnum::PRISMSETSABOTAGEDREQUESTMESSAGE)
      return "PrismSetSabotagedRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMSETTINGSERRORMESSAGE)
      return "PrismSettingsErrorMessage";
  
  else if(messageEnum == MessageEnum::PRISMSETTINGSREQUESTMESSAGE)
      return "PrismSettingsRequestMessage";
  
  else if(messageEnum == MessageEnum::PRISMSINFOVALIDMESSAGE)
      return "PrismsInfoValidMessage";
  
  else if(messageEnum == MessageEnum::PRISMSLISTMESSAGE)
      return "PrismsListMessage";
  
  else if(messageEnum == MessageEnum::PRISMSLISTREGISTERMESSAGE)
      return "PrismsListRegisterMessage";
  
  else if(messageEnum == MessageEnum::PRISMSLISTUPDATEMESSAGE)
      return "PrismsListUpdateMessage";
  
  else if(messageEnum == MessageEnum::PRISMUSEREQUESTMESSAGE)
      return "PrismUseRequestMessage";
  
  else if(messageEnum == MessageEnum::ALIGNMENTRANKUPDATEMESSAGE)
      return "AlignmentRankUpdateMessage";
  
  else if(messageEnum == MessageEnum::SETENABLEAVAREQUESTMESSAGE)
      return "SetEnableAVARequestMessage";
  
  else if(messageEnum == MessageEnum::SETENABLEPVPREQUESTMESSAGE)
      return "SetEnablePVPRequestMessage";
  
  else if(messageEnum == MessageEnum::UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE)
      return "UpdateMapPlayersAgressableStatusMessage";
  
  else if(messageEnum == MessageEnum::UPDATESELFAGRESSABLESTATUSMESSAGE)
      return "UpdateSelfAgressableStatusMessage";
  
  else if(messageEnum == MessageEnum::CHARACTERREPORTMESSAGE)
      return "CharacterReportMessage";
  
  else if(messageEnum == MessageEnum::CINEMATICMESSAGE)
      return "CinematicMessage";
  
  else if(messageEnum == MessageEnum::URLOPENMESSAGE)
      return "URLOpenMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARADDERRORMESSAGE)
      return "ShortcutBarAddErrorMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARADDREQUESTMESSAGE)
      return "ShortcutBarAddRequestMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARCONTENTMESSAGE)
      return "ShortcutBarContentMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREFRESHMESSAGE)
      return "ShortcutBarRefreshMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREMOVEDMESSAGE)
      return "ShortcutBarRemovedMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREMOVEERRORMESSAGE)
      return "ShortcutBarRemoveErrorMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREMOVEREQUESTMESSAGE)
      return "ShortcutBarRemoveRequestMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARREPLACEDMESSAGE)
      return "ShortcutBarReplacedMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARSWAPERRORMESSAGE)
      return "ShortcutBarSwapErrorMessage";
  
  else if(messageEnum == MessageEnum::SHORTCUTBARSWAPREQUESTMESSAGE)
      return "ShortcutBarSwapRequestMessage";
  
  else if(messageEnum == MessageEnum::BULLETINMESSAGE)
      return "BulletinMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKERRORMESSAGE)
      return "ContactLookErrorMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKMESSAGE)
      return "ContactLookMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKREQUESTBYIDMESSAGE)
      return "ContactLookRequestByIdMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKREQUESTBYNAMEMESSAGE)
      return "ContactLookRequestByNameMessage";
  
  else if(messageEnum == MessageEnum::CONTACTLOOKREQUESTMESSAGE)
      return "ContactLookRequestMessage";
  
  else if(messageEnum == MessageEnum::SOCIALNOTICEMESSAGE)
      return "SocialNoticeMessage";
  
  else if(messageEnum == MessageEnum::SOCIALNOTICESETERRORMESSAGE)
      return "SocialNoticeSetErrorMessage";
  
  else if(messageEnum == MessageEnum::SOCIALNOTICESETREQUESTMESSAGE)
      return "SocialNoticeSetRequestMessage";
  
  else if(messageEnum == MessageEnum::STARTUPACTIONADDMESSAGE)
      return "StartupActionAddMessage";
  
  else if(messageEnum == MessageEnum::STARTUPACTIONFINISHEDMESSAGE)
      return "StartupActionFinishedMessage";
  
  else if(messageEnum == MessageEnum::STARTUPACTIONSALLATTRIBUTIONMESSAGE)
      return "StartupActionsAllAttributionMessage";
  
  else if(messageEnum == MessageEnum::STARTUPACTIONSEXECUTEMESSAGE)
      return "StartupActionsExecuteMessage";
  
  else if(messageEnum == MessageEnum::STARTUPACTIONSLISTMESSAGE)
      return "StartupActionsListMessage";
  
  else if(messageEnum == MessageEnum::STARTUPACTIONSOBJETATTRIBUTIONMESSAGE)
      return "StartupActionsObjetAttributionMessage";
  
  else if(messageEnum == MessageEnum::SUBSCRIPTIONLIMITATIONMESSAGE)
      return "SubscriptionLimitationMessage";
  
  else if(messageEnum == MessageEnum::SUBSCRIPTIONZONEMESSAGE)
      return "SubscriptionZoneMessage";
  
  else if(messageEnum == MessageEnum::ORNAMENTGAINEDMESSAGE)
      return "OrnamentGainedMessage";
  
  else if(messageEnum == MessageEnum::ORNAMENTSELECTEDMESSAGE)
      return "OrnamentSelectedMessage";
  
  else if(messageEnum == MessageEnum::ORNAMENTSELECTERRORMESSAGE)
      return "OrnamentSelectErrorMessage";
  
  else if(messageEnum == MessageEnum::ORNAMENTSELECTREQUESTMESSAGE)
      return "OrnamentSelectRequestMessage";
  
  else if(messageEnum == MessageEnum::TITLEGAINEDMESSAGE)
      return "TitleGainedMessage";
  
  else if(messageEnum == MessageEnum::TITLELOSTMESSAGE)
      return "TitleLostMessage";
  
  else if(messageEnum == MessageEnum::TITLESANDORNAMENTSLISTMESSAGE)
      return "TitlesAndOrnamentsListMessage";
  
  else if(messageEnum == MessageEnum::TITLESANDORNAMENTSLISTREQUESTMESSAGE)
      return "TitlesAndOrnamentsListRequestMessage";
  
  else if(messageEnum == MessageEnum::TITLESELECTEDMESSAGE)
      return "TitleSelectedMessage";
  
  else if(messageEnum == MessageEnum::TITLESELECTERRORMESSAGE)
      return "TitleSelectErrorMessage";
  
  else if(messageEnum == MessageEnum::TITLESELECTREQUESTMESSAGE)
      return "TitleSelectRequestMessage";
  
  else if(messageEnum == MessageEnum::CLIENTUIOPENEDBYOBJECTMESSAGE)
      return "ClientUIOpenedByObjectMessage";
  
  else if(messageEnum == MessageEnum::CLIENTUIOPENEDMESSAGE)
      return "ClientUIOpenedMessage";
  
  else if(messageEnum == MessageEnum::PROTOCOLREQUIRED)
      return "ProtocolRequired";
  
  else if(messageEnum == MessageEnum::LOGINQUEUESTATUSMESSAGE)
      return "LoginQueueStatusMessage";
  
  else if(messageEnum == MessageEnum::QUEUESTATUSMESSAGE)
      return "QueueStatusMessage";
  
  else if(messageEnum == MessageEnum::TRUSTSTATUSMESSAGE)
      return "TrustStatusMessage";
  
  else if(messageEnum == MessageEnum::CHECKFILEMESSAGE)
      return "CheckFileMessage";
  
  else if(messageEnum == MessageEnum::CHECKFILEREQUESTMESSAGE)
      return "CheckFileRequestMessage";
  
  else if(messageEnum == MessageEnum::CHECKINTEGRITYMESSAGE)
      return "CheckIntegrityMessage";
  
  else if(messageEnum == MessageEnum::CLIENTKEYMESSAGE)
      return "ClientKeyMessage";
  
  else if(messageEnum == MessageEnum::RAWDATAMESSAGE)
      return "RawDataMessage";
  
  else if(messageEnum == MessageEnum::SYSTEMMESSAGEDISPLAYMESSAGE)
      return "SystemMessageDisplayMessage";
  
  else if(messageEnum == MessageEnum::SUBSCRIPTIONUPDATEMESSAGE)
      return "SubscriptionUpdateMessage";
  
  else if(messageEnum == MessageEnum::DOWNLOADCURRENTSPEEDMESSAGE)
      return "DownloadCurrentSpeedMessage";
  
  else if(messageEnum == MessageEnum::DOWNLOADERRORMESSAGE)
      return "DownloadErrorMessage";
  
  else if(messageEnum == MessageEnum::DOWNLOADGETCURRENTSPEEDREQUESTMESSAGE)
      return "DownloadGetCurrentSpeedRequestMessage";
  
  else if(messageEnum == MessageEnum::DOWNLOADPARTMESSAGE)
      return "DownloadPartMessage";
  
  else if(messageEnum == MessageEnum::DOWNLOADSETSPEEDREQUESTMESSAGE)
      return "DownloadSetSpeedRequestMessage";
  
  else if(messageEnum == MessageEnum::GETPARTINFOMESSAGE)
      return "GetPartInfoMessage";
  
  else if(messageEnum == MessageEnum::GETPARTSLISTMESSAGE)
      return "GetPartsListMessage";
  
  else if(messageEnum == MessageEnum::PARTINFOMESSAGE)
      return "PartInfoMessage";
  
  else if(messageEnum == MessageEnum::PARTSLISTMESSAGE)
      return "PartsListMessage";
  
  else if(messageEnum == MessageEnum::MAILSTATUSMESSAGE)
      return "MailStatusMessage";
  
  else if(messageEnum == MessageEnum::NEWMAILMESSAGE)
      return "NewMailMessage";
  
  else if(messageEnum == MessageEnum::HAAPIAPIKEYMESSAGE)
      return "HaapiApiKeyMessage";
  
  else if(messageEnum == MessageEnum::HAAPIAPIKEYREQUESTMESSAGE)
      return "HaapiApiKeyRequestMessage";
  
  else if(messageEnum == MessageEnum::KROSMASTERAUTHTOKENERRORMESSAGE)
      return "KrosmasterAuthTokenErrorMessage";
  
  else if(messageEnum == MessageEnum::KROSMASTERAUTHTOKENMESSAGE)
      return "KrosmasterAuthTokenMessage";
  
  else if(messageEnum == MessageEnum::KROSMASTERAUTHTOKENREQUESTMESSAGE)
      return "KrosmasterAuthTokenRequestMessage";
  
  else if(messageEnum == MessageEnum::KROSMASTERINVENTORYERRORMESSAGE)
      return "KrosmasterInventoryErrorMessage";
  
  else if(messageEnum == MessageEnum::KROSMASTERINVENTORYMESSAGE)
      return "KrosmasterInventoryMessage";
  
  else if(messageEnum == MessageEnum::KROSMASTERINVENTORYREQUESTMESSAGE)
      return "KrosmasterInventoryRequestMessage";
  
  else if(messageEnum == MessageEnum::KROSMASTERPLAYINGSTATUSMESSAGE)
      return "KrosmasterPlayingStatusMessage";
  
  else if(messageEnum == MessageEnum::KROSMASTERTRANSFERMESSAGE)
      return "KrosmasterTransferMessage";
  
  else if(messageEnum == MessageEnum::KROSMASTERTRANSFERREQUESTMESSAGE)
      return "KrosmasterTransferRequestMessage";
  
  else if(messageEnum == MessageEnum::CLIENTYOUAREDRUNKMESSAGE)
      return "ClientYouAreDrunkMessage";
  
  else
  {
    qDebug()<<"ERREUR - MessageUtils - Ne connait pas l'enum :"<<(int)messageEnum;
    return "";
  }
}

