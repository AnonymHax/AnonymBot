#include "ExchangeStartOkNpcShopMessage.h"

void ExchangeStartOkNpcShopMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkNpcShopMessage(param1);
}

void ExchangeStartOkNpcShopMessage::serializeAs_ExchangeStartOkNpcShopMessage(Writer *param1)
{
  if(this->npcSellerId < -9.007199254740992E15 || this->npcSellerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcShopMessage -"<<"Forbidden value (" << this->npcSellerId << ") on element npcSellerId.";
  }
  else
  {
    param1->writeDouble(this->npcSellerId);
    if(this->tokenId < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkNpcShopMessage -"<<"Forbidden value (" << this->tokenId << ") on element tokenId.";
    }
    else
    {
      param1->writeVarShort((int)this->tokenId);
      param1->writeShort((short)this->objectsInfos.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->objectsInfos.size())
      {
        qSharedPointerCast<ObjectItemToSellInNpcShop>(this->objectsInfos[_loc2_])->serializeAs_ObjectItemToSellInNpcShop(param1);
        _loc2_++;
      }
      return;
    }
  }
}

void ExchangeStartOkNpcShopMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkNpcShopMessage(param1);
}

void ExchangeStartOkNpcShopMessage::deserializeAs_ExchangeStartOkNpcShopMessage(Reader *param1)
{
  QSharedPointer<ObjectItemToSellInNpcShop> _loc4_ ;
  this->npcSellerId = param1->readDouble();
  if(this->npcSellerId < -9.007199254740992E15 || this->npcSellerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartOkNpcShopMessage -"<<"Forbidden value (" << this->npcSellerId << ") on element of ExchangeStartOkNpcShopMessage.npcSellerId.";
  }
  else
  {
    this->tokenId = param1->readVarUhShort();
    if(this->tokenId < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkNpcShopMessage -"<<"Forbidden value (" << this->tokenId << ") on element of ExchangeStartOkNpcShopMessage.tokenId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = QSharedPointer<ObjectItemToSellInNpcShop>(new ObjectItemToSellInNpcShop() );
        _loc4_->deserialize(param1);
        this->objectsInfos.append(_loc4_);
        _loc3_++;
      }
      return;
    }
  }
}

ExchangeStartOkNpcShopMessage::ExchangeStartOkNpcShopMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKNPCSHOPMESSAGE;
}

