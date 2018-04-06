#ifndef TAXCOLLECTORFIRSTNAMEDATA_H
#define TAXCOLLECTORFIRSTNAMEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class TaxCollectorFirstnameData : public AbstractGameData
{
public:
  int getId() const;
  uint getFirstnameId() const;
  QString getFirstname() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_firstnameId;
};

#endif // TAXCOLLECTORFIRSTNAMEDATA_H