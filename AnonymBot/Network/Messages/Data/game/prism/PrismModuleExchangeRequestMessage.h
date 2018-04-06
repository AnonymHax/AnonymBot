#ifndef PRISMMODULEEXCHANGEREQUESTMESSAGE_H
#define PRISMMODULEEXCHANGEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismModuleExchangeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismModuleExchangeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismModuleExchangeRequestMessage(Reader *param1);
  PrismModuleExchangeRequestMessage();
};

#endif // PRISMMODULEEXCHANGEREQUESTMESSAGE_H