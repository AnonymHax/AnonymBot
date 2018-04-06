#ifndef EXCHANGEMOUNTSPADDOCKADDMESSAGE_H
#define EXCHANGEMOUNTSPADDOCKADDMESSAGE_H

#include "Network/Classes/Data/game/mount/MountClientData.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/mount/MountClientData.h"

class ExchangeMountsPaddockAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMountsPaddockAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMountsPaddockAddMessage(Reader *param1);
  ExchangeMountsPaddockAddMessage();

  QList<QSharedPointer<MountClientData>> mountDescription;
};

#endif // EXCHANGEMOUNTSPADDOCKADDMESSAGE_H