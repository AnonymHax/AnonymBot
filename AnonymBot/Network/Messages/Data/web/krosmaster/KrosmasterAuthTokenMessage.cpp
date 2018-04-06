#include "KrosmasterAuthTokenMessage.h"

void KrosmasterAuthTokenMessage::serialize(Writer *param1)
{
  this->serializeAs_KrosmasterAuthTokenMessage(param1);
}

void KrosmasterAuthTokenMessage::serializeAs_KrosmasterAuthTokenMessage(Writer *param1)
{
  param1->writeUTF(this->token);
}

void KrosmasterAuthTokenMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KrosmasterAuthTokenMessage(param1);
}

void KrosmasterAuthTokenMessage::deserializeAs_KrosmasterAuthTokenMessage(Reader *param1)
{
  this->token = param1->readUTF();
}

KrosmasterAuthTokenMessage::KrosmasterAuthTokenMessage()
{
  m_type = MessageEnum::KROSMASTERAUTHTOKENMESSAGE;
}

