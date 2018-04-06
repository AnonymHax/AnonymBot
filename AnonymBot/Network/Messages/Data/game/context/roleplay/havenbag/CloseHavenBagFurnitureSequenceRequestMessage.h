#ifndef CLOSEHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H
#define CLOSEHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CloseHavenBagFurnitureSequenceRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CloseHavenBagFurnitureSequenceRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CloseHavenBagFurnitureSequenceRequestMessage(Reader *param1);
  CloseHavenBagFurnitureSequenceRequestMessage();
};

#endif // CLOSEHAVENBAGFURNITURESEQUENCEREQUESTMESSAGE_H