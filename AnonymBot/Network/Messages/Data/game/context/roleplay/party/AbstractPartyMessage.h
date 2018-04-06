#ifndef ABSTRACTPARTYMESSAGE_H
#define ABSTRACTPARTYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AbstractPartyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractPartyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractPartyMessage(Reader *param1);
  AbstractPartyMessage();

  uint partyId;
};

#endif // ABSTRACTPARTYMESSAGE_H