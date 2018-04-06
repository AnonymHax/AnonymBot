#ifndef IDENTIFICATIONMESSAGE_H
#define IDENTIFICATIONMESSAGE_H

#include "Network/Classes/Data/version/VersionExtended.h"
#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/version/VersionExtended.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class IdentificationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdentificationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdentificationMessage(Reader *param1);
  IdentificationMessage();

  VersionExtended version;
  QString lang;
  QList<int> credentials;
  int serverId;
  bool autoconnect;
  bool useCertificate;
  bool useLoginToken;
  double sessionOptionalSalt;
  QList<uint> failedAttempts;
};

#endif // IDENTIFICATIONMESSAGE_H