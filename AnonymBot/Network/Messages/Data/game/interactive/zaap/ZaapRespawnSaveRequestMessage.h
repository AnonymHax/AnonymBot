#ifndef ZAAPRESPAWNSAVEREQUESTMESSAGE_H
#define ZAAPRESPAWNSAVEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ZaapRespawnSaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ZaapRespawnSaveRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ZaapRespawnSaveRequestMessage(Reader *param1);
  ZaapRespawnSaveRequestMessage();
};

#endif // ZAAPRESPAWNSAVEREQUESTMESSAGE_H