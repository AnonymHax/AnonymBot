#ifndef DARESUBSCRIBEDMESSAGE_H
#define DARESUBSCRIBEDMESSAGE_H

#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"
#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class DareSubscribedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareSubscribedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareSubscribedMessage(Reader *param1);
  DareSubscribedMessage();

  double dareId;
  bool success;
  bool subscribe;
  DareVersatileInformations dareVersatilesInfos;
};

#endif // DARESUBSCRIBEDMESSAGE_H