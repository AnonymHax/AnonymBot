#ifndef QUESTCATEGORYDATA_H
#define QUESTCATEGORYDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class QuestCategoryData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getOrder() const;
  QList<uint> getQuestIds() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_order;
  QList<uint> m_questIds;
};

#endif // QUESTCATEGORYDATA_H