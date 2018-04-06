#ifndef SUPERAREADATA_H
#define SUPERAREADATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SuperAreaData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getWorldmapId() const;
  bool getHasWorldMap() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_worldmapId;
  bool m_hasWorldMap;
};

#endif // SUPERAREADATA_H