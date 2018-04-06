#ifndef EFFECTINSTANCEDICEDATA_H
#define EFFECTINSTANCEDICEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceIntegerData.h"

class EffectInstanceDiceData : public EffectInstanceIntegerData
{
public:
  uint getDiceNum() const;
  uint getDiceSide() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_diceNum;
  uint m_diceSide;
};

#endif // EFFECTINSTANCEDICEDATA_H