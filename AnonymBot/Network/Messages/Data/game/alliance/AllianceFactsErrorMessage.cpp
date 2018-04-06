#include "AllianceFactsErrorMessage.h"

void AllianceFactsErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceFactsErrorMessage(param1);
}

void AllianceFactsErrorMessage::serializeAs_AllianceFactsErrorMessage(Writer *param1)
{
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsErrorMessage -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  else
  {
    param1->writeVarInt((int)this->allianceId);
    return;
  }
}

void AllianceFactsErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceFactsErrorMessage(param1);
}

void AllianceFactsErrorMessage::deserializeAs_AllianceFactsErrorMessage(Reader *param1)
{
  this->allianceId = param1->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - AllianceFactsErrorMessage -"<<"Forbidden value (" << this->allianceId << ") on element of AllianceFactsErrorMessage.allianceId.";
  }
  else
  {
    return;
  }
}

AllianceFactsErrorMessage::AllianceFactsErrorMessage()
{
  m_type = MessageEnum::ALLIANCEFACTSERRORMESSAGE;
}

