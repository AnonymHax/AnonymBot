#include "ServerSessionConstantInteger.h"

void ServerSessionConstantInteger::serialize(Writer *param1)
{
  this->serializeAs_ServerSessionConstantInteger(param1);
}

void ServerSessionConstantInteger::serializeAs_ServerSessionConstantInteger(Writer *param1)
{
  ServerSessionConstant::serializeAs_ServerSessionConstant(param1);
  param1->writeInt((int)this->value);
}

void ServerSessionConstantInteger::deserialize(Reader *param1)
{
  this->deserializeAs_ServerSessionConstantInteger(param1);
}

void ServerSessionConstantInteger::deserializeAs_ServerSessionConstantInteger(Reader *param1)
{
  ServerSessionConstant::deserialize(param1);
  this->value = param1->readInt();
}

ServerSessionConstantInteger::ServerSessionConstantInteger()
{
  m_types<<ClassEnum::SERVERSESSIONCONSTANTINTEGER;
}

bool ServerSessionConstantInteger::operator==(const ServerSessionConstantInteger &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

