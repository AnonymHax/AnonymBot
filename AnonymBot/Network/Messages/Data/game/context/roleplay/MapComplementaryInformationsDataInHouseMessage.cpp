#include "MapComplementaryInformationsDataInHouseMessage.h"

void MapComplementaryInformationsDataInHouseMessage::serialize(Writer *param1)
{
  this->serializeAs_MapComplementaryInformationsDataInHouseMessage(param1);
}

void MapComplementaryInformationsDataInHouseMessage::serializeAs_MapComplementaryInformationsDataInHouseMessage(Writer *param1)
{
  MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(param1);
  this->currentHouse.serializeAs_HouseInformationsInside(param1);
}

void MapComplementaryInformationsDataInHouseMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapComplementaryInformationsDataInHouseMessage(param1);
}

void MapComplementaryInformationsDataInHouseMessage::deserializeAs_MapComplementaryInformationsDataInHouseMessage(Reader *param1)
{
  MapComplementaryInformationsDataMessage::deserialize(param1);
  this->currentHouse = HouseInformationsInside();
  this->currentHouse.deserialize(param1);
}

MapComplementaryInformationsDataInHouseMessage::MapComplementaryInformationsDataInHouseMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE;
}

