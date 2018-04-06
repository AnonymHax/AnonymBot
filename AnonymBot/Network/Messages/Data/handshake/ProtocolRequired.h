#ifndef PROTOCOLREQUIRED_H
#define PROTOCOLREQUIRED_H

#include "Network/Messages/AbstractMessage.h"

class ProtocolRequired : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ProtocolRequired(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ProtocolRequired(Reader *param1);
  ProtocolRequired();

  uint requiredVersion;
  uint currentVersion;
};

#endif // PROTOCOLREQUIRED_H