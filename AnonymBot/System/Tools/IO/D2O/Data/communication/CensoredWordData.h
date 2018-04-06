#ifndef CENSOREDWORDDATA_H
#define CENSOREDWORDDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class CensoredWordData : public AbstractGameData
{
public:
  uint getId() const;
  uint getListId() const;
  QString getLanguage() const;
  QString getWord() const;
  bool getDeepLooking() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  uint m_id;
  uint m_listId;
  QString m_language;
  QString m_word;
  bool m_deepLooking;
};

#endif // CENSOREDWORDDATA_H