#include "MountSetXpRatioRequestMessage.h"

void MountSetXpRatioRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MountSetXpRatioRequestMessage(param1);
}

void MountSetXpRatioRequestMessage::serializeAs_MountSetXpRatioRequestMessage(Writer *param1)
{
  if(this->xpRatio < 0)
  {
    qDebug()<<"ERREUR - MountSetXpRatioRequestMessage -"<<"Forbidden value (" << this->xpRatio << ") on element xpRatio.";
  }
  else
  {
    param1->writeByte(this->xpRatio);
    return;
  }
}

void MountSetXpRatioRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountSetXpRatioRequestMessage(param1);
}

void MountSetXpRatioRequestMessage::deserializeAs_MountSetXpRatioRequestMessage(Reader *param1)
{
  this->xpRatio = param1->readByte();
  if(this->xpRatio < 0)
  {
    qDebug()<<"ERREUR - MountSetXpRatioRequestMessage -"<<"Forbidden value (" << this->xpRatio << ") on element of MountSetXpRatioRequestMessage.xpRatio.";
  }
  else
  {
    return;
  }
}

MountSetXpRatioRequestMessage::MountSetXpRatioRequestMessage()
{
  m_type = MessageEnum::MOUNTSETXPRATIOREQUESTMESSAGE;
}

