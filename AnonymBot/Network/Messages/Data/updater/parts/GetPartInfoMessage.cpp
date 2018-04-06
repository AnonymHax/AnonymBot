#include "GetPartInfoMessage.h"

void GetPartInfoMessage::serialize(Writer *param1)
{
  this->serializeAs_GetPartInfoMessage(param1);
}

void GetPartInfoMessage::serializeAs_GetPartInfoMessage(Writer *param1)
{
  param1->writeUTF(this->id);
}

void GetPartInfoMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GetPartInfoMessage(param1);
}

void GetPartInfoMessage::deserializeAs_GetPartInfoMessage(Reader *param1)
{
  this->id = param1->readUTF();
}

GetPartInfoMessage::GetPartInfoMessage()
{
  m_type = MessageEnum::GETPARTINFOMESSAGE;
}

