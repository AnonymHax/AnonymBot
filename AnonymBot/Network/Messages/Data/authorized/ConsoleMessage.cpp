#include "ConsoleMessage.h"

void ConsoleMessage::serialize(Writer *param1)
{
  this->serializeAs_ConsoleMessage(param1);
}

void ConsoleMessage::serializeAs_ConsoleMessage(Writer *param1)
{
  param1->writeByte(this->type);
  param1->writeUTF(this->content);
}

void ConsoleMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ConsoleMessage(param1);
}

void ConsoleMessage::deserializeAs_ConsoleMessage(Reader *param1)
{
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - ConsoleMessage -"<<"Forbidden value (" << this->type << ") on element of ConsoleMessage.type.";
  }
  else
  {
    this->content = param1->readUTF();
    return;
  }
}

ConsoleMessage::ConsoleMessage()
{
  m_type = MessageEnum::CONSOLEMESSAGE;
}

