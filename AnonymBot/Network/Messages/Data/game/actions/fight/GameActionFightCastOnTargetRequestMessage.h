#ifndef GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE_H
#define GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameActionFightCastOnTargetRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightCastOnTargetRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightCastOnTargetRequestMessage(Reader *param1);
  GameActionFightCastOnTargetRequestMessage();

  uint spellId;
  double targetId;
};

#endif // GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE_H