#ifndef ACHIEVEMENTDATA_H
#define ACHIEVEMENTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AchievementData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getCategoryId() const;
  uint getDescriptionId() const;
  uint getIconId() const;
  uint getPoints() const;
  uint getLevel() const;
  uint getOrder() const;
  double getKamasRatio() const;
  double getExperienceRatio() const;
  bool getKamasScaleWithPlayerLevel() const;
  QList<int> getObjectiveIds() const;
  QList<int> getRewardIds() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_categoryId;
  uint m_descriptionId;
  uint m_iconId;
  uint m_points;
  uint m_level;
  uint m_order;
  double m_kamasRatio;
  double m_experienceRatio;
  bool m_kamasScaleWithPlayerLevel;
  QList<int> m_objectiveIds;
  QList<int> m_rewardIds;
};

#endif // ACHIEVEMENTDATA_H