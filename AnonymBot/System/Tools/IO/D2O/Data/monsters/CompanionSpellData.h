#ifndef COMPANIONSPELLDATA_H
#define COMPANIONSPELLDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class CompanionSpellData : public AbstractGameData
{
public:
  int getId() const;
  int getSpellId() const;
  int getCompanionId() const;
  QString getGradeByLevel() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_spellId;
  int m_companionId;
  QString m_gradeByLevel;
};

#endif // COMPANIONSPELLDATA_H