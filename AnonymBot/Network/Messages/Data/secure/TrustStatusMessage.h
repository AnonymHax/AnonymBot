#ifndef TRUSTSTATUSMESSAGE_H
#define TRUSTSTATUSMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class TrustStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TrustStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TrustStatusMessage(Reader *param1);
  TrustStatusMessage();

  bool trusted;
  bool certified;
};

#endif // TRUSTSTATUSMESSAGE_H