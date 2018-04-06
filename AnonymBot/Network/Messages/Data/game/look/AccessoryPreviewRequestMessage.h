#ifndef ACCESSORYPREVIEWREQUESTMESSAGE_H
#define ACCESSORYPREVIEWREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AccessoryPreviewRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AccessoryPreviewRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AccessoryPreviewRequestMessage(Reader *param1);
  AccessoryPreviewRequestMessage();

  QList<uint> genericId;
};

#endif // ACCESSORYPREVIEWREQUESTMESSAGE_H