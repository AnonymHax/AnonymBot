#include "CinematicMessage.h"

void CinematicMessage::serialize(Writer *param1)
{
  this->serializeAs_CinematicMessage(param1);
}

void CinematicMessage::serializeAs_CinematicMessage(Writer *param1)
{
  if(this->cinematicId < 0)
  {
    qDebug()<<"ERREUR - CinematicMessage -"<<"Forbidden value (" << this->cinematicId << ") on element cinematicId.";
  }
  else
  {
    param1->writeVarShort((int)this->cinematicId);
    return;
  }
}

void CinematicMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CinematicMessage(param1);
}

void CinematicMessage::deserializeAs_CinematicMessage(Reader *param1)
{
  this->cinematicId = param1->readVarUhShort();
  if(this->cinematicId < 0)
  {
    qDebug()<<"ERREUR - CinematicMessage -"<<"Forbidden value (" << this->cinematicId << ") on element of CinematicMessage.cinematicId.";
  }
  else
  {
    return;
  }
}

CinematicMessage::CinematicMessage()
{
  m_type = MessageEnum::CINEMATICMESSAGE;
}

