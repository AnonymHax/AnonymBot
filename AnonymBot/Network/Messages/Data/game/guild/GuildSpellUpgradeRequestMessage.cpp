#include "GuildSpellUpgradeRequestMessage.h"

void GuildSpellUpgradeRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildSpellUpgradeRequestMessage(param1);
}

void GuildSpellUpgradeRequestMessage::serializeAs_GuildSpellUpgradeRequestMessage(Writer *param1)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GuildSpellUpgradeRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  else
  {
    param1->writeInt((int)this->spellId);
    return;
  }
}

void GuildSpellUpgradeRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildSpellUpgradeRequestMessage(param1);
}

void GuildSpellUpgradeRequestMessage::deserializeAs_GuildSpellUpgradeRequestMessage(Reader *param1)
{
  this->spellId = param1->readInt();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GuildSpellUpgradeRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element of GuildSpellUpgradeRequestMessage.spellId.";
  }
  else
  {
    return;
  }
}

GuildSpellUpgradeRequestMessage::GuildSpellUpgradeRequestMessage()
{
  m_type = MessageEnum::GUILDSPELLUPGRADEREQUESTMESSAGE;
}

