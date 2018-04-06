#include "IdolsPreset.h"

void IdolsPreset::serialize(Writer *param1)
{
  this->serializeAs_IdolsPreset(param1);
}

void IdolsPreset::serializeAs_IdolsPreset(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << this->symbolId << ") on element symbolId.";
    }
    else
    {
      param1->writeByte(this->symbolId);
      param1->writeShort((short)this->idolId.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->idolId.size())
      {
        if(this->idolId[_loc2_] < 0)
        {
          qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << this->idolId[_loc2_] << ") on element 3 (starting at 1) of idolId.";
        }
        else
        {
          param1->writeVarShort((int)this->idolId[_loc2_]);
          _loc2_++;
          continue;
        }
      }
      return;
    }
  }
}

void IdolsPreset::deserialize(Reader *param1)
{
  this->deserializeAs_IdolsPreset(param1);
}

void IdolsPreset::deserializeAs_IdolsPreset(Reader *param1)
{
  uint _loc4_ = 0;
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << this->presetId << ") on element of IdolsPreset.presetId.";
  }
  else
  {
    this->symbolId = param1->readByte();
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << this->symbolId << ") on element of IdolsPreset.symbolId.";
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
          qDebug()<<"ERREUR - IdolsPreset -"<<"Forbidden value (" << _loc4_ << ") on elements of idolId.";
        }
        else
        {
          this->idolId.append(_loc4_);
          _loc3_++;
          continue;
        }
      }
      return;
    }
  }
}

IdolsPreset::IdolsPreset()
{
  m_types<<ClassEnum::IDOLSPRESET;
}

bool IdolsPreset::operator==(const IdolsPreset &compared)
{
  if(presetId == compared.presetId)
  if(symbolId == compared.symbolId)
  if(idolId == compared.idolId)
  return true;
  
  return false;
}

