#include "ProtocolRequired.h"

void ProtocolRequired::serialize(Writer *param1)
{
  this->serializeAs_ProtocolRequired(param1);
}

void ProtocolRequired::serializeAs_ProtocolRequired(Writer *param1)
{
  if(this->requiredVersion < 0)
  {
    qDebug()<<"ERREUR - ProtocolRequired -"<<"Forbidden value (" << this->requiredVersion << ") on element requiredVersion.";
  }
  else
  {
    param1->writeInt((int)this->requiredVersion);
    if(this->currentVersion < 0)
    {
      qDebug()<<"ERREUR - ProtocolRequired -"<<"Forbidden value (" << this->currentVersion << ") on element currentVersion.";
    }
    else
    {
      param1->writeInt((int)this->currentVersion);
      return;
    }
  }
}

void ProtocolRequired::deserialize(Reader *param1)
{
  this->deserializeAs_ProtocolRequired(param1);
}

void ProtocolRequired::deserializeAs_ProtocolRequired(Reader *param1)
{
  this->requiredVersion = param1->readInt();
  if(this->requiredVersion < 0)
  {
    qDebug()<<"ERREUR - ProtocolRequired -"<<"Forbidden value (" << this->requiredVersion << ") on element of ProtocolRequired.requiredVersion.";
  }
  else
  {
    this->currentVersion = param1->readInt();
    if(this->currentVersion < 0)
    {
      qDebug()<<"ERREUR - ProtocolRequired -"<<"Forbidden value (" << this->currentVersion << ") on element of ProtocolRequired.currentVersion.";
    }
    else
    {
      return;
    }
  }
}

ProtocolRequired::ProtocolRequired()
{
  m_type = MessageEnum::PROTOCOLREQUIRED;
}

