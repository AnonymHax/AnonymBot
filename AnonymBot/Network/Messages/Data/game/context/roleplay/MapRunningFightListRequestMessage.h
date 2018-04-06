#ifndef MAPRUNNINGFIGHTLISTREQUESTMESSAGE_H
#define MAPRUNNINGFIGHTLISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MapRunningFightListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapRunningFightListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapRunningFightListRequestMessage(Reader *param1);
  MapRunningFightListRequestMessage();
};

#endif // MAPRUNNINGFIGHTLISTREQUESTMESSAGE_H