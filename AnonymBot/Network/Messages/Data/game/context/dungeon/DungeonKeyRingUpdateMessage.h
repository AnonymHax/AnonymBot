#ifndef DUNGEONKEYRINGUPDATEMESSAGE_H
#define DUNGEONKEYRINGUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DungeonKeyRingUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonKeyRingUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonKeyRingUpdateMessage(Reader *param1);
  DungeonKeyRingUpdateMessage();

  uint dungeonId;
  bool available;
};

#endif // DUNGEONKEYRINGUPDATEMESSAGE_H