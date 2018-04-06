#ifndef EXCHANGECRAFTCOUNTMODIFIEDMESSAGE_H
#define EXCHANGECRAFTCOUNTMODIFIEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeCraftCountModifiedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeCraftCountModifiedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeCraftCountModifiedMessage(Reader *param1);
  ExchangeCraftCountModifiedMessage();

  int count;
};

#endif // EXCHANGECRAFTCOUNTMODIFIEDMESSAGE_H