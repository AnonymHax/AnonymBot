#include "StatisticDataByte.h"

void StatisticDataByte::serialize(Writer *param1)
{
  this->serializeAs_StatisticDataByte(param1);
}

void StatisticDataByte::serializeAs_StatisticDataByte(Writer *param1)
{
  StatisticData::serializeAs_StatisticData(param1);
  param1->writeByte(this->value);
}

void StatisticDataByte::deserialize(Reader *param1)
{
  this->deserializeAs_StatisticDataByte(param1);
}

void StatisticDataByte::deserializeAs_StatisticDataByte(Reader *param1)
{
  StatisticData::deserialize(param1);
  this->value = param1->readByte();
}

StatisticDataByte::StatisticDataByte()
{
  m_types<<ClassEnum::STATISTICDATABYTE;
}

bool StatisticDataByte::operator==(const StatisticDataByte &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

