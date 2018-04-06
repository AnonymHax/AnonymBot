#ifndef GAMEROLEPLAYGAMEOVERMESSAGE_H
#define GAMEROLEPLAYGAMEOVERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayGameOverMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayGameOverMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayGameOverMessage(Reader *param1);
  GameRolePlayGameOverMessage();
};

#endif // GAMEROLEPLAYGAMEOVERMESSAGE_H