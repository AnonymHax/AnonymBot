#include "TrustCertificate.h"

void TrustCertificate::serialize(Writer *param1)
{
  this->serializeAs_TrustCertificate(param1);
}

void TrustCertificate::serializeAs_TrustCertificate(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - TrustCertificate -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeInt((int)this->id);
    param1->writeUTF(this->hash);
    return;
  }
}

void TrustCertificate::deserialize(Reader *param1)
{
  this->deserializeAs_TrustCertificate(param1);
}

void TrustCertificate::deserializeAs_TrustCertificate(Reader *param1)
{
  this->id = param1->readInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - TrustCertificate -"<<"Forbidden value (" << this->id << ") on element of TrustCertificate.id.";
  }
  else
  {
    this->hash = param1->readUTF();
    return;
  }
}

TrustCertificate::TrustCertificate()
{
  m_types<<ClassEnum::TRUSTCERTIFICATE;
}

bool TrustCertificate::operator==(const TrustCertificate &compared)
{
  if(id == compared.id)
  if(hash == compared.hash)
  return true;
  
  return false;
}

