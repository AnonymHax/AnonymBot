#include "TeleportOnSameMapMessage.h"

void TeleportOnSameMapMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportOnSameMapMessage(param1);
}

void TeleportOnSameMapMessage::serializeAs_TeleportOnSameMapMessage(Writer *param1)
{
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportOnSameMapMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->cellId < 0 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - TeleportOnSameMapMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
    }
    else
    {
      param1->writeVarShort((int)this->cellId);
      return;
    }
  }
}

void TeleportOnSameMapMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportOnSameMapMessage(param1);
}

void TeleportOnSameMapMessage::deserializeAs_TeleportOnSameMapMessage(Reader *param1)
{
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportOnSameMapMessage -"<<"Forbidden value (" << this->targetId << ") on element of TeleportOnSameMapMessage.targetId.";
  }
  else
  {
    this->cellId = param1->readVarUhShort();
    if(this->cellId < 0 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - TeleportOnSameMapMessage -"<<"Forbidden value (" << this->cellId << ") on element of TeleportOnSameMapMessage.cellId.";
    }
    else
    {
      return;
    }
  }
}

TeleportOnSameMapMessage::TeleportOnSameMapMessage()
{
  m_type = MessageEnum::TELEPORTONSAMEMAPMESSAGE;
}

