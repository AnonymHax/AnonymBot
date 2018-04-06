#include "NpcDialogCreationMessage.h"

void NpcDialogCreationMessage::serialize(Writer *param1)
{
  this->serializeAs_NpcDialogCreationMessage(param1);
}

void NpcDialogCreationMessage::serializeAs_NpcDialogCreationMessage(Writer *param1)
{
  param1->writeInt((int)this->mapId);
  param1->writeInt((int)this->npcId);
}

void NpcDialogCreationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NpcDialogCreationMessage(param1);
}

void NpcDialogCreationMessage::deserializeAs_NpcDialogCreationMessage(Reader *param1)
{
  this->mapId = param1->readInt();
  this->npcId = param1->readInt();
}

NpcDialogCreationMessage::NpcDialogCreationMessage()
{
  m_type = MessageEnum::NPCDIALOGCREATIONMESSAGE;
}

