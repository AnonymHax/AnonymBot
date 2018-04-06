#include "NicknameRefusedMessage.h"

void NicknameRefusedMessage::serialize(Writer *param1)
{
  this->serializeAs_NicknameRefusedMessage(param1);
}

void NicknameRefusedMessage::serializeAs_NicknameRefusedMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void NicknameRefusedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NicknameRefusedMessage(param1);
}

void NicknameRefusedMessage::deserializeAs_NicknameRefusedMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - NicknameRefusedMessage -"<<"Forbidden value (" << this->reason << ") on element of NicknameRefusedMessage.reason.";
  }
  else
  {
    return;
  }
}

NicknameRefusedMessage::NicknameRefusedMessage()
{
  m_type = MessageEnum::NICKNAMEREFUSEDMESSAGE;
}

