#ifndef GAMEROLEPLAYARENAUNREGISTERMESSAGE_H
#define GAMEROLEPLAYARENAUNREGISTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayArenaUnregisterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaUnregisterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaUnregisterMessage(Reader *param1);
  GameRolePlayArenaUnregisterMessage();
};

#endif // GAMEROLEPLAYARENAUNREGISTERMESSAGE_H