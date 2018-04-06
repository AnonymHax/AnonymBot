#ifndef ARENAMAXTEAMRANKCRITERIONDATA_H
#define ARENAMAXTEAMRANKCRITERIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/items/criterion/ItemCriterionData.h"

class ArenaMaxTeamRankCriterionData : public ItemCriterionData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // ARENAMAXTEAMRANKCRITERIONDATA_H