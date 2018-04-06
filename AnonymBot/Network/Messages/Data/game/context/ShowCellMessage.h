#ifndef SHOWCELLMESSAGE_H
#define SHOWCELLMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ShowCellMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShowCellMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShowCellMessage(Reader *param1);
  ShowCellMessage();

  double sourceId;
  uint cellId;
};

#endif // SHOWCELLMESSAGE_H