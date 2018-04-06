#include "KrosmasterTransferRequestMessage.h"

void KrosmasterTransferRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_KrosmasterTransferRequestMessage(param1);
}

void KrosmasterTransferRequestMessage::serializeAs_KrosmasterTransferRequestMessage(Writer *param1)
{
  param1->writeUTF(this->uid);
}

void KrosmasterTransferRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KrosmasterTransferRequestMessage(param1);
}

void KrosmasterTransferRequestMessage::deserializeAs_KrosmasterTransferRequestMessage(Reader *param1)
{
  this->uid = param1->readUTF();
}

KrosmasterTransferRequestMessage::KrosmasterTransferRequestMessage()
{
  m_type = MessageEnum::KROSMASTERTRANSFERREQUESTMESSAGE;
}

