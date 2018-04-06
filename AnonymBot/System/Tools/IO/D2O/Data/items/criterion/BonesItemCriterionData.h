#ifndef BONESITEMCRITERIONDATA_H
#define BONESITEMCRITERIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ItemCriterionData.h"

class BonesItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // BONESITEMCRITERIONDATA_H