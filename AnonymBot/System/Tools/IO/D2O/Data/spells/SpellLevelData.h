#ifndef SPELLLEVELDATA_H
#define SPELLLEVELDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/effects/instances/EffectInstanceDiceData.h"

class SpellLevelData : public AbstractGameData
{
public:
  uint getId() const;
  uint getSpellId() const;
  uint getGrade() const;
  uint getSpellBreed() const;
  uint getApCost() const;
  uint getMinRange() const;
  uint getRange() const;
  bool getCastInLine() const;
  bool getCastInDiagonal() const;
  bool getCastTestLos() const;
  uint getCriticalHitProbability() const;
  bool getNeedFreeCell() const;
  bool getNeedTakenCell() const;
  bool getNeedFreeTrapCell() const;
  bool getRangeCanBeBoosted() const;
  int getMaxStack() const;
  uint getMaxCastPerTurn() const;
  uint getMaxCastPerTarget() const;
  uint getMinCastInterval() const;
  uint getInitialCooldown() const;
  int getGlobalCooldown() const;
  uint getMinPlayerLevel() const;
  bool getHideEffects() const;
  bool getHidden() const;
  bool getPlayAnimation() const;
  QList<int> getStatesRequired() const;
  QList<int> getStatesForbidden() const;
  QList<EffectInstanceDiceData> getEffects() const;
  QList<EffectInstanceDiceData> getCriticalEffect() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_spellId;
  uint m_grade;
  uint m_spellBreed;
  uint m_apCost;
  uint m_minRange;
  uint m_range;
  bool m_castInLine;
  bool m_castInDiagonal;
  bool m_castTestLos;
  uint m_criticalHitProbability;
  bool m_needFreeCell;
  bool m_needTakenCell;
  bool m_needFreeTrapCell;
  bool m_rangeCanBeBoosted;
  int m_maxStack;
  uint m_maxCastPerTurn;
  uint m_maxCastPerTarget;
  uint m_minCastInterval;
  uint m_initialCooldown;
  int m_globalCooldown;
  uint m_minPlayerLevel;
  bool m_hideEffects;
  bool m_hidden;
  bool m_playAnimation;
  QList<int> m_statesRequired;
  QList<int> m_statesForbidden;
  QList<EffectInstanceDiceData> m_effects;
  QList<EffectInstanceDiceData> m_criticalEffect;
};

#endif // SPELLLEVELDATA_H