#ifndef PACKDATA_H
#define PACKDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class PackData : public AbstractGameData
{
public:
  int getId() const;
  QString getName() const;
  bool getHasSubAreas() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  QString m_name;
  bool m_hasSubAreas;
};

#endif // PACKDATA_H