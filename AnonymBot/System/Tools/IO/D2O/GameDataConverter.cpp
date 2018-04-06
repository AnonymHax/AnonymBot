#include "GameDataConverter.h"

QSharedPointer<AbstractGameData> GameDataConverter::getClass(const QString &name)
{
  if(name == "AbuseReasons")
      return QSharedPointer<AbstractGameData>(new AbuseReasonsData());
  
  else if(name == "AlignmentBalance")
      return QSharedPointer<AbstractGameData>(new AlignmentBalanceData());
  
  else if(name == "AlignmentEffect")
      return QSharedPointer<AbstractGameData>(new AlignmentEffectData());
  
  else if(name == "AlignmentGift")
      return QSharedPointer<AbstractGameData>(new AlignmentGiftData());
  
  else if(name == "AlignmentOrder")
      return QSharedPointer<AbstractGameData>(new AlignmentOrderData());
  
  else if(name == "AlignmentRank")
      return QSharedPointer<AbstractGameData>(new AlignmentRankData());
  
  else if(name == "AlignmentRankJntGift")
      return QSharedPointer<AbstractGameData>(new AlignmentRankJntGiftData());
  
  else if(name == "AlignmentSide")
      return QSharedPointer<AbstractGameData>(new AlignmentSideData());
  
  else if(name == "AlignmentTitle")
      return QSharedPointer<AbstractGameData>(new AlignmentTitleData());
  
  else if(name == "AlmanaxCalendar")
      return QSharedPointer<AbstractGameData>(new AlmanaxCalendarData());
  
  else if(name == "AmbientSound")
      return QSharedPointer<AbstractGameData>(new AmbientSoundData());
  
  else if(name == "PlaylistSound")
      return QSharedPointer<AbstractGameData>(new PlaylistSoundData());
  
  else if(name == "Appearance")
      return QSharedPointer<AbstractGameData>(new AppearanceData());
  
  else if(name == "CreatureBoneOverride")
      return QSharedPointer<AbstractGameData>(new CreatureBoneOverrideData());
  
  else if(name == "CreatureBoneType")
      return QSharedPointer<AbstractGameData>(new CreatureBoneTypeData());
  
  else if(name == "Ornament")
      return QSharedPointer<AbstractGameData>(new OrnamentData());
  
  else if(name == "SkinMapping")
      return QSharedPointer<AbstractGameData>(new SkinMappingData());
  
  else if(name == "SkinPosition")
      return QSharedPointer<AbstractGameData>(new SkinPositionData());
  
  else if(name == "Title")
      return QSharedPointer<AbstractGameData>(new TitleData());
  
  else if(name == "TitleCategory")
      return QSharedPointer<AbstractGameData>(new TitleCategoryData());
  
  else if(name == "Bonus")
      return QSharedPointer<AbstractGameData>(new BonusData());
  
  else if(name == "BonusCriterion")
      return QSharedPointer<AbstractGameData>(new BonusCriterionData());
  
  else if(name == "Breed")
      return QSharedPointer<AbstractGameData>(new BreedData());
  
  else if(name == "BreedRole")
      return QSharedPointer<AbstractGameData>(new BreedRoleData());
  
  else if(name == "BreedRoleByBreed")
      return QSharedPointer<AbstractGameData>(new BreedRoleByBreedData());
  
  else if(name == "Head")
      return QSharedPointer<AbstractGameData>(new HeadData());
  
  else if(name == "Challenge")
      return QSharedPointer<AbstractGameData>(new ChallengeData());
  
  else if(name == "Characteristic")
      return QSharedPointer<AbstractGameData>(new CharacteristicData());
  
  else if(name == "CharacteristicCategory")
      return QSharedPointer<AbstractGameData>(new CharacteristicCategoryData());
  
  else if(name == "CensoredWord")
      return QSharedPointer<AbstractGameData>(new CensoredWordData());
  
  else if(name == "ChatChannel")
      return QSharedPointer<AbstractGameData>(new ChatChannelData());
  
  else if(name == "Emoticon")
      return QSharedPointer<AbstractGameData>(new EmoticonData());
  
  else if(name == "InfoMessage")
      return QSharedPointer<AbstractGameData>(new InfoMessageData());
  
  else if(name == "Smiley")
      return QSharedPointer<AbstractGameData>(new SmileyData());
  
  else if(name == "SmileyCategory")
      return QSharedPointer<AbstractGameData>(new SmileyCategoryData());
  
  else if(name == "SmileyPack")
      return QSharedPointer<AbstractGameData>(new SmileyPackData());
  
  else if(name == "DareCriteria")
      return QSharedPointer<AbstractGameData>(new DareCriteriaData());
  
  else if(name == "Comic")
      return QSharedPointer<AbstractGameData>(new ComicData());
  
  else if(name == "Document")
      return QSharedPointer<AbstractGameData>(new DocumentData());
  
  else if(name == "Effect")
      return QSharedPointer<AbstractGameData>(new EffectData());
  
  else if(name == "EffectInstance")
      return QSharedPointer<AbstractGameData>(new EffectInstanceData());
  
  else if(name == "EffectInstanceCreature")
      return QSharedPointer<AbstractGameData>(new EffectInstanceCreatureData());
  
  else if(name == "EffectInstanceDate")
      return QSharedPointer<AbstractGameData>(new EffectInstanceDateData());
  
  else if(name == "EffectInstanceDice")
      return QSharedPointer<AbstractGameData>(new EffectInstanceDiceData());
  
  else if(name == "EffectInstanceDuration")
      return QSharedPointer<AbstractGameData>(new EffectInstanceDurationData());
  
  else if(name == "EffectInstanceInteger")
      return QSharedPointer<AbstractGameData>(new EffectInstanceIntegerData());
  
  else if(name == "EffectInstanceLadder")
      return QSharedPointer<AbstractGameData>(new EffectInstanceLadderData());
  
  else if(name == "EffectInstanceMinMax")
      return QSharedPointer<AbstractGameData>(new EffectInstanceMinMaxData());
  
  else if(name == "EffectInstanceMount")
      return QSharedPointer<AbstractGameData>(new EffectInstanceMountData());
  
  else if(name == "EffectInstanceString")
      return QSharedPointer<AbstractGameData>(new EffectInstanceStringData());
  
  else if(name == "ExternalNotification")
      return QSharedPointer<AbstractGameData>(new ExternalNotificationData());
  
  else if(name == "EmblemBackground")
      return QSharedPointer<AbstractGameData>(new EmblemBackgroundData());
  
  else if(name == "EmblemSymbol")
      return QSharedPointer<AbstractGameData>(new EmblemSymbolData());
  
  else if(name == "EmblemSymbolCategory")
      return QSharedPointer<AbstractGameData>(new EmblemSymbolCategoryData());
  
  else if(name == "RankName")
      return QSharedPointer<AbstractGameData>(new RankNameData());
  
  else if(name == "HavenbagFurniture")
      return QSharedPointer<AbstractGameData>(new HavenbagFurnitureData());
  
  else if(name == "HavenbagTheme")
      return QSharedPointer<AbstractGameData>(new HavenbagThemeData());
  
  else if(name == "House")
      return QSharedPointer<AbstractGameData>(new HouseData());
  
  else if(name == "Idol")
      return QSharedPointer<AbstractGameData>(new IdolData());
  
  else if(name == "Interactive")
      return QSharedPointer<AbstractGameData>(new InteractiveData());
  
  else if(name == "SkillName")
      return QSharedPointer<AbstractGameData>(new SkillNameData());
  
  else if(name == "StealthBones")
      return QSharedPointer<AbstractGameData>(new StealthBonesData());
  
  else if(name == "AccountRightsItemCriterion")
      return QSharedPointer<AbstractGameData>(new AccountRightsItemCriterionData());
  
  else if(name == "AchievementItemCriterion")
      return QSharedPointer<AbstractGameData>(new AchievementItemCriterionData());
  
  else if(name == "AlignmentItemCriterion")
      return QSharedPointer<AbstractGameData>(new AlignmentItemCriterionData());
  
  else if(name == "AlignmentLevelItemCriterion")
      return QSharedPointer<AbstractGameData>(new AlignmentLevelItemCriterionData());
  
  else if(name == "AllianceAvAItemCriterion")
      return QSharedPointer<AbstractGameData>(new AllianceAvAItemCriterionData());
  
  else if(name == "AllianceItemCriterion")
      return QSharedPointer<AbstractGameData>(new AllianceItemCriterionData());
  
  else if(name == "AllianceRightsItemCriterion")
      return QSharedPointer<AbstractGameData>(new AllianceRightsItemCriterionData());
  
  else if(name == "AreaItemCriterion")
      return QSharedPointer<AbstractGameData>(new AreaItemCriterionData());
  
  else if(name == "ArenaMaxSoloRankCriterion")
      return QSharedPointer<AbstractGameData>(new ArenaMaxSoloRankCriterionData());
  
  else if(name == "ArenaMaxTeamRankCriterion")
      return QSharedPointer<AbstractGameData>(new ArenaMaxTeamRankCriterionData());
  
  else if(name == "ArenaSoloRankCriterion")
      return QSharedPointer<AbstractGameData>(new ArenaSoloRankCriterionData());
  
  else if(name == "ArenaTeamRankCriterion")
      return QSharedPointer<AbstractGameData>(new ArenaTeamRankCriterionData());
  
  else if(name == "BonesItemCriterion")
      return QSharedPointer<AbstractGameData>(new BonesItemCriterionData());
  
  else if(name == "BonusSetItemCriterion")
      return QSharedPointer<AbstractGameData>(new BonusSetItemCriterionData());
  
  else if(name == "BreedItemCriterion")
      return QSharedPointer<AbstractGameData>(new BreedItemCriterionData());
  
  else if(name == "CommunityItemCriterion")
      return QSharedPointer<AbstractGameData>(new CommunityItemCriterionData());
  
  else if(name == "DayItemCriterion")
      return QSharedPointer<AbstractGameData>(new DayItemCriterionData());
  
  else if(name == "EmoteItemCriterion")
      return QSharedPointer<AbstractGameData>(new EmoteItemCriterionData());
  
  else if(name == "FriendlistItemCriterion")
      return QSharedPointer<AbstractGameData>(new FriendlistItemCriterionData());
  
  else if(name == "GiftItemCriterion")
      return QSharedPointer<AbstractGameData>(new GiftItemCriterionData());
  
  else if(name == "GroupItemCriterion")
      return QSharedPointer<AbstractGameData>(new GroupItemCriterionData());
  
  else if(name == "GuildItemCriterion")
      return QSharedPointer<AbstractGameData>(new GuildItemCriterionData());
  
  else if(name == "GuildLevelItemCriterion")
      return QSharedPointer<AbstractGameData>(new GuildLevelItemCriterionData());
  
  else if(name == "GuildRightsItemCriterion")
      return QSharedPointer<AbstractGameData>(new GuildRightsItemCriterionData());
  
  else if(name == "ItemCriterion")
      return QSharedPointer<AbstractGameData>(new ItemCriterionData());
  
  else if(name == "ItemCriterionFactory")
      return QSharedPointer<AbstractGameData>(new ItemCriterionFactoryData());
  
  else if(name == "ItemCriterionOperator")
      return QSharedPointer<AbstractGameData>(new ItemCriterionOperatorData());
  
  else if(name == "JobItemCriterion")
      return QSharedPointer<AbstractGameData>(new JobItemCriterionData());
  
  else if(name == "KamaItemCriterion")
      return QSharedPointer<AbstractGameData>(new KamaItemCriterionData());
  
  else if(name == "LevelItemCriterion")
      return QSharedPointer<AbstractGameData>(new LevelItemCriterionData());
  
  else if(name == "MapCharactersItemCriterion")
      return QSharedPointer<AbstractGameData>(new MapCharactersItemCriterionData());
  
  else if(name == "MariedItemCriterion")
      return QSharedPointer<AbstractGameData>(new MariedItemCriterionData());
  
  else if(name == "MonthItemCriterion")
      return QSharedPointer<AbstractGameData>(new MonthItemCriterionData());
  
  else if(name == "MountFamilyItemCriterion")
      return QSharedPointer<AbstractGameData>(new MountFamilyItemCriterionData());
  
  else if(name == "NameItemCriterion")
      return QSharedPointer<AbstractGameData>(new NameItemCriterionData());
  
  else if(name == "ObjectItemCriterion")
      return QSharedPointer<AbstractGameData>(new ObjectItemCriterionData());
  
  else if(name == "PremiumAccountItemCriterion")
      return QSharedPointer<AbstractGameData>(new PremiumAccountItemCriterionData());
  
  else if(name == "PrestigeLevelItemCriterion")
      return QSharedPointer<AbstractGameData>(new PrestigeLevelItemCriterionData());
  
  else if(name == "PVPRankItemCriterion")
      return QSharedPointer<AbstractGameData>(new PVPRankItemCriterionData());
  
  else if(name == "QuestItemCriterion")
      return QSharedPointer<AbstractGameData>(new QuestItemCriterionData());
  
  else if(name == "RideItemCriterion")
      return QSharedPointer<AbstractGameData>(new RideItemCriterionData());
  
  else if(name == "ServerItemCriterion")
      return QSharedPointer<AbstractGameData>(new ServerItemCriterionData());
  
  else if(name == "SexItemCriterion")
      return QSharedPointer<AbstractGameData>(new SexItemCriterionData());
  
  else if(name == "SkillItemCriterion")
      return QSharedPointer<AbstractGameData>(new SkillItemCriterionData());
  
  else if(name == "SmileyPackItemCriterion")
      return QSharedPointer<AbstractGameData>(new SmileyPackItemCriterionData());
  
  else if(name == "SoulStoneItemCriterion")
      return QSharedPointer<AbstractGameData>(new SoulStoneItemCriterionData());
  
  else if(name == "SpecializationItemCriterion")
      return QSharedPointer<AbstractGameData>(new SpecializationItemCriterionData());
  
  else if(name == "SpellItemCriterion")
      return QSharedPointer<AbstractGameData>(new SpellItemCriterionData());
  
  else if(name == "StaticCriterionItemCriterion")
      return QSharedPointer<AbstractGameData>(new StaticCriterionItemCriterionData());
  
  else if(name == "SubareaItemCriterion")
      return QSharedPointer<AbstractGameData>(new SubareaItemCriterionData());
  
  else if(name == "SubscribeItemCriterion")
      return QSharedPointer<AbstractGameData>(new SubscribeItemCriterionData());
  
  else if(name == "SubscriptionDurationItemCriterion")
      return QSharedPointer<AbstractGameData>(new SubscriptionDurationItemCriterionData());
  
  else if(name == "UnusableItemCriterion")
      return QSharedPointer<AbstractGameData>(new UnusableItemCriterionData());
  
  else if(name == "WeightItemCriterion")
      return QSharedPointer<AbstractGameData>(new WeightItemCriterionData());
  
  else if(name == "Incarnation")
      return QSharedPointer<AbstractGameData>(new IncarnationData());
  
  else if(name == "IncarnationLevel")
      return QSharedPointer<AbstractGameData>(new IncarnationLevelData());
  
  else if(name == "Item")
      return QSharedPointer<AbstractGameData>(new ItemData());
  
  else if(name == "ItemSet")
      return QSharedPointer<AbstractGameData>(new ItemSetData());
  
  else if(name == "ItemType")
      return QSharedPointer<AbstractGameData>(new ItemTypeData());
  
  else if(name == "PresetIcon")
      return QSharedPointer<AbstractGameData>(new PresetIconData());
  
  else if(name == "VeteranReward")
      return QSharedPointer<AbstractGameData>(new VeteranRewardData());
  
  else if(name == "Weapon")
      return QSharedPointer<AbstractGameData>(new WeaponData());
  
  else if(name == "Job")
      return QSharedPointer<AbstractGameData>(new JobData());
  
  else if(name == "Recipe")
      return QSharedPointer<AbstractGameData>(new RecipeData());
  
  else if(name == "Skill")
      return QSharedPointer<AbstractGameData>(new SkillData());
  
  else if(name == "LivingObjectSkinJntMood")
      return QSharedPointer<AbstractGameData>(new LivingObjectSkinJntMoodData());
  
  else if(name == "Pet")
      return QSharedPointer<AbstractGameData>(new PetData());
  
  else if(name == "SpeakingItemsTrigger")
      return QSharedPointer<AbstractGameData>(new SpeakingItemsTriggerData());
  
  else if(name == "SpeakingItemText")
      return QSharedPointer<AbstractGameData>(new SpeakingItemTextData());
  
  else if(name == "ActionDescription")
      return QSharedPointer<AbstractGameData>(new ActionDescriptionData());
  
  else if(name == "CensoredContent")
      return QSharedPointer<AbstractGameData>(new CensoredContentData());
  
  else if(name == "Month")
      return QSharedPointer<AbstractGameData>(new MonthData());
  
  else if(name == "OptionalFeature")
      return QSharedPointer<AbstractGameData>(new OptionalFeatureData());
  
  else if(name == "Pack")
      return QSharedPointer<AbstractGameData>(new PackData());
  
  else if(name == "Tips")
      return QSharedPointer<AbstractGameData>(new TipsData());
  
  else if(name == "TypeAction")
      return QSharedPointer<AbstractGameData>(new TypeActionData());
  
  else if(name == "Url")
      return QSharedPointer<AbstractGameData>(new UrlData());
  
  else if(name == "Companion")
      return QSharedPointer<AbstractGameData>(new CompanionData());
  
  else if(name == "CompanionCharacteristic")
      return QSharedPointer<AbstractGameData>(new CompanionCharacteristicData());
  
  else if(name == "CompanionSpell")
      return QSharedPointer<AbstractGameData>(new CompanionSpellData());
  
  else if(name == "Monster")
      return QSharedPointer<AbstractGameData>(new MonsterData());
  
  else if(name == "MonsterDrop")
      return QSharedPointer<AbstractGameData>(new MonsterDropData());
  
  else if(name == "MonsterGrade")
      return QSharedPointer<AbstractGameData>(new MonsterGradeData());
  
  else if(name == "MonsterMiniBoss")
      return QSharedPointer<AbstractGameData>(new MonsterMiniBossData());
  
  else if(name == "MonsterRace")
      return QSharedPointer<AbstractGameData>(new MonsterRaceData());
  
  else if(name == "MonsterSuperRace")
      return QSharedPointer<AbstractGameData>(new MonsterSuperRaceData());
  
  else if(name == "Mount")
      return QSharedPointer<AbstractGameData>(new MountData());
  
  else if(name == "MountBehavior")
      return QSharedPointer<AbstractGameData>(new MountBehaviorData());
  
  else if(name == "MountBone")
      return QSharedPointer<AbstractGameData>(new MountBoneData());
  
  else if(name == "MountFamily")
      return QSharedPointer<AbstractGameData>(new MountFamilyData());
  
  else if(name == "RideFood")
      return QSharedPointer<AbstractGameData>(new RideFoodData());
  
  else if(name == "Notification")
      return QSharedPointer<AbstractGameData>(new NotificationData());
  
  else if(name == "Npc")
      return QSharedPointer<AbstractGameData>(new NpcData());
  
  else if(name == "NpcAction")
      return QSharedPointer<AbstractGameData>(new NpcActionData());
  
  else if(name == "NpcMessage")
      return QSharedPointer<AbstractGameData>(new NpcMessageData());
  
  else if(name == "TaxCollectorFirstname")
      return QSharedPointer<AbstractGameData>(new TaxCollectorFirstnameData());
  
  else if(name == "TaxCollectorName")
      return QSharedPointer<AbstractGameData>(new TaxCollectorNameData());
  
  else if(name == "Playlist")
      return QSharedPointer<AbstractGameData>(new PlaylistData());
  
  else if(name == "Achievement")
      return QSharedPointer<AbstractGameData>(new AchievementData());
  
  else if(name == "AchievementCategory")
      return QSharedPointer<AbstractGameData>(new AchievementCategoryData());
  
  else if(name == "AchievementObjective")
      return QSharedPointer<AbstractGameData>(new AchievementObjectiveData());
  
  else if(name == "AchievementReward")
      return QSharedPointer<AbstractGameData>(new AchievementRewardData());
  
  else if(name == "QuestObjectiveBringItemToNpc")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveBringItemToNpcData());
  
  else if(name == "QuestObjectiveBringSoulToNpc")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveBringSoulToNpcData());
  
  else if(name == "QuestObjectiveCraftItem")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveCraftItemData());
  
  else if(name == "QuestObjectiveDiscoverMap")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveDiscoverMapData());
  
  else if(name == "QuestObjectiveDiscoverSubArea")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveDiscoverSubAreaData());
  
  else if(name == "QuestObjectiveDuelSpecificPlayer")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveDuelSpecificPlayerData());
  
  else if(name == "QuestObjectiveFightMonster")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveFightMonsterData());
  
  else if(name == "QuestObjectiveFightMonstersOnMap")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveFightMonstersOnMapData());
  
  else if(name == "QuestObjectiveFreeForm")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveFreeFormData());
  
  else if(name == "QuestObjectiveGoToNpc")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveGoToNpcData());
  
  else if(name == "QuestObjectiveMultiFightMonster")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveMultiFightMonsterData());
  
  else if(name == "Quest")
      return QSharedPointer<AbstractGameData>(new QuestData());
  
  else if(name == "QuestCategory")
      return QSharedPointer<AbstractGameData>(new QuestCategoryData());
  
  else if(name == "QuestObjective")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveData());
  
  else if(name == "QuestObjectiveType")
      return QSharedPointer<AbstractGameData>(new QuestObjectiveTypeData());
  
  else if(name == "QuestStep")
      return QSharedPointer<AbstractGameData>(new QuestStepData());
  
  else if(name == "QuestStepRewards")
      return QSharedPointer<AbstractGameData>(new QuestStepRewardsData());
  
  else if(name == "LegendaryTreasureHunt")
      return QSharedPointer<AbstractGameData>(new LegendaryTreasureHuntData());
  
  else if(name == "PointOfInterest")
      return QSharedPointer<AbstractGameData>(new PointOfInterestData());
  
  else if(name == "PointOfInterestCategory")
      return QSharedPointer<AbstractGameData>(new PointOfInterestCategoryData());
  
  else if(name == "Server")
      return QSharedPointer<AbstractGameData>(new ServerData());
  
  else if(name == "ServerCommunity")
      return QSharedPointer<AbstractGameData>(new ServerCommunityData());
  
  else if(name == "ServerGameType")
      return QSharedPointer<AbstractGameData>(new ServerGameTypeData());
  
  else if(name == "ServerPopulation")
      return QSharedPointer<AbstractGameData>(new ServerPopulationData());
  
  else if(name == "SoundAnimation")
      return QSharedPointer<AbstractGameData>(new SoundAnimationData());
  
  else if(name == "SoundBones")
      return QSharedPointer<AbstractGameData>(new SoundBonesData());
  
  else if(name == "SoundUi")
      return QSharedPointer<AbstractGameData>(new SoundUiData());
  
  else if(name == "SoundUiElement")
      return QSharedPointer<AbstractGameData>(new SoundUiElementData());
  
  else if(name == "SoundUiHook")
      return QSharedPointer<AbstractGameData>(new SoundUiHookData());
  
  else if(name == "FinishMove")
      return QSharedPointer<AbstractGameData>(new FinishMoveData());
  
  else if(name == "Spell")
      return QSharedPointer<AbstractGameData>(new SpellData());
  
  else if(name == "SpellBomb")
      return QSharedPointer<AbstractGameData>(new SpellBombData());
  
  else if(name == "SpellLevel")
      return QSharedPointer<AbstractGameData>(new SpellLevelData());
  
  else if(name == "SpellPair")
      return QSharedPointer<AbstractGameData>(new SpellPairData());
  
  else if(name == "SpellState")
      return QSharedPointer<AbstractGameData>(new SpellStateData());
  
  else if(name == "SpellType")
      return QSharedPointer<AbstractGameData>(new SpellTypeData());
  
  else if(name == "Area")
      return QSharedPointer<AbstractGameData>(new AreaData());
  
  else if(name == "Dungeon")
      return QSharedPointer<AbstractGameData>(new DungeonData());
  
  else if(name == "Hint")
      return QSharedPointer<AbstractGameData>(new HintData());
  
  else if(name == "HintCategory")
      return QSharedPointer<AbstractGameData>(new HintCategoryData());
  
  else if(name == "MapCoordinates")
      return QSharedPointer<AbstractGameData>(new MapCoordinatesData());
  
  else if(name == "MapPosition")
      return QSharedPointer<AbstractGameData>(new MapPositionData());
  
  else if(name == "MapReference")
      return QSharedPointer<AbstractGameData>(new MapReferenceData());
  
  else if(name == "MapScrollAction")
      return QSharedPointer<AbstractGameData>(new MapScrollActionData());
  
  else if(name == "Phoenix")
      return QSharedPointer<AbstractGameData>(new PhoenixData());
  
  else if(name == "SubArea")
      return QSharedPointer<AbstractGameData>(new SubAreaData());
  
  else if(name == "SuperArea")
      return QSharedPointer<AbstractGameData>(new SuperAreaData());
  
  else if(name == "Waypoint")
      return QSharedPointer<AbstractGameData>(new WaypointData());
  
  else if(name == "WorldMap")
      return QSharedPointer<AbstractGameData>(new WorldMapData());
  
  else if(name == "BonusAreaCriterion")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "BonusEquippedItemCriterion")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "BonusMonsterCriterion")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "BonusMonsterFamilyCriterion")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "BonusQuestCategoryCriterion")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "BonusSubAreaCriterion")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "MonsterBonus")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "MonsterDropChanceBonus")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "MonsterLightBonus")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "MonsterStarRateBonus")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "MonsterXPBonus")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "MountBonus")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "QuestBonus")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "QuestKamasBonus")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "QuestXPBonus")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "IdolsPresetIcon")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "AnimFunMonsterData")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "AnimFunNpcData")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else if(name == "QuestObjectiveParameters")
      return QSharedPointer<AbstractGameData>(NULL);
  
  else
  {
  //  qDebug()<<"ERREUR - GameDataConverter - Ne connait pas la classe :"<<name;
    return QSharedPointer<AbstractGameData>(NULL);
  }
}

GameDataTypeEnum GameDataConverter::getEnum(const QString &name)
{
  if(name == "AbuseReasons")
      return GameDataTypeEnum::ABUSEREASONS;
  
  else if(name == "AlignmentBalance")
      return GameDataTypeEnum::ALIGNMENTBALANCE;
  
  else if(name == "AlignmentEffect")
      return GameDataTypeEnum::ALIGNMENTEFFECT;
  
  else if(name == "AlignmentGift")
      return GameDataTypeEnum::ALIGNMENTGIFT;
  
  else if(name == "AlignmentOrder")
      return GameDataTypeEnum::ALIGNMENTORDER;
  
  else if(name == "AlignmentRank")
      return GameDataTypeEnum::ALIGNMENTRANK;
  
  else if(name == "AlignmentRankJntGift")
      return GameDataTypeEnum::ALIGNMENTRANKJNTGIFT;
  
  else if(name == "AlignmentSides")
      return GameDataTypeEnum::ALIGNMENTSIDES;
  
  else if(name == "AlignmentTitles")
      return GameDataTypeEnum::ALIGNMENTTITLES;
  
  else if(name == "AlmanaxCalendars")
      return GameDataTypeEnum::ALMANAXCALENDARS;
  
  else if(name == "AmbientSounds")
      return GameDataTypeEnum::AMBIENTSOUNDS;
  
  else if(name == "PlaylistSounds")
      return GameDataTypeEnum::PLAYLISTSOUNDS;
  
  else if(name == "Appearances")
      return GameDataTypeEnum::APPEARANCES;
  
  else if(name == "CreatureBonesOverrides")
      return GameDataTypeEnum::CREATUREBONESOVERRIDES;
  
  else if(name == "CreatureBonesTypes")
      return GameDataTypeEnum::CREATUREBONESTYPES;
  
  else if(name == "Ornaments")
      return GameDataTypeEnum::ORNAMENTS;
  
  else if(name == "SkinMappings")
      return GameDataTypeEnum::SKINMAPPINGS;
  
  else if(name == "SkinPositions")
      return GameDataTypeEnum::SKINPOSITIONS;
  
  else if(name == "Titles")
      return GameDataTypeEnum::TITLES;
  
  else if(name == "TitleCategories")
      return GameDataTypeEnum::TITLECATEGORIES;
  
  else if(name == "Bonuses")
      return GameDataTypeEnum::BONUSES;
  
  else if(name == "BonusesCriterions")
      return GameDataTypeEnum::BONUSESCRITERIONS;
  
  else if(name == "Breeds")
      return GameDataTypeEnum::BREEDS;
  
  else if(name == "BreedRoles")
      return GameDataTypeEnum::BREEDROLES;
  
  else if(name == "BreedRoleByBreeds")
      return GameDataTypeEnum::BREEDROLEBYBREEDS;
  
  else if(name == "Heads")
      return GameDataTypeEnum::HEADS;
  
  else if(name == "Challenge")
      return GameDataTypeEnum::CHALLENGE;
  
  else if(name == "Characteristics")
      return GameDataTypeEnum::CHARACTERISTICS;
  
  else if(name == "CharacteristicCategories")
      return GameDataTypeEnum::CHARACTERISTICCATEGORIES;
  
  else if(name == "CensoredWords")
      return GameDataTypeEnum::CENSOREDWORDS;
  
  else if(name == "ChatChannels")
      return GameDataTypeEnum::CHATCHANNELS;
  
  else if(name == "Emoticons")
      return GameDataTypeEnum::EMOTICONS;
  
  else if(name == "InfoMessages")
      return GameDataTypeEnum::INFOMESSAGES;
  
  else if(name == "Smileys")
      return GameDataTypeEnum::SMILEYS;
  
  else if(name == "SmileyCategories")
      return GameDataTypeEnum::SMILEYCATEGORIES;
  
  else if(name == "SmileyPacks")
      return GameDataTypeEnum::SMILEYPACKS;
  
  else if(name == "DareCriterias")
      return GameDataTypeEnum::DARECRITERIAS;
  
  else if(name == "Comics")
      return GameDataTypeEnum::COMICS;
  
  else if(name == "Documents")
      return GameDataTypeEnum::DOCUMENTS;
  
  else if(name == "Effects")
      return GameDataTypeEnum::EFFECTS;
  
  else if(name == "ExternalNotifications")
      return GameDataTypeEnum::EXTERNALNOTIFICATIONS;
  
  else if(name == "EmblemBackgrounds")
      return GameDataTypeEnum::EMBLEMBACKGROUNDS;
  
  else if(name == "EmblemSymbols")
      return GameDataTypeEnum::EMBLEMSYMBOLS;
  
  else if(name == "EmblemSymbolCategories")
      return GameDataTypeEnum::EMBLEMSYMBOLCATEGORIES;
  
  else if(name == "RankNames")
      return GameDataTypeEnum::RANKNAMES;
  
  else if(name == "HavenbagFurnitures")
      return GameDataTypeEnum::HAVENBAGFURNITURES;
  
  else if(name == "HavenbagThemes")
      return GameDataTypeEnum::HAVENBAGTHEMES;
  
  else if(name == "Houses")
      return GameDataTypeEnum::HOUSES;
  
  else if(name == "Idols")
      return GameDataTypeEnum::IDOLS;
  
  else if(name == "Interactives")
      return GameDataTypeEnum::INTERACTIVES;
  
  else if(name == "SkillNames")
      return GameDataTypeEnum::SKILLNAMES;
  
  else if(name == "StealthBones")
      return GameDataTypeEnum::STEALTHBONES;
  
  else if(name == "Incarnation")
      return GameDataTypeEnum::INCARNATION;
  
  else if(name == "IncarnationLevels")
      return GameDataTypeEnum::INCARNATIONLEVELS;
  
  else if(name == "Items")
      return GameDataTypeEnum::ITEMS;
  
  else if(name == "ItemSets")
      return GameDataTypeEnum::ITEMSETS;
  
  else if(name == "ItemTypes")
      return GameDataTypeEnum::ITEMTYPES;
  
  else if(name == "PresetIcons")
      return GameDataTypeEnum::PRESETICONS;
  
  else if(name == "VeteranRewards")
      return GameDataTypeEnum::VETERANREWARDS;
  
  else if(name == "Jobs")
      return GameDataTypeEnum::JOBS;
  
  else if(name == "Recipes")
      return GameDataTypeEnum::RECIPES;
  
  else if(name == "Skills")
      return GameDataTypeEnum::SKILLS;
  
  else if(name == "LivingObjectSkinJntMood")
      return GameDataTypeEnum::LIVINGOBJECTSKINJNTMOOD;
  
  else if(name == "Pets")
      return GameDataTypeEnum::PETS;
  
  else if(name == "SpeakingItemsTriggers")
      return GameDataTypeEnum::SPEAKINGITEMSTRIGGERS;
  
  else if(name == "SpeakingItemsText")
      return GameDataTypeEnum::SPEAKINGITEMSTEXT;
  
  else if(name == "ActionDescriptions")
      return GameDataTypeEnum::ACTIONDESCRIPTIONS;
  
  else if(name == "CensoredContents")
      return GameDataTypeEnum::CENSOREDCONTENTS;
  
  else if(name == "Months")
      return GameDataTypeEnum::MONTHS;
  
  else if(name == "OptionalFeatures")
      return GameDataTypeEnum::OPTIONALFEATURES;
  
  else if(name == "Pack")
      return GameDataTypeEnum::PACK;
  
  else if(name == "Tips")
      return GameDataTypeEnum::TIPS;
  
  else if(name == "TypeActions")
      return GameDataTypeEnum::TYPEACTIONS;
  
  else if(name == "Url")
      return GameDataTypeEnum::URL;
  
  else if(name == "Companions")
      return GameDataTypeEnum::COMPANIONS;
  
  else if(name == "CompanionCharacteristics")
      return GameDataTypeEnum::COMPANIONCHARACTERISTICS;
  
  else if(name == "CompanionSpells")
      return GameDataTypeEnum::COMPANIONSPELLS;
  
  else if(name == "Monsters")
      return GameDataTypeEnum::MONSTERS;
  
  else if(name == "MonsterMiniBoss")
      return GameDataTypeEnum::MONSTERMINIBOSS;
  
  else if(name == "MonsterRaces")
      return GameDataTypeEnum::MONSTERRACES;
  
  else if(name == "MonsterSuperRaces")
      return GameDataTypeEnum::MONSTERSUPERRACES;
  
  else if(name == "Mounts")
      return GameDataTypeEnum::MOUNTS;
  
  else if(name == "MountBehaviors")
      return GameDataTypeEnum::MOUNTBEHAVIORS;
  
  else if(name == "MountBones")
      return GameDataTypeEnum::MOUNTBONES;
  
  else if(name == "MountFamily")
      return GameDataTypeEnum::MOUNTFAMILY;
  
  else if(name == "RideFood")
      return GameDataTypeEnum::RIDEFOOD;
  
  else if(name == "Notifications")
      return GameDataTypeEnum::NOTIFICATIONS;
  
  else if(name == "Npcs")
      return GameDataTypeEnum::NPCS;
  
  else if(name == "NpcActions")
      return GameDataTypeEnum::NPCACTIONS;
  
  else if(name == "NpcMessages")
      return GameDataTypeEnum::NPCMESSAGES;
  
  else if(name == "TaxCollectorFirstnames")
      return GameDataTypeEnum::TAXCOLLECTORFIRSTNAMES;
  
  else if(name == "TaxCollectorNames")
      return GameDataTypeEnum::TAXCOLLECTORNAMES;
  
  else if(name == "Playlists")
      return GameDataTypeEnum::PLAYLISTS;
  
  else if(name == "Achievements")
      return GameDataTypeEnum::ACHIEVEMENTS;
  
  else if(name == "AchievementCategories")
      return GameDataTypeEnum::ACHIEVEMENTCATEGORIES;
  
  else if(name == "AchievementObjectives")
      return GameDataTypeEnum::ACHIEVEMENTOBJECTIVES;
  
  else if(name == "AchievementRewards")
      return GameDataTypeEnum::ACHIEVEMENTREWARDS;
  
  else if(name == "Quests")
      return GameDataTypeEnum::QUESTS;
  
  else if(name == "QuestCategory")
      return GameDataTypeEnum::QUESTCATEGORY;
  
  else if(name == "QuestObjectives")
      return GameDataTypeEnum::QUESTOBJECTIVES;
  
  else if(name == "QuestObjectiveTypes")
      return GameDataTypeEnum::QUESTOBJECTIVETYPES;
  
  else if(name == "QuestSteps")
      return GameDataTypeEnum::QUESTSTEPS;
  
  else if(name == "QuestStepRewards")
      return GameDataTypeEnum::QUESTSTEPREWARDS;
  
  else if(name == "LegendaryTreasureHunts")
      return GameDataTypeEnum::LEGENDARYTREASUREHUNTS;
  
  else if(name == "PointOfInterest")
      return GameDataTypeEnum::POINTOFINTEREST;
  
  else if(name == "PointOfInterestCategory")
      return GameDataTypeEnum::POINTOFINTERESTCATEGORY;
  
  else if(name == "Servers")
      return GameDataTypeEnum::SERVERS;
  
  else if(name == "ServerCommunities")
      return GameDataTypeEnum::SERVERCOMMUNITIES;
  
  else if(name == "ServerGameTypes")
      return GameDataTypeEnum::SERVERGAMETYPES;
  
  else if(name == "ServerPopulations")
      return GameDataTypeEnum::SERVERPOPULATIONS;
  
  else if(name == "SoundAnimations")
      return GameDataTypeEnum::SOUNDANIMATIONS;
  
  else if(name == "SoundBones")
      return GameDataTypeEnum::SOUNDBONES;
  
  else if(name == "SoundUi")
      return GameDataTypeEnum::SOUNDUI;
  
  else if(name == "SoundUiElement")
      return GameDataTypeEnum::SOUNDUIELEMENT;
  
  else if(name == "SoundUiHook")
      return GameDataTypeEnum::SOUNDUIHOOK;
  
  else if(name == "FinishMoves")
      return GameDataTypeEnum::FINISHMOVES;
  
  else if(name == "Spells")
      return GameDataTypeEnum::SPELLS;
  
  else if(name == "SpellBombs")
      return GameDataTypeEnum::SPELLBOMBS;
  
  else if(name == "SpellLevels")
      return GameDataTypeEnum::SPELLLEVELS;
  
  else if(name == "SpellPairs")
      return GameDataTypeEnum::SPELLPAIRS;
  
  else if(name == "SpellStates")
      return GameDataTypeEnum::SPELLSTATES;
  
  else if(name == "SpellTypes")
      return GameDataTypeEnum::SPELLTYPES;
  
  else if(name == "Areas")
      return GameDataTypeEnum::AREAS;
  
  else if(name == "Dungeons")
      return GameDataTypeEnum::DUNGEONS;
  
  else if(name == "Hints")
      return GameDataTypeEnum::HINTS;
  
  else if(name == "HintCategory")
      return GameDataTypeEnum::HINTCATEGORY;
  
  else if(name == "MapCoordinates")
      return GameDataTypeEnum::MAPCOORDINATES;
  
  else if(name == "MapPositions")
      return GameDataTypeEnum::MAPPOSITIONS;
  
  else if(name == "MapReferences")
      return GameDataTypeEnum::MAPREFERENCES;
  
  else if(name == "MapScrollActions")
      return GameDataTypeEnum::MAPSCROLLACTIONS;
  
  else if(name == "Phoenixes")
      return GameDataTypeEnum::PHOENIXES;
  
  else if(name == "SubAreas")
      return GameDataTypeEnum::SUBAREAS;
  
  else if(name == "SuperAreas")
      return GameDataTypeEnum::SUPERAREAS;
  
  else if(name == "Waypoints")
      return GameDataTypeEnum::WAYPOINTS;
  
  else if(name == "WorldMaps")
      return GameDataTypeEnum::WORLDMAPS;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "IdolsPresetIcons")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else if(name == "")
      return GameDataTypeEnum::UNKNOWN;
  
  else
  {
    qDebug()<<"ERREUR - GameDataConverter - Ne connait pas l'enum :"<<name;
    return GameDataTypeEnum::UNKNOWN;
  }
}

