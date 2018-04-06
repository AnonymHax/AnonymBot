#include "DareInformations.h"

void DareInformations::serialize(Writer *param1)
{
  this->serializeAs_DareInformations(param1);
}

void DareInformations::serializeAs_DareInformations(Writer *param1)
{
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    this->creator.serializeAs_CharacterBasicMinimalInformations(param1);
    if(this->subscriptionFee < 0)
    {
      qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->subscriptionFee << ") on element subscriptionFee.";
    }
    else
    {
      param1->writeInt((int)this->subscriptionFee);
      if(this->jackpot < 0)
      {
        qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->jackpot << ") on element jackpot.";
      }
      else
      {
        param1->writeInt((int)this->jackpot);
        if(this->maxCountWinners < 0 || this->maxCountWinners > 65535)
        {
          qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->maxCountWinners << ") on element maxCountWinners.";
        }
        else
        {
          param1->writeShort((short)this->maxCountWinners);
          if(this->endDate < 0 || this->endDate > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->endDate << ") on element endDate.";
          }
          else
          {
            param1->writeDouble(this->endDate);
            param1->writeBool(this->isPrivate);
            if(this->guildId < 0)
            {
              qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
            }
            else
            {
              param1->writeVarInt((int)this->guildId);
              if(this->allianceId < 0)
              {
                qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
              }
              else
              {
                param1->writeVarInt((int)this->allianceId);
                param1->writeShort((short)this->criterions.size());
                uint _loc2_ = 0;
                while(_loc2_ < this->criterions.size())
                {
                  (this->criterions[_loc2_]).serializeAs_DareCriteria(param1);
                  _loc2_++;
                }
                if(this->startDate < 0 || this->startDate > 9.007199254740992E15)
                {
                  qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->startDate << ") on element startDate.";
                }
                else
                {
                  param1->writeDouble(this->startDate);
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

void DareInformations::deserialize(Reader *param1)
{
  this->deserializeAs_DareInformations(param1);
}

void DareInformations::deserializeAs_DareInformations(Reader *param1)
{
  DareCriteria _loc4_ ;
  this->dareId = param1->readDouble();
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->dareId << ") on element of DareInformations.dareId.";
  }
  else
  {
    this->creator = CharacterBasicMinimalInformations();
    this->creator.deserialize(param1);
    this->subscriptionFee = param1->readInt();
    if(this->subscriptionFee < 0)
    {
      qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->subscriptionFee << ") on element of DareInformations.subscriptionFee.";
    }
    else
    {
      this->jackpot = param1->readInt();
      if(this->jackpot < 0)
      {
        qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->jackpot << ") on element of DareInformations.jackpot.";
      }
      else
      {
        this->maxCountWinners = param1->readUShort();
        if(this->maxCountWinners < 0 || this->maxCountWinners > 65535)
        {
          qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->maxCountWinners << ") on element of DareInformations.maxCountWinners.";
        }
        else
        {
          this->endDate = param1->readDouble();
          if(this->endDate < 0 || this->endDate > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->endDate << ") on element of DareInformations.endDate.";
          }
          else
          {
            this->isPrivate = param1->readBool();
            this->guildId = param1->readVarUhInt();
            if(this->guildId < 0)
            {
              qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->guildId << ") on element of DareInformations.guildId.";
            }
            else
            {
              this->allianceId = param1->readVarUhInt();
              if(this->allianceId < 0)
              {
                qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->allianceId << ") on element of DareInformations.allianceId.";
              }
              else
              {
                uint _loc2_ = param1->readUShort();
                uint _loc3_ = 0;
                while(_loc3_ < _loc2_)
                {
                  _loc4_ = DareCriteria();
                  _loc4_.deserialize(param1);
                  this->criterions.append(_loc4_);
                  _loc3_++;
                }
                this->startDate = param1->readDouble();
                if(this->startDate < 0 || this->startDate > 9.007199254740992E15)
                {
                  qDebug()<<"ERREUR - DareInformations -"<<"Forbidden value (" << this->startDate << ") on element of DareInformations.startDate.";
                }
                else
                {
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

DareInformations::DareInformations()
{
  m_types<<ClassEnum::DAREINFORMATIONS;
}

bool DareInformations::operator==(const DareInformations &compared)
{
  if(dareId == compared.dareId)
  if(creator == compared.creator)
  if(subscriptionFee == compared.subscriptionFee)
  if(jackpot == compared.jackpot)
  if(maxCountWinners == compared.maxCountWinners)
  if(endDate == compared.endDate)
  if(isPrivate == compared.isPrivate)
  if(guildId == compared.guildId)
  if(allianceId == compared.allianceId)
  if(criterions == compared.criterions)
  if(startDate == compared.startDate)
  return true;
  
  return false;
}

