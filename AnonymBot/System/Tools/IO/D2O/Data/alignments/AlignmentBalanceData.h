#ifndef ALIGNMENTBALANCEDATA_H
#define ALIGNMENTBALANCEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AlignmentBalanceData : public AbstractGameData
{
public:
  int getId() const;
  int getStartValue() const;
  int getEndValue() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_startValue;
  int m_endValue;
  uint m_nameId;
  uint m_descriptionId;
};

#endif // ALIGNMENTBALANCEDATA_H