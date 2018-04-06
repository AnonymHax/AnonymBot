#include "SelectedServerDataMessage.h"

void SelectedServerDataMessage::serialize(Writer *param1)
{
  this->serializeAs_SelectedServerDataMessage(param1);
}

void SelectedServerDataMessage::serializeAs_SelectedServerDataMessage(Writer *param1)
{
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - SelectedServerDataMessage -"<<"Forbidden value (" << this->serverId << ") on element serverId.";
  }
  else
  {
    param1->writeVarShort((int)this->serverId);
    param1->writeUTF(this->address);
    if(this->port < 0 || this->port > 65535)
    {
      qDebug()<<"ERREUR - SelectedServerDataMessage -"<<"Forbidden value (" << this->port << ") on element port.";
    }
    else
    {
      param1->writeShort((short)this->port);
      param1->writeBool(this->canCreateNewCharacter);
      param1->writeVarInt((int)this->ticket.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->ticket.size())
      {
        param1->writeByte(this->ticket[_loc2_]);
        _loc2_++;
      }
      return;
    }
  }
}

void SelectedServerDataMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SelectedServerDataMessage(param1);
}

void SelectedServerDataMessage::deserializeAs_SelectedServerDataMessage(Reader *param1)
{
  auto _loc4_ = 0;
  this->serverId = param1->readVarUhShort();
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - SelectedServerDataMessage -"<<"Forbidden value (" << this->serverId << ") on element of SelectedServerDataMessage.serverId.";
  }
  else
  {
    this->address = param1->readUTF();
    this->port = param1->readUShort();
    if(this->port < 0 || this->port > 65535)
    {
      qDebug()<<"ERREUR - SelectedServerDataMessage -"<<"Forbidden value (" << this->port << ") on element of SelectedServerDataMessage.port.";
    }
    else
    {
      this->canCreateNewCharacter = param1->readBool();
      uint _loc2_ = param1->readVarInt();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = param1->readByte();
        this->ticket.append(_loc4_);
        _loc3_++;
      }
      return;
    }
  }
}

SelectedServerDataMessage::SelectedServerDataMessage()
{
  m_type = MessageEnum::SELECTEDSERVERDATAMESSAGE;
}

