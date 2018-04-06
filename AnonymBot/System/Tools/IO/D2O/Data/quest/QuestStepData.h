#ifndef QUESTSTEPDATA_H
#define QUESTSTEPDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class QuestStepData : public AbstractGameData
{
public:
  uint getId() const;
  uint getQuestId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  int getDialogId() const;
  uint getOptimalLevel() const;
  double getDuration() const;
  bool getKamasScaleWithPlayerLevel() const;
  double getKamasRatio() const;
  double getXpRatio() const;
  QList<uint> getObjectiveIds() const;
  QList<uint> getRewardsIds() const;
  QString getName() const;
  QString getDescription() const;
  QString getDialog() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_questId;
  uint m_nameId;
  uint m_descriptionId;
  int m_dialogId;
  uint m_optimalLevel;
  double m_duration;
  bool m_kamasScaleWithPlayerLevel;
  double m_kamasRatio;
  double m_xpRatio;
  QList<uint> m_objectiveIds;
  QList<uint> m_rewardsIds;
};

#endif // QUESTSTEPDATA_H