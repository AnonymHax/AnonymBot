#ifndef ABSTRACTPARTYEVENTMESSAGE_H
#define ABSTRACTPARTYEVENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class AbstractPartyEventMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractPartyEventMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractPartyEventMessage(Reader *param1);
  AbstractPartyEventMessage();
};

#endif // ABSTRACTPARTYEVENTMESSAGE_H