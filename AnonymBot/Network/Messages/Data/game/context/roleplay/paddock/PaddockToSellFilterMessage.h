#ifndef PADDOCKTOSELLFILTERMESSAGE_H
#define PADDOCKTOSELLFILTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PaddockToSellFilterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockToSellFilterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockToSellFilterMessage(Reader *param1);
  PaddockToSellFilterMessage();

  int areaId;
  int atLeastNbMount;
  int atLeastNbMachine;
  uint maxPrice;
};

#endif // PADDOCKTOSELLFILTERMESSAGE_H