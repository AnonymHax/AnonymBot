#ifndef GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE_H
#define GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightPlacementPositionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightPlacementPositionRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightPlacementPositionRequestMessage(Reader *param1);
  GameFightPlacementPositionRequestMessage();

  uint cellId;
};

#endif // GAMEFIGHTPLACEMENTPOSITIONREQUESTMESSAGE_H