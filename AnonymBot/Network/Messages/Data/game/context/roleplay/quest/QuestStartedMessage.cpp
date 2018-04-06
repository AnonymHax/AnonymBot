#include "QuestStartedMessage.h"

void QuestStartedMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestStartedMessage(param1);
}

void QuestStartedMessage::serializeAs_QuestStartedMessage(Writer *param1)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStartedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  else
  {
    param1->writeVarShort((int)this->questId);
    return;
  }
}

void QuestStartedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestStartedMessage(param1);
}

void QuestStartedMessage::deserializeAs_QuestStartedMessage(Reader *param1)
{
  this->questId = param1->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStartedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStartedMessage.questId.";
  }
  else
  {
    return;
  }
}

QuestStartedMessage::QuestStartedMessage()
{
  m_type = MessageEnum::QUESTSTARTEDMESSAGE;
}

