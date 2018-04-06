#include "NpcDialogReplyMessage.h"

void NpcDialogReplyMessage::serialize(Writer *param1)
{
  this->serializeAs_NpcDialogReplyMessage(param1);
}

void NpcDialogReplyMessage::serializeAs_NpcDialogReplyMessage(Writer *param1)
{
  if(this->replyId < 0)
  {
    qDebug()<<"ERREUR - NpcDialogReplyMessage -"<<"Forbidden value (" << this->replyId << ") on element replyId.";
  }
  else
  {
    param1->writeVarShort((int)this->replyId);
    return;
  }
}

void NpcDialogReplyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NpcDialogReplyMessage(param1);
}

void NpcDialogReplyMessage::deserializeAs_NpcDialogReplyMessage(Reader *param1)
{
  this->replyId = param1->readVarUhShort();
  if(this->replyId < 0)
  {
    qDebug()<<"ERREUR - NpcDialogReplyMessage -"<<"Forbidden value (" << this->replyId << ") on element of NpcDialogReplyMessage.replyId.";
  }
  else
  {
    return;
  }
}

NpcDialogReplyMessage::NpcDialogReplyMessage()
{
  m_type = MessageEnum::NPCDIALOGREPLYMESSAGE;
}

