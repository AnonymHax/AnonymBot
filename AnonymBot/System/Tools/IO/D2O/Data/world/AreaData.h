#ifndef AREADATA_H
#define AREADATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AreaData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getSuperAreaId() const;
  bool getContainHouses() const;
  bool getContainPaddocks() const;
  uint getWorldmapId() const;
  bool getHasWorldMap() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_superAreaId;
  bool m_containHouses;
  bool m_containPaddocks;
  uint m_worldmapId;
  bool m_hasWorldMap;
};

#endif // AREADATA_H