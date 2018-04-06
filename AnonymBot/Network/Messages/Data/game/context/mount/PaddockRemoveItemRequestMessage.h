#ifndef PADDOCKREMOVEITEMREQUESTMESSAGE_H
#define PADDOCKREMOVEITEMREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PaddockRemoveItemRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockRemoveItemRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockRemoveItemRequestMessage(Reader *param1);
  PaddockRemoveItemRequestMessage();

  uint cellId;
};

#endif // PADDOCKREMOVEITEMREQUESTMESSAGE_H