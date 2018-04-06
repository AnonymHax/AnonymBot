#include "StatisticDataInt.h"

void StatisticDataInt::serialize(Writer *param1)
{
  this->serializeAs_StatisticDataInt(param1);
}

void StatisticDataInt::serializeAs_StatisticDataInt(Writer *param1)
{
  StatisticData::serializeAs_StatisticData(param1);
  param1->writeInt((int)this->value);
}

void StatisticDataInt::deserialize(Reader *param1)
{
  this->deserializeAs_StatisticDataInt(param1);
}

void StatisticDataInt::deserializeAs_StatisticDataInt(Reader *param1)
{
  StatisticData::deserialize(param1);
  this->value = param1->readInt();
}

StatisticDataInt::StatisticDataInt()
{
  m_types<<ClassEnum::STATISTICDATAINT;
}

bool StatisticDataInt::operator==(const StatisticDataInt &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

