#ifndef RELOGINTOKENSTATUSMESSAGE_H
#define RELOGINTOKENSTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ReloginTokenStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ReloginTokenStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ReloginTokenStatusMessage(Reader *param1);
  ReloginTokenStatusMessage();

  bool validToken;
  QList<int> ticket;
};

#endif // RELOGINTOKENSTATUSMESSAGE_H