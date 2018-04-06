#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include "Network/Classes/AbstractClass.h"

class PlayerStatus : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PlayerStatus(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PlayerStatus(Reader *param1);
  PlayerStatus();
  bool operator==(const PlayerStatus &compared);

  uint statusId;
};

#endif // PLAYERSTATUS_H