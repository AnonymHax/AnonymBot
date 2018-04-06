#ifndef POINTOFINTERESTDATA_H
#define POINTOFINTERESTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class PointOfInterestData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getCategoryId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_categoryId;
};

#endif // POINTOFINTERESTDATA_H