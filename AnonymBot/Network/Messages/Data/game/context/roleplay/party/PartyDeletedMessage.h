#ifndef PARTYDELETEDMESSAGE_H
#define PARTYDELETEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyDeletedMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyDeletedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyDeletedMessage(Reader *param1);
  PartyDeletedMessage();
};

#endif // PARTYDELETEDMESSAGE_H