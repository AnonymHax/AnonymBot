#include "GameServerInformations.h"

void GameServerInformations::serialize(Writer *param1)
{
  this->serializeAs_GameServerInformations(param1);
}

void GameServerInformations::serializeAs_GameServerInformations(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarShort((int)this->id);
    param1->writeByte(this->type);
    param1->writeByte(this->status);
    param1->writeByte(this->completion);
    param1->writeBool(this->isSelectable);
    if(this->charactersCount < 0)
    {
      qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->charactersCount << ") on element charactersCount.";
    }
    else
    {
      param1->writeByte(this->charactersCount);
      if(this->charactersSlots < 0)
      {
        qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->charactersSlots << ") on element charactersSlots.";
      }
      else
      {
        param1->writeByte(this->charactersSlots);
        if(this->date < -9.007199254740992E15 || this->date > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->date << ") on element date.";
        }
        else
        {
          param1->writeDouble(this->date);
          return;
        }
      }
    }
  }
}

void GameServerInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameServerInformations(param1);
}

void GameServerInformations::deserializeAs_GameServerInformations(Reader *param1)
{
  this->id = param1->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->id << ") on element of GameServerInformations.id.";
  }
  else
  {
    this->type = param1->readByte();
    this->status = param1->readByte();
    if(this->status < 0)
    {
      qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->status << ") on element of GameServerInformations.status.";
    }
    else
    {
      this->completion = param1->readByte();
      if(this->completion < 0)
      {
        qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->completion << ") on element of GameServerInformations.completion.";
      }
      else
      {
        this->isSelectable = param1->readBool();
        this->charactersCount = param1->readByte();
        if(this->charactersCount < 0)
        {
          qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->charactersCount << ") on element of GameServerInformations.charactersCount.";
        }
        else
        {
          this->charactersSlots = param1->readByte();
          if(this->charactersSlots < 0)
          {
            qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->charactersSlots << ") on element of GameServerInformations.charactersSlots.";
          }
          else
          {
            this->date = param1->readDouble();
            if(this->date < -9.007199254740992E15 || this->date > 9.007199254740992E15)
            {
              qDebug()<<"ERREUR - GameServerInformations -"<<"Forbidden value (" << this->date << ") on element of GameServerInformations.date.";
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

GameServerInformations::GameServerInformations()
{
  m_types<<ClassEnum::GAMESERVERINFORMATIONS;
}

bool GameServerInformations::operator==(const GameServerInformations &compared)
{
  if(id == compared.id)
  if(type == compared.type)
  if(status == compared.status)
  if(completion == compared.completion)
  if(isSelectable == compared.isSelectable)
  if(charactersCount == compared.charactersCount)
  if(charactersSlots == compared.charactersSlots)
  if(date == compared.date)
  return true;
  
  return false;
}

