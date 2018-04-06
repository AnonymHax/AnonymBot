#include "StatisticDataString.h"

void StatisticDataString::serialize(Writer *param1)
{
  this->serializeAs_StatisticDataString(param1);
}

void StatisticDataString::serializeAs_StatisticDataString(Writer *param1)
{
  StatisticData::serializeAs_StatisticData(param1);
  param1->writeUTF(this->value);
}

void StatisticDataString::deserialize(Reader *param1)
{
  this->deserializeAs_StatisticDataString(param1);
}

void StatisticDataString::deserializeAs_StatisticDataString(Reader *param1)
{
  StatisticData::deserialize(param1);
  this->value = param1->readUTF();
}

StatisticDataString::StatisticDataString()
{
  m_types<<ClassEnum::STATISTICDATASTRING;
}

bool StatisticDataString::operator==(const StatisticDataString &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

