#include "ShowCellRequestMessage.h"

void ShowCellRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ShowCellRequestMessage(param1);
}

void ShowCellRequestMessage::serializeAs_ShowCellRequestMessage(Writer *param1)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ShowCellRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    return;
  }
}

void ShowCellRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShowCellRequestMessage(param1);
}

void ShowCellRequestMessage::deserializeAs_ShowCellRequestMessage(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ShowCellRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of ShowCellRequestMessage.cellId.";
  }
  else
  {
    return;
  }
}

ShowCellRequestMessage::ShowCellRequestMessage()
{
  m_type = MessageEnum::SHOWCELLREQUESTMESSAGE;
}

