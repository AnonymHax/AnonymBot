#include "QuestStartRequestMessage.h"

void QuestStartRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestStartRequestMessage(param1);
}

void QuestStartRequestMessage::serializeAs_QuestStartRequestMessage(Writer *param1)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStartRequestMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  else
  {
    param1->writeVarShort((int)this->questId);
    return;
  }
}

void QuestStartRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestStartRequestMessage(param1);
}

void QuestStartRequestMessage::deserializeAs_QuestStartRequestMessage(Reader *param1)
{
  this->questId = param1->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStartRequestMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStartRequestMessage.questId.";
  }
  else
  {
    return;
  }
}

QuestStartRequestMessage::QuestStartRequestMessage()
{
  m_type = MessageEnum::QUESTSTARTREQUESTMESSAGE;
}

