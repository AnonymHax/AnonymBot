#include "ServerSessionConstantLong.h"

void ServerSessionConstantLong::serialize(Writer *param1)
{
  this->serializeAs_ServerSessionConstantLong(param1);
}

void ServerSessionConstantLong::serializeAs_ServerSessionConstantLong(Writer *param1)
{
  ServerSessionConstant::serializeAs_ServerSessionConstant(param1);
  if(this->value < -9.007199254740992E15 || this->value > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ServerSessionConstantLong -"<<"Forbidden value (" << this->value << ") on element value.";
  }
  else
  {
    param1->writeDouble(this->value);
    return;
  }
}

void ServerSessionConstantLong::deserialize(Reader *param1)
{
  this->deserializeAs_ServerSessionConstantLong(param1);
}

void ServerSessionConstantLong::deserializeAs_ServerSessionConstantLong(Reader *param1)
{
  ServerSessionConstant::deserialize(param1);
  this->value = param1->readDouble();
  if(this->value < -9.007199254740992E15 || this->value > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ServerSessionConstantLong -"<<"Forbidden value (" << this->value << ") on element of ServerSessionConstantLong.value.";
  }
  else
  {
    return;
  }
}

ServerSessionConstantLong::ServerSessionConstantLong()
{
  m_types<<ClassEnum::SERVERSESSIONCONSTANTLONG;
}

bool ServerSessionConstantLong::operator==(const ServerSessionConstantLong &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

