#ifndef FIGHTRESULTADDITIONALDATA_H
#define FIGHTRESULTADDITIONALDATA_H

#include "Network/Classes/AbstractClass.h"

class FightResultAdditionalData : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightResultAdditionalData(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightResultAdditionalData(Reader *param1);
  FightResultAdditionalData();
  bool operator==(const FightResultAdditionalData &compared);
};

#endif // FIGHTRESULTADDITIONALDATA_H