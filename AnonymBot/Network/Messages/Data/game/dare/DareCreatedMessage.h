#ifndef DARECREATEDMESSAGE_H
#define DARECREATEDMESSAGE_H

#include "Network/Classes/Data/game/dare/DareInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareInformations.h"

class DareCreatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareCreatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareCreatedMessage(Reader *param1);
  DareCreatedMessage();

  DareInformations dareInfos;
  bool needNotifications;
};

#endif // DARECREATEDMESSAGE_H