#ifndef OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H
#define OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class OpenHavenBagFurnitureSequenceRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_OpenHavenBagFurnitureSequenceRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_OpenHavenBagFurnitureSequenceRequestMessage(Reader *param1);
  OpenHavenBagFurnitureSequenceRequestMessage();
};

#endif // OPENHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H