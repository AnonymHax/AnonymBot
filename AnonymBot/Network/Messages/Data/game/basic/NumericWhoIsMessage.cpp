#include "NumericWhoIsMessage.h"

void NumericWhoIsMessage::serialize(Writer *param1)
{
  this->serializeAs_NumericWhoIsMessage(param1);
}

void NumericWhoIsMessage::serializeAs_NumericWhoIsMessage(Writer *param1)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - NumericWhoIsMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    if(this->accountId < 0)
    {
      qDebug()<<"ERREUR - NumericWhoIsMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
    }
    else
    {
      param1->writeInt((int)this->accountId);
      return;
    }
  }
}

void NumericWhoIsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NumericWhoIsMessage(param1);
}

void NumericWhoIsMessage::deserializeAs_NumericWhoIsMessage(Reader *param1)
{
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - NumericWhoIsMessage -"<<"Forbidden value (" << this->playerId << ") on element of NumericWhoIsMessage.playerId.";
  }
  else
  {
    this->accountId = param1->readInt();
    if(this->accountId < 0)
    {
      qDebug()<<"ERREUR - NumericWhoIsMessage -"<<"Forbidden value (" << this->accountId << ") on element of NumericWhoIsMessage.accountId.";
    }
    else
    {
      return;
    }
  }
}

NumericWhoIsMessage::NumericWhoIsMessage()
{
  m_type = MessageEnum::NUMERICWHOISMESSAGE;
}

