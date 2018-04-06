#ifndef IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE_H
#define IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE_H

#include "Network/Classes/Data/version/Version.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/connection/IdentificationFailedMessage.h"
#include "Network/Classes/Data/version/Version.h"

class IdentificationFailedForBadVersionMessage : public IdentificationFailedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdentificationFailedForBadVersionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdentificationFailedForBadVersionMessage(Reader *param1);
  IdentificationFailedForBadVersionMessage();

  Version requiredVersion;
};

#endif // IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE_H