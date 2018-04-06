#ifndef PARTYNAMESETERRORMESSAGE_H
#define PARTYNAMESETERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyNameSetErrorMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyNameSetErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyNameSetErrorMessage(Reader *param1);
  PartyNameSetErrorMessage();

  uint result;
};

#endif // PARTYNAMESETERRORMESSAGE_H