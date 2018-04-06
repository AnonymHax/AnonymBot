#ifndef ITEMTYPEDATA_H
#define ITEMTYPEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ItemTypeData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getSuperTypeId() const;
  bool getPlural() const;
  uint getGender() const;
  QString getRawZone() const;
  bool getMimickable() const;
  int getCraftXpRatio() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_superTypeId;
  bool m_plural;
  uint m_gender;
  QString m_rawZone;
  bool m_mimickable;
  int m_craftXpRatio;
};

#endif // ITEMTYPEDATA_H