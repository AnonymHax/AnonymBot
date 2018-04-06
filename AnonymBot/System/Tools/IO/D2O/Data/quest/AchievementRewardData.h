#ifndef ACHIEVEMENTREWARDDATA_H
#define ACHIEVEMENTREWARDDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AchievementRewardData : public AbstractGameData
{
public:
  uint getId() const;
  uint getAchievementId() const;
  int getLevelMin() const;
  int getLevelMax() const;
  QList<uint> getItemsReward() const;
  QList<uint> getItemsQuantityReward() const;
  QList<uint> getEmotesReward() const;
  QList<uint> getSpellsReward() const;
  QList<uint> getTitlesReward() const;
  QList<uint> getOrnamentsReward() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_achievementId;
  int m_levelMin;
  int m_levelMax;
  QList<uint> m_itemsReward;
  QList<uint> m_itemsQuantityReward;
  QList<uint> m_emotesReward;
  QList<uint> m_spellsReward;
  QList<uint> m_titlesReward;
  QList<uint> m_ornamentsReward;
};

#endif // ACHIEVEMENTREWARDDATA_H