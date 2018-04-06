#include "CharacterLevelUpMessage.h"

void CharacterLevelUpMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterLevelUpMessage(param1);
}

void CharacterLevelUpMessage::serializeAs_CharacterLevelUpMessage(Writer *param1)
{
  if(this->newLevel < 2 || this->newLevel > 206)
  {
    qDebug()<<"ERREUR - CharacterLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element newLevel.";
  }
  else
  {
    param1->writeByte(this->newLevel);
    return;
  }
}

void CharacterLevelUpMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterLevelUpMessage(param1);
}

void CharacterLevelUpMessage::deserializeAs_CharacterLevelUpMessage(Reader *param1)
{
  this->newLevel = param1->readUByte();
  if(this->newLevel < 2 || this->newLevel > 206)
  {
    qDebug()<<"ERREUR - CharacterLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element of CharacterLevelUpMessage.newLevel.";
  }
  else
  {
    return;
  }
}

CharacterLevelUpMessage::CharacterLevelUpMessage()
{
  m_type = MessageEnum::CHARACTERLEVELUPMESSAGE;
}

