#ifndef QUESTSTEPREWARDSDATA_H
#define QUESTSTEPREWARDSDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class QuestStepRewardsData : public AbstractGameData
{
public:
  uint getId() const;
  uint getStepId() const;
  int getLevelMin() const;
  int getLevelMax() const;
  QList<QList<uint>> getItemsReward() const;
  QList<uint> getEmotesReward() const;
  QList<uint> getJobsReward() const;
  QList<uint> getSpellsReward() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_stepId;
  int m_levelMin;
  int m_levelMax;
  QList<QList<uint>> m_itemsReward;
  QList<uint> m_emotesReward;
  QList<uint> m_jobsReward;
  QList<uint> m_spellsReward;
};

#endif // QUESTSTEPREWARDSDATA_H