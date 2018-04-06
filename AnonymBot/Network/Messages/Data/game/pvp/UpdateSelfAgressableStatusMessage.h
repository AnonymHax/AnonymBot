#ifndef UPDATESELFAGRESSABLESTATUSMESSAGE_H
#define UPDATESELFAGRESSABLESTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class UpdateSelfAgressableStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_UpdateSelfAgressableStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_UpdateSelfAgressableStatusMessage(Reader *param1);
  UpdateSelfAgressableStatusMessage();

  uint status;
  uint probationTime;
};

#endif // UPDATESELFAGRESSABLESTATUSMESSAGE_H