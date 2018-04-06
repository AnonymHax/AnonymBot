#ifndef COMPANIONCHARACTERISTICDATA_H
#define COMPANIONCHARACTERISTICDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class CompanionCharacteristicData : public AbstractGameData
{
public:
  int getId() const;
  int getCaracId() const;
  int getCompanionId() const;
  int getOrder() const;
  QList<QList<double>> getStatPerLevelRange() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_caracId;
  int m_companionId;
  int m_order;
  QList<QList<double>> m_statPerLevelRange;
};

#endif // COMPANIONCHARACTERISTICDATA_H