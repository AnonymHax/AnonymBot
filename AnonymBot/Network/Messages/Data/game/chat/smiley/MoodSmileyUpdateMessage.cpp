#include "MoodSmileyUpdateMessage.h"

void MoodSmileyUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_MoodSmileyUpdateMessage(param1);
}

void MoodSmileyUpdateMessage::serializeAs_MoodSmileyUpdateMessage(Writer *param1)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  else
  {
    param1->writeInt((int)this->accountId);
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
    }
    else
    {
      param1->writeVarLong((double)this->playerId);
      if(this->smileyId < 0)
      {
        qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
      }
      else
      {
        param1->writeVarShort((int)this->smileyId);
        return;
      }
    }
  }
}

void MoodSmileyUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MoodSmileyUpdateMessage(param1);
}

void MoodSmileyUpdateMessage::deserializeAs_MoodSmileyUpdateMessage(Reader *param1)
{
  this->accountId = param1->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->accountId << ") on element of MoodSmileyUpdateMessage.accountId.";
  }
  else
  {
    this->playerId = param1->readVarUhLong();
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element of MoodSmileyUpdateMessage.playerId.";
    }
    else
    {
      this->smileyId = param1->readVarUhShort();
      if(this->smileyId < 0)
      {
        qDebug()<<"ERREUR - MoodSmileyUpdateMessage -"<<"Forbidden value (" << this->smileyId << ") on element of MoodSmileyUpdateMessage.smileyId.";
      }
      else
      {
        return;
      }
    }
  }
}

MoodSmileyUpdateMessage::MoodSmileyUpdateMessage()
{
  m_type = MessageEnum::MOODSMILEYUPDATEMESSAGE;
}

