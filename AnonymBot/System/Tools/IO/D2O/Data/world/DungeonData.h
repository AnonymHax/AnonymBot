#ifndef DUNGEONDATA_H
#define DUNGEONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class DungeonData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOptimalPlayerLevel() const;
  QList<int> getMapIds() const;
  int getEntranceMapId() const;
  int getExitMapId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_optimalPlayerLevel;
  QList<int> m_mapIds;
  int m_entranceMapId;
  int m_exitMapId;
};

#endif // DUNGEONDATA_H