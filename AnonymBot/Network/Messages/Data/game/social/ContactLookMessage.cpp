#include "ContactLookMessage.h"

void ContactLookMessage::serialize(Writer *param1)
{
  this->serializeAs_ContactLookMessage(param1);
}

void ContactLookMessage::serializeAs_ContactLookMessage(Writer *param1)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - ContactLookMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  else
  {
    param1->writeVarInt((int)this->requestId);
    param1->writeUTF(this->playerName);
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ContactLookMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
    }
    else
    {
      param1->writeVarLong((double)this->playerId);
      this->look->serializeAs_EntityLook(param1);
      return;
    }
  }
}

void ContactLookMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ContactLookMessage(param1);
}

void ContactLookMessage::deserializeAs_ContactLookMessage(Reader *param1)
{
  this->requestId = param1->readVarUhInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - ContactLookMessage -"<<"Forbidden value (" << this->requestId << ") on element of ContactLookMessage.requestId.";
  }
  else
  {
    this->playerName = param1->readUTF();
    this->playerId = param1->readVarUhLong();
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ContactLookMessage -"<<"Forbidden value (" << this->playerId << ") on element of ContactLookMessage.playerId.";
    }
    else
    {
      this->look = QSharedPointer<EntityLook>(new EntityLook() );
      this->look->deserialize(param1);
      return;
    }
  }
}

ContactLookMessage::ContactLookMessage()
{
  m_type = MessageEnum::CONTACTLOOKMESSAGE;
}

