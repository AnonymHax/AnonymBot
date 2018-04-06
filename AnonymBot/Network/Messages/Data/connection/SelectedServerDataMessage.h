#ifndef SELECTEDSERVERDATAMESSAGE_H
#define SELECTEDSERVERDATAMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SelectedServerDataMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SelectedServerDataMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SelectedServerDataMessage(Reader *param1);
  SelectedServerDataMessage();

  uint serverId;
  QString address;
  uint port;
  bool canCreateNewCharacter;
  QList<int> ticket;
};

#endif // SELECTEDSERVERDATAMESSAGE_H