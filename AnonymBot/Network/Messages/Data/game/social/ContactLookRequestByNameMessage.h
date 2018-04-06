#ifndef CONTACTLOOKREQUESTBYNAMEMESSAGE_H
#define CONTACTLOOKREQUESTBYNAMEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/social/ContactLookRequestMessage.h"

class ContactLookRequestByNameMessage : public ContactLookRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ContactLookRequestByNameMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ContactLookRequestByNameMessage(Reader *param1);
  ContactLookRequestByNameMessage();

  QString playerName;
};

#endif // CONTACTLOOKREQUESTBYNAMEMESSAGE_H