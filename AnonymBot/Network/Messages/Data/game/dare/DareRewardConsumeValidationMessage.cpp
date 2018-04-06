#include "DareRewardConsumeValidationMessage.h"

void DareRewardConsumeValidationMessage::serialize(Writer *param1)
{
  this->serializeAs_DareRewardConsumeValidationMessage(param1);
}

void DareRewardConsumeValidationMessage::serializeAs_DareRewardConsumeValidationMessage(Writer *param1)
{
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareRewardConsumeValidationMessage -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    param1->writeByte(this->type);
    return;
  }
}

void DareRewardConsumeValidationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareRewardConsumeValidationMessage(param1);
}

void DareRewardConsumeValidationMessage::deserializeAs_DareRewardConsumeValidationMessage(Reader *param1)
{
  this->dareId = param1->readDouble();
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareRewardConsumeValidationMessage -"<<"Forbidden value (" << this->dareId << ") on element of DareRewardConsumeValidationMessage.dareId.";
  }
  else
  {
    this->type = param1->readByte();
    if(this->type < 0)
    {
      qDebug()<<"ERREUR - DareRewardConsumeValidationMessage -"<<"Forbidden value (" << this->type << ") on element of DareRewardConsumeValidationMessage.type.";
    }
    else
    {
      return;
    }
  }
}

DareRewardConsumeValidationMessage::DareRewardConsumeValidationMessage()
{
  m_type = MessageEnum::DAREREWARDCONSUMEVALIDATIONMESSAGE;
}

