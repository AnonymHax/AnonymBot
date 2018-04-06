#ifndef ITEMCRITERIONDATA_H
#define ITEMCRITERIONDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ItemCriterionData : public AbstractGameData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // ITEMCRITERIONDATA_H