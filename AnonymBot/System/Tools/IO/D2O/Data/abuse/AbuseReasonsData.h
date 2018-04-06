#ifndef ABUSEREASONSDATA_H
#define ABUSEREASONSDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AbuseReasonsData : public AbstractGameData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // ABUSEREASONSDATA_H