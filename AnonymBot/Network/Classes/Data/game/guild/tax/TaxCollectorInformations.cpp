#include "TaxCollectorInformations.h"

void TaxCollectorInformations::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorInformations(param1);
}

void TaxCollectorInformations::serializeAs_TaxCollectorInformations(Writer *param1)
{
  param1->writeInt((int)this->uniqueId);
  if(this->firtNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->firtNameId << ") on element firtNameId.";
  }
  else
  {
    param1->writeVarShort((int)this->firtNameId);
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
    }
    else
    {
      param1->writeVarShort((int)this->lastNameId);
      this->additionalInfos.serializeAs_AdditionalTaxCollectorInformations(param1);
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
      }
      else
      {
        param1->writeShort((short)this->worldX);
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
        }
        else
        {
          param1->writeShort((short)this->worldY);
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
          }
          else
          {
            param1->writeVarShort((int)this->subAreaId);
            param1->writeByte(this->state);
            this->look->serializeAs_EntityLook(param1);
            param1->writeShort((short)this->complements.size());
            uint _loc2_ = 0;
            while(_loc2_ < this->complements.size())
            {
              param1->writeShort((short)qSharedPointerCast<TaxCollectorComplementaryInformations>(this->complements[_loc2_])->getTypes().last());
              qSharedPointerCast<TaxCollectorComplementaryInformations>(this->complements[_loc2_])->serialize(param1);
              _loc2_++;
            }
            return;
          }
        }
      }
    }
  }
}

void TaxCollectorInformations::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorInformations(param1);
}

void TaxCollectorInformations::deserializeAs_TaxCollectorInformations(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<TaxCollectorComplementaryInformations> _loc5_ ;
  this->uniqueId = param1->readInt();
  this->firtNameId = param1->readVarUhShort();
  if(this->firtNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->firtNameId << ") on element of TaxCollectorInformations.firtNameId.";
  }
  else
  {
    this->lastNameId = param1->readVarUhShort();
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of TaxCollectorInformations.lastNameId.";
    }
    else
    {
      this->additionalInfos = AdditionalTaxCollectorInformations();
      this->additionalInfos.deserialize(param1);
      this->worldX = param1->readShort();
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->worldX << ") on element of TaxCollectorInformations.worldX.";
      }
      else
      {
        this->worldY = param1->readShort();
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->worldY << ") on element of TaxCollectorInformations.worldY.";
        }
        else
        {
          this->subAreaId = param1->readVarUhShort();
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of TaxCollectorInformations.subAreaId.";
          }
          else
          {
            this->state = param1->readByte();
            if(this->state < 0)
            {
              qDebug()<<"ERREUR - TaxCollectorInformations -"<<"Forbidden value (" << this->state << ") on element of TaxCollectorInformations.state.";
            }
            else
            {
              this->look = QSharedPointer<EntityLook>(new EntityLook() );
              this->look->deserialize(param1);
              uint _loc2_ = param1->readUShort();
              uint _loc3_ = 0;
              while(_loc3_ < _loc2_)
              {
                _loc4_ = param1->readUShort();
                _loc5_ = qSharedPointerCast<TaxCollectorComplementaryInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
                _loc5_->deserialize(param1);
                this->complements.append(_loc5_);
                _loc3_++;
              }
              return;
            }
          }
        }
      }
    }
  }
}

TaxCollectorInformations::TaxCollectorInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORINFORMATIONS;
}

bool TaxCollectorInformations::operator==(const TaxCollectorInformations &compared)
{
  if(uniqueId == compared.uniqueId)
  if(firtNameId == compared.firtNameId)
  if(lastNameId == compared.lastNameId)
  if(additionalInfos == compared.additionalInfos)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(subAreaId == compared.subAreaId)
  if(state == compared.state)
  if(look == compared.look)
  if(complements == compared.complements)
  return true;
  
  return false;
}

