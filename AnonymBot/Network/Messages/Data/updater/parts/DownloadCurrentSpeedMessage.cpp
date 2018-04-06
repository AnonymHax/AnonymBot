#include "DownloadCurrentSpeedMessage.h"

void DownloadCurrentSpeedMessage::serialize(Writer *param1)
{
  this->serializeAs_DownloadCurrentSpeedMessage(param1);
}

void DownloadCurrentSpeedMessage::serializeAs_DownloadCurrentSpeedMessage(Writer *param1)
{
  if(this->downloadSpeed < 1 || this->downloadSpeed > 10)
  {
    qDebug()<<"ERREUR - DownloadCurrentSpeedMessage -"<<"Forbidden value (" << this->downloadSpeed << ") on element downloadSpeed.";
  }
  else
  {
    param1->writeByte(this->downloadSpeed);
    return;
  }
}

void DownloadCurrentSpeedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DownloadCurrentSpeedMessage(param1);
}

void DownloadCurrentSpeedMessage::deserializeAs_DownloadCurrentSpeedMessage(Reader *param1)
{
  this->downloadSpeed = param1->readByte();
  if(this->downloadSpeed < 1 || this->downloadSpeed > 10)
  {
    qDebug()<<"ERREUR - DownloadCurrentSpeedMessage -"<<"Forbidden value (" << this->downloadSpeed << ") on element of DownloadCurrentSpeedMessage.downloadSpeed.";
  }
  else
  {
    return;
  }
}

DownloadCurrentSpeedMessage::DownloadCurrentSpeedMessage()
{
  m_type = MessageEnum::DOWNLOADCURRENTSPEEDMESSAGE;
}

