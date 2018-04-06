#include "IdolsPresetUseMessage.h"

void IdolsPresetUseMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolsPresetUseMessage(param1);
}

void IdolsPresetUseMessage::serializeAs_IdolsPresetUseMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetUseMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    param1->writeBool(this->party);
    return;
  }
}

void IdolsPresetUseMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolsPresetUseMessage(param1);
}

void IdolsPresetUseMessage::deserializeAs_IdolsPresetUseMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetUseMessage -"<<"Forbidden value (" << this->presetId << ") on element of IdolsPresetUseMessage.presetId.";
  }
  else
  {
    this->party = param1->readBool();
    return;
  }
}

IdolsPresetUseMessage::IdolsPresetUseMessage()
{
  m_type = MessageEnum::IDOLSPRESETUSEMESSAGE;
}

