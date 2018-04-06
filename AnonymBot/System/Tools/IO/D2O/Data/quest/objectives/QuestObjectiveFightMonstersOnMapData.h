#ifndef QUESTOBJECTIVEFIGHTMONSTERSONMAPDATA_H
#define QUESTOBJECTIVEFIGHTMONSTERSONMAPDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestObjectiveData.h"

class QuestObjectiveFightMonstersOnMapData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEFIGHTMONSTERSONMAPDATA_H