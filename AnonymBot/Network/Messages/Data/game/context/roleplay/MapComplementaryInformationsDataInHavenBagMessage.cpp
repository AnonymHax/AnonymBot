#include "MapComplementaryInformationsDataInHavenBagMessage.h"

void MapComplementaryInformationsDataInHavenBagMessage::serialize(Writer *param1)
{
  this->serializeAs_MapComplementaryInformationsDataInHavenBagMessage(param1);
}

void MapComplementaryInformationsDataInHavenBagMessage::serializeAs_MapComplementaryInformationsDataInHavenBagMessage(Writer *param1)
{
  MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(param1);
  this->ownerInformations.serializeAs_CharacterMinimalInformations(param1);
  param1->writeByte(this->theme);
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataInHavenBagMessage -"<<"Forbidden value (" << this->roomId << ") on element roomId.";
  }
  else
  {
    param1->writeByte(this->roomId);
    if(this->maxRoomId < 0)
    {
      qDebug()<<"ERREUR - MapComplementaryInformationsDataInHavenBagMessage -"<<"Forbidden value (" << this->maxRoomId << ") on element maxRoomId.";
    }
    else
    {
      param1->writeByte(this->maxRoomId);
      return;
    }
  }
}

void MapComplementaryInformationsDataInHavenBagMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapComplementaryInformationsDataInHavenBagMessage(param1);
}

void MapComplementaryInformationsDataInHavenBagMessage::deserializeAs_MapComplementaryInformationsDataInHavenBagMessage(Reader *param1)
{
  MapComplementaryInformationsDataMessage::deserialize(param1);
  this->ownerInformations = CharacterMinimalInformations();
  this->ownerInformations.deserialize(param1);
  this->theme = param1->readByte();
  this->roomId = param1->readByte();
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataInHavenBagMessage -"<<"Forbidden value (" << this->roomId << ") on element of MapComplementaryInformationsDataInHavenBagMessage.roomId.";
  }
  else
  {
    this->maxRoomId = param1->readByte();
    if(this->maxRoomId < 0)
    {
      qDebug()<<"ERREUR - MapComplementaryInformationsDataInHavenBagMessage -"<<"Forbidden value (" << this->maxRoomId << ") on element of MapComplementaryInformationsDataInHavenBagMessage.maxRoomId.";
    }
    else
    {
      return;
    }
  }
}

MapComplementaryInformationsDataInHavenBagMessage::MapComplementaryInformationsDataInHavenBagMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE;
}

