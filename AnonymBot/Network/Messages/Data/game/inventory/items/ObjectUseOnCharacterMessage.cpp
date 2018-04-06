#include "ObjectUseOnCharacterMessage.h"

void ObjectUseOnCharacterMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectUseOnCharacterMessage(param1);
}

void ObjectUseOnCharacterMessage::serializeAs_ObjectUseOnCharacterMessage(Writer *param1)
{
  ObjectUseMessage::serializeAs_ObjectUseMessage(param1);
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectUseOnCharacterMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  else
  {
    param1->writeVarLong((double)this->characterId);
    return;
  }
}

void ObjectUseOnCharacterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectUseOnCharacterMessage(param1);
}

void ObjectUseOnCharacterMessage::deserializeAs_ObjectUseOnCharacterMessage(Reader *param1)
{
  ObjectUseMessage::deserialize(param1);
  this->characterId = param1->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ObjectUseOnCharacterMessage -"<<"Forbidden value (" << this->characterId << ") on element of ObjectUseOnCharacterMessage.characterId.";
  }
  else
  {
    return;
  }
}

ObjectUseOnCharacterMessage::ObjectUseOnCharacterMessage()
{
  m_type = MessageEnum::OBJECTUSEONCHARACTERMESSAGE;
}

