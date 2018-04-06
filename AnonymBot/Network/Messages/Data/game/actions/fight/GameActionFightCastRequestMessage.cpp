#include "GameActionFightCastRequestMessage.h"

void GameActionFightCastRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightCastRequestMessage(param1);
}

void GameActionFightCastRequestMessage::serializeAs_GameActionFightCastRequestMessage(Writer *param1)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCastRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  else
  {
    param1->writeVarShort((int)this->spellId);
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightCastRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
    }
    else
    {
      param1->writeShort((short)this->cellId);
      return;
    }
  }
}

void GameActionFightCastRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightCastRequestMessage(param1);
}

void GameActionFightCastRequestMessage::deserializeAs_GameActionFightCastRequestMessage(Reader *param1)
{
  this->spellId = param1->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCastRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightCastRequestMessage.spellId.";
  }
  else
  {
    this->cellId = param1->readShort();
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightCastRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightCastRequestMessage.cellId.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightCastRequestMessage::GameActionFightCastRequestMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCASTREQUESTMESSAGE;
  m_needsHash = true;
}

