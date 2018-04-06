#include "StartupActionsObjetAttributionMessage.h"

void StartupActionsObjetAttributionMessage::serialize(Writer *param1)
{
  this->serializeAs_StartupActionsObjetAttributionMessage(param1);
}

void StartupActionsObjetAttributionMessage::serializeAs_StartupActionsObjetAttributionMessage(Writer *param1)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - StartupActionsObjetAttributionMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  else
  {
    param1->writeInt((int)this->actionId);
    if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - StartupActionsObjetAttributionMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
    }
    else
    {
      param1->writeVarLong((double)this->characterId);
      return;
    }
  }
}

void StartupActionsObjetAttributionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StartupActionsObjetAttributionMessage(param1);
}

void StartupActionsObjetAttributionMessage::deserializeAs_StartupActionsObjetAttributionMessage(Reader *param1)
{
  this->actionId = param1->readInt();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - StartupActionsObjetAttributionMessage -"<<"Forbidden value (" << this->actionId << ") on element of StartupActionsObjetAttributionMessage.actionId.";
  }
  else
  {
    this->characterId = param1->readVarUhLong();
    if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - StartupActionsObjetAttributionMessage -"<<"Forbidden value (" << this->characterId << ") on element of StartupActionsObjetAttributionMessage.characterId.";
    }
    else
    {
      return;
    }
  }
}

StartupActionsObjetAttributionMessage::StartupActionsObjetAttributionMessage()
{
  m_type = MessageEnum::STARTUPACTIONSOBJETATTRIBUTIONMESSAGE;
}

