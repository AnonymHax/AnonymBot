#ifndef ACHIEVEMENTCATEGORYDATA_H
#define ACHIEVEMENTCATEGORYDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AchievementCategoryData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getParentId() const;
  QString getIcon() const;
  uint getOrder() const;
  QString getColor() const;
  QList<uint> getAchievementIds() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_parentId;
  QString m_icon;
  uint m_order;
  QString m_color;
  QList<uint> m_achievementIds;
};

#endif // ACHIEVEMENTCATEGORYDATA_H