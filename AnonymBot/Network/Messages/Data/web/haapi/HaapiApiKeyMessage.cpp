#include "HaapiApiKeyMessage.h"

void HaapiApiKeyMessage::serialize(Writer *param1)
{
  this->serializeAs_HaapiApiKeyMessage(param1);
}

void HaapiApiKeyMessage::serializeAs_HaapiApiKeyMessage(Writer *param1)
{
  param1->writeByte(this->returnType);
  param1->writeByte(this->keyType);
  param1->writeUTF(this->token);
}

void HaapiApiKeyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HaapiApiKeyMessage(param1);
}

void HaapiApiKeyMessage::deserializeAs_HaapiApiKeyMessage(Reader *param1)
{
  this->returnType = param1->readByte();
  if(this->returnType < 0)
  {
    qDebug()<<"ERREUR - HaapiApiKeyMessage -"<<"Forbidden value (" << this->returnType << ") on element of HaapiApiKeyMessage.returnType.";
  }
  else
  {
    this->keyType = param1->readByte();
    if(this->keyType < 0)
    {
      qDebug()<<"ERREUR - HaapiApiKeyMessage -"<<"Forbidden value (" << this->keyType << ") on element of HaapiApiKeyMessage.keyType.";
    }
    else
    {
      this->token = param1->readUTF();
      return;
    }
  }
}

HaapiApiKeyMessage::HaapiApiKeyMessage()
{
  m_type = MessageEnum::HAAPIAPIKEYMESSAGE;
}

