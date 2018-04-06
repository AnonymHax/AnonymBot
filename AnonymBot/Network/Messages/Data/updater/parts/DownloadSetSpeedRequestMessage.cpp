#include "DownloadSetSpeedRequestMessage.h"

void DownloadSetSpeedRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_DownloadSetSpeedRequestMessage(param1);
}

void DownloadSetSpeedRequestMessage::serializeAs_DownloadSetSpeedRequestMessage(Writer *param1)
{
  if(this->downloadSpeed < 1 || this->downloadSpeed > 10)
  {
    qDebug()<<"ERREUR - DownloadSetSpeedRequestMessage -"<<"Forbidden value (" << this->downloadSpeed << ") on element downloadSpeed.";
  }
  else
  {
    param1->writeByte(this->downloadSpeed);
    return;
  }
}

void DownloadSetSpeedRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DownloadSetSpeedRequestMessage(param1);
}

void DownloadSetSpeedRequestMessage::deserializeAs_DownloadSetSpeedRequestMessage(Reader *param1)
{
  this->downloadSpeed = param1->readByte();
  if(this->downloadSpeed < 1 || this->downloadSpeed > 10)
  {
    qDebug()<<"ERREUR - DownloadSetSpeedRequestMessage -"<<"Forbidden value (" << this->downloadSpeed << ") on element of DownloadSetSpeedRequestMessage.downloadSpeed.";
  }
  else
  {
    return;
  }
}

DownloadSetSpeedRequestMessage::DownloadSetSpeedRequestMessage()
{
  m_type = MessageEnum::DOWNLOADSETSPEEDREQUESTMESSAGE;
}

