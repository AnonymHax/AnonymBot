#include "DareRewardConsumeRequestMessage.h"

void DareRewardConsumeRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_DareRewardConsumeRequestMessage(param1);
}

void DareRewardConsumeRequestMessage::serializeAs_DareRewardConsumeRequestMessage(Writer *param1)
{
  if(this->dareId < -9.007199254740992E15 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareRewardConsumeRequestMessage -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    param1->writeByte(this->type);
    return;
  }
}

void DareRewardConsumeRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareRewardConsumeRequestMessage(param1);
}

void DareRewardConsumeRequestMessage::deserializeAs_DareRewardConsumeRequestMessage(Reader *param1)
{
  this->dareId = param1->readDouble();
  if(this->dareId < -9.007199254740992E15 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareRewardConsumeRequestMessage -"<<"Forbidden value (" << this->dareId << ") on element of DareRewardConsumeRequestMessage.dareId.";
  }
  else
  {
    this->type = param1->readByte();
    if(this->type < 0)
    {
      qDebug()<<"ERREUR - DareRewardConsumeRequestMessage -"<<"Forbidden value (" << this->type << ") on element of DareRewardConsumeRequestMessage.type.";
    }
    else
    {
      return;
    }
  }
}

DareRewardConsumeRequestMessage::DareRewardConsumeRequestMessage()
{
  m_type = MessageEnum::DAREREWARDCONSUMEREQUESTMESSAGE;
}

