#include "MonsterBoosts.h"

void MonsterBoosts::serialize(Writer *param1)
{
  this->serializeAs_MonsterBoosts(param1);
}

void MonsterBoosts::serializeAs_MonsterBoosts(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarInt((int)this->id);
    if(this->xpBoost < 0)
    {
      qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->xpBoost << ") on element xpBoost.";
    }
    else
    {
      param1->writeVarShort((int)this->xpBoost);
      if(this->dropBoost < 0)
      {
        qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->dropBoost << ") on element dropBoost.";
      }
      else
      {
        param1->writeVarShort((int)this->dropBoost);
        return;
      }
    }
  }
}

void MonsterBoosts::deserialize(Reader *param1)
{
  this->deserializeAs_MonsterBoosts(param1);
}

void MonsterBoosts::deserializeAs_MonsterBoosts(Reader *param1)
{
  this->id = param1->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->id << ") on element of MonsterBoosts.id.";
  }
  else
  {
    this->xpBoost = param1->readVarUhShort();
    if(this->xpBoost < 0)
    {
      qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->xpBoost << ") on element of MonsterBoosts.xpBoost.";
    }
    else
    {
      this->dropBoost = param1->readVarUhShort();
      if(this->dropBoost < 0)
      {
        qDebug()<<"ERREUR - MonsterBoosts -"<<"Forbidden value (" << this->dropBoost << ") on element of MonsterBoosts.dropBoost.";
      }
      else
      {
        return;
      }
    }
  }
}

MonsterBoosts::MonsterBoosts()
{
  m_types<<ClassEnum::MONSTERBOOSTS;
}

bool MonsterBoosts::operator==(const MonsterBoosts &compared)
{
  if(id == compared.id)
  if(xpBoost == compared.xpBoost)
  if(dropBoost == compared.dropBoost)
  return true;
  
  return false;
}

