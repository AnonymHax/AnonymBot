#ifndef COMPANIONDATA_H
#define COMPANIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class CompanionData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getLook() const;
  bool getWebDisplay() const;
  uint getDescriptionId() const;
  uint getStartingSpellLevelId() const;
  uint getAssetId() const;
  QList<uint> getCharacteristics() const;
  QList<uint> getSpells() const;
  int getCreatureBoneId() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  QString m_look;
  bool m_webDisplay;
  uint m_descriptionId;
  uint m_startingSpellLevelId;
  uint m_assetId;
  QList<uint> m_characteristics;
  QList<uint> m_spells;
  int m_creatureBoneId;
};

#endif // COMPANIONDATA_H