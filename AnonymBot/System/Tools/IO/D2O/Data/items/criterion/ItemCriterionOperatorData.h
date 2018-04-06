#ifndef ITEMCRITERIONOPERATORDATA_H
#define ITEMCRITERIONOPERATORDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class ItemCriterionOperatorData : public AbstractGameData
{
public:
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);
};

#endif // ITEMCRITERIONOPERATORDATA_H