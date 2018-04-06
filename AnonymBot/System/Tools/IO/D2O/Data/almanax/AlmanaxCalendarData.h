#ifndef ALMANAXCALENDARDATA_H
#define ALMANAXCALENDARDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AlmanaxCalendarData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescId() const;
  int getNpcId() const;
  QList<int> getBonusesIds() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descId;
  int m_npcId;
  QList<int> m_bonusesIds;
};

#endif // ALMANAXCALENDARDATA_H