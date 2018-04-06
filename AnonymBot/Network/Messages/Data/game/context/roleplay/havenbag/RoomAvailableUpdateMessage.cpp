#include "RoomAvailableUpdateMessage.h"

void RoomAvailableUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_RoomAvailableUpdateMessage(param1);
}

void RoomAvailableUpdateMessage::serializeAs_RoomAvailableUpdateMessage(Writer *param1)
{
  if(this->nbRoom < 0 || this->nbRoom > 255)
  {
    qDebug()<<"ERREUR - RoomAvailableUpdateMessage -"<<"Forbidden value (" << this->nbRoom << ") on element nbRoom.";
  }
  else
  {
    param1->writeByte(this->nbRoom);
    return;
  }
}

void RoomAvailableUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_RoomAvailableUpdateMessage(param1);
}

void RoomAvailableUpdateMessage::deserializeAs_RoomAvailableUpdateMessage(Reader *param1)
{
  this->nbRoom = param1->readUByte();
  if(this->nbRoom < 0 || this->nbRoom > 255)
  {
    qDebug()<<"ERREUR - RoomAvailableUpdateMessage -"<<"Forbidden value (" << this->nbRoom << ") on element of RoomAvailableUpdateMessage.nbRoom.";
  }
  else
  {
    return;
  }
}

RoomAvailableUpdateMessage::RoomAvailableUpdateMessage()
{
  m_type = MessageEnum::ROOMAVAILABLEUPDATEMESSAGE;
}

