#ifndef DARECREATEDLISTMESSAGE_H
#define DARECREATEDLISTMESSAGE_H

#include "Network/Classes/Data/game/dare/DareInformations.h"
#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareInformations.h"
#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"

class DareCreatedListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareCreatedListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareCreatedListMessage(Reader *param1);
  DareCreatedListMessage();

  QList<DareInformations> daresFixedInfos;
  QList<DareVersatileInformations> daresVersatilesInfos;
};

#endif // DARECREATEDLISTMESSAGE_H