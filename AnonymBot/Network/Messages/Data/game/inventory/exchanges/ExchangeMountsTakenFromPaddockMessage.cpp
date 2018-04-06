#include "ExchangeMountsTakenFromPaddockMessage.h"

void ExchangeMountsTakenFromPaddockMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeMountsTakenFromPaddockMessage(param1);
}

void ExchangeMountsTakenFromPaddockMessage::serializeAs_ExchangeMountsTakenFromPaddockMessage(Writer *param1)
{
  param1->writeUTF(this->name);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountsTakenFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - ExchangeMountsTakenFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      param1->writeUTF(this->ownername);
      return;
    }
  }
}

void ExchangeMountsTakenFromPaddockMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeMountsTakenFromPaddockMessage(param1);
}

void ExchangeMountsTakenFromPaddockMessage::deserializeAs_ExchangeMountsTakenFromPaddockMessage(Reader *param1)
{
  this->name = param1->readUTF();
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - ExchangeMountsTakenFromPaddockMessage -"<<"Forbidden value (" << this->worldX << ") on element of ExchangeMountsTakenFromPaddockMessage.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - ExchangeMountsTakenFromPaddockMessage -"<<"Forbidden value (" << this->worldY << ") on element of ExchangeMountsTakenFromPaddockMessage.worldY.";
    }
    else
    {
      this->ownername = param1->readUTF();
      return;
    }
  }
}

ExchangeMountsTakenFromPaddockMessage::ExchangeMountsTakenFromPaddockMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSTAKENFROMPADDOCKMESSAGE;
}

