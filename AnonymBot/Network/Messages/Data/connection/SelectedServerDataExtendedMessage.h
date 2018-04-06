#ifndef SELECTEDSERVERDATAEXTENDEDMESSAGE_H
#define SELECTEDSERVERDATAEXTENDEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/connection/SelectedServerDataMessage.h"

class SelectedServerDataExtendedMessage : public SelectedServerDataMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SelectedServerDataExtendedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SelectedServerDataExtendedMessage(Reader *param1);
  SelectedServerDataExtendedMessage();

  QList<uint> serverIds;
};

#endif // SELECTEDSERVERDATAEXTENDEDMESSAGE_H