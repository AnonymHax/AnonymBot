#include "AllianceFactsRequestMessage.h"

void AllianceFactsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceFactsRequestMessage(param1);
}

void AllianceFactsRequestMessage::serializeAs_AllianceFactsRequestMessage(Writer *param1)
{
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsRequestMessage -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  else
  {
    param1->writeVarInt((int)this->allianceId);
    return;
  }
}

void AllianceFactsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceFactsRequestMessage(param1);
}

void AllianceFactsRequestMessage::deserializeAs_AllianceFactsRequestMessage(Reader *param1)
{
  this->allianceId = param1->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsRequestMessage -"<<"Forbidden value (" << this->allianceId << ") on element of AllianceFactsRequestMessage.allianceId.";
  }
  else
  {
    return;
  }
}

AllianceFactsRequestMessage::AllianceFactsRequestMessage()
{
  m_type = MessageEnum::ALLIANCEFACTSREQUESTMESSAGE;
}

