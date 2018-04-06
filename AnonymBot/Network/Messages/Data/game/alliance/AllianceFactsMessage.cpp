#include "AllianceFactsMessage.h"

void AllianceFactsMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceFactsMessage(param1);
}

void AllianceFactsMessage::serializeAs_AllianceFactsMessage(Writer *param1)
{
  param1->writeShort((short)this->infos->getTypes().last());
  this->infos->serialize(param1);
  param1->writeShort((short)this->guilds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->guilds.size())
  {
    qSharedPointerCast<GuildInAllianceInformations>(this->guilds[_loc2_])->serializeAs_GuildInAllianceInformations(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->controlledSubareaIds.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->controlledSubareaIds.size())
  {
    if(this->controlledSubareaIds[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << this->controlledSubareaIds[_loc3_] << ") on element 3 (starting at 1) of controlledSubareaIds.";
    }
    else
    {
      param1->writeVarShort((int)this->controlledSubareaIds[_loc3_]);
      _loc3_++;
      continue;
    }
  }
  if(this->leaderCharacterId < 0 || this->leaderCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << this->leaderCharacterId << ") on element leaderCharacterId.";
  }
  else
  {
    param1->writeVarLong((double)this->leaderCharacterId);
    param1->writeUTF(this->leaderCharacterName);
    return;
  }
}

void AllianceFactsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceFactsMessage(param1);
}

void AllianceFactsMessage::deserializeAs_AllianceFactsMessage(Reader *param1)
{
  QSharedPointer<GuildInAllianceInformations> _loc7_ ;
  uint _loc8_ = 0;
  uint _loc2_ = param1->readUShort();
  this->infos = qSharedPointerCast<AllianceFactSheetInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->infos->deserialize(param1);
  uint _loc3_ = param1->readUShort();
  uint _loc4_ = 0;
  while(_loc4_ < _loc3_)
  {
    _loc7_ = QSharedPointer<GuildInAllianceInformations>(new GuildInAllianceInformations() );
    _loc7_->deserialize(param1);
    this->guilds.append(_loc7_);
    _loc4_++;
  }
  uint _loc5_ = param1->readUShort();
  uint _loc6_ = 0;
  while(_loc6_ < _loc5_)
  {
    _loc8_ = param1->readVarUhShort();
    if(_loc8_ < 0)
    {
      qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << _loc8_ << ") on elements of controlledSubareaIds.";
    }
    else
    {
      this->controlledSubareaIds.append(_loc8_);
      _loc6_++;
      continue;
    }
  }
  this->leaderCharacterId = param1->readVarUhLong();
  if(this->leaderCharacterId < 0 || this->leaderCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceFactsMessage -"<<"Forbidden value (" << this->leaderCharacterId << ") on element of AllianceFactsMessage.leaderCharacterId.";
  }
  else
  {
    this->leaderCharacterName = param1->readUTF();
    return;
  }
}

AllianceFactsMessage::AllianceFactsMessage()
{
  m_type = MessageEnum::ALLIANCEFACTSMESSAGE;
}

