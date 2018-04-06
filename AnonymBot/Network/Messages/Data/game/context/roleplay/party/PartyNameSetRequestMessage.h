#ifndef PARTYNAMESETREQUESTMESSAGE_H
#define PARTYNAMESETREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyNameSetRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyNameSetRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyNameSetRequestMessage(Reader *param1);
  PartyNameSetRequestMessage();

  QString partyName;
};

#endif // PARTYNAMESETREQUESTMESSAGE_H