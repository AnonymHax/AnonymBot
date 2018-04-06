#include "StartupActionAddMessage.h"

void StartupActionAddMessage::serialize(Writer *param1)
{
  this->serializeAs_StartupActionAddMessage(param1);
}

void StartupActionAddMessage::serializeAs_StartupActionAddMessage(Writer *param1)
{
  this->newAction->serializeAs_StartupActionAddObject(param1);
}

void StartupActionAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StartupActionAddMessage(param1);
}

void StartupActionAddMessage::deserializeAs_StartupActionAddMessage(Reader *param1)
{
  this->newAction = QSharedPointer<StartupActionAddObject>(new StartupActionAddObject() );
  this->newAction->deserialize(param1);
}

StartupActionAddMessage::StartupActionAddMessage()
{
  m_type = MessageEnum::STARTUPACTIONADDMESSAGE;
}

