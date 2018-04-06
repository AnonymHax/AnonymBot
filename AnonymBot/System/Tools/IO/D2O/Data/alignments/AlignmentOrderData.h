#ifndef ALIGNMENTORDERDATA_H
#define ALIGNMENTORDERDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AlignmentOrderData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getSideId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_sideId;
};

#endif // ALIGNMENTORDERDATA_H