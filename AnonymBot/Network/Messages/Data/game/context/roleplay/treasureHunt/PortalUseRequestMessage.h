#ifndef PORTALUSEREQUESTMESSAGE_H
#define PORTALUSEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PortalUseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PortalUseRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PortalUseRequestMessage(Reader *param1);
  PortalUseRequestMessage();

  uint portalId;
};

#endif // PORTALUSEREQUESTMESSAGE_H