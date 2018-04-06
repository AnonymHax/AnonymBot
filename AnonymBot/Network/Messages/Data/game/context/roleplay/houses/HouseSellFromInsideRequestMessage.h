#ifndef HOUSESELLFROMINSIDEREQUESTMESSAGE_H
#define HOUSESELLFROMINSIDEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/houses/HouseSellRequestMessage.h"

class HouseSellFromInsideRequestMessage : public HouseSellRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseSellFromInsideRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseSellFromInsideRequestMessage(Reader *param1);
  HouseSellFromInsideRequestMessage();
};

#endif // HOUSESELLFROMINSIDEREQUESTMESSAGE_H