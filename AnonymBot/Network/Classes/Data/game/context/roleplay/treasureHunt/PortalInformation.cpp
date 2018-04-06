#include "PortalInformation.h"

void PortalInformation::serialize(Writer *param1)
{
  this->serializeAs_PortalInformation(param1);
}

void PortalInformation::serializeAs_PortalInformation(Writer *param1)
{
  param1->writeInt((int)this->portalId);
  param1->writeShort((short)this->areaId);
}

void PortalInformation::deserialize(Reader *param1)
{
  this->deserializeAs_PortalInformation(param1);
}

void PortalInformation::deserializeAs_PortalInformation(Reader *param1)
{
  this->portalId = param1->readInt();
  this->areaId = param1->readShort();
}

PortalInformation::PortalInformation()
{
  m_types<<ClassEnum::PORTALINFORMATION;
}

bool PortalInformation::operator==(const PortalInformation &compared)
{
  if(portalId == compared.portalId)
  if(areaId == compared.areaId)
  return true;
  
  return false;
}

