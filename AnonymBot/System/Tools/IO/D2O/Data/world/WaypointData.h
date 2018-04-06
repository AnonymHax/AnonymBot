#ifndef WAYPOINTDATA_H
#define WAYPOINTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class WaypointData : public AbstractGameData
{
public:
  uint getId() const;
  uint getMapId() const;
  uint getSubAreaId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_mapId;
  uint m_subAreaId;
};

#endif // WAYPOINTDATA_H