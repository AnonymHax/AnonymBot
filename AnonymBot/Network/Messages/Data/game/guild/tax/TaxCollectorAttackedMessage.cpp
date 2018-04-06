#include "TaxCollectorAttackedMessage.h"

void TaxCollectorAttackedMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorAttackedMessage(param1);
}

void TaxCollectorAttackedMessage::serializeAs_TaxCollectorAttackedMessage(Writer *param1)
{
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  else
  {
    param1->writeVarShort((int)this->firstNameId);
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
    }
    else
    {
      param1->writeVarShort((int)this->lastNameId);
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
      }
      else
      {
        param1->writeShort((short)this->worldX);
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
        }
        else
        {
          param1->writeShort((short)this->worldY);
          param1->writeInt((int)this->mapId);
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
          }
          else
          {
            param1->writeVarShort((int)this->subAreaId);
            this->guild->serializeAs_BasicGuildInformations(param1);
            return;
          }
        }
      }
    }
  }
}

void TaxCollectorAttackedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorAttackedMessage(param1);
}

void TaxCollectorAttackedMessage::deserializeAs_TaxCollectorAttackedMessage(Reader *param1)
{
  this->firstNameId = param1->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->firstNameId << ") on element of TaxCollectorAttackedMessage.firstNameId.";
  }
  else
  {
    this->lastNameId = param1->readVarUhShort();
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->lastNameId << ") on element of TaxCollectorAttackedMessage.lastNameId.";
    }
    else
    {
      this->worldX = param1->readShort();
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->worldX << ") on element of TaxCollectorAttackedMessage.worldX.";
      }
      else
      {
        this->worldY = param1->readShort();
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->worldY << ") on element of TaxCollectorAttackedMessage.worldY.";
        }
        else
        {
          this->mapId = param1->readInt();
          this->subAreaId = param1->readVarUhShort();
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of TaxCollectorAttackedMessage.subAreaId.";
          }
          else
          {
            this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
            this->guild->deserialize(param1);
            return;
          }
        }
      }
    }
  }
}

TaxCollectorAttackedMessage::TaxCollectorAttackedMessage()
{
  m_type = MessageEnum::TAXCOLLECTORATTACKEDMESSAGE;
}

