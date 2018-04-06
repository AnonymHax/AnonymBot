#include "DownloadErrorMessage.h"

void DownloadErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_DownloadErrorMessage(param1);
}

void DownloadErrorMessage::serializeAs_DownloadErrorMessage(Writer *param1)
{
  param1->writeByte(this->errorId);
  param1->writeUTF(this->message);
  param1->writeUTF(this->helpUrl);
}

void DownloadErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DownloadErrorMessage(param1);
}

void DownloadErrorMessage::deserializeAs_DownloadErrorMessage(Reader *param1)
{
  this->errorId = param1->readByte();
  if(this->errorId < 0)
  {
    qDebug()<<"ERREUR - DownloadErrorMessage -"<<"Forbidden value (" << this->errorId << ") on element of DownloadErrorMessage.errorId.";
  }
  else
  {
    this->message = param1->readUTF();
    this->helpUrl = param1->readUTF();
    return;
  }
}

DownloadErrorMessage::DownloadErrorMessage()
{
  m_type = MessageEnum::DOWNLOADERRORMESSAGE;
}

