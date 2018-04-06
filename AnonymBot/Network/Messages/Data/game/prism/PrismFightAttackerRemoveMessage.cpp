#include "PrismFightAttackerRemoveMessage.h"

void PrismFightAttackerRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismFightAttackerRemoveMessage(param1);
}

void PrismFightAttackerRemoveMessage::serializeAs_PrismFightAttackerRemoveMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    if(this->fightId < 0)
    {
      qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
    }
    else
    {
      param1->writeVarShort((int)this->fightId);
      if(this->fighterToRemoveId < 0 || this->fighterToRemoveId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->fighterToRemoveId << ") on element fighterToRemoveId.";
      }
      else
      {
        param1->writeVarLong((double)this->fighterToRemoveId);
        return;
      }
    }
  }
}

void PrismFightAttackerRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightAttackerRemoveMessage(param1);
}

void PrismFightAttackerRemoveMessage::deserializeAs_PrismFightAttackerRemoveMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightAttackerRemoveMessage.subAreaId.";
  }
  else
  {
    this->fightId = param1->readVarUhShort();
    if(this->fightId < 0)
    {
      qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->fightId << ") on element of PrismFightAttackerRemoveMessage.fightId.";
    }
    else
    {
      this->fighterToRemoveId = param1->readVarUhLong();
      if(this->fighterToRemoveId < 0 || this->fighterToRemoveId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->fighterToRemoveId << ") on element of PrismFightAttackerRemoveMessage.fighterToRemoveId.";
      }
      else
      {
        return;
      }
    }
  }
}

PrismFightAttackerRemoveMessage::PrismFightAttackerRemoveMessage()
{
  m_type = MessageEnum::PRISMFIGHTATTACKERREMOVEMESSAGE;
}

