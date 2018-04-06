#ifndef EXCHANGEMOUNTSSTABLEADDMESSAGE_H
#define EXCHANGEMOUNTSSTABLEADDMESSAGE_H

#include "Network/Classes/Data/game/mount/MountClientData.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/mount/MountClientData.h"

class ExchangeMountsStableAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMountsStableAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMountsStableAddMessage(Reader *param1);
  ExchangeMountsStableAddMessage();

  QList<QSharedPointer<MountClientData>> mountDescription;
};

#endif // EXCHANGEMOUNTSSTABLEADDMESSAGE_H