#ifndef GAMEDATAPADDOCKOBJECTADDMESSAGE_H
#define GAMEDATAPADDOCKOBJECTADDMESSAGE_H

#include "Network/Classes/Data/game/paddock/PaddockItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/paddock/PaddockItem.h"

class GameDataPaddockObjectAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameDataPaddockObjectAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameDataPaddockObjectAddMessage(Reader *param1);
  GameDataPaddockObjectAddMessage();

  PaddockItem paddockItemDescription;
};

#endif // GAMEDATAPADDOCKOBJECTADDMESSAGE_H