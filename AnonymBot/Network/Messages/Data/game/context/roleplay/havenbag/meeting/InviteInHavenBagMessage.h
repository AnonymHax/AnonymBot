#ifndef INVITEINHAVENBAGMESSAGE_H
#define INVITEINHAVENBAGMESSAGE_H

#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"

class InviteInHavenBagMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InviteInHavenBagMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InviteInHavenBagMessage(Reader *param1);
  InviteInHavenBagMessage();

  CharacterMinimalInformations guestInformations;
  bool accept;
};

#endif // INVITEINHAVENBAGMESSAGE_H