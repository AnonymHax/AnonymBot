#ifndef URLDATA_H
#define URLDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class UrlData : public AbstractGameData
{
public:
  int getId() const;
  int getBrowserId() const;
  QString getUrl() const;
  QString getParam() const;
  QString getMethod() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_browserId;
  QString m_url;
  QString m_param;
  QString m_method;
};

#endif // URLDATA_H