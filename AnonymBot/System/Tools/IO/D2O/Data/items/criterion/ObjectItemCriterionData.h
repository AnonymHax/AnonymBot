#ifndef OBJECTITEMCRITERIONDATA_H
#define OBJECTITEMCRITERIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ItemCriterionData.h"

class ObjectItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // OBJECTITEMCRITERIONDATA_H