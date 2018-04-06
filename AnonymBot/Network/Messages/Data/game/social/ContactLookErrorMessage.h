#ifndef CONTACTLOOKERRORMESSAGE_H
#define CONTACTLOOKERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ContactLookErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ContactLookErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ContactLookErrorMessage(Reader *param1);
  ContactLookErrorMessage();

  uint requestId;
};

#endif // CONTACTLOOKERRORMESSAGE_H