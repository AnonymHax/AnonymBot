#ifndef INVITEINHAVENBAGOFFERMESSAGE_H
#define INVITEINHAVENBAGOFFERMESSAGE_H

#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"

class InviteInHavenBagOfferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InviteInHavenBagOfferMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InviteInHavenBagOfferMessage(Reader *param1);
  InviteInHavenBagOfferMessage();

  CharacterMinimalInformations hostInformations;
  int timeLeftBeforeCancel;
};

#endif // INVITEINHAVENBAGOFFERMESSAGE_H