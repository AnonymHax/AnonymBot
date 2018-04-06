#include "PartyCompanionUpdateLightMessage.h"

void PartyCompanionUpdateLightMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyCompanionUpdateLightMessage(param1);
}

void PartyCompanionUpdateLightMessage::serializeAs_PartyCompanionUpdateLightMessage(Writer *param1)
{
  PartyUpdateLightMessage::serializeAs_PartyUpdateLightMessage(param1);
  if(this->indexId < 0)
  {
    qDebug()<<"ERREUR - PartyCompanionUpdateLightMessage -"<<"Forbidden value (" << this->indexId << ") on element indexId.";
  }
  else
  {
    param1->writeByte(this->indexId);
    return;
  }
}

void PartyCompanionUpdateLightMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyCompanionUpdateLightMessage(param1);
}

void PartyCompanionUpdateLightMessage::deserializeAs_PartyCompanionUpdateLightMessage(Reader *param1)
{
  PartyUpdateLightMessage::deserialize(param1);
  this->indexId = param1->readByte();
  if(this->indexId < 0)
  {
    qDebug()<<"ERREUR - PartyCompanionUpdateLightMessage -"<<"Forbidden value (" << this->indexId << ") on element of PartyCompanionUpdateLightMessage.indexId.";
  }
  else
  {
    return;
  }
}

PartyCompanionUpdateLightMessage::PartyCompanionUpdateLightMessage()
{
  m_type = MessageEnum::PARTYCOMPANIONUPDATELIGHTMESSAGE;
}

