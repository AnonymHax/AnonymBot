#include "MoodSmileyResultMessage.h"

void MoodSmileyResultMessage::serialize(Writer *param1)
{
  this->serializeAs_MoodSmileyResultMessage(param1);
}

void MoodSmileyResultMessage::serializeAs_MoodSmileyResultMessage(Writer *param1)
{
  param1->writeByte(this->resultCode);
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyResultMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  else
  {
    param1->writeVarShort((int)this->smileyId);
    return;
  }
}

void MoodSmileyResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MoodSmileyResultMessage(param1);
}

void MoodSmileyResultMessage::deserializeAs_MoodSmileyResultMessage(Reader *param1)
{
  this->resultCode = param1->readByte();
  if(this->resultCode < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyResultMessage -"<<"Forbidden value (" << this->resultCode << ") on element of MoodSmileyResultMessage.resultCode.";
  }
  else
  {
    this->smileyId = param1->readVarUhShort();
    if(this->smileyId < 0)
    {
      qDebug()<<"ERREUR - MoodSmileyResultMessage -"<<"Forbidden value (" << this->smileyId << ") on element of MoodSmileyResultMessage.smileyId.";
    }
    else
    {
      return;
    }
  }
}

MoodSmileyResultMessage::MoodSmileyResultMessage()
{
  m_type = MessageEnum::MOODSMILEYRESULTMESSAGE;
}

