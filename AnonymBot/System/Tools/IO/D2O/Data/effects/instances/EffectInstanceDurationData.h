#ifndef EFFECTINSTANCEDURATIONDATA_H
#define EFFECTINSTANCEDURATIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"

class EffectInstanceDurationData : public EffectInstanceData
{
public:
  uint getDays() const;
  uint getHours() const;
  uint getMinutes() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_days;
  uint m_hours;
  uint m_minutes;
};

#endif // EFFECTINSTANCEDURATIONDATA_H