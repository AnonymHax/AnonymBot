#include "MimicryObjectFeedAndAssociateRequestMessage.h"

void MimicryObjectFeedAndAssociateRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MimicryObjectFeedAndAssociateRequestMessage(param1);
}

void MimicryObjectFeedAndAssociateRequestMessage::serializeAs_MimicryObjectFeedAndAssociateRequestMessage(Writer *param1)
{
  SymbioticObjectAssociateRequestMessage::serializeAs_SymbioticObjectAssociateRequestMessage(param1);
  if(this->foodUID < 0)
  {
    qDebug()<<"ERREUR - MimicryObjectFeedAndAssociateRequestMessage -"<<"Forbidden value (" << this->foodUID << ") on element foodUID.";
  }
  else
  {
    param1->writeVarInt((int)this->foodUID);
    if(this->foodPos < 0 || this->foodPos > 255)
    {
      qDebug()<<"ERREUR - MimicryObjectFeedAndAssociateRequestMessage -"<<"Forbidden value (" << this->foodPos << ") on element foodPos.";
    }
    else
    {
      param1->writeByte(this->foodPos);
      param1->writeBool(this->preview);
      return;
    }
  }
}

void MimicryObjectFeedAndAssociateRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MimicryObjectFeedAndAssociateRequestMessage(param1);
}

void MimicryObjectFeedAndAssociateRequestMessage::deserializeAs_MimicryObjectFeedAndAssociateRequestMessage(Reader *param1)
{
  SymbioticObjectAssociateRequestMessage::deserialize(param1);
  this->foodUID = param1->readVarUhInt();
  if(this->foodUID < 0)
  {
    qDebug()<<"ERREUR - MimicryObjectFeedAndAssociateRequestMessage -"<<"Forbidden value (" << this->foodUID << ") on element of MimicryObjectFeedAndAssociateRequestMessage.foodUID.";
  }
  else
  {
    this->foodPos = param1->readUByte();
    if(this->foodPos < 0 || this->foodPos > 255)
    {
      qDebug()<<"ERREUR - MimicryObjectFeedAndAssociateRequestMessage -"<<"Forbidden value (" << this->foodPos << ") on element of MimicryObjectFeedAndAssociateRequestMessage.foodPos.";
    }
    else
    {
      this->preview = param1->readBool();
      return;
    }
  }
}

MimicryObjectFeedAndAssociateRequestMessage::MimicryObjectFeedAndAssociateRequestMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE;
}

