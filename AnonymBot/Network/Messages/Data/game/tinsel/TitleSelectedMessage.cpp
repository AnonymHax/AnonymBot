#include "TitleSelectedMessage.h"

void TitleSelectedMessage::serialize(Writer *param1)
{
  this->serializeAs_TitleSelectedMessage(param1);
}

void TitleSelectedMessage::serializeAs_TitleSelectedMessage(Writer *param1)
{
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleSelectedMessage -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  else
  {
    param1->writeVarShort((int)this->titleId);
    return;
  }
}

void TitleSelectedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TitleSelectedMessage(param1);
}

void TitleSelectedMessage::deserializeAs_TitleSelectedMessage(Reader *param1)
{
  this->titleId = param1->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleSelectedMessage -"<<"Forbidden value (" << this->titleId << ") on element of TitleSelectedMessage.titleId.";
  }
  else
  {
    return;
  }
}

TitleSelectedMessage::TitleSelectedMessage()
{
  m_type = MessageEnum::TITLESELECTEDMESSAGE;
}

