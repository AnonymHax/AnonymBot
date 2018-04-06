#ifndef MAPINFORMATIONSREQUESTMESSAGE_H
#define MAPINFORMATIONSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MapInformationsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapInformationsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapInformationsRequestMessage(Reader *param1);
  MapInformationsRequestMessage();

  uint mapId;
};

#endif // MAPINFORMATIONSREQUESTMESSAGE_H