#include "StatisticData.h"

void StatisticData::serialize(Writer *param1)
{
}

void StatisticData::serializeAs_StatisticData(Writer *param1)
{
}

void StatisticData::deserialize(Reader *param1)
{
}

void StatisticData::deserializeAs_StatisticData(Reader *param1)
{
}

StatisticData::StatisticData()
{
  m_types<<ClassEnum::STATISTICDATA;
}

bool StatisticData::operator==(const StatisticData &compared)
{
  return true;
}

