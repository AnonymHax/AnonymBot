#include "TitleSelectRequestMessage.h"

void TitleSelectRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_TitleSelectRequestMessage(param1);
}

void TitleSelectRequestMessage::serializeAs_TitleSelectRequestMessage(Writer *param1)
{
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleSelectRequestMessage -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  else
  {
    param1->writeVarShort((int)this->titleId);
    return;
  }
}

void TitleSelectRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TitleSelectRequestMessage(param1);
}

void TitleSelectRequestMessage::deserializeAs_TitleSelectRequestMessage(Reader *param1)
{
  this->titleId = param1->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleSelectRequestMessage -"<<"Forbidden value (" << this->titleId << ") on element of TitleSelectRequestMessage.titleId.";
  }
  else
  {
    return;
  }
}

TitleSelectRequestMessage::TitleSelectRequestMessage()
{
  m_type = MessageEnum::TITLESELECTREQUESTMESSAGE;
}

