#ifndef SPELLPAIRDATA_H
#define SPELLPAIRDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SpellPairData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  uint getIconId() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descriptionId;
  uint m_iconId;
};

#endif // SPELLPAIRDATA_H