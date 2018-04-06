#ifndef EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE_H
#define EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeMountsPaddockRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMountsPaddockRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMountsPaddockRemoveMessage(Reader *param1);
  ExchangeMountsPaddockRemoveMessage();

  QList<int> mountsId;
};

#endif // EXCHANGEMOUNTSPADDOCKREMOVEMESSAGE_H