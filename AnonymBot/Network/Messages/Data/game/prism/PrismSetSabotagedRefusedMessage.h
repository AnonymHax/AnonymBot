#ifndef PRISMSETSABOTAGEDREFUSEDMESSAGE_H
#define PRISMSETSABOTAGEDREFUSEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismSetSabotagedRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismSetSabotagedRefusedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismSetSabotagedRefusedMessage(Reader *param1);
  PrismSetSabotagedRefusedMessage();

  uint subAreaId;
  int reason;
};

#endif // PRISMSETSABOTAGEDREFUSEDMESSAGE_H