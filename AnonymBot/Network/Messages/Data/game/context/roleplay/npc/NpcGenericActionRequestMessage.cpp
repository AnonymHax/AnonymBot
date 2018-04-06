#include "NpcGenericActionRequestMessage.h"

void NpcGenericActionRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_NpcGenericActionRequestMessage(param1);
}

void NpcGenericActionRequestMessage::serializeAs_NpcGenericActionRequestMessage(Writer *param1)
{
  param1->writeInt((int)this->npcId);
  if(this->npcActionId < 0)
  {
    qDebug()<<"ERREUR - NpcGenericActionRequestMessage -"<<"Forbidden value (" << this->npcActionId << ") on element npcActionId.";
  }
  else
  {
    param1->writeByte(this->npcActionId);
    param1->writeInt((int)this->npcMapId);
    return;
  }
}

void NpcGenericActionRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NpcGenericActionRequestMessage(param1);
}

void NpcGenericActionRequestMessage::deserializeAs_NpcGenericActionRequestMessage(Reader *param1)
{
  this->npcId = param1->readInt();
  this->npcActionId = param1->readByte();
  if(this->npcActionId < 0)
  {
    qDebug()<<"ERREUR - NpcGenericActionRequestMessage -"<<"Forbidden value (" << this->npcActionId << ") on element of NpcGenericActionRequestMessage.npcActionId.";
  }
  else
  {
    this->npcMapId = param1->readInt();
    return;
  }
}

NpcGenericActionRequestMessage::NpcGenericActionRequestMessage()
{
  m_type = MessageEnum::NPCGENERICACTIONREQUESTMESSAGE;
  m_needsHash = true;
}

