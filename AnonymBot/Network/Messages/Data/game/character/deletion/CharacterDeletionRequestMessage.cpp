#include "CharacterDeletionRequestMessage.h"

void CharacterDeletionRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterDeletionRequestMessage(param1);
}

void CharacterDeletionRequestMessage::serializeAs_CharacterDeletionRequestMessage(Writer *param1)
{
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterDeletionRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  else
  {
    param1->writeVarLong((double)this->characterId);
    param1->writeUTF(this->secretAnswerHash);
    return;
  }
}

void CharacterDeletionRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterDeletionRequestMessage(param1);
}

void CharacterDeletionRequestMessage::deserializeAs_CharacterDeletionRequestMessage(Reader *param1)
{
  this->characterId = param1->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterDeletionRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element of CharacterDeletionRequestMessage.characterId.";
  }
  else
  {
    this->secretAnswerHash = param1->readUTF();
    return;
  }
}

CharacterDeletionRequestMessage::CharacterDeletionRequestMessage()
{
  m_type = MessageEnum::CHARACTERDELETIONREQUESTMESSAGE;
}

