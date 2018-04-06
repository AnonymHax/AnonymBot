#ifndef DUNGEONKEYRINGMESSAGE_H
#define DUNGEONKEYRINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DungeonKeyRingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonKeyRingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonKeyRingMessage(Reader *param1);
  DungeonKeyRingMessage();

  QList<uint> availables;
  QList<uint> unavailables;
};

#endif // DUNGEONKEYRINGMESSAGE_H