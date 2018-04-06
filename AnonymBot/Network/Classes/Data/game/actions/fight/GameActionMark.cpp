#include "GameActionMark.h"

void GameActionMark::serialize(Writer *param1)
{
  this->serializeAs_GameActionMark(param1);
}

void GameActionMark::serializeAs_GameActionMark(Writer *param1)
{
  if(this->markAuthorId < -9.007199254740992E15 || this->markAuthorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markAuthorId << ") on element markAuthorId.";
  }
  else
  {
    param1->writeDouble(this->markAuthorId);
    param1->writeByte(this->markTeamId);
    if(this->markSpellId < 0)
    {
      qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markSpellId << ") on element markSpellId.";
    }
    else
    {
      param1->writeInt((int)this->markSpellId);
      if(this->markSpellLevel < 1 || this->markSpellLevel > 200)
      {
        qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markSpellLevel << ") on element markSpellLevel.";
      }
      else
      {
        param1->writeShort((short)this->markSpellLevel);
        param1->writeShort((short)this->markId);
        param1->writeByte(this->markType);
        if(this->markimpactCell < -1 || this->markimpactCell > 559)
        {
          qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markimpactCell << ") on element markimpactCell.";
        }
        else
        {
          param1->writeShort((short)this->markimpactCell);
          param1->writeShort((short)this->cells.size());
          uint _loc2_ = 0;
          while(_loc2_ < this->cells.size())
          {
            (this->cells[_loc2_]).serializeAs_GameActionMarkedCell(param1);
            _loc2_++;
          }
          param1->writeBool(this->active);
          return;
        }
      }
    }
  }
}

void GameActionMark::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionMark(param1);
}

void GameActionMark::deserializeAs_GameActionMark(Reader *param1)
{
  GameActionMarkedCell _loc4_ ;
  this->markAuthorId = param1->readDouble();
  if(this->markAuthorId < -9.007199254740992E15 || this->markAuthorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markAuthorId << ") on element of GameActionMark.markAuthorId.";
  }
  else
  {
    this->markTeamId = param1->readByte();
    if(this->markTeamId < 0)
    {
      qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markTeamId << ") on element of GameActionMark.markTeamId.";
    }
    else
    {
      this->markSpellId = param1->readInt();
      if(this->markSpellId < 0)
      {
        qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markSpellId << ") on element of GameActionMark.markSpellId.";
      }
      else
      {
        this->markSpellLevel = param1->readShort();
        if(this->markSpellLevel < 1 || this->markSpellLevel > 200)
        {
          qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markSpellLevel << ") on element of GameActionMark.markSpellLevel.";
        }
        else
        {
          this->markId = param1->readShort();
          this->markType = param1->readByte();
          this->markimpactCell = param1->readShort();
          if(this->markimpactCell < -1 || this->markimpactCell > 559)
          {
            qDebug()<<"ERREUR - GameActionMark -"<<"Forbidden value (" << this->markimpactCell << ") on element of GameActionMark.markimpactCell.";
          }
          else
          {
            uint _loc2_ = param1->readUShort();
            uint _loc3_ = 0;
            while(_loc3_ < _loc2_)
            {
              _loc4_ = GameActionMarkedCell();
              _loc4_.deserialize(param1);
              this->cells.append(_loc4_);
              _loc3_++;
            }
            this->active = param1->readBool();
            return;
          }
        }
      }
    }
  }
}

GameActionMark::GameActionMark()
{
  m_types<<ClassEnum::GAMEACTIONMARK;
}

bool GameActionMark::operator==(const GameActionMark &compared)
{
  if(markAuthorId == compared.markAuthorId)
  if(markTeamId == compared.markTeamId)
  if(markSpellId == compared.markSpellId)
  if(markSpellLevel == compared.markSpellLevel)
  if(markId == compared.markId)
  if(markType == compared.markType)
  if(markimpactCell == compared.markimpactCell)
  if(cells == compared.cells)
  if(active == compared.active)
  return true;
  
  return false;
}

