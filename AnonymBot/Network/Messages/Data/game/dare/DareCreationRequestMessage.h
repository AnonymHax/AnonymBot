#ifndef DARECREATIONREQUESTMESSAGE_H
#define DARECREATIONREQUESTMESSAGE_H

#include "Network/Classes/Data/game/dare/DareCriteria.h"
#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareCriteria.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class DareCreationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareCreationRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareCreationRequestMessage(Reader *param1);
  DareCreationRequestMessage();

  uint subscriptionFee;
  uint jackpot;
  uint maxCountWinners;
  uint delayBeforeStart;
  uint duration;
  bool isPrivate;
  bool isForGuild;
  bool isForAlliance;
  bool needNotifications;
  QList<DareCriteria> criterions;
};

#endif // DARECREATIONREQUESTMESSAGE_H