#ifndef QUESTDATA_H
#define QUESTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class QuestData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  QList<uint> getStepIds() const;
  uint getCategoryId() const;
  uint getRepeatType() const;
  uint getRepeatLimit() const;
  bool getIsDungeonQuest() const;
  uint getLevelMin() const;
  uint getLevelMax() const;
  bool getIsPartyQuest() const;
  QString getStartCriterion() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  QList<uint> m_stepIds;
  uint m_categoryId;
  uint m_repeatType;
  uint m_repeatLimit;
  bool m_isDungeonQuest;
  uint m_levelMin;
  uint m_levelMax;
  bool m_isPartyQuest;
  QString m_startCriterion;
};

#endif // QUESTDATA_H