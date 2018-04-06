#ifndef RANKNAMEDATA_H
#define RANKNAMEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class RankNameData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getOrder() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_order;
};

#endif // RANKNAMEDATA_H