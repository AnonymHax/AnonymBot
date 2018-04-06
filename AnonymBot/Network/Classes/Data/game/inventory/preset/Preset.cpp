#include "Preset.h"

void Preset::serialize(Writer *param1)
{
  this->serializeAs_Preset(param1);
}

void Preset::serializeAs_Preset(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - Preset -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - Preset -"<<"Forbidden value (" << this->symbolId << ") on element symbolId.";
    }
    else
    {
      param1->writeByte(this->symbolId);
      param1->writeBool(this->mount);
      param1->writeShort((short)this->objects.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->objects.size())
      {
        (this->objects[_loc2_]).serializeAs_PresetItem(param1);
        _loc2_++;
      }
      return;
    }
  }
}

void Preset::deserialize(Reader *param1)
{
  this->deserializeAs_Preset(param1);
}

void Preset::deserializeAs_Preset(Reader *param1)
{
  PresetItem _loc4_ ;
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - Preset -"<<"Forbidden value (" << this->presetId << ") on element of Preset.presetId.";
  }
  else
  {
    this->symbolId = param1->readByte();
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - Preset -"<<"Forbidden value (" << this->symbolId << ") on element of Preset.symbolId.";
    }
    else
    {
      this->mount = param1->readBool();
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = PresetItem();
        _loc4_.deserialize(param1);
        this->objects.append(_loc4_);
        _loc3_++;
      }
      return;
    }
  }
}

Preset::Preset()
{
  m_types<<ClassEnum::PRESET;
}

bool Preset::operator==(const Preset &compared)
{
  if(presetId == compared.presetId)
  if(symbolId == compared.symbolId)
  if(mount == compared.mount)
  if(objects == compared.objects)
  return true;
  
  return false;
}

