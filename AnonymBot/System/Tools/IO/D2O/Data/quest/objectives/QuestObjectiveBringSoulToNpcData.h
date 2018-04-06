#ifndef QUESTOBJECTIVEBRINGSOULTONPCDATA_H
#define QUESTOBJECTIVEBRINGSOULTONPCDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestObjectiveData.h"

class QuestObjectiveBringSoulToNpcData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEBRINGSOULTONPCDATA_H