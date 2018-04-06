#include "ServerSettingsMessage.h"

void ServerSettingsMessage::serialize(Writer *param1)
{
  this->serializeAs_ServerSettingsMessage(param1);
}

void ServerSettingsMessage::serializeAs_ServerSettingsMessage(Writer *param1)
{
  param1->writeUTF(this->lang);
  if(this->community < 0)
  {
    qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->community << ") on element community.";
  }
  else
  {
    param1->writeByte(this->community);
    param1->writeByte(this->gameType);
    if(this->arenaLeaveBanTime < 0)
    {
      qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->arenaLeaveBanTime << ") on element arenaLeaveBanTime.";
    }
    else
    {
      param1->writeVarShort((int)this->arenaLeaveBanTime);
      return;
    }
  }
}

void ServerSettingsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ServerSettingsMessage(param1);
}

void ServerSettingsMessage::deserializeAs_ServerSettingsMessage(Reader *param1)
{
  this->lang = param1->readUTF();
  this->community = param1->readByte();
  if(this->community < 0)
  {
    qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->community << ") on element of ServerSettingsMessage.community.";
  }
  else
  {
    this->gameType = param1->readByte();
    this->arenaLeaveBanTime = param1->readVarUhShort();
    if(this->arenaLeaveBanTime < 0)
    {
      qDebug()<<"ERREUR - ServerSettingsMessage -"<<"Forbidden value (" << this->arenaLeaveBanTime << ") on element of ServerSettingsMessage.arenaLeaveBanTime.";
    }
    else
    {
      return;
    }
  }
}

ServerSettingsMessage::ServerSettingsMessage()
{
  m_type = MessageEnum::SERVERSETTINGSMESSAGE;
}

