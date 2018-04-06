#include "SetCharacterRestrictionsMessage.h"

void SetCharacterRestrictionsMessage::serialize(Writer *param1)
{
  this->serializeAs_SetCharacterRestrictionsMessage(param1);
}

void SetCharacterRestrictionsMessage::serializeAs_SetCharacterRestrictionsMessage(Writer *param1)
{
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SetCharacterRestrictionsMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  else
  {
    param1->writeDouble(this->actorId);
    this->restrictions.serializeAs_ActorRestrictionsInformations(param1);
    return;
  }
}

void SetCharacterRestrictionsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SetCharacterRestrictionsMessage(param1);
}

void SetCharacterRestrictionsMessage::deserializeAs_SetCharacterRestrictionsMessage(Reader *param1)
{
  this->actorId = param1->readDouble();
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SetCharacterRestrictionsMessage -"<<"Forbidden value (" << this->actorId << ") on element of SetCharacterRestrictionsMessage.actorId.";
  }
  else
  {
    this->restrictions = ActorRestrictionsInformations();
    this->restrictions.deserialize(param1);
    return;
  }
}

SetCharacterRestrictionsMessage::SetCharacterRestrictionsMessage()
{
  m_type = MessageEnum::SETCHARACTERRESTRICTIONSMESSAGE;
}

