#include "ArenaRankInfos.h"

void ArenaRankInfos::serialize(Writer *param1)
{
  this->serializeAs_ArenaRankInfos(param1);
}

void ArenaRankInfos::serializeAs_ArenaRankInfos(Writer *param1)
{
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->rank << ") on element rank.";
  }
  else
  {
    param1->writeVarShort((int)this->rank);
    if(this->bestRank < 0 || this->bestRank > 20000)
    {
      qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->bestRank << ") on element bestRank.";
    }
    else
    {
      param1->writeVarShort((int)this->bestRank);
      if(this->victoryCount < 0)
      {
        qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->victoryCount << ") on element victoryCount.";
      }
      else
      {
        param1->writeVarShort((int)this->victoryCount);
        if(this->fightcount < 0)
        {
          qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->fightcount << ") on element fightcount.";
        }
        else
        {
          param1->writeVarShort((int)this->fightcount);
          return;
        }
      }
    }
  }
}

void ArenaRankInfos::deserialize(Reader *param1)
{
  this->deserializeAs_ArenaRankInfos(param1);
}

void ArenaRankInfos::deserializeAs_ArenaRankInfos(Reader *param1)
{
  this->rank = param1->readVarUhShort();
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->rank << ") on element of ArenaRankInfos.rank.";
  }
  else
  {
    this->bestRank = param1->readVarUhShort();
    if(this->bestRank < 0 || this->bestRank > 20000)
    {
      qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->bestRank << ") on element of ArenaRankInfos.bestRank.";
    }
    else
    {
      this->victoryCount = param1->readVarUhShort();
      if(this->victoryCount < 0)
      {
        qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->victoryCount << ") on element of ArenaRankInfos.victoryCount.";
      }
      else
      {
        this->fightcount = param1->readVarUhShort();
        if(this->fightcount < 0)
        {
          qDebug()<<"ERREUR - ArenaRankInfos -"<<"Forbidden value (" << this->fightcount << ") on element of ArenaRankInfos.fightcount.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

ArenaRankInfos::ArenaRankInfos()
{
  m_types<<ClassEnum::ARENARANKINFOS;
}

bool ArenaRankInfos::operator==(const ArenaRankInfos &compared)
{
  if(rank == compared.rank)
  if(bestRank == compared.bestRank)
  if(victoryCount == compared.victoryCount)
  if(fightcount == compared.fightcount)
  return true;
  
  return false;
}

