#ifndef OPTIONALFEATUREDATA_H
#define OPTIONALFEATUREDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class OptionalFeatureData : public AbstractGameData
{
public:
  int getId() const;
  QString getKeyword() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  QString m_keyword;
};

#endif // OPTIONALFEATUREDATA_H