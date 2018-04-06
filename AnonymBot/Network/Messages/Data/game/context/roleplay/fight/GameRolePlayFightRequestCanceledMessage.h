#ifndef GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE_H
#define GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayFightRequestCanceledMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayFightRequestCanceledMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayFightRequestCanceledMessage(Reader *param1);
  GameRolePlayFightRequestCanceledMessage();

  int fightId;
  double sourceId;
  double targetId;
};

#endif // GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE_H