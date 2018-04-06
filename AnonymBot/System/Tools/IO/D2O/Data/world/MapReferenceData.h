#ifndef MAPREFERENCEDATA_H
#define MAPREFERENCEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class MapReferenceData : public AbstractGameData
{
public:
  int getId() const;
  uint getMapId() const;
  int getCellId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_mapId;
  int m_cellId;
};

#endif // MAPREFERENCEDATA_H