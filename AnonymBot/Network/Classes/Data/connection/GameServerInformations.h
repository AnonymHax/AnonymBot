#ifndef GAMESERVERINFORMATIONS_H
#define GAMESERVERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class GameServerInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameServerInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameServerInformations(Reader *param1);
  GameServerInformations();
  bool operator==(const GameServerInformations &compared);

  uint id;
  int type;
  uint status;
  uint completion;
  bool isSelectable;
  uint charactersCount;
  uint charactersSlots;
  double date;
};

#endif // GAMESERVERINFORMATIONS_H