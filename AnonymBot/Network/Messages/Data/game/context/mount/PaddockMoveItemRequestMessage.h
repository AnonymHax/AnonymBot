#ifndef PADDOCKMOVEITEMREQUESTMESSAGE_H
#define PADDOCKMOVEITEMREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PaddockMoveItemRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockMoveItemRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockMoveItemRequestMessage(Reader *param1);
  PaddockMoveItemRequestMessage();

  uint oldCellId;
  uint newCellId;
};

#endif // PADDOCKMOVEITEMREQUESTMESSAGE_H