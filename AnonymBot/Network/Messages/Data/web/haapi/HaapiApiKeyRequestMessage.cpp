#include "HaapiApiKeyRequestMessage.h"

void HaapiApiKeyRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HaapiApiKeyRequestMessage(param1);
}

void HaapiApiKeyRequestMessage::serializeAs_HaapiApiKeyRequestMessage(Writer *param1)
{
  param1->writeByte(this->keyType);
}

void HaapiApiKeyRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HaapiApiKeyRequestMessage(param1);
}

void HaapiApiKeyRequestMessage::deserializeAs_HaapiApiKeyRequestMessage(Reader *param1)
{
  this->keyType = param1->readByte();
  if(this->keyType < 0)
  {
    qDebug()<<"ERREUR - HaapiApiKeyRequestMessage -"<<"Forbidden value (" << this->keyType << ") on element of HaapiApiKeyRequestMessage.keyType.";
  }
  else
  {
    return;
  }
}

HaapiApiKeyRequestMessage::HaapiApiKeyRequestMessage()
{
  m_type = MessageEnum::HAAPIAPIKEYREQUESTMESSAGE;
}

