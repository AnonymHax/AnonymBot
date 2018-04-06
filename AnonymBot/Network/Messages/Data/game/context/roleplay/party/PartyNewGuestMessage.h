#ifndef PARTYNEWGUESTMESSAGE_H
#define PARTYNEWGUESTMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/PartyGuestInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyGuestInformations.h"

class PartyNewGuestMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyNewGuestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyNewGuestMessage(Reader *param1);
  PartyNewGuestMessage();

  QSharedPointer<PartyGuestInformations> guest;
};

#endif // PARTYNEWGUESTMESSAGE_H