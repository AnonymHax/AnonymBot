#include "TeleportRequestMessage.h"

void TeleportRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportRequestMessage(param1);
}

void TeleportRequestMessage::serializeAs_TeleportRequestMessage(Writer *param1)
{
  param1->writeByte(this->teleporterType);
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - TeleportRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  else
  {
    param1->writeInt((int)this->mapId);
    return;
  }
}

void TeleportRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportRequestMessage(param1);
}

void TeleportRequestMessage::deserializeAs_TeleportRequestMessage(Reader *param1)
{
  this->teleporterType = param1->readByte();
  if(this->teleporterType < 0)
  {
    qDebug()<<"ERREUR - TeleportRequestMessage -"<<"Forbidden value (" << this->teleporterType << ") on element of TeleportRequestMessage.teleporterType.";
  }
  else
  {
    this->mapId = param1->readInt();
    if(this->mapId < 0)
    {
      qDebug()<<"ERREUR - TeleportRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element of TeleportRequestMessage.mapId.";
    }
    else
    {
      return;
    }
  }
}

TeleportRequestMessage::TeleportRequestMessage()
{
  m_type = MessageEnum::TELEPORTREQUESTMESSAGE;
}

