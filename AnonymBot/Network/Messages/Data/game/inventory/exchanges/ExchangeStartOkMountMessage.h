#ifndef EXCHANGESTARTOKMOUNTMESSAGE_H
#define EXCHANGESTARTOKMOUNTMESSAGE_H

#include "Network/Classes/Data/game/mount/MountClientData.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/exchanges/ExchangeStartOkMountWithOutPaddockMessage.h"
#include "Network/Classes/Data/game/mount/MountClientData.h"

class ExchangeStartOkMountMessage : public ExchangeStartOkMountWithOutPaddockMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkMountMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkMountMessage(Reader *param1);
  ExchangeStartOkMountMessage();

  QList<QSharedPointer<MountClientData>> paddockedMountsDescription;
};

#endif // EXCHANGESTARTOKMOUNTMESSAGE_H