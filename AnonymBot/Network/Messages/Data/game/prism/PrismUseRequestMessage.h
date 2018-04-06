#ifndef PRISMUSEREQUESTMESSAGE_H
#define PRISMUSEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismUseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismUseRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismUseRequestMessage(Reader *param1);
  PrismUseRequestMessage();

  uint moduleToUse;
};

#endif // PRISMUSEREQUESTMESSAGE_H