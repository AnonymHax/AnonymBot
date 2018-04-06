#include "CompassUpdateMessage.h"

void CompassUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_CompassUpdateMessage(param1);
}

void CompassUpdateMessage::serializeAs_CompassUpdateMessage(Writer *param1)
{
  param1->writeByte(this->type);
  param1->writeShort((short)this->coords->getTypes().last());
  this->coords->serialize(param1);
}

void CompassUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CompassUpdateMessage(param1);
}

void CompassUpdateMessage::deserializeAs_CompassUpdateMessage(Reader *param1)
{
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - CompassUpdateMessage -"<<"Forbidden value (" << this->type << ") on element of CompassUpdateMessage.type.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    this->coords = qSharedPointerCast<MapCoordinates>(ClassManagerSingleton::get()->getClass(_loc2_));
    this->coords->deserialize(param1);
    return;
  }
}

CompassUpdateMessage::CompassUpdateMessage()
{
  m_type = MessageEnum::COMPASSUPDATEMESSAGE;
}

