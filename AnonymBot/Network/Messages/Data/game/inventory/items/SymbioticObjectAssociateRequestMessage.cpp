#include "SymbioticObjectAssociateRequestMessage.h"

void SymbioticObjectAssociateRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_SymbioticObjectAssociateRequestMessage(param1);
}

void SymbioticObjectAssociateRequestMessage::serializeAs_SymbioticObjectAssociateRequestMessage(Writer *param1)
{
  if(this->symbioteUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->symbioteUID << ") on element symbioteUID.";
  }
  else
  {
    param1->writeVarInt((int)this->symbioteUID);
    if(this->symbiotePos < 0 || this->symbiotePos > 255)
    {
      qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->symbiotePos << ") on element symbiotePos.";
    }
    else
    {
      param1->writeByte(this->symbiotePos);
      if(this->hostUID < 0)
      {
        qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element hostUID.";
      }
      else
      {
        param1->writeVarInt((int)this->hostUID);
        if(this->hostPos < 0 || this->hostPos > 255)
        {
          qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element hostPos.";
        }
        else
        {
          param1->writeByte(this->hostPos);
          return;
        }
      }
    }
  }
}

void SymbioticObjectAssociateRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SymbioticObjectAssociateRequestMessage(param1);
}

void SymbioticObjectAssociateRequestMessage::deserializeAs_SymbioticObjectAssociateRequestMessage(Reader *param1)
{
  this->symbioteUID = param1->readVarUhInt();
  if(this->symbioteUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->symbioteUID << ") on element of SymbioticObjectAssociateRequestMessage.symbioteUID.";
  }
  else
  {
    this->symbiotePos = param1->readUByte();
    if(this->symbiotePos < 0 || this->symbiotePos > 255)
    {
      qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->symbiotePos << ") on element of SymbioticObjectAssociateRequestMessage.symbiotePos.";
    }
    else
    {
      this->hostUID = param1->readVarUhInt();
      if(this->hostUID < 0)
      {
        qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element of SymbioticObjectAssociateRequestMessage.hostUID.";
      }
      else
      {
        this->hostPos = param1->readUByte();
        if(this->hostPos < 0 || this->hostPos > 255)
        {
          qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element of SymbioticObjectAssociateRequestMessage.hostPos.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

SymbioticObjectAssociateRequestMessage::SymbioticObjectAssociateRequestMessage()
{
  m_type = MessageEnum::SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE;
}

