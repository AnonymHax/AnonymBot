#ifndef EFFECTDATA_H
#define EFFECTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class EffectData : public AbstractGameData
{
public:
  int getId() const;
  uint getDescriptionId() const;
  uint getIconId() const;
  int getCharacteristic() const;
  uint getCategory() const;
  QString getOperator() const;
  bool getShowInTooltip() const;
  bool getUseDice() const;
  bool getForceMinMax() const;
  bool getBoost() const;
  bool getActive() const;
  int getOppositeId() const;
  uint getTheoreticalDescriptionId() const;
  uint getTheoreticalPattern() const;
  bool getShowInSet() const;
  int getBonusType() const;
  bool getUseInFight() const;
  uint getEffectPriority() const;
  int getElementId() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_descriptionId;
  uint m_iconId;
  int m_characteristic;
  uint m_category;
  QString m_operator;
  bool m_showInTooltip;
  bool m_useDice;
  bool m_forceMinMax;
  bool m_boost;
  bool m_active;
  int m_oppositeId;
  uint m_theoreticalDescriptionId;
  uint m_theoreticalPattern;
  bool m_showInSet;
  int m_bonusType;
  bool m_useInFight;
  uint m_effectPriority;
  int m_elementId;
};

#endif // EFFECTDATA_H