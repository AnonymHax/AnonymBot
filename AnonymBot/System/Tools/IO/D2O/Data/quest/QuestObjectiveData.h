#ifndef QUESTOBJECTIVEDATA_H
#define QUESTOBJECTIVEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class QuestObjectiveData : public AbstractGameData
{
public:
  uint getId() const;
  uint getStepId() const;
  uint getTypeId() const;
  int getDialogId() const;
  int getMapId() const;
  QString getDialog() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_stepId;
  uint m_typeId;
  int m_dialogId;
  int m_mapId;
};

#endif // QUESTOBJECTIVEDATA_H