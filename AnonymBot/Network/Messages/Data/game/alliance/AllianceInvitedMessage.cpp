#include "AllianceInvitedMessage.h"

void AllianceInvitedMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceInvitedMessage(param1);
}

void AllianceInvitedMessage::serializeAs_AllianceInvitedMessage(Writer *param1)
{
  if(this->recruterId < 0 || this->recruterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInvitedMessage -"<<"Forbidden value (" << this->recruterId << ") on element recruterId.";
  }
  else
  {
    param1->writeVarLong((double)this->recruterId);
    param1->writeUTF(this->recruterName);
    this->allianceInfo->serializeAs_BasicNamedAllianceInformations(param1);
    return;
  }
}

void AllianceInvitedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceInvitedMessage(param1);
}

void AllianceInvitedMessage::deserializeAs_AllianceInvitedMessage(Reader *param1)
{
  this->recruterId = param1->readVarUhLong();
  if(this->recruterId < 0 || this->recruterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInvitedMessage -"<<"Forbidden value (" << this->recruterId << ") on element of AllianceInvitedMessage.recruterId.";
  }
  else
  {
    this->recruterName = param1->readUTF();
    this->allianceInfo = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
    this->allianceInfo->deserialize(param1);
    return;
  }
}

AllianceInvitedMessage::AllianceInvitedMessage()
{
  m_type = MessageEnum::ALLIANCEINVITEDMESSAGE;
}

