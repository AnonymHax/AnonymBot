#include "CharacterLevelUpInformationMessage.h"

void CharacterLevelUpInformationMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterLevelUpInformationMessage(param1);
}

void CharacterLevelUpInformationMessage::serializeAs_CharacterLevelUpInformationMessage(Writer *param1)
{
  CharacterLevelUpMessage::serializeAs_CharacterLevelUpMessage(param1);
  param1->writeUTF(this->name);
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterLevelUpInformationMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarLong((double)this->id);
    return;
  }
}

void CharacterLevelUpInformationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterLevelUpInformationMessage(param1);
}

void CharacterLevelUpInformationMessage::deserializeAs_CharacterLevelUpInformationMessage(Reader *param1)
{
  CharacterLevelUpMessage::deserialize(param1);
  this->name = param1->readUTF();
  this->id = param1->readVarUhLong();
  if(this->id < 0 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CharacterLevelUpInformationMessage -"<<"Forbidden value (" << this->id << ") on element of CharacterLevelUpInformationMessage.id.";
  }
  else
  {
    return;
  }
}

CharacterLevelUpInformationMessage::CharacterLevelUpInformationMessage()
{
  m_type = MessageEnum::CHARACTERLEVELUPINFORMATIONMESSAGE;
}

