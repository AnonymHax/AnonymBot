#ifndef GAMEDATAPADDOCKOBJECTLISTADDMESSAGE_H
#define GAMEDATAPADDOCKOBJECTLISTADDMESSAGE_H

#include "Network/Classes/Data/game/paddock/PaddockItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/paddock/PaddockItem.h"

class GameDataPaddockObjectListAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameDataPaddockObjectListAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameDataPaddockObjectListAddMessage(Reader *param1);
  GameDataPaddockObjectListAddMessage();

  QList<PaddockItem> paddockItemDescription;
};

#endif // GAMEDATAPADDOCKOBJECTLISTADDMESSAGE_H