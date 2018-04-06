#ifndef TIPSDATA_H
#define TIPSDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class TipsData : public AbstractGameData
{
public:
  int getId() const;
  uint getDescId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_descId;
};

#endif // TIPSDATA_H