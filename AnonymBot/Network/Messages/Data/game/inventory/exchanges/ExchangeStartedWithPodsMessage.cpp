#include "ExchangeStartedWithPodsMessage.h"

void ExchangeStartedWithPodsMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartedWithPodsMessage(param1);
}

void ExchangeStartedWithPodsMessage::serializeAs_ExchangeStartedWithPodsMessage(Writer *param1)
{
  ExchangeStartedMessage::serializeAs_ExchangeStartedMessage(param1);
  if(this->firstCharacterId < -9.007199254740992E15 || this->firstCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterId << ") on element firstCharacterId.";
  }
  else
  {
    param1->writeDouble(this->firstCharacterId);
    if(this->firstCharacterCurrentWeight < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterCurrentWeight << ") on element firstCharacterCurrentWeight.";
    }
    else
    {
      param1->writeVarInt((int)this->firstCharacterCurrentWeight);
      if(this->firstCharacterMaxWeight < 0)
      {
        qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterMaxWeight << ") on element firstCharacterMaxWeight.";
      }
      else
      {
        param1->writeVarInt((int)this->firstCharacterMaxWeight);
        if(this->secondCharacterId < -9.007199254740992E15 || this->secondCharacterId > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterId << ") on element secondCharacterId.";
        }
        else
        {
          param1->writeDouble(this->secondCharacterId);
          if(this->secondCharacterCurrentWeight < 0)
          {
            qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterCurrentWeight << ") on element secondCharacterCurrentWeight.";
          }
          else
          {
            param1->writeVarInt((int)this->secondCharacterCurrentWeight);
            if(this->secondCharacterMaxWeight < 0)
            {
              qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterMaxWeight << ") on element secondCharacterMaxWeight.";
            }
            else
            {
              param1->writeVarInt((int)this->secondCharacterMaxWeight);
              return;
            }
          }
        }
      }
    }
  }
}

void ExchangeStartedWithPodsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartedWithPodsMessage(param1);
}

void ExchangeStartedWithPodsMessage::deserializeAs_ExchangeStartedWithPodsMessage(Reader *param1)
{
  ExchangeStartedMessage::deserialize(param1);
  this->firstCharacterId = param1->readDouble();
  if(this->firstCharacterId < -9.007199254740992E15 || this->firstCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterId << ") on element of ExchangeStartedWithPodsMessage.firstCharacterId.";
  }
  else
  {
    this->firstCharacterCurrentWeight = param1->readVarUhInt();
    if(this->firstCharacterCurrentWeight < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterCurrentWeight << ") on element of ExchangeStartedWithPodsMessage.firstCharacterCurrentWeight.";
    }
    else
    {
      this->firstCharacterMaxWeight = param1->readVarUhInt();
      if(this->firstCharacterMaxWeight < 0)
      {
        qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->firstCharacterMaxWeight << ") on element of ExchangeStartedWithPodsMessage.firstCharacterMaxWeight.";
      }
      else
      {
        this->secondCharacterId = param1->readDouble();
        if(this->secondCharacterId < -9.007199254740992E15 || this->secondCharacterId > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterId << ") on element of ExchangeStartedWithPodsMessage.secondCharacterId.";
        }
        else
        {
          this->secondCharacterCurrentWeight = param1->readVarUhInt();
          if(this->secondCharacterCurrentWeight < 0)
          {
            qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterCurrentWeight << ") on element of ExchangeStartedWithPodsMessage.secondCharacterCurrentWeight.";
          }
          else
          {
            this->secondCharacterMaxWeight = param1->readVarUhInt();
            if(this->secondCharacterMaxWeight < 0)
            {
              qDebug()<<"ERREUR - ExchangeStartedWithPodsMessage -"<<"Forbidden value (" << this->secondCharacterMaxWeight << ") on element of ExchangeStartedWithPodsMessage.secondCharacterMaxWeight.";
            }
            else
            {
              return;
            }
          }
        }
      }
    }
  }
}

ExchangeStartedWithPodsMessage::ExchangeStartedWithPodsMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDWITHPODSMESSAGE;
}

