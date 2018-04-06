#ifndef NPCMESSAGEDATA_H
#define NPCMESSAGEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class NpcMessageData : public AbstractGameData
{
public:
  int getId() const;
  uint getMessageId() const;
  QList<QString> getMessageParams() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_messageId;
  QList<QString> m_messageParams;
};

#endif // NPCMESSAGEDATA_H