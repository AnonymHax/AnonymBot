#ifndef CREATUREBONETYPEDATA_H
#define CREATUREBONETYPEDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class CreatureBoneTypeData : public AbstractGameData
{
public:
  int getId() const;
  int getCreatureBoneId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_creatureBoneId;
};

#endif // CREATUREBONETYPEDATA_H