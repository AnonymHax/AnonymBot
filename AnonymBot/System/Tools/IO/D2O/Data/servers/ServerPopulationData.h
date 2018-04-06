#ifndef SERVERPOPULATIONDATA_H
#define SERVERPOPULATIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ServerPopulationData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  int getWeight() const;
  QString getName() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  int m_weight;
};

#endif // SERVERPOPULATIONDATA_H