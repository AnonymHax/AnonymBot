#ifndef DARELISTMESSAGE_H
#define DARELISTMESSAGE_H

#include "Network/Classes/Data/game/dare/DareInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareInformations.h"

class DareListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareListMessage(Reader *param1);
  DareListMessage();

  QList<DareInformations> dares;
};

#endif // DARELISTMESSAGE_H