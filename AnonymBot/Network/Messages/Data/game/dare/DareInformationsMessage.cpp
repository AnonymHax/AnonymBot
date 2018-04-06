#include "DareInformationsMessage.h"

void DareInformationsMessage::serialize(Writer *param1)
{
  this->serializeAs_DareInformationsMessage(param1);
}

void DareInformationsMessage::serializeAs_DareInformationsMessage(Writer *param1)
{
  this->dareFixedInfos.serializeAs_DareInformations(param1);
  this->dareVersatilesInfos.serializeAs_DareVersatileInformations(param1);
}

void DareInformationsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareInformationsMessage(param1);
}

void DareInformationsMessage::deserializeAs_DareInformationsMessage(Reader *param1)
{
  this->dareFixedInfos = DareInformations();
  this->dareFixedInfos.deserialize(param1);
  this->dareVersatilesInfos = DareVersatileInformations();
  this->dareVersatilesInfos.deserialize(param1);
}

DareInformationsMessage::DareInformationsMessage()
{
  m_type = MessageEnum::DAREINFORMATIONSMESSAGE;
}

