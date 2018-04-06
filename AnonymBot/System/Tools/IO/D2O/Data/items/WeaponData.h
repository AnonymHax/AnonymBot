#ifndef WEAPONDATA_H
#define WEAPONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/items/ItemData.h"

class WeaponData : public ItemData
{
public:
  int getApCost() const;
  int getMinRange() const;
  int getRange() const;
  uint getMaxCastPerTurn() const;
  bool getCastInLine() const;
  bool getCastInDiagonal() const;
  bool getCastTestLos() const;
  int getCriticalHitProbability() const;
  int getCriticalHitBonus() const;
  int getCriticalFailureProbability() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_apCost;
  int m_minRange;
  int m_range;
  uint m_maxCastPerTurn;
  bool m_castInLine;
  bool m_castInDiagonal;
  bool m_castTestLos;
  int m_criticalHitProbability;
  int m_criticalHitBonus;
  int m_criticalFailureProbability;
};

#endif // WEAPONDATA_H