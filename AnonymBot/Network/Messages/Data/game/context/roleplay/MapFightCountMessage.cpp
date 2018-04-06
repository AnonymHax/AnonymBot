#include "MapFightCountMessage.h"

void MapFightCountMessage::serialize(Writer *param1)
{
  this->serializeAs_MapFightCountMessage(param1);
}

void MapFightCountMessage::serializeAs_MapFightCountMessage(Writer *param1)
{
  if(this->fightCount < 0)
  {
    qDebug()<<"ERREUR - MapFightCountMessage -"<<"Forbidden value (" << this->fightCount << ") on element fightCount.";
  }
  else
  {
    param1->writeVarShort((int)this->fightCount);
    return;
  }
}

void MapFightCountMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapFightCountMessage(param1);
}

void MapFightCountMessage::deserializeAs_MapFightCountMessage(Reader *param1)
{
  this->fightCount = param1->readVarUhShort();
  if(this->fightCount < 0)
  {
    qDebug()<<"ERREUR - MapFightCountMessage -"<<"Forbidden value (" << this->fightCount << ") on element of MapFightCountMessage.fightCount.";
  }
  else
  {
    return;
  }
}

MapFightCountMessage::MapFightCountMessage()
{
  m_type = MessageEnum::MAPFIGHTCOUNTMESSAGE;
}

