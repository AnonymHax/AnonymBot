#ifndef INCARNATIONDATA_H
#define INCARNATIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class IncarnationData : public AbstractGameData
{
public:
  uint getId() const;
  QString getLookMale() const;
  QString getLookFemale() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  QString m_lookMale;
  QString m_lookFemale;
};

#endif // INCARNATIONDATA_H