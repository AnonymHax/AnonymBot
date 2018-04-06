#ifndef AREAFIGHTMODIFICATORUPDATEMESSAGE_H
#define AREAFIGHTMODIFICATORUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AreaFightModificatorUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AreaFightModificatorUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AreaFightModificatorUpdateMessage(Reader *param1);
  AreaFightModificatorUpdateMessage();

  int spellPairId;
};

#endif // AREAFIGHTMODIFICATORUPDATEMESSAGE_H