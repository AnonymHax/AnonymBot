#include "ExchangeMountFreeFromPaddockMessage.h"

void ExchangeMountFreeFromPaddockMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeMountFreeFromPaddockMessage(param1);
}

void ExchangeMountFreeFromPaddockMessage::serializeAs_ExchangeMountFreeFromPaddockMessage(Writer *param1)
{
  param1->writeUTF(this->name);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountFreeFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - ExchangeMountFreeFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      param1->writeUTF(this->liberator);
      return;
    }
  }
}

void ExchangeMountFreeFromPaddockMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeMountFreeFromPaddockMessage(param1);
}

void ExchangeMountFreeFromPaddockMessage::deserializeAs_ExchangeMountFreeFromPaddockMessage(Reader *param1)
{
  this->name = param1->readUTF();
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountFreeFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element of ExchangeMountFreeFromPaddockMessage.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - ExchangeMountFreeFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element of ExchangeMountFreeFromPaddockMessage.worldY.";
    }
    else
    {
      this->liberator = param1->readUTF();
      return;
    }
  }
}

ExchangeMountFreeFromPaddockMessage::ExchangeMountFreeFromPaddockMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTFREEFROMPADDOCKMESSAGE;
}

