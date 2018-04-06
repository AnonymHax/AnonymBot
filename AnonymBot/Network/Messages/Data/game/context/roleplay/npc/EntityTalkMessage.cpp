#include "EntityTalkMessage.h"

void EntityTalkMessage::serialize(Writer *param1)
{
  this->serializeAs_EntityTalkMessage(param1);
}

void EntityTalkMessage::serializeAs_EntityTalkMessage(Writer *param1)
{
  if(this->entityId < -9.007199254740992E15 || this->entityId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - EntityTalkMessage -"<<"Forbidden value (" << this->entityId << ") on element entityId.";
  }
  else
  {
    param1->writeDouble(this->entityId);
    if(this->textId < 0)
    {
      qDebug()<<"ERREUR - EntityTalkMessage -"<<"Forbidden value (" << this->textId << ") on element textId.";
    }
    else
    {
      param1->writeVarShort((int)this->textId);
      param1->writeShort((short)this->parameters.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->parameters.size())
      {
        param1->writeUTF(this->parameters[_loc2_]);
        _loc2_++;
      }
      return;
    }
  }
}

void EntityTalkMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EntityTalkMessage(param1);
}

void EntityTalkMessage::deserializeAs_EntityTalkMessage(Reader *param1)
{
  QString _loc4_ ;
  this->entityId = param1->readDouble();
  if(this->entityId < -9.007199254740992E15 || this->entityId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - EntityTalkMessage -"<<"Forbidden value (" << this->entityId << ") on element of EntityTalkMessage.entityId.";
  }
  else
  {
    this->textId = param1->readVarUhShort();
    if(this->textId < 0)
    {
      qDebug()<<"ERREUR - EntityTalkMessage -"<<"Forbidden value (" << this->textId << ") on element of EntityTalkMessage.textId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = param1->readUTF();
        this->parameters.append(_loc4_);
        _loc3_++;
      }
      return;
    }
  }
}

EntityTalkMessage::EntityTalkMessage()
{
  m_type = MessageEnum::ENTITYTALKMESSAGE;
}

