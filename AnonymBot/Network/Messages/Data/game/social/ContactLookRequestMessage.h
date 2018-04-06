#ifndef CONTACTLOOKREQUESTMESSAGE_H
#define CONTACTLOOKREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ContactLookRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ContactLookRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ContactLookRequestMessage(Reader *param1);
  ContactLookRequestMessage();

  uint requestId;
  uint contactType;
};

#endif // CONTACTLOOKREQUESTMESSAGE_H