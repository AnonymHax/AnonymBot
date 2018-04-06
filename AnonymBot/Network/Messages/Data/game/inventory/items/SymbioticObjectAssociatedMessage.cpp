#include "SymbioticObjectAssociatedMessage.h"

void SymbioticObjectAssociatedMessage::serialize(Writer *param1)
{
  this->serializeAs_SymbioticObjectAssociatedMessage(param1);
}

void SymbioticObjectAssociatedMessage::serializeAs_SymbioticObjectAssociatedMessage(Writer *param1)
{
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociatedMessage -"<<"Forbidden value (" << this->hostUID << ") on element hostUID.";
  }
  else
  {
    param1->writeVarInt((int)this->hostUID);
    return;
  }
}

void SymbioticObjectAssociatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SymbioticObjectAssociatedMessage(param1);
}

void SymbioticObjectAssociatedMessage::deserializeAs_SymbioticObjectAssociatedMessage(Reader *param1)
{
  this->hostUID = param1->readVarUhInt();
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociatedMessage -"<<"Forbidden value (" << this->hostUID << ") on element of SymbioticObjectAssociatedMessage.hostUID.";
  }
  else
  {
    return;
  }
}

SymbioticObjectAssociatedMessage::SymbioticObjectAssociatedMessage()
{
  m_type = MessageEnum::SYMBIOTICOBJECTASSOCIATEDMESSAGE;
}

