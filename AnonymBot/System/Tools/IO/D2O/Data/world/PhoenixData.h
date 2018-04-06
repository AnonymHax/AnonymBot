#ifndef PHOENIXDATA_H
#define PHOENIXDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class PhoenixData : public AbstractGameData
{
public:
  uint getMapId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_mapId;
};

#endif // PHOENIXDATA_H