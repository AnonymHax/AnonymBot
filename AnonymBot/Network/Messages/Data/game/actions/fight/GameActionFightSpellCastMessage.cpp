#include "GameActionFightSpellCastMessage.h"

void GameActionFightSpellCastMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightSpellCastMessage(param1);
}

void GameActionFightSpellCastMessage::serializeAs_GameActionFightSpellCastMessage(Writer *param1)
{
  AbstractGameActionFightTargetedAbilityMessage::serializeAs_AbstractGameActionFightTargetedAbilityMessage(param1);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCastMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  else
  {
    param1->writeVarShort((int)this->spellId);
    if(this->spellLevel < 1 || this->spellLevel > 200)
    {
      qDebug()<<"ERREUR - GameActionFightSpellCastMessage -"<<"Forbidden value (" << this->spellLevel << ") on element spellLevel.";
    }
    else
    {
      param1->writeShort((short)this->spellLevel);
      param1->writeShort((short)this->portalsIds.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->portalsIds.size())
      {
        param1->writeShort((short)this->portalsIds[_loc2_]);
        _loc2_++;
      }
      return;
    }
  }
}

void GameActionFightSpellCastMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightSpellCastMessage(param1);
}

void GameActionFightSpellCastMessage::deserializeAs_GameActionFightSpellCastMessage(Reader *param1)
{
  auto _loc4_ = 0;
  AbstractGameActionFightTargetedAbilityMessage::deserialize(param1);
  this->spellId = param1->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCastMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightSpellCastMessage.spellId.";
  }
  else
  {
    this->spellLevel = param1->readShort();
    if(this->spellLevel < 1 || this->spellLevel > 200)
    {
      qDebug()<<"ERREUR - GameActionFightSpellCastMessage -"<<"Forbidden value (" << this->spellLevel << ") on element of GameActionFightSpellCastMessage.spellLevel.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = param1->readShort();
        this->portalsIds.append(_loc4_);
        _loc3_++;
      }
      return;
    }
  }
}

GameActionFightSpellCastMessage::GameActionFightSpellCastMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSPELLCASTMESSAGE;
}

