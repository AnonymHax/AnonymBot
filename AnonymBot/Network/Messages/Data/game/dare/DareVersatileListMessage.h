#ifndef DAREVERSATILELISTMESSAGE_H
#define DAREVERSATILELISTMESSAGE_H

#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareVersatileInformations.h"

class DareVersatileListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareVersatileListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareVersatileListMessage(Reader *param1);
  DareVersatileListMessage();

  QList<DareVersatileInformations> dares;
};

#endif // DAREVERSATILELISTMESSAGE_H