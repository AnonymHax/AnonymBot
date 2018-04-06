#ifndef QUESTOBJECTIVEFIGHTMONSTERDATA_H
#define QUESTOBJECTIVEFIGHTMONSTERDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestObjectiveData.h"

class QuestObjectiveFightMonsterData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEFIGHTMONSTERDATA_H