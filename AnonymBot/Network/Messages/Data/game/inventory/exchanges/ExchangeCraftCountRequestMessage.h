#ifndef EXCHANGECRAFTCOUNTREQUESTMESSAGE_H
#define EXCHANGECRAFTCOUNTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeCraftCountRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCraftCountRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCraftCountRequestMessage(Reader *param1);
  ExchangeCraftCountRequestMessage();

  int count;
};

#endif // EXCHANGECRAFTCOUNTREQUESTMESSAGE_H