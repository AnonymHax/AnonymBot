#ifndef MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE_H
#define MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MapRunningFightDetailsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapRunningFightDetailsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapRunningFightDetailsRequestMessage(Reader *param1);
  MapRunningFightDetailsRequestMessage();

  uint fightId;
};

#endif // MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE_H