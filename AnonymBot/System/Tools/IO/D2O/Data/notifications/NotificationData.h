#ifndef NOTIFICATIONDATA_H
#define NOTIFICATIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class NotificationData : public AbstractGameData
{
public:
  int getId() const;
  uint getTitleId() const;
  uint getMessageId() const;
  int getIconId() const;
  int getTypeId() const;
  QString getTrigger() const;
  QString getTitle() const;
  QString getMessage() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_titleId;
  uint m_messageId;
  int m_iconId;
  int m_typeId;
  QString m_trigger;
};

#endif // NOTIFICATIONDATA_H