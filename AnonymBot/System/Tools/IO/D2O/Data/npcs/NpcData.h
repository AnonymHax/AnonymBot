#ifndef NPCDATA_H
#define NPCDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class NpcData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QList<QList<int>> getDialogMessages() const;
  QList<QList<int>> getDialogReplies() const;
  QList<uint> getActions() const;
  uint getGender() const;
  QString getLook() const;
  int getTokenShop() const;
  bool getFastAnimsFun() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  QList<QList<int>> m_dialogMessages;
  QList<QList<int>> m_dialogReplies;
  QList<uint> m_actions;
  uint m_gender;
  QString m_look;
  int m_tokenShop;
  bool m_fastAnimsFun;
};

#endif // NPCDATA_H