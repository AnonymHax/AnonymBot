#include "ActorOrientation.h"

void ActorOrientation::serialize(Writer *param1)
{
  this->serializeAs_ActorOrientation(param1);
}

void ActorOrientation::serializeAs_ActorOrientation(Writer *param1)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ActorOrientation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    param1->writeByte(this->direction);
    return;
  }
}

void ActorOrientation::deserialize(Reader *param1)
{
  this->deserializeAs_ActorOrientation(param1);
}

void ActorOrientation::deserializeAs_ActorOrientation(Reader *param1)
{
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ActorOrientation -"<<"Forbidden value (" << this->id << ") on element of ActorOrientation.id.";
  }
  else
  {
    this->direction = param1->readByte();
    if(this->direction < 0)
    {
      qDebug()<<"ERREUR - ActorOrientation -"<<"Forbidden value (" << this->direction << ") on element of ActorOrientation.direction.";
    }
    else
    {
      return;
    }
  }
}

ActorOrientation::ActorOrientation()
{
  m_types<<ClassEnum::ACTORORIENTATION;
}

bool ActorOrientation::operator==(const ActorOrientation &compared)
{
  if(id == compared.id)
  if(direction == compared.direction)
  return true;
  
  return false;
}

