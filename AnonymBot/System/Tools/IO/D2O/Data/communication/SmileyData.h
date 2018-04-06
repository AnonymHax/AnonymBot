#ifndef SMILEYDATA_H
#define SMILEYDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class SmileyData : public AbstractGameData
{
public:
  uint getId() const;
  uint getOrder() const;
  QString getGfxId() const;
  bool getForPlayers() const;
  QList<QString> getTriggers() const;
  uint getReferenceId() const;
  uint getCategoryId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_order;
  QString m_gfxId;
  bool m_forPlayers;
  QList<QString> m_triggers;
  uint m_referenceId;
  uint m_categoryId;
};

#endif // SMILEYDATA_H