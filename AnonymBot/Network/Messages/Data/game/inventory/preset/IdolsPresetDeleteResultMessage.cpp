#include "IdolsPresetDeleteResultMessage.h"

void IdolsPresetDeleteResultMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolsPresetDeleteResultMessage(param1);
}

void IdolsPresetDeleteResultMessage::serializeAs_IdolsPresetDeleteResultMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetDeleteResultMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    param1->writeByte(this->code);
    return;
  }
}

void IdolsPresetDeleteResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolsPresetDeleteResultMessage(param1);
}

void IdolsPresetDeleteResultMessage::deserializeAs_IdolsPresetDeleteResultMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetDeleteResultMessage -"<<"Forbidden value (" << this->presetId << ") on element of IdolsPresetDeleteResultMessage.presetId.";
  }
  else
  {
    this->code = param1->readByte();
    if(this->code < 0)
    {
      qDebug()<<"ERREUR - IdolsPresetDeleteResultMessage -"<<"Forbidden value (" << this->code << ") on element of IdolsPresetDeleteResultMessage.code.";
    }
    else
    {
      return;
    }
  }
}

IdolsPresetDeleteResultMessage::IdolsPresetDeleteResultMessage()
{
  m_type = MessageEnum::IDOLSPRESETDELETERESULTMESSAGE;
}

