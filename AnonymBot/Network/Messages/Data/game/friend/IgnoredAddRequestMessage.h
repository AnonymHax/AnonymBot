#ifndef IGNOREDADDREQUESTMESSAGE_H
#define IGNOREDADDREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IgnoredAddRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IgnoredAddRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IgnoredAddRequestMessage(Reader *param1);
  IgnoredAddRequestMessage();

  QString name;
  bool session;
};

#endif // IGNOREDADDREQUESTMESSAGE_H