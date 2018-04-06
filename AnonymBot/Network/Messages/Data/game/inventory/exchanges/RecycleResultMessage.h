#ifndef RECYCLERESULTMESSAGE_H
#define RECYCLERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class RecycleResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_RecycleResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_RecycleResultMessage(Reader *param1);
  RecycleResultMessage();

  uint nuggetsForPrism;
  uint nuggetsForPlayer;
};

#endif // RECYCLERESULTMESSAGE_H