#include "AllianceInsiderPrismInformation.h"

void AllianceInsiderPrismInformation::serialize(Writer *param1)
{
  this->serializeAs_AllianceInsiderPrismInformation(param1);
}

void AllianceInsiderPrismInformation::serializeAs_AllianceInsiderPrismInformation(Writer *param1)
{
  PrismInformation::serializeAs_PrismInformation(param1);
  if(this->lastTimeSlotModificationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationDate << ") on element lastTimeSlotModificationDate.";
  }
  else
  {
    param1->writeInt((int)this->lastTimeSlotModificationDate);
    if(this->lastTimeSlotModificationAuthorGuildId < 0)
    {
      qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationAuthorGuildId << ") on element lastTimeSlotModificationAuthorGuildId.";
    }
    else
    {
      param1->writeVarInt((int)this->lastTimeSlotModificationAuthorGuildId);
      if(this->lastTimeSlotModificationAuthorId < 0 || this->lastTimeSlotModificationAuthorId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationAuthorId << ") on element lastTimeSlotModificationAuthorId.";
      }
      else
      {
        param1->writeVarLong((double)this->lastTimeSlotModificationAuthorId);
        param1->writeUTF(this->lastTimeSlotModificationAuthorName);
        param1->writeShort((short)this->modulesObjects.size());
        uint _loc2_ = 0;
        while(_loc2_ < this->modulesObjects.size())
        {
          qSharedPointerCast<ObjectItem>(this->modulesObjects[_loc2_])->serializeAs_ObjectItem(param1);
          _loc2_++;
        }
        return;
      }
    }
  }
}

void AllianceInsiderPrismInformation::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceInsiderPrismInformation(param1);
}

void AllianceInsiderPrismInformation::deserializeAs_AllianceInsiderPrismInformation(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  PrismInformation::deserialize(param1);
  this->lastTimeSlotModificationDate = param1->readInt();
  if(this->lastTimeSlotModificationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationDate << ") on element of AllianceInsiderPrismInformation.lastTimeSlotModificationDate.";
  }
  else
  {
    this->lastTimeSlotModificationAuthorGuildId = param1->readVarUhInt();
    if(this->lastTimeSlotModificationAuthorGuildId < 0)
    {
      qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationAuthorGuildId << ") on element of AllianceInsiderPrismInformation.lastTimeSlotModificationAuthorGuildId.";
    }
    else
    {
      this->lastTimeSlotModificationAuthorId = param1->readVarUhLong();
      if(this->lastTimeSlotModificationAuthorId < 0 || this->lastTimeSlotModificationAuthorId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationAuthorId << ") on element of AllianceInsiderPrismInformation.lastTimeSlotModificationAuthorId.";
      }
      else
      {
        this->lastTimeSlotModificationAuthorName = param1->readUTF();
        uint _loc2_ = param1->readUShort();
        uint _loc3_ = 0;
        while(_loc3_ < _loc2_)
        {
          _loc4_ = QSharedPointer<ObjectItem>(new ObjectItem() );
          _loc4_->deserialize(param1);
          this->modulesObjects.append(_loc4_);
          _loc3_++;
        }
        return;
      }
    }
  }
}

AllianceInsiderPrismInformation::AllianceInsiderPrismInformation()
{
  m_types<<ClassEnum::ALLIANCEINSIDERPRISMINFORMATION;
}

bool AllianceInsiderPrismInformation::operator==(const AllianceInsiderPrismInformation &compared)
{
  if(lastTimeSlotModificationDate == compared.lastTimeSlotModificationDate)
  if(lastTimeSlotModificationAuthorGuildId == compared.lastTimeSlotModificationAuthorGuildId)
  if(lastTimeSlotModificationAuthorId == compared.lastTimeSlotModificationAuthorId)
  if(lastTimeSlotModificationAuthorName == compared.lastTimeSlotModificationAuthorName)
  if(modulesObjects == compared.modulesObjects)
  return true;
  
  return false;
}

