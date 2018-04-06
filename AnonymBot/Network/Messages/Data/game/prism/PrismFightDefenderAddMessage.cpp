#include "PrismFightDefenderAddMessage.h"

void PrismFightDefenderAddMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismFightDefenderAddMessage(param1);
}

void PrismFightDefenderAddMessage::serializeAs_PrismFightDefenderAddMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderAddMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    if(this->fightId < 0)
    {
      qDebug()<<"ERREUR - PrismFightDefenderAddMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
    }
    else
    {
      param1->writeVarShort((int)this->fightId);
      param1->writeShort((short)this->defender->getTypes().last());
      this->defender->serialize(param1);
      return;
    }
  }
}

void PrismFightDefenderAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightDefenderAddMessage(param1);
}

void PrismFightDefenderAddMessage::deserializeAs_PrismFightDefenderAddMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderAddMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightDefenderAddMessage.subAreaId.";
  }
  else
  {
    this->fightId = param1->readVarUhShort();
    if(this->fightId < 0)
    {
      qDebug()<<"ERREUR - PrismFightDefenderAddMessage -"<<"Forbidden value (" << this->fightId << ") on element of PrismFightDefenderAddMessage.fightId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      this->defender = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
      this->defender->deserialize(param1);
      return;
    }
  }
}

PrismFightDefenderAddMessage::PrismFightDefenderAddMessage()
{
  m_type = MessageEnum::PRISMFIGHTDEFENDERADDMESSAGE;
}

