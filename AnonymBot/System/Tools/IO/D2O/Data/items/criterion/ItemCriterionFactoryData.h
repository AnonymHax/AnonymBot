#ifndef ITEMCRITERIONFACTORYDATA_H
#define ITEMCRITERIONFACTORYDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ItemCriterionFactoryData : public AbstractGameData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // ITEMCRITERIONFACTORYDATA_H