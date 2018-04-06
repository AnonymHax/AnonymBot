#include "MoodSmileyRequestMessage.h"

void MoodSmileyRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MoodSmileyRequestMessage(param1);
}

void MoodSmileyRequestMessage::serializeAs_MoodSmileyRequestMessage(Writer *param1)
{
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyRequestMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  else
  {
    param1->writeVarShort((int)this->smileyId);
    return;
  }
}

void MoodSmileyRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MoodSmileyRequestMessage(param1);
}

void MoodSmileyRequestMessage::deserializeAs_MoodSmileyRequestMessage(Reader *param1)
{
  this->smileyId = param1->readVarUhShort();
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - MoodSmileyRequestMessage -"<<"Forbidden value (" << this->smileyId << ") on element of MoodSmileyRequestMessage.smileyId.";
  }
  else
  {
    return;
  }
}

MoodSmileyRequestMessage::MoodSmileyRequestMessage()
{
  m_type = MessageEnum::MOODSMILEYREQUESTMESSAGE;
}

