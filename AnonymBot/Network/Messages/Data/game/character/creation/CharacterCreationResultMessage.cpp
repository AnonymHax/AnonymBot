#include "CharacterCreationResultMessage.h"

void CharacterCreationResultMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterCreationResultMessage(param1);
}

void CharacterCreationResultMessage::serializeAs_CharacterCreationResultMessage(Writer *param1)
{
  param1->writeByte(this->result);
}

void CharacterCreationResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterCreationResultMessage(param1);
}

void CharacterCreationResultMessage::deserializeAs_CharacterCreationResultMessage(Reader *param1)
{
  this->result = param1->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - CharacterCreationResultMessage -"<<"Forbidden value (" << this->result << ") on element of CharacterCreationResultMessage.result.";
  }
  else
  {
    return;
  }
}

CharacterCreationResultMessage::CharacterCreationResultMessage()
{
  m_type = MessageEnum::CHARACTERCREATIONRESULTMESSAGE;
}

