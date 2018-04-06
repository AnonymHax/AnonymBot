#ifndef BREEDROLEDATA_H
#define BREEDROLEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class BreedRoleData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  int getAssetId() const;
  int getColor() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descriptionId;
  int m_assetId;
  int m_color;
};

#endif // BREEDROLEDATA_H