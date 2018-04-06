#ifndef GROUPITEMCRITERIONDATA_H
#define GROUPITEMCRITERIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class GroupItemCriterionData : public AbstractGameData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // GROUPITEMCRITERIONDATA_H