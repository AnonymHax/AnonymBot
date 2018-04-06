#include "ConsoleCommandsListMessage.h"

void ConsoleCommandsListMessage::serialize(Writer *param1)
{
  this->serializeAs_ConsoleCommandsListMessage(param1);
}

void ConsoleCommandsListMessage::serializeAs_ConsoleCommandsListMessage(Writer *param1)
{
  param1->writeShort((short)this->aliases.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->aliases.size())
  {
    param1->writeUTF(this->aliases[_loc2_]);
    _loc2_++;
  }
  param1->writeShort((short)this->args.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->args.size())
  {
    param1->writeUTF(this->args[_loc3_]);
    _loc3_++;
  }
  param1->writeShort((short)this->descriptions.size());
  uint _loc4_ = 0;
  while(_loc4_ < this->descriptions.size())
  {
    param1->writeUTF(this->descriptions[_loc4_]);
    _loc4_++;
  }
}

void ConsoleCommandsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ConsoleCommandsListMessage(param1);
}

void ConsoleCommandsListMessage::deserializeAs_ConsoleCommandsListMessage(Reader *param1)
{
  QString _loc8_ ;
  QString _loc9_ ;
  QString _loc10_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc8_ = param1->readUTF();
    this->aliases.append(_loc8_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc9_ = param1->readUTF();
    this->args.append(_loc9_);
    _loc5_++;
  }
  uint _loc6_ = param1->readUShort();
  uint _loc7_ = 0;
  while(_loc7_ < _loc6_)
  {
    _loc10_ = param1->readUTF();
    this->descriptions.append(_loc10_);
    _loc7_++;
  }
}

ConsoleCommandsListMessage::ConsoleCommandsListMessage()
{
  m_type = MessageEnum::CONSOLECOMMANDSLISTMESSAGE;
}

