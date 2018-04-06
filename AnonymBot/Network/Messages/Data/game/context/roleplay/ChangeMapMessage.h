#ifndef CHANGEMAPMESSAGE_H
#define CHANGEMAPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChangeMapMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChangeMapMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChangeMapMessage(Reader *param1);
  ChangeMapMessage();

  uint mapId;
};

#endif // CHANGEMAPMESSAGE_H