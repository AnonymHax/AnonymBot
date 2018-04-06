#ifndef NICKNAMEREFUSEDMESSAGE_H
#define NICKNAMEREFUSEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NicknameRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NicknameRefusedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NicknameRefusedMessage(Reader *param1);
  NicknameRefusedMessage();

  uint reason;
};

#endif // NICKNAMEREFUSEDMESSAGE_H