#include "WrapperObjectDissociateRequestMessage.h"

void WrapperObjectDissociateRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_WrapperObjectDissociateRequestMessage(param1);
}

void WrapperObjectDissociateRequestMessage::serializeAs_WrapperObjectDissociateRequestMessage(Writer *param1)
{
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - WrapperObjectDissociateRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element hostUID.";
  }
  else
  {
    param1->writeVarInt((int)this->hostUID);
    if(this->hostPos < 0 || this->hostPos > 255)
    {
      qDebug()<<"ERREUR - WrapperObjectDissociateRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element hostPos.";
    }
    else
    {
      param1->writeByte(this->hostPos);
      return;
    }
  }
}

void WrapperObjectDissociateRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_WrapperObjectDissociateRequestMessage(param1);
}

void WrapperObjectDissociateRequestMessage::deserializeAs_WrapperObjectDissociateRequestMessage(Reader *param1)
{
  this->hostUID = param1->readVarUhInt();
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - WrapperObjectDissociateRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element of WrapperObjectDissociateRequestMessage.hostUID.";
  }
  else
  {
    this->hostPos = param1->readUByte();
    if(this->hostPos < 0 || this->hostPos > 255)
    {
      qDebug()<<"ERREUR - WrapperObjectDissociateRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element of WrapperObjectDissociateRequestMessage.hostPos.";
    }
    else
    {
      return;
    }
  }
}

WrapperObjectDissociateRequestMessage::WrapperObjectDissociateRequestMessage()
{
  m_type = MessageEnum::WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE;
}

