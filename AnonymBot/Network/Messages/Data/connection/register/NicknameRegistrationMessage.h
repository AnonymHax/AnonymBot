#ifndef NICKNAMEREGISTRATIONMESSAGE_H
#define NICKNAMEREGISTRATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NicknameRegistrationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NicknameRegistrationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NicknameRegistrationMessage(Reader *param1);
  NicknameRegistrationMessage();
};

#endif // NICKNAMEREGISTRATIONMESSAGE_H