#include "Version.h"

void Version::serialize(Writer *param1)
{
  this->serializeAs_Version(param1);
}

void Version::serializeAs_Version(Writer *param1)
{
  if(this->major < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->major << ") on element major.";
  }
  else
  {
    param1->writeByte(this->major);
    if(this->minor < 0)
    {
      qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->minor << ") on element minor.";
    }
    else
    {
      param1->writeByte(this->minor);
      if(this->release < 0)
      {
        qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->release << ") on element release.";
      }
      else
      {
        param1->writeByte(this->release);
        if(this->revision < 0)
        {
          qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->revision << ") on element revision.";
        }
        else
        {
          param1->writeInt((int)this->revision);
          if(this->patch < 0)
          {
            qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->patch << ") on element patch.";
          }
          else
          {
            param1->writeByte(this->patch);
            param1->writeByte(this->buildType);
            return;
          }
        }
      }
    }
  }
}

void Version::deserialize(Reader *param1)
{
  this->deserializeAs_Version(param1);
}

void Version::deserializeAs_Version(Reader *param1)
{
  this->major = param1->readByte();
  if(this->major < 0)
  {
    qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->major << ") on element of Version.major.";
  }
  else
  {
    this->minor = param1->readByte();
    if(this->minor < 0)
    {
      qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->minor << ") on element of Version.minor.";
    }
    else
    {
      this->release = param1->readByte();
      if(this->release < 0)
      {
        qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->release << ") on element of Version.release.";
      }
      else
      {
        this->revision = param1->readInt();
        if(this->revision < 0)
        {
          qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->revision << ") on element of Version.revision.";
        }
        else
        {
          this->patch = param1->readByte();
          if(this->patch < 0)
          {
            qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->patch << ") on element of Version.patch.";
          }
          else
          {
            this->buildType = param1->readByte();
            if(this->buildType < 0)
            {
              qDebug()<<"ERREUR - Version -"<<"Forbidden value (" << this->buildType << ") on element of Version.buildType.";
            }
            else
            {
              return;
            }
          }
        }
      }
    }
  }
}

Version::Version()
{
  m_types<<ClassEnum::VERSION;
}

bool Version::operator==(const Version &compared)
{
  if(major == compared.major)
  if(minor == compared.minor)
  if(release == compared.release)
  if(revision == compared.revision)
  if(patch == compared.patch)
  if(buildType == compared.buildType)
  return true;
  
  return false;
}

