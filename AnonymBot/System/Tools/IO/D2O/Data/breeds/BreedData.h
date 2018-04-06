#ifndef BREEDDATA_H
#define BREEDDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/breeds/BreedRoleByBreedData.h"

class BreedData : public AbstractGameData
{
public:
  int getId() const;
  uint getShortNameId() const;
  uint getLongNameId() const;
  uint getDescriptionId() const;
  uint getGameplayDescriptionId() const;
  QString getMaleLook() const;
  QString getFemaleLook() const;
  uint getCreatureBonesId() const;
  int getMaleArtwork() const;
  int getFemaleArtwork() const;
  QList<QList<uint>> getStatsPointsForStrength() const;
  QList<QList<uint>> getStatsPointsForIntelligence() const;
  QList<QList<uint>> getStatsPointsForChance() const;
  QList<QList<uint>> getStatsPointsForAgility() const;
  QList<QList<uint>> getStatsPointsForVitality() const;
  QList<QList<uint>> getStatsPointsForWisdom() const;
  QList<uint> getBreedSpellsId() const;
  QList<BreedRoleByBreedData> getBreedRoles() const;
  QList<uint> getMaleColors() const;
  QList<uint> getFemaleColors() const;
  uint getSpawnMap() const;
  uint getComplexity() const;
  uint getSortIndex() const;
  QString getShortName() const;
  QString getLongName() const;
  QString getDescription() const;
  QString getGameplayDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_shortNameId;
  uint m_longNameId;
  uint m_descriptionId;
  uint m_gameplayDescriptionId;
  QString m_maleLook;
  QString m_femaleLook;
  uint m_creatureBonesId;
  int m_maleArtwork;
  int m_femaleArtwork;
  QList<QList<uint>> m_statsPointsForStrength;
  QList<QList<uint>> m_statsPointsForIntelligence;
  QList<QList<uint>> m_statsPointsForChance;
  QList<QList<uint>> m_statsPointsForAgility;
  QList<QList<uint>> m_statsPointsForVitality;
  QList<QList<uint>> m_statsPointsForWisdom;
  QList<uint> m_breedSpellsId;
  QList<BreedRoleByBreedData> m_breedRoles;
  QList<uint> m_maleColors;
  QList<uint> m_femaleColors;
  uint m_spawnMap;
  uint m_complexity;
  uint m_sortIndex;
};

#endif // BREEDDATA_H