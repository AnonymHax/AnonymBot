#ifndef EXCHANGESTARTOKJOBINDEXMESSAGE_H
#define EXCHANGESTARTOKJOBINDEXMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeStartOkJobIndexMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkJobIndexMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkJobIndexMessage(Reader *param1);
  ExchangeStartOkJobIndexMessage();

  QList<uint> jobs;
};

#endif // EXCHANGESTARTOKJOBINDEXMESSAGE_H