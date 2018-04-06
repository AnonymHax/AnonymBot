#ifndef SUBAREADATA_H
#define SUBAREADATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/ambientSounds/AmbientSoundData.h"

class SubAreaData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getAreaId() const;
  QList<AmbientSoundData> getAmbientSounds() const;
  QList<QList<int>> getPlaylists() const;
  QList<uint> getMapIds() const;
  QList<int> getShape() const;
  QList<uint> getCustomWorldMap() const;
  int getPackId() const;
  uint getLevel() const;
  bool getIsConquestVillage() const;
  bool getBasicAccountAllowed() const;
  bool getDisplayOnWorldMap() const;
  QList<uint> getMonsters() const;
  QList<uint> getEntranceMapIds() const;
  QList<uint> getExitMapIds() const;
  bool getCapturable() const;
  QList<uint> getAchievements() const;
  QList<QList<int>> getQuests() const;
  QList<QList<int>> getNpcs() const;
  int getExploreAchievementId() const;
  bool getIsDiscovered() const;
  QList<int> getHarvestables() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_areaId;
  QList<AmbientSoundData> m_ambientSounds;
  QList<QList<int>> m_playlists;
  QList<uint> m_mapIds;
  QList<int> m_shape;
  QList<uint> m_customWorldMap;
  int m_packId;
  uint m_level;
  bool m_isConquestVillage;
  bool m_basicAccountAllowed;
  bool m_displayOnWorldMap;
  QList<uint> m_monsters;
  QList<uint> m_entranceMapIds;
  QList<uint> m_exitMapIds;
  bool m_capturable;
  QList<uint> m_achievements;
  QList<QList<int>> m_quests;
  QList<QList<int>> m_npcs;
  int m_exploreAchievementId;
  bool m_isDiscovered;
  QList<int> m_harvestables;
};

#endif // SUBAREADATA_H