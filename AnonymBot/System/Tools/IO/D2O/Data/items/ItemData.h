#ifndef ITEMDATA_H
#define ITEMDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"
#include "System/Tools/IO/D2O/Data/effects/EffectInstanceData.h"

class ItemData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getTypeId() const;
  uint getDescriptionId() const;
  uint getIconId() const;
  uint getLevel() const;
  uint getRealWeight() const;
  bool getCursed() const;
  int getUseAnimationId() const;
  bool getUsable() const;
  bool getTargetable() const;
  bool getExchangeable() const;
  double getPrice() const;
  bool getTwoHanded() const;
  bool getEtheral() const;
  int getItemSetId() const;
  QString getCriteria() const;
  QString getCriteriaTarget() const;
  bool getHideEffects() const;
  bool getEnhanceable() const;
  bool getNonUsableOnAnother() const;
  uint getAppearanceId() const;
  bool getSecretRecipe() const;
  QList<uint> getDropMonsterIds() const;
  uint getRecipeSlots() const;
  QList<uint> getRecipeIds() const;
  bool getBonusIsSecret() const;
  QList<EffectInstanceData> getPossibleEffects() const;
  QList<uint> getFavoriteSubAreas() const;
  uint getFavoriteSubAreasBonus() const;
  int getCraftXpRatio() const;
  bool getNeedUseConfirm() const;
  bool getIsDestructible() const;
  QList<QList<double>> getNuggetsBySubarea() const;
  QList<uint> getContainerIds() const;
  QList<QList<int>> getResourcesBySubarea() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_typeId;
  uint m_descriptionId;
  uint m_iconId;
  uint m_level;
  uint m_realWeight;
  bool m_cursed;
  int m_useAnimationId;
  bool m_usable;
  bool m_targetable;
  bool m_exchangeable;
  double m_price;
  bool m_twoHanded;
  bool m_etheral;
  int m_itemSetId;
  QString m_criteria;
  QString m_criteriaTarget;
  bool m_hideEffects;
  bool m_enhanceable;
  bool m_nonUsableOnAnother;
  uint m_appearanceId;
  bool m_secretRecipe;
  QList<uint> m_dropMonsterIds;
  uint m_recipeSlots;
  QList<uint> m_recipeIds;
  bool m_bonusIsSecret;
  QList<EffectInstanceData> m_possibleEffects;
  QList<uint> m_favoriteSubAreas;
  uint m_favoriteSubAreasBonus;
  int m_craftXpRatio;
  bool m_needUseConfirm;
  bool m_isDestructible;
  QList<QList<double>> m_nuggetsBySubarea;
  QList<uint> m_containerIds;
  QList<QList<int>> m_resourcesBySubarea;
};

#endif // ITEMDATA_H