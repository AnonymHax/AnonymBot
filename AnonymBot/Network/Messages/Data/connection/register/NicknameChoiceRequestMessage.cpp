#include "NicknameChoiceRequestMessage.h"

void NicknameChoiceRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_NicknameChoiceRequestMessage(param1);
}

void NicknameChoiceRequestMessage::serializeAs_NicknameChoiceRequestMessage(Writer *param1)
{
  param1->writeUTF(this->nickname);
}

void NicknameChoiceRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NicknameChoiceRequestMessage(param1);
}

void NicknameChoiceRequestMessage::deserializeAs_NicknameChoiceRequestMessage(Reader *param1)
{
  this->nickname = param1->readUTF();
}

NicknameChoiceRequestMessage::NicknameChoiceRequestMessage()
{
  m_type = MessageEnum::NICKNAMECHOICEREQUESTMESSAGE;
}

