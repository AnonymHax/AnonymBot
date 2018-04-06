#ifndef EFFECTINSTANCEMOUNTDATA_H
#define EFFECTINSTANCEMOUNTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"

class EffectInstanceMountData : public EffectInstanceData
{
public:
  double getDate() const;
  uint getModelId() const;
  uint getMountId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  double m_date;
  uint m_modelId;
  uint m_mountId;
};

#endif // EFFECTINSTANCEMOUNTDATA_H