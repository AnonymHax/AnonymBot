#ifndef IDENTIFICATIONFAILEDMESSAGE_H
#define IDENTIFICATIONFAILEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IdentificationFailedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdentificationFailedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdentificationFailedMessage(Reader *param1);
  IdentificationFailedMessage();

  uint reason;
};

#endif // IDENTIFICATIONFAILEDMESSAGE_H