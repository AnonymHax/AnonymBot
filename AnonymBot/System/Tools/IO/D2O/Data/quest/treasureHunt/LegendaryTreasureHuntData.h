#ifndef LEGENDARYTREASUREHUNTDATA_H
#define LEGENDARYTREASUREHUNTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class LegendaryTreasureHuntData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getLevel() const;
  uint getChestId() const;
  uint getMonsterId() const;
  uint getMapItemId() const;
  double getXpRatio() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_level;
  uint m_chestId;
  uint m_monsterId;
  uint m_mapItemId;
  double m_xpRatio;
};

#endif // LEGENDARYTREASUREHUNTDATA_H