#ifndef SERVERCOMMUNITYDATA_H
#define SERVERCOMMUNITYDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ServerCommunityData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  QString getShortId() const;
  QList<QString> getDefaultCountries() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  QString m_shortId;
  QList<QString> m_defaultCountries;
};

#endif // SERVERCOMMUNITYDATA_H