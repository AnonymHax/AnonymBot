#ifndef HEADDATA_H
#define HEADDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class HeadData : public AbstractGameData
{
public:
  int getId() const;
  QString getSkins() const;
  QString getAssetId() const;
  uint getBreed() const;
  uint getGender() const;
  QString getLabel() const;
  uint getOrder() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  QString m_skins;
  QString m_assetId;
  uint m_breed;
  uint m_gender;
  QString m_label;
  uint m_order;
};

#endif // HEADDATA_H