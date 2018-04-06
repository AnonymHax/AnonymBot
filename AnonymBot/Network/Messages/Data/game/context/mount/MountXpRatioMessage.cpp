#include "MountXpRatioMessage.h"

void MountXpRatioMessage::serialize(Writer *param1)
{
  this->serializeAs_MountXpRatioMessage(param1);
}

void MountXpRatioMessage::serializeAs_MountXpRatioMessage(Writer *param1)
{
  if(this->ratio < 0)
  {
    qDebug()<<"ERREUR - MountXpRatioMessage -"<<"Forbidden value (" << this->ratio << ") on element ratio.";
  }
  else
  {
    param1->writeByte(this->ratio);
    return;
  }
}

void MountXpRatioMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountXpRatioMessage(param1);
}

void MountXpRatioMessage::deserializeAs_MountXpRatioMessage(Reader *param1)
{
  this->ratio = param1->readByte();
  if(this->ratio < 0)
  {
    qDebug()<<"ERREUR - MountXpRatioMessage -"<<"Forbidden value (" << this->ratio << ") on element of MountXpRatioMessage.ratio.";
  }
  else
  {
    return;
  }
}

MountXpRatioMessage::MountXpRatioMessage()
{
  m_type = MessageEnum::MOUNTXPRATIOMESSAGE;
}

