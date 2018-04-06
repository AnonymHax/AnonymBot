#include "IdolsPresetSaveResultMessage.h"

void IdolsPresetSaveResultMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolsPresetSaveResultMessage(param1);
}

void IdolsPresetSaveResultMessage::serializeAs_IdolsPresetSaveResultMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetSaveResultMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    param1->writeByte(this->code);
    return;
  }
}

void IdolsPresetSaveResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolsPresetSaveResultMessage(param1);
}

void IdolsPresetSaveResultMessage::deserializeAs_IdolsPresetSaveResultMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetSaveResultMessage -"<<"Forbidden value (" << this->presetId << ") on element of IdolsPresetSaveResultMessage.presetId.";
  }
  else
  {
    this->code = param1->readByte();
    if(this->code < 0)
    {
      qDebug()<<"ERREUR - IdolsPresetSaveResultMessage -"<<"Forbidden value (" << this->code << ") on element of IdolsPresetSaveResultMessage.code.";
    }
    else
    {
      return;
    }
  }
}

IdolsPresetSaveResultMessage::IdolsPresetSaveResultMessage()
{
  m_type = MessageEnum::IDOLSPRESETSAVERESULTMESSAGE;
}

