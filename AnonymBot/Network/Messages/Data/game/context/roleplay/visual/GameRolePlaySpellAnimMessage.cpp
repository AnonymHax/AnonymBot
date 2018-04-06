#include "GameRolePlaySpellAnimMessage.h"

void GameRolePlaySpellAnimMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlaySpellAnimMessage(param1);
}

void GameRolePlaySpellAnimMessage::serializeAs_GameRolePlaySpellAnimMessage(Writer *param1)
{
  if(this->casterId < 0 || this->casterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->casterId << ") on element casterId.";
  }
  else
  {
    param1->writeVarLong((double)this->casterId);
    if(this->targetCellId < 0 || this->targetCellId > 559)
    {
      qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->targetCellId << ") on element targetCellId.";
    }
    else
    {
      param1->writeVarShort((int)this->targetCellId);
      if(this->spellId < 0)
      {
        qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
      }
      else
      {
        param1->writeVarShort((int)this->spellId);
        if(this->spellLevel < 1 || this->spellLevel > 200)
        {
          qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->spellLevel << ") on element spellLevel.";
        }
        else
        {
          param1->writeShort((short)this->spellLevel);
          return;
        }
      }
    }
  }
}

void GameRolePlaySpellAnimMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlaySpellAnimMessage(param1);
}

void GameRolePlaySpellAnimMessage::deserializeAs_GameRolePlaySpellAnimMessage(Reader *param1)
{
  this->casterId = param1->readVarUhLong();
  if(this->casterId < 0 || this->casterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->casterId << ") on element of GameRolePlaySpellAnimMessage.casterId.";
  }
  else
  {
    this->targetCellId = param1->readVarUhShort();
    if(this->targetCellId < 0 || this->targetCellId > 559)
    {
      qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->targetCellId << ") on element of GameRolePlaySpellAnimMessage.targetCellId.";
    }
    else
    {
      this->spellId = param1->readVarUhShort();
      if(this->spellId < 0)
      {
        qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameRolePlaySpellAnimMessage.spellId.";
      }
      else
      {
        this->spellLevel = param1->readShort();
        if(this->spellLevel < 1 || this->spellLevel > 200)
        {
          qDebug()<<"ERREUR - GameRolePlaySpellAnimMessage -"<<"Forbidden value (" << this->spellLevel << ") on element of GameRolePlaySpellAnimMessage.spellLevel.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

GameRolePlaySpellAnimMessage::GameRolePlaySpellAnimMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYSPELLANIMMESSAGE;
}

