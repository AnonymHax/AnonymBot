#ifndef IDOLDATA_H
#define IDOLDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class IdolData : public AbstractGameData
{
public:
  int getId() const;
  QString getDescription() const;
  int getCategoryId() const;
  int getItemId() const;
  bool getGroupOnly() const;
  int getSpellPairId() const;
  int getScore() const;
  int getExperienceBonus() const;
  int getDropBonus() const;
  QList<int> getSynergyIdolsIds() const;
  QList<double> getSynergyIdolsCoeff() const;
  QList<int> getIncompatibleMonsters() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  QString m_description;
  int m_categoryId;
  int m_itemId;
  bool m_groupOnly;
  int m_spellPairId;
  int m_score;
  int m_experienceBonus;
  int m_dropBonus;
  QList<int> m_synergyIdolsIds;
  QList<double> m_synergyIdolsCoeff;
  QList<int> m_incompatibleMonsters;
};

#endif // IDOLDATA_H