#include "GuildEmblem.h"

void GuildEmblem::serialize(Writer *param1)
{
  this->serializeAs_GuildEmblem(param1);
}

void GuildEmblem::serializeAs_GuildEmblem(Writer *param1)
{
  if(this->symbolShape < 0)
  {
    qDebug()<<"ERREUR - GuildEmblem -"<<"Forbidden value (" << this->symbolShape << ") on element symbolShape.";
  }
  else
  {
    param1->writeVarShort((int)this->symbolShape);
    param1->writeInt((int)this->symbolColor);
    if(this->backgroundShape < 0)
    {
      qDebug()<<"ERREUR - GuildEmblem -"<<"Forbidden value (" << this->backgroundShape << ") on element backgroundShape.";
    }
    else
    {
      param1->writeByte(this->backgroundShape);
      param1->writeInt((int)this->backgroundColor);
      return;
    }
  }
}

void GuildEmblem::deserialize(Reader *param1)
{
  this->deserializeAs_GuildEmblem(param1);
}

void GuildEmblem::deserializeAs_GuildEmblem(Reader *param1)
{
  this->symbolShape = param1->readVarUhShort();
  if(this->symbolShape < 0)
  {
    qDebug()<<"ERREUR - GuildEmblem -"<<"Forbidden value (" << this->symbolShape << ") on element of GuildEmblem.symbolShape.";
  }
  else
  {
    this->symbolColor = param1->readInt();
    this->backgroundShape = param1->readByte();
    if(this->backgroundShape < 0)
    {
      qDebug()<<"ERREUR - GuildEmblem -"<<"Forbidden value (" << this->backgroundShape << ") on element of GuildEmblem.backgroundShape.";
    }
    else
    {
      this->backgroundColor = param1->readInt();
      return;
    }
  }
}

GuildEmblem::GuildEmblem()
{
  m_types<<ClassEnum::GUILDEMBLEM;
}

bool GuildEmblem::operator==(const GuildEmblem &compared)
{
  if(symbolShape == compared.symbolShape)
  if(symbolColor == compared.symbolColor)
  if(backgroundShape == compared.backgroundShape)
  if(backgroundColor == compared.backgroundColor)
  return true;
  
  return false;
}

