#ifndef PARTYNAMEUPDATEMESSAGE_H
#define PARTYNAMEUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyNameUpdateMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyNameUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyNameUpdateMessage(Reader *param1);
  PartyNameUpdateMessage();

  QString partyName;
};

#endif // PARTYNAMEUPDATEMESSAGE_H