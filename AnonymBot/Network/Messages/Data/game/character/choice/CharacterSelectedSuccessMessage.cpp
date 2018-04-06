#include "CharacterSelectedSuccessMessage.h"

void CharacterSelectedSuccessMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterSelectedSuccessMessage(param1);
}

void CharacterSelectedSuccessMessage::serializeAs_CharacterSelectedSuccessMessage(Writer *param1)
{
  this->infos->serializeAs_CharacterBaseInformations(param1);
  param1->writeBool(this->isCollectingStats);
}

void CharacterSelectedSuccessMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterSelectedSuccessMessage(param1);
}

void CharacterSelectedSuccessMessage::deserializeAs_CharacterSelectedSuccessMessage(Reader *param1)
{
  this->infos = QSharedPointer<CharacterBaseInformations>(new CharacterBaseInformations() );
  this->infos->deserialize(param1);
  this->isCollectingStats = param1->readBool();
}

CharacterSelectedSuccessMessage::CharacterSelectedSuccessMessage()
{
  m_type = MessageEnum::CHARACTERSELECTEDSUCCESSMESSAGE;
}

