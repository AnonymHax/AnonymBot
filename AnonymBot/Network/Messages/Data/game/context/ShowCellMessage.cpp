#include "ShowCellMessage.h"

void ShowCellMessage::serialize(Writer *param1)
{
  this->serializeAs_ShowCellMessage(param1);
}

void ShowCellMessage::serializeAs_ShowCellMessage(Writer *param1)
{
  if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ShowCellMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
  }
  else
  {
    param1->writeDouble(this->sourceId);
    if(this->cellId < 0 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - ShowCellMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
    }
    else
    {
      param1->writeVarShort((int)this->cellId);
      return;
    }
  }
}

void ShowCellMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShowCellMessage(param1);
}

void ShowCellMessage::deserializeAs_ShowCellMessage(Reader *param1)
{
  this->sourceId = param1->readDouble();
  if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ShowCellMessage -"<<"Forbidden value (" << this->sourceId << ") on element of ShowCellMessage.sourceId.";
  }
  else
  {
    this->cellId = param1->readVarUhShort();
    if(this->cellId < 0 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - ShowCellMessage -"<<"Forbidden value (" << this->cellId << ") on element of ShowCellMessage.cellId.";
    }
    else
    {
      return;
    }
  }
}

ShowCellMessage::ShowCellMessage()
{
  m_type = MessageEnum::SHOWCELLMESSAGE;
}

