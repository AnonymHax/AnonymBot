#ifndef GAMEROLEPLAYARENAREGISTERMESSAGE_H
#define GAMEROLEPLAYARENAREGISTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayArenaRegisterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaRegisterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaRegisterMessage(Reader *param1);
  GameRolePlayArenaRegisterMessage();

  uint battleMode;
};

#endif // GAMEROLEPLAYARENAREGISTERMESSAGE_H