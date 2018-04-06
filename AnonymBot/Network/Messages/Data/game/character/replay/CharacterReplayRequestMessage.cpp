#include "CharacterReplayRequestMessage.h"

void CharacterReplayRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterReplayRequestMessage(param1);
}

void CharacterReplayRequestMessage::serializeAs_CharacterReplayRequestMessage(Writer *param1)
{
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterReplayRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  else
  {
    param1->writeVarLong((double)this->characterId);
    return;
  }
}

void CharacterReplayRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterReplayRequestMessage(param1);
}

void CharacterReplayRequestMessage::deserializeAs_CharacterReplayRequestMessage(Reader *param1)
{
  this->characterId = param1->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterReplayRequestMessage -"<<"Forbidden value (" << this->characterId << ") on element of CharacterReplayRequestMessage.characterId.";
  }
  else
  {
    return;
  }
}

CharacterReplayRequestMessage::CharacterReplayRequestMessage()
{
  m_type = MessageEnum::CHARACTERREPLAYREQUESTMESSAGE;
}

