#ifndef ALIGNMENTGIFTDATA_H
#define ALIGNMENTGIFTDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class AlignmentGiftData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getEffectId() const;
  uint getGfxId() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_effectId;
  uint m_gfxId;
};

#endif // ALIGNMENTGIFTDATA_H