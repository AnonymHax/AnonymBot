#include "GuildInformationsPaddocksMessage.h"

void GuildInformationsPaddocksMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInformationsPaddocksMessage(param1);
}

void GuildInformationsPaddocksMessage::serializeAs_GuildInformationsPaddocksMessage(Writer *param1)
{
  if(this->nbPaddockMax < 0)
  {
    qDebug()<<"ERREUR - GuildInformationsPaddocksMessage -"<<"Forbidden value (" << this->nbPaddockMax << ") on element nbPaddockMax.";
  }
  else
  {
    param1->writeByte(this->nbPaddockMax);
    param1->writeShort((short)this->paddocksInformations.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->paddocksInformations.size())
    {
      qSharedPointerCast<PaddockContentInformations>(this->paddocksInformations[_loc2_])->serializeAs_PaddockContentInformations(param1);
      _loc2_++;
    }
    return;
  }
}

void GuildInformationsPaddocksMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInformationsPaddocksMessage(param1);
}

void GuildInformationsPaddocksMessage::deserializeAs_GuildInformationsPaddocksMessage(Reader *param1)
{
  QSharedPointer<PaddockContentInformations> _loc4_ ;
  this->nbPaddockMax = param1->readByte();
  if(this->nbPaddockMax < 0)
  {
    qDebug()<<"ERREUR - GuildInformationsPaddocksMessage -"<<"Forbidden value (" << this->nbPaddockMax << ") on element of GuildInformationsPaddocksMessage.nbPaddockMax.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = QSharedPointer<PaddockContentInformations>(new PaddockContentInformations() );
      _loc4_->deserialize(param1);
      this->paddocksInformations.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

GuildInformationsPaddocksMessage::GuildInformationsPaddocksMessage()
{
  m_type = MessageEnum::GUILDINFORMATIONSPADDOCKSMESSAGE;
}

