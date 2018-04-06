#ifndef MAPCOORDINATESDATA_H
#define MAPCOORDINATESDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class MapCoordinatesData : public AbstractGameData
{
public:
  uint getCompressedCoords() const;
  QList<int> getMapIds() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_compressedCoords;
  QList<int> m_mapIds;
};

#endif // MAPCOORDINATESDATA_H