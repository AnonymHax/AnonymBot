#include "ShowCellSpectatorMessage.h"

void ShowCellSpectatorMessage::serialize(Writer *param1)
{
  this->serializeAs_ShowCellSpectatorMessage(param1);
}

void ShowCellSpectatorMessage::serializeAs_ShowCellSpectatorMessage(Writer *param1)
{
  ShowCellMessage::serializeAs_ShowCellMessage(param1);
  param1->writeUTF(this->playerName);
}

void ShowCellSpectatorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShowCellSpectatorMessage(param1);
}

void ShowCellSpectatorMessage::deserializeAs_ShowCellSpectatorMessage(Reader *param1)
{
  ShowCellMessage::deserialize(param1);
  this->playerName = param1->readUTF();
}

ShowCellSpectatorMessage::ShowCellSpectatorMessage()
{
  m_type = MessageEnum::SHOWCELLSPECTATORMESSAGE;
}

