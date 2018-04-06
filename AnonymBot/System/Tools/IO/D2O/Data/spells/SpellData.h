#ifndef SPELLDATA_H
#define SPELLDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SpellData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getDescriptionId() const;
  uint getTypeId() const;
  uint getOrder() const;
  QString getScriptParams() const;
  QString getScriptParamsCritical() const;
  int getScriptId() const;
  int getScriptIdCritical() const;
  uint getIconId() const;
  QList<uint> getSpellLevels() const;
  QList<int> getVariants() const;
  bool getUseParamCache() const;
  uint getObtentionLevel() const;
  bool getUseSpellLevelScaling() const;
  QString getName() const;
  QString getDescription() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_descriptionId;
  uint m_typeId;
  uint m_order;
  QString m_scriptParams;
  QString m_scriptParamsCritical;
  int m_scriptId;
  int m_scriptIdCritical;
  uint m_iconId;
  QList<uint> m_spellLevels;
  QList<int> m_variants;
  bool m_useParamCache;
  uint m_obtentionLevel;
  bool m_useSpellLevelScaling;
};

#endif // SPELLDATA_H