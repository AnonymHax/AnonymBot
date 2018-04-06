#include "TextInformationMessage.h"

void TextInformationMessage::serialize(Writer *param1)
{
  this->serializeAs_TextInformationMessage(param1);
}

void TextInformationMessage::serializeAs_TextInformationMessage(Writer *param1)
{
  param1->writeByte(this->msgType);
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - TextInformationMessage -"<<"Forbidden value (" << this->msgId << ") on element msgId.";
  }
  else
  {
    param1->writeVarShort((int)this->msgId);
    param1->writeShort((short)this->parameters.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->parameters.size())
    {
      param1->writeUTF(this->parameters[_loc2_]);
      _loc2_++;
    }
    return;
  }
}

void TextInformationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TextInformationMessage(param1);
}

void TextInformationMessage::deserializeAs_TextInformationMessage(Reader *param1)
{
  QString _loc4_ ;
  this->msgType = param1->readByte();
  if(this->msgType < 0)
  {
    qDebug()<<"ERREUR - TextInformationMessage -"<<"Forbidden value (" << this->msgType << ") on element of TextInformationMessage.msgType.";
  }
  else
  {
    this->msgId = param1->readVarUhShort();
    if(this->msgId < 0)
    {
      qDebug()<<"ERREUR - TextInformationMessage -"<<"Forbidden value (" << this->msgId << ") on element of TextInformationMessage.msgId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = param1->readUTF();
        this->parameters.append(_loc4_);
        _loc3_++;
      }
      return;
    }
  }
}

TextInformationMessage::TextInformationMessage()
{
  m_type = MessageEnum::TEXTINFORMATIONMESSAGE;
}

