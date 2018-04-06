#ifndef PARTYMEMBEREJECTEDMESSAGE_H
#define PARTYMEMBEREJECTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/PartyMemberRemoveMessage.h"

class PartyMemberEjectedMessage : public PartyMemberRemoveMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyMemberEjectedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyMemberEjectedMessage(Reader *param1);
  PartyMemberEjectedMessage();

  double kickerId;
};

#endif // PARTYMEMBEREJECTEDMESSAGE_H