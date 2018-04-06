#include "StartupActionsAllAttributionMessage.h"

void StartupActionsAllAttributionMessage::serialize(Writer *param1)
{
  this->serializeAs_StartupActionsAllAttributionMessage(param1);
}

void StartupActionsAllAttributionMessage::serializeAs_StartupActionsAllAttributionMessage(Writer *param1)
{
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - StartupActionsAllAttributionMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  else
  {
    param1->writeVarLong((double)this->characterId);
    return;
  }
}

void StartupActionsAllAttributionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StartupActionsAllAttributionMessage(param1);
}

void StartupActionsAllAttributionMessage::deserializeAs_StartupActionsAllAttributionMessage(Reader *param1)
{
  this->characterId = param1->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - StartupActionsAllAttributionMessage -"<<"Forbidden value (" << this->characterId << ") on element of StartupActionsAllAttributionMessage.characterId.";
  }
  else
  {
    return;
  }
}

StartupActionsAllAttributionMessage::StartupActionsAllAttributionMessage()
{
  m_type = MessageEnum::STARTUPACTIONSALLATTRIBUTIONMESSAGE;
}

