#include "CompassUpdatePartyMemberMessage.h"

void CompassUpdatePartyMemberMessage::serialize(Writer *param1)
{
  this->serializeAs_CompassUpdatePartyMemberMessage(param1);
}

void CompassUpdatePartyMemberMessage::serializeAs_CompassUpdatePartyMemberMessage(Writer *param1)
{
  CompassUpdateMessage::serializeAs_CompassUpdateMessage(param1);
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CompassUpdatePartyMemberMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  else
  {
    param1->writeVarLong((double)this->memberId);
    param1->writeBool(this->active);
    return;
  }
}

void CompassUpdatePartyMemberMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CompassUpdatePartyMemberMessage(param1);
}

void CompassUpdatePartyMemberMessage::deserializeAs_CompassUpdatePartyMemberMessage(Reader *param1)
{
  CompassUpdateMessage::deserialize(param1);
  this->memberId = param1->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CompassUpdatePartyMemberMessage -"<<"Forbidden value (" << this->memberId << ") on element of CompassUpdatePartyMemberMessage.memberId.";
  }
  else
  {
    this->active = param1->readBool();
    return;
  }
}

CompassUpdatePartyMemberMessage::CompassUpdatePartyMemberMessage()
{
  m_type = MessageEnum::COMPASSUPDATEPARTYMEMBERMESSAGE;
}

