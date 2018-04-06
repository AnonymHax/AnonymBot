#ifndef VETERANREWARDDATA_H
#define VETERANREWARDDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class VeteranRewardData : public AbstractGameData
{
public:
  int getId() const;
  uint getRequiredSubDays() const;
  uint getItemGID() const;
  uint getItemQuantity() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_requiredSubDays;
  uint m_itemGID;
  uint m_itemQuantity;
};

#endif // VETERANREWARDDATA_H