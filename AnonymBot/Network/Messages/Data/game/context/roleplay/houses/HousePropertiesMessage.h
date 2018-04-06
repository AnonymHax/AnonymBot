#ifndef HOUSEPROPERTIESMESSAGE_H
#define HOUSEPROPERTIESMESSAGE_H

#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/ClassManager.h"

class HousePropertiesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HousePropertiesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HousePropertiesMessage(Reader *param1);
  HousePropertiesMessage();

  QSharedPointer<HouseInformations> properties;
};

#endif // HOUSEPROPERTIESMESSAGE_H