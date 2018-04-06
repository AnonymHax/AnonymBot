#include "DownloadPartMessage.h"

void DownloadPartMessage::serialize(Writer *param1)
{
  this->serializeAs_DownloadPartMessage(param1);
}

void DownloadPartMessage::serializeAs_DownloadPartMessage(Writer *param1)
{
  param1->writeUTF(this->id);
}

void DownloadPartMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DownloadPartMessage(param1);
}

void DownloadPartMessage::deserializeAs_DownloadPartMessage(Reader *param1)
{
  this->id = param1->readUTF();
}

DownloadPartMessage::DownloadPartMessage()
{
  m_type = MessageEnum::DOWNLOADPARTMESSAGE;
}

