#include "HouseKickIndoorMerchantRequestMessage.h"

void HouseKickIndoorMerchantRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseKickIndoorMerchantRequestMessage(param1);
}

void HouseKickIndoorMerchantRequestMessage::serializeAs_HouseKickIndoorMerchantRequestMessage(Writer *param1)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - HouseKickIndoorMerchantRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    return;
  }
}

void HouseKickIndoorMerchantRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseKickIndoorMerchantRequestMessage(param1);
}

void HouseKickIndoorMerchantRequestMessage::deserializeAs_HouseKickIndoorMerchantRequestMessage(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - HouseKickIndoorMerchantRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of HouseKickIndoorMerchantRequestMessage.cellId.";
  }
  else
  {
    return;
  }
}

HouseKickIndoorMerchantRequestMessage::HouseKickIndoorMerchantRequestMessage()
{
  m_type = MessageEnum::HOUSEKICKINDOORMERCHANTREQUESTMESSAGE;
}

