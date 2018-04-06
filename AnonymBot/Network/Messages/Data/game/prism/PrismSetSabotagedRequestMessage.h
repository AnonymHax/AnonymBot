#ifndef PRISMSETSABOTAGEDREQUESTMESSAGE_H
#define PRISMSETSABOTAGEDREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismSetSabotagedRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismSetSabotagedRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismSetSabotagedRequestMessage(Reader *param1);
  PrismSetSabotagedRequestMessage();

  uint subAreaId;
};

#endif // PRISMSETSABOTAGEDREQUESTMESSAGE_H