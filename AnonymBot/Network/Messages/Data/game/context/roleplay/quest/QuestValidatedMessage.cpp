#include "QuestValidatedMessage.h"

void QuestValidatedMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestValidatedMessage(param1);
}

void QuestValidatedMessage::serializeAs_QuestValidatedMessage(Writer *param1)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  else
  {
    param1->writeVarShort((int)this->questId);
    return;
  }
}

void QuestValidatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestValidatedMessage(param1);
}

void QuestValidatedMessage::deserializeAs_QuestValidatedMessage(Reader *param1)
{
  this->questId = param1->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestValidatedMessage.questId.";
  }
  else
  {
    return;
  }
}

QuestValidatedMessage::QuestValidatedMessage()
{
  m_type = MessageEnum::QUESTVALIDATEDMESSAGE;
}

