#ifndef QUESTOBJECTIVEFREEFORMDATA_H
#define QUESTOBJECTIVEFREEFORMDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/quest/QuestObjectiveData.h"

class QuestObjectiveFreeFormData : public QuestObjectiveData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // QUESTOBJECTIVEFREEFORMDATA_H