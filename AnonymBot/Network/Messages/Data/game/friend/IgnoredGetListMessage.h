#ifndef IGNOREDGETLISTMESSAGE_H
#define IGNOREDGETLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IgnoredGetListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IgnoredGetListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IgnoredGetListMessage(Reader *param1);
  IgnoredGetListMessage();
};

#endif // IGNOREDGETLISTMESSAGE_H