#ifndef IDENTIFICATIONACCOUNTFORCEMESSAGE_H
#define IDENTIFICATIONACCOUNTFORCEMESSAGE_H

#include "Network/Classes/Data/version/VersionExtended.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/connection/IdentificationMessage.h"
#include "Network/Classes/Data/version/VersionExtended.h"

class IdentificationAccountForceMessage : public IdentificationMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdentificationAccountForceMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdentificationAccountForceMessage(Reader *param1);
  IdentificationAccountForceMessage();

  QString forcedAccountLogin;
};

#endif // IDENTIFICATIONACCOUNTFORCEMESSAGE_H