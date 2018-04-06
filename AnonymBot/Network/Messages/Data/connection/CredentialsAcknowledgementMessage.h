#ifndef CREDENTIALSACKNOWLEDGEMENTMESSAGE_H
#define CREDENTIALSACKNOWLEDGEMENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CredentialsAcknowledgementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CredentialsAcknowledgementMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CredentialsAcknowledgementMessage(Reader *param1);
  CredentialsAcknowledgementMessage();
};

#endif // CREDENTIALSACKNOWLEDGEMENTMESSAGE_H