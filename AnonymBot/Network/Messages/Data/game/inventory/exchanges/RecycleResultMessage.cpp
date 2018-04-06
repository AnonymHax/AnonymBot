#include "RecycleResultMessage.h"

void RecycleResultMessage::serialize(Writer *param1)
{
  this->serializeAs_RecycleResultMessage(param1);
}

void RecycleResultMessage::serializeAs_RecycleResultMessage(Writer *param1)
{
  if(this->nuggetsForPrism < 0)
  {
    qDebug()<<"ERREUR - RecycleResultMessage -"<<"Forbidden value (" << this->nuggetsForPrism << ") on element nuggetsForPrism.";
  }
  else
  {
    param1->writeVarInt((int)this->nuggetsForPrism);
    if(this->nuggetsForPlayer < 0)
    {
      qDebug()<<"ERREUR - RecycleResultMessage -"<<"Forbidden value (" << this->nuggetsForPlayer << ") on element nuggetsForPlayer.";
    }
    else
    {
      param1->writeVarInt((int)this->nuggetsForPlayer);
      return;
    }
  }
}

void RecycleResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_RecycleResultMessage(param1);
}

void RecycleResultMessage::deserializeAs_RecycleResultMessage(Reader *param1)
{
  this->nuggetsForPrism = param1->readVarUhInt();
  if(this->nuggetsForPrism < 0)
  {
    qDebug()<<"ERREUR - RecycleResultMessage -"<<"Forbidden value (" << this->nuggetsForPrism << ") on element of RecycleResultMessage.nuggetsForPrism.";
  }
  else
  {
    this->nuggetsForPlayer = param1->readVarUhInt();
    if(this->nuggetsForPlayer < 0)
    {
      qDebug()<<"ERREUR - RecycleResultMessage -"<<"Forbidden value (" << this->nuggetsForPlayer << ") on element of RecycleResultMessage.nuggetsForPlayer.";
    }
    else
    {
      return;
    }
  }
}

RecycleResultMessage::RecycleResultMessage()
{
  m_type = MessageEnum::RECYCLERESULTMESSAGE;
}

