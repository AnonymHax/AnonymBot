#include "PrismFightAttackerAddMessage.h"

void PrismFightAttackerAddMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismFightAttackerAddMessage(param1);
}

void PrismFightAttackerAddMessage::serializeAs_PrismFightAttackerAddMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerAddMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    if(this->fightId < 0)
    {
      qDebug()<<"ERREUR - PrismFightAttackerAddMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
    }
    else
    {
      param1->writeVarShort((int)this->fightId);
      param1->writeShort((short)this->attacker->getTypes().last());
      this->attacker->serialize(param1);
      return;
    }
  }
}

void PrismFightAttackerAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightAttackerAddMessage(param1);
}

void PrismFightAttackerAddMessage::deserializeAs_PrismFightAttackerAddMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerAddMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightAttackerAddMessage.subAreaId.";
  }
  else
  {
    this->fightId = param1->readVarUhShort();
    if(this->fightId < 0)
    {
      qDebug()<<"ERREUR - PrismFightAttackerAddMessage -"<<"Forbidden value (" << this->fightId << ") on element of PrismFightAttackerAddMessage.fightId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      this->attacker = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
      this->attacker->deserialize(param1);
      return;
    }
  }
}

PrismFightAttackerAddMessage::PrismFightAttackerAddMessage()
{
  m_type = MessageEnum::PRISMFIGHTATTACKERADDMESSAGE;
}

