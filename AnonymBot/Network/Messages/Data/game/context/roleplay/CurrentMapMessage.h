#ifndef CURRENTMAPMESSAGE_H
#define CURRENTMAPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CurrentMapMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CurrentMapMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CurrentMapMessage(Reader *param1);
  CurrentMapMessage();

  uint mapId;
  QString mapKey;
};

#endif // CURRENTMAPMESSAGE_H