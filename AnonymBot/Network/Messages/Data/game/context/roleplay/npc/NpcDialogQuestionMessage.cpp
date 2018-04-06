#include "NpcDialogQuestionMessage.h"

void NpcDialogQuestionMessage::serialize(Writer *param1)
{
  this->serializeAs_NpcDialogQuestionMessage(param1);
}

void NpcDialogQuestionMessage::serializeAs_NpcDialogQuestionMessage(Writer *param1)
{
  if(this->messageId < 0)
  {
    qDebug()<<"ERREUR - NpcDialogQuestionMessage -"<<"Forbidden value (" << this->messageId << ") on element messageId.";
  }
  else
  {
    param1->writeVarShort((int)this->messageId);
    param1->writeShort((short)this->dialogParams.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->dialogParams.size())
    {
      param1->writeUTF(this->dialogParams[_loc2_]);
      _loc2_++;
    }
    param1->writeShort((short)this->visibleReplies.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->visibleReplies.size())
    {
      if(this->visibleReplies[_loc3_] < 0)
      {
        qDebug()<<"ERREUR - NpcDialogQuestionMessage -"<<"Forbidden value (" << this->visibleReplies[_loc3_] << ") on element 3 (starting at 1) of visibleReplies.";
      }
      else
      {
        param1->writeVarShort((int)this->visibleReplies[_loc3_]);
        _loc3_++;
        continue;
      }
    }
    return;
  }
}

void NpcDialogQuestionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NpcDialogQuestionMessage(param1);
}

void NpcDialogQuestionMessage::deserializeAs_NpcDialogQuestionMessage(Reader *param1)
{
  QString _loc6_ ;
  uint _loc7_ = 0;
  this->messageId = param1->readVarUhShort();
  if(this->messageId < 0)
  {
    qDebug()<<"ERREUR - NpcDialogQuestionMessage -"<<"Forbidden value (" << this->messageId << ") on element of NpcDialogQuestionMessage.messageId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc6_ = param1->readUTF();
      this->dialogParams.append(_loc6_);
      _loc3_++;
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc7_ = param1->readVarUhShort();
      if(_loc7_ < 0)
      {
        qDebug()<<"ERREUR - NpcDialogQuestionMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of visibleReplies.";
      }
      else
      {
        this->visibleReplies.append(_loc7_);
        _loc5_++;
        continue;
      }
    }
    return;
  }
}

NpcDialogQuestionMessage::NpcDialogQuestionMessage()
{
  m_type = MessageEnum::NPCDIALOGQUESTIONMESSAGE;
}

