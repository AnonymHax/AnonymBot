#ifndef ITEMSETDATA_H
#define ITEMSETDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"

class ItemSetData : public AbstractGameData
{
public:
  uint getId() const;
  QList<uint> getItems() const;
  uint getNameId() const;
  QList<QList<EffectInstanceData>> getEffects() const;
  bool getBonusIsSecret() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  QList<uint> m_items;
  uint m_nameId;
  QList<QList<EffectInstanceData>> m_effects;
  bool m_bonusIsSecret;
};

#endif // ITEMSETDATA_H