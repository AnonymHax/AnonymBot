#include "StatisticDataBoolean.h"

void StatisticDataBoolean::serialize(Writer *param1)
{
  this->serializeAs_StatisticDataBoolean(param1);
}

void StatisticDataBoolean::serializeAs_StatisticDataBoolean(Writer *param1)
{
  StatisticData::serializeAs_StatisticData(param1);
  param1->writeBool(this->value);
}

void StatisticDataBoolean::deserialize(Reader *param1)
{
  this->deserializeAs_StatisticDataBoolean(param1);
}

void StatisticDataBoolean::deserializeAs_StatisticDataBoolean(Reader *param1)
{
  StatisticData::deserialize(param1);
  this->value = param1->readBool();
}

StatisticDataBoolean::StatisticDataBoolean()
{
  m_types<<ClassEnum::STATISTICDATABOOLEAN;
}

bool StatisticDataBoolean::operator==(const StatisticDataBoolean &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

