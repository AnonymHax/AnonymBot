#ifndef ZAAPRESPAWNUPDATEDMESSAGE_H
#define ZAAPRESPAWNUPDATEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ZaapRespawnUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ZaapRespawnUpdatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ZaapRespawnUpdatedMessage(Reader *param1);
  ZaapRespawnUpdatedMessage();

  uint mapId;
};

#endif // ZAAPRESPAWNUPDATEDMESSAGE_H