#ifndef EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE_H
#define EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE_H

#include "Network/Classes/Data/game/mount/MountClientData.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/mount/MountClientData.h"

class ExchangeStartOkMountWithOutPaddockMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeStartOkMountWithOutPaddockMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeStartOkMountWithOutPaddockMessage(Reader *param1);
  ExchangeStartOkMountWithOutPaddockMessage();

  QList<QSharedPointer<MountClientData>> stabledMountsDescription;
};

#endif // EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE_H