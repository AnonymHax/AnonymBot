#ifndef EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE_H
#define EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeTypesExchangerDescriptionForUserMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeTypesExchangerDescriptionForUserMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeTypesExchangerDescriptionForUserMessage(Reader *param1);
  ExchangeTypesExchangerDescriptionForUserMessage();

  QList<uint> typeDescription;
};

#endif // EXCHANGETYPESEXCHANGERDESCRIPTIONFORUSERMESSAGE_H