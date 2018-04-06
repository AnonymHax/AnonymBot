#include "GuildInfosUpgradeMessage.h"

void GuildInfosUpgradeMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInfosUpgradeMessage(param1);
}

void GuildInfosUpgradeMessage::serializeAs_GuildInfosUpgradeMessage(Writer *param1)
{
  if(this->maxTaxCollectorsCount < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->maxTaxCollectorsCount << ") on element maxTaxCollectorsCount.";
  }
  else
  {
    param1->writeByte(this->maxTaxCollectorsCount);
    if(this->taxCollectorsCount < 0)
    {
      qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorsCount << ") on element taxCollectorsCount.";
    }
    else
    {
      param1->writeByte(this->taxCollectorsCount);
      if(this->taxCollectorLifePoints < 0)
      {
        qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorLifePoints << ") on element taxCollectorLifePoints.";
      }
      else
      {
        param1->writeVarShort((int)this->taxCollectorLifePoints);
        if(this->taxCollectorDamagesBonuses < 0)
        {
          qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorDamagesBonuses << ") on element taxCollectorDamagesBonuses.";
        }
        else
        {
          param1->writeVarShort((int)this->taxCollectorDamagesBonuses);
          if(this->taxCollectorPods < 0)
          {
            qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorPods << ") on element taxCollectorPods.";
          }
          else
          {
            param1->writeVarShort((int)this->taxCollectorPods);
            if(this->taxCollectorProspecting < 0)
            {
              qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorProspecting << ") on element taxCollectorProspecting.";
            }
            else
            {
              param1->writeVarShort((int)this->taxCollectorProspecting);
              if(this->taxCollectorWisdom < 0)
              {
                qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorWisdom << ") on element taxCollectorWisdom.";
              }
              else
              {
                param1->writeVarShort((int)this->taxCollectorWisdom);
                if(this->boostPoints < 0)
                {
                  qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->boostPoints << ") on element boostPoints.";
                }
                else
                {
                  param1->writeVarShort((int)this->boostPoints);
                  param1->writeShort((short)this->spellId.size());
                  uint _loc2_ = 0;
                  while(_loc2_ < this->spellId.size())
                  {
                    if(this->spellId[_loc2_] < 0)
                    {
                      qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->spellId[_loc2_] << ") on element 9 (starting at 1) of spellId.";
                    }
                    else
                    {
                      param1->writeVarShort((int)this->spellId[_loc2_]);
                      _loc2_++;
                      continue;
                    }
                  }
                  param1->writeShort((short)this->spellLevel.size());
                  uint _loc3_ = 0;
                  while(_loc3_ < this->spellLevel.size())
                  {
                    param1->writeShort((short)this->spellLevel[_loc3_]);
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
  }
}

void GuildInfosUpgradeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInfosUpgradeMessage(param1);
}

void GuildInfosUpgradeMessage::deserializeAs_GuildInfosUpgradeMessage(Reader *param1)
{
  uint _loc6_ = 0;
  auto _loc7_ = 0;
  this->maxTaxCollectorsCount = param1->readByte();
  if(this->maxTaxCollectorsCount < 0)
  {
    qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->maxTaxCollectorsCount << ") on element of GuildInfosUpgradeMessage.maxTaxCollectorsCount.";
  }
  else
  {
    this->taxCollectorsCount = param1->readByte();
    if(this->taxCollectorsCount < 0)
    {
      qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorsCount << ") on element of GuildInfosUpgradeMessage.taxCollectorsCount.";
    }
    else
    {
      this->taxCollectorLifePoints = param1->readVarUhShort();
      if(this->taxCollectorLifePoints < 0)
      {
        qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorLifePoints << ") on element of GuildInfosUpgradeMessage.taxCollectorLifePoints.";
      }
      else
      {
        this->taxCollectorDamagesBonuses = param1->readVarUhShort();
        if(this->taxCollectorDamagesBonuses < 0)
        {
          qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorDamagesBonuses << ") on element of GuildInfosUpgradeMessage.taxCollectorDamagesBonuses.";
        }
        else
        {
          this->taxCollectorPods = param1->readVarUhShort();
          if(this->taxCollectorPods < 0)
          {
            qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorPods << ") on element of GuildInfosUpgradeMessage.taxCollectorPods.";
          }
          else
          {
            this->taxCollectorProspecting = param1->readVarUhShort();
            if(this->taxCollectorProspecting < 0)
            {
              qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorProspecting << ") on element of GuildInfosUpgradeMessage.taxCollectorProspecting.";
            }
            else
            {
              this->taxCollectorWisdom = param1->readVarUhShort();
              if(this->taxCollectorWisdom < 0)
              {
                qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->taxCollectorWisdom << ") on element of GuildInfosUpgradeMessage.taxCollectorWisdom.";
              }
              else
              {
                this->boostPoints = param1->readVarUhShort();
                if(this->boostPoints < 0)
                {
                  qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << this->boostPoints << ") on element of GuildInfosUpgradeMessage.boostPoints.";
                }
                else
                {
                  uint _loc2_ = param1->readUShort();
                  uint _loc3_ = 0;
                  while(_loc3_ < _loc2_)
                  {
                    _loc6_ = param1->readVarUhShort();
                    if(_loc6_ < 0)
                    {
                      qDebug()<<"ERREUR - GuildInfosUpgradeMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of spellId.";
                    }
                    else
                    {
                      this->spellId.append(_loc6_);
                      _loc3_++;
                      continue;
                    }
                  }
                  uint _loc4_ = param1->readUShort();
                  uint _loc5_ = 0;
                  while(_loc5_ < _loc4_)
                  {
                    _loc7_ = param1->readShort();
                    this->spellLevel.append(_loc7_);
                    _loc5_++;
                  }
                  return;
                }
              }
            }
          }
        }
      }
    }
  }
}

GuildInfosUpgradeMessage::GuildInfosUpgradeMessage()
{
  m_type = MessageEnum::GUILDINFOSUPGRADEMESSAGE;
}

