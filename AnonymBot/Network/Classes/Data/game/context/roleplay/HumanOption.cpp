#include "HumanOption.h"

void HumanOption::serialize(Writer *param1)
{
}

void HumanOption::serializeAs_HumanOption(Writer *param1)
{
}

void HumanOption::deserialize(Reader *param1)
{
}

void HumanOption::deserializeAs_HumanOption(Reader *param1)
{
}

HumanOption::HumanOption()
{
  m_types<<ClassEnum::HUMANOPTION;
}

bool HumanOption::operator==(const HumanOption &compared)
{
  return true;
}

