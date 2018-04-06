#include "KrosmasterTransferMessage.h"

void KrosmasterTransferMessage::serialize(Writer *param1)
{
  this->serializeAs_KrosmasterTransferMessage(param1);
}

void KrosmasterTransferMessage::serializeAs_KrosmasterTransferMessage(Writer *param1)
{
  param1->writeUTF(this->uid);
  param1->writeByte(this->failure);
}

void KrosmasterTransferMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KrosmasterTransferMessage(param1);
}

void KrosmasterTransferMessage::deserializeAs_KrosmasterTransferMessage(Reader *param1)
{
  this->uid = param1->readUTF();
  this->failure = param1->readByte();
  if(this->failure < 0)
  {
    qDebug()<<"ERREUR - KrosmasterTransferMessage -"<<"Forbidden value (" << this->failure << ") on element of KrosmasterTransferMessage.failure.";
  }
  else
  {
    return;
  }
}

KrosmasterTransferMessage::KrosmasterTransferMessage()
{
  m_type = MessageEnum::KROSMASTERTRANSFERMESSAGE;
}

