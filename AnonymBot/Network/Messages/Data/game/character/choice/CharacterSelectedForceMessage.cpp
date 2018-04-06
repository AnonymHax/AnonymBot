#include "CharacterSelectedForceMessage.h"

void CharacterSelectedForceMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterSelectedForceMessage(param1);
}

void CharacterSelectedForceMessage::serializeAs_CharacterSelectedForceMessage(Writer *param1)
{
  if(this->id < 1 || this->id > 2147483647)
  {
    qDebug()<<"ERREUR - CharacterSelectedForceMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeInt((int)this->id);
    return;
  }
}

void CharacterSelectedForceMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterSelectedForceMessage(param1);
}

void CharacterSelectedForceMessage::deserializeAs_CharacterSelectedForceMessage(Reader *param1)
{
  this->id = param1->readInt();
  if(this->id < 1 || this->id > 2147483647)
  {
    qDebug()<<"ERREUR - CharacterSelectedForceMessage -"<<"Forbidden value (" << this->id << ") on element of CharacterSelectedForceMessage.id.";
  }
  else
  {
    return;
  }
}

CharacterSelectedForceMessage::CharacterSelectedForceMessage()
{
  m_type = MessageEnum::CHARACTERSELECTEDFORCEMESSAGE;
}

