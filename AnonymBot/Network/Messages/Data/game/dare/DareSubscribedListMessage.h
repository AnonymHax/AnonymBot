#ifndef DARESUBSCRIBEDLISTMESSAGE_H
#define DARESUBSCRIBEDLISTMESSAGE_H

#include "Network/Classes/Data/game/dare/DareInformations.h"
#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareInformations.h"
#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"

class DareSubscribedListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareSubscribedListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareSubscribedListMessage(Reader *param1);
  DareSubscribedListMessage();

  QList<DareInformations> daresFixedInfos;
  QList<DareVersatileInformations> daresVersatilesInfos;
};

#endif // DARESUBSCRIBEDLISTMESSAGE_H