#ifndef JOBDATA_H
#define JOBDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class JobData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getIconId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_iconId;
};

#endif // JOBDATA_H