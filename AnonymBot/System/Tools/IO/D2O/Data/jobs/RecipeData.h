#ifndef RECIPEDATA_H
#define RECIPEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class RecipeData : public AbstractGameData
{
public:
  int getResultId() const;
  uint getResultNameId() const;
  uint getResultTypeId() const;
  uint getResultLevel() const;
  QList<int> getIngredientIds() const;
  QList<uint> getQuantities() const;
  int getJobId() const;
  int getSkillId() const;
  QString getResultName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_resultId;
  uint m_resultNameId;
  uint m_resultTypeId;
  uint m_resultLevel;
  QList<int> m_ingredientIds;
  QList<uint> m_quantities;
  int m_jobId;
  int m_skillId;
};

#endif // RECIPEDATA_H