#include "SelectedServerRefusedMessage.h"

void SelectedServerRefusedMessage::serialize(Writer *param1)
{
  this->serializeAs_SelectedServerRefusedMessage(param1);
}

void SelectedServerRefusedMessage::serializeAs_SelectedServerRefusedMessage(Writer *param1)
{
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - SelectedServerRefusedMessage -"<<"Forbidden value (" << this->serverId << ") on element serverId.";
  }
  else
  {
    param1->writeVarShort((int)this->serverId);
    param1->writeByte(this->error);
    param1->writeByte(this->serverStatus);
    return;
  }
}

void SelectedServerRefusedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SelectedServerRefusedMessage(param1);
}

void SelectedServerRefusedMessage::deserializeAs_SelectedServerRefusedMessage(Reader *param1)
{
  this->serverId = param1->readVarUhShort();
  if(this->serverId < 0)
  {
    qDebug()<<"ERREUR - SelectedServerRefusedMessage -"<<"Forbidden value (" << this->serverId << ") on element of SelectedServerRefusedMessage.serverId.";
  }
  else
  {
    this->error = param1->readByte();
    if(this->error < 0)
    {
      qDebug()<<"ERREUR - SelectedServerRefusedMessage -"<<"Forbidden value (" << this->error << ") on element of SelectedServerRefusedMessage.error.";
    }
    else
    {
      this->serverStatus = param1->readByte();
      if(this->serverStatus < 0)
      {
        qDebug()<<"ERREUR - SelectedServerRefusedMessage -"<<"Forbidden value (" << this->serverStatus << ") on element of SelectedServerRefusedMessage.serverStatus.";
      }
      else
      {
        return;
      }
    }
  }
}

SelectedServerRefusedMessage::SelectedServerRefusedMessage()
{
  m_type = MessageEnum::SELECTEDSERVERREFUSEDMESSAGE;
}

