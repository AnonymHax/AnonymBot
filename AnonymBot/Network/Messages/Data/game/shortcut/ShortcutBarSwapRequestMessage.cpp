#include "ShortcutBarSwapRequestMessage.h"

void ShortcutBarSwapRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarSwapRequestMessage(param1);
}

void ShortcutBarSwapRequestMessage::serializeAs_ShortcutBarSwapRequestMessage(Writer *param1)
{
  param1->writeByte(this->barType);
  if(this->firstSlot < 0 || this->firstSlot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->firstSlot << ") on element firstSlot.";
  }
  else
  {
    param1->writeByte(this->firstSlot);
    if(this->secondSlot < 0 || this->secondSlot > 99)
    {
      qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->secondSlot << ") on element secondSlot.";
    }
    else
    {
      param1->writeByte(this->secondSlot);
      return;
    }
  }
}

void ShortcutBarSwapRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarSwapRequestMessage(param1);
}

void ShortcutBarSwapRequestMessage::deserializeAs_ShortcutBarSwapRequestMessage(Reader *param1)
{
  this->barType = param1->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarSwapRequestMessage.barType.";
  }
  else
  {
    this->firstSlot = param1->readByte();
    if(this->firstSlot < 0 || this->firstSlot > 99)
    {
      qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->firstSlot << ") on element of ShortcutBarSwapRequestMessage.firstSlot.";
    }
    else
    {
      this->secondSlot = param1->readByte();
      if(this->secondSlot < 0 || this->secondSlot > 99)
      {
        qDebug()<<"ERREUR - ShortcutBarSwapRequestMessage -"<<"Forbidden value (" << this->secondSlot << ") on element of ShortcutBarSwapRequestMessage.secondSlot.";
      }
      else
      {
        return;
      }
    }
  }
}

ShortcutBarSwapRequestMessage::ShortcutBarSwapRequestMessage()
{
  m_type = MessageEnum::SHORTCUTBARSWAPREQUESTMESSAGE;
}

