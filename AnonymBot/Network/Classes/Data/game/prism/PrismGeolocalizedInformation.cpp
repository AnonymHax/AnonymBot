#include "PrismGeolocalizedInformation.h"

void PrismGeolocalizedInformation::serialize(Writer *param1)
{
  this->serializeAs_PrismGeolocalizedInformation(param1);
}

void PrismGeolocalizedInformation::serializeAs_PrismGeolocalizedInformation(Writer *param1)
{
  PrismSubareaEmptyInfo::serializeAs_PrismSubareaEmptyInfo(param1);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      param1->writeInt((int)this->mapId);
      param1->writeShort((short)this->prism->getTypes().last());
      this->prism->serialize(param1);
      return;
    }
  }
}

void PrismGeolocalizedInformation::deserialize(Reader *param1)
{
  this->deserializeAs_PrismGeolocalizedInformation(param1);
}

void PrismGeolocalizedInformation::deserializeAs_PrismGeolocalizedInformation(Reader *param1)
{
  PrismSubareaEmptyInfo::deserialize(param1);
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->worldX << ") on element of PrismGeolocalizedInformation.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->worldY << ") on element of PrismGeolocalizedInformation.worldY.";
    }
    else
    {
      this->mapId = param1->readInt();
      uint _loc2_ = param1->readUShort();
      this->prism = qSharedPointerCast<PrismInformation>(ClassManagerSingleton::get()->getClass(_loc2_));
      this->prism->deserialize(param1);
      return;
    }
  }
}

PrismGeolocalizedInformation::PrismGeolocalizedInformation()
{
  m_types<<ClassEnum::PRISMGEOLOCALIZEDINFORMATION;
}

bool PrismGeolocalizedInformation::operator==(const PrismGeolocalizedInformation &compared)
{
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(prism == compared.prism)
  return true;
  
  return false;
}

