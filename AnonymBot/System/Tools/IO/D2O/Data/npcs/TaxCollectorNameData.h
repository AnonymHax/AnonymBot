#ifndef TAXCOLLECTORNAMEDATA_H
#define TAXCOLLECTORNAMEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class TaxCollectorNameData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
};

#endif // TAXCOLLECTORNAMEDATA_H