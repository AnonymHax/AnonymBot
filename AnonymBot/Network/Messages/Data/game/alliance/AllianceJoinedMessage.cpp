#include "AllianceJoinedMessage.h"

void AllianceJoinedMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceJoinedMessage(param1);
}

void AllianceJoinedMessage::serializeAs_AllianceJoinedMessage(Writer *param1)
{
  this->allianceInfo->serializeAs_AllianceInformations(param1);
  param1->writeBool(this->enabled);
}

void AllianceJoinedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceJoinedMessage(param1);
}

void AllianceJoinedMessage::deserializeAs_AllianceJoinedMessage(Reader *param1)
{
  this->allianceInfo = QSharedPointer<AllianceInformations>(new AllianceInformations() );
  this->allianceInfo->deserialize(param1);
  this->enabled = param1->readBool();
}

AllianceJoinedMessage::AllianceJoinedMessage()
{
  m_type = MessageEnum::ALLIANCEJOINEDMESSAGE;
}

