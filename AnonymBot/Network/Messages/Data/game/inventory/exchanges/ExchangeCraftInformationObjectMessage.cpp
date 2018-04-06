#include "ExchangeCraftInformationObjectMessage.h"

void ExchangeCraftInformationObjectMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCraftInformationObjectMessage(param1);
}

void ExchangeCraftInformationObjectMessage::serializeAs_ExchangeCraftInformationObjectMessage(Writer *param1)
{
  ExchangeCraftResultWithObjectIdMessage::serializeAs_ExchangeCraftResultWithObjectIdMessage(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeCraftInformationObjectMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void ExchangeCraftInformationObjectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCraftInformationObjectMessage(param1);
}

void ExchangeCraftInformationObjectMessage::deserializeAs_ExchangeCraftInformationObjectMessage(Reader *param1)
{
  ExchangeCraftResultWithObjectIdMessage::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeCraftInformationObjectMessage -"<<"Forbidden value (" << this->playerId << ") on element of ExchangeCraftInformationObjectMessage.playerId.";
  }
  else
  {
    return;
  }
}

ExchangeCraftInformationObjectMessage::ExchangeCraftInformationObjectMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTINFORMATIONOBJECTMESSAGE;
}

