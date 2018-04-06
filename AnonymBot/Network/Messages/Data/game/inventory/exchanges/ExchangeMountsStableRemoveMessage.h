#ifndef EXCHANGEMOUNTSSTABLEREMOVEMESSAGE_H
#define EXCHANGEMOUNTSSTABLEREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeMountsStableRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMountsStableRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMountsStableRemoveMessage(Reader *param1);
  ExchangeMountsStableRemoveMessage();

  QList<int> mountsId;
};

#endif // EXCHANGEMOUNTSSTABLEREMOVEMESSAGE_H