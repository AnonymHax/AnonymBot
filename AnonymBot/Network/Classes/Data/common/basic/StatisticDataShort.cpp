#include "StatisticDataShort.h"

void StatisticDataShort::serialize(Writer *param1)
{
  this->serializeAs_StatisticDataShort(param1);
}

void StatisticDataShort::serializeAs_StatisticDataShort(Writer *param1)
{
  StatisticData::serializeAs_StatisticData(param1);
  param1->writeShort((short)this->value);
}

void StatisticDataShort::deserialize(Reader *param1)
{
  this->deserializeAs_StatisticDataShort(param1);
}

void StatisticDataShort::deserializeAs_StatisticDataShort(Reader *param1)
{
  StatisticData::deserialize(param1);
  this->value = param1->readShort();
}

StatisticDataShort::StatisticDataShort()
{
  m_types<<ClassEnum::STATISTICDATASHORT;
}

bool StatisticDataShort::operator==(const StatisticDataShort &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

