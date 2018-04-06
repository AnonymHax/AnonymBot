#ifndef CONTACTLOOKREQUESTBYIDMESSAGE_H
#define CONTACTLOOKREQUESTBYIDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/ContactLookRequestMessage.h"

class ContactLookRequestByIdMessage : public ContactLookRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ContactLookRequestByIdMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ContactLookRequestByIdMessage(Reader *param1);
  ContactLookRequestByIdMessage();

  double playerId;
};

#endif // CONTACTLOOKREQUESTBYIDMESSAGE_H