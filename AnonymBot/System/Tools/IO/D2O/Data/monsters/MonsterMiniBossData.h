#ifndef MONSTERMINIBOSSDATA_H
#define MONSTERMINIBOSSDATA_H

#include "System/Tools/IO/D2O/AbstractGameData.h"

class MonsterMiniBossData : public AbstractGameData
{
public:
  int getId() const;
  int getMonsterReplacingId() const;
  virtual void loadData(const QList<Field*> &fields, I18nFile *I18n);

  int m_id;
  int m_monsterReplacingId;
};

#endif // MONSTERMINIBOSSDATA_H