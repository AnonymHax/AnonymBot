#include "CharacterReportMessage.h"

void CharacterReportMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterReportMessage(param1);
}

void CharacterReportMessage::serializeAs_CharacterReportMessage(Writer *param1)
{
  if(this->reportedId < 0 || this->reportedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterReportMessage -"<<"Forbidden value (" << this->reportedId << ") on element reportedId.";
  }
  else
  {
    param1->writeVarLong((double)this->reportedId);
    if(this->reason < 0)
    {
      qDebug()<<"ERREUR - CharacterReportMessage -"<<"Forbidden value (" << this->reason << ") on element reason.";
    }
    else
    {
      param1->writeByte(this->reason);
      return;
    }
  }
}

void CharacterReportMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterReportMessage(param1);
}

void CharacterReportMessage::deserializeAs_CharacterReportMessage(Reader *param1)
{
  this->reportedId = param1->readVarUhLong();
  if(this->reportedId < 0 || this->reportedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterReportMessage -"<<"Forbidden value (" << this->reportedId << ") on element of CharacterReportMessage.reportedId.";
  }
  else
  {
    this->reason = param1->readByte();
    if(this->reason < 0)
    {
      qDebug()<<"ERREUR - CharacterReportMessage -"<<"Forbidden value (" << this->reason << ") on element of CharacterReportMessage.reason.";
    }
    else
    {
      return;
    }
  }
}

CharacterReportMessage::CharacterReportMessage()
{
  m_type = MessageEnum::CHARACTERREPORTMESSAGE;
}

