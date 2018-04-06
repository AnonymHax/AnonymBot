#ifndef SKILLDATA_H
#define SKILLDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SkillData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getParentJobId() const;
  bool getIsForgemagus() const;
  QList<int> getModifiableItemTypeIds() const;
  int getGatheredRessourceItem() const;
  QList<int> getCraftableItemIds() const;
  int getInteractiveId() const;
  QString getUseAnimation() const;
  int getCursor() const;
  int getElementActionId() const;
  bool getAvailableInHouse() const;
  uint getLevelMin() const;
  bool getClientDisplay() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_parentJobId;
  bool m_isForgemagus;
  QList<int> m_modifiableItemTypeIds;
  int m_gatheredRessourceItem;
  QList<int> m_craftableItemIds;
  int m_interactiveId;
  QString m_useAnimation;
  int m_cursor;
  int m_elementActionId;
  bool m_availableInHouse;
  uint m_levelMin;
  bool m_clientDisplay;
};

#endif // SKILLDATA_H