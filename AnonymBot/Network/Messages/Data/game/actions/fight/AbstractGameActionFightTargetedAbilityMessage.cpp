#include "AbstractGameActionFightTargetedAbilityMessage.h"

void AbstractGameActionFightTargetedAbilityMessage::serialize(Writer *param1)
{
  this->serializeAs_AbstractGameActionFightTargetedAbilityMessage(param1);
}

void AbstractGameActionFightTargetedAbilityMessage::serializeAs_AbstractGameActionFightTargetedAbilityMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->silentCast);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->verboseCast);
  param1->writeByte(_loc2_);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->destinationCellId < -1 || this->destinationCellId > 559)
    {
      qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->destinationCellId << ") on element destinationCellId.";
    }
    else
    {
      param1->writeShort((short)this->destinationCellId);
      param1->writeByte(this->critical);
      return;
    }
  }
}

void AbstractGameActionFightTargetedAbilityMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractGameActionFightTargetedAbilityMessage(param1);
}

void AbstractGameActionFightTargetedAbilityMessage::deserializeAs_AbstractGameActionFightTargetedAbilityMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  uint _loc2_ = param1->readByte();
  this->silentCast = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->verboseCast = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->targetId << ") on element of AbstractGameActionFightTargetedAbilityMessage.targetId.";
  }
  else
  {
    this->destinationCellId = param1->readShort();
    if(this->destinationCellId < -1 || this->destinationCellId > 559)
    {
      qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->destinationCellId << ") on element of AbstractGameActionFightTargetedAbilityMessage.destinationCellId.";
    }
    else
    {
      this->critical = param1->readByte();
      if(this->critical < 0)
      {
        qDebug()<<"ERREUR - AbstractGameActionFightTargetedAbilityMessage -"<<"Forbidden value (" << this->critical << ") on element of AbstractGameActionFightTargetedAbilityMessage.critical.";
      }
      else
      {
        return;
      }
    }
  }
}

AbstractGameActionFightTargetedAbilityMessage::AbstractGameActionFightTargetedAbilityMessage()
{
  m_type = MessageEnum::ABSTRACTGAMEACTIONFIGHTTARGETEDABILITYMESSAGE;
}

