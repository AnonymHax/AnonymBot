#ifndef MONSTERRACEDATA_H
#define MONSTERRACEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class MonsterRaceData : public AbstractGameData
{
public:
  int getId() const;
  int getSuperRaceId() const;
  uint getNameId() const;
  QList<uint> getMonsters() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_superRaceId;
  uint m_nameId;
  QList<uint> m_monsters;
};

#endif // MONSTERRACEDATA_H