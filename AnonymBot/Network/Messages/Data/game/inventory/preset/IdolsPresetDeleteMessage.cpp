#include "IdolsPresetDeleteMessage.h"

void IdolsPresetDeleteMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolsPresetDeleteMessage(param1);
}

void IdolsPresetDeleteMessage::serializeAs_IdolsPresetDeleteMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetDeleteMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    return;
  }
}

void IdolsPresetDeleteMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolsPresetDeleteMessage(param1);
}

void IdolsPresetDeleteMessage::deserializeAs_IdolsPresetDeleteMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetDeleteMessage -"<<"Forbidden value (" << this->presetId << ") on element of IdolsPresetDeleteMessage.presetId.";
  }
  else
  {
    return;
  }
}

IdolsPresetDeleteMessage::IdolsPresetDeleteMessage()
{
  m_type = MessageEnum::IDOLSPRESETDELETEMESSAGE;
}

