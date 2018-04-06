#ifndef QUESTOBJECTIVEBRINGITEMTONPCDATA_H
#define QUESTOBJECTIVEBRINGITEMTONPCDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestObjectiveData.h"

class QuestObjectiveBringItemToNpcData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEBRINGITEMTONPCDATA_H