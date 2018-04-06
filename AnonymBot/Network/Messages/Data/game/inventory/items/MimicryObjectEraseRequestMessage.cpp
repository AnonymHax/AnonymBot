#include "MimicryObjectEraseRequestMessage.h"

void MimicryObjectEraseRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MimicryObjectEraseRequestMessage(param1);
}

void MimicryObjectEraseRequestMessage::serializeAs_MimicryObjectEraseRequestMessage(Writer *param1)
{
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - MimicryObjectEraseRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element hostUID.";
  }
  else
  {
    param1->writeVarInt((int)this->hostUID);
    if(this->hostPos < 0 || this->hostPos > 255)
    {
      qDebug()<<"ERREUR - MimicryObjectEraseRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element hostPos.";
    }
    else
    {
      param1->writeByte(this->hostPos);
      return;
    }
  }
}

void MimicryObjectEraseRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MimicryObjectEraseRequestMessage(param1);
}

void MimicryObjectEraseRequestMessage::deserializeAs_MimicryObjectEraseRequestMessage(Reader *param1)
{
  this->hostUID = param1->readVarUhInt();
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - MimicryObjectEraseRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element of MimicryObjectEraseRequestMessage.hostUID.";
  }
  else
  {
    this->hostPos = param1->readUByte();
    if(this->hostPos < 0 || this->hostPos > 255)
    {
      qDebug()<<"ERREUR - MimicryObjectEraseRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element of MimicryObjectEraseRequestMessage.hostPos.";
    }
    else
    {
      return;
    }
  }
}

MimicryObjectEraseRequestMessage::MimicryObjectEraseRequestMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTERASEREQUESTMESSAGE;
}

