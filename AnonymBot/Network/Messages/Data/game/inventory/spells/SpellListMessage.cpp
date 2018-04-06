#include "SpellListMessage.h"

void SpellListMessage::serialize(Writer *param1)
{
  this->serializeAs_SpellListMessage(param1);
}

void SpellListMessage::serializeAs_SpellListMessage(Writer *param1)
{
  param1->writeBool(this->spellPrevisualization);
  param1->writeShort((short)this->spells.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->spells.size())
  {
    (this->spells[_loc2_]).serializeAs_SpellItem(param1);
    _loc2_++;
  }
}

void SpellListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SpellListMessage(param1);
}

void SpellListMessage::deserializeAs_SpellListMessage(Reader *param1)
{
  SpellItem _loc4_ ;
  this->spellPrevisualization = param1->readBool();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = SpellItem();
    _loc4_.deserialize(param1);
    this->spells.append(_loc4_);
    _loc3_++;
  }
}

SpellListMessage::SpellListMessage()
{
  m_type = MessageEnum::SPELLLISTMESSAGE;
}

