#ifndef NICKNAMEACCEPTEDMESSAGE_H
#define NICKNAMEACCEPTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NicknameAcceptedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NicknameAcceptedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NicknameAcceptedMessage(Reader *param1);
  NicknameAcceptedMessage();
};

#endif // NICKNAMEACCEPTEDMESSAGE_H