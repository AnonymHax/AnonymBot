#include "ShortcutBarSwapErrorMessage.h"

void ShortcutBarSwapErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarSwapErrorMessage(param1);
}

void ShortcutBarSwapErrorMessage::serializeAs_ShortcutBarSwapErrorMessage(Writer *param1)
{
  param1->writeByte(this->error);
}

void ShortcutBarSwapErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarSwapErrorMessage(param1);
}

void ShortcutBarSwapErrorMessage::deserializeAs_ShortcutBarSwapErrorMessage(Reader *param1)
{
  this->error = param1->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarSwapErrorMessage -"<<"Forbidden value (" << this->error << ") on element of ShortcutBarSwapErrorMessage.error.";
  }
  else
  {
    return;
  }
}

ShortcutBarSwapErrorMessage::ShortcutBarSwapErrorMessage()
{
  m_type = MessageEnum::SHORTCUTBARSWAPERRORMESSAGE;
}

