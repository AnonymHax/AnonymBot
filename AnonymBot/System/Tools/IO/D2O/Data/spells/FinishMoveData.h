#ifndef FINISHMOVEDATA_H
#define FINISHMOVEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class FinishMoveData : public AbstractGameData
{
public:
  int getId() const;
  int getDuration() const;
  bool getFree() const;
  uint getNameId() const;
  int getCategory() const;
  int getSpellLevel() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_duration;
  bool m_free;
  uint m_nameId;
  int m_category;
  int m_spellLevel;
};

#endif // FINISHMOVEDATA_H