#ifndef EFFECTINSTANCECREATUREDATA_H
#define EFFECTINSTANCECREATUREDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"

class EffectInstanceCreatureData : public EffectInstanceData
{
public:
  uint getMonsterFamilyId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_monsterFamilyId;
};

#endif // EFFECTINSTANCECREATUREDATA_H