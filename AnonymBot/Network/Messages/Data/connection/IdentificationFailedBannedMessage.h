#ifndef IDENTIFICATIONFAILEDBANNEDMESSAGE_H
#define IDENTIFICATIONFAILEDBANNEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/connection/IdentificationFailedMessage.h"

class IdentificationFailedBannedMessage : public IdentificationFailedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdentificationFailedBannedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdentificationFailedBannedMessage(Reader *param1);
  IdentificationFailedBannedMessage();

  double banEndDate;
};

#endif // IDENTIFICATIONFAILEDBANNEDMESSAGE_H