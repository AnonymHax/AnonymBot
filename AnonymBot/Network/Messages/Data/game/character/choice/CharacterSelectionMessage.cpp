#include "CharacterSelectionMessage.h"

void CharacterSelectionMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterSelectionMessage(param1);
}

void CharacterSelectionMessage::serializeAs_CharacterSelectionMessage(Writer *param1)
{
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterSelectionMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarLong((double)this->id);
    return;
  }
}

void CharacterSelectionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterSelectionMessage(param1);
}

void CharacterSelectionMessage::deserializeAs_CharacterSelectionMessage(Reader *param1)
{
  this->id = param1->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterSelectionMessage -"<<"Forbidden value (" << this->id << ") on element of CharacterSelectionMessage.id.";
  }
  else
  {
    return;
  }
}

CharacterSelectionMessage::CharacterSelectionMessage()
{
  m_type = MessageEnum::CHARACTERSELECTIONMESSAGE;
}

