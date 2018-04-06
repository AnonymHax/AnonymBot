#ifndef GAMEROLEPLAYFREESOULREQUESTMESSAGE_H
#define GAMEROLEPLAYFREESOULREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayFreeSoulRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayFreeSoulRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayFreeSoulRequestMessage(Reader *param1);
  GameRolePlayFreeSoulRequestMessage();
};

#endif // GAMEROLEPLAYFREESOULREQUESTMESSAGE_H