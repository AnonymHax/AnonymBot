#ifndef EXCHANGECRAFTRESULTMESSAGE_H
#define EXCHANGECRAFTRESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeCraftResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCraftResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCraftResultMessage(Reader *param1);
  ExchangeCraftResultMessage();

  uint craftResult;
};

#endif // EXCHANGECRAFTRESULTMESSAGE_H