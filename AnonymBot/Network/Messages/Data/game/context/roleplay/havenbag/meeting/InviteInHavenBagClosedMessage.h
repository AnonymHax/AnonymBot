#ifndef INVITEINHAVENBAGCLOSEDMESSAGE_H
#define INVITEINHAVENBAGCLOSEDMESSAGE_H

#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"

class InviteInHavenBagClosedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InviteInHavenBagClosedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InviteInHavenBagClosedMessage(Reader *param1);
  InviteInHavenBagClosedMessage();

  CharacterMinimalInformations hostInformations;
};

#endif // INVITEINHAVENBAGCLOSEDMESSAGE_H