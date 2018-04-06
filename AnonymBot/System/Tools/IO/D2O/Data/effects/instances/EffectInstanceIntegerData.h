#ifndef EFFECTINSTANCEINTEGERDATA_H
#define EFFECTINSTANCEINTEGERDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"

class EffectInstanceIntegerData : public EffectInstanceData
{
public:
  int getValue() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_value;
};

#endif // EFFECTINSTANCEINTEGERDATA_H