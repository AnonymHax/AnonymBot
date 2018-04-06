#include "ClientYouAreDrunkMessage.h"

void ClientYouAreDrunkMessage::serialize(Writer *param1)
{
  this->serializeAs_ClientYouAreDrunkMessage(param1);
}

void ClientYouAreDrunkMessage::serializeAs_ClientYouAreDrunkMessage(Writer *param1)
{
  DebugInClientMessage::serializeAs_DebugInClientMessage(param1);
}

void ClientYouAreDrunkMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ClientYouAreDrunkMessage(param1);
}

void ClientYouAreDrunkMessage::deserializeAs_ClientYouAreDrunkMessage(Reader *param1)
{
  DebugInClientMessage::deserialize(param1);
}

ClientYouAreDrunkMessage::ClientYouAreDrunkMessage()
{
  m_type = MessageEnum::CLIENTYOUAREDRUNKMESSAGE;
}

