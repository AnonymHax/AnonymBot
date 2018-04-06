#ifndef SETCHARACTERRESTRICTIONSMESSAGE_H
#define SETCHARACTERRESTRICTIONSMESSAGE_H

#include "Network/Classes/Data/game/character/restriction/ActorRestrictionsInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/restriction/ActorRestrictionsInformations.h"

class SetCharacterRestrictionsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SetCharacterRestrictionsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SetCharacterRestrictionsMessage(Reader *param1);
  SetCharacterRestrictionsMessage();

  double actorId;
  ActorRestrictionsInformations restrictions;
};

#endif // SETCHARACTERRESTRICTIONSMESSAGE_H