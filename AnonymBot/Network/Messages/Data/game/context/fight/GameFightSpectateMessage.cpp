#include "GameFightSpectateMessage.h"

void GameFightSpectateMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightSpectateMessage(param1);
}

void GameFightSpectateMessage::serializeAs_GameFightSpectateMessage(Writer *param1)
{
  param1->writeShort((short)this->effects.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->effects.size())
  {
    qSharedPointerCast<FightDispellableEffectExtendedInformations>(this->effects[_loc2_])->serializeAs_FightDispellableEffectExtendedInformations(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->marks.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->marks.size())
  {
    (this->marks[_loc3_]).serializeAs_GameActionMark(param1);
    _loc3_++;
  }
  if(this->gameTurn < 0)
  {
    qDebug()<<"ERREUR - GameFightSpectateMessage -"<<"Forbidden value (" << this->gameTurn << ") on element gameTurn.";
  }
  else
  {
    param1->writeVarShort((int)this->gameTurn);
    if(this->fightStart < 0)
    {
      qDebug()<<"ERREUR - GameFightSpectateMessage -"<<"Forbidden value (" << this->fightStart << ") on element fightStart.";
    }
    else
    {
      param1->writeInt((int)this->fightStart);
      param1->writeShort((short)this->idols.size());
      uint _loc4_ = 0;
      while(_loc4_ < this->idols.size())
      {
        qSharedPointerCast<Idol>(this->idols[_loc4_])->serializeAs_Idol(param1);
        _loc4_++;
      }
      return;
    }
  }
}

void GameFightSpectateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightSpectateMessage(param1);
}

void GameFightSpectateMessage::deserializeAs_GameFightSpectateMessage(Reader *param1)
{
  QSharedPointer<FightDispellableEffectExtendedInformations> _loc8_ ;
  GameActionMark _loc9_ ;
  QSharedPointer<Idol> _loc10_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc8_ = QSharedPointer<FightDispellableEffectExtendedInformations>(new FightDispellableEffectExtendedInformations() );
    _loc8_->deserialize(param1);
    this->effects.append(_loc8_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc9_ = GameActionMark();
    _loc9_.deserialize(param1);
    this->marks.append(_loc9_);
    _loc5_++;
  }
  this->gameTurn = param1->readVarUhShort();
  if(this->gameTurn < 0)
  {
    qDebug()<<"ERREUR - GameFightSpectateMessage -"<<"Forbidden value (" << this->gameTurn << ") on element of GameFightSpectateMessage.gameTurn.";
  }
  else
  {
    this->fightStart = param1->readInt();
    if(this->fightStart < 0)
    {
      qDebug()<<"ERREUR - GameFightSpectateMessage -"<<"Forbidden value (" << this->fightStart << ") on element of GameFightSpectateMessage.fightStart.";
    }
    else
    {
      uint _loc6_ = param1->readUShort();
      uint _loc7_ = 0;
      while(_loc7_ < _loc6_)
      {
        _loc10_ = QSharedPointer<Idol>(new Idol() );
        _loc10_->deserialize(param1);
        this->idols.append(_loc10_);
        _loc7_++;
      }
      return;
    }
  }
}

GameFightSpectateMessage::GameFightSpectateMessage()
{
  m_type = MessageEnum::GAMEFIGHTSPECTATEMESSAGE;
}

