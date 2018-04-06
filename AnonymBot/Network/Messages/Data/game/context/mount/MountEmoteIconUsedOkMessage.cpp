#include "MountEmoteIconUsedOkMessage.h"

void MountEmoteIconUsedOkMessage::serialize(Writer *param1)
{
  this->serializeAs_MountEmoteIconUsedOkMessage(param1);
}

void MountEmoteIconUsedOkMessage::serializeAs_MountEmoteIconUsedOkMessage(Writer *param1)
{
  param1->writeVarInt((int)this->mountId);
  if(this->reactionType < 0)
  {
    qDebug()<<"ERREUR - MountEmoteIconUsedOkMessage -"<<"Forbidden value (" << this->reactionType << ") on element reactionType.";
  }
  else
  {
    param1->writeByte(this->reactionType);
    return;
  }
}

void MountEmoteIconUsedOkMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountEmoteIconUsedOkMessage(param1);
}

void MountEmoteIconUsedOkMessage::deserializeAs_MountEmoteIconUsedOkMessage(Reader *param1)
{
  this->mountId = param1->readVarInt();
  this->reactionType = param1->readByte();
  if(this->reactionType < 0)
  {
    qDebug()<<"ERREUR - MountEmoteIconUsedOkMessage -"<<"Forbidden value (" << this->reactionType << ") on element of MountEmoteIconUsedOkMessage.reactionType.";
  }
  else
  {
    return;
  }
}

MountEmoteIconUsedOkMessage::MountEmoteIconUsedOkMessage()
{
  m_type = MessageEnum::MOUNTEMOTEICONUSEDOKMESSAGE;
}

