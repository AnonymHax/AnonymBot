#include "HouseKickRequestMessage.h"

void HouseKickRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseKickRequestMessage(param1);
}

void HouseKickRequestMessage::serializeAs_HouseKickRequestMessage(Writer *param1)
{
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseKickRequestMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarLong((double)this->id);
    return;
  }
}

void HouseKickRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseKickRequestMessage(param1);
}

void HouseKickRequestMessage::deserializeAs_HouseKickRequestMessage(Reader *param1)
{
  this->id = param1->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HouseKickRequestMessage -"<<"Forbidden value (" << this->id << ") on element of HouseKickRequestMessage.id.";
  }
  else
  {
    return;
  }
}

HouseKickRequestMessage::HouseKickRequestMessage()
{
  m_type = MessageEnum::HOUSEKICKREQUESTMESSAGE;
}

