#include "CharacterCapabilitiesMessage.h"

void CharacterCapabilitiesMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterCapabilitiesMessage(param1);
}

void CharacterCapabilitiesMessage::serializeAs_CharacterCapabilitiesMessage(Writer *param1)
{
  if(this->guildEmblemSymbolCategories < 0)
  {
    qDebug()<<"ERREUR - CharacterCapabilitiesMessage -"<<"Forbidden value (" << this->guildEmblemSymbolCategories << ") on element guildEmblemSymbolCategories.";
  }
  else
  {
    param1->writeVarInt((int)this->guildEmblemSymbolCategories);
    return;
  }
}

void CharacterCapabilitiesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterCapabilitiesMessage(param1);
}

void CharacterCapabilitiesMessage::deserializeAs_CharacterCapabilitiesMessage(Reader *param1)
{
  this->guildEmblemSymbolCategories = param1->readVarUhInt();
  if(this->guildEmblemSymbolCategories < 0)
  {
    qDebug()<<"ERREUR - CharacterCapabilitiesMessage -"<<"Forbidden value (" << this->guildEmblemSymbolCategories << ") on element of CharacterCapabilitiesMessage.guildEmblemSymbolCategories.";
  }
  else
  {
    return;
  }
}

CharacterCapabilitiesMessage::CharacterCapabilitiesMessage()
{
  m_type = MessageEnum::CHARACTERCAPABILITIESMESSAGE;
}

