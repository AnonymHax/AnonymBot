#ifndef CHARACTERISTICDATA_H
#define CHARACTERISTICDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class CharacteristicData : public AbstractGameData
{
public:
  int getId() const;
  QString getKeyword() const;
  uint getNameId() const;
  QString getAsset() const;
  int getCategoryId() const;
  bool getVisible() const;
  int getOrder() const;
  bool getUpgradable() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  QString m_keyword;
  uint m_nameId;
  QString m_asset;
  int m_categoryId;
  bool m_visible;
  int m_order;
  bool m_upgradable;
};

#endif // CHARACTERISTICDATA_H