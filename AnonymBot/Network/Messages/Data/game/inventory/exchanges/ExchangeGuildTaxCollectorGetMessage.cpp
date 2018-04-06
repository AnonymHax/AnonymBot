#include "ExchangeGuildTaxCollectorGetMessage.h"

void ExchangeGuildTaxCollectorGetMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeGuildTaxCollectorGetMessage(param1);
}

void ExchangeGuildTaxCollectorGetMessage::serializeAs_ExchangeGuildTaxCollectorGetMessage(Writer *param1)
{
  param1->writeUTF(this->collectorName);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      param1->writeInt((int)this->mapId);
      if(this->subAreaId < 0)
      {
        qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
      }
      else
      {
        param1->writeVarShort((int)this->subAreaId);
        param1->writeUTF(this->userName);
        if(this->callerId < 0 || this->callerId > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->callerId << ") on element callerId.";
        }
        else
        {
          param1->writeVarLong((double)this->callerId);
          param1->writeUTF(this->callerName);
          if(this->experience < -9.007199254740992E15 || this->experience > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->experience << ") on element experience.";
          }
          else
          {
            param1->writeDouble(this->experience);
            if(this->pods < 0)
            {
              qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->pods << ") on element pods.";
            }
            else
            {
              param1->writeVarShort((int)this->pods);
              param1->writeShort((short)this->objectsInfos.size());
              uint _loc2_ = 0;
              while(_loc2_ < this->objectsInfos.size())
              {
                (this->objectsInfos[_loc2_]).serializeAs_ObjectItemGenericQuantity(param1);
                _loc2_++;
              }
              return;
            }
          }
        }
      }
    }
  }
}

void ExchangeGuildTaxCollectorGetMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeGuildTaxCollectorGetMessage(param1);
}

void ExchangeGuildTaxCollectorGetMessage::deserializeAs_ExchangeGuildTaxCollectorGetMessage(Reader *param1)
{
  ObjectItemGenericQuantity _loc4_ ;
  this->collectorName = param1->readUTF();
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldX << ") on element of ExchangeGuildTaxCollectorGetMessage.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->worldY << ") on element of ExchangeGuildTaxCollectorGetMessage.worldY.";
    }
    else
    {
      this->mapId = param1->readInt();
      this->subAreaId = param1->readVarUhShort();
      if(this->subAreaId < 0)
      {
        qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of ExchangeGuildTaxCollectorGetMessage.subAreaId.";
      }
      else
      {
        this->userName = param1->readUTF();
        this->callerId = param1->readVarUhLong();
        if(this->callerId < 0 || this->callerId > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->callerId << ") on element of ExchangeGuildTaxCollectorGetMessage.callerId.";
        }
        else
        {
          this->callerName = param1->readUTF();
          this->experience = param1->readDouble();
          if(this->experience < -9.007199254740992E15 || this->experience > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->experience << ") on element of ExchangeGuildTaxCollectorGetMessage.experience.";
          }
          else
          {
            this->pods = param1->readVarUhShort();
            if(this->pods < 0)
            {
              qDebug()<<"ERREUR - ExchangeGuildTaxCollectorGetMessage -"<<"Forbidden value (" << this->pods << ") on element of ExchangeGuildTaxCollectorGetMessage.pods.";
            }
            else
            {
              uint _loc2_ = param1->readUShort();
              uint _loc3_ = 0;
              while(_loc3_ < _loc2_)
              {
                _loc4_ = ObjectItemGenericQuantity();
                _loc4_.deserialize(param1);
                this->objectsInfos.append(_loc4_);
                _loc3_++;
              }
              return;
            }
          }
        }
      }
    }
  }
}

ExchangeGuildTaxCollectorGetMessage::ExchangeGuildTaxCollectorGetMessage()
{
  m_type = MessageEnum::EXCHANGEGUILDTAXCOLLECTORGETMESSAGE;
}

