#ifndef QUESTOBJECTIVEGOTONPCDATA_H
#define QUESTOBJECTIVEGOTONPCDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestObjectiveData.h"

class QuestObjectiveGoToNpcData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEGOTONPCDATA_H