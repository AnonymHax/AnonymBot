#ifndef PETDATA_H
#define PETDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"

class PetData : public AbstractGameData
{
public:
  int getId() const;
  QList<int> getFoodItems() const;
  QList<int> getFoodTypes() const;
  int getMinDurationBeforeMeal() const;
  int getMaxDurationBeforeMeal() const;
  QList<EffectInstanceData> getPossibleEffects() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  QList<int> m_foodItems;
  QList<int> m_foodTypes;
  int m_minDurationBeforeMeal;
  int m_maxDurationBeforeMeal;
  QList<EffectInstanceData> m_possibleEffects;
};

#endif // PETDATA_H