#include "TitleLostMessage.h"

void TitleLostMessage::serialize(Writer *param1)
{
  this->serializeAs_TitleLostMessage(param1);
}

void TitleLostMessage::serializeAs_TitleLostMessage(Writer *param1)
{
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleLostMessage -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  else
  {
    param1->writeVarShort((int)this->titleId);
    return;
  }
}

void TitleLostMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TitleLostMessage(param1);
}

void TitleLostMessage::deserializeAs_TitleLostMessage(Reader *param1)
{
  this->titleId = param1->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleLostMessage -"<<"Forbidden value (" << this->titleId << ") on element of TitleLostMessage.titleId.";
  }
  else
  {
    return;
  }
}

TitleLostMessage::TitleLostMessage()
{
  m_type = MessageEnum::TITLELOSTMESSAGE;
}

