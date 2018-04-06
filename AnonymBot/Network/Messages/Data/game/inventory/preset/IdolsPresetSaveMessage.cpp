#include "IdolsPresetSaveMessage.h"

void IdolsPresetSaveMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolsPresetSaveMessage(param1);
}

void IdolsPresetSaveMessage::serializeAs_IdolsPresetSaveMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetSaveMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - IdolsPresetSaveMessage -"<<"Forbidden value (" << this->symbolId << ") on element symbolId.";
    }
    else
    {
      param1->writeByte(this->symbolId);
      return;
    }
  }
}

void IdolsPresetSaveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolsPresetSaveMessage(param1);
}

void IdolsPresetSaveMessage::deserializeAs_IdolsPresetSaveMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetSaveMessage -"<<"Forbidden value (" << this->presetId << ") on element of IdolsPresetSaveMessage.presetId.";
  }
  else
  {
    this->symbolId = param1->readByte();
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - IdolsPresetSaveMessage -"<<"Forbidden value (" << this->symbolId << ") on element of IdolsPresetSaveMessage.symbolId.";
    }
    else
    {
      return;
    }
  }
}

IdolsPresetSaveMessage::IdolsPresetSaveMessage()
{
  m_type = MessageEnum::IDOLSPRESETSAVEMESSAGE;
}

