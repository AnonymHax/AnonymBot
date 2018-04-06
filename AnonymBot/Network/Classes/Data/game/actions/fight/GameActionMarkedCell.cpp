#include "GameActionMarkedCell.h"

void GameActionMarkedCell::serialize(Writer *param1)
{
  this->serializeAs_GameActionMarkedCell(param1);
}

void GameActionMarkedCell::serializeAs_GameActionMarkedCell(Writer *param1)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionMarkedCell -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    param1->writeByte(this->zoneSize);
    param1->writeInt((int)this->cellColor);
    param1->writeByte(this->cellsType);
    return;
  }
}

void GameActionMarkedCell::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionMarkedCell(param1);
}

void GameActionMarkedCell::deserializeAs_GameActionMarkedCell(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - GameActionMarkedCell -"<<"Forbidden value (" << this->cellId << ") on element of GameActionMarkedCell.cellId.";
  }
  else
  {
    this->zoneSize = param1->readByte();
    this->cellColor = param1->readInt();
    this->cellsType = param1->readByte();
    return;
  }
}

GameActionMarkedCell::GameActionMarkedCell()
{
  m_types<<ClassEnum::GAMEACTIONMARKEDCELL;
}

bool GameActionMarkedCell::operator==(const GameActionMarkedCell &compared)
{
  if(cellId == compared.cellId)
  if(zoneSize == compared.zoneSize)
  if(cellColor == compared.cellColor)
  if(cellsType == compared.cellsType)
  return true;
  
  return false;
}

