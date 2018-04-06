#include "AllianceCreationResultMessage.h"

void AllianceCreationResultMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceCreationResultMessage(param1);
}

void AllianceCreationResultMessage::serializeAs_AllianceCreationResultMessage(Writer *param1)
{
  param1->writeByte(this->result);
}

void AllianceCreationResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceCreationResultMessage(param1);
}

void AllianceCreationResultMessage::deserializeAs_AllianceCreationResultMessage(Reader *param1)
{
  this->result = param1->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - AllianceCreationResultMessage -"<<"Forbidden value (" << this->result << ") on element of AllianceCreationResultMessage.result.";
  }
  else
  {
    return;
  }
}

AllianceCreationResultMessage::AllianceCreationResultMessage()
{
  m_type = MessageEnum::ALLIANCECREATIONRESULTMESSAGE;
}

