#ifndef COMMUNITYITEMCRITERIONDATA_H
#define COMMUNITYITEMCRITERIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ItemCriterionData.h"

class CommunityItemCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // COMMUNITYITEMCRITERIONDATA_H