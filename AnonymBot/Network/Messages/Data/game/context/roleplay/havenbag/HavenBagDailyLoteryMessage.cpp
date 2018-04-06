#include "HavenBagDailyLoteryMessage.h"

void HavenBagDailyLoteryMessage::serialize(Writer *param1)
{
  this->serializeAs_HavenBagDailyLoteryMessage(param1);
}

void HavenBagDailyLoteryMessage::serializeAs_HavenBagDailyLoteryMessage(Writer *param1)
{
  param1->writeByte(this->returnType);
  param1->writeUTF(this->tokenId);
}

void HavenBagDailyLoteryMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HavenBagDailyLoteryMessage(param1);
}

void HavenBagDailyLoteryMessage::deserializeAs_HavenBagDailyLoteryMessage(Reader *param1)
{
  this->returnType = param1->readByte();
  if(this->returnType < 0)
  {
    qDebug()<<"ERREUR - HavenBagDailyLoteryMessage -"<<"Forbidden value (" << this->returnType << ") on element of HavenBagDailyLoteryMessage.returnType.";
  }
  else
  {
    this->tokenId = param1->readUTF();
    return;
  }
}

HavenBagDailyLoteryMessage::HavenBagDailyLoteryMessage()
{
  m_type = MessageEnum::HAVENBAGDAILYLOTERYMESSAGE;
}

