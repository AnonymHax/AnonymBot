#include "PaddockInformationsForSell.h"

void PaddockInformationsForSell::serialize(Writer *param1)
{
  this->serializeAs_PaddockInformationsForSell(param1);
}

void PaddockInformationsForSell::serializeAs_PaddockInformationsForSell(Writer *param1)
{
  param1->writeUTF(this->guildOwner);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      if(this->subAreaId < 0)
      {
        qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
      }
      else
      {
        param1->writeVarShort((int)this->subAreaId);
        param1->writeByte(this->nbMount);
        param1->writeByte(this->nbObject);
        if(this->price < 0)
        {
          qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->price << ") on element price.";
        }
        else
        {
          param1->writeVarInt((int)this->price);
          return;
        }
      }
    }
  }
}

void PaddockInformationsForSell::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockInformationsForSell(param1);
}

void PaddockInformationsForSell::deserializeAs_PaddockInformationsForSell(Reader *param1)
{
  this->guildOwner = param1->readUTF();
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->worldX << ") on element of PaddockInformationsForSell.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->worldY << ") on element of PaddockInformationsForSell.worldY.";
    }
    else
    {
      this->subAreaId = param1->readVarUhShort();
      if(this->subAreaId < 0)
      {
        qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->subAreaId << ") on element of PaddockInformationsForSell.subAreaId.";
      }
      else
      {
        this->nbMount = param1->readByte();
        this->nbObject = param1->readByte();
        this->price = param1->readVarUhInt();
        if(this->price < 0)
        {
          qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->price << ") on element of PaddockInformationsForSell.price.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

PaddockInformationsForSell::PaddockInformationsForSell()
{
  m_types<<ClassEnum::PADDOCKINFORMATIONSFORSELL;
}

bool PaddockInformationsForSell::operator==(const PaddockInformationsForSell &compared)
{
  if(guildOwner == compared.guildOwner)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(subAreaId == compared.subAreaId)
  if(nbMount == compared.nbMount)
  if(nbObject == compared.nbObject)
  if(price == compared.price)
  return true;
  
  return false;
}

