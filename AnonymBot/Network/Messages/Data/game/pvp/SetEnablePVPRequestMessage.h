#ifndef SETENABLEPVPREQUESTMESSAGE_H
#define SETENABLEPVPREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SetEnablePVPRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SetEnablePVPRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SetEnablePVPRequestMessage(Reader *param1);
  SetEnablePVPRequestMessage();

  bool enable;
};

#endif // SETENABLEPVPREQUESTMESSAGE_H