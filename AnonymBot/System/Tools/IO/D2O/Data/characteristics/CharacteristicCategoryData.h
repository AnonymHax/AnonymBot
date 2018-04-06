#ifndef CHARACTERISTICCATEGORYDATA_H
#define CHARACTERISTICCATEGORYDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class CharacteristicCategoryData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrder() const;
  QList<uint> getCharacteristicIds() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_order;
  QList<uint> m_characteristicIds;
};

#endif // CHARACTERISTICCATEGORYDATA_H