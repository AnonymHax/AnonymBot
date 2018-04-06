#ifndef PARTYLEAVEMESSAGE_H
#define PARTYLEAVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyLeaveMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyLeaveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyLeaveMessage(Reader *param1);
  PartyLeaveMessage();
};

#endif // PARTYLEAVEMESSAGE_H