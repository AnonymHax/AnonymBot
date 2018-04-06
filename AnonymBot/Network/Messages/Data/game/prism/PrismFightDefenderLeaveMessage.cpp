#include "PrismFightDefenderLeaveMessage.h"

void PrismFightDefenderLeaveMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismFightDefenderLeaveMessage(param1);
}

void PrismFightDefenderLeaveMessage::serializeAs_PrismFightDefenderLeaveMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    if(this->fightId < 0)
    {
      qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
    }
    else
    {
      param1->writeVarShort((int)this->fightId);
      if(this->fighterToRemoveId < 0 || this->fighterToRemoveId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->fighterToRemoveId << ") on element fighterToRemoveId.";
      }
      else
      {
        param1->writeVarLong((double)this->fighterToRemoveId);
        return;
      }
    }
  }
}

void PrismFightDefenderLeaveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightDefenderLeaveMessage(param1);
}

void PrismFightDefenderLeaveMessage::deserializeAs_PrismFightDefenderLeaveMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightDefenderLeaveMessage.subAreaId.";
  }
  else
  {
    this->fightId = param1->readVarUhShort();
    if(this->fightId < 0)
    {
      qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->fightId << ") on element of PrismFightDefenderLeaveMessage.fightId.";
    }
    else
    {
      this->fighterToRemoveId = param1->readVarUhLong();
      if(this->fighterToRemoveId < 0 || this->fighterToRemoveId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->fighterToRemoveId << ") on element of PrismFightDefenderLeaveMessage.fighterToRemoveId.";
      }
      else
      {
        return;
      }
    }
  }
}

PrismFightDefenderLeaveMessage::PrismFightDefenderLeaveMessage()
{
  m_type = MessageEnum::PRISMFIGHTDEFENDERLEAVEMESSAGE;
}

