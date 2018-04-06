#ifndef PARTYKICKEDBYMESSAGE_H
#define PARTYKICKEDBYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyKickedByMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyKickedByMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyKickedByMessage(Reader *param1);
  PartyKickedByMessage();

  double kickerId;
};

#endif // PARTYKICKEDBYMESSAGE_H