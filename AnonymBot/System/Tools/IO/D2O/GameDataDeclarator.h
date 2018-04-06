#ifndef GAMEDATADECLARATOR_H
#define GAMEDATADECLARATOR_H

#include "System/Tools/IO/D2O/Data/abuse/AbuseReasonsData.h"
#include "System/Tools/IO/D2O/Data/alignments/AlignmentBalanceData.h"
#include "System/Tools/IO/D2O/Data/alignments/AlignmentEffectData.h"
#include "System/Tools/IO/D2O/Data/alignments/AlignmentGiftData.h"
#include "System/Tools/IO/D2O/Data/alignments/AlignmentOrderData.h"
#include "System/Tools/IO/D2O/Data/alignments/AlignmentRankData.h"
#include "System/Tools/IO/D2O/Data/alignments/AlignmentRankJntGiftData.h"
#include "System/Tools/IO/D2O/Data/alignments/AlignmentSideData.h"
#include "System/Tools/IO/D2O/Data/alignments/AlignmentTitleData.h"
#include "System/Tools/IO/D2O/Data/almanax/AlmanaxCalendarData.h"
#include "System/Tools/IO/D2O/Data/ambientSounds/AmbientSoundData.h"
#include "System/Tools/IO/D2O/Data/ambientSounds/PlaylistSoundData.h"
#include "System/Tools/IO/D2O/Data/appearance/AppearanceData.h"
#include "System/Tools/IO/D2O/Data/appearance/CreatureBoneOverrideData.h"
#include "System/Tools/IO/D2O/Data/appearance/CreatureBoneTypeData.h"
#include "System/Tools/IO/D2O/Data/appearance/OrnamentData.h"
#include "System/Tools/IO/D2O/Data/appearance/SkinMappingData.h"
#include "System/Tools/IO/D2O/Data/appearance/SkinPositionData.h"
#include "System/Tools/IO/D2O/Data/appearance/TitleData.h"
#include "System/Tools/IO/D2O/Data/appearance/TitleCategoryData.h"
#include "System/Tools/IO/D2O/Data/bonus/BonusData.h"
#include "System/Tools/IO/D2O/Data/bonus/criterion/BonusCriterionData.h"
#include "System/Tools/IO/D2O/Data/breeds/BreedData.h"
#include "System/Tools/IO/D2O/Data/breeds/BreedRoleData.h"
#include "System/Tools/IO/D2O/Data/breeds/BreedRoleByBreedData.h"
#include "System/Tools/IO/D2O/Data/breeds/HeadData.h"
#include "System/Tools/IO/D2O/Data/challenges/ChallengeData.h"
#include "System/Tools/IO/D2O/Data/characteristics/CharacteristicData.h"
#include "System/Tools/IO/D2O/Data/characteristics/CharacteristicCategoryData.h"
#include "System/Tools/IO/D2O/Data/communication/CensoredWordData.h"
#include "System/Tools/IO/D2O/Data/communication/ChatChannelData.h"
#include "System/Tools/IO/D2O/Data/communication/EmoticonData.h"
#include "System/Tools/IO/D2O/Data/communication/InfoMessageData.h"
#include "System/Tools/IO/D2O/Data/communication/SmileyData.h"
#include "System/Tools/IO/D2O/Data/communication/SmileyCategoryData.h"
#include "System/Tools/IO/D2O/Data/communication/SmileyPackData.h"
#include "System/Tools/IO/D2O/Data/dare/DareCriteriaData.h"
#include "System/Tools/IO/D2O/Data/documents/ComicData.h"
#include "System/Tools/IO/D2O/Data/documents/DocumentData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceCreatureData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceDateData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceDiceData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceDurationData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceIntegerData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceLadderData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceMinMaxData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceMountData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceStringData.h"
#include "System/Tools/IO/D2O/Data/externalnotifications/ExternalNotificationData.h"
#include "System/Tools/IO/D2O/Data/guild/EmblemBackgroundData.h"
#include "System/Tools/IO/D2O/Data/guild/EmblemSymbolData.h"
#include "System/Tools/IO/D2O/Data/guild/EmblemSymbolCategoryData.h"
#include "System/Tools/IO/D2O/Data/guild/RankNameData.h"
#include "System/Tools/IO/D2O/Data/houses/HavenbagFurnitureData.h"
#include "System/Tools/IO/D2O/Data/houses/HavenbagThemeData.h"
#include "System/Tools/IO/D2O/Data/houses/HouseData.h"
#include "System/Tools/IO/D2O/Data/idols/IdolData.h"
#include "System/Tools/IO/D2O/Data/interactives/InteractiveData.h"
#include "System/Tools/IO/D2O/Data/interactives/SkillNameData.h"
#include "System/Tools/IO/D2O/Data/interactives/StealthBonesData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/AccountRightsItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/AchievementItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/AlignmentItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/AlignmentLevelItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/AllianceAvAItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/AllianceItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/AllianceRightsItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/AreaItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ArenaMaxSoloRankCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ArenaMaxTeamRankCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ArenaSoloRankCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ArenaTeamRankCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/BonesItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/BonusSetItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/BreedItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/CommunityItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/DayItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/EmoteItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/FriendlistItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/GiftItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/GroupItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/GuildItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/GuildLevelItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/GuildRightsItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ItemCriterionFactoryData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ItemCriterionOperatorData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/JobItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/KamaItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/LevelItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/MapCharactersItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/MariedItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/MonthItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/MountFamilyItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/NameItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ObjectItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/PremiumAccountItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/PrestigeLevelItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/PVPRankItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/QuestItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/RideItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ServerItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/SexItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/SkillItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/SmileyPackItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/SoulStoneItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/SpecializationItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/SpellItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/StaticCriterionItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/SubareaItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/SubscribeItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/SubscriptionDurationItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/UnusableItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/WeightItemCriterionData.h"
#include "System/Tools/IO/D2O/Data/items/IncarnationData.h"
#include "System/Tools/IO/D2O/Data/items/IncarnationLevelData.h"
#include "System/Tools/IO/D2O/Data/items/ItemData.h"
#include "System/Tools/IO/D2O/Data/items/ItemSetData.h"
#include "System/Tools/IO/D2O/Data/items/ItemTypeData.h"
#include "System/Tools/IO/D2O/Data/items/PresetIconData.h"
#include "System/Tools/IO/D2O/Data/items/VeteranRewardData.h"
#include "System/Tools/IO/D2O/Data/items/WeaponData.h"
#include "System/Tools/IO/D2O/Data/jobs/JobData.h"
#include "System/Tools/IO/D2O/Data/jobs/RecipeData.h"
#include "System/Tools/IO/D2O/Data/jobs/SkillData.h"
#include "System/Tools/IO/D2O/Data/livingObjects/LivingObjectSkinJntMoodData.h"
#include "System/Tools/IO/D2O/Data/livingObjects/PetData.h"
#include "System/Tools/IO/D2O/Data/livingObjects/SpeakingItemsTriggerData.h"
#include "System/Tools/IO/D2O/Data/livingObjects/SpeakingItemTextData.h"
#include "System/Tools/IO/D2O/Data/misc/ActionDescriptionData.h"
#include "System/Tools/IO/D2O/Data/misc/CensoredContentData.h"
#include "System/Tools/IO/D2O/Data/misc/MonthData.h"
#include "System/Tools/IO/D2O/Data/misc/OptionalFeatureData.h"
#include "System/Tools/IO/D2O/Data/misc/PackData.h"
#include "System/Tools/IO/D2O/Data/misc/TipsData.h"
#include "System/Tools/IO/D2O/Data/misc/TypeActionData.h"
#include "System/Tools/IO/D2O/Data/misc/UrlData.h"
#include "System/Tools/IO/D2O/Data/monsters/CompanionData.h"
#include "System/Tools/IO/D2O/Data/monsters/CompanionCharacteristicData.h"
#include "System/Tools/IO/D2O/Data/monsters/CompanionSpellData.h"
#include "System/Tools/IO/D2O/Data/monsters/MonsterData.h"
#include "System/Tools/IO/D2O/Data/monsters/MonsterDropData.h"
#include "System/Tools/IO/D2O/Data/monsters/MonsterGradeData.h"
#include "System/Tools/IO/D2O/Data/monsters/MonsterMiniBossData.h"
#include "System/Tools/IO/D2O/Data/monsters/MonsterRaceData.h"
#include "System/Tools/IO/D2O/Data/monsters/MonsterSuperRaceData.h"
#include "System/Tools/IO/D2O/Data/mounts/MountData.h"
#include "System/Tools/IO/D2O/Data/mounts/MountBehaviorData.h"
#include "System/Tools/IO/D2O/Data/mounts/MountBoneData.h"
#include "System/Tools/IO/D2O/Data/mounts/MountFamilyData.h"
#include "System/Tools/IO/D2O/Data/mounts/RideFoodData.h"
#include "System/Tools/IO/D2O/Data/notifications/NotificationData.h"
#include "System/Tools/IO/D2O/Data/npcs/NpcData.h"
#include "System/Tools/IO/D2O/Data/npcs/NpcActionData.h"
#include "System/Tools/IO/D2O/Data/npcs/NpcMessageData.h"
#include "System/Tools/IO/D2O/Data/npcs/TaxCollectorFirstnameData.h"
#include "System/Tools/IO/D2O/Data/npcs/TaxCollectorNameData.h"
#include "System/Tools/IO/D2O/Data/playlists/PlaylistData.h"
#include "System/Tools/IO/D2O/Data/quest/AchievementData.h"
#include "System/Tools/IO/D2O/Data/quest/AchievementCategoryData.h"
#include "System/Tools/IO/D2O/Data/quest/AchievementObjectiveData.h"
#include "System/Tools/IO/D2O/Data/quest/AchievementRewardData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveBringItemToNpcData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveBringSoulToNpcData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveCraftItemData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveDiscoverMapData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveDiscoverSubAreaData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveDuelSpecificPlayerData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveFightMonsterData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveFightMonstersOnMapData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveFreeFormData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveGoToNpcData.h"
#include "System/Tools/IO/D2O/Data/quest/objectives/QuestObjectiveMultiFightMonsterData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestCategoryData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestObjectiveData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestObjectiveTypeData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestStepData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestStepRewardsData.h"
#include "System/Tools/IO/D2O/Data/quest/treasureHunt/LegendaryTreasureHuntData.h"
#include "System/Tools/IO/D2O/Data/quest/treasureHunt/PointOfInterestData.h"
#include "System/Tools/IO/D2O/Data/quest/treasureHunt/PointOfInterestCategoryData.h"
#include "System/Tools/IO/D2O/Data/servers/ServerData.h"
#include "System/Tools/IO/D2O/Data/servers/ServerCommunityData.h"
#include "System/Tools/IO/D2O/Data/servers/ServerGameTypeData.h"
#include "System/Tools/IO/D2O/Data/servers/ServerPopulationData.h"
#include "System/Tools/IO/D2O/Data/sounds/SoundAnimationData.h"
#include "System/Tools/IO/D2O/Data/sounds/SoundBonesData.h"
#include "System/Tools/IO/D2O/Data/sounds/SoundUiData.h"
#include "System/Tools/IO/D2O/Data/sounds/SoundUiElementData.h"
#include "System/Tools/IO/D2O/Data/sounds/SoundUiHookData.h"
#include "System/Tools/IO/D2O/Data/spells/FinishMoveData.h"
#include "System/Tools/IO/D2O/Data/spells/SpellData.h"
#include "System/Tools/IO/D2O/Data/spells/SpellBombData.h"
#include "System/Tools/IO/D2O/Data/spells/SpellLevelData.h"
#include "System/Tools/IO/D2O/Data/spells/SpellPairData.h"
#include "System/Tools/IO/D2O/Data/spells/SpellStateData.h"
#include "System/Tools/IO/D2O/Data/spells/SpellTypeData.h"
#include "System/Tools/IO/D2O/Data/world/AreaData.h"
#include "System/Tools/IO/D2O/Data/world/DungeonData.h"
#include "System/Tools/IO/D2O/Data/world/HintData.h"
#include "System/Tools/IO/D2O/Data/world/HintCategoryData.h"
#include "System/Tools/IO/D2O/Data/world/MapCoordinatesData.h"
#include "System/Tools/IO/D2O/Data/world/MapPositionData.h"
#include "System/Tools/IO/D2O/Data/world/MapReferenceData.h"
#include "System/Tools/IO/D2O/Data/world/MapScrollActionData.h"
#include "System/Tools/IO/D2O/Data/world/PhoenixData.h"
#include "System/Tools/IO/D2O/Data/world/SubAreaData.h"
#include "System/Tools/IO/D2O/Data/world/SuperAreaData.h"
#include "System/Tools/IO/D2O/Data/world/WaypointData.h"
#include "System/Tools/IO/D2O/Data/world/WorldMapData.h"

enum class GameDataEnum
{
    ABUSEREASONSDATA,
    ALIGNMENTBALANCEDATA,
    ALIGNMENTEFFECTDATA,
    ALIGNMENTGIFTDATA,
    ALIGNMENTORDERDATA,
    ALIGNMENTRANKDATA,
    ALIGNMENTRANKJNTGIFTDATA,
    ALIGNMENTSIDEDATA,
    ALIGNMENTTITLEDATA,
    ALMANAXCALENDARDATA,
    AMBIENTSOUNDDATA,
    PLAYLISTSOUNDDATA,
    APPEARANCEDATA,
    CREATUREBONEOVERRIDEDATA,
    CREATUREBONETYPEDATA,
    ORNAMENTDATA,
    SKINMAPPINGDATA,
    SKINPOSITIONDATA,
    TITLEDATA,
    TITLECATEGORYDATA,
    BONUSDATA,
    BONUSCRITERIONDATA,
    BREEDDATA,
    BREEDROLEDATA,
    BREEDROLEBYBREEDDATA,
    HEADDATA,
    CHALLENGEDATA,
    CHARACTERISTICDATA,
    CHARACTERISTICCATEGORYDATA,
    CENSOREDWORDDATA,
    CHATCHANNELDATA,
    EMOTICONDATA,
    INFOMESSAGEDATA,
    SMILEYDATA,
    SMILEYCATEGORYDATA,
    SMILEYPACKDATA,
    DARECRITERIADATA,
    COMICDATA,
    DOCUMENTDATA,
    EFFECTDATA,
    EFFECTINSTANCEDATA,
    EFFECTINSTANCECREATUREDATA,
    EFFECTINSTANCEDATEDATA,
    EFFECTINSTANCEDICEDATA,
    EFFECTINSTANCEDURATIONDATA,
    EFFECTINSTANCEINTEGERDATA,
    EFFECTINSTANCELADDERDATA,
    EFFECTINSTANCEMINMAXDATA,
    EFFECTINSTANCEMOUNTDATA,
    EFFECTINSTANCESTRINGDATA,
    EXTERNALNOTIFICATIONDATA,
    EMBLEMBACKGROUNDDATA,
    EMBLEMSYMBOLDATA,
    EMBLEMSYMBOLCATEGORYDATA,
    RANKNAMEDATA,
    HAVENBAGFURNITUREDATA,
    HAVENBAGTHEMEDATA,
    HOUSEDATA,
    IDOLDATA,
    INTERACTIVEDATA,
    SKILLNAMEDATA,
    STEALTHBONESDATA,
    ACCOUNTRIGHTSITEMCRITERIONDATA,
    ACHIEVEMENTITEMCRITERIONDATA,
    ALIGNMENTITEMCRITERIONDATA,
    ALIGNMENTLEVELITEMCRITERIONDATA,
    ALLIANCEAVAITEMCRITERIONDATA,
    ALLIANCEITEMCRITERIONDATA,
    ALLIANCERIGHTSITEMCRITERIONDATA,
    AREAITEMCRITERIONDATA,
    ARENAMAXSOLORANKCRITERIONDATA,
    ARENAMAXTEAMRANKCRITERIONDATA,
    ARENASOLORANKCRITERIONDATA,
    ARENATEAMRANKCRITERIONDATA,
    BONESITEMCRITERIONDATA,
    BONUSSETITEMCRITERIONDATA,
    BREEDITEMCRITERIONDATA,
    COMMUNITYITEMCRITERIONDATA,
    DAYITEMCRITERIONDATA,
    EMOTEITEMCRITERIONDATA,
    FRIENDLISTITEMCRITERIONDATA,
    GIFTITEMCRITERIONDATA,
    GROUPITEMCRITERIONDATA,
    GUILDITEMCRITERIONDATA,
    GUILDLEVELITEMCRITERIONDATA,
    GUILDRIGHTSITEMCRITERIONDATA,
    ITEMCRITERIONDATA,
    ITEMCRITERIONFACTORYDATA,
    ITEMCRITERIONOPERATORDATA,
    JOBITEMCRITERIONDATA,
    KAMAITEMCRITERIONDATA,
    LEVELITEMCRITERIONDATA,
    MAPCHARACTERSITEMCRITERIONDATA,
    MARIEDITEMCRITERIONDATA,
    MONTHITEMCRITERIONDATA,
    MOUNTFAMILYITEMCRITERIONDATA,
    NAMEITEMCRITERIONDATA,
    OBJECTITEMCRITERIONDATA,
    PREMIUMACCOUNTITEMCRITERIONDATA,
    PRESTIGELEVELITEMCRITERIONDATA,
    PVPRANKITEMCRITERIONDATA,
    QUESTITEMCRITERIONDATA,
    RIDEITEMCRITERIONDATA,
    SERVERITEMCRITERIONDATA,
    SEXITEMCRITERIONDATA,
    SKILLITEMCRITERIONDATA,
    SMILEYPACKITEMCRITERIONDATA,
    SOULSTONEITEMCRITERIONDATA,
    SPECIALIZATIONITEMCRITERIONDATA,
    SPELLITEMCRITERIONDATA,
    STATICCRITERIONITEMCRITERIONDATA,
    SUBAREAITEMCRITERIONDATA,
    SUBSCRIBEITEMCRITERIONDATA,
    SUBSCRIPTIONDURATIONITEMCRITERIONDATA,
    UNUSABLEITEMCRITERIONDATA,
    WEIGHTITEMCRITERIONDATA,
    INCARNATIONDATA,
    INCARNATIONLEVELDATA,
    ITEMDATA,
    ITEMSETDATA,
    ITEMTYPEDATA,
    PRESETICONDATA,
    VETERANREWARDDATA,
    WEAPONDATA,
    JOBDATA,
    RECIPEDATA,
    SKILLDATA,
    LIVINGOBJECTSKINJNTMOODDATA,
    PETDATA,
    SPEAKINGITEMSTRIGGERDATA,
    SPEAKINGITEMTEXTDATA,
    ACTIONDESCRIPTIONDATA,
    CENSOREDCONTENTDATA,
    MONTHDATA,
    OPTIONALFEATUREDATA,
    PACKDATA,
    TIPSDATA,
    TYPEACTIONDATA,
    URLDATA,
    COMPANIONDATA,
    COMPANIONCHARACTERISTICDATA,
    COMPANIONSPELLDATA,
    MONSTERDATA,
    MONSTERDROPDATA,
    MONSTERGRADEDATA,
    MONSTERMINIBOSSDATA,
    MONSTERRACEDATA,
    MONSTERSUPERRACEDATA,
    MOUNTDATA,
    MOUNTBEHAVIORDATA,
    MOUNTBONEDATA,
    MOUNTFAMILYDATA,
    RIDEFOODDATA,
    NOTIFICATIONDATA,
    NPCDATA,
    NPCACTIONDATA,
    NPCMESSAGEDATA,
    TAXCOLLECTORFIRSTNAMEDATA,
    TAXCOLLECTORNAMEDATA,
    PLAYLISTDATA,
    ACHIEVEMENTDATA,
    ACHIEVEMENTCATEGORYDATA,
    ACHIEVEMENTOBJECTIVEDATA,
    ACHIEVEMENTREWARDDATA,
    QUESTOBJECTIVEBRINGITEMTONPCDATA,
    QUESTOBJECTIVEBRINGSOULTONPCDATA,
    QUESTOBJECTIVECRAFTITEMDATA,
    QUESTOBJECTIVEDISCOVERMAPDATA,
    QUESTOBJECTIVEDISCOVERSUBAREADATA,
    QUESTOBJECTIVEDUELSPECIFICPLAYERDATA,
    QUESTOBJECTIVEFIGHTMONSTERDATA,
    QUESTOBJECTIVEFIGHTMONSTERSONMAPDATA,
    QUESTOBJECTIVEFREEFORMDATA,
    QUESTOBJECTIVEGOTONPCDATA,
    QUESTOBJECTIVEMULTIFIGHTMONSTERDATA,
    QUESTDATA,
    QUESTCATEGORYDATA,
    QUESTOBJECTIVEDATA,
    QUESTOBJECTIVETYPEDATA,
    QUESTSTEPDATA,
    QUESTSTEPREWARDSDATA,
    LEGENDARYTREASUREHUNTDATA,
    POINTOFINTERESTDATA,
    POINTOFINTERESTCATEGORYDATA,
    SERVERDATA,
    SERVERCOMMUNITYDATA,
    SERVERGAMETYPEDATA,
    SERVERPOPULATIONDATA,
    SOUNDANIMATIONDATA,
    SOUNDBONESDATA,
    SOUNDUIDATA,
    SOUNDUIELEMENTDATA,
    SOUNDUIHOOKDATA,
    FINISHMOVEDATA,
    SPELLDATA,
    SPELLBOMBDATA,
    SPELLLEVELDATA,
    SPELLPAIRDATA,
    SPELLSTATEDATA,
    SPELLTYPEDATA,
    AREADATA,
    DUNGEONDATA,
    HINTDATA,
    HINTCATEGORYDATA,
    MAPCOORDINATESDATA,
    MAPPOSITIONDATA,
    MAPREFERENCEDATA,
    MAPSCROLLACTIONDATA,
    PHOENIXDATA,
    SUBAREADATA,
    SUPERAREADATA,
    WAYPOINTDATA,
    WORLDMAPDATA
};

#endif // GAMEDATADECLARATOR_H