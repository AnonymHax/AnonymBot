#include "ServerSessionConstant.h"

void ServerSessionConstant::serialize(Writer *param1)
{
  this->serializeAs_ServerSessionConstant(param1);
}

void ServerSessionConstant::serializeAs_ServerSessionConstant(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - ServerSessionConstant -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarShort((int)this->id);
    return;
  }
}

void ServerSessionConstant::deserialize(Reader *param1)
{
  this->deserializeAs_ServerSessionConstant(param1);
}

void ServerSessionConstant::deserializeAs_ServerSessionConstant(Reader *param1)
{
  this->id = param1->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - ServerSessionConstant -"<<"Forbidden value (" << this->id << ") on element of ServerSessionConstant.id.";
  }
  else
  {
    return;
  }
}

ServerSessionConstant::ServerSessionConstant()
{
  m_types<<ClassEnum::SERVERSESSIONCONSTANT;
}

bool ServerSessionConstant::operator==(const ServerSessionConstant &compared)
{
  if(id == compared.id)
  return true;
  
  return false;
}

