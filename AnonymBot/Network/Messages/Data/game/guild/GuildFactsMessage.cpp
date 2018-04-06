#include "GuildFactsMessage.h"

void GuildFactsMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFactsMessage(param1);
}

void GuildFactsMessage::serializeAs_GuildFactsMessage(Writer *param1)
{
  param1->writeShort((short)this->infos->getTypes().last());
  this->infos->serialize(param1);
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - GuildFactsMessage -"<<"Forbidden value (" << this->creationDate << ") on element creationDate.";
  }
  else
  {
    param1->writeInt((int)this->creationDate);
    if(this->nbTaxCollectors < 0)
    {
      qDebug()<<"ERREUR - GuildFactsMessage -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element nbTaxCollectors.";
    }
    else
    {
      param1->writeVarShort((int)this->nbTaxCollectors);
      param1->writeShort((short)this->members.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->members.size())
      {
        (this->members[_loc2_]).serializeAs_CharacterMinimalInformations(param1);
        _loc2_++;
      }
      return;
    }
  }
}

void GuildFactsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFactsMessage(param1);
}

void GuildFactsMessage::deserializeAs_GuildFactsMessage(Reader *param1)
{
  CharacterMinimalInformations _loc5_ ;
  uint _loc2_ = param1->readUShort();
  this->infos = qSharedPointerCast<GuildFactSheetInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->infos->deserialize(param1);
  this->creationDate = param1->readInt();
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - GuildFactsMessage -"<<"Forbidden value (" << this->creationDate << ") on element of GuildFactsMessage.creationDate.";
  }
  else
  {
    this->nbTaxCollectors = param1->readVarUhShort();
    if(this->nbTaxCollectors < 0)
    {
      qDebug()<<"ERREUR - GuildFactsMessage -"<<"Forbidden value (" << this->nbTaxCollectors << ") on element of GuildFactsMessage.nbTaxCollectors.";
    }
    else
    {
      uint _loc3_ = param1->readUShort();
      uint _loc4_ = 0;
      while(_loc4_ < _loc3_)
      {
        _loc5_ = CharacterMinimalInformations();
        _loc5_.deserialize(param1);
        this->members.append(_loc5_);
        _loc4_++;
      }
      return;
    }
  }
}

GuildFactsMessage::GuildFactsMessage()
{
  m_type = MessageEnum::GUILDFACTSMESSAGE;
}

