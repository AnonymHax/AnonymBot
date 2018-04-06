#include "TaxCollectorListMessage.h"

void TaxCollectorListMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorListMessage(param1);
}

void TaxCollectorListMessage::serializeAs_TaxCollectorListMessage(Writer *param1)
{
  AbstractTaxCollectorListMessage::serializeAs_AbstractTaxCollectorListMessage(param1);
  if(this->nbcollectorMax < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorListMessage -"<<"Forbidden value (" << this->nbcollectorMax << ") on element nbcollectorMax.";
  }
  else
  {
    param1->writeByte(this->nbcollectorMax);
    param1->writeShort((short)this->fightersInformations.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->fightersInformations.size())
    {
      qSharedPointerCast<TaxCollectorFightersInformation>(this->fightersInformations[_loc2_])->serializeAs_TaxCollectorFightersInformation(param1);
      _loc2_++;
    }
    return;
  }
}

void TaxCollectorListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorListMessage(param1);
}

void TaxCollectorListMessage::deserializeAs_TaxCollectorListMessage(Reader *param1)
{
  QSharedPointer<TaxCollectorFightersInformation> _loc4_ ;
  AbstractTaxCollectorListMessage::deserialize(param1);
  this->nbcollectorMax = param1->readByte();
  if(this->nbcollectorMax < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorListMessage -"<<"Forbidden value (" << this->nbcollectorMax << ") on element of TaxCollectorListMessage.nbcollectorMax.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = QSharedPointer<TaxCollectorFightersInformation>(new TaxCollectorFightersInformation() );
      _loc4_->deserialize(param1);
      this->fightersInformations.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

TaxCollectorListMessage::TaxCollectorListMessage()
{
  m_type = MessageEnum::TAXCOLLECTORLISTMESSAGE;
}

