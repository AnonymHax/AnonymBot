#ifndef GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE_H
#define GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayPlayerFightRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayPlayerFightRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayPlayerFightRequestMessage(Reader *param1);
  GameRolePlayPlayerFightRequestMessage();

  double targetId;
  int targetCellId;
  bool friendly;
};

#endif // GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE_H