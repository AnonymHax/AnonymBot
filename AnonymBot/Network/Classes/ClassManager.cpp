#include "ClassManager.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberArenaInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterHardcoreOrEpicInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalGuildInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalAllianceInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookAndGradeInformations.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/Data/game/context/IdentifiedEntityDispositionInformations.h"
#include "Network/Classes/Data/game/context/FightEntityDispositionInformations.h"
#include "Network/Classes/Data/game/social/AbstractSocialGroupInfos.h"
#include "Network/Classes/Data/game/context/roleplay/BasicAllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/social/AllianceFactSheetInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/social/GuildFactSheetInformations.h"
#include "Network/Classes/Data/game/social/GuildInsiderFactSheetInformations.h"
#include "Network/Classes/Data/game/social/AlliancedGuildFactSheetInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInAllianceInformations.h"
#include "Network/Classes/Data/game/social/GuildVersatileInformations.h"
#include "Network/Classes/Data/game/social/GuildInAllianceVersatileInformations.h"
#include "Network/Classes/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "Network/Classes/Data/game/prism/PrismGeolocalizedInformation.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/prism/AllianceInsiderPrismInformation.h"
#include "Network/Classes/Data/game/prism/AlliancePrismInformation.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberCharacterInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberWithAllianceCharacterInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberCompanionInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberMonsterInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamMemberTaxCollectorInformations.h"
#include "Network/Classes/Data/game/context/fight/FightTeamInformations.h"
#include "Network/Classes/Data/game/context/fight/FightAllianceTeamInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightMinimalStats.h"
#include "Network/Classes/Data/game/context/fight/GameFightMinimalStatsPreparation.h"
#include "Network/Classes/Data/game/context/fight/FightResultListEntry.h"
#include "Network/Classes/Data/game/context/fight/FightResultFighterListEntry.h"
#include "Network/Classes/Data/game/context/fight/FightResultMutantListEntry.h"
#include "Network/Classes/Data/game/context/fight/FightResultPlayerListEntry.h"
#include "Network/Classes/Data/game/context/fight/FightResultTaxCollectorListEntry.h"
#include "Network/Classes/Data/game/context/fight/FightResultAdditionalData.h"
#include "Network/Classes/Data/game/context/fight/FightResultPvpData.h"
#include "Network/Classes/Data/game/context/fight/FightResultExperienceData.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporaryBoostEffect.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporaryBoostStateEffect.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporaryBoostWeaponDamagesEffect.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporarySpellBoostEffect.h"
#include "Network/Classes/Data/game/actions/fight/FightTemporarySpellImmunityEffect.h"
#include "Network/Classes/Data/game/actions/fight/FightTriggeredEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectInteger.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectCreature.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectLadder.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectDuration.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectDice.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectMinMax.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectString.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectMount.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectDate.h"
#include "Network/Classes/Data/game/mount/UpdateMountBoost.h"
#include "Network/Classes/Data/game/mount/UpdateMountIntBoost.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObject.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObjectIdolsPreset.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObjectItem.h"
#include "Network/Classes/Data/game/shortcut/ShortcutObjectPreset.h"
#include "Network/Classes/Data/game/shortcut/ShortcutSpell.h"
#include "Network/Classes/Data/game/shortcut/ShortcutEmote.h"
#include "Network/Classes/Data/game/shortcut/ShortcutSmiley.h"
#include "Network/Classes/Data/game/idol/Idol.h"
#include "Network/Classes/Data/game/idol/PartyIdol.h"
#include "Network/Classes/Data/game/friend/IgnoredInformations.h"
#include "Network/Classes/Data/game/friend/IgnoredOnlineInformations.h"
#include "Network/Classes/Data/game/friend/FriendInformations.h"
#include "Network/Classes/Data/game/friend/FriendOnlineInformations.h"
#include "Network/Classes/Data/game/friend/FriendSpouseInformations.h"
#include "Network/Classes/Data/game/friend/FriendSpouseOnlineInformations.h"
#include "Network/Classes/Data/game/interactive/InteractiveElementSkill.h"
#include "Network/Classes/Data/game/interactive/InteractiveElementNamedSkill.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/InteractiveElementWithAgeBonus.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescription.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescriptionTimed.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescriptionCollect.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescriptionCraft.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/house/HouseInformationsExtended.h"
#include "Network/Classes/Data/game/paddock/PaddockInformations.h"
#include "Network/Classes/Data/game/paddock/PaddockBuyableInformations.h"
#include "Network/Classes/Data/game/paddock/PaddockAbandonnedInformations.h"
#include "Network/Classes/Data/game/paddock/PaddockPrivateInformations.h"
#include "Network/Classes/Data/game/paddock/PaddockContentInformations.h"
#include "Network/Classes/Data/game/context/GameContextActorInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightAIInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightMonsterInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightMonsterWithAlignmentInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightTaxCollectorInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterNamedInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightMutantInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightCharacterInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightCompanionInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNamedActorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayHumanoidInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayMutantInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayCharacterInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayMerchantInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayMountInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNpcInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayNpcWithQuestInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayGroupMonsterInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayGroupMonsterWaveInformations.h"
#include "Network/Classes/Data/game/context/GameRolePlayTaxCollectorInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayPrismInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayPortalInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayTreasureHintInformations.h"
#include "Network/Classes/Data/game/context/roleplay/HumanInformations.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOptionAlliance.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOptionSkillUse.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOptionOrnament.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOptionFollowers.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOptionObjectUse.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOptionGuild.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOptionTitle.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOptionEmote.h"
#include "Network/Classes/Data/game/context/TaxCollectorStaticInformations.h"
#include "Network/Classes/Data/game/context/TaxCollectorStaticExtendedInformations.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorInformations.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorLootInformations.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorWaitingForHelpInformations.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorGuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GroupMonsterStaticInformationsWithAlternatives.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestActiveDetailedInformations.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestObjectiveInformationsWithCompletion.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterLightInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterNamedLightInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterMonsterLightInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterCompanionLightInformations.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterTaxCollectorLightInformations.h"
#include "Network/Classes/Data/game/context/MapCoordinates.h"
#include "Network/Classes/Data/game/context/MapCoordinatesAndId.h"
#include "Network/Classes/Data/game/context/MapCoordinatesExtended.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStepFight.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirection.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStepDig.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToPOI.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStepFollowDirectionToHint.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/PortalInformation.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/character/status/PlayerStatusExtended.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstant.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstantString.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstantInteger.h"
#include "Network/Classes/Data/game/approach/ServerSessionConstantLong.h"
#include "Network/Classes/Data/common/basic/StatisticData.h"
#include "Network/Classes/Data/common/basic/StatisticDataShort.h"
#include "Network/Classes/Data/common/basic/StatisticDataString.h"
#include "Network/Classes/Data/common/basic/StatisticDataByte.h"
#include "Network/Classes/Data/common/basic/StatisticDataInt.h"
#include "Network/Classes/Data/common/basic/StatisticDataBoolean.h"

QSharedPointer<AbstractClass> ClassManager::getClass(int classId)
{
  switch(classId)
  {
    default:
    {
      qDebug()<<"ERREUR - ClassManager - Ne connait de classe possedant l'id"<<classId;
      return QSharedPointer<AbstractClass>();
    }
    
    case 163:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookInformations());
    
    case 45:
      return QSharedPointer<AbstractClass>(new CharacterBaseInformations());
    
    case 90:
      return QSharedPointer<AbstractClass>(new PartyMemberInformations());
    
    case 391:
      return QSharedPointer<AbstractClass>(new PartyMemberArenaInformations());
    
    case 376:
      return QSharedPointer<AbstractClass>(new PartyInvitationMemberInformations());
    
    case 474:
      return QSharedPointer<AbstractClass>(new CharacterHardcoreOrEpicInformations());
    
    case 445:
      return QSharedPointer<AbstractClass>(new CharacterMinimalGuildInformations());
    
    case 444:
      return QSharedPointer<AbstractClass>(new CharacterMinimalAllianceInformations());
    
    case 193:
      return QSharedPointer<AbstractClass>(new CharacterMinimalPlusLookAndGradeInformations());
    
    case 60:
      return QSharedPointer<AbstractClass>(new EntityDispositionInformations());
    
    case 107:
      return QSharedPointer<AbstractClass>(new IdentifiedEntityDispositionInformations());
    
    case 217:
      return QSharedPointer<AbstractClass>(new FightEntityDispositionInformations());
    
    case 416:
      return QSharedPointer<AbstractClass>(new AbstractSocialGroupInfos());
    
    case 419:
      return QSharedPointer<AbstractClass>(new BasicAllianceInformations());
    
    case 418:
      return QSharedPointer<AbstractClass>(new BasicNamedAllianceInformations());
    
    case 417:
      return QSharedPointer<AbstractClass>(new AllianceInformations());
    
    case 421:
      return QSharedPointer<AbstractClass>(new AllianceFactSheetInformations());
    
    case 365:
      return QSharedPointer<AbstractClass>(new BasicGuildInformations());
    
    case 127:
      return QSharedPointer<AbstractClass>(new GuildInformations());
    
    case 424:
      return QSharedPointer<AbstractClass>(new GuildFactSheetInformations());
    
    case 423:
      return QSharedPointer<AbstractClass>(new GuildInsiderFactSheetInformations());
    
    case 422:
      return QSharedPointer<AbstractClass>(new AlliancedGuildFactSheetInformations());
    
    case 420:
      return QSharedPointer<AbstractClass>(new GuildInAllianceInformations());
    
    case 435:
      return QSharedPointer<AbstractClass>(new GuildVersatileInformations());
    
    case 437:
      return QSharedPointer<AbstractClass>(new GuildInAllianceVersatileInformations());
    
    case 438:
      return QSharedPointer<AbstractClass>(new PrismSubareaEmptyInfo());
    
    case 434:
      return QSharedPointer<AbstractClass>(new PrismGeolocalizedInformation());
    
    case 428:
      return QSharedPointer<AbstractClass>(new PrismInformation());
    
    case 431:
      return QSharedPointer<AbstractClass>(new AllianceInsiderPrismInformation());
    
    case 427:
      return QSharedPointer<AbstractClass>(new AlliancePrismInformation());
    
    case 44:
      return QSharedPointer<AbstractClass>(new FightTeamMemberInformations());
    
    case 13:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCharacterInformations());
    
    case 426:
      return QSharedPointer<AbstractClass>(new FightTeamMemberWithAllianceCharacterInformations());
    
    case 451:
      return QSharedPointer<AbstractClass>(new FightTeamMemberCompanionInformations());
    
    case 6:
      return QSharedPointer<AbstractClass>(new FightTeamMemberMonsterInformations());
    
    case 177:
      return QSharedPointer<AbstractClass>(new FightTeamMemberTaxCollectorInformations());
    
    case 33:
      return QSharedPointer<AbstractClass>(new FightTeamInformations());
    
    case 439:
      return QSharedPointer<AbstractClass>(new FightAllianceTeamInformations());
    
    case 31:
      return QSharedPointer<AbstractClass>(new GameFightMinimalStats());
    
    case 360:
      return QSharedPointer<AbstractClass>(new GameFightMinimalStatsPreparation());
    
    case 16:
      return QSharedPointer<AbstractClass>(new FightResultListEntry());
    
    case 189:
      return QSharedPointer<AbstractClass>(new FightResultFighterListEntry());
    
    case 216:
      return QSharedPointer<AbstractClass>(new FightResultMutantListEntry());
    
    case 24:
      return QSharedPointer<AbstractClass>(new FightResultPlayerListEntry());
    
    case 84:
      return QSharedPointer<AbstractClass>(new FightResultTaxCollectorListEntry());
    
    case 191:
      return QSharedPointer<AbstractClass>(new FightResultAdditionalData());
    
    case 190:
      return QSharedPointer<AbstractClass>(new FightResultPvpData());
    
    case 192:
      return QSharedPointer<AbstractClass>(new FightResultExperienceData());
    
    case 206:
      return QSharedPointer<AbstractClass>(new AbstractFightDispellableEffect());
    
    case 209:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostEffect());
    
    case 214:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostStateEffect());
    
    case 211:
      return QSharedPointer<AbstractClass>(new FightTemporaryBoostWeaponDamagesEffect());
    
    case 207:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellBoostEffect());
    
    case 366:
      return QSharedPointer<AbstractClass>(new FightTemporarySpellImmunityEffect());
    
    case 210:
      return QSharedPointer<AbstractClass>(new FightTriggeredEffect());
    
    case 76:
      return QSharedPointer<AbstractClass>(new ObjectEffect());
    
    case 70:
      return QSharedPointer<AbstractClass>(new ObjectEffectInteger());
    
    case 71:
      return QSharedPointer<AbstractClass>(new ObjectEffectCreature());
    
    case 81:
      return QSharedPointer<AbstractClass>(new ObjectEffectLadder());
    
    case 75:
      return QSharedPointer<AbstractClass>(new ObjectEffectDuration());
    
    case 73:
      return QSharedPointer<AbstractClass>(new ObjectEffectDice());
    
    case 82:
      return QSharedPointer<AbstractClass>(new ObjectEffectMinMax());
    
    case 74:
      return QSharedPointer<AbstractClass>(new ObjectEffectString());
    
    case 179:
      return QSharedPointer<AbstractClass>(new ObjectEffectMount());
    
    case 72:
      return QSharedPointer<AbstractClass>(new ObjectEffectDate());
    
    case 356:
      return QSharedPointer<AbstractClass>(new UpdateMountBoost());
    
    case 357:
      return QSharedPointer<AbstractClass>(new UpdateMountIntBoost());
    
    case 369:
      return QSharedPointer<AbstractClass>(new Shortcut());
    
    case 367:
      return QSharedPointer<AbstractClass>(new ShortcutObject());
    
    case 492:
      return QSharedPointer<AbstractClass>(new ShortcutObjectIdolsPreset());
    
    case 371:
      return QSharedPointer<AbstractClass>(new ShortcutObjectItem());
    
    case 370:
      return QSharedPointer<AbstractClass>(new ShortcutObjectPreset());
    
    case 368:
      return QSharedPointer<AbstractClass>(new ShortcutSpell());
    
    case 389:
      return QSharedPointer<AbstractClass>(new ShortcutEmote());
    
    case 388:
      return QSharedPointer<AbstractClass>(new ShortcutSmiley());
    
    case 489:
      return QSharedPointer<AbstractClass>(new Idol());
    
    case 490:
      return QSharedPointer<AbstractClass>(new PartyIdol());
    
    case 106:
      return QSharedPointer<AbstractClass>(new IgnoredInformations());
    
    case 105:
      return QSharedPointer<AbstractClass>(new IgnoredOnlineInformations());
    
    case 78:
      return QSharedPointer<AbstractClass>(new FriendInformations());
    
    case 92:
      return QSharedPointer<AbstractClass>(new FriendOnlineInformations());
    
    case 77:
      return QSharedPointer<AbstractClass>(new FriendSpouseInformations());
    
    case 93:
      return QSharedPointer<AbstractClass>(new FriendSpouseOnlineInformations());
    
    case 219:
      return QSharedPointer<AbstractClass>(new InteractiveElementSkill());
    
    case 220:
      return QSharedPointer<AbstractClass>(new InteractiveElementNamedSkill());
    
    case 80:
      return QSharedPointer<AbstractClass>(new InteractiveElement());
    
    case 398:
      return QSharedPointer<AbstractClass>(new InteractiveElementWithAgeBonus());
    
    case 102:
      return QSharedPointer<AbstractClass>(new SkillActionDescription());
    
    case 103:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionTimed());
    
    case 99:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCollect());
    
    case 100:
      return QSharedPointer<AbstractClass>(new SkillActionDescriptionCraft());
    
    case 111:
      return QSharedPointer<AbstractClass>(new HouseInformations());
    
    case 112:
      return QSharedPointer<AbstractClass>(new HouseInformationsExtended());
    
    case 132:
      return QSharedPointer<AbstractClass>(new PaddockInformations());
    
    case 130:
      return QSharedPointer<AbstractClass>(new PaddockBuyableInformations());
    
    case 133:
      return QSharedPointer<AbstractClass>(new PaddockAbandonnedInformations());
    
    case 131:
      return QSharedPointer<AbstractClass>(new PaddockPrivateInformations());
    
    case 183:
      return QSharedPointer<AbstractClass>(new PaddockContentInformations());
    
    case 150:
      return QSharedPointer<AbstractClass>(new GameContextActorInformations());
    
    case 143:
      return QSharedPointer<AbstractClass>(new GameFightFighterInformations());
    
    case 151:
      return QSharedPointer<AbstractClass>(new GameFightAIInformations());
    
    case 29:
      return QSharedPointer<AbstractClass>(new GameFightMonsterInformations());
    
    case 203:
      return QSharedPointer<AbstractClass>(new GameFightMonsterWithAlignmentInformations());
    
    case 48:
      return QSharedPointer<AbstractClass>(new GameFightTaxCollectorInformations());
    
    case 158:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedInformations());
    
    case 50:
      return QSharedPointer<AbstractClass>(new GameFightMutantInformations());
    
    case 46:
      return QSharedPointer<AbstractClass>(new GameFightCharacterInformations());
    
    case 450:
      return QSharedPointer<AbstractClass>(new GameFightCompanionInformations());
    
    case 141:
      return QSharedPointer<AbstractClass>(new GameRolePlayActorInformations());
    
    case 154:
      return QSharedPointer<AbstractClass>(new GameRolePlayNamedActorInformations());
    
    case 159:
      return QSharedPointer<AbstractClass>(new GameRolePlayHumanoidInformations());
    
    case 3:
      return QSharedPointer<AbstractClass>(new GameRolePlayMutantInformations());
    
    case 36:
      return QSharedPointer<AbstractClass>(new GameRolePlayCharacterInformations());
    
    case 129:
      return QSharedPointer<AbstractClass>(new GameRolePlayMerchantInformations());
    
    case 180:
      return QSharedPointer<AbstractClass>(new GameRolePlayMountInformations());
    
    case 156:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcInformations());
    
    case 383:
      return QSharedPointer<AbstractClass>(new GameRolePlayNpcWithQuestInformations());
    
    case 160:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterInformations());
    
    case 464:
      return QSharedPointer<AbstractClass>(new GameRolePlayGroupMonsterWaveInformations());
    
    case 148:
      return QSharedPointer<AbstractClass>(new GameRolePlayTaxCollectorInformations());
    
    case 161:
      return QSharedPointer<AbstractClass>(new GameRolePlayPrismInformations());
    
    case 467:
      return QSharedPointer<AbstractClass>(new GameRolePlayPortalInformations());
    
    case 471:
      return QSharedPointer<AbstractClass>(new GameRolePlayTreasureHintInformations());
    
    case 157:
      return QSharedPointer<AbstractClass>(new HumanInformations());
    
    case 406:
      return QSharedPointer<AbstractClass>(new HumanOption());
    
    case 425:
      return QSharedPointer<AbstractClass>(new HumanOptionAlliance());
    
    case 495:
      return QSharedPointer<AbstractClass>(new HumanOptionSkillUse());
    
    case 411:
      return QSharedPointer<AbstractClass>(new HumanOptionOrnament());
    
    case 410:
      return QSharedPointer<AbstractClass>(new HumanOptionFollowers());
    
    case 449:
      return QSharedPointer<AbstractClass>(new HumanOptionObjectUse());
    
    case 409:
      return QSharedPointer<AbstractClass>(new HumanOptionGuild());
    
    case 408:
      return QSharedPointer<AbstractClass>(new HumanOptionTitle());
    
    case 407:
      return QSharedPointer<AbstractClass>(new HumanOptionEmote());
    
    case 147:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticInformations());
    
    case 440:
      return QSharedPointer<AbstractClass>(new TaxCollectorStaticExtendedInformations());
    
    case 167:
      return QSharedPointer<AbstractClass>(new TaxCollectorInformations());
    
    case 448:
      return QSharedPointer<AbstractClass>(new TaxCollectorComplementaryInformations());
    
    case 372:
      return QSharedPointer<AbstractClass>(new TaxCollectorLootInformations());
    
    case 447:
      return QSharedPointer<AbstractClass>(new TaxCollectorWaitingForHelpInformations());
    
    case 446:
      return QSharedPointer<AbstractClass>(new TaxCollectorGuildInformations());
    
    case 140:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformations());
    
    case 396:
      return QSharedPointer<AbstractClass>(new GroupMonsterStaticInformationsWithAlternatives());
    
    case 381:
      return QSharedPointer<AbstractClass>(new QuestActiveInformations());
    
    case 382:
      return QSharedPointer<AbstractClass>(new QuestActiveDetailedInformations());
    
    case 385:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformations());
    
    case 386:
      return QSharedPointer<AbstractClass>(new QuestObjectiveInformationsWithCompletion());
    
    case 413:
      return QSharedPointer<AbstractClass>(new GameFightFighterLightInformations());
    
    case 456:
      return QSharedPointer<AbstractClass>(new GameFightFighterNamedLightInformations());
    
    case 455:
      return QSharedPointer<AbstractClass>(new GameFightFighterMonsterLightInformations());
    
    case 454:
      return QSharedPointer<AbstractClass>(new GameFightFighterCompanionLightInformations());
    
    case 457:
      return QSharedPointer<AbstractClass>(new GameFightFighterTaxCollectorLightInformations());
    
    case 174:
      return QSharedPointer<AbstractClass>(new MapCoordinates());
    
    case 392:
      return QSharedPointer<AbstractClass>(new MapCoordinatesAndId());
    
    case 176:
      return QSharedPointer<AbstractClass>(new MapCoordinatesExtended());
    
    case 463:
      return QSharedPointer<AbstractClass>(new TreasureHuntStep());
    
    case 462:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFight());
    
    case 468:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirection());
    
    case 465:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepDig());
    
    case 461:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToPOI());
    
    case 472:
      return QSharedPointer<AbstractClass>(new TreasureHuntStepFollowDirectionToHint());
    
    case 466:
      return QSharedPointer<AbstractClass>(new PortalInformation());
    
    case 415:
      return QSharedPointer<AbstractClass>(new PlayerStatus());
    
    case 414:
      return QSharedPointer<AbstractClass>(new PlayerStatusExtended());
    
    case 430:
      return QSharedPointer<AbstractClass>(new ServerSessionConstant());
    
    case 436:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantString());
    
    case 433:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantInteger());
    
    case 429:
      return QSharedPointer<AbstractClass>(new ServerSessionConstantLong());
    
    case 484:
      return QSharedPointer<AbstractClass>(new StatisticData());
    
    case 488:
      return QSharedPointer<AbstractClass>(new StatisticDataShort());
    
    case 487:
      return QSharedPointer<AbstractClass>(new StatisticDataString());
    
    case 486:
      return QSharedPointer<AbstractClass>(new StatisticDataByte());
    
    case 485:
      return QSharedPointer<AbstractClass>(new StatisticDataInt());
    
    case 482:
      return QSharedPointer<AbstractClass>(new StatisticDataBoolean());
    
  }
}

