#ifndef EXTERNALNOTIFICATIONDATA_H
#define EXTERNALNOTIFICATIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ExternalNotificationData : public AbstractGameData
{
public:
  int getId() const;
  int getCategoryId() const;
  int getIconId() const;
  int getColorId() const;
  uint getDescriptionId() const;
  bool getDefaultEnable() const;
  bool getDefaultSound() const;
  bool getDefaultNotify() const;
  bool getDefaultMultiAccount() const;
  QString getName() const;
  uint getMessageId() const;
  QString getDescription() const;
  QString getMessage() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_categoryId;
  int m_iconId;
  int m_colorId;
  uint m_descriptionId;
  bool m_defaultEnable;
  bool m_defaultSound;
  bool m_defaultNotify;
  bool m_defaultMultiAccount;
  QString m_name;
  uint m_messageId;
};

#endif // EXTERNALNOTIFICATIONDATA_H