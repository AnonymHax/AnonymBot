#include "VersionExtended.h"

void VersionExtended::serialize(Writer *param1)
{
  this->serializeAs_VersionExtended(param1);
}

void VersionExtended::serializeAs_VersionExtended(Writer *param1)
{
  Version::serializeAs_Version(param1);
  param1->writeByte(this->install);
  param1->writeByte(this->technology);
}

void VersionExtended::deserialize(Reader *param1)
{
  this->deserializeAs_VersionExtended(param1);
}

void VersionExtended::deserializeAs_VersionExtended(Reader *param1)
{
  Version::deserialize(param1);
  this->install = param1->readByte();
  if(this->install < 0)
  {
    qDebug()<<"ERREUR - VersionExtended -"<<"Forbidden value (" << this->install << ") on element of VersionExtended.install.";
  }
  else
  {
    this->technology = param1->readByte();
    if(this->technology < 0)
    {
      qDebug()<<"ERREUR - VersionExtended -"<<"Forbidden value (" << this->technology << ") on element of VersionExtended.technology.";
    }
    else
    {
      return;
    }
  }
}

VersionExtended::VersionExtended()
{
  m_types<<ClassEnum::VERSIONEXTENDED;
}

bool VersionExtended::operator==(const VersionExtended &compared)
{
  if(install == compared.install)
  if(technology == compared.technology)
  return true;
  
  return false;
}

