#include "IgnoredInformations.h"

void IgnoredInformations::serialize(Writer *param1)
{
  this->serializeAs_IgnoredInformations(param1);
}

void IgnoredInformations::serializeAs_IgnoredInformations(Writer *param1)
{
  AbstractContactInformations::serializeAs_AbstractContactInformations(param1);
}

void IgnoredInformations::deserialize(Reader *param1)
{
  this->deserializeAs_IgnoredInformations(param1);
}

void IgnoredInformations::deserializeAs_IgnoredInformations(Reader *param1)
{
  AbstractContactInformations::deserialize(param1);
}

IgnoredInformations::IgnoredInformations()
{
  m_types<<ClassEnum::IGNOREDINFORMATIONS;
}

bool IgnoredInformations::operator==(const IgnoredInformations &compared)
{
  return true;
}

