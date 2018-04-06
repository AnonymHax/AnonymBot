#include "ObtainedItemWithBonusMessage.h"

void ObtainedItemWithBonusMessage::serialize(Writer *param1)
{
  this->serializeAs_ObtainedItemWithBonusMessage(param1);
}

void ObtainedItemWithBonusMessage::serializeAs_ObtainedItemWithBonusMessage(Writer *param1)
{
  ObtainedItemMessage::serializeAs_ObtainedItemMessage(param1);
  if(this->bonusQuantity < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemWithBonusMessage -"<<"Forbidden value (" << this->bonusQuantity << ") on element bonusQuantity.";
  }
  else
  {
    param1->writeVarInt((int)this->bonusQuantity);
    return;
  }
}

void ObtainedItemWithBonusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObtainedItemWithBonusMessage(param1);
}

void ObtainedItemWithBonusMessage::deserializeAs_ObtainedItemWithBonusMessage(Reader *param1)
{
  ObtainedItemMessage::deserialize(param1);
  this->bonusQuantity = param1->readVarUhInt();
  if(this->bonusQuantity < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemWithBonusMessage -"<<"Forbidden value (" << this->bonusQuantity << ") on element of ObtainedItemWithBonusMessage.bonusQuantity.";
  }
  else
  {
    return;
  }
}

ObtainedItemWithBonusMessage::ObtainedItemWithBonusMessage()
{
  m_type = MessageEnum::OBTAINEDITEMWITHBONUSMESSAGE;
}

