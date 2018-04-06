#ifndef QUESTOBJECTIVETYPEDATA_H
#define QUESTOBJECTIVETYPEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class QuestObjectiveTypeData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
};

#endif // QUESTOBJECTIVETYPEDATA_H