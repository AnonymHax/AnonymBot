#ifndef CHATERRORMESSAGE_H
#define CHATERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChatErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChatErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChatErrorMessage(Reader *param1);
  ChatErrorMessage();

  uint reason;
};

#endif // CHATERRORMESSAGE_H