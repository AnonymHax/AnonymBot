#include "CharacterDeletionErrorMessage.h"

void CharacterDeletionErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterDeletionErrorMessage(param1);
}

void CharacterDeletionErrorMessage::serializeAs_CharacterDeletionErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void CharacterDeletionErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterDeletionErrorMessage(param1);
}

void CharacterDeletionErrorMessage::deserializeAs_CharacterDeletionErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - CharacterDeletionErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of CharacterDeletionErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

CharacterDeletionErrorMessage::CharacterDeletionErrorMessage()
{
  m_type = MessageEnum::CHARACTERDELETIONERRORMESSAGE;
}

