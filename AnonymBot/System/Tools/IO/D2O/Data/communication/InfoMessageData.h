#ifndef INFOMESSAGEDATA_H
#define INFOMESSAGEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class InfoMessageData : public AbstractGameData
{
public:
  uint getTypeId() const;
  uint getMessageId() const;
  uint getTextId() const;
  QString getText() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_typeId;
  uint m_messageId;
  uint m_textId;
};

#endif // INFOMESSAGEDATA_H