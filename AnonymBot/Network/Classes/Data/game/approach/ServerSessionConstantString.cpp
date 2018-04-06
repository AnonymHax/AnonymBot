#include "ServerSessionConstantString.h"

void ServerSessionConstantString::serialize(Writer *param1)
{
  this->serializeAs_ServerSessionConstantString(param1);
}

void ServerSessionConstantString::serializeAs_ServerSessionConstantString(Writer *param1)
{
  ServerSessionConstant::serializeAs_ServerSessionConstant(param1);
  param1->writeUTF(this->value);
}

void ServerSessionConstantString::deserialize(Reader *param1)
{
  this->deserializeAs_ServerSessionConstantString(param1);
}

void ServerSessionConstantString::deserializeAs_ServerSessionConstantString(Reader *param1)
{
  ServerSessionConstant::deserialize(param1);
  this->value = param1->readUTF();
}

ServerSessionConstantString::ServerSessionConstantString()
{
  m_types<<ClassEnum::SERVERSESSIONCONSTANTSTRING;
}

bool ServerSessionConstantString::operator==(const ServerSessionConstantString &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

