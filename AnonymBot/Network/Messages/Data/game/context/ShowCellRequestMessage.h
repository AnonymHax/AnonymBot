#ifndef SHOWCELLREQUESTMESSAGE_H
#define SHOWCELLREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ShowCellRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ShowCellRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ShowCellRequestMessage(Reader *param1);
  ShowCellRequestMessage();

  uint cellId;
};

#endif // SHOWCELLREQUESTMESSAGE_H