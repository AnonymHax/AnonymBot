#include "AbstractContactInformations.h"

void AbstractContactInformations::serialize(Writer *param1)
{
  this->serializeAs_AbstractContactInformations(param1);
}

void AbstractContactInformations::serializeAs_AbstractContactInformations(Writer *param1)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - AbstractContactInformations -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  else
  {
    param1->writeInt((int)this->accountId);
    param1->writeUTF(this->accountName);
    return;
  }
}

void AbstractContactInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractContactInformations(param1);
}

void AbstractContactInformations::deserializeAs_AbstractContactInformations(Reader *param1)
{
  this->accountId = param1->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - AbstractContactInformations -"<<"Forbidden value (" << this->accountId << ") on element of AbstractContactInformations.accountId.";
  }
  else
  {
    this->accountName = param1->readUTF();
    return;
  }
}

AbstractContactInformations::AbstractContactInformations()
{
  m_types<<ClassEnum::ABSTRACTCONTACTINFORMATIONS;
}

bool AbstractContactInformations::operator==(const AbstractContactInformations &compared)
{
  if(accountId == compared.accountId)
  if(accountName == compared.accountName)
  return true;
  
  return false;
}

