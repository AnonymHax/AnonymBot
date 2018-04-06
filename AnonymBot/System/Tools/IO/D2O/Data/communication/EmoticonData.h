#ifndef EMOTICONDATA_H
#define EMOTICONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class EmoticonData : public AbstractGameData
{
public:
  uint getId() const;
  uint getNameId() const;
  uint getShortcutId() const;
  uint getOrder() const;
  QString getDefaultAnim() const;
  bool getPersistancy() const;
  bool getAura() const;
  QList<QString> getAnims() const;
  uint getCooldown() const;
  uint getDuration() const;
  uint getWeight() const;
  QString getName() const;
  QString getShortcut() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_nameId;
  uint m_shortcutId;
  uint m_order;
  QString m_defaultAnim;
  bool m_persistancy;
  bool m_aura;
  QList<QString> m_anims;
  uint m_cooldown;
  uint m_duration;
  uint m_weight;
};

#endif // EMOTICONDATA_H