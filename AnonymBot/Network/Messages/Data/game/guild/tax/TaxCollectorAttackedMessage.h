#ifndef TAXCOLLECTORATTACKEDMESSAGE_H
#define TAXCOLLECTORATTACKEDMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"

class TaxCollectorAttackedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorAttackedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorAttackedMessage(Reader *param1);
  TaxCollectorAttackedMessage();

  uint firstNameId;
  uint lastNameId;
  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
  QSharedPointer<BasicGuildInformations> guild;
};

#endif // TAXCOLLECTORATTACKEDMESSAGE_H