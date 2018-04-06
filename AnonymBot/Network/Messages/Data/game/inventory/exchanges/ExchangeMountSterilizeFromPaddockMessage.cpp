#include "ExchangeMountSterilizeFromPaddockMessage.h"

void ExchangeMountSterilizeFromPaddockMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeMountSterilizeFromPaddockMessage(param1);
}

void ExchangeMountSterilizeFromPaddockMessage::serializeAs_ExchangeMountSterilizeFromPaddockMessage(Writer *param1)
{
  param1->writeUTF(this->name);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountSterilizeFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - ExchangeMountSterilizeFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      param1->writeUTF(this->sterilizator);
      return;
    }
  }
}

void ExchangeMountSterilizeFromPaddockMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeMountSterilizeFromPaddockMessage(param1);
}

void ExchangeMountSterilizeFromPaddockMessage::deserializeAs_ExchangeMountSterilizeFromPaddockMessage(Reader *param1)
{
  this->name = param1->readUTF();
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountSterilizeFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element of ExchangeMountSterilizeFromPaddockMessage.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - ExchangeMountSterilizeFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element of ExchangeMountSterilizeFromPaddockMessage.worldY.";
    }
    else
    {
      this->sterilizator = param1->readUTF();
      return;
    }
  }
}

ExchangeMountSterilizeFromPaddockMessage::ExchangeMountSterilizeFromPaddockMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSTERILIZEFROMPADDOCKMESSAGE;
}

