#include "TitleGainedMessage.h"

void TitleGainedMessage::serialize(Writer *param1)
{
  this->serializeAs_TitleGainedMessage(param1);
}

void TitleGainedMessage::serializeAs_TitleGainedMessage(Writer *param1)
{
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleGainedMessage -"<<"Forbidden value (" << this->titleId << ") on element titleId.";
  }
  else
  {
    param1->writeVarShort((int)this->titleId);
    return;
  }
}

void TitleGainedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TitleGainedMessage(param1);
}

void TitleGainedMessage::deserializeAs_TitleGainedMessage(Reader *param1)
{
  this->titleId = param1->readVarUhShort();
  if(this->titleId < 0)
  {
    qDebug()<<"ERREUR - TitleGainedMessage -"<<"Forbidden value (" << this->titleId << ") on element of TitleGainedMessage.titleId.";
  }
  else
  {
    return;
  }
}

TitleGainedMessage::TitleGainedMessage()
{
  m_type = MessageEnum::TITLEGAINEDMESSAGE;
}

