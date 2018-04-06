#ifndef GAMEACTIONFIGHTCASTREQUESTMESSAGE_H
#define GAMEACTIONFIGHTCASTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameActionFightCastRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightCastRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightCastRequestMessage(Reader *param1);
  GameActionFightCastRequestMessage();

  uint spellId;
  int cellId;
};

#endif // GAMEACTIONFIGHTCASTREQUESTMESSAGE_H