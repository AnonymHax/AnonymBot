#include "IdolsPresetUseResultMessage.h"

void IdolsPresetUseResultMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolsPresetUseResultMessage(param1);
}

void IdolsPresetUseResultMessage::serializeAs_IdolsPresetUseResultMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetUseResultMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    param1->writeByte(this->code);
    param1->writeShort((short)this->missingIdols.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->missingIdols.size())
    {
      if(this->missingIdols[_loc2_] < 0)
      {
        qDebug()<<"ERREUR - IdolsPresetUseResultMessage -"<<"Forbidden value (" << this->missingIdols[_loc2_] << ") on element 3 (starting at 1) of missingIdols.";
      }
      else
      {
        param1->writeVarShort((int)this->missingIdols[_loc2_]);
        _loc2_++;
        continue;
      }
    }
    return;
  }
}

void IdolsPresetUseResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolsPresetUseResultMessage(param1);
}

void IdolsPresetUseResultMessage::deserializeAs_IdolsPresetUseResultMessage(Reader *param1)
{
  uint _loc4_ = 0;
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPresetUseResultMessage -"<<"Forbidden value (" << this->presetId << ") on element of IdolsPresetUseResultMessage.presetId.";
  }
  else
  {
    this->code = param1->readByte();
    if(this->code < 0)
    {
      qDebug()<<"ERREUR - IdolsPresetUseResultMessage -"<<"Forbidden value (" << this->code << ") on element of IdolsPresetUseResultMessage.code.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = param1->readVarUhShort();
        if(_loc4_ < 0)
        {
          qDebug()<<"ERREUR - IdolsPresetUseResultMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of missingIdols.";
        }
        else
        {
          this->missingIdols.append(_loc4_);
          _loc3_++;
          continue;
        }
      }
      return;
    }
  }
}

IdolsPresetUseResultMessage::IdolsPresetUseResultMessage()
{
  m_type = MessageEnum::IDOLSPRESETUSERESULTMESSAGE;
}

