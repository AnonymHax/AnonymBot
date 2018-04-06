#include "TaxCollectorAttackedResultMessage.h"

void TaxCollectorAttackedResultMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorAttackedResultMessage(param1);
}

void TaxCollectorAttackedResultMessage::serializeAs_TaxCollectorAttackedResultMessage(Writer *param1)
{
  param1->writeBool(this->deadOrAlive);
  this->basicInfos.serializeAs_TaxCollectorBasicInformations(param1);
  this->guild->serializeAs_BasicGuildInformations(param1);
}

void TaxCollectorAttackedResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorAttackedResultMessage(param1);
}

void TaxCollectorAttackedResultMessage::deserializeAs_TaxCollectorAttackedResultMessage(Reader *param1)
{
  this->deadOrAlive = param1->readBool();
  this->basicInfos = TaxCollectorBasicInformations();
  this->basicInfos.deserialize(param1);
  this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guild->deserialize(param1);
}

TaxCollectorAttackedResultMessage::TaxCollectorAttackedResultMessage()
{
  m_type = MessageEnum::TAXCOLLECTORATTACKEDRESULTMESSAGE;
}

