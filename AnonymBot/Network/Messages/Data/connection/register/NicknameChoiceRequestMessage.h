#ifndef NICKNAMECHOICEREQUESTMESSAGE_H
#define NICKNAMECHOICEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NicknameChoiceRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NicknameChoiceRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NicknameChoiceRequestMessage(Reader *param1);
  NicknameChoiceRequestMessage();

  QString nickname;
};

#endif // NICKNAMECHOICEREQUESTMESSAGE_H