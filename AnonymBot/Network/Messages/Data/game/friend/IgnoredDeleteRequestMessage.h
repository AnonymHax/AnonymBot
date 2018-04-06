#ifndef IGNOREDDELETEREQUESTMESSAGE_H
#define IGNOREDDELETEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IgnoredDeleteRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IgnoredDeleteRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IgnoredDeleteRequestMessage(Reader *param1);
  IgnoredDeleteRequestMessage();

  uint accountId;
  bool session;
};

#endif // IGNOREDDELETEREQUESTMESSAGE_H