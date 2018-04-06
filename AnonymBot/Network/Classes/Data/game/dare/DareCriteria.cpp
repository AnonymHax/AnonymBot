#include "DareCriteria.h"

void DareCriteria::serialize(Writer *param1)
{
  this->serializeAs_DareCriteria(param1);
}

void DareCriteria::serializeAs_DareCriteria(Writer *param1)
{
  param1->writeByte(this->type);
  param1->writeShort((short)this->params.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->params.size())
  {
    param1->writeInt((int)this->params[_loc2_]);
    _loc2_++;
  }
}

void DareCriteria::deserialize(Reader *param1)
{
  this->deserializeAs_DareCriteria(param1);
}

void DareCriteria::deserializeAs_DareCriteria(Reader *param1)
{
  auto _loc4_ = 0;
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - DareCriteria -"<<"Forbidden value (" << this->type << ") on element of DareCriteria.type.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readInt();
      this->params.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

DareCriteria::DareCriteria()
{
  m_types<<ClassEnum::DARECRITERIA;
}

bool DareCriteria::operator==(const DareCriteria &compared)
{
  if(type == compared.type)
  if(params == compared.params)
  return true;
  
  return false;
}

