#ifndef GAMEROLEPLAYTAXCOLLECTORFIGHTREQUESTMESSAGE_H
#define GAMEROLEPLAYTAXCOLLECTORFIGHTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayTaxCollectorFightRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayTaxCollectorFightRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayTaxCollectorFightRequestMessage(Reader *param1);
  GameRolePlayTaxCollectorFightRequestMessage();

  int taxCollectorId;
};

#endif // GAMEROLEPLAYTAXCOLLECTORFIGHTREQUESTMESSAGE_H